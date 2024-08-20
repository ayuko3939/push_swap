/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:12:30 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:42:10 by yohasega         ###   ########.fr       */
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

static int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (validate(stack_a))
		return (-1);
	rotate(stack_a);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (validate(stack_b))
		return (-1);
	rotate(stack_b);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (validate(stack_a) || validate(stack_b))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (0);
}
