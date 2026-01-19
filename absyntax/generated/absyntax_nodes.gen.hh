// Generated file. Do not edit manually.
// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)

#pragma once

class invalid_type_name_c: public symbol_c {
public:
public:
  invalid_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "invalid_type_name_c";};
};

class disable_code_generation_pragma_c: public symbol_c {
public:
public:
  disable_code_generation_pragma_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "disable_code_generation_pragma_c";};
};

class enable_code_generation_pragma_c: public symbol_c {
public:
public:
  enable_code_generation_pragma_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "enable_code_generation_pragma_c";};
};

class pragma_c: public token_c {
public:
public:
  pragma_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "pragma_c";};
};

class library_c: public list_c {
public:
  enumvalue_symtable_t enumvalue_symtable;
public:
  library_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  library_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "library_c";};
};

class identifier_c: public token_c {
public:
public:
  identifier_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "identifier_c";};
};

class derived_datatype_identifier_c: public token_c {
public:
public:
  derived_datatype_identifier_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "derived_datatype_identifier_c";};
};

class poutype_identifier_c: public token_c {
public:
public:
  poutype_identifier_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "poutype_identifier_c";};
};

class ref_value_null_literal_c: public symbol_c {
public:
public:
  ref_value_null_literal_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ref_value_null_literal_c";};
};

class real_c: public token_c {
public:
public:
  real_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "real_c";};
};

class integer_c: public token_c {
public:
public:
  integer_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "integer_c";};
};

class binary_integer_c: public token_c {
public:
public:
  binary_integer_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "binary_integer_c";};
};

class octal_integer_c: public token_c {
public:
public:
  octal_integer_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "octal_integer_c";};
};

class hex_integer_c: public token_c {
public:
public:
  hex_integer_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "hex_integer_c";};
};

class neg_real_c: public symbol_c {
public:
  symbol_c *exp;
public:
  neg_real_c(symbol_c *exp,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "neg_real_c";};
};

class neg_integer_c: public symbol_c {
public:
  symbol_c *exp;
public:
  neg_integer_c(symbol_c *exp,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "neg_integer_c";};
};

class integer_literal_c: public symbol_c {
public:
  symbol_c *type;
  symbol_c *value;
public:
  integer_literal_c(symbol_c *type,
                 symbol_c *value = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "integer_literal_c";};
};

class real_literal_c: public symbol_c {
public:
  symbol_c *type;
  symbol_c *value;
public:
  real_literal_c(symbol_c *type,
                 symbol_c *value = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "real_literal_c";};
};

class bit_string_literal_c: public symbol_c {
public:
  symbol_c *type;
  symbol_c *value;
public:
  bit_string_literal_c(symbol_c *type,
                 symbol_c *value = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "bit_string_literal_c";};
};

class boolean_literal_c: public symbol_c {
public:
  symbol_c *type;
  symbol_c *value;
public:
  boolean_literal_c(symbol_c *type,
                 symbol_c *value = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "boolean_literal_c";};
};

class boolean_true_c: public symbol_c {
public:
public:
  boolean_true_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "boolean_true_c";};
};

class boolean_false_c: public symbol_c {
public:
public:
  boolean_false_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "boolean_false_c";};
};

class double_byte_character_string_c: public token_c {
public:
public:
  double_byte_character_string_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "double_byte_character_string_c";};
};

class single_byte_character_string_c: public token_c {
public:
public:
  single_byte_character_string_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "single_byte_character_string_c";};
};

class neg_time_c: public symbol_c {
public:
public:
  neg_time_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "neg_time_c";};
};

class duration_c: public symbol_c {
public:
  symbol_c *type_name;
  symbol_c *neg;
  symbol_c *interval;
public:
  duration_c(symbol_c *type_name,
                 symbol_c *neg,
                 symbol_c *interval,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "duration_c";};
};

class interval_c: public symbol_c {
public:
  symbol_c *days;
  symbol_c *hours;
  symbol_c *minutes;
  symbol_c *seconds;
  symbol_c *milliseconds;
public:
  interval_c(symbol_c *days,
                 symbol_c *hours,
                 symbol_c *minutes,
                 symbol_c *seconds,
                 symbol_c *milliseconds,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "interval_c";};
};

class fixed_point_c: public token_c {
public:
public:
  fixed_point_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "fixed_point_c";};
};

class time_of_day_c: public symbol_c {
public:
  symbol_c *type_name;
  symbol_c *daytime;
public:
  time_of_day_c(symbol_c *type_name,
                 symbol_c *daytime = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "time_of_day_c";};
};

class daytime_c: public symbol_c {
public:
  symbol_c *day_hour;
  symbol_c *day_minute;
  symbol_c *day_second;
public:
  daytime_c(symbol_c *day_hour,
                 symbol_c *day_minute,
                 symbol_c *day_second,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "daytime_c";};
};

class date_c: public symbol_c {
public:
  symbol_c *type_name;
  symbol_c *date_literal;
public:
  date_c(symbol_c *type_name,
                 symbol_c *date_literal = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "date_c";};
};

class date_literal_c: public symbol_c {
public:
  symbol_c *year;
  symbol_c *month;
  symbol_c *day;
public:
  date_literal_c(symbol_c *year,
                 symbol_c *month,
                 symbol_c *day,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "date_literal_c";};
};

class date_and_time_c: public symbol_c {
public:
  symbol_c *type_name;
  symbol_c *date_literal;
  symbol_c *daytime;
public:
  date_and_time_c(symbol_c *type_name,
                 symbol_c *date_literal,
                 symbol_c *daytime,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "date_and_time_c";};
};

class time_type_name_c: public symbol_c {
public:
public:
  time_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "time_type_name_c";};
};

class bool_type_name_c: public symbol_c {
public:
public:
  bool_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "bool_type_name_c";};
};

class sint_type_name_c: public symbol_c {
public:
public:
  sint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "sint_type_name_c";};
};

class int_type_name_c: public symbol_c {
public:
public:
  int_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "int_type_name_c";};
};

class dint_type_name_c: public symbol_c {
public:
public:
  dint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "dint_type_name_c";};
};

class lint_type_name_c: public symbol_c {
public:
public:
  lint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "lint_type_name_c";};
};

class usint_type_name_c: public symbol_c {
public:
public:
  usint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "usint_type_name_c";};
};

class uint_type_name_c: public symbol_c {
public:
public:
  uint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "uint_type_name_c";};
};

class udint_type_name_c: public symbol_c {
public:
public:
  udint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "udint_type_name_c";};
};

class ulint_type_name_c: public symbol_c {
public:
public:
  ulint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ulint_type_name_c";};
};

class real_type_name_c: public symbol_c {
public:
public:
  real_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "real_type_name_c";};
};

class lreal_type_name_c: public symbol_c {
public:
public:
  lreal_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "lreal_type_name_c";};
};

