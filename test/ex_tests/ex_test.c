#include "ex_test.h"

t_li_node	*EX_str_arr_to_list(char **arr)
{
	t_li_node *node;
	node = 0;
	int i = 0;
	while(arr[i])
	{
		li_new_stack(&node, mini_strdup(arr[i]));
		i += 1;
	}
	return node;
}

t_ps_input	*EX_input_dup(t_ps_input data)
{
	t_ps_input *duplicate = mini_malloc(sizeof(t_ps_input));
	mini_assert(duplicate != NULL, "allocation in EX_input_dup works");
	duplicate->fd = data.fd;
	duplicate->type = data.type;
	duplicate->name = mini_strdup(data.name);
	mini_assert(duplicate->name != NULL, "allocation in EX_input_dup works");
	return duplicate;
}

t_li_node	*EX_input_arr_to_list(t_ps_input *arr)
{
	t_li_node *node;
	node = 0;
	int i = 0;
	while(arr[i].name)
	{
		li_new_stack(&node, EX_input_dup(arr[i]));
		i += 1;
	}
	return node;
}

t_ps_input	*EX_output_dup(t_ps_output data)
{
	t_ps_input *duplicate = mini_malloc(sizeof(t_ps_input));
	mini_assert(duplicate != NULL, "allocation in EX_input_dup works");
	duplicate->fd = data.fd;
	duplicate->type = data.type;
	duplicate->name = mini_strdup(data.name);
	mini_assert(duplicate->name != NULL, "allocation in EX_input_dup works");
	return duplicate;
}

t_li_node	*EX_input_arr_to_list(t_ps_input *arr)
{
	t_li_node *node;
	node = 0;
	int i = 0;
	while(arr[i].name)
	{
		li_new_stack(&node, EX_input_dup(arr[i]));
		i += 1;
	}
	return node;
}

t_ps_single_command	*EX_create_command(t_EX_dummy_command dummy)
{

}

t_li_node	*EX_create_commands(t_EX_dummy_command* dummies)
{

}