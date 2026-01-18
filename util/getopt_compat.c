/*
 * getopt compatibility implementation for Windows
 *
 * This is a minimal implementation sufficient for matiec's needs.
 * Based on public domain implementations.
 */

#ifdef _WIN32

#include <stdio.h>
#include <string.h>
#include "getopt_compat.h"

char *optarg = NULL;
int optind = 1;
int opterr = 1;
int optopt = '?';

static int optwhere = 1;

static void permute_args(int paession, int from, int to, char *const argv[]) {
    /* Simple implementation: we don't actually permute, just process in order */
    (void)paession; (void)from; (void)to; (void)argv;
}

int getopt(int argc, char *const argv[], const char *optstring) {
    const char *oli; /* option letter list index */

    if (optind == 0) {
        optind = 1;
        optwhere = 1;
    }

    if (optwhere == 1) {
        if (optind >= argc || argv[optind] == NULL ||
            argv[optind][0] != '-' || argv[optind][1] == '\0') {
            return -1;
        }
        if (strcmp(argv[optind], "--") == 0) {
            optind++;
            return -1;
        }
    }

    optopt = argv[optind][optwhere];
    oli = strchr(optstring, optopt);

    if (optopt == ':' || oli == NULL) {
        if (opterr && *optstring != ':')
            fprintf(stderr, "%s: illegal option -- %c\n", argv[0], optopt);
        if (argv[optind][++optwhere] == '\0') {
            optind++;
            optwhere = 1;
        }
        return '?';
    }

    if (oli[1] != ':') {
        /* No argument */
        optarg = NULL;
        if (argv[optind][++optwhere] == '\0') {
            optind++;
            optwhere = 1;
        }
    } else {
        /* Argument required or optional */
        if (argv[optind][optwhere + 1] != '\0') {
            /* Argument is in this argv element */
            optarg = &argv[optind][optwhere + 1];
        } else if (oli[2] != ':') {
            /* Argument required, get next argv */
            if (++optind >= argc) {
                if (opterr && *optstring != ':')
                    fprintf(stderr, "%s: option requires an argument -- %c\n",
                            argv[0], optopt);
                optopt = '?';
                if (*optstring == ':')
                    return ':';
                return '?';
            }
            optarg = argv[optind];
        } else {
            /* Optional argument not present */
            optarg = NULL;
        }
        optind++;
        optwhere = 1;
    }

    return optopt;
}

int getopt_long(int argc, char *const argv[], const char *optstring,
                const struct option *longopts, int *longindex) {
    int i;
    const char *arg;

    if (optind == 0) {
        optind = 1;
        optwhere = 1;
    }

    if (optind >= argc || argv[optind] == NULL) {
        return -1;
    }

    arg = argv[optind];

    /* Check for -- prefix (long option) */
    if (arg[0] == '-' && arg[1] == '-') {
        const char *opt_start = arg + 2;
        const char *eq_pos;
        size_t opt_len;

        if (*opt_start == '\0') {
            /* Just "--" means end of options */
            optind++;
            return -1;
        }

        eq_pos = strchr(opt_start, '=');
        if (eq_pos != NULL) {
            opt_len = eq_pos - opt_start;
        } else {
            opt_len = strlen(opt_start);
        }

        for (i = 0; longopts[i].name != NULL; i++) {
            if (strncmp(longopts[i].name, opt_start, opt_len) == 0 &&
                longopts[i].name[opt_len] == '\0') {
                /* Found matching long option */
                if (longindex != NULL)
                    *longindex = i;

                if (longopts[i].has_arg == no_argument) {
                    if (eq_pos != NULL) {
                        if (opterr)
                            fprintf(stderr, "%s: option '--%s' doesn't allow an argument\n",
                                    argv[0], longopts[i].name);
                        optopt = '?';
                        optind++;
                        return '?';
                    }
                    optarg = NULL;
                } else if (longopts[i].has_arg == required_argument) {
                    if (eq_pos != NULL) {
                        optarg = (char *)(eq_pos + 1);
                    } else if (optind + 1 < argc) {
                        optarg = argv[++optind];
                    } else {
                        if (opterr)
                            fprintf(stderr, "%s: option '--%s' requires an argument\n",
                                    argv[0], longopts[i].name);
                        optopt = '?';
                        optind++;
                        return '?';
                    }
                } else { /* optional_argument */
                    if (eq_pos != NULL) {
                        optarg = (char *)(eq_pos + 1);
                    } else {
                        optarg = NULL;
                    }
                }

                optind++;

                if (longopts[i].flag != NULL) {
                    *longopts[i].flag = longopts[i].val;
                    return 0;
                }
                return longopts[i].val;
            }
        }

        /* Unknown long option */
        if (opterr)
            fprintf(stderr, "%s: unrecognized option '--%.*s'\n",
                    argv[0], (int)opt_len, opt_start);
        optopt = '?';
        optind++;
        return '?';
    }

    /* Not a long option, try short option */
    return getopt(argc, argv, optstring);
}

#endif /* _WIN32 */
