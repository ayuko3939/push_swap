/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:05:45 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:37:56 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pivot;

	size = ft_lstsize(*stack_b);
	pivot = get_min(stack_b) + (size / 2);
	while (size--)
	{
		if ((*stack_b)->index < pivot)
		{
			(*stack_b)->group += 1;
			rb(stack_b);
		}
		else
		{
			(*stack_b)->group += 10;
			pa(stack_a, stack_b);
		}
	}
	size = ft_lstsize(*stack_b);
	if (size > 5)
		quick_sort_b(stack_a, stack_b);
}

void	quick_sort_a(t_list **stack_a, t_list **stack_b, int group)
{
	int	size;
	int	pivot;
	int	count;

	size = group_size(*stack_a, group);
	pivot = get_min_group(stack_a, group) + (size / 2);
	count = 0;
	while (size--)
	{
		(*stack_a)->group = 0;
		if ((*stack_a)->index < pivot)
		{
			(*stack_a)->group += 1000;
			pb(stack_a, stack_b);
		}
		else
		{
			(*stack_a)->group += 10000;
			ra(stack_a);
			count++;
		}
	}
	while (count--)
		rra(stack_a);
}
