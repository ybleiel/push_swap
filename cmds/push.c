/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:15:51 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/10 16:06:32 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_pushswap *ps)
{
	int	n;

	n = 0;
	if (!ps->stack_a)
		exit(0);
	while (ps->stack_b[n])
		n++;
	while (n >= 0)
	{
		ps->stack_b[n] = ps->stack_b[n - 1];
		n--;
	}
	n = 0;
	ps->stack_b[0] = ps->stack_a[0];
	while (ps->stack_a[n])
	{
		ps->stack_a[n] = ps->stack_a[n + 1];
		n++;
	}
	write(1, "pb\n", 3);
}

void	push_a(t_pushswap *ps)
{
	int	n;

	n = 0;
	if (!ps->stack_b)
		exit(0);
	while (ps->stack_a[n])
		n++;
	while (n >= 0)
	{
		ps->stack_a[n] = ps->stack_a[n - 1];
		n--;
	}
	n = 0;
	ps->stack_a[0] = ps->stack_b[0];
	while (ps->stack_b[n])
	{
		ps->stack_b[n] = ps->stack_b[n + 1];
		n++;
	}
	write(1, "pa\n", 3);
}
