/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:48:25 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/18 12:55:01 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

void check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	check_order(t_pushswap *ps)
{
	int i;
	int a;
	int d1;
	int d2;

	i = 0;
	a = 1;
	while (ps->stack_a[a])
	{
		d1 = ft_atoi(ps->stack_a[i]);
		d2 = ft_atoi(ps->stack_a[a]);
		while (ps->stack_a[a])
		{
			d1 = ft_atoi(ps->stack_a[i]);
			d2 = ft_atoi(ps->stack_a[a]);
			if (d1 > d2)
				return (1);
			a++;
		}
		i++;
		a = i + 1;
	}
	return (0);
}

void	check_max(t_pushswap *ps)
{
	int i;
	int d1;

	i = 0;
	while (ps->stack_a[i])
	{
		d1 = ft_atoi(ps->stack_a[i]);
		if (d1 > 2147483647 || d1 < -2147483648)
			exit(1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned int		j;
	int					m;

	i = 0;
	j = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if ((j > 2147483648 && m == -1) || (j > 2147483647 && m == 1))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (j * m);
}

// long	ft_atoi(const char *nptr)
// {
// 	int		counter;
// 	long	number;
// 	int		sign;

// 	number = 0;
// 	sign = 1;
// 	counter = 0;
// 	if (nptr[counter] == '+' || nptr[counter] == '-')
// 	{
// 		if (nptr[counter] == '-')
// 			sign = -1;
// 		counter ++;
// 	}
// 	while (ft_isdigit(nptr[counter]) != 0 && number < 2147483648)
// 	{
// 		number = number * 10 + (nptr[counter] - '0');
// 		counter ++;
// 	}
// 	return ((number * sign));
// }

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

void	push_back(t_pushswap *ps)
{
	int i;
	int d1;
	int d2;

	i = 0;
	d1 = ft_atoi(ps->stack_b[0]);
	d2 = ft_atoi(ps->stack_b[1]);
	if (d2 > d1)
		swap_b(ps);
	while (ps->stack_b[i])
	{
		push_a(ps);
		i++;
	}
}
