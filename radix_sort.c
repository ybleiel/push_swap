/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:58:10 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/05 16:46:51 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_bit(int d1, int a)
{
	if ((d1 & a) == a)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	find_indexnr(t_pushswap *ps, int nr, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		if (ps->index[i] == nr)
			break ;
		i++;
	}
	return (i);
}

static int	max_bits(t_pushswap *ps)
{
	int	i;
	int	max_bits;

	i = 0;
	max_bits = 1;
	while (ps->stack_a[i])
		i++;
	while (i != 0)
	{
		max_bits <<= 1;
		i >>= 1;
	}
	return (max_bits);
}

void	big_sort(t_pushswap *ps)
{
	int	i;
	int	d1;
	int	a;
	int	n;
	int	mb;

	i = 0;
	a = 1;
	mb = max_bits(ps);
	n = count_elements(ps);
	while (a < mb)
	{
		while (i < n)
		{
			d1 = find_indexnr(ps, ft_atoi(ps->stack_a[0]), n);
			if (search_bit(d1, a) == 0)
				push_b(ps);
			else
				rotate_a(ps);
			i++;
		}
		push_stackb(ps);
		a = a << 1;
		i = 0;
	}
}
