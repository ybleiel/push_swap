/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:46:54 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/23 12:34:45 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int search_snr(t_pushswap *ps)
// {
// 	int i;
// 	int a;
// 	int d1;
// 	int d2;

// 	i = 0;
// 	a = 0;
// 	while (ps->stack_a[a])
// 	{
// 		d1 = ft_atoi(ps->stack_a[i]);
// 		d2 = ft_atoi(ps->stack_a[a]);
// 		if (d1 > d2)
// 		{
// 			i++;
// 			a = 0;
// 		}
// 		a++;
// 	}
// 	return (i);
// }

// int search_bnr(t_pushswap *ps)
// {
// 	int i;
// 	int a;
// 	int d1;
// 	int d2;

// 	i = 0;
// 	a = 0;
// 	while (ps->stack_b[a])
// 	{
// 		d1 = ft_atoi(ps->stack_b[i]);
// 		d2 = ft_atoi(ps->stack_b[a]);
// 		if (d1 < d2)
// 		{
// 			i++;
// 			a = 0;
// 		}
// 		a++;
// 	}
// 	return (i);
// }

// int	search_bighalf(t_pushswap *ps, int d1)
// {
// 	int i;
// 	int n;
// 	int a;
// 	int d2;

// 	i = 0;
// 	n = 0;
// 	a = 0;
// 	while (ps->stack_a[n])
// 		n++;
// 	while (ps->stack_a[i])
// 	{
// 		d2 = ft_atoi(ps->stack_a[i]);
// 		if (d1 > d2 && d1 != d2)
// 			a++;
// 		i++;
// 	}
// 	if (a >= (n / 2))
// 		return (0);
// 	else
// 		return (1);
// }

// void big_sort1(t_pushswap *ps)
// {
// 	int i;
// 	int n;
// 	int a;
// 	int nra;
// 	int nrb;

// 	i = 1;
// 	n = 0;
// 	a = 0;
// 	nra = search_snr(ps);
// 	nrb = search_bnr(ps);
// 	while (ps->stack_a[n])
// 		n++;
// 	while (ps->stack_b[a])
// 		a++;
// 	while (nra != 0)
// 	{
// 		while (nra > (n / 2) && nrb > (a / 2) && nra != 0 && nrb != 0)
// 			reverse_rotate_rotate(ps);
// 		if (nra > (n / 2))
// 			reverse_rotate_a(ps);
// 		// if (nra <= (n / 2) && nrb <= (a / 2) && nrb != 0)
// 		// 	rotate_rotate(ps);
// 		if (nra <= (n / 2))
// 			rotate_a(ps);
// 		nra = search_snr(ps);
// 		nrb = search_bnr(ps);
// 	}
// 	push_b(ps);
// }

// void big_sort2(t_pushswap *ps)
// {
// 	int i;
// 	int n;
// 	int nr;

// 	i = 1;
// 	n = 0;
// 	nr = search_bnr(ps);
// 	while (ps->stack_b[n])
// 		n++;
// 	while (nr != 0)
// 	{
// 		if (nr > (n / 2))
// 			reverse_rotate_b(ps);
// 		if (nr <= (n / 2))
// 			rotate_b(ps);
// 		nr = search_bnr(ps);
// 	}
// 	push_a(ps);
// }

// void big_sort(t_pushswap *ps)
// {
// 	int i;
// 	int n;
// 	int a;
// 	int d1;

// 	i = 0;
// 	n = 0;
// 	while (ps->stack_a[n])
// 		n++;
// 	a = n / 2;
// 	while (n > a)
// 	{
// 		d1 = ft_atoi(ps->stack_a[i]);
// 		if (search_bighalf(ps, d1) == 0)
// 		{
// 			push_b(ps);
// 			n--;
// 		}
// 		rotate_a(ps);
// 	}
	// while (ps->stack_a[i])
	// {
	// 	big_sort1(ps);
	// }
	// while (ps->stack_b[i])
	// {
	// 	big_sort2(ps);
	// }
// }