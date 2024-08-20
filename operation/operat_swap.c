/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operat_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:12:30 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:41:41 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 0:OK  1:NG
static int	validate(t_list **stack)
{
	t_list	*head;
	t_list	*next;

	head = *stack;
	next = head->next;
	if (!head || !next)
		return (1);
	return (0);
}

static int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_idx;

	head = *stack;
	next = head->next;
	tmp_val = head->value;
	tmp_idx = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_idx;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (validate(stack_a))
		return (-1);
	swap(stack_a);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (validate(stack_b))
		return (-1);
	swap(stack_b);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (validate(stack_a) || validate(stack_b))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return (0);
}
