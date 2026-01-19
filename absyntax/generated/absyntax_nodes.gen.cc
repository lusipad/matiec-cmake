// Generated file. Do not edit manually.
// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)

#include "absyntax.hh"
#include "visitor.hh"

invalid_type_name_c::invalid_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *invalid_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

disable_code_generation_pragma_c::disable_code_generation_pragma_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *disable_code_generation_pragma_c::accept(visitor_c &visitor) {return visitor.visit(this);}

enable_code_generation_pragma_c::enable_code_generation_pragma_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *enable_code_generation_pragma_c::accept(visitor_c &visitor) {return visitor.visit(this);}

pragma_c::pragma_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *pragma_c::accept(visitor_c &visitor) {return visitor.visit(this);}

library_c::library_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

library_c::library_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *library_c::accept(visitor_c &visitor) {return visitor.visit(this);}

identifier_c::identifier_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *identifier_c::accept(visitor_c &visitor) {return visitor.visit(this);}

derived_datatype_identifier_c::derived_datatype_identifier_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *derived_datatype_identifier_c::accept(visitor_c &visitor) {return visitor.visit(this);}

poutype_identifier_c::poutype_identifier_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *poutype_identifier_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ref_value_null_literal_c::ref_value_null_literal_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *ref_value_null_literal_c::accept(visitor_c &visitor) {return visitor.visit(this);}

real_c::real_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *real_c::accept(visitor_c &visitor) {return visitor.visit(this);}

integer_c::integer_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *integer_c::accept(visitor_c &visitor) {return visitor.visit(this);}

binary_integer_c::binary_integer_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *binary_integer_c::accept(visitor_c &visitor) {return visitor.visit(this);}

octal_integer_c::octal_integer_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *octal_integer_c::accept(visitor_c &visitor) {return visitor.visit(this);}

hex_integer_c::hex_integer_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *hex_integer_c::accept(visitor_c &visitor) {return visitor.visit(this);}

neg_real_c::neg_real_c(symbol_c *exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->exp = exp;
  if  (NULL != exp)   exp->parent = this;
}
void *neg_real_c::accept(visitor_c &visitor) {return visitor.visit(this);}

neg_integer_c::neg_integer_c(symbol_c *exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->exp = exp;
  if  (NULL != exp)   exp->parent = this;
}
void *neg_integer_c::accept(visitor_c &visitor) {return visitor.visit(this);}

integer_literal_c::integer_literal_c(symbol_c *type,
                           symbol_c *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type = type;
  this->value = value;
  if  (NULL != type)   type->parent = this;
  if  (NULL != value)   value->parent = this;
}
void *integer_literal_c::accept(visitor_c &visitor) {return visitor.visit(this);}

real_literal_c::real_literal_c(symbol_c *type,
                           symbol_c *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type = type;
  this->value = value;
  if  (NULL != type)   type->parent = this;
  if  (NULL != value)   value->parent = this;
}
void *real_literal_c::accept(visitor_c &visitor) {return visitor.visit(this);}

bit_string_literal_c::bit_string_literal_c(symbol_c *type,
                           symbol_c *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type = type;
  this->value = value;
  if  (NULL != type)   type->parent = this;
  if  (NULL != value)   value->parent = this;
}
void *bit_string_literal_c::accept(visitor_c &visitor) {return visitor.visit(this);}

boolean_literal_c::boolean_literal_c(symbol_c *type,
                           symbol_c *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type = type;
  this->value = value;
  if  (NULL != type)   type->parent = this;
  if  (NULL != value)   value->parent = this;
}
void *boolean_literal_c::accept(visitor_c &visitor) {return visitor.visit(this);}

boolean_true_c::boolean_true_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *boolean_true_c::accept(visitor_c &visitor) {return visitor.visit(this);}

boolean_false_c::boolean_false_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *boolean_false_c::accept(visitor_c &visitor) {return visitor.visit(this);}

double_byte_character_string_c::double_byte_character_string_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *double_byte_character_string_c::accept(visitor_c &visitor) {return visitor.visit(this);}

single_byte_character_string_c::single_byte_character_string_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *single_byte_character_string_c::accept(visitor_c &visitor) {return visitor.visit(this);}

neg_time_c::neg_time_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *neg_time_c::accept(visitor_c &visitor) {return visitor.visit(this);}

duration_c::duration_c(symbol_c *type_name,
                           symbol_c *neg,
                           symbol_c *interval,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type_name = type_name;
  this->neg = neg;
  this->interval = interval;
  if  (NULL != type_name)   type_name->parent = this;
  if  (NULL != neg)   neg->parent = this;
  if  (NULL != interval)   interval->parent = this;
}
void *duration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

interval_c::interval_c(symbol_c *days,
                           symbol_c *hours,
                           symbol_c *minutes,
                           symbol_c *seconds,
                           symbol_c *milliseconds,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->days = days;
  this->hours = hours;
  this->minutes = minutes;
  this->seconds = seconds;
  this->milliseconds = milliseconds;
  if  (NULL != days)   days->parent = this;
  if  (NULL != hours)   hours->parent = this;
  if  (NULL != minutes)   minutes->parent = this;
  if  (NULL != seconds)   seconds->parent = this;
  if  (NULL != milliseconds)   milliseconds->parent = this;
}
void *interval_c::accept(visitor_c &visitor) {return visitor.visit(this);}

fixed_point_c::fixed_point_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *fixed_point_c::accept(visitor_c &visitor) {return visitor.visit(this);}

time_of_day_c::time_of_day_c(symbol_c *type_name,
                           symbol_c *daytime,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type_name = type_name;
  this->daytime = daytime;
  if  (NULL != type_name)   type_name->parent = this;
  if  (NULL != daytime)   daytime->parent = this;
}
void *time_of_day_c::accept(visitor_c &visitor) {return visitor.visit(this);}

daytime_c::daytime_c(symbol_c *day_hour,
                           symbol_c *day_minute,
                           symbol_c *day_second,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->day_hour = day_hour;
  this->day_minute = day_minute;
  this->day_second = day_second;
  if  (NULL != day_hour)   day_hour->parent = this;
  if  (NULL != day_minute)   day_minute->parent = this;
  if  (NULL != day_second)   day_second->parent = this;
}
void *daytime_c::accept(visitor_c &visitor) {return visitor.visit(this);}

date_c::date_c(symbol_c *type_name,
                           symbol_c *date_literal,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type_name = type_name;
  this->date_literal = date_literal;
  if  (NULL != type_name)   type_name->parent = this;
  if  (NULL != date_literal)   date_literal->parent = this;
}
void *date_c::accept(visitor_c &visitor) {return visitor.visit(this);}

date_literal_c::date_literal_c(symbol_c *year,
                           symbol_c *month,
                           symbol_c *day,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->year = year;
  this->month = month;
  this->day = day;
  if  (NULL != year)   year->parent = this;
  if  (NULL != month)   month->parent = this;
  if  (NULL != day)   day->parent = this;
}
void *date_literal_c::accept(visitor_c &visitor) {return visitor.visit(this);}

date_and_time_c::date_and_time_c(symbol_c *type_name,
                           symbol_c *date_literal,
                           symbol_c *daytime,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type_name = type_name;
  this->date_literal = date_literal;
  this->daytime = daytime;
  if  (NULL != type_name)   type_name->parent = this;
  if  (NULL != date_literal)   date_literal->parent = this;
  if  (NULL != daytime)   daytime->parent = this;
}
void *date_and_time_c::accept(visitor_c &visitor) {return visitor.visit(this);}

time_type_name_c::time_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *time_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

bool_type_name_c::bool_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *bool_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

sint_type_name_c::sint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *sint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

int_type_name_c::int_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *int_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

dint_type_name_c::dint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *dint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

lint_type_name_c::lint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *lint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

usint_type_name_c::usint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *usint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

uint_type_name_c::uint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *uint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

udint_type_name_c::udint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *udint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ulint_type_name_c::ulint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *ulint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

real_type_name_c::real_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *real_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

lreal_type_name_c::lreal_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *lreal_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

date_type_name_c::date_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *date_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

tod_type_name_c::tod_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *tod_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

