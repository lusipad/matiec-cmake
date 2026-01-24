void FIXTURE_TEST_init__(FIXTURE_TEST *data__, BOOL retain) {
  __INIT_VAR(data__->COUNTER,0,retain)
}

// Code part
void FIXTURE_TEST_body__(FIXTURE_TEST *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,COUNTER,,(__GET_VAR(data__->COUNTER,) + 1));

  goto __end;

__end:
  return;
} // FIXTURE_TEST_body__() 





