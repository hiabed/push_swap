/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:29:31 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 15:31:02 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	pa_ra_down(t_stack **stack_a, t_stack **stack_b, t_int v)
{
	pa(stack_a, stack_b);
	ra(stack_a);
	v.down++;
	return (v.down);
}

void	conditions(t_stack **stack_a, t_stack **stack_b, int *sorted_arr,
		t_int v)
{
	while (*stack_b)
	{
		if ((*stack_b)->data == sorted_arr[v.i])
		{
			pa(stack_a, stack_b);
			v.i--;
		}
		else if (v.down == 0 && (*stack_b)->data != sorted_arr[v.i])
			v.down = pa_ra_down(stack_a, stack_b, v);
		else if (v.down && last_node(*stack_a)->data < (*stack_b)->data)
			v.down = pa_ra_down(stack_a, stack_b, v);
		else if (v.down && last_node(*stack_a)->data == sorted_arr[v.i])
		{
			rra(stack_a);
			v.down--;
			v.i--;
		}
		else if (v.down && last_node(*stack_a)->data > (*stack_b)->data)
		{
			if (find_max_index(stack_b) > ft_lstsize(*stack_b) / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}
	}
}

void	push_to_a_100(t_stack **stack_a, t_stack **stack_b)
{
	t_int	v;
	int		*sorted_arr;

	push_to_b_100(stack_a, stack_b);
	v.down = 0;
	v.size = ft_lstsize(*stack_b);
	sorted_arr = sort_the_array(*stack_b);
	v.i = v.size - 1;
	conditions(stack_a, stack_b, sorted_arr, v);
	while (!is_sorted(*stack_a))
		rra(stack_a);
	free(sorted_arr);
}

void	push_to_a_500(t_stack **stack_a, t_stack **stack_b)
{
	t_int	v;
	int		*sorted_arr;

	push_to_b_500(stack_a, stack_b);
	v.down = 0;
	v.size = ft_lstsize(*stack_b);
	sorted_arr = sort_the_array(*stack_b);
	v.i = v.size - 1;
	conditions(stack_a, stack_b, sorted_arr, v);
	while (!is_sorted(*stack_a))
		rra(stack_a);
	free(sorted_arr);
}