dt_type_name_c::dt_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *dt_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

byte_type_name_c::byte_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *byte_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

word_type_name_c::word_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *word_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

dword_type_name_c::dword_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *dword_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

lword_type_name_c::lword_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *lword_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

string_type_name_c::string_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *string_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

wstring_type_name_c::wstring_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *wstring_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

void_type_name_c::void_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *void_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safetime_type_name_c::safetime_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safetime_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safebool_type_name_c::safebool_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safebool_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safesint_type_name_c::safesint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safesint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safeint_type_name_c::safeint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safeint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safedint_type_name_c::safedint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safedint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safelint_type_name_c::safelint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safelint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safeusint_type_name_c::safeusint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safeusint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safeuint_type_name_c::safeuint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safeuint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safeudint_type_name_c::safeudint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safeudint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safeulint_type_name_c::safeulint_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safeulint_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safereal_type_name_c::safereal_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safereal_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safelreal_type_name_c::safelreal_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safelreal_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safedate_type_name_c::safedate_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safedate_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safetod_type_name_c::safetod_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safetod_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safedt_type_name_c::safedt_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safedt_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safebyte_type_name_c::safebyte_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safebyte_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safeword_type_name_c::safeword_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safeword_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safedword_type_name_c::safedword_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safedword_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safelword_type_name_c::safelword_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safelword_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safestring_type_name_c::safestring_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safestring_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

safewstring_type_name_c::safewstring_type_name_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *safewstring_type_name_c::accept(visitor_c &visitor) {return visitor.visit(this);}

generic_type_any_c::generic_type_any_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *generic_type_any_c::accept(visitor_c &visitor) {return visitor.visit(this);}

data_type_declaration_c::data_type_declaration_c(symbol_c *type_declaration_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type_declaration_list = type_declaration_list;
  if  (NULL != type_declaration_list)   type_declaration_list->parent = this;
}
void *data_type_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

type_declaration_list_c::type_declaration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

type_declaration_list_c::type_declaration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *type_declaration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

simple_type_declaration_c::simple_type_declaration_c(symbol_c *simple_type_name,
                           symbol_c *simple_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->simple_type_name = simple_type_name;
  this->simple_spec_init = simple_spec_init;
  if  (NULL != simple_type_name)   simple_type_name->parent = this;
  if  (NULL != simple_spec_init)   simple_spec_init->parent = this;
}
void *simple_type_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

simple_spec_init_c::simple_spec_init_c(symbol_c *simple_specification,
                           symbol_c *constant,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->simple_specification = simple_specification;
  this->constant = constant;
  if  (NULL != simple_specification)   simple_specification->parent = this;
  if  (NULL != constant)   constant->parent = this;
}
void *simple_spec_init_c::accept(visitor_c &visitor) {return visitor.visit(this);}

subrange_type_declaration_c::subrange_type_declaration_c(symbol_c *subrange_type_name,
                           symbol_c *subrange_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->subrange_type_name = subrange_type_name;
  this->subrange_spec_init = subrange_spec_init;
  if  (NULL != subrange_type_name)   subrange_type_name->parent = this;
  if  (NULL != subrange_spec_init)   subrange_spec_init->parent = this;
}
void *subrange_type_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

subrange_spec_init_c::subrange_spec_init_c(symbol_c *subrange_specification,
                           symbol_c *signed_integer,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->subrange_specification = subrange_specification;
  this->signed_integer = signed_integer;
  if  (NULL != subrange_specification)   subrange_specification->parent = this;
  if  (NULL != signed_integer)   signed_integer->parent = this;
}
void *subrange_spec_init_c::accept(visitor_c &visitor) {return visitor.visit(this);}

subrange_specification_c::subrange_specification_c(symbol_c *integer_type_name,
                           symbol_c *subrange,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->integer_type_name = integer_type_name;
  this->subrange = subrange;
  if  (NULL != integer_type_name)   integer_type_name->parent = this;
  if  (NULL != subrange)   subrange->parent = this;
}
void *subrange_specification_c::accept(visitor_c &visitor) {return visitor.visit(this);}

subrange_c::subrange_c(symbol_c *lower_limit,
                           symbol_c *upper_limit,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->lower_limit = lower_limit;
  this->upper_limit = upper_limit;
  if  (NULL != lower_limit)   lower_limit->parent = this;
  if  (NULL != upper_limit)   upper_limit->parent = this;
}
void *subrange_c::accept(visitor_c &visitor) {return visitor.visit(this);}

enumerated_type_declaration_c::enumerated_type_declaration_c(symbol_c *enumerated_type_name,
                           symbol_c *enumerated_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->enumerated_type_name = enumerated_type_name;
  this->enumerated_spec_init = enumerated_spec_init;
  if  (NULL != enumerated_type_name)   enumerated_type_name->parent = this;
  if  (NULL != enumerated_spec_init)   enumerated_spec_init->parent = this;
}
void *enumerated_type_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

enumerated_spec_init_c::enumerated_spec_init_c(symbol_c *enumerated_specification,
                           symbol_c *enumerated_value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->enumerated_specification = enumerated_specification;
  this->enumerated_value = enumerated_value;
  if  (NULL != enumerated_specification)   enumerated_specification->parent = this;
  if  (NULL != enumerated_value)   enumerated_value->parent = this;
}
void *enumerated_spec_init_c::accept(visitor_c &visitor) {return visitor.visit(this);}

enumerated_value_list_c::enumerated_value_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

enumerated_value_list_c::enumerated_value_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *enumerated_value_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

enumerated_value_c::enumerated_value_c(symbol_c *type,
                           symbol_c *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type = type;
  this->value = value;
  if  (NULL != type)   type->parent = this;
  if  (NULL != value)   value->parent = this;
}
void *enumerated_value_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_type_declaration_c::array_type_declaration_c(symbol_c *identifier,
                           symbol_c *array_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->identifier = identifier;
  this->array_spec_init = array_spec_init;
  if  (NULL != identifier)   identifier->parent = this;
  if  (NULL != array_spec_init)   array_spec_init->parent = this;
}
void *array_type_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_spec_init_c::array_spec_init_c(symbol_c *array_specification,
                           symbol_c *array_initialization,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->array_specification = array_specification;
  this->array_initialization = array_initialization;
  if  (NULL != array_specification)   array_specification->parent = this;
  if  (NULL != array_initialization)   array_initialization->parent = this;
}
void *array_spec_init_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_specification_c::array_specification_c(symbol_c *array_subrange_list,
                           symbol_c *non_generic_type_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->array_subrange_list = array_subrange_list;
  this->non_generic_type_name = non_generic_type_name;
  if  (NULL != array_subrange_list)   array_subrange_list->parent = this;
  if  (NULL != non_generic_type_name)   non_generic_type_name->parent = this;
}
void *array_specification_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_subrange_list_c::array_subrange_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

array_subrange_list_c::array_subrange_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *array_subrange_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_initial_elements_list_c::array_initial_elements_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

array_initial_elements_list_c::array_initial_elements_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *array_initial_elements_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_initial_elements_c::array_initial_elements_c(symbol_c *integer,
                           symbol_c *array_initial_element,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->integer = integer;
  this->array_initial_element = array_initial_element;
  if  (NULL != integer)   integer->parent = this;
  if  (NULL != array_initial_element)   array_initial_element->parent = this;
}
void *array_initial_elements_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structure_type_declaration_c::structure_type_declaration_c(symbol_c *structure_type_name,
                           symbol_c *structure_specification,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->structure_type_name = structure_type_name;
  this->structure_specification = structure_specification;
  if  (NULL != structure_type_name)   structure_type_name->parent = this;
  if  (NULL != structure_specification)   structure_specification->parent = this;
}
void *structure_type_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

initialized_structure_c::initialized_structure_c(symbol_c *structure_type_name,
                           symbol_c *structure_initialization,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->structure_type_name = structure_type_name;
  this->structure_initialization = structure_initialization;
  if  (NULL != structure_type_name)   structure_type_name->parent = this;
  if  (NULL != structure_initialization)   structure_initialization->parent = this;
}
void *initialized_structure_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structure_element_declaration_list_c::structure_element_declaration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

