/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:20:02 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/08 14:37:43 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

int	stack_size(char **argv)
{
	int		i;
	int		j;
	int		d;
	char	*str;

	i = 0;
	j = 1;
	d = 0;
	while (argv[j])
	{
		str = argv[j];
		if (str[i++] != 0)
			d += ft_strlen(str);
		else
			d++;
		i = 0;
		j++;
	}
	return (d);
}

void	malloc_ps(t_pushswap *ps, char **argv)
{
	int	d;

	d = stack_size(argv);
	// printf("%d\n", sizeof(d));
	ps->stack_a = malloc(sizeof(char **) * d);
	ps->stack_b = malloc(sizeof(char **) * d);
	ps->index = malloc(sizeof(int *) * d);
}

void	free_ps(t_pushswap *ps)
{
	free(ps);
	free(ps->stack_a);
	free(ps->stack_b);
	free(index);
	exit(0);
}

void	main_sort(t_pushswap *ps, int j)
{
	check_duplicate(ps);
	if (check_order(ps) == 0)
		exit(0);
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
	t_pushswap	*ps;
	int			j;
	int			n;
	char		*str;
	int			i;

	i = 0;
	j = 1;
	n = 0;
	if (argc <= 1)
		exit(0);
	ps = malloc(sizeof(t_pushswap));
	malloc_ps(ps, argv);
	while (argv[j])
	{
		check_digit(argv[j]);
		ps->stack_a[n] = malloc(ft_strlen(argv[j]));
		ps->stack_a[n] = argv[j];
		str = argv[j];
		i = str[i] + '0';
		n++;
		j++;
	}
	main_sort(ps, j);
	exit(0);
	free_ps(ps);
}
