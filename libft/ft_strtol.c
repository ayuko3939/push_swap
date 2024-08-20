/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:45:01 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/13 19:01:50 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strtol(const char *str)
{
	long	lnum;
	int		sign;

	lnum = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
	{
		if (lnum > LONG_MAX / 10 || (lnum == LONG_MAX / 10 && (*str
					- '0') > LONG_MAX % 10))
		{
			if (sign < 0)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		lnum = lnum * 10 + (*str - '0');
		str++;
	}
	return (lnum * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *nm = "9223372036854775807";

// 	printf("ft_strtol : %ld\n", ft_strtol(nm));
// 	return (0);
// }