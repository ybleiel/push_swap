/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigbigsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:58:10 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/28 13:54:30 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_bit(int d1, int a)
{
	printf("%d\n", a);
	if ((d1 & a) == a)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	big_big_sort(t_pushswap *ps)
{
	int i;
	int d1;
	int a;
	int n;

	i = 0;
	a = 1;
	n = 0;
	while (a <= 4)
	{
		
		while (ps->stack_a[i])
		{
			d1 = ft_atoi(ps->stack_a[0]);
			if (search_bit(d1, a) == 0)
			{
				push_b(ps);
				i = 0;
			}
			else
			{
				reverse_rotate_a(ps);
			}
			i++;
		}
		print_stacks(ps);
		while (ps->stack_b[0])
		{
			push_a(ps);
		}
		a = a << 1;
		i = 0;
	}
}