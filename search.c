/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:34:12 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:13:40 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_list **stack, int idx)
{
	t_list	*head;
	int		distance;

	head = *stack;
	distance = 0;
	while (head)
	{
		if (head->index == idx)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_min(t_list **stack)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < min)
			min = head->index;
	}
	return (min);
}

int	get_max(t_list **stack)
{
	t_list	*head;
	int		max;

	head = *stack;
	max = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index > max)
			max = head->index;
	}
	return (max);
}

int	get_min_group(t_list **stack, int group)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next && head->next->group == group)
	{
		head = head->next;
		if (head->index < min)
			min = head->index;
	}
	return (min);
}

int	group_size(t_list *lst, int group)
{
	size_t	counter;

	counter = 0;
	while (lst && lst->group == group)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}
