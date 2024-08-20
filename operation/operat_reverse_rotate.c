/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operat_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:12:30 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:42:50 by yohasega         ###   ########.fr       */
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

static int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
			break ;
		head = head->next;
	}
	head->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (validate(stack_a))
		return (-1);
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (validate(stack_b))
		return (-1);
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (validate(stack_a) || validate(stack_b))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}
