/*
 * getopt compatibility layer for Windows
 *
 * This provides a minimal getopt/getopt_long implementation for platforms
 * that don't have it (primarily Windows/MSVC).
 */

#ifndef GETOPT_COMPAT_H
#define GETOPT_COMPAT_H

#ifdef _WIN32

#ifdef __cplusplus
extern "C" {
#endif

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;

struct option {
    const char *name;
    int has_arg;
    int *flag;
    int val;
};

#define no_argument       0
#define required_argument 1
#define optional_argument 2

int getopt(int argc, char *const argv[], const char *optstring);
int getopt_long(int argc, char *const argv[], const char *optstring,
                const struct option *longopts, int *longindex);

#ifdef __cplusplus
}
#endif

#else
/* On Unix-like systems, use the system getopt */
#include <getopt.h>
#endif

#endif /* GETOPT_COMPAT_H */
