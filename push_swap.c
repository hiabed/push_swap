/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:16 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/14 22:24:36 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	str_is_num(char *s)
{
	int	i;

	i = 0;
	if (ft_atoi(s) > INT_MAX)
		return (0);
	if ((s[i] == '-' || s[i] == '+') && ft_strlen(s) > 1)
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
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
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	ptr = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
// Print the elements of the stack
void	print_stack(t_stack *head)
{
	if (head == NULL)
		return ;
	while (head)
	{
		printf("%ld \n", head->data);
		head = head->next;
	}
}

t_stack	*ft_lstnew(long content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->data = content;
	head->next = NULL;
	return (head);
}

int	main(int ac, char *av[])
{
	t_stack	*head;
	t_stack	*b;
	char	**s;
	int		i;
	int		j;

	b = NULL;
	head = NULL;
	i = 1;
	if (ac < 2)
		exit(EXIT_FAILURE);
	else
	{
		while (i < ac)
		{
			s = ft_split(av[i], ' ');
			if (!s[0])
			{
				write(2, "Error\n", 6);
				write(2, "There is an empty string\n", 25);
				exit(1);
			}
			j = 0;
			while (s && s[j])
			{
				if (!str_is_num(s[j]) && !ft_atoi(s[j]))
				{
					write(1, "Error\n", 6);
					write(2, "Please enter only numbers less than max int\n",
							44);
					exit(1);
				}
				ft_lstadd_back(&head, ft_lstnew(ft_atoi(s[j])));
				j++;
			}
			i++;
		}
		if (check_double(head))
		{
			write(2, "Error\n", 6);
			write(2, "There is a double in the list\n", 30);
			exit(1);
		}
		if (ft_lstsize(head) <= 1)
			exit(EXIT_SUCCESS);
		if (ft_lstsize(head) == 2)
			sort_two_numbers(&head);
		if (ft_lstsize(head) == 3)
			sort_three_numbers(&head);
		if (ft_lstsize(head) >= 4)
			sort_five(&head, &b);
		if (ft_lstsize(head) >= 100 && ft_lstsize(head) < 500)
		{
			push_to_a_100(&head, &b);
			print_stack(head);
		}
	}
}
