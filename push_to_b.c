/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:13:35 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 00:31:45 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	*stack_to_array(t_stack *head)
{
	int	size;
	int	*sorted_arr;
	int	i;

	size = ft_lstsize(head);
	sorted_arr = malloc(sizeof(int) * size);
	i = 0;
	while (head != NULL)
	{
		sorted_arr[i++] = head->data;
		head = head->next;
	}
	return (sorted_arr);
}

// Sort the array in ascending order using bubble sort algorithm;
int	*sort_the_array(t_stack *head)
{
	int	*sorted_arr;
	int	i;
	int	j;
	int	temp;

	sorted_arr = stack_to_array(head);
	temp = 0;
	i = 0;
	while (i < ft_lstsize(head) - 1)
	{
		j = 0;
		while (j < ft_lstsize(head) - 1 - i)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
			{
				temp = sorted_arr[j];
				sorted_arr[j] = sorted_arr[j + 1];
				sorted_arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted_arr);
}

int	check_range(t_int v, t_stack **a, t_stack **b, int *sorted_arr)
{
	while (v.range <= v.end - v.start)
	{
		if ((*a)->data >= sorted_arr[v.start]
			&& (*a)->data <= sorted_arr[v.end])
		{
			if ((*a)->data >= v.stack_size / 2)
				pb(a, b);
			else if ((*a)->data < v.stack_size / 2)
			{
				pb(a, b);
				if ((*b)->next)
					rb(b);
			}
			v.range++;
		}
		else
			ra(a);
	}
	return (v.range);
}

void	push_to_b_100(t_stack **a, t_stack **b)
{
	int		*sorted_arr;
	t_int	v;

	sorted_arr = sort_the_array(*a);
	v.stack_size = ft_lstsize(*a);
	v.offset = 10;
	v.end = (v.stack_size / 2 - 1) + v.offset;
	v.start = (v.stack_size / 2 - 1) - v.offset;
	v.range = 0;
	while (*a)
	{
		v.range = check_range(v, a, b, sorted_arr);
		v.start = v.start - v.offset;
		v.end = v.end + v.offset;
		if (v.start < 0)
			v.start = 0;
		if (v.end > v.stack_size)
			v.end = v.stack_size - 1;
	}
	free(sorted_arr);
}

void	push_to_b_500(t_stack **a, t_stack **b)
{
	int		*sorted_arr;
	t_int	v;

	sorted_arr = sort_the_array(*a);
	v.stack_size = ft_lstsize(*a);
	v.offset = 20;
	v.end = (v.stack_size / 2 - 1) + v.offset;
	v.start = (v.stack_size / 2 - 1) - v.offset;
	v.range = 0;
	while (*a)
	{
		v.range = check_range(v, a, b, sorted_arr);
		v.start = v.start - v.offset;
		v.end = v.end + v.offset;
		if (v.start < 0)
			v.start = 0;
		if (v.end > v.stack_size)
			v.end = v.stack_size - 1;
	}
	free(sorted_arr);
}