class date_type_name_c: public symbol_c {
public:
public:
  date_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "date_type_name_c";};
};

class tod_type_name_c: public symbol_c {
public:
public:
  tod_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "tod_type_name_c";};
};

class dt_type_name_c: public symbol_c {
public:
public:
  dt_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "dt_type_name_c";};
};

class byte_type_name_c: public symbol_c {
public:
public:
  byte_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "byte_type_name_c";};
};

class word_type_name_c: public symbol_c {
public:
public:
  word_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "word_type_name_c";};
};

class dword_type_name_c: public symbol_c {
public:
public:
  dword_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "dword_type_name_c";};
};

class lword_type_name_c: public symbol_c {
public:
public:
  lword_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "lword_type_name_c";};
};

class string_type_name_c: public symbol_c {
public:
public:
  string_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "string_type_name_c";};
};

class wstring_type_name_c: public symbol_c {
public:
public:
  wstring_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "wstring_type_name_c";};
};

class void_type_name_c: public symbol_c {
public:
public:
  void_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "void_type_name_c";};
};

class safetime_type_name_c: public symbol_c {
public:
public:
  safetime_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safetime_type_name_c";};
};

class safebool_type_name_c: public symbol_c {
public:
public:
  safebool_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safebool_type_name_c";};
};

class safesint_type_name_c: public symbol_c {
public:
public:
  safesint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safesint_type_name_c";};
};

class safeint_type_name_c: public symbol_c {
public:
public:
  safeint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safeint_type_name_c";};
};

class safedint_type_name_c: public symbol_c {
public:
public:
  safedint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safedint_type_name_c";};
};

class safelint_type_name_c: public symbol_c {
public:
public:
  safelint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safelint_type_name_c";};
};

class safeusint_type_name_c: public symbol_c {
public:
public:
  safeusint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safeusint_type_name_c";};
};

class safeuint_type_name_c: public symbol_c {
public:
public:
  safeuint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safeuint_type_name_c";};
};

class safeudint_type_name_c: public symbol_c {
public:
public:
  safeudint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safeudint_type_name_c";};
};

class safeulint_type_name_c: public symbol_c {
public:
public:
  safeulint_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safeulint_type_name_c";};
};

class safereal_type_name_c: public symbol_c {
public:
public:
  safereal_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safereal_type_name_c";};
};

class safelreal_type_name_c: public symbol_c {
public:
public:
  safelreal_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safelreal_type_name_c";};
};

class safedate_type_name_c: public symbol_c {
public:
public:
  safedate_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safedate_type_name_c";};
};

class safetod_type_name_c: public symbol_c {
public:
public:
  safetod_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safetod_type_name_c";};
};

class safedt_type_name_c: public symbol_c {
public:
public:
  safedt_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safedt_type_name_c";};
};

class safebyte_type_name_c: public symbol_c {
public:
public:
  safebyte_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safebyte_type_name_c";};
};

class safeword_type_name_c: public symbol_c {
public:
public:
  safeword_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safeword_type_name_c";};
};

class safedword_type_name_c: public symbol_c {
public:
public:
  safedword_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safedword_type_name_c";};
};

class safelword_type_name_c: public symbol_c {
public:
public:
  safelword_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safelword_type_name_c";};
};

class safestring_type_name_c: public symbol_c {
public:
public:
  safestring_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safestring_type_name_c";};
};

class safewstring_type_name_c: public symbol_c {
public:
public:
  safewstring_type_name_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "safewstring_type_name_c";};
};

class generic_type_any_c: public symbol_c {
public:
public:
  generic_type_any_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "generic_type_any_c";};
};

class data_type_declaration_c: public symbol_c {
public:
  symbol_c *type_declaration_list;
public:
  data_type_declaration_c(symbol_c *type_declaration_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "data_type_declaration_c";};
};

class type_declaration_list_c: public list_c {
public:
public:
  type_declaration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  type_declaration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "type_declaration_list_c";};
};

class simple_type_declaration_c: public symbol_c {
public:
  symbol_c *simple_type_name;
  symbol_c *simple_spec_init;
public:
  simple_type_declaration_c(symbol_c *simple_type_name,
                 symbol_c *simple_spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "simple_type_declaration_c";};
};

class simple_spec_init_c: public symbol_c {
public:
  symbol_c *simple_specification;
  symbol_c *constant;
public:
  simple_spec_init_c(symbol_c *simple_specification,
                 symbol_c *constant = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "simple_spec_init_c";};
};

class subrange_type_declaration_c: public symbol_c {
public:
  symbol_c *subrange_type_name;
  symbol_c *subrange_spec_init;
public:
  subrange_type_declaration_c(symbol_c *subrange_type_name,
                 symbol_c *subrange_spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "subrange_type_declaration_c";};
};

class subrange_spec_init_c: public symbol_c {
public:
  symbol_c *subrange_specification;
  symbol_c *signed_integer;
public:
  subrange_spec_init_c(symbol_c *subrange_specification,
                 symbol_c *signed_integer = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "subrange_spec_init_c";};
};

class subrange_specification_c: public symbol_c {
public:
  symbol_c *integer_type_name;
  symbol_c *subrange;
public:
  subrange_specification_c(symbol_c *integer_type_name,
                 symbol_c *subrange = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "subrange_specification_c";};
};

class subrange_c: public symbol_c {
public:
  symbol_c *lower_limit;
  symbol_c *upper_limit;
  unsigned long long int dimension;
public:
  subrange_c(symbol_c *lower_limit,
                 symbol_c *upper_limit = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "subrange_c";};
};

class enumerated_type_declaration_c: public symbol_c {
public:
  symbol_c *enumerated_type_name;
  symbol_c *enumerated_spec_init;
public:
  enumerated_type_declaration_c(symbol_c *enumerated_type_name,
                 symbol_c *enumerated_spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "enumerated_type_declaration_c";};
};

class enumerated_spec_init_c: public symbol_c {
public:
  symbol_c *enumerated_specification;
  symbol_c *enumerated_value;
public:
  enumerated_spec_init_c(symbol_c *enumerated_specification,
                 symbol_c *enumerated_value = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "enumerated_spec_init_c";};
};

class enumerated_value_list_c: public list_c {
public:
public:
  enumerated_value_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  enumerated_value_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "enumerated_value_list_c";};
};

class enumerated_value_c: public symbol_c {
public:
  symbol_c *type;
  symbol_c *value;
public:
  enumerated_value_c(symbol_c *type,
                 symbol_c *value = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "enumerated_value_c";};
};

