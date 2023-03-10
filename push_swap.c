/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:16 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/09 18:34:53 by mhassani         ###   ########.fr       */
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
	if (s[i] == '-' || s[i] == '+')
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
void print_stack(t_stack *head)
{
	if(head == NULL)
		return;
    while (head) {
        printf("%ld ", head->data);
        head = head->next;
    }
    printf("\n");
}

int	main(int ac, char *av[])
{
	t_stack	*head;
	t_stack	*newnode;
	t_stack *b = NULL;
	char	**s;
	int		i;
	int		j;

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
				if (!str_is_num(s[j]))
				{
					write(1, "Error\n", 6);
					write(2, "Please enter only numbers less than max int\n", 44);
					exit(1);
				}
				newnode = malloc(sizeof(t_stack));
				newnode->data = ft_atoi(s[j]);
				newnode->next = NULL;
				// add the new node to the list
				ft_lstadd_back(&head, newnode);
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

		// //sort 2 testing;
		// printf("Before sort_three_numbers() function:      ");
		// print_stack(head);
		// sort_two_numbers(&head);
		// printf("After  sort_three_numbers() function:      ");
		// print_stack(head);
		
		//sort 3 testing;
		// printf("Before sort_three_numbers() function:      ");
		// print_stack(head);
		// sort_three_numbers(&head);
		// printf("After  sort_three_numbers() function:      ");
		// print_stack(head);
		// print_stack(head);
		// sort_five(&head, &b);
		// print_stack(head);
		// int i = 0;
		// int size = ft_lstsize(head);
		// while(i < size)
		// printf("%d, ", stack_to_sorted_array(head)[i++]);

		sort_chunk(&head, &b);
		printf("stack b is: \n");
		print_stack(b);
		// printf("\n");
		// printf("stack a is: ");
		// print_stack(head);
	}
}








