/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:11:09 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/10 16:08:00 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_pushswap *ps)
{
	int	n;

	n = 0;
	if (!ps->stack_a[0] || !ps->stack_a[1])
		exit(0);
	while (ps->stack_a[n])
		n++;
	ps->stack_a[n] = ps->stack_a[0];
	ps->stack_a[0] = ps->stack_a[1];
	ps->stack_a[1] = ps->stack_a[n];
	ps->stack_a[n] = 0;
	write(1, "sa\n", 3);
}

void	swap_b(t_pushswap *ps)
{
	int n;

	n = 0;
	if (!ps->stack_b[0] || !ps->stack_b[1])
		exit(0);
	while (ps->stack_a[n])
		n++;
	ps->stack_b[n] = ps->stack_b[0];
	ps->stack_b[0] = ps->stack_b[1];
	ps->stack_b[1] = ps->stack_b[n];
	ps->stack_b[n] = 0;
	write(1, "sb\n", 3);
}

void	swap_swap(t_pushswap *ps)
{
	swap_a(ps);
	swap_b(ps);
	write(1, "ss\n", 3);
}