class array_type_declaration_c: public symbol_c {
public:
  symbol_c *identifier;
  symbol_c *array_spec_init;
public:
  array_type_declaration_c(symbol_c *identifier,
                 symbol_c *array_spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_type_declaration_c";};
};

class array_spec_init_c: public symbol_c {
public:
  symbol_c *array_specification;
  symbol_c *array_initialization;
public:
  array_spec_init_c(symbol_c *array_specification,
                 symbol_c *array_initialization = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_spec_init_c";};
};

class array_specification_c: public symbol_c {
public:
  symbol_c *array_subrange_list;
  symbol_c *non_generic_type_name;
public:
  array_specification_c(symbol_c *array_subrange_list,
                 symbol_c *non_generic_type_name = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_specification_c";};
};

class array_subrange_list_c: public list_c {
public:
public:
  array_subrange_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  array_subrange_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_subrange_list_c";};
};

class array_initial_elements_list_c: public list_c {
public:
public:
  array_initial_elements_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  array_initial_elements_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_initial_elements_list_c";};
};

class array_initial_elements_c: public symbol_c {
public:
  symbol_c *integer;
  symbol_c *array_initial_element;
public:
  array_initial_elements_c(symbol_c *integer,
                 symbol_c *array_initial_element = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_initial_elements_c";};
};

class structure_type_declaration_c: public symbol_c {
public:
  symbol_c *structure_type_name;
  symbol_c *structure_specification;
public:
  structure_type_declaration_c(symbol_c *structure_type_name,
                 symbol_c *structure_specification = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structure_type_declaration_c";};
};

class initialized_structure_c: public symbol_c {
public:
  symbol_c *structure_type_name;
  symbol_c *structure_initialization;
public:
  initialized_structure_c(symbol_c *structure_type_name,
                 symbol_c *structure_initialization = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "initialized_structure_c";};
};

class structure_element_declaration_list_c: public list_c {
public:
public:
  structure_element_declaration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  structure_element_declaration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structure_element_declaration_list_c";};
};

class structure_element_declaration_c: public symbol_c {
public:
  symbol_c *structure_element_name;
  symbol_c *spec_init;
public:
  structure_element_declaration_c(symbol_c *structure_element_name,
                 symbol_c *spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structure_element_declaration_c";};
};

class structure_element_initialization_list_c: public list_c {
public:
public:
  structure_element_initialization_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  structure_element_initialization_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structure_element_initialization_list_c";};
};

class structure_element_initialization_c: public symbol_c {
public:
  symbol_c *structure_element_name;
  symbol_c *value;
public:
  structure_element_initialization_c(symbol_c *structure_element_name,
                 symbol_c *value = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structure_element_initialization_c";};
};

class string_type_declaration_c: public symbol_c {
public:
  symbol_c *string_type_name;
  symbol_c *elementary_string_type_name;
  symbol_c *string_type_declaration_size;
  symbol_c *string_type_declaration_init;
public:
  string_type_declaration_c(symbol_c *string_type_name,
                 symbol_c *elementary_string_type_name,
                 symbol_c *string_type_declaration_size,
                 symbol_c *string_type_declaration_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "string_type_declaration_c";};
};

class fb_spec_init_c: public symbol_c {
public:
  symbol_c *function_block_type_name;
  symbol_c *structure_initialization;
public:
  fb_spec_init_c(symbol_c *function_block_type_name,
                 symbol_c *structure_initialization = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "fb_spec_init_c";};
};

class ref_spec_c: public symbol_c {
public:
  symbol_c *type_name;
public:
  ref_spec_c(symbol_c *type_name,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ref_spec_c";};
};

class ref_spec_init_c: public symbol_c {
public:
  symbol_c *ref_spec;
  symbol_c *ref_initialization;
public:
  ref_spec_init_c(symbol_c *ref_spec,
                 symbol_c *ref_initialization = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ref_spec_init_c";};
};

class ref_type_decl_c: public symbol_c {
public:
  symbol_c *ref_type_name;
  symbol_c *ref_spec_init;
public:
  ref_type_decl_c(symbol_c *ref_type_name,
                 symbol_c *ref_spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ref_type_decl_c";};
};

class symbolic_variable_c: public symbol_c {
public:
  symbol_c *var_name;
public:
  symbolic_variable_c(symbol_c *var_name,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "symbolic_variable_c";};
};

class symbolic_constant_c: public symbol_c {
public:
  symbol_c *var_name;
public:
  symbolic_constant_c(symbol_c *var_name,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "symbolic_constant_c";};
};

class direct_variable_c: public token_c {
public:
public:
  direct_variable_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "direct_variable_c";};
};

class array_variable_c: public symbol_c {
public:
  symbol_c *subscripted_variable;
  symbol_c *subscript_list;
public:
  array_variable_c(symbol_c *subscripted_variable,
                 symbol_c *subscript_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_variable_c";};
};

class subscript_list_c: public list_c {
public:
public:
  subscript_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  subscript_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "subscript_list_c";};
};

class structured_variable_c: public symbol_c {
public:
  symbol_c *record_variable;
  symbol_c *field_selector;
public:
  structured_variable_c(symbol_c *record_variable,
                 symbol_c *field_selector = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structured_variable_c";};
};

class constant_option_c: public symbol_c {
public:
public:
  constant_option_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "constant_option_c";};
};

class retain_option_c: public symbol_c {
public:
public:
  retain_option_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "retain_option_c";};
};

class non_retain_option_c: public symbol_c {
public:
public:
  non_retain_option_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "non_retain_option_c";};
};

class input_declarations_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *input_declaration_list;
  symbol_c *method;
public:
  input_declarations_c(symbol_c *option,
                 symbol_c *input_declaration_list,
                 symbol_c *method,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "input_declarations_c";};
};

class input_declaration_list_c: public list_c {
public:
public:
  input_declaration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  input_declaration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "input_declaration_list_c";};
};

class implicit_definition_c: public symbol_c {
public:
public:
  implicit_definition_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "implicit_definition_c";};
};

class explicit_definition_c: public symbol_c {
public:
public:
  explicit_definition_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "explicit_definition_c";};
};

class en_param_declaration_c: public symbol_c {
public:
  symbol_c *name;
  symbol_c *type_decl;
  symbol_c *method;
public:
  en_param_declaration_c(symbol_c *name,
                 symbol_c *type_decl,
                 symbol_c *method,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "en_param_declaration_c";};
};

class eno_param_declaration_c: public symbol_c {
public:
  symbol_c *name;
  symbol_c *type;
  symbol_c *method;
public:
  eno_param_declaration_c(symbol_c *name,
                 symbol_c *type,
                 symbol_c *method,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "eno_param_declaration_c";};
};

class edge_declaration_c: public symbol_c {
public:
  symbol_c *edge;
  symbol_c *var1_list;
public:
  edge_declaration_c(symbol_c *edge,
                 symbol_c *var1_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "edge_declaration_c";};
};

class raising_edge_option_c: public symbol_c {
public:
public:
  raising_edge_option_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "raising_edge_option_c";};
};

class falling_edge_option_c: public symbol_c {
public:
public:
  falling_edge_option_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "falling_edge_option_c";};
};

class var1_init_decl_c: public symbol_c {
public:
  symbol_c *var1_list;
  symbol_c *spec_init;
public:
  var1_init_decl_c(symbol_c *var1_list,
                 symbol_c *spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "var1_init_decl_c";};
};

class var1_list_c: public list_c {
public:
public:
  var1_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  var1_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "var1_list_c";};
};