structure_element_declaration_list_c::structure_element_declaration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *structure_element_declaration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structure_element_declaration_c::structure_element_declaration_c(symbol_c *structure_element_name,
                           symbol_c *spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->structure_element_name = structure_element_name;
  this->spec_init = spec_init;
  if  (NULL != structure_element_name)   structure_element_name->parent = this;
  if  (NULL != spec_init)   spec_init->parent = this;
}
void *structure_element_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structure_element_initialization_list_c::structure_element_initialization_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

structure_element_initialization_list_c::structure_element_initialization_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *structure_element_initialization_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structure_element_initialization_c::structure_element_initialization_c(symbol_c *structure_element_name,
                           symbol_c *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->structure_element_name = structure_element_name;
  this->value = value;
  if  (NULL != structure_element_name)   structure_element_name->parent = this;
  if  (NULL != value)   value->parent = this;
}
void *structure_element_initialization_c::accept(visitor_c &visitor) {return visitor.visit(this);}

string_type_declaration_c::string_type_declaration_c(symbol_c *string_type_name,
                           symbol_c *elementary_string_type_name,
                           symbol_c *string_type_declaration_size,
                           symbol_c *string_type_declaration_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->string_type_name = string_type_name;
  this->elementary_string_type_name = elementary_string_type_name;
  this->string_type_declaration_size = string_type_declaration_size;
  this->string_type_declaration_init = string_type_declaration_init;
  if  (NULL != string_type_name)   string_type_name->parent = this;
  if  (NULL != elementary_string_type_name)   elementary_string_type_name->parent = this;
  if  (NULL != string_type_declaration_size)   string_type_declaration_size->parent = this;
  if  (NULL != string_type_declaration_init)   string_type_declaration_init->parent = this;
}
void *string_type_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

fb_spec_init_c::fb_spec_init_c(symbol_c *function_block_type_name,
                           symbol_c *structure_initialization,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->function_block_type_name = function_block_type_name;
  this->structure_initialization = structure_initialization;
  if  (NULL != function_block_type_name)   function_block_type_name->parent = this;
  if  (NULL != structure_initialization)   structure_initialization->parent = this;
}
void *fb_spec_init_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ref_spec_c::ref_spec_c(symbol_c *type_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->type_name = type_name;
  if  (NULL != type_name)   type_name->parent = this;
}
void *ref_spec_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ref_spec_init_c::ref_spec_init_c(symbol_c *ref_spec,
                           symbol_c *ref_initialization,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->ref_spec = ref_spec;
  this->ref_initialization = ref_initialization;
  if  (NULL != ref_spec)   ref_spec->parent = this;
  if  (NULL != ref_initialization)   ref_initialization->parent = this;
}
void *ref_spec_init_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ref_type_decl_c::ref_type_decl_c(symbol_c *ref_type_name,
                           symbol_c *ref_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->ref_type_name = ref_type_name;
  this->ref_spec_init = ref_spec_init;
  if  (NULL != ref_type_name)   ref_type_name->parent = this;
  if  (NULL != ref_spec_init)   ref_spec_init->parent = this;
}
void *ref_type_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

symbolic_variable_c::symbolic_variable_c(symbol_c *var_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var_name = var_name;
  if  (NULL != var_name)   var_name->parent = this;
}
void *symbolic_variable_c::accept(visitor_c &visitor) {return visitor.visit(this);}

symbolic_constant_c::symbolic_constant_c(symbol_c *var_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var_name = var_name;
  if  (NULL != var_name)   var_name->parent = this;
}
void *symbolic_constant_c::accept(visitor_c &visitor) {return visitor.visit(this);}

direct_variable_c::direct_variable_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *direct_variable_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_variable_c::array_variable_c(symbol_c *subscripted_variable,
                           symbol_c *subscript_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->subscripted_variable = subscripted_variable;
  this->subscript_list = subscript_list;
  if  (NULL != subscripted_variable)   subscripted_variable->parent = this;
  if  (NULL != subscript_list)   subscript_list->parent = this;
}
void *array_variable_c::accept(visitor_c &visitor) {return visitor.visit(this);}

subscript_list_c::subscript_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

subscript_list_c::subscript_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *subscript_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structured_variable_c::structured_variable_c(symbol_c *record_variable,
                           symbol_c *field_selector,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->record_variable = record_variable;
  this->field_selector = field_selector;
  if  (NULL != record_variable)   record_variable->parent = this;
  if  (NULL != field_selector)   field_selector->parent = this;
}
void *structured_variable_c::accept(visitor_c &visitor) {return visitor.visit(this);}

constant_option_c::constant_option_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *constant_option_c::accept(visitor_c &visitor) {return visitor.visit(this);}

retain_option_c::retain_option_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *retain_option_c::accept(visitor_c &visitor) {return visitor.visit(this);}

non_retain_option_c::non_retain_option_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *non_retain_option_c::accept(visitor_c &visitor) {return visitor.visit(this);}

input_declarations_c::input_declarations_c(symbol_c *option,
                           symbol_c *input_declaration_list,
                           symbol_c *method,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->input_declaration_list = input_declaration_list;
  this->method = method;
  if  (NULL != option)   option->parent = this;
  if  (NULL != input_declaration_list)   input_declaration_list->parent = this;
  if  (NULL != method)   method->parent = this;
}
void *input_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

input_declaration_list_c::input_declaration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

input_declaration_list_c::input_declaration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *input_declaration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

implicit_definition_c::implicit_definition_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *implicit_definition_c::accept(visitor_c &visitor) {return visitor.visit(this);}

explicit_definition_c::explicit_definition_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *explicit_definition_c::accept(visitor_c &visitor) {return visitor.visit(this);}

en_param_declaration_c::en_param_declaration_c(symbol_c *name,
                           symbol_c *type_decl,
                           symbol_c *method,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->name = name;
  this->type_decl = type_decl;
  this->method = method;
  if  (NULL != name)   name->parent = this;
  if  (NULL != type_decl)   type_decl->parent = this;
  if  (NULL != method)   method->parent = this;
}
void *en_param_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

eno_param_declaration_c::eno_param_declaration_c(symbol_c *name,
                           symbol_c *type,
                           symbol_c *method,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->name = name;
  this->type = type;
  this->method = method;
  if  (NULL != name)   name->parent = this;
  if  (NULL != type)   type->parent = this;
  if  (NULL != method)   method->parent = this;
}
void *eno_param_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

edge_declaration_c::edge_declaration_c(symbol_c *edge,
                           symbol_c *var1_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->edge = edge;
  this->var1_list = var1_list;
  if  (NULL != edge)   edge->parent = this;
  if  (NULL != var1_list)   var1_list->parent = this;
}
void *edge_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

raising_edge_option_c::raising_edge_option_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *raising_edge_option_c::accept(visitor_c &visitor) {return visitor.visit(this);}

falling_edge_option_c::falling_edge_option_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *falling_edge_option_c::accept(visitor_c &visitor) {return visitor.visit(this);}

var1_init_decl_c::var1_init_decl_c(symbol_c *var1_list,
                           symbol_c *spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var1_list = var1_list;
  this->spec_init = spec_init;
  if  (NULL != var1_list)   var1_list->parent = this;
  if  (NULL != spec_init)   spec_init->parent = this;
}
void *var1_init_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

var1_list_c::var1_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

var1_list_c::var1_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *var1_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

extensible_input_parameter_c::extensible_input_parameter_c(symbol_c *var_name,
                           symbol_c *first_index,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var_name = var_name;
  this->first_index = first_index;
  if  (NULL != var_name)   var_name->parent = this;
  if  (NULL != first_index)   first_index->parent = this;
}
void *extensible_input_parameter_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_var_init_decl_c::array_var_init_decl_c(symbol_c *var1_list,
                           symbol_c *array_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var1_list = var1_list;
  this->array_spec_init = array_spec_init;
  if  (NULL != var1_list)   var1_list->parent = this;
  if  (NULL != array_spec_init)   array_spec_init->parent = this;
}
void *array_var_init_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structured_var_init_decl_c::structured_var_init_decl_c(symbol_c *var1_list,
                           symbol_c *initialized_structure,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var1_list = var1_list;
  this->initialized_structure = initialized_structure;
  if  (NULL != var1_list)   var1_list->parent = this;
  if  (NULL != initialized_structure)   initialized_structure->parent = this;
}
void *structured_var_init_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

