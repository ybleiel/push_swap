/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:45:00 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/05 16:46:35 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

void	check_digit(char *str)
{
	int	i;

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
	int	i;
	int	a;
	int	d1;
	int	d2;

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

void	check_duplicate(t_pushswap *ps)
{
	int	i;
	int	n;
	int	d1;
	int	d2;

	i = 0;
	n = 0;
	while (ps->stack_a[i])
	{
		while (ps->stack_a[n])
		{
			if (n == i)
				n++;
			d1 = ft_atoi(ps->stack_a[n]);
			d2 = ft_atoi(ps->stack_a[i]);
			if (d1 == d2)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			n++;
		}
		i++;
	}
}

void	check_max(unsigned int j, int m)
{
	if ((j > 2147483648 && m == -1) || (j > 2147483647 && m == 1))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}