class extensible_input_parameter_c: public symbol_c {
public:
  symbol_c *var_name;
  symbol_c *first_index;
public:
  extensible_input_parameter_c(symbol_c *var_name,
                 symbol_c *first_index = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "extensible_input_parameter_c";};
};

class array_var_init_decl_c: public symbol_c {
public:
  symbol_c *var1_list;
  symbol_c *array_spec_init;
public:
  array_var_init_decl_c(symbol_c *var1_list,
                 symbol_c *array_spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_var_init_decl_c";};
};

class structured_var_init_decl_c: public symbol_c {
public:
  symbol_c *var1_list;
  symbol_c *initialized_structure;
public:
  structured_var_init_decl_c(symbol_c *var1_list,
                 symbol_c *initialized_structure = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structured_var_init_decl_c";};
};

class fb_name_decl_c: public symbol_c {
public:
  symbol_c *fb_name_list;
  symbol_c *fb_spec_init;
public:
  fb_name_decl_c(symbol_c *fb_name_list,
                 symbol_c *fb_spec_init = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "fb_name_decl_c";};
};

class fb_name_list_c: public list_c {
public:
public:
  fb_name_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  fb_name_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "fb_name_list_c";};
};

class output_declarations_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *var_init_decl_list;
  symbol_c *method;
public:
  output_declarations_c(symbol_c *option,
                 symbol_c *var_init_decl_list,
                 symbol_c *method,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "output_declarations_c";};
};

class input_output_declarations_c: public symbol_c {
public:
  symbol_c *var_declaration_list;
public:
  input_output_declarations_c(symbol_c *var_declaration_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "input_output_declarations_c";};
};

class var_declaration_list_c: public list_c {
public:
public:
  var_declaration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  var_declaration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "var_declaration_list_c";};
};

class array_var_declaration_c: public symbol_c {
public:
  symbol_c *var1_list;
  symbol_c *array_specification;
public:
  array_var_declaration_c(symbol_c *var1_list,
                 symbol_c *array_specification = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "array_var_declaration_c";};
};

class structured_var_declaration_c: public symbol_c {
public:
  symbol_c *var1_list;
  symbol_c *structure_type_name;
public:
  structured_var_declaration_c(symbol_c *var1_list,
                 symbol_c *structure_type_name = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "structured_var_declaration_c";};
};

class var_declarations_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *var_init_decl_list;
public:
  var_declarations_c(symbol_c *option,
                 symbol_c *var_init_decl_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "var_declarations_c";};
};

class retentive_var_declarations_c: public symbol_c {
public:
  symbol_c *var_init_decl_list;
public:
  retentive_var_declarations_c(symbol_c *var_init_decl_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "retentive_var_declarations_c";};
};

class located_var_declarations_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *located_var_decl_list;
public:
  located_var_declarations_c(symbol_c *option,
                 symbol_c *located_var_decl_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "located_var_declarations_c";};
};

class located_var_decl_list_c: public list_c {
public:
public:
  located_var_decl_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  located_var_decl_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "located_var_decl_list_c";};
};

class located_var_decl_c: public symbol_c {
public:
  symbol_c *variable_name;
  symbol_c *location;
  symbol_c *located_var_spec_init;
public:
  located_var_decl_c(symbol_c *variable_name,
                 symbol_c *location,
                 symbol_c *located_var_spec_init,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "located_var_decl_c";};
};

class external_var_declarations_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *external_declaration_list;
public:
  external_var_declarations_c(symbol_c *option,
                 symbol_c *external_declaration_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "external_var_declarations_c";};
};

class external_declaration_list_c: public list_c {
public:
public:
  external_declaration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  external_declaration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "external_declaration_list_c";};
};

class external_declaration_c: public symbol_c {
public:
  symbol_c *global_var_name;
  symbol_c *specification;
public:
  external_declaration_c(symbol_c *global_var_name,
                 symbol_c *specification = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "external_declaration_c";};
};

class global_var_declarations_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *global_var_decl_list;
public:
  global_var_declarations_c(symbol_c *option,
                 symbol_c *global_var_decl_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "global_var_declarations_c";};
};

class global_var_decl_list_c: public list_c {
public:
public:
  global_var_decl_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  global_var_decl_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "global_var_decl_list_c";};
};

class global_var_decl_c: public symbol_c {
public:
  symbol_c *global_var_spec;
  symbol_c *type_specification;
public:
  global_var_decl_c(symbol_c *global_var_spec,
                 symbol_c *type_specification = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "global_var_decl_c";};
};

class global_var_spec_c: public symbol_c {
public:
  symbol_c *global_var_name;
  symbol_c *location;
public:
  global_var_spec_c(symbol_c *global_var_name,
                 symbol_c *location = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "global_var_spec_c";};
};

class location_c: public symbol_c {
public:
  symbol_c *direct_variable;
public:
  location_c(symbol_c *direct_variable,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "location_c";};
};

class global_var_list_c: public list_c {
public:
public:
  global_var_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  global_var_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "global_var_list_c";};
};

class single_byte_string_var_declaration_c: public symbol_c {
public:
  symbol_c *var1_list;
  symbol_c *single_byte_string_spec;
public:
  single_byte_string_var_declaration_c(symbol_c *var1_list,
                 symbol_c *single_byte_string_spec = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "single_byte_string_var_declaration_c";};
};

class single_byte_string_spec_c: public symbol_c {
public:
  symbol_c *string_spec;
  symbol_c *single_byte_character_string;
public:
  single_byte_string_spec_c(symbol_c *string_spec,
                 symbol_c *single_byte_character_string = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "single_byte_string_spec_c";};
};

class single_byte_limited_len_string_spec_c: public symbol_c {
public:
  symbol_c *string_type_name;
  symbol_c *character_string_len;
public:
  single_byte_limited_len_string_spec_c(symbol_c *string_type_name,
                 symbol_c *character_string_len = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "single_byte_limited_len_string_spec_c";};
};

class double_byte_limited_len_string_spec_c: public symbol_c {
public:
  symbol_c *string_type_name;
  symbol_c *character_string_len;
public:
  double_byte_limited_len_string_spec_c(symbol_c *string_type_name,
                 symbol_c *character_string_len = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "double_byte_limited_len_string_spec_c";};
};

class double_byte_string_var_declaration_c: public symbol_c {
public:
  symbol_c *var1_list;
  symbol_c *double_byte_string_spec;
public:
  double_byte_string_var_declaration_c(symbol_c *var1_list,
                 symbol_c *double_byte_string_spec = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "double_byte_string_var_declaration_c";};
};

