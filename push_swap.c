/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:16 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/18 15:35:35 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

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

void	print_stack(t_stack *head)
{
	if (head == NULL)
		return ;
	while (head)
	{
		printf("%ld ", head->data);
		head = head->next;
	}
}

t_stack	*ft_lstnew(long value)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->data = value;
	head->next = NULL;
	return (head);
}

void	fill_all_stack(t_stack **head, int i, char *av[], char **s)
{
	int	j;

	while (av[i])
	{
		s = ft_split(av[i], ' ');
		is_empty(s[0]);
		j = 0;
		while (s && s[j])
		{
			str_is_num(s[j]);
			ft_lstadd_back(head, ft_lstnew(ft_atoi(s[j])));
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	check_double(*head);
	if (is_sorted(*head))
		exit(EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_stack	*head;
	t_stack	*b;
	char	**s;
	int		i;

	s = NULL;
	b = NULL;
	head = NULL;
	i = 1;
	if (ac < 2)
		exit(EXIT_FAILURE);
	else
	{
		fill_all_stack(&head, i, av, s);
		if (ft_lstsize(head) == 2)
			sort_two_numbers(&head);
		if (ft_lstsize(head) == 3)
			sort_three_numbers(&head);
		if (ft_lstsize(head) >= 4 && ft_lstsize(head) < 20)
			sort_five(&head, &b);
		if (ft_lstsize(head) >= 20 && ft_lstsize(head) <= 100)
			push_to_a_100(&head, &b);
		if (ft_lstsize(head) > 100)
			push_to_a_500(&head, &b);
	}
}
