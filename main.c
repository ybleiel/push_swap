/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:20:02 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/21 10:56:36 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void	malloc_ps(t_pushswap *ps, int argc)
{
	ps->stack_a = malloc(argc * sizeof(char *));
	ps->stack_a[argc - 1] = NULL;
	ps->stack_b = malloc(argc * sizeof(char *));
	ps->stack_b[argc - 1] = NULL;
	ps->index = malloc(argc * sizeof(int));
	ps->index[argc - 1] = 0;
}

void	free_ps(t_pushswap *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps->index);
	exit(0);
}

void	main_sort(t_pushswap *ps, int j)
{
	check_duplicate(ps);
	if (check_order(ps) == 0)
		free_ps(ps);
	index_sort(ps);
	if (j == 3)
		two_sort(ps);
	else if (j <= 4)
		small_small_sort(ps);
	else if (j >= 5 && j <= 6)
		small_sort(ps);
	else
		big_sort(ps);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;
	int			j;
	int			n;

	j = 1;
	n = 0;
	if (argc <= 1)
		return (0);
	malloc_ps(&ps, argc);
	while (argv[j])
	{
		check_digit(argv[j]);
		ps.stack_a[n] = argv[j];
		n++;
		j++;
	}
	main_sort(&ps, j);
	free_ps(&ps);
	return (0);
}
