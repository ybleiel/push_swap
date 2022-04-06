/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:31 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/05 15:28:16 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_small_ifs(t_pushswap *ps, int d1, int d2, int d3)
{
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
}

void	small_small_sort(t_pushswap *ps)
{
	int	i;
	int	d1;
	int	d2;
	int	d3;

	i = 0;
	while (ps->stack_a[i])
	{
		d1 = ft_atoi(ps->stack_a[0]);
		d2 = ft_atoi(ps->stack_a[1]);
		d3 = ft_atoi(ps->stack_a[2]);
		small_small_ifs(ps, d1, d2, d3);
		i++;
	}
}

void	small_ifs(t_pushswap *ps)
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

void	small_sort(t_pushswap *ps)
{
	int	i;
	int	n;
	int	d1;
	int	d2;

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
		small_ifs(ps);
	small_small_sort(ps);
}

void	two_sort(t_pushswap *ps)
{
	int	d1;
	int	d2;

	d1 = ft_atoi(ps->stack_a[0]);
	d2 = ft_atoi(ps->stack_a[1]);
	if (d1 > d2)
		swap_a(ps);
}
