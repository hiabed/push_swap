/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:38:22 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/10 22:25:23 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	sort_two_numbers(t_stack **head)
{
	if ((*head)->data < (*head)->next->data)
		return ;
	else
		sa(head);
}

void	sort_three_numbers(t_stack **head)
{
	var	v;

	v.a = (*head)->data;
	v.b = (*head)->next->data;
	v.c = (*head)->next->next->data;
	if ((v.a < v.b) && (v.b < v.c))
		return ;
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

int	*stack_to_array(t_stack *head)
{
	int	size;
	int	*sortedArr;
	int	i;

	size = ft_lstsize(head) - 1;
	sortedArr = malloc(sizeof(int) * size);
	i = 0;
	while (head != NULL)
	{
		sortedArr[i++] = head->data;
		head = head->next;
	}
	return (sortedArr);
}

// Sort the array in ascending order using bubble sort algorithm;
int	*stack_to_sorted_array(t_stack *head)
{
	int	*sortedArr;
	int	i;
	int	j;
	int	temp;

	sortedArr = stack_to_array(head);
	temp = 0;
	i = 0;
	while (i < ft_lstsize(head) - 1)
	{
		j = 0;
		while (j < ft_lstsize(head) - 1 - i)
		{
			if (sortedArr[j] > sortedArr[j + 1])
			{
				temp = sortedArr[j];
				sortedArr[j] = sortedArr[j + 1];
				sortedArr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (sortedArr);
}

// int	ft_range(int *arr, int start, int end, int content)
// {
// 	int	i;

// 	if (!arr)
// 		return (0);
// 	i = 0;
// 	while (i < end - start + 1)
// 	{
// 		if (content == arr[start + i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

void sort_chunk(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current = *stack_a;
    int stack_size = ft_lstsize(current);
    int *sorted_arr = stack_to_sorted_array(current);
    int offset = 10;
//    int i ;
//    i= 20;
	int range;
    int chunk_start = (stack_size / 2 - 1) - offset;
    int chunk_end = (stack_size / 2 - 1) + offset;
	range = chunk_start;
    while (*stack_a)
    {
        while (range <= chunk_end - chunk_start)
        {
            if (current->data >= sorted_arr[chunk_start] && current->data <= sorted_arr[chunk_end])
                pb(&current, stack_b);       //push to top;
            else
			{
                ra(&current);
				printf("ssss%d\n",chunk_start);
				printf("eeee%d\n",chunk_end);
			}
			range++;
		if(range == 100)
			return;
        }
        chunk_start -= offset;
		chunk_end += offset;
		if (chunk_start < 0)
			chunk_start = 0;
		if (chunk_end > stack_size)
			chunk_end = stack_size - 1;
        printf("------------------\n");
    }
    free(sorted_arr);
}

// void	sort_chunk(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*current;
// 	int		stack_size;
// 	int		*sorted_arr;
// 	int		chunk_start;
// 	int		chunk_end;
// 	int		offset;
// 	int		i;

// 	current = *stack_a;
// 	stack_size = ft_lstsize(*stack_a);
// 	sorted_arr = stack_to_sorted_array(*stack_a);
// 	offset = 4;
// 	i = 0;
// 	while (current)
// 	{
// 		chunk_start = (stack_size / 2) - offset;
// 		chunk_end = (stack_size / 2) + offset;
// 		while (i < stack_size && *stack_a)
// 		{
// 			if ((*stack_a)->data >= sorted_arr[chunk_start]
// 				&& (*stack_a)->data <= sorted_arr[chunk_end])
// 			{
// 				if (i >= stack_size / 2)
// 					pb(stack_a, stack_b);
// 				else
// 				{
// 					pb(stack_a, stack_b);
// 					rb(stack_b);
// 				}
// 			}
// 			else
// 				ra(stack_a);
// 			i++;
// 		}
// 		offset = offset + 2;
// 		printf("------------------");
// 		current = current->next;
// 	}
// 	free(sorted_arr);
// }

// void	sort_hundred(t_stack **head_a, t_stack **head_b)
// {
// 	int	mid;
// 	int	offset;
// 	int	start;
// 	int	end;

// 	mid = (ft_lstsize(&head_a) / 2) - 1;
// 	offset = (ft_lstsize(&head_a) / (ft_lstsize(&head_a) / 2));
// 	start = mid - offsets;
// 	end = mid + offset;

// }