fb_name_decl_c::fb_name_decl_c(symbol_c *fb_name_list,
                           symbol_c *fb_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->fb_name_list = fb_name_list;
  this->fb_spec_init = fb_spec_init;
  if  (NULL != fb_name_list)   fb_name_list->parent = this;
  if  (NULL != fb_spec_init)   fb_spec_init->parent = this;
}
void *fb_name_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

fb_name_list_c::fb_name_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

fb_name_list_c::fb_name_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *fb_name_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

output_declarations_c::output_declarations_c(symbol_c *option,
                           symbol_c *var_init_decl_list,
                           symbol_c *method,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->var_init_decl_list = var_init_decl_list;
  this->method = method;
  if  (NULL != option)   option->parent = this;
  if  (NULL != var_init_decl_list)   var_init_decl_list->parent = this;
  if  (NULL != method)   method->parent = this;
}
void *output_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

input_output_declarations_c::input_output_declarations_c(symbol_c *var_declaration_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var_declaration_list = var_declaration_list;
  if  (NULL != var_declaration_list)   var_declaration_list->parent = this;
}
void *input_output_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

var_declaration_list_c::var_declaration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

var_declaration_list_c::var_declaration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *var_declaration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

array_var_declaration_c::array_var_declaration_c(symbol_c *var1_list,
                           symbol_c *array_specification,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var1_list = var1_list;
  this->array_specification = array_specification;
  if  (NULL != var1_list)   var1_list->parent = this;
  if  (NULL != array_specification)   array_specification->parent = this;
}
void *array_var_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

structured_var_declaration_c::structured_var_declaration_c(symbol_c *var1_list,
                           symbol_c *structure_type_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var1_list = var1_list;
  this->structure_type_name = structure_type_name;
  if  (NULL != var1_list)   var1_list->parent = this;
  if  (NULL != structure_type_name)   structure_type_name->parent = this;
}
void *structured_var_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

var_declarations_c::var_declarations_c(symbol_c *option,
                           symbol_c *var_init_decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->var_init_decl_list = var_init_decl_list;
  if  (NULL != option)   option->parent = this;
  if  (NULL != var_init_decl_list)   var_init_decl_list->parent = this;
}
void *var_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

retentive_var_declarations_c::retentive_var_declarations_c(symbol_c *var_init_decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var_init_decl_list = var_init_decl_list;
  if  (NULL != var_init_decl_list)   var_init_decl_list->parent = this;
}
void *retentive_var_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

located_var_declarations_c::located_var_declarations_c(symbol_c *option,
                           symbol_c *located_var_decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->located_var_decl_list = located_var_decl_list;
  if  (NULL != option)   option->parent = this;
  if  (NULL != located_var_decl_list)   located_var_decl_list->parent = this;
}
void *located_var_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

located_var_decl_list_c::located_var_decl_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

located_var_decl_list_c::located_var_decl_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *located_var_decl_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

located_var_decl_c::located_var_decl_c(symbol_c *variable_name,
                           symbol_c *location,
                           symbol_c *located_var_spec_init,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->variable_name = variable_name;
  this->location = location;
  this->located_var_spec_init = located_var_spec_init;
  if  (NULL != variable_name)   variable_name->parent = this;
  if  (NULL != location)   location->parent = this;
  if  (NULL != located_var_spec_init)   located_var_spec_init->parent = this;
}
void *located_var_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

external_var_declarations_c::external_var_declarations_c(symbol_c *option,
                           symbol_c *external_declaration_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->external_declaration_list = external_declaration_list;
  if  (NULL != option)   option->parent = this;
  if  (NULL != external_declaration_list)   external_declaration_list->parent = this;
}
void *external_var_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

external_declaration_list_c::external_declaration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

external_declaration_list_c::external_declaration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *external_declaration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

external_declaration_c::external_declaration_c(symbol_c *global_var_name,
                           symbol_c *specification,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->global_var_name = global_var_name;
  this->specification = specification;
  if  (NULL != global_var_name)   global_var_name->parent = this;
  if  (NULL != specification)   specification->parent = this;
}
void *external_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

global_var_declarations_c::global_var_declarations_c(symbol_c *option,
                           symbol_c *global_var_decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->global_var_decl_list = global_var_decl_list;
  if  (NULL != option)   option->parent = this;
  if  (NULL != global_var_decl_list)   global_var_decl_list->parent = this;
}
void *global_var_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

global_var_decl_list_c::global_var_decl_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

global_var_decl_list_c::global_var_decl_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *global_var_decl_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

global_var_decl_c::global_var_decl_c(symbol_c *global_var_spec,
                           symbol_c *type_specification,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->global_var_spec = global_var_spec;
  this->type_specification = type_specification;
  if  (NULL != global_var_spec)   global_var_spec->parent = this;
  if  (NULL != type_specification)   type_specification->parent = this;
}
void *global_var_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

global_var_spec_c::global_var_spec_c(symbol_c *global_var_name,
                           symbol_c *location,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->global_var_name = global_var_name;
  this->location = location;
  if  (NULL != global_var_name)   global_var_name->parent = this;
  if  (NULL != location)   location->parent = this;
}
void *global_var_spec_c::accept(visitor_c &visitor) {return visitor.visit(this);}

location_c::location_c(symbol_c *direct_variable,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->direct_variable = direct_variable;
  if  (NULL != direct_variable)   direct_variable->parent = this;
}
void *location_c::accept(visitor_c &visitor) {return visitor.visit(this);}

global_var_list_c::global_var_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

global_var_list_c::global_var_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *global_var_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

single_byte_string_var_declaration_c::single_byte_string_var_declaration_c(symbol_c *var1_list,
                           symbol_c *single_byte_string_spec,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var1_list = var1_list;
  this->single_byte_string_spec = single_byte_string_spec;
  if  (NULL != var1_list)   var1_list->parent = this;
  if  (NULL != single_byte_string_spec)   single_byte_string_spec->parent = this;
}
void *single_byte_string_var_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

single_byte_string_spec_c::single_byte_string_spec_c(symbol_c *string_spec,
                           symbol_c *single_byte_character_string,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->string_spec = string_spec;
  this->single_byte_character_string = single_byte_character_string;
  if  (NULL != string_spec)   string_spec->parent = this;
  if  (NULL != single_byte_character_string)   single_byte_character_string->parent = this;
}
void *single_byte_string_spec_c::accept(visitor_c &visitor) {return visitor.visit(this);}

single_byte_limited_len_string_spec_c::single_byte_limited_len_string_spec_c(symbol_c *string_type_name,
                           symbol_c *character_string_len,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->string_type_name = string_type_name;
  this->character_string_len = character_string_len;
  if  (NULL != string_type_name)   string_type_name->parent = this;
  if  (NULL != character_string_len)   character_string_len->parent = this;
}
void *single_byte_limited_len_string_spec_c::accept(visitor_c &visitor) {return visitor.visit(this);}

double_byte_limited_len_string_spec_c::double_byte_limited_len_string_spec_c(symbol_c *string_type_name,
                           symbol_c *character_string_len,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->string_type_name = string_type_name;
  this->character_string_len = character_string_len;
  if  (NULL != string_type_name)   string_type_name->parent = this;
  if  (NULL != character_string_len)   character_string_len->parent = this;
}
void *double_byte_limited_len_string_spec_c::accept(visitor_c &visitor) {return visitor.visit(this);}

double_byte_string_var_declaration_c::double_byte_string_var_declaration_c(symbol_c *var1_list,
                           symbol_c *double_byte_string_spec,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var1_list = var1_list;
  this->double_byte_string_spec = double_byte_string_spec;
  if  (NULL != var1_list)   var1_list->parent = this;
  if  (NULL != double_byte_string_spec)   double_byte_string_spec->parent = this;
}
void *double_byte_string_var_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

