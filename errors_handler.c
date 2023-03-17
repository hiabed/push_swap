/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:32:41 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 00:33:57 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	str_is_num(char *s)
{
	int	i;

	i = 0;
	if (ft_atoi(s) > INT_MAX)
	{
		write(1, "Error\n", 6);
		write(2, "enter only numbers less than max int\n", 37);
		exit(EXIT_FAILURE);
	}
	if ((s[i] == '-' || s[i] == '+') && ft_strlen(s) > 1)
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			write(1, "Error\n", 6);
			write(2, "enter only numbers less than max int\n", 37);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

int	check_double(t_stack *head)
{
	t_stack	*current;
	t_stack	*runner;

	current = head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->data == runner->data)
			{
				write(2, "Error\n", 6);
				write(2, "There is a double in the list\n", 30);
				exit(1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	is_empty(char *s)
{
	if (!s)
	{
		write(2, "Error\n", 6);
		write(2, "There is an empty string\n", 25);
		exit(1);
	}
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