class double_byte_string_spec_c: public symbol_c {
public:
  symbol_c *string_spec;
  symbol_c *double_byte_character_string;
public:
  double_byte_string_spec_c(symbol_c *string_spec,
                 symbol_c *double_byte_character_string = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "double_byte_string_spec_c";};
};

class incompl_located_var_declarations_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *incompl_located_var_decl_list;
public:
  incompl_located_var_declarations_c(symbol_c *option,
                 symbol_c *incompl_located_var_decl_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "incompl_located_var_declarations_c";};
};

class incompl_located_var_decl_list_c: public list_c {
public:
public:
  incompl_located_var_decl_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  incompl_located_var_decl_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "incompl_located_var_decl_list_c";};
};

class incompl_located_var_decl_c: public symbol_c {
public:
  symbol_c *variable_name;
  symbol_c *incompl_location;
  symbol_c *var_spec;
public:
  incompl_located_var_decl_c(symbol_c *variable_name,
                 symbol_c *incompl_location,
                 symbol_c *var_spec,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "incompl_located_var_decl_c";};
};

class incompl_location_c: public token_c {
public:
public:
  incompl_location_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "incompl_location_c";};
};

class var_init_decl_list_c: public list_c {
public:
public:
  var_init_decl_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  var_init_decl_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "var_init_decl_list_c";};
};

class function_declaration_c: public symbol_c {
public:
  symbol_c *derived_function_name;
  symbol_c *type_name;
  symbol_c *var_declarations_list;
  symbol_c *function_body;
  enumvalue_symtable_t enumvalue_symtable;
public:
  function_declaration_c(symbol_c *derived_function_name,
                 symbol_c *type_name,
                 symbol_c *var_declarations_list,
                 symbol_c *function_body = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "function_declaration_c";};
};

class var_declarations_list_c: public list_c {
public:
public:
  var_declarations_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  var_declarations_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "var_declarations_list_c";};
};

class function_var_decls_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *decl_list;
public:
  function_var_decls_c(symbol_c *option,
                 symbol_c *decl_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "function_var_decls_c";};
};

class var2_init_decl_list_c: public list_c {
public:
public:
  var2_init_decl_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  var2_init_decl_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "var2_init_decl_list_c";};
};

class function_block_declaration_c: public symbol_c {
public:
  symbol_c *fblock_name;
  symbol_c *var_declarations;
  symbol_c *fblock_body;
  enumvalue_symtable_t enumvalue_symtable;
public:
  function_block_declaration_c(symbol_c *fblock_name,
                 symbol_c *var_declarations,
                 symbol_c *fblock_body,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "function_block_declaration_c";};
};

class temp_var_decls_c: public symbol_c {
public:
  symbol_c *var_decl_list;
public:
  temp_var_decls_c(symbol_c *var_decl_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "temp_var_decls_c";};
};

class temp_var_decls_list_c: public list_c {
public:
public:
  temp_var_decls_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  temp_var_decls_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "temp_var_decls_list_c";};
};

class non_retentive_var_decls_c: public symbol_c {
public:
  symbol_c *var_decl_list;
public:
  non_retentive_var_decls_c(symbol_c *var_decl_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "non_retentive_var_decls_c";};
};

class program_declaration_c: public symbol_c {
public:
  symbol_c *program_type_name;
  symbol_c *var_declarations;
  symbol_c *function_block_body;
  enumvalue_symtable_t enumvalue_symtable;
public:
  program_declaration_c(symbol_c *program_type_name,
                 symbol_c *var_declarations,
                 symbol_c *function_block_body,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "program_declaration_c";};
};

class sequential_function_chart_c: public list_c {
public:
public:
  sequential_function_chart_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  sequential_function_chart_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "sequential_function_chart_c";};
};

class sfc_network_c: public list_c {
public:
public:
  sfc_network_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  sfc_network_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "sfc_network_c";};
};

class initial_step_c: public symbol_c {
public:
  symbol_c *step_name;
  symbol_c *action_association_list;
public:
  initial_step_c(symbol_c *step_name,
                 symbol_c *action_association_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "initial_step_c";};
};

class action_association_list_c: public list_c {
public:
public:
  action_association_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  action_association_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "action_association_list_c";};
};

class step_c: public symbol_c {
public:
  symbol_c *step_name;
  symbol_c *action_association_list;
public:
  step_c(symbol_c *step_name,
                 symbol_c *action_association_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "step_c";};
};

class action_association_c: public symbol_c {
public:
  symbol_c *action_name;
  symbol_c *action_qualifier;
  symbol_c *indicator_name_list;
public:
  action_association_c(symbol_c *action_name,
                 symbol_c *action_qualifier,
                 symbol_c *indicator_name_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "action_association_c";};
};

class qualifier_c: public token_c {
public:
public:
  qualifier_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "qualifier_c";};
};

class timed_qualifier_c: public token_c {
public:
public:
  timed_qualifier_c(const char *value,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "timed_qualifier_c";};
};

class indicator_name_list_c: public list_c {
public:
public:
  indicator_name_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  indicator_name_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "indicator_name_list_c";};
};

class action_qualifier_c: public symbol_c {
public:
  symbol_c *action_qualifier;
  symbol_c *action_time;
public:
  action_qualifier_c(symbol_c *action_qualifier,
                 symbol_c *action_time = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "action_qualifier_c";};
};

class transition_c: public symbol_c {
public:
  symbol_c *transition_name;
  symbol_c *integer;
  symbol_c *from_steps;
  symbol_c *to_steps;
  symbol_c *transition_condition;
public:
  transition_c(symbol_c *transition_name,
                 symbol_c *integer,
                 symbol_c *from_steps,
                 symbol_c *to_steps,
                 symbol_c *transition_condition,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "transition_c";};
};

class transition_condition_c: public symbol_c {
public:
  symbol_c *transition_condition_il;
  symbol_c *transition_condition_st;
public:
  transition_condition_c(symbol_c *transition_condition_il,
                 symbol_c *transition_condition_st = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "transition_condition_c";};
};

class steps_c: public symbol_c {
public:
  symbol_c *step_name;
  symbol_c *step_name_list;
public:
  steps_c(symbol_c *step_name,
                 symbol_c *step_name_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "steps_c";};
};

class step_name_list_c: public list_c {
public:
public:
  step_name_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  step_name_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "step_name_list_c";};
};

class action_c: public symbol_c {
public:
  symbol_c *action_name;
  symbol_c *function_block_body;
public:
  action_c(symbol_c *action_name,
                 symbol_c *function_block_body = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "action_c";};
};

