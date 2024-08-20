/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2pivots.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:06:14 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:31:32 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_three_sizes_b(t_list **stack_a, t_list **stack_b,
		t_pivot pivot, t_count *count)
{
	if ((*stack_b)->index >= pivot.l)
	{
		(*stack_b)->group += 100;
		pa(stack_a, stack_b);
	}
	else if ((*stack_b)->index >= pivot.s)
	{
		(*stack_b)->group += 10;
		pa(stack_a, stack_b);
		ra(stack_a);
		count->ra++;
	}
	else
	{
		(*stack_b)->group += 1;
		rb(stack_b);
		count->rb++;
	}
}

void	quick_sort_2pivots_b(t_list **stack_a, t_list **stack_b, int size)
{
	t_pivot	pivot;
	t_count	count;

	pivot.s = get_min_group(stack_b, (*stack_b)->group) + size / 3;
	pivot.l = get_min_group(stack_b, (*stack_b)->group) + size / 3 * 2;
	count.ra = 0;
	count.rb = 0;
	while (size--)
		divide_three_sizes_b(stack_a, stack_b, pivot, &count);
	while (count.ra--)
		rra(stack_a);
	while (count.rb--)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

static void	divide_three_sizes_a(t_list **stack_a, t_list **stack_b,
		t_pivot pivot)
{
	if ((*stack_a)->index >= pivot.l)
	{
		(*stack_a)->group += 100000;
		ra(stack_a);
	}
	else if ((*stack_a)->index >= pivot.s)
	{
		(*stack_a)->group += 10000;
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else
	{
		(*stack_a)->group += 1000;
		pb(stack_a, stack_b);
	}
}

void	quick_sort_2pivots_a(t_list **stack_a, t_list **stack_b)
{
	t_pivot	pivot;
	int		size;

	size = ft_lstsize(*stack_a);
	pivot.s = get_min(stack_a) + size / 3;
	pivot.l = get_min(stack_a) + size / 3 * 2;
	while (size--)
		divide_three_sizes_a(stack_a, stack_b, pivot);
	while (ft_lstlast(*stack_b)->group != 1000)
		rrb(stack_b);
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		quick_sort_2pivots_a(stack_a, stack_b);
}
