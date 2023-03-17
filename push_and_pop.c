/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:59:00 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/17 16:01:54 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	push(t_stack **head, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->data = value;
	new_node->next = (*head);
	(*head) = new_node;
}

void	pop(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b != NULL)
	{
		push(a, (*b)->data);
		pop(b);
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a != NULL)
	{
		push(b, (*a)->data);
		pop(a);
	}
	write(1, "pb\n", 3);
}
