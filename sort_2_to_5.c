/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:38:22 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/17 23:07:09 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	sort_two_numbers(t_stack **head)
{
	sa(head);
}

void	sort_three_numbers(t_stack **head)
{
	t_int	v;

	v.a = (*head)->data;
	v.b = (*head)->next->data;
	v.c = (*head)->next->next->data;
	if ((v.a < v.b) && (v.b > v.c) && (v.a < v.c))
	{
		rra(head);
		sa(head);
	}
	if ((v.a < v.b) && (v.b > v.c) && (v.a > v.c))
		rra(head);
	if ((v.a > v.b) && (v.b < v.c) && (v.a < v.c))
		sa(head);
	if ((v.a > v.b) && (v.b < v.c) && (v.a > v.c))
		ra(head);
	if ((v.a > v.b) && (v.b > v.c))
	{
		sa(head);
		rra(head);
	}
}

int	find_min_index(t_stack *stack)
{
	int		min;
	int		index;
	int		i;
	t_stack	*current;

	min = stack->data;
	index = 0;
	i = 0;
	current = stack->next;
	while (current != NULL)
	{
		i++;
		if (current->data < min)
		{
			min = current->data;
			index = i;
		}
		current = current->next;
	}
	return (index);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	sort_five(t_stack **head_a, t_stack **head_b)
{
	int	min_index;
	int	middle;
	int	lst_size;

	middle = ft_lstsize(*head_a) / 2;
	lst_size = ft_lstsize(*head_a);
	while (lst_size > 3)
	{
		min_index = find_min_index(*head_a);
		if (min_index <= middle)
		{
			while (min_index-- > 0)
				ra(head_a);
		}
		else
		{
			while (min_index++ < lst_size)
				rra(head_a);
		}
		pb(head_a, head_b);
		lst_size--;
	}
	sort_three_numbers(head_a);
	while (*head_b)
		pa(head_a, head_b);
}
