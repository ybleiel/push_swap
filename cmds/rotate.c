/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:17:53 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/10 16:07:37 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_pushswap *ps)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (ps->stack_a[n])
		n++;
	ps->stack_a[n] = ps->stack_a[0];
	while (ps->stack_a[i] && i < n)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[n - 1] = ps->stack_a[n];
	ps->stack_a[n] = 0;
	write(1, "ra\n", 3);
}

void	rotate_b(t_pushswap *ps)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (ps->stack_b[n])
		n++;
	ps->stack_b[n] = ps->stack_b[0];
	while (ps->stack_b[i] && i < n)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[n - 1] = ps->stack_b[n];
	ps->stack_b[n] = 0;
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_pushswap *ps)
{
	rotate_a(ps);
	rotate_b(ps);
	write(1, "rr\n", 3);
}
