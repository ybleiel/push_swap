/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:50:33 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/21 11:10:31 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller_zero(t_pushswap *ps, int n, int d1, int d2)
{
	int	j;
	int test;

	j = 0;
	test = 0;
	while (ps->index[j])
	{
		if (d1 == ps->index[j] || (d1 > d2 && d2 > ps->index[n]))
		{
			return (1);
		}
		j++;
	}
	return (0);
}

int	bigger_zero(t_pushswap *ps, int n, int d1, int d2)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (ps->stack_a[len])
		len++;
	while (j < (len - 1))
	{
		if (d1 == ps->index[j] || (d1 > d2 && d2 > ps->index[n]))
		{
			return (1);
		}
		j++;
	}
	return (0);
}

int	search_nsnr(t_pushswap *ps, int n, int len)
{
	int	i;
	int	a;
	int	d1;
	int	d2;

	i = 0;
	a = 0;
	while (ps->stack_a[a] && n < (len - 1))
	{
		d1 = ft_atoi(ps->stack_a[i]);
		d2 = ft_atoi(ps->stack_a[a]);
		if (ps->index[n] >= 0 && bigger_zero(ps, n, d1, d2) == 1)
		{
			i++;
			a = 0;
		}
		else if (smaller_zero(ps, n, d1, d2) == 1)
		{
			i++;
			a = 0;
		}
		a++;
	}
	return (i);
}

void	index_sort(t_pushswap *ps)
{
	int	i;
	int	n;
	int	d1;

	i = 0;
	n = 0;
	d1 = search_snr(ps);
	while (ps->stack_a[n])
		n++;
	while (i < n)
	{
		ps->index[i] = ft_atoi(ps->stack_a[d1]);
		d1 = search_nsnr(ps, i, n);
		i++;
	}
}
