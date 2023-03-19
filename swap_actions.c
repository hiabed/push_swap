/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:45:38 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 17:00:37 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	sa(t_stack **head)
{
	int	temp;

	temp = (*head)->data;
	(*head)->data = (*head)->next->data;
	(*head)->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **head)
{
	int	temp;

	temp = (*head)->data;
	(*head)->data = (*head)->next->data;
	(*head)->next->data = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	rrr(t_stack **top_a, t_stack **top_b)
{
	rra(top_a);
	rrb(top_b);
	write(1, "rrr\n", 4);
}