class configuration_declaration_c: public symbol_c {
public:
  symbol_c *configuration_name;
  symbol_c *global_var_declarations;
  symbol_c *resource_declarations;
  symbol_c *access_declarations;
  symbol_c *instance_specific_initializations;
  enumvalue_symtable_t enumvalue_symtable;
public:
  configuration_declaration_c(symbol_c *configuration_name,
                 symbol_c *global_var_declarations,
                 symbol_c *resource_declarations,
                 symbol_c *access_declarations,
                 symbol_c *instance_specific_initializations,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "configuration_declaration_c";};
};

class global_var_declarations_list_c: public list_c {
public:
public:
  global_var_declarations_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  global_var_declarations_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "global_var_declarations_list_c";};
};

class resource_declaration_list_c: public list_c {
public:
public:
  resource_declaration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  resource_declaration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "resource_declaration_list_c";};
};

class resource_declaration_c: public symbol_c {
public:
  symbol_c *resource_name;
  symbol_c *resource_type_name;
  symbol_c *global_var_declarations;
  symbol_c *resource_declaration;
  enumvalue_symtable_t enumvalue_symtable;
public:
  resource_declaration_c(symbol_c *resource_name,
                 symbol_c *resource_type_name,
                 symbol_c *global_var_declarations,
                 symbol_c *resource_declaration = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "resource_declaration_c";};
};

class single_resource_declaration_c: public symbol_c {
public:
  symbol_c *task_configuration_list;
  symbol_c *program_configuration_list;
public:
  single_resource_declaration_c(symbol_c *task_configuration_list,
                 symbol_c *program_configuration_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "single_resource_declaration_c";};
};

class task_configuration_list_c: public list_c {
public:
public:
  task_configuration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  task_configuration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "task_configuration_list_c";};
};

class program_configuration_list_c: public list_c {
public:
public:
  program_configuration_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  program_configuration_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "program_configuration_list_c";};
};

class any_fb_name_list_c: public list_c {
public:
public:
  any_fb_name_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  any_fb_name_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "any_fb_name_list_c";};
};

class global_var_reference_c: public symbol_c {
public:
  symbol_c *resource_name;
  symbol_c *global_var_name;
  symbol_c *structure_element_name;
public:
  global_var_reference_c(symbol_c *resource_name,
                 symbol_c *global_var_name,
                 symbol_c *structure_element_name,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "global_var_reference_c";};
};

class program_output_reference_c: public symbol_c {
public:
  symbol_c *program_name;
  symbol_c *symbolic_variable;
public:
  program_output_reference_c(symbol_c *program_name,
                 symbol_c *symbolic_variable = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "program_output_reference_c";};
};

class task_configuration_c: public symbol_c {
public:
  symbol_c *task_name;
  symbol_c *task_initialization;
public:
  task_configuration_c(symbol_c *task_name,
                 symbol_c *task_initialization = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "task_configuration_c";};
};

class task_initialization_c: public symbol_c {
public:
  symbol_c *single_data_source;
  symbol_c *interval_data_source;
  symbol_c *priority_data_source;
public:
  task_initialization_c(symbol_c *single_data_source,
                 symbol_c *interval_data_source,
                 symbol_c *priority_data_source,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "task_initialization_c";};
};

class program_configuration_c: public symbol_c {
public:
  symbol_c *retain_option;
  symbol_c *program_name;
  symbol_c *task_name;
  symbol_c *program_type_name;
  symbol_c *prog_conf_elements;
public:
  program_configuration_c(symbol_c *retain_option,
                 symbol_c *program_name,
                 symbol_c *task_name,
                 symbol_c *program_type_name,
                 symbol_c *prog_conf_elements,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "program_configuration_c";};
};

class prog_conf_elements_c: public list_c {
public:
public:
  prog_conf_elements_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  prog_conf_elements_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "prog_conf_elements_c";};
};

class fb_task_c: public symbol_c {
public:
  symbol_c *fb_name;
  symbol_c *task_name;
public:
  fb_task_c(symbol_c *fb_name,
                 symbol_c *task_name = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "fb_task_c";};
};

class prog_cnxn_assign_c: public symbol_c {
public:
  symbol_c *symbolic_variable;
  symbol_c *prog_data_source;
public:
  prog_cnxn_assign_c(symbol_c *symbolic_variable,
                 symbol_c *prog_data_source = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "prog_cnxn_assign_c";};
};

class prog_cnxn_sendto_c: public symbol_c {
public:
  symbol_c *symbolic_variable;
  symbol_c *data_sink;
public:
  prog_cnxn_sendto_c(symbol_c *symbolic_variable,
                 symbol_c *data_sink = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "prog_cnxn_sendto_c";};
};

class instance_specific_initializations_c: public symbol_c {
public:
  symbol_c *instance_specific_init_list;
public:
  instance_specific_initializations_c(symbol_c *instance_specific_init_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "instance_specific_initializations_c";};
};

class instance_specific_init_list_c: public list_c {
public:
public:
  instance_specific_init_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  instance_specific_init_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "instance_specific_init_list_c";};
};

class instance_specific_init_c: public symbol_c {
public:
  symbol_c *resource_name;
  symbol_c *program_name;
  symbol_c *any_fb_name_list;
  symbol_c *variable_name;
  symbol_c *location;
  symbol_c *initialization;
public:
  instance_specific_init_c(symbol_c *resource_name,
                 symbol_c *program_name,
                 symbol_c *any_fb_name_list,
                 symbol_c *variable_name,
                 symbol_c *location,
                 symbol_c *initialization = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "instance_specific_init_c";};
};

class fb_initialization_c: public symbol_c {
public:
  symbol_c *function_block_type_name;
  symbol_c *structure_initialization;
public:
  fb_initialization_c(symbol_c *function_block_type_name,
                 symbol_c *structure_initialization = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "fb_initialization_c";};
};

class instruction_list_c: public list_c {
public:
public:
  instruction_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  instruction_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "instruction_list_c";};
};

