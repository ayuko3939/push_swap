/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operat_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:12:30 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:40:30 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*head_to;
	t_list	*head_from;
	t_list	*tmp;

	if (*stack_from == NULL)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (head_to)
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	else
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
