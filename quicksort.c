/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:44 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/23 12:51:19 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_pushswap *ps)
{
	int i;
	int n;
	int j;
	int d1;
	int d2;

	i = 0;
	n = 0;
	j = 0;
	while (ps->stack_a[n])
		n++;
	reverse_rotate_a(ps);
	push_b(ps);
	while (i < (n - 1))
	{
		d1 = ft_atoi(ps->stack_a[0]);
		d2 = ft_atoi(ps->stack_b[j]);
		if (d1 < d2)
		{
			push_b(ps);
			j++;
		}
		rotate_a(ps);
		i++;
	}
	while (j >= 0)
	{
		reverse_rotate_b(ps);
		push_a(ps);
		j--;
	}
	if (check_order(ps) == 1)
		quick_sort(ps);	
}