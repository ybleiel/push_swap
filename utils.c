/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:48:25 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/22 14:12:23 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
		check_max(j, m);
	}
	return (j * m);
}

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

int	search_snr(t_pushswap *ps)
{
	int	i;
	int	a;
	int	d1;
	int	d2;

	i = 0;
	a = 0;
	while (ps->stack_a[a])
	{
		d1 = ft_atoi(ps->stack_a[i]);
		d2 = ft_atoi(ps->stack_a[a]);
		if (d1 > d2)
		{
			i++;
			a = 0;
		}
		a++;
	}
	return (i);
}

int	count_elements(t_pushswap *ps)
{
	int	i;

	i = 0;
	while (ps->stack_a[i])
		i++;
	return (i);
}

void	push_stackb(t_pushswap *ps)
{
	while (ps->stack_b[0])
		push_a(ps);
}
