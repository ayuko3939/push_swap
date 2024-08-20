/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:58:57 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 12:11:54 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	tmp = *stack;
	if (tmp)
	{
		while (tmp)
		{
			if ((tmp->index == -1) && (!has_min || tmp->value < min->value))
			{
				min = tmp;
				has_min = 1;
			}
			tmp = tmp->next;
		}
	}
	return (min);
}

static void	add_index(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = get_next_min(stack);
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = get_next_min(stack);
		i++;
	}
}

void	set_stack(t_list **stack, int ac, char **av)
{
	t_list	*new;
	char	**args;
	int		i;

	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (args == NULL)
		error_exit();
	i = 0;
	while (args[i])
	{
		new = ft_lstnew_ps(ft_atoi(args[i]));
		if (new)
			ft_lstadd_back(stack, new);
		i++;
	}
	add_index(stack);
	if (ac == 2)
		free_all(args);
}

t_list	**init_stack(void)
{
	t_list	**stack;

	stack = (t_list **)malloc(sizeof(t_list));
	if (stack == NULL)
		return (NULL);
	*stack = NULL;
	return (stack);
}