class il_instruction_c: public symbol_c {
public:
  symbol_c *label;
  symbol_c *il_instruction;
  std::vector <symbol_c *> prev_il_instruction, next_il_instruction;
public:
  il_instruction_c(symbol_c *label,
                 symbol_c *il_instruction = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_instruction_c";};
};

class il_simple_operation_c: public symbol_c {
public:
  symbol_c *il_simple_operator;
  symbol_c *il_operand;
public:
  il_simple_operation_c(symbol_c *il_simple_operator,
                 symbol_c *il_operand = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_simple_operation_c";};
};

class il_function_call_c: public symbol_c {
public:
  symbol_c *function_name;
  symbol_c *il_operand_list;
  symbol_c *called_function_declaration; int extensible_param_count; std::vector <symbol_c *> candidate_functions;
public:
  il_function_call_c(symbol_c *function_name,
                 symbol_c *il_operand_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_function_call_c";};
};

class il_expression_c: public symbol_c {
public:
  symbol_c *il_expr_operator;
  symbol_c *il_operand;
  symbol_c *simple_instr_list;
public:
  il_expression_c(symbol_c *il_expr_operator,
                 symbol_c *il_operand,
                 symbol_c *simple_instr_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_expression_c";};
};

class il_jump_operation_c: public symbol_c {
public:
  symbol_c *il_jump_operator;
  symbol_c *label;
public:
  il_jump_operation_c(symbol_c *il_jump_operator,
                 symbol_c *label = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_jump_operation_c";};
};

class il_fb_call_c: public symbol_c {
public:
  symbol_c *il_call_operator;
  symbol_c *fb_name;
  symbol_c *il_operand_list;
  symbol_c *il_param_list;
  symbol_c *called_fb_declaration;
public:
  il_fb_call_c(symbol_c *il_call_operator,
                 symbol_c *fb_name,
                 symbol_c *il_operand_list,
                 symbol_c *il_param_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_fb_call_c";};
};

class il_formal_funct_call_c: public symbol_c {
public:
  symbol_c *function_name;
  symbol_c *il_param_list;
  symbol_c *called_function_declaration; int extensible_param_count; std::vector <symbol_c *> candidate_functions;
public:
  il_formal_funct_call_c(symbol_c *function_name,
                 symbol_c *il_param_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_formal_funct_call_c";};
};

class il_operand_list_c: public list_c {
public:
public:
  il_operand_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  il_operand_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_operand_list_c";};
};

class simple_instr_list_c: public list_c {
public:
public:
  simple_instr_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  simple_instr_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "simple_instr_list_c";};
};

class il_simple_instruction_c: public symbol_c {
public:
  symbol_c *il_simple_instruction;
  std::vector <symbol_c *> prev_il_instruction, next_il_instruction;
public:
  il_simple_instruction_c(symbol_c *il_simple_instruction,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_simple_instruction_c";};
};

class il_param_list_c: public list_c {
public:
public:
  il_param_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  il_param_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_param_list_c";};
};

class il_param_assignment_c: public symbol_c {
public:
  symbol_c *il_assign_operator;
  symbol_c *il_operand;
  symbol_c *simple_instr_list;
public:
  il_param_assignment_c(symbol_c *il_assign_operator,
                 symbol_c *il_operand,
                 symbol_c *simple_instr_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_param_assignment_c";};
};

class il_param_out_assignment_c: public symbol_c {
public:
  symbol_c *il_assign_out_operator;
  symbol_c *variable;
public:
  il_param_out_assignment_c(symbol_c *il_assign_out_operator,
                 symbol_c *variable = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_param_out_assignment_c";};
};

class LD_operator_c: public symbol_c {
public:
public:
  LD_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "LD_operator_c";};
};

class LDN_operator_c: public symbol_c {
public:
public:
  LDN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "LDN_operator_c";};
};

class ST_operator_c: public symbol_c {
public:
public:
  ST_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ST_operator_c";};
};

class STN_operator_c: public symbol_c {
public:
public:
  STN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "STN_operator_c";};
};

class NOT_operator_c: public symbol_c {
public:
public:
  NOT_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "NOT_operator_c";};
};

class S_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  S_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "S_operator_c";};
};

class R_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  R_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "R_operator_c";};
};

class S1_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  S1_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "S1_operator_c";};
};

class R1_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  R1_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "R1_operator_c";};
};

class CLK_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  CLK_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "CLK_operator_c";};
};

class CU_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  CU_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "CU_operator_c";};
};

class CD_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  CD_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "CD_operator_c";};
};

class PV_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  PV_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "PV_operator_c";};
};

class IN_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  IN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "IN_operator_c";};
};

class PT_operator_c: public symbol_c {
public:
  symbol_c *called_fb_declaration;
public:
  PT_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "PT_operator_c";};
};

class AND_operator_c: public symbol_c {
public:
public:
  AND_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "AND_operator_c";};
};

class OR_operator_c: public symbol_c {
public:
public:
  OR_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "OR_operator_c";};
};

class XOR_operator_c: public symbol_c {
public:
public:
  XOR_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "XOR_operator_c";};
};

class ANDN_operator_c: public symbol_c {
public:
public:
  ANDN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ANDN_operator_c";};
};

class ORN_operator_c: public symbol_c {
public:
public:
  ORN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ORN_operator_c";};
};

class XORN_operator_c: public symbol_c {
public:
public:
  XORN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "XORN_operator_c";};
};

class ADD_operator_c: public symbol_c {
public:
  bool deprecated_operation;
public:
  ADD_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ADD_operator_c";};
};

class SUB_operator_c: public symbol_c {
public:
  bool deprecated_operation;
public:
  SUB_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "SUB_operator_c";};
};

class MUL_operator_c: public symbol_c {
public:
  bool deprecated_operation;
public:
  MUL_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "MUL_operator_c";};
};

class DIV_operator_c: public symbol_c {
public:
  bool deprecated_operation;
public:
  DIV_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "DIV_operator_c";};
};

class MOD_operator_c: public symbol_c {
public:
public:
  MOD_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "MOD_operator_c";};
};

class GT_operator_c: public symbol_c {
public:
public:
  GT_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "GT_operator_c";};
};

class GE_operator_c: public symbol_c {
public:
public:
  GE_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "GE_operator_c";};
};

class EQ_operator_c: public symbol_c {
public:
public:
  EQ_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "EQ_operator_c";};
};

class LT_operator_c: public symbol_c {
public:
public:
  LT_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "LT_operator_c";};
};

class LE_operator_c: public symbol_c {
public:
public:
  LE_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "LE_operator_c";};
};

class NE_operator_c: public symbol_c {
public:
public:
  NE_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "NE_operator_c";};
};

class CAL_operator_c: public symbol_c {
public:
public:
  CAL_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "CAL_operator_c";};
};

class CALC_operator_c: public symbol_c {
public:
public:
  CALC_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "CALC_operator_c";};
};

class CALCN_operator_c: public symbol_c {
public:
public:
  CALCN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "CALCN_operator_c";};
};

class RET_operator_c: public symbol_c {
public:
public:
  RET_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "RET_operator_c";};
};

class RETC_operator_c: public symbol_c {
public:
public:
  RETC_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "RETC_operator_c";};
};

class RETCN_operator_c: public symbol_c {
public:
public:
  RETCN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "RETCN_operator_c";};
};

class JMP_operator_c: public symbol_c {
public:
public:
  JMP_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "JMP_operator_c";};
};

class JMPC_operator_c: public symbol_c {
public:
public:
  JMPC_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "JMPC_operator_c";};
};

class JMPCN_operator_c: public symbol_c {
public:
public:
  JMPCN_operator_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "JMPCN_operator_c";};
};