double_byte_string_spec_c::double_byte_string_spec_c(symbol_c *string_spec,
                           symbol_c *double_byte_character_string,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->string_spec = string_spec;
  this->double_byte_character_string = double_byte_character_string;
  if  (NULL != string_spec)   string_spec->parent = this;
  if  (NULL != double_byte_character_string)   double_byte_character_string->parent = this;
}
void *double_byte_string_spec_c::accept(visitor_c &visitor) {return visitor.visit(this);}

incompl_located_var_declarations_c::incompl_located_var_declarations_c(symbol_c *option,
                           symbol_c *incompl_located_var_decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->incompl_located_var_decl_list = incompl_located_var_decl_list;
  if  (NULL != option)   option->parent = this;
  if  (NULL != incompl_located_var_decl_list)   incompl_located_var_decl_list->parent = this;
}
void *incompl_located_var_declarations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

incompl_located_var_decl_list_c::incompl_located_var_decl_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

incompl_located_var_decl_list_c::incompl_located_var_decl_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *incompl_located_var_decl_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

incompl_located_var_decl_c::incompl_located_var_decl_c(symbol_c *variable_name,
                           symbol_c *incompl_location,
                           symbol_c *var_spec,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->variable_name = variable_name;
  this->incompl_location = incompl_location;
  this->var_spec = var_spec;
  if  (NULL != variable_name)   variable_name->parent = this;
  if  (NULL != incompl_location)   incompl_location->parent = this;
  if  (NULL != var_spec)   var_spec->parent = this;
}
void *incompl_located_var_decl_c::accept(visitor_c &visitor) {return visitor.visit(this);}

incompl_location_c::incompl_location_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *incompl_location_c::accept(visitor_c &visitor) {return visitor.visit(this);}

var_init_decl_list_c::var_init_decl_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

var_init_decl_list_c::var_init_decl_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *var_init_decl_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

function_declaration_c::function_declaration_c(symbol_c *derived_function_name,
                           symbol_c *type_name,
                           symbol_c *var_declarations_list,
                           symbol_c *function_body,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->derived_function_name = derived_function_name;
  this->type_name = type_name;
  this->var_declarations_list = var_declarations_list;
  this->function_body = function_body;
  if  (NULL != derived_function_name)   derived_function_name->parent = this;
  if  (NULL != type_name)   type_name->parent = this;
  if  (NULL != var_declarations_list)   var_declarations_list->parent = this;
  if  (NULL != function_body)   function_body->parent = this;
}
void *function_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

var_declarations_list_c::var_declarations_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

var_declarations_list_c::var_declarations_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *var_declarations_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

function_var_decls_c::function_var_decls_c(symbol_c *option,
                           symbol_c *decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->decl_list = decl_list;
  if  (NULL != option)   option->parent = this;
  if  (NULL != decl_list)   decl_list->parent = this;
}
void *function_var_decls_c::accept(visitor_c &visitor) {return visitor.visit(this);}

var2_init_decl_list_c::var2_init_decl_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

var2_init_decl_list_c::var2_init_decl_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *var2_init_decl_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

function_block_declaration_c::function_block_declaration_c(symbol_c *fblock_name,
                           symbol_c *var_declarations,
                           symbol_c *fblock_body,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->fblock_name = fblock_name;
  this->var_declarations = var_declarations;
  this->fblock_body = fblock_body;
  if  (NULL != fblock_name)   fblock_name->parent = this;
  if  (NULL != var_declarations)   var_declarations->parent = this;
  if  (NULL != fblock_body)   fblock_body->parent = this;
}
void *function_block_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

temp_var_decls_c::temp_var_decls_c(symbol_c *var_decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var_decl_list = var_decl_list;
  if  (NULL != var_decl_list)   var_decl_list->parent = this;
}
void *temp_var_decls_c::accept(visitor_c &visitor) {return visitor.visit(this);}

temp_var_decls_list_c::temp_var_decls_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

temp_var_decls_list_c::temp_var_decls_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *temp_var_decls_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

non_retentive_var_decls_c::non_retentive_var_decls_c(symbol_c *var_decl_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->var_decl_list = var_decl_list;
  if  (NULL != var_decl_list)   var_decl_list->parent = this;
}
void *non_retentive_var_decls_c::accept(visitor_c &visitor) {return visitor.visit(this);}

program_declaration_c::program_declaration_c(symbol_c *program_type_name,
                           symbol_c *var_declarations,
                           symbol_c *function_block_body,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->program_type_name = program_type_name;
  this->var_declarations = var_declarations;
  this->function_block_body = function_block_body;
  if  (NULL != program_type_name)   program_type_name->parent = this;
  if  (NULL != var_declarations)   var_declarations->parent = this;
  if  (NULL != function_block_body)   function_block_body->parent = this;
}
void *program_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

sequential_function_chart_c::sequential_function_chart_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

sequential_function_chart_c::sequential_function_chart_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *sequential_function_chart_c::accept(visitor_c &visitor) {return visitor.visit(this);}

sfc_network_c::sfc_network_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

sfc_network_c::sfc_network_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *sfc_network_c::accept(visitor_c &visitor) {return visitor.visit(this);}

initial_step_c::initial_step_c(symbol_c *step_name,
                           symbol_c *action_association_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->step_name = step_name;
  this->action_association_list = action_association_list;
  if  (NULL != step_name)   step_name->parent = this;
  if  (NULL != action_association_list)   action_association_list->parent = this;
}
void *initial_step_c::accept(visitor_c &visitor) {return visitor.visit(this);}

action_association_list_c::action_association_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

action_association_list_c::action_association_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *action_association_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

step_c::step_c(symbol_c *step_name,
                           symbol_c *action_association_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->step_name = step_name;
  this->action_association_list = action_association_list;
  if  (NULL != step_name)   step_name->parent = this;
  if  (NULL != action_association_list)   action_association_list->parent = this;
}
void *step_c::accept(visitor_c &visitor) {return visitor.visit(this);}

action_association_c::action_association_c(symbol_c *action_name,
                           symbol_c *action_qualifier,
                           symbol_c *indicator_name_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->action_name = action_name;
  this->action_qualifier = action_qualifier;
  this->indicator_name_list = indicator_name_list;
  if  (NULL != action_name)   action_name->parent = this;
  if  (NULL != action_qualifier)   action_qualifier->parent = this;
  if  (NULL != indicator_name_list)   indicator_name_list->parent = this;
}
void *action_association_c::accept(visitor_c &visitor) {return visitor.visit(this);}

qualifier_c::qualifier_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *qualifier_c::accept(visitor_c &visitor) {return visitor.visit(this);}

