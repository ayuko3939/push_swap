/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:45:46 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/17 15:06:07 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check number or not except for space and one '-' or '+'
static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// check '0' and '0'  or  '100' and '+100'
static int	check_dup(int nm, char **av, int i)
{
	i += 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == nm)
			return (1);
		i++;
	}
	return (0);
}

static char	**set_args(int ac, char **av)
{
	char	**args;

	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (args == NULL)
		return (NULL);
	return (args);
}

// 0:uavailable  1:available
static int	is_available(char **args, char *str, int i)
{
	long	nm;

	if (!is_num(str))
		return (0);
	nm = ft_strtol(str);
	if (nm < INT_MIN || nm > INT_MAX)
		return (0);
	if (check_dup(nm, args, i))
		return (0);
	return (1);
}

void	check_args(int ac, char **av)
{
	char	**args;
	int		i;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	args = set_args(ac, av);
	if (args == NULL)
		error_exit();
	i = 0;
	while (args[i])
	{
		if (!is_available(args, args[i], i))
			break ;
		i++;
	}
	if (args[i])
	{
		if (ac == 2)
			free_all(args);
		error_exit();
	}
	if (ac == 2)
		free_all(args);
}
