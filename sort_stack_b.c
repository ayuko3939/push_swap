/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:32:10 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:38:44 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_b(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_b, get_min(stack_b));
	if (distance == 0 || distance == 2)
	{
		if (distance == 2)
			rrb(stack_b);
		save_sorted_nm(stack_a, stack_b, 1, 'b');
		if (!is_sorted_group(stack_b, -1))
			sb(stack_b);
		save_sorted_nm(stack_a, stack_b, 2, 'b');
	}
	else
	{
		if ((*stack_b)->index == get_max(stack_b))
			rb(stack_b);
		else
			sb(stack_b);
		save_sorted_nm(stack_a, stack_b, 3, 'b');
	}
}

static void	sort_four_b(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted_group(stack_b, 4))
	{
		save_sorted_nm(stack_a, stack_b, 4, 'b');
		return ;
	}
	distance = get_distance(stack_b, get_min(stack_b));
	if (distance == 1)
		rb(stack_b);
	else if (distance == 2)
	{
		rb(stack_b);
		rb(stack_b);
	}
	else if (distance == 3)
		rrb(stack_b);
	save_sorted_nm(stack_a, stack_b, 1, 'b');
	sort_three_b(stack_a, stack_b);
}

static void	sort_five_b(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_b, get_min(stack_b));
	if (distance == 1)
		rb(stack_b);
	else if (distance == 2)
	{
		rb(stack_b);
		rb(stack_b);
	}
	else if (distance == 3)
	{
		rrb(stack_b);
		rrb(stack_b);
	}
	else if (distance == 4)
		rrb(stack_b);
	save_sorted_nm(stack_a, stack_b, 1, 'b');
	sort_four_b(stack_a, stack_b);
}

// stack_b is 5 or less
void	sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (is_sorted_group(stack_b, size))
	{
		save_sorted_nm(stack_a, stack_b, size, 'b');
		return ;
	}
	else if (size == 2)
	{
		sb(stack_b);
		save_sorted_nm(stack_a, stack_b, 2, 'b');
		return ;
	}
	else if (size == 3)
		sort_three_b(stack_a, stack_b);
	else if (size == 4)
		sort_four_b(stack_a, stack_b);
	else if (size == 5)
		sort_five_b(stack_a, stack_b);
}
