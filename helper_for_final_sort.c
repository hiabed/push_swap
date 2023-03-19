/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_for_final_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:33:32 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 16:39:48 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	find_max_index(t_stack *stack)
{
	int		max;
	int		index;
	int		i;

	max = stack->data;
	index = 0;
	i = 0;
	while (stack->next)
	{
		i++;
		if (stack->next->data > max)
		{
			max = stack->next->data;
			index = i;
		}
		stack = stack->next;
	}
	return (index);
}