timed_qualifier_c::timed_qualifier_c(const char *value,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *timed_qualifier_c::accept(visitor_c &visitor) {return visitor.visit(this);}

indicator_name_list_c::indicator_name_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

indicator_name_list_c::indicator_name_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *indicator_name_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

action_qualifier_c::action_qualifier_c(symbol_c *action_qualifier,
                           symbol_c *action_time,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->action_qualifier = action_qualifier;
  this->action_time = action_time;
  if  (NULL != action_qualifier)   action_qualifier->parent = this;
  if  (NULL != action_time)   action_time->parent = this;
}
void *action_qualifier_c::accept(visitor_c &visitor) {return visitor.visit(this);}

transition_c::transition_c(symbol_c *transition_name,
                           symbol_c *integer,
                           symbol_c *from_steps,
                           symbol_c *to_steps,
                           symbol_c *transition_condition,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->transition_name = transition_name;
  this->integer = integer;
  this->from_steps = from_steps;
  this->to_steps = to_steps;
  this->transition_condition = transition_condition;
  if  (NULL != transition_name)   transition_name->parent = this;
  if  (NULL != integer)   integer->parent = this;
  if  (NULL != from_steps)   from_steps->parent = this;
  if  (NULL != to_steps)   to_steps->parent = this;
  if  (NULL != transition_condition)   transition_condition->parent = this;
}
void *transition_c::accept(visitor_c &visitor) {return visitor.visit(this);}

transition_condition_c::transition_condition_c(symbol_c *transition_condition_il,
                           symbol_c *transition_condition_st,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->transition_condition_il = transition_condition_il;
  this->transition_condition_st = transition_condition_st;
  if  (NULL != transition_condition_il)   transition_condition_il->parent = this;
  if  (NULL != transition_condition_st)   transition_condition_st->parent = this;
}
void *transition_condition_c::accept(visitor_c &visitor) {return visitor.visit(this);}

steps_c::steps_c(symbol_c *step_name,
                           symbol_c *step_name_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->step_name = step_name;
  this->step_name_list = step_name_list;
  if  (NULL != step_name)   step_name->parent = this;
  if  (NULL != step_name_list)   step_name_list->parent = this;
}
void *steps_c::accept(visitor_c &visitor) {return visitor.visit(this);}

step_name_list_c::step_name_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

step_name_list_c::step_name_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *step_name_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

action_c::action_c(symbol_c *action_name,
                           symbol_c *function_block_body,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->action_name = action_name;
  this->function_block_body = function_block_body;
  if  (NULL != action_name)   action_name->parent = this;
  if  (NULL != function_block_body)   function_block_body->parent = this;
}
void *action_c::accept(visitor_c &visitor) {return visitor.visit(this);}

configuration_declaration_c::configuration_declaration_c(symbol_c *configuration_name,
                           symbol_c *global_var_declarations,
                           symbol_c *resource_declarations,
                           symbol_c *access_declarations,
                           symbol_c *instance_specific_initializations,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->configuration_name = configuration_name;
  this->global_var_declarations = global_var_declarations;
  this->resource_declarations = resource_declarations;
  this->access_declarations = access_declarations;
  this->instance_specific_initializations = instance_specific_initializations;
  if  (NULL != configuration_name)   configuration_name->parent = this;
  if  (NULL != global_var_declarations)   global_var_declarations->parent = this;
  if  (NULL != resource_declarations)   resource_declarations->parent = this;
  if  (NULL != access_declarations)   access_declarations->parent = this;
  if  (NULL != instance_specific_initializations)   instance_specific_initializations->parent = this;
}
void *configuration_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

global_var_declarations_list_c::global_var_declarations_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

global_var_declarations_list_c::global_var_declarations_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *global_var_declarations_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

resource_declaration_list_c::resource_declaration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

resource_declaration_list_c::resource_declaration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *resource_declaration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

resource_declaration_c::resource_declaration_c(symbol_c *resource_name,
                           symbol_c *resource_type_name,
                           symbol_c *global_var_declarations,
                           symbol_c *resource_declaration,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->resource_name = resource_name;
  this->resource_type_name = resource_type_name;
  this->global_var_declarations = global_var_declarations;
  this->resource_declaration = resource_declaration;
  if  (NULL != resource_name)   resource_name->parent = this;
  if  (NULL != resource_type_name)   resource_type_name->parent = this;
  if  (NULL != global_var_declarations)   global_var_declarations->parent = this;
  if  (NULL != resource_declaration)   resource_declaration->parent = this;
}
void *resource_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

single_resource_declaration_c::single_resource_declaration_c(symbol_c *task_configuration_list,
                           symbol_c *program_configuration_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->task_configuration_list = task_configuration_list;
  this->program_configuration_list = program_configuration_list;
  if  (NULL != task_configuration_list)   task_configuration_list->parent = this;
  if  (NULL != program_configuration_list)   program_configuration_list->parent = this;
}
void *single_resource_declaration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

task_configuration_list_c::task_configuration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

task_configuration_list_c::task_configuration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *task_configuration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

program_configuration_list_c::program_configuration_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

program_configuration_list_c::program_configuration_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *program_configuration_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

any_fb_name_list_c::any_fb_name_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

any_fb_name_list_c::any_fb_name_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *any_fb_name_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

global_var_reference_c::global_var_reference_c(symbol_c *resource_name,
                           symbol_c *global_var_name,
                           symbol_c *structure_element_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->resource_name = resource_name;
  this->global_var_name = global_var_name;
  this->structure_element_name = structure_element_name;
  if  (NULL != resource_name)   resource_name->parent = this;
  if  (NULL != global_var_name)   global_var_name->parent = this;
  if  (NULL != structure_element_name)   structure_element_name->parent = this;
}
void *global_var_reference_c::accept(visitor_c &visitor) {return visitor.visit(this);}

program_output_reference_c::program_output_reference_c(symbol_c *program_name,
                           symbol_c *symbolic_variable,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->program_name = program_name;
  this->symbolic_variable = symbolic_variable;
  if  (NULL != program_name)   program_name->parent = this;
  if  (NULL != symbolic_variable)   symbolic_variable->parent = this;
}
void *program_output_reference_c::accept(visitor_c &visitor) {return visitor.visit(this);}

task_configuration_c::task_configuration_c(symbol_c *task_name,
                           symbol_c *task_initialization,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->task_name = task_name;
  this->task_initialization = task_initialization;
  if  (NULL != task_name)   task_name->parent = this;
  if  (NULL != task_initialization)   task_initialization->parent = this;
}
void *task_configuration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

task_initialization_c::task_initialization_c(symbol_c *single_data_source,
                           symbol_c *interval_data_source,
                           symbol_c *priority_data_source,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->single_data_source = single_data_source;
  this->interval_data_source = interval_data_source;
  this->priority_data_source = priority_data_source;
  if  (NULL != single_data_source)   single_data_source->parent = this;
  if  (NULL != interval_data_source)   interval_data_source->parent = this;
  if  (NULL != priority_data_source)   priority_data_source->parent = this;
}
void *task_initialization_c::accept(visitor_c &visitor) {return visitor.visit(this);}

program_configuration_c::program_configuration_c(symbol_c *retain_option,
                           symbol_c *program_name,
                           symbol_c *task_name,
                           symbol_c *program_type_name,
                           symbol_c *prog_conf_elements,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->retain_option = retain_option;
  this->program_name = program_name;
  this->task_name = task_name;
  this->program_type_name = program_type_name;
  this->prog_conf_elements = prog_conf_elements;
  if  (NULL != retain_option)   retain_option->parent = this;
  if  (NULL != program_name)   program_name->parent = this;
  if  (NULL != task_name)   task_name->parent = this;
  if  (NULL != program_type_name)   program_type_name->parent = this;
  if  (NULL != prog_conf_elements)   prog_conf_elements->parent = this;
}
void *program_configuration_c::accept(visitor_c &visitor) {return visitor.visit(this);}

prog_conf_elements_c::prog_conf_elements_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

prog_conf_elements_c::prog_conf_elements_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *prog_conf_elements_c::accept(visitor_c &visitor) {return visitor.visit(this);}

fb_task_c::fb_task_c(symbol_c *fb_name,
                           symbol_c *task_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->fb_name = fb_name;
  this->task_name = task_name;
  if  (NULL != fb_name)   fb_name->parent = this;
  if  (NULL != task_name)   task_name->parent = this;
}
void *fb_task_c::accept(visitor_c &visitor) {return visitor.visit(this);}

prog_cnxn_assign_c::prog_cnxn_assign_c(symbol_c *symbolic_variable,
                           symbol_c *prog_data_source,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->symbolic_variable = symbolic_variable;
  this->prog_data_source = prog_data_source;
  if  (NULL != symbolic_variable)   symbolic_variable->parent = this;
  if  (NULL != prog_data_source)   prog_data_source->parent = this;
}
void *prog_cnxn_assign_c::accept(visitor_c &visitor) {return visitor.visit(this);}

prog_cnxn_sendto_c::prog_cnxn_sendto_c(symbol_c *symbolic_variable,
                           symbol_c *data_sink,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->symbolic_variable = symbolic_variable;
  this->data_sink = data_sink;
  if  (NULL != symbolic_variable)   symbolic_variable->parent = this;
  if  (NULL != data_sink)   data_sink->parent = this;
}
void *prog_cnxn_sendto_c::accept(visitor_c &visitor) {return visitor.visit(this);}

instance_specific_initializations_c::instance_specific_initializations_c(symbol_c *instance_specific_init_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->instance_specific_init_list = instance_specific_init_list;
  if  (NULL != instance_specific_init_list)   instance_specific_init_list->parent = this;
}
void *instance_specific_initializations_c::accept(visitor_c &visitor) {return visitor.visit(this);}

instance_specific_init_list_c::instance_specific_init_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

instance_specific_init_list_c::instance_specific_init_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *instance_specific_init_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

instance_specific_init_c::instance_specific_init_c(symbol_c *resource_name,
                           symbol_c *program_name,
                           symbol_c *any_fb_name_list,
                           symbol_c *variable_name,
                           symbol_c *location,
                           symbol_c *initialization,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->resource_name = resource_name;
  this->program_name = program_name;
  this->any_fb_name_list = any_fb_name_list;
  this->variable_name = variable_name;
  this->location = location;
  this->initialization = initialization;
  if  (NULL != resource_name)   resource_name->parent = this;
  if  (NULL != program_name)   program_name->parent = this;
  if  (NULL != any_fb_name_list)   any_fb_name_list->parent = this;
  if  (NULL != variable_name)   variable_name->parent = this;
  if  (NULL != location)   location->parent = this;
  if  (NULL != initialization)   initialization->parent = this;
}
void *instance_specific_init_c::accept(visitor_c &visitor) {return visitor.visit(this);}

fb_initialization_c::fb_initialization_c(symbol_c *function_block_type_name,
                           symbol_c *structure_initialization,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->function_block_type_name = function_block_type_name;
  this->structure_initialization = structure_initialization;
  if  (NULL != function_block_type_name)   function_block_type_name->parent = this;
  if  (NULL != structure_initialization)   structure_initialization->parent = this;
}
void *fb_initialization_c::accept(visitor_c &visitor) {return visitor.visit(this);}

instruction_list_c::instruction_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

instruction_list_c::instruction_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *instruction_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_instruction_c::il_instruction_c(symbol_c *label,
                           symbol_c *il_instruction,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->label = label;
  this->il_instruction = il_instruction;
  if  (NULL != label)   label->parent = this;
  if  (NULL != il_instruction)   il_instruction->parent = this;
}
void *il_instruction_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_simple_operation_c::il_simple_operation_c(symbol_c *il_simple_operator,
                           symbol_c *il_operand,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->il_simple_operator = il_simple_operator;
  this->il_operand = il_operand;
  if  (NULL != il_simple_operator)   il_simple_operator->parent = this;
  if  (NULL != il_operand)   il_operand->parent = this;
}
void *il_simple_operation_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_function_call_c::il_function_call_c(symbol_c *function_name,
                           symbol_c *il_operand_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->function_name = function_name;
  this->il_operand_list = il_operand_list;
  if  (NULL != function_name)   function_name->parent = this;
  if  (NULL != il_operand_list)   il_operand_list->parent = this;
}
void *il_function_call_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_expression_c::il_expression_c(symbol_c *il_expr_operator,
                           symbol_c *il_operand,
                           symbol_c *simple_instr_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->il_expr_operator = il_expr_operator;
  this->il_operand = il_operand;
  this->simple_instr_list = simple_instr_list;
  if  (NULL != il_expr_operator)   il_expr_operator->parent = this;
  if  (NULL != il_operand)   il_operand->parent = this;
  if  (NULL != simple_instr_list)   simple_instr_list->parent = this;
}
void *il_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_jump_operation_c::il_jump_operation_c(symbol_c *il_jump_operator,
                           symbol_c *label,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->il_jump_operator = il_jump_operator;
  this->label = label;
  if  (NULL != il_jump_operator)   il_jump_operator->parent = this;
  if  (NULL != label)   label->parent = this;
}
void *il_jump_operation_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_fb_call_c::il_fb_call_c(symbol_c *il_call_operator,
                           symbol_c *fb_name,
                           symbol_c *il_operand_list,
                           symbol_c *il_param_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->il_call_operator = il_call_operator;
  this->fb_name = fb_name;
  this->il_operand_list = il_operand_list;
  this->il_param_list = il_param_list;
  if  (NULL != il_call_operator)   il_call_operator->parent = this;
  if  (NULL != fb_name)   fb_name->parent = this;
  if  (NULL != il_operand_list)   il_operand_list->parent = this;
  if  (NULL != il_param_list)   il_param_list->parent = this;
}
void *il_fb_call_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_formal_funct_call_c::il_formal_funct_call_c(symbol_c *function_name,
                           symbol_c *il_param_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->function_name = function_name;
  this->il_param_list = il_param_list;
  if  (NULL != function_name)   function_name->parent = this;
  if  (NULL != il_param_list)   il_param_list->parent = this;
}
void *il_formal_funct_call_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_operand_list_c::il_operand_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

il_operand_list_c::il_operand_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *il_operand_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

simple_instr_list_c::simple_instr_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

simple_instr_list_c::simple_instr_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *simple_instr_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_simple_instruction_c::il_simple_instruction_c(symbol_c *il_simple_instruction,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->il_simple_instruction = il_simple_instruction;
  if  (NULL != il_simple_instruction)   il_simple_instruction->parent = this;
}
void *il_simple_instruction_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_param_list_c::il_param_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

il_param_list_c::il_param_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *il_param_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_param_assignment_c::il_param_assignment_c(symbol_c *il_assign_operator,
                           symbol_c *il_operand,
                           symbol_c *simple_instr_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->il_assign_operator = il_assign_operator;
  this->il_operand = il_operand;
  this->simple_instr_list = simple_instr_list;
  if  (NULL != il_assign_operator)   il_assign_operator->parent = this;
  if  (NULL != il_operand)   il_operand->parent = this;
  if  (NULL != simple_instr_list)   simple_instr_list->parent = this;
}
void *il_param_assignment_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_param_out_assignment_c::il_param_out_assignment_c(symbol_c *il_assign_out_operator,
                           symbol_c *variable,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->il_assign_out_operator = il_assign_out_operator;
  this->variable = variable;
  if  (NULL != il_assign_out_operator)   il_assign_out_operator->parent = this;
  if  (NULL != variable)   variable->parent = this;
}
void *il_param_out_assignment_c::accept(visitor_c &visitor) {return visitor.visit(this);}

LD_operator_c::LD_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *LD_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

LDN_operator_c::LDN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *LDN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ST_operator_c::ST_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *ST_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

STN_operator_c::STN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *STN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

NOT_operator_c::NOT_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *NOT_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

S_operator_c::S_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *S_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

R_operator_c::R_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *R_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

S1_operator_c::S1_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *S1_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

R1_operator_c::R1_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *R1_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

CLK_operator_c::CLK_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *CLK_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

CU_operator_c::CU_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *CU_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

CD_operator_c::CD_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *CD_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

PV_operator_c::PV_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *PV_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

IN_operator_c::IN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *IN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

PT_operator_c::PT_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *PT_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

AND_operator_c::AND_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *AND_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

OR_operator_c::OR_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *OR_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

XOR_operator_c::XOR_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *XOR_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ANDN_operator_c::ANDN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *ANDN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ORN_operator_c::ORN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *ORN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

XORN_operator_c::XORN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *XORN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ADD_operator_c::ADD_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *ADD_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

SUB_operator_c::SUB_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *SUB_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

MUL_operator_c::MUL_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *MUL_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

DIV_operator_c::DIV_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *DIV_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

MOD_operator_c::MOD_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *MOD_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

GT_operator_c::GT_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *GT_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

GE_operator_c::GE_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *GE_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

EQ_operator_c::EQ_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *EQ_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

LT_operator_c::LT_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *LT_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

LE_operator_c::LE_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *LE_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

NE_operator_c::NE_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *NE_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

CAL_operator_c::CAL_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *CAL_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

CALC_operator_c::CALC_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *CALC_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

CALCN_operator_c::CALCN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *CALCN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

RET_operator_c::RET_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *RET_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

RETC_operator_c::RETC_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *RETC_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

RETCN_operator_c::RETCN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *RETCN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

JMP_operator_c::JMP_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *JMP_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

JMPC_operator_c::JMPC_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *JMPC_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

JMPCN_operator_c::JMPCN_operator_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *JMPCN_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_assign_operator_c::il_assign_operator_c(symbol_c *variable_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->variable_name = variable_name;
  if  (NULL != variable_name)   variable_name->parent = this;
}
void *il_assign_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

il_assign_out_operator_c::il_assign_out_operator_c(symbol_c *option,
                           symbol_c *variable_name,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->option = option;
  this->variable_name = variable_name;
  if  (NULL != option)   option->parent = this;
  if  (NULL != variable_name)   variable_name->parent = this;
}
void *il_assign_out_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ref_expression_c::ref_expression_c(symbol_c *exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->exp = exp;
  if  (NULL != exp)   exp->parent = this;
}
void *ref_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

deref_expression_c::deref_expression_c(symbol_c *exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->exp = exp;
  if  (NULL != exp)   exp->parent = this;
}
void *deref_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

deref_operator_c::deref_operator_c(symbol_c *exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->exp = exp;
  if  (NULL != exp)   exp->parent = this;
}
void *deref_operator_c::accept(visitor_c &visitor) {return visitor.visit(this);}

or_expression_c::or_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *or_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

xor_expression_c::xor_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *xor_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

and_expression_c::and_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *and_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

equ_expression_c::equ_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *equ_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

notequ_expression_c::notequ_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *notequ_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

lt_expression_c::lt_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *lt_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

gt_expression_c::gt_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *gt_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

le_expression_c::le_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *le_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

ge_expression_c::ge_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *ge_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

add_expression_c::add_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *add_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

sub_expression_c::sub_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *sub_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

mul_expression_c::mul_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *mul_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

div_expression_c::div_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *div_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

mod_expression_c::mod_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *mod_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

power_expression_c::power_expression_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *power_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

neg_expression_c::neg_expression_c(symbol_c *exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->exp = exp;
  if  (NULL != exp)   exp->parent = this;
}
void *neg_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

not_expression_c::not_expression_c(symbol_c *exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->exp = exp;
  if  (NULL != exp)   exp->parent = this;
}
void *not_expression_c::accept(visitor_c &visitor) {return visitor.visit(this);}

function_invocation_c::function_invocation_c(symbol_c *function_name,
                           symbol_c *formal_param_list,
                           symbol_c *nonformal_param_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->function_name = function_name;
  this->formal_param_list = formal_param_list;
  this->nonformal_param_list = nonformal_param_list;
  if  (NULL != function_name)   function_name->parent = this;
  if  (NULL != formal_param_list)   formal_param_list->parent = this;
  if  (NULL != nonformal_param_list)   nonformal_param_list->parent = this;
}
void *function_invocation_c::accept(visitor_c &visitor) {return visitor.visit(this);}

statement_list_c::statement_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

statement_list_c::statement_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *statement_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

assignment_statement_c::assignment_statement_c(symbol_c *l_exp,
                           symbol_c *r_exp,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->l_exp = l_exp;
  this->r_exp = r_exp;
  if  (NULL != l_exp)   l_exp->parent = this;
  if  (NULL != r_exp)   r_exp->parent = this;
}
void *assignment_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

return_statement_c::return_statement_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *return_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

fb_invocation_c::fb_invocation_c(symbol_c *fb_name,
                           symbol_c *formal_param_list,
                           symbol_c *nonformal_param_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->fb_name = fb_name;
  this->formal_param_list = formal_param_list;
  this->nonformal_param_list = nonformal_param_list;
  if  (NULL != fb_name)   fb_name->parent = this;
  if  (NULL != formal_param_list)   formal_param_list->parent = this;
  if  (NULL != nonformal_param_list)   nonformal_param_list->parent = this;
}
void *fb_invocation_c::accept(visitor_c &visitor) {return visitor.visit(this);}

param_assignment_list_c::param_assignment_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

param_assignment_list_c::param_assignment_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *param_assignment_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

input_variable_param_assignment_c::input_variable_param_assignment_c(symbol_c *variable_name,
                           symbol_c *expression,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->variable_name = variable_name;
  this->expression = expression;
  if  (NULL != variable_name)   variable_name->parent = this;
  if  (NULL != expression)   expression->parent = this;
}
void *input_variable_param_assignment_c::accept(visitor_c &visitor) {return visitor.visit(this);}

output_variable_param_assignment_c::output_variable_param_assignment_c(symbol_c *not_param,
                           symbol_c *variable_name,
                           symbol_c *variable,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->not_param = not_param;
  this->variable_name = variable_name;
  this->variable = variable;
  if  (NULL != not_param)   not_param->parent = this;
  if  (NULL != variable_name)   variable_name->parent = this;
  if  (NULL != variable)   variable->parent = this;
}
void *output_variable_param_assignment_c::accept(visitor_c &visitor) {return visitor.visit(this);}

not_paramassign_c::not_paramassign_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *not_paramassign_c::accept(visitor_c &visitor) {return visitor.visit(this);}

if_statement_c::if_statement_c(symbol_c *expression,
                           symbol_c *statement_list,
                           symbol_c *elseif_statement_list,
                           symbol_c *else_statement_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->expression = expression;
  this->statement_list = statement_list;
  this->elseif_statement_list = elseif_statement_list;
  this->else_statement_list = else_statement_list;
  if  (NULL != expression)   expression->parent = this;
  if  (NULL != statement_list)   statement_list->parent = this;
  if  (NULL != elseif_statement_list)   elseif_statement_list->parent = this;
  if  (NULL != else_statement_list)   else_statement_list->parent = this;
}
void *if_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

elseif_statement_list_c::elseif_statement_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

elseif_statement_list_c::elseif_statement_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *elseif_statement_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

elseif_statement_c::elseif_statement_c(symbol_c *expression,
                           symbol_c *statement_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->expression = expression;
  this->statement_list = statement_list;
  if  (NULL != expression)   expression->parent = this;
  if  (NULL != statement_list)   statement_list->parent = this;
}
void *elseif_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

case_statement_c::case_statement_c(symbol_c *expression,
                           symbol_c *case_element_list,
                           symbol_c *statement_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->expression = expression;
  this->case_element_list = case_element_list;
  this->statement_list = statement_list;
  if  (NULL != expression)   expression->parent = this;
  if  (NULL != case_element_list)   case_element_list->parent = this;
  if  (NULL != statement_list)   statement_list->parent = this;
}
void *case_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

case_element_list_c::case_element_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

case_element_list_c::case_element_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *case_element_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

case_element_c::case_element_c(symbol_c *case_list,
                           symbol_c *statement_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->case_list = case_list;
  this->statement_list = statement_list;
  if  (NULL != case_list)   case_list->parent = this;
  if  (NULL != statement_list)   statement_list->parent = this;
}
void *case_element_c::accept(visitor_c &visitor) {return visitor.visit(this);}

case_list_c::case_list_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}

