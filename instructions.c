/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:45:38 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/05 20:34:20 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	sa(t_stack **head)
{
	int	temp;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp = (*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = temp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack **head)
{
	int	temp;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp = (*head)->data;
		(*head)->data = (*head)->next->data;
		(*head)->next->data = temp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	push(t_stack **head, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->data = value;
	new_node->next = (*head);    //(*head) refers to the current top node of the stack;
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
	// find the last node and the second to last node
	prev = NULL;
	last = *top_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	// move the last node to the front
	last->next = *top_a;
	*top_a = last;
	// update the previous node to become the new last node
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **top_b)
{
	t_stack	*prev;
	t_stack	*last;

	if (*top_b == NULL || (*top_b)->next == NULL)
		return ;
	// find the last node and the second to last node
	prev = NULL;
	last = *top_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	// move the last node to the front
	last->next = *top_b;
	*top_b = last;
	// update the previous node to become the new last node
	prev->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **top_a, t_stack **top_b)
{
	rra(top_a);
	rrb(top_b);
	write(1, "rrr\n", 4);
}