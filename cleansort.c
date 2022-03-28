/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleansort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:20:10 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/28 12:00:32 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_smallhalf(t_pushswap *ps, int d1)
{
	int i;
	int n;
	int a;
	int d2;

	i = 1;
	n = 0;
	a = 0;
	while (ps->stack_a[n])
		n++;
	while (ps->stack_a[i])
	{
		d2 = ft_atoi(ps->stack_a[i]);
		if (d1 > d2)
		{
			a++;
		}
		i++;
	}
	if (a >= (n / 2))
		return (1);
	else
		return (0);
}

int search_nbnr(t_pushswap *ps)
{
	int i;
	int a;
	static int nr;
	int d1;
	int d2;

	i = 0;
	a = 0;
	while (ps->stack_b[a])
	{
		d1 = ft_atoi(ps->stack_b[i]);
		d2 = ft_atoi(ps->stack_b[a]);
		if (d1 < d2 && i != nr)
		{
			i++;
			a = 0;
		}
		a++;
	}
	nr = i;
	return (i);
}

void	sort_b(t_pushswap *ps)
{
	int n;
	int nr1;

	n = 0;
	nr1 = search_bnr(ps);
	while (ps->stack_b[n])
		n++;
	while (nr1 != 0)
	{
		if (nr1 > (n / 2))
			reverse_rotate_b(ps);
		if (nr1 <= (n / 2))
			rotate_b(ps);
		else if (nr1 == 1)
			swap_b(ps);
		nr1 = search_bnr(ps);
	}
	push_a(ps);
}

void	push_smallhalf(t_pushswap *ps)
{
	int n;
	int a;
	int d1;

	n = 0;
	while (ps->stack_a[n])
		n++;
	a = n / 2;
	while (n >= a && ps->stack_a[1])
	{
		d1 = ft_atoi(ps->stack_a[0]);
		if (search_smallhalf(ps, d1) == 0)
		{
			push_b(ps);
			n--;
			sort_b(ps);
		}
		reverse_rotate_a(ps);
	}
}

int search_bnr(t_pushswap *ps)
{
	int i;
	int a;
	int d1;
	int d2;

	i = 0;
	a = 0;
	while (ps->stack_b[a])
	{
		d1 = ft_atoi(ps->stack_b[i]);
		d2 = ft_atoi(ps->stack_b[a]);
		if (d1 < d2)
		{
			i++;
			a = 0;
		}
		a++;
	}
	return (i);
}

void big_sort2(t_pushswap *ps)
{
	int i;
	int n;
	int nr;

	i = 0;
	n = 0;
	nr = search_bnr(ps);
	while (ps->stack_b[n])
		n++;
	while (nr != 0)
	{
		if (nr > (n / 2))
			reverse_rotate_b(ps);
		if (nr <= (n / 2))
			rotate_b(ps);
		nr = search_bnr(ps);
	}
	push_a(ps);
}

void	big_sort(t_pushswap *ps)
{
	while (ps->stack_a[1])
	{
		push_smallhalf(ps);
		
		// print_stacks(ps);
	}
	while (ps->stack_b[0])
		big_sort2(ps);
}