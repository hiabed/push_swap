/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:38:22 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/16 21:07:18 by mhassani         ###   ########.fr       */
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

	size = ft_lstsize(head);
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

void	push_to_b_100(t_stack **a, t_stack **b)
{
	int	stack_size;
	int	*arr;
	int	range;
	int	offset;
	int	end;
	int	start;

	stack_size = ft_lstsize(*a);
	arr = stack_to_sorted_array(*a);
	offset = 10;
	end = (stack_size / 2 - 1) + offset;
	start = (stack_size / 2 - 1) - offset;
	range = 0;
	while (*a)
	{
		while (range <= end - start)
		{
			if ((*a)->data >= arr[start] && (*a)->data <= arr[end])
			{
				if ((*a)->data >= stack_size / 2)
					pb(a, b);
				else if ((*a)->data < stack_size / 2)
				{
					pb(a, b);
					if ((*b)->next)
						rb(b);
				}
				range++;
			}
			else
				ra(a);
		}
		start = start - offset;
		end = end + offset;
		if (start < 0)
			start = 0;
		if (end > stack_size)
			end = stack_size - 1;
	}
	free(arr);
}

void	push_to_b_500(t_stack **a, t_stack **b)
{
	int	stack_size;
	int	*arr;
	int	range;
	int	offset;
	int	end;
	int	start;

	stack_size = ft_lstsize(*a);
	arr = stack_to_sorted_array(*a);
	offset = 20;
	end = (stack_size / 2 - 1) + offset;
	start = (stack_size / 2 - 1) - offset;
	range = 0;
	while (*a)
	{
		while (range <= end - start)
		{
			if ((*a)->data >= arr[start] && (*a)->data <= arr[end])
			{
				if ((*a)->data >= stack_size / 2)
					pb(a, b);
				else if ((*a)->data < stack_size / 2)
				{
					pb(a, b);
					if ((*b)->next)
						rb(b);
				}
				range++;
			}
			else
				ra(a);
		}
		start = start - offset;
		end = end + offset;
		if (start < 0)
			start = 0;
		if (end > stack_size)
			end = stack_size - 1;
	}
	free(arr);
}

t_stack	*last_node_adress(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int find_max_index(t_stack **stack)
{
    int max = (*stack)->data;
    int index = 0;
    int i = 0;
    t_stack *current = (*stack)->next;
    while (current != NULL)
    {
        i++;
        if (current->data > max)
        {
            max = current->data;
            index = i;
        }
        current = current->next;
    }
    return index;
}

void	push_to_a_100(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	*sorted_arr;
	int	i;
	int	down;
	

	push_to_b_100(stack_a, stack_b);
	down = 0;
	size = ft_lstsize(*stack_b);
	sorted_arr = stack_to_sorted_array(*stack_b);
	i = size - 1;
	while (*stack_b)
	{
		if ((*stack_b)->data == sorted_arr[i])
		{
			pa(stack_a, stack_b);
			i--;
		}
		else if (down == 0 && (*stack_b)->data != sorted_arr[i])
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			down++;
		}
		else if (down && last_node_adress(*stack_a)->data < (*stack_b)->data)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			down++;
		}
		else if (down && last_node_adress(*stack_a)->data == sorted_arr[i])
		{
			rra(stack_a);
			down--;
			i--;
		}
		else if (down && last_node_adress(*stack_a)->data > (*stack_b)->data)
		{
			if (find_max_index(stack_b) > ft_lstsize(*stack_b) / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}
	}
	if (find_min_index(*stack_a) == size - 1)
		rra(stack_a);
	free(sorted_arr);
}

void	push_to_a_500(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	*sorted_arr;
	int	i;
	int	down;
	

	push_to_b_500(stack_a, stack_b);
	down = 0;
	size = ft_lstsize(*stack_b);
	sorted_arr = stack_to_sorted_array(*stack_b);
	i = size - 1;
	while (*stack_b)
	{
		if ((*stack_b)->data == sorted_arr[i])
		{
			pa(stack_a, stack_b);
			i--;
		}
		else if (down == 0 && (*stack_b)->data != sorted_arr[i])
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			down++;
		}
		else if (down && last_node_adress(*stack_a)->data < (*stack_b)->data)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			down++;
		}
		else if (down && last_node_adress(*stack_a)->data == sorted_arr[i])
		{
			rra(stack_a);
			down--;
			i--;
		}
		else if (down && last_node_adress(*stack_a)->data > (*stack_b)->data)
		{
			if (find_max_index(stack_b) > ft_lstsize(*stack_b) / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}
	}
	if (find_min_index(*stack_a) == size - 1)
		rra(stack_a);
	free(sorted_arr);
}
