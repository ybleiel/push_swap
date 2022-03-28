/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:22:34 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/19 15:59:03 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_pushswap *ps)
{
	int	n;
	int	i;

	n = 0;
	while (ps->stack_a[n])
		n++;
	ps->stack_a[n] = ps->stack_a[n - 1];
	i = n - 1;
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = ps->stack_a[n];
	ps->stack_a[n] = 0;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_pushswap *ps)
{
	int	n;
	int	i;

	n = 0;
	while (ps->stack_b[n])
		n++;
	ps->stack_b[n] = ps->stack_b[n - 1];
	i = n - 1;
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = ps->stack_b[n];
	ps->stack_b[n] = 0;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_rotate(t_pushswap *ps)
{
	reverse_rotate_a(ps);
	reverse_rotate_b(ps);
	write(1, "rrr\n", 4);
}
