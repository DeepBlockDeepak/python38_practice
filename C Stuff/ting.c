void outer_menu_for_black_box_function_calls(
	unsigned long *sorted_list, int list_size, int step, int cycles,
	int function_choice, int shuffle_option_for_arrays, 
	void (*func_pointer_to_1)(unsigned long),
	void (*func_pointer_to_2)(unsigned long),
	void (*func_pointer_to_3)(unsigned long*, unsigned long),
	void (*func_pointer_to_4)(unsigned long),
	void (*func_pointer_to_5)(unsigned long),
	void (*func_pointer_to_6)(unsigned long*, unsigned long),
	void (*func_pointer_to_7)(unsigned long),
	void (*func_pointer_to_array_sort_in_order)(unsigned long**, int),
	void (*func_pointer_to_array_sort_reverse)(unsigned long**, int),
	void (*func_pointer_to_array_sort_random_shuffle)(unsigned long**, int)
);