class il_assign_operator_c: public symbol_c {
public:
  symbol_c *variable_name;
public:
  il_assign_operator_c(symbol_c *variable_name,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_assign_operator_c";};
};

class il_assign_out_operator_c: public symbol_c {
public:
  symbol_c *option;
  symbol_c *variable_name;
public:
  il_assign_out_operator_c(symbol_c *option,
                 symbol_c *variable_name = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "il_assign_out_operator_c";};
};

class ref_expression_c: public symbol_c {
public:
  symbol_c *exp;
public:
  ref_expression_c(symbol_c *exp,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ref_expression_c";};
};

class deref_expression_c: public symbol_c {
public:
  symbol_c *exp;
public:
  deref_expression_c(symbol_c *exp,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "deref_expression_c";};
};

class deref_operator_c: public symbol_c {
public:
  symbol_c *exp;
public:
  deref_operator_c(symbol_c *exp,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "deref_operator_c";};
};

class or_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  or_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "or_expression_c";};
};

class xor_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  xor_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "xor_expression_c";};
};

class and_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  and_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "and_expression_c";};
};

class equ_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  equ_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "equ_expression_c";};
};

class notequ_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  notequ_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "notequ_expression_c";};
};

class lt_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  lt_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "lt_expression_c";};
};

class gt_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  gt_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "gt_expression_c";};
};

class le_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  le_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "le_expression_c";};
};

class ge_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  ge_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "ge_expression_c";};
};

class add_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
  bool deprecated_operation;
public:
  add_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "add_expression_c";};
};

class sub_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
  bool deprecated_operation;
public:
  sub_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "sub_expression_c";};
};

class mul_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
  bool deprecated_operation;
public:
  mul_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "mul_expression_c";};
};

class div_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
  bool deprecated_operation;
public:
  div_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "div_expression_c";};
};

class mod_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  mod_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "mod_expression_c";};
};

class power_expression_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  power_expression_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "power_expression_c";};
};

class neg_expression_c: public symbol_c {
public:
  symbol_c *exp;
public:
  neg_expression_c(symbol_c *exp,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "neg_expression_c";};
};

class not_expression_c: public symbol_c {
public:
  symbol_c *exp;
public:
  not_expression_c(symbol_c *exp,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "not_expression_c";};
};

class function_invocation_c: public symbol_c {
public:
  symbol_c *function_name;
  symbol_c *formal_param_list;
  symbol_c *nonformal_param_list;
  symbol_c *called_function_declaration; int extensible_param_count; std::vector <symbol_c *> candidate_functions;
public:
  function_invocation_c(symbol_c *function_name,
                 symbol_c *formal_param_list,
                 symbol_c *nonformal_param_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "function_invocation_c";};
};

class statement_list_c: public list_c {
public:
public:
  statement_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  statement_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "statement_list_c";};
};

class assignment_statement_c: public symbol_c {
public:
  symbol_c *l_exp;
  symbol_c *r_exp;
public:
  assignment_statement_c(symbol_c *l_exp,
                 symbol_c *r_exp = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "assignment_statement_c";};
};

class return_statement_c: public symbol_c {
public:
public:
  return_statement_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "return_statement_c";};
};

class fb_invocation_c: public symbol_c {
public:
  symbol_c *fb_name;
  symbol_c *formal_param_list;
  symbol_c *nonformal_param_list;
  symbol_c *called_fb_declaration;
public:
  fb_invocation_c(symbol_c *fb_name,
                 symbol_c *formal_param_list,
                 symbol_c *nonformal_param_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "fb_invocation_c";};
};

class param_assignment_list_c: public list_c {
public:
public:
  param_assignment_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  param_assignment_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "param_assignment_list_c";};
};

class input_variable_param_assignment_c: public symbol_c {
public:
  symbol_c *variable_name;
  symbol_c *expression;
public:
  input_variable_param_assignment_c(symbol_c *variable_name,
                 symbol_c *expression = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "input_variable_param_assignment_c";};
};

class output_variable_param_assignment_c: public symbol_c {
public:
  symbol_c *not_param;
  symbol_c *variable_name;
  symbol_c *variable;
public:
  output_variable_param_assignment_c(symbol_c *not_param,
                 symbol_c *variable_name,
                 symbol_c *variable,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "output_variable_param_assignment_c";};
};

class not_paramassign_c: public symbol_c {
public:
public:
  not_paramassign_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "not_paramassign_c";};
};

class if_statement_c: public symbol_c {
public:
  symbol_c *expression;
  symbol_c *statement_list;
  symbol_c *elseif_statement_list;
  symbol_c *else_statement_list;
public:
  if_statement_c(symbol_c *expression,
                 symbol_c *statement_list,
                 symbol_c *elseif_statement_list,
                 symbol_c *else_statement_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "if_statement_c";};
};

class elseif_statement_list_c: public list_c {
public:
public:
  elseif_statement_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  elseif_statement_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "elseif_statement_list_c";};
};

class elseif_statement_c: public symbol_c {
public:
  symbol_c *expression;
  symbol_c *statement_list;
public:
  elseif_statement_c(symbol_c *expression,
                 symbol_c *statement_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "elseif_statement_c";};
};

class case_statement_c: public symbol_c {
public:
  symbol_c *expression;
  symbol_c *case_element_list;
  symbol_c *statement_list;
public:
  case_statement_c(symbol_c *expression,
                 symbol_c *case_element_list,
                 symbol_c *statement_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "case_statement_c";};
};

class case_element_list_c: public list_c {
public:
public:
  case_element_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  case_element_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "case_element_list_c";};
};

class case_element_c: public symbol_c {
public:
  symbol_c *case_list;
  symbol_c *statement_list;
public:
  case_element_c(symbol_c *case_list,
                 symbol_c *statement_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "case_element_c";};
};

class case_list_c: public list_c {
public:
public:
  case_list_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  case_list_c(symbol_c *elem,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "case_list_c";};
};

class for_statement_c: public symbol_c {
public:
  symbol_c *control_variable;
  symbol_c *beg_expression;
  symbol_c *end_expression;
  symbol_c *by_expression;
  symbol_c *statement_list;
public:
  for_statement_c(symbol_c *control_variable,
                 symbol_c *beg_expression,
                 symbol_c *end_expression,
                 symbol_c *by_expression,
                 symbol_c *statement_list,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "for_statement_c";};
};

class while_statement_c: public symbol_c {
public:
  symbol_c *expression;
  symbol_c *statement_list;
public:
  while_statement_c(symbol_c *expression,
                 symbol_c *statement_list = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "while_statement_c";};
};

class repeat_statement_c: public symbol_c {
public:
  symbol_c *statement_list;
  symbol_c *expression;
public:
  repeat_statement_c(symbol_c *statement_list,
                 symbol_c *expression = NULL,
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "repeat_statement_c";};
};

class exit_statement_c: public symbol_c {
public:
public:
  exit_statement_c(
                 int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,
                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0);
  virtual void *accept(visitor_c &visitor);
  virtual const char *absyntax_cname(void) {return "exit_statement_c";};
};

