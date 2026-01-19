// Generated fragment. Do not edit manually.
// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)

    void* visit(invalid_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(disable_code_generation_pragma_c* /*symbol*/) override { return nullptr; }
    void* visit(enable_code_generation_pragma_c* /*symbol*/) override { return nullptr; }
    void* visit(pragma_c* /*symbol*/) override { return nullptr; }
    void* visit(library_c* symbol) override { return visit_list(symbol); }
    void* visit(identifier_c* /*symbol*/) override { return nullptr; }
    void* visit(derived_datatype_identifier_c* /*symbol*/) override { return nullptr; }
    void* visit(poutype_identifier_c* /*symbol*/) override { return nullptr; }
    void* visit(ref_value_null_literal_c* /*symbol*/) override { return nullptr; }
    void* visit(real_c* /*symbol*/) override { return nullptr; }
    void* visit(integer_c* /*symbol*/) override { return nullptr; }
    void* visit(binary_integer_c* /*symbol*/) override { return nullptr; }
    void* visit(octal_integer_c* /*symbol*/) override { return nullptr; }
    void* visit(hex_integer_c* /*symbol*/) override { return nullptr; }
    void* visit(neg_real_c* symbol) override { push(symbol->exp); return nullptr; }
    void* visit(neg_integer_c* symbol) override { push(symbol->exp); return nullptr; }
    void* visit(integer_literal_c* symbol) override { push(symbol->type); push(symbol->value); return nullptr; }
    void* visit(real_literal_c* symbol) override { push(symbol->type); push(symbol->value); return nullptr; }
    void* visit(bit_string_literal_c* symbol) override { push(symbol->type); push(symbol->value); return nullptr; }
    void* visit(boolean_literal_c* symbol) override { push(symbol->type); push(symbol->value); return nullptr; }
    void* visit(boolean_true_c* /*symbol*/) override { return nullptr; }
    void* visit(boolean_false_c* /*symbol*/) override { return nullptr; }
    void* visit(double_byte_character_string_c* /*symbol*/) override { return nullptr; }
    void* visit(single_byte_character_string_c* /*symbol*/) override { return nullptr; }
    void* visit(neg_time_c* /*symbol*/) override { return nullptr; }
    void* visit(duration_c* symbol) override { push(symbol->type_name); push(symbol->neg); push(symbol->interval); return nullptr; }
    void* visit(interval_c* symbol) override { push(symbol->days); push(symbol->hours); push(symbol->minutes); push(symbol->seconds); push(symbol->milliseconds); return nullptr; }
    void* visit(fixed_point_c* /*symbol*/) override { return nullptr; }
    void* visit(time_of_day_c* symbol) override { push(symbol->type_name); push(symbol->daytime); return nullptr; }
    void* visit(daytime_c* symbol) override { push(symbol->day_hour); push(symbol->day_minute); push(symbol->day_second); return nullptr; }
    void* visit(date_c* symbol) override { push(symbol->type_name); push(symbol->date_literal); return nullptr; }
    void* visit(date_literal_c* symbol) override { push(symbol->year); push(symbol->month); push(symbol->day); return nullptr; }
    void* visit(date_and_time_c* symbol) override { push(symbol->type_name); push(symbol->date_literal); push(symbol->daytime); return nullptr; }
    void* visit(time_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(bool_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(sint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(int_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(dint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(lint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(usint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(uint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(udint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(ulint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(real_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(lreal_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(date_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(tod_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(dt_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(byte_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(word_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(dword_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(lword_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(string_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(wstring_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(void_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safetime_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safebool_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safesint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safeint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safedint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safelint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safeusint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safeuint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safeudint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safeulint_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safereal_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safelreal_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safedate_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safetod_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safedt_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safebyte_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safeword_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safedword_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safelword_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safestring_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(safewstring_type_name_c* /*symbol*/) override { return nullptr; }
    void* visit(generic_type_any_c* /*symbol*/) override { return nullptr; }
    void* visit(data_type_declaration_c* symbol) override { push(symbol->type_declaration_list); return nullptr; }
    void* visit(type_declaration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(simple_type_declaration_c* symbol) override { push(symbol->simple_type_name); push(symbol->simple_spec_init); return nullptr; }
    void* visit(simple_spec_init_c* symbol) override { push(symbol->simple_specification); push(symbol->constant); return nullptr; }
    void* visit(subrange_type_declaration_c* symbol) override { push(symbol->subrange_type_name); push(symbol->subrange_spec_init); return nullptr; }
    void* visit(subrange_spec_init_c* symbol) override { push(symbol->subrange_specification); push(symbol->signed_integer); return nullptr; }
    void* visit(subrange_specification_c* symbol) override { push(symbol->integer_type_name); push(symbol->subrange); return nullptr; }
    void* visit(subrange_c* symbol) override { push(symbol->lower_limit); push(symbol->upper_limit); return nullptr; }
    void* visit(enumerated_type_declaration_c* symbol) override { push(symbol->enumerated_type_name); push(symbol->enumerated_spec_init); return nullptr; }
    void* visit(enumerated_spec_init_c* symbol) override { push(symbol->enumerated_specification); push(symbol->enumerated_value); return nullptr; }
    void* visit(enumerated_value_list_c* symbol) override { return visit_list(symbol); }
    void* visit(enumerated_value_c* symbol) override { push(symbol->type); push(symbol->value); return nullptr; }
    void* visit(array_type_declaration_c* symbol) override { push(symbol->identifier); push(symbol->array_spec_init); return nullptr; }
    void* visit(array_spec_init_c* symbol) override { push(symbol->array_specification); push(symbol->array_initialization); return nullptr; }
    void* visit(array_specification_c* symbol) override { push(symbol->array_subrange_list); push(symbol->non_generic_type_name); return nullptr; }
    void* visit(array_subrange_list_c* symbol) override { return visit_list(symbol); }
    void* visit(array_initial_elements_list_c* symbol) override { return visit_list(symbol); }
    void* visit(array_initial_elements_c* symbol) override { push(symbol->integer); push(symbol->array_initial_element); return nullptr; }
    void* visit(structure_type_declaration_c* symbol) override { push(symbol->structure_type_name); push(symbol->structure_specification); return nullptr; }
    void* visit(initialized_structure_c* symbol) override { push(symbol->structure_type_name); push(symbol->structure_initialization); return nullptr; }
    void* visit(structure_element_declaration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(structure_element_declaration_c* symbol) override { push(symbol->structure_element_name); push(symbol->spec_init); return nullptr; }
    void* visit(structure_element_initialization_list_c* symbol) override { return visit_list(symbol); }
    void* visit(structure_element_initialization_c* symbol) override { push(symbol->structure_element_name); push(symbol->value); return nullptr; }
    void* visit(string_type_declaration_c* symbol) override { push(symbol->string_type_name); push(symbol->elementary_string_type_name); push(symbol->string_type_declaration_size); push(symbol->string_type_declaration_init); return nullptr; }
    void* visit(fb_spec_init_c* symbol) override { push(symbol->function_block_type_name); push(symbol->structure_initialization); return nullptr; }
    void* visit(ref_spec_c* symbol) override { push(symbol->type_name); return nullptr; }
    void* visit(ref_spec_init_c* symbol) override { push(symbol->ref_spec); push(symbol->ref_initialization); return nullptr; }
    void* visit(ref_type_decl_c* symbol) override { push(symbol->ref_type_name); push(symbol->ref_spec_init); return nullptr; }
    void* visit(symbolic_variable_c* symbol) override { push(symbol->var_name); return nullptr; }
    void* visit(symbolic_constant_c* symbol) override { push(symbol->var_name); return nullptr; }
    void* visit(direct_variable_c* /*symbol*/) override { return nullptr; }
    void* visit(array_variable_c* symbol) override { push(symbol->subscripted_variable); push(symbol->subscript_list); return nullptr; }
    void* visit(subscript_list_c* symbol) override { return visit_list(symbol); }
    void* visit(structured_variable_c* symbol) override { push(symbol->record_variable); push(symbol->field_selector); return nullptr; }
    void* visit(constant_option_c* /*symbol*/) override { return nullptr; }
    void* visit(retain_option_c* /*symbol*/) override { return nullptr; }
    void* visit(non_retain_option_c* /*symbol*/) override { return nullptr; }
    void* visit(input_declarations_c* symbol) override { push(symbol->option); push(symbol->input_declaration_list); push(symbol->method); return nullptr; }
    void* visit(input_declaration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(implicit_definition_c* /*symbol*/) override { return nullptr; }
    void* visit(explicit_definition_c* /*symbol*/) override { return nullptr; }
    void* visit(en_param_declaration_c* symbol) override { push(symbol->name); push(symbol->type_decl); push(symbol->method); return nullptr; }
    void* visit(eno_param_declaration_c* symbol) override { push(symbol->name); push(symbol->type); push(symbol->method); return nullptr; }
    void* visit(edge_declaration_c* symbol) override { push(symbol->edge); push(symbol->var1_list); return nullptr; }
    void* visit(raising_edge_option_c* /*symbol*/) override { return nullptr; }
    void* visit(falling_edge_option_c* /*symbol*/) override { return nullptr; }
    void* visit(var1_init_decl_c* symbol) override { push(symbol->var1_list); push(symbol->spec_init); return nullptr; }
    void* visit(var1_list_c* symbol) override { return visit_list(symbol); }
    void* visit(extensible_input_parameter_c* symbol) override { push(symbol->var_name); push(symbol->first_index); return nullptr; }
    void* visit(array_var_init_decl_c* symbol) override { push(symbol->var1_list); push(symbol->array_spec_init); return nullptr; }
    void* visit(structured_var_init_decl_c* symbol) override { push(symbol->var1_list); push(symbol->initialized_structure); return nullptr; }
    void* visit(fb_name_decl_c* symbol) override { push(symbol->fb_name_list); push(symbol->fb_spec_init); return nullptr; }
    void* visit(fb_name_list_c* symbol) override { return visit_list(symbol); }
    void* visit(output_declarations_c* symbol) override { push(symbol->option); push(symbol->var_init_decl_list); push(symbol->method); return nullptr; }
    void* visit(input_output_declarations_c* symbol) override { push(symbol->var_declaration_list); return nullptr; }
    void* visit(var_declaration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(array_var_declaration_c* symbol) override { push(symbol->var1_list); push(symbol->array_specification); return nullptr; }
    void* visit(structured_var_declaration_c* symbol) override { push(symbol->var1_list); push(symbol->structure_type_name); return nullptr; }
    void* visit(var_declarations_c* symbol) override { push(symbol->option); push(symbol->var_init_decl_list); return nullptr; }
    void* visit(retentive_var_declarations_c* symbol) override { push(symbol->var_init_decl_list); return nullptr; }
    void* visit(located_var_declarations_c* symbol) override { push(symbol->option); push(symbol->located_var_decl_list); return nullptr; }
    void* visit(located_var_decl_list_c* symbol) override { return visit_list(symbol); }
    void* visit(located_var_decl_c* symbol) override { push(symbol->variable_name); push(symbol->location); push(symbol->located_var_spec_init); return nullptr; }
    void* visit(external_var_declarations_c* symbol) override { push(symbol->option); push(symbol->external_declaration_list); return nullptr; }
    void* visit(external_declaration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(external_declaration_c* symbol) override { push(symbol->global_var_name); push(symbol->specification); return nullptr; }
    void* visit(global_var_declarations_c* symbol) override { push(symbol->option); push(symbol->global_var_decl_list); return nullptr; }
    void* visit(global_var_decl_list_c* symbol) override { return visit_list(symbol); }
    void* visit(global_var_decl_c* symbol) override { push(symbol->global_var_spec); push(symbol->type_specification); return nullptr; }
    void* visit(global_var_spec_c* symbol) override { push(symbol->global_var_name); push(symbol->location); return nullptr; }
    void* visit(location_c* symbol) override { push(symbol->direct_variable); return nullptr; }
    void* visit(global_var_list_c* symbol) override { return visit_list(symbol); }
    void* visit(single_byte_string_var_declaration_c* symbol) override { push(symbol->var1_list); push(symbol->single_byte_string_spec); return nullptr; }
    void* visit(single_byte_string_spec_c* symbol) override { push(symbol->string_spec); push(symbol->single_byte_character_string); return nullptr; }
    void* visit(single_byte_limited_len_string_spec_c* symbol) override { push(symbol->string_type_name); push(symbol->character_string_len); return nullptr; }
    void* visit(double_byte_limited_len_string_spec_c* symbol) override { push(symbol->string_type_name); push(symbol->character_string_len); return nullptr; }
    void* visit(double_byte_string_var_declaration_c* symbol) override { push(symbol->var1_list); push(symbol->double_byte_string_spec); return nullptr; }
    void* visit(double_byte_string_spec_c* symbol) override { push(symbol->string_spec); push(symbol->double_byte_character_string); return nullptr; }
    void* visit(incompl_located_var_declarations_c* symbol) override { push(symbol->option); push(symbol->incompl_located_var_decl_list); return nullptr; }
    void* visit(incompl_located_var_decl_list_c* symbol) override { return visit_list(symbol); }
    void* visit(incompl_located_var_decl_c* symbol) override { push(symbol->variable_name); push(symbol->incompl_location); push(symbol->var_spec); return nullptr; }
    void* visit(incompl_location_c* /*symbol*/) override { return nullptr; }
    void* visit(var_init_decl_list_c* symbol) override { return visit_list(symbol); }
    void* visit(function_declaration_c* symbol) override { push(symbol->derived_function_name); push(symbol->type_name); push(symbol->var_declarations_list); push(symbol->function_body); return nullptr; }
    void* visit(var_declarations_list_c* symbol) override { return visit_list(symbol); }
    void* visit(function_var_decls_c* symbol) override { push(symbol->option); push(symbol->decl_list); return nullptr; }
    void* visit(var2_init_decl_list_c* symbol) override { return visit_list(symbol); }
    void* visit(function_block_declaration_c* symbol) override { push(symbol->fblock_name); push(symbol->var_declarations); push(symbol->fblock_body); return nullptr; }
    void* visit(temp_var_decls_c* symbol) override { push(symbol->var_decl_list); return nullptr; }
    void* visit(temp_var_decls_list_c* symbol) override { return visit_list(symbol); }
    void* visit(non_retentive_var_decls_c* symbol) override { push(symbol->var_decl_list); return nullptr; }
    void* visit(program_declaration_c* symbol) override { push(symbol->program_type_name); push(symbol->var_declarations); push(symbol->function_block_body); return nullptr; }
    void* visit(sequential_function_chart_c* symbol) override { return visit_list(symbol); }
    void* visit(sfc_network_c* symbol) override { return visit_list(symbol); }
    void* visit(initial_step_c* symbol) override { push(symbol->step_name); push(symbol->action_association_list); return nullptr; }
    void* visit(action_association_list_c* symbol) override { return visit_list(symbol); }
    void* visit(step_c* symbol) override { push(symbol->step_name); push(symbol->action_association_list); return nullptr; }
    void* visit(action_association_c* symbol) override { push(symbol->action_name); push(symbol->action_qualifier); push(symbol->indicator_name_list); return nullptr; }
    void* visit(qualifier_c* /*symbol*/) override { return nullptr; }
    void* visit(timed_qualifier_c* /*symbol*/) override { return nullptr; }
    void* visit(indicator_name_list_c* symbol) override { return visit_list(symbol); }
    void* visit(action_qualifier_c* symbol) override { push(symbol->action_qualifier); push(symbol->action_time); return nullptr; }
    void* visit(transition_c* symbol) override { push(symbol->transition_name); push(symbol->integer); push(symbol->from_steps); push(symbol->to_steps); push(symbol->transition_condition); return nullptr; }
    void* visit(transition_condition_c* symbol) override { push(symbol->transition_condition_il); push(symbol->transition_condition_st); return nullptr; }
    void* visit(steps_c* symbol) override { push(symbol->step_name); push(symbol->step_name_list); return nullptr; }
    void* visit(step_name_list_c* symbol) override { return visit_list(symbol); }
    void* visit(action_c* symbol) override { push(symbol->action_name); push(symbol->function_block_body); return nullptr; }
    void* visit(configuration_declaration_c* symbol) override { push(symbol->configuration_name); push(symbol->global_var_declarations); push(symbol->resource_declarations); push(symbol->access_declarations); push(symbol->instance_specific_initializations); return nullptr; }
    void* visit(global_var_declarations_list_c* symbol) override { return visit_list(symbol); }
    void* visit(resource_declaration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(resource_declaration_c* symbol) override { push(symbol->resource_name); push(symbol->resource_type_name); push(symbol->global_var_declarations); push(symbol->resource_declaration); return nullptr; }
    void* visit(single_resource_declaration_c* symbol) override { push(symbol->task_configuration_list); push(symbol->program_configuration_list); return nullptr; }
    void* visit(task_configuration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(program_configuration_list_c* symbol) override { return visit_list(symbol); }
    void* visit(any_fb_name_list_c* symbol) override { return visit_list(symbol); }
    void* visit(global_var_reference_c* symbol) override { push(symbol->resource_name); push(symbol->global_var_name); push(symbol->structure_element_name); return nullptr; }
    void* visit(program_output_reference_c* symbol) override { push(symbol->program_name); push(symbol->symbolic_variable); return nullptr; }
    void* visit(task_configuration_c* symbol) override { push(symbol->task_name); push(symbol->task_initialization); return nullptr; }
    void* visit(task_initialization_c* symbol) override { push(symbol->single_data_source); push(symbol->interval_data_source); push(symbol->priority_data_source); return nullptr; }
    void* visit(program_configuration_c* symbol) override { push(symbol->retain_option); push(symbol->program_name); push(symbol->task_name); push(symbol->program_type_name); push(symbol->prog_conf_elements); return nullptr; }
    void* visit(prog_conf_elements_c* symbol) override { return visit_list(symbol); }
    void* visit(fb_task_c* symbol) override { push(symbol->fb_name); push(symbol->task_name); return nullptr; }
    void* visit(prog_cnxn_assign_c* symbol) override { push(symbol->symbolic_variable); push(symbol->prog_data_source); return nullptr; }
    void* visit(prog_cnxn_sendto_c* symbol) override { push(symbol->symbolic_variable); push(symbol->data_sink); return nullptr; }
    void* visit(instance_specific_initializations_c* symbol) override { push(symbol->instance_specific_init_list); return nullptr; }
    void* visit(instance_specific_init_list_c* symbol) override { return visit_list(symbol); }
    void* visit(instance_specific_init_c* symbol) override { push(symbol->resource_name); push(symbol->program_name); push(symbol->any_fb_name_list); push(symbol->variable_name); push(symbol->location); push(symbol->initialization); return nullptr; }
    void* visit(fb_initialization_c* symbol) override { push(symbol->function_block_type_name); push(symbol->structure_initialization); return nullptr; }
    void* visit(instruction_list_c* symbol) override { return visit_list(symbol); }
    void* visit(il_instruction_c* symbol) override { push(symbol->label); push(symbol->il_instruction); return nullptr; }
    void* visit(il_simple_operation_c* symbol) override { push(symbol->il_simple_operator); push(symbol->il_operand); return nullptr; }
    void* visit(il_function_call_c* symbol) override { push(symbol->function_name); push(symbol->il_operand_list); return nullptr; }
    void* visit(il_expression_c* symbol) override { push(symbol->il_expr_operator); push(symbol->il_operand); push(symbol->simple_instr_list); return nullptr; }
    void* visit(il_jump_operation_c* symbol) override { push(symbol->il_jump_operator); push(symbol->label); return nullptr; }
    void* visit(il_fb_call_c* symbol) override { push(symbol->il_call_operator); push(symbol->fb_name); push(symbol->il_operand_list); push(symbol->il_param_list); return nullptr; }
    void* visit(il_formal_funct_call_c* symbol) override { push(symbol->function_name); push(symbol->il_param_list); return nullptr; }
    void* visit(il_operand_list_c* symbol) override { return visit_list(symbol); }
    void* visit(simple_instr_list_c* symbol) override { return visit_list(symbol); }
    void* visit(il_simple_instruction_c* symbol) override { push(symbol->il_simple_instruction); return nullptr; }
    void* visit(il_param_list_c* symbol) override { return visit_list(symbol); }
    void* visit(il_param_assignment_c* symbol) override { push(symbol->il_assign_operator); push(symbol->il_operand); push(symbol->simple_instr_list); return nullptr; }
    void* visit(il_param_out_assignment_c* symbol) override { push(symbol->il_assign_out_operator); push(symbol->variable); return nullptr; }
    void* visit(LD_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(LDN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(ST_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(STN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(NOT_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(S_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(R_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(S1_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(R1_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(CLK_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(CU_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(CD_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(PV_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(IN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(PT_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(AND_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(OR_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(XOR_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(ANDN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(ORN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(XORN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(ADD_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(SUB_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(MUL_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(DIV_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(MOD_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(GT_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(GE_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(EQ_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(LT_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(LE_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(NE_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(CAL_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(CALC_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(CALCN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(RET_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(RETC_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(RETCN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(JMP_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(JMPC_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(JMPCN_operator_c* /*symbol*/) override { return nullptr; }
    void* visit(il_assign_operator_c* symbol) override { push(symbol->variable_name); return nullptr; }
    void* visit(il_assign_out_operator_c* symbol) override { push(symbol->option); push(symbol->variable_name); return nullptr; }
    void* visit(ref_expression_c* symbol) override { push(symbol->exp); return nullptr; }
    void* visit(deref_expression_c* symbol) override { push(symbol->exp); return nullptr; }
    void* visit(deref_operator_c* symbol) override { push(symbol->exp); return nullptr; }
    void* visit(or_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(xor_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(and_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(equ_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(notequ_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(lt_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(gt_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(le_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(ge_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(add_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(sub_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(mul_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(div_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(mod_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(power_expression_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(neg_expression_c* symbol) override { push(symbol->exp); return nullptr; }
    void* visit(not_expression_c* symbol) override { push(symbol->exp); return nullptr; }
    void* visit(function_invocation_c* symbol) override { push(symbol->function_name); push(symbol->formal_param_list); push(symbol->nonformal_param_list); return nullptr; }
    void* visit(statement_list_c* symbol) override { return visit_list(symbol); }
    void* visit(assignment_statement_c* symbol) override { push(symbol->l_exp); push(symbol->r_exp); return nullptr; }
    void* visit(return_statement_c* /*symbol*/) override { return nullptr; }
    void* visit(fb_invocation_c* symbol) override { push(symbol->fb_name); push(symbol->formal_param_list); push(symbol->nonformal_param_list); return nullptr; }
    void* visit(param_assignment_list_c* symbol) override { return visit_list(symbol); }
    void* visit(input_variable_param_assignment_c* symbol) override { push(symbol->variable_name); push(symbol->expression); return nullptr; }
    void* visit(output_variable_param_assignment_c* symbol) override { push(symbol->not_param); push(symbol->variable_name); push(symbol->variable); return nullptr; }
    void* visit(not_paramassign_c* /*symbol*/) override { return nullptr; }
    void* visit(if_statement_c* symbol) override { push(symbol->expression); push(symbol->statement_list); push(symbol->elseif_statement_list); push(symbol->else_statement_list); return nullptr; }
    void* visit(elseif_statement_list_c* symbol) override { return visit_list(symbol); }
    void* visit(elseif_statement_c* symbol) override { push(symbol->expression); push(symbol->statement_list); return nullptr; }
    void* visit(case_statement_c* symbol) override { push(symbol->expression); push(symbol->case_element_list); push(symbol->statement_list); return nullptr; }
    void* visit(case_element_list_c* symbol) override { return visit_list(symbol); }
    void* visit(case_element_c* symbol) override { push(symbol->case_list); push(symbol->statement_list); return nullptr; }
    void* visit(case_list_c* symbol) override { return visit_list(symbol); }
    void* visit(for_statement_c* symbol) override { push(symbol->control_variable); push(symbol->beg_expression); push(symbol->end_expression); push(symbol->by_expression); push(symbol->statement_list); return nullptr; }
    void* visit(while_statement_c* symbol) override { push(symbol->expression); push(symbol->statement_list); return nullptr; }
    void* visit(repeat_statement_c* symbol) override { push(symbol->statement_list); push(symbol->expression); return nullptr; }
    void* visit(exit_statement_c* /*symbol*/) override { return nullptr; }
