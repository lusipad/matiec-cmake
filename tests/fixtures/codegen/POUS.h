#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// PROGRAM FIXTURE_TEST
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,COUNTER)

} FIXTURE_TEST;

void FIXTURE_TEST_init__(FIXTURE_TEST *data__, BOOL retain);
// Code part
void FIXTURE_TEST_body__(FIXTURE_TEST *data__);
#endif //__POUS_H
