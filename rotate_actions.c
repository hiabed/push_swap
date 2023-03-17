/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:10:45 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 00:32:34 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ra(t_stack **top_a)
{
	t_stack	*current;

	if (*top_a != NULL && (*top_a)->next != NULL)
	{
		current = *top_a;
		while (current->next != NULL)
			current = current->next;
		current->next = *top_a;
		*top_a = (*top_a)->next;
		current->next->next = NULL;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **top_b)
{
	t_stack	*current;

	if (*top_b != NULL && (*top_b)->next != NULL)
	{
		current = *top_b;
		while (current->next != NULL)
			current = current->next;
		current->next = *top_b;
		*top_b = (*top_b)->next;
		current->next->next = NULL;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_stack **top_a)
{
	t_stack	*prev;
	t_stack	*last;

	if (*top_a == NULL || (*top_a)->next == NULL)
		return ;
	prev = NULL;
	last = *top_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	last->next = *top_a;
	*top_a = last;
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **top_b)
{
	t_stack	*prev;
	t_stack	*last;

	if (*top_b == NULL || (*top_b)->next == NULL)
		return ;
	prev = NULL;
	last = *top_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	last->next = *top_b;
	*top_b = last;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}
