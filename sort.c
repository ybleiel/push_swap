/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:31 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/18 16:28:44 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int search_snr(t_pushswap *ps)
{
	int i;
	int a;
	int d1;
	int d2;

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

void push_half(t_pushswap *ps)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (ps->stack_a[n])
		n++;
	while (i < (n / 2))
	{
		push_b(ps);
		i++;
	}
}

void	big_sort(t_pushswap *ps)
{
	int i;
	int n;
	int nra;

	i = 1;
	n = 0;
	while (ps->stack_a[n])
		n++;
	nra = search_snr(ps);
	while (nra != 0)
	{
		if (nra > (n / 2))
			reverse_rotate_a(ps);
		if (nra <= (n / 2) && nra != 1)
			rotate_a(ps);
		if (nra == 1)
			swap_a(ps);
		nra = search_snr(ps);
	}
	i = 0;
	if (n > 0)
	{
		push_b(ps);
		big_sort(ps);
	}
	while (ps->stack_b[i])
		i++;
	i = i / 2;
	while (i < 0)
	{
		push_a(ps);
		i--;
	}
}

void	big_sort2(t_pushswap *ps)
{
	int i;
	int n;
	int nr;

	i = 1;
	n = 0;
	nr = search_snr(ps);
	while (ps->stack_a[n])
		n++;
	while (nr != 0)
	{
		if (nr > (n / 2))
			reverse_rotate_a(ps);
		if (nr <= (n / 2) && nr != 1)
			rotate_a(ps);
		if (nr == 1)
			swap_a(ps);
		nr = search_snr(ps);
	}
	i = 0;
	if (n > 0)
	{
		push_b(ps);
		big_sort(ps);
	}
	while (ps->stack_b[i])
	{
		push_a(ps);
		i++;
	}
}

void	old_big_sort(t_pushswap *ps)
{
	int i;
	int n;
	int d1;
	int d2;

	i = 1;
	n = 0;
	while (ps->stack_a[n])
		n++;
	while (ps->stack_a[i])
	{
		d1 = ft_atoi(ps->stack_a[0]);
		d2 = ft_atoi(ps->stack_a[i]);
		if (d1 > d2)
		{
			rotate_a(ps);
			i = 0;
		}
		i++;
	}
	i = 0;
	if (n > 0)
	{
		push_b(ps);
		big_sort(ps);
	}
	while (ps->stack_b[i])
	{
		push_a(ps);
		i++;
	}
}

void small_small_sort(t_pushswap *ps)
{
	int i;
	int d1;
	int d2;
	int d3;
	
	i = 0;
	while (ps->stack_a[i])
	{
		d1 = ft_atoi(ps->stack_a[0]);
		d2 = ft_atoi(ps->stack_a[1]);
		d3 = ft_atoi(ps->stack_a[2]);
		if (d1 > d2 && d1 > d3)
		{
			rotate_a(ps);
			if (d1 > d2)
				swap_a(ps);
		}
		if (d1 > d2 && d1 < d3)
			swap_a(ps);
		if (d1 < d2 && d1 < d3 && d2 > d3)
		{
			push_b(ps);
			swap_a(ps);
			push_a(ps);
		}
		if (d1 < d2 && d1 > d3)
			reverse_rotate_a(ps);
		i++;
	}
}

void	small_sort(t_pushswap *ps)
{
	int i;
	int n;
	int d1;
	int d2;

	i = 1;
	n = 0;
	while (ps->stack_a[n])
		n++;
	while (ps->stack_a[i])
	{
		d1 = ft_atoi(ps->stack_a[0]);
		d2 = ft_atoi(ps->stack_a[i]);
		if (d1 > d2)
		{
			rotate_a(ps);
			i = 0;
		}
		i++;
	}
	if (n > 3)
	{
		push_b(ps);
		small_sort(ps);
		if (ps->stack_b[1])
		{
			push_a(ps);
			push_a(ps);
		}
		else if (ps->stack_b[0])
			push_a(ps);
	}
	small_small_sort(ps);
}

void	two_sort(t_pushswap *ps)
{
	int d1;
	int d2;

	d1 = ft_atoi(ps->stack_a[0]);
	d2 = ft_atoi(ps->stack_a[1]);
	if (d1 > d2)
		swap_a(ps);
}
