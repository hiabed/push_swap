/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:30:34 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/16 21:19:09 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	long			data;
	struct s_stack	*next;
}					t_stack;

typedef struct var
{
	int				a;
	int				b;
	int				c;
}					var;

void				sa(t_stack **head);
void				sb(t_stack **head);
void				ss(t_stack **a, t_stack **b);
void				push(t_stack **head, int data);
void				pop(t_stack **head);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **top_a);
void				rb(t_stack **top_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **top_a);
void				rrb(t_stack **top_b);
void				rrr(t_stack **top_a, t_stack **top_b);
void				push(t_stack **head, int data);
void				sort_two_numbers(t_stack **head);
void				sort_three_numbers(t_stack **head);
void				sort_five(t_stack **head_a, t_stack **head_b);
int					find_min_index(t_stack *stack);
int					ft_lstsize(t_stack *lst);
int					*stack_to_array(t_stack *head);
int					*stack_to_sorted_array(t_stack *head);
void				push_to_b_100(t_stack **a, t_stack **b);
void				push_to_a_100(t_stack **stack_a, t_stack **stack_b);
t_stack				*last_node_adress(t_stack *stack);
int					find_max_index(t_stack **stack);
void				push_to_b_500(t_stack **a, t_stack **b);
void				push_to_a_500(t_stack **stack_a, t_stack **stack_b);
void				print_stack(t_stack *head);

#endif