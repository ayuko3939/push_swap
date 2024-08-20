/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:46:48 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 11:57:41 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	int	group;
	int	size;

	group = (*stack_a)->group;
	size = group_size(*stack_a, group);
	if (size <= 5)
	{
		save_next_min(stack_a, group, &size);
		while (size--)
			pb(stack_a, stack_b);
	}
	else
		quick_sort_a(stack_a, stack_b, group);
}

void	recursive_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) <= 5)
		sort_stack_b(stack_a, stack_b);
	else
		quick_sort_b(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 5)
		simple_sort(stack_a, stack_b);
	else
	{
		quick_sort_2pivots_a(stack_a, stack_b);
		while (*stack_b)
		{
			size = group_size(*stack_b, (*stack_b)->group);
			if (size <= 5)
				push_b_to_a(stack_a, stack_b, size);
			else
				quick_sort_2pivots_b(stack_a, stack_b, size);
		}
		while (!is_sorted_group(stack_a, -1))
		{
			if (*stack_b == NULL)
				move_a_to_b(stack_a, stack_b);
			else
				recursive_sort(stack_a, stack_b);
		}
	}
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	check_args(ac, av);
	stack_a = init_stack();
	if (stack_a == NULL)
		error_exit();
	stack_b = init_stack();
	if (stack_b == NULL)
	{
		free_stack(stack_a);
		error_exit();
	}
	set_stack(stack_a, ac, av);
	if (is_sorted_group(stack_a, -1))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
