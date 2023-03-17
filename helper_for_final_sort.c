/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_for_final_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:33:32 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 00:33:26 by mhassani         ###   ########.fr       */
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

int	find_max_index(t_stack **stack)
{
	int		max;
	int		index;
	int		i;
	t_stack	*current;

	max = (*stack)->data;
	index = 0;
	i = 0;
	current = (*stack)->next;
	while (current != NULL)
	{
		i++;
		if (current->data > max)
		{
			max = current->data;
			index = i;
		}
		current = current->next;
	}
	return (index);
}