case_list_c::case_list_c(symbol_c *elem,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *case_list_c::accept(visitor_c &visitor) {return visitor.visit(this);}

for_statement_c::for_statement_c(symbol_c *control_variable,
                           symbol_c *beg_expression,
                           symbol_c *end_expression,
                           symbol_c *by_expression,
                           symbol_c *statement_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->control_variable = control_variable;
  this->beg_expression = beg_expression;
  this->end_expression = end_expression;
  this->by_expression = by_expression;
  this->statement_list = statement_list;
  if  (NULL != control_variable)   control_variable->parent = this;
  if  (NULL != beg_expression)   beg_expression->parent = this;
  if  (NULL != end_expression)   end_expression->parent = this;
  if  (NULL != by_expression)   by_expression->parent = this;
  if  (NULL != statement_list)   statement_list->parent = this;
}
void *for_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

while_statement_c::while_statement_c(symbol_c *expression,
                           symbol_c *statement_list,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->expression = expression;
  this->statement_list = statement_list;
  if  (NULL != expression)   expression->parent = this;
  if  (NULL != statement_list)   statement_list->parent = this;
}
void *while_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

repeat_statement_c::repeat_statement_c(symbol_c *statement_list,
                           symbol_c *expression,
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {
  this->statement_list = statement_list;
  this->expression = expression;
  if  (NULL != statement_list)   statement_list->parent = this;
  if  (NULL != expression)   expression->parent = this;
}
void *repeat_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

exit_statement_c::exit_statement_c(
                           int fl, int fc, const char *ffile, long int forder,
                 int ll, int lc, const char *lfile, long int lorder)
                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {}
void *exit_statement_c::accept(visitor_c &visitor) {return visitor.visit(this);}

