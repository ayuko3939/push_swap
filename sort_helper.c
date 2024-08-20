/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:33:38 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:39:29 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// save sorted numbers to bottom of stack_a from stack_a or stack_b
void	save_sorted_nm(t_list **stack_a, t_list **stack_b, int size, char from)
{
	if (from == 'a')
	{
		while (size--)
			ra(stack_a);
	}
	if (from == 'b')
	{
		while (size--)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
	}
}

void	push_b_to_a(t_list **stack_a, t_list **stack_b, int size)
{
	while (size--)
	{
		(*stack_b)->group += 100;
		pa(stack_a, stack_b);
	}
}

void	save_next_min(t_list **stack_a, int group, int *size)
{
	int	distance;

	distance = 0;
	while (*size > 0 && distance == 0)
	{
		distance = get_distance(stack_a, get_min_group(stack_a, group));
		if (distance == 1)
		{
			sa(stack_a);
			distance = 0;
		}
		if (distance == 0)
		{
			ra(stack_a);
			*size -= 1;
		}
	}
}

// is ascending or not ( size : -1 = all )
int	is_sorted_group(t_list **stack, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	if (size == -1)
		size = ft_lstsize(tmp);
	while (i < size - 1)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
