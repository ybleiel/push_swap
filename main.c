/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:20:02 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/18 16:22:18 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

int malloc_stack(char **argv)
{
	int i;
	int j;
	int d;
	char *str;

	i = 0;
	j = 1;
	if (!argv[j])
		d = 0;
	while (argv[j])
	{
		str = argv[j];
		if (str[i++] != 0)
			d += strlen(str);
		else
			d++;
		i = 0;
		j++;
	}
	return (d);
}

void check_duplicate(t_pushswap *ps)
{
	int i;
	int n;
	int d1;
	int d2;

	i = 0;
	n = 0;
	while (ps->stack_a[i])
	{
		while (ps->stack_a[n])
		{
			if (n == i)
				n++;
			d1 = ft_atoi(ps->stack_a[n]);
			d2 = ft_atoi(ps->stack_a[i]);
			if (d1 == d2)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			n++;
		}
		i++;
	}
}

void print_stacks(t_pushswap *ps)
{
	int n;
	
	n = 0;
	while (n < 13)
	{
		printf("%s %s\n", ps->stack_a[n], ps->stack_b[n]);
		n++;
	}
	printf("_ _\n");
	printf("a b\n");
	printf("-------------\n");
}

int main(int argc, char **argv)
{
	t_pushswap *ps;
	int j;
	int n;
	int d;
	char *str;
	int i;
	int a;

	i = 0;
	j = 1;
	n = 0;
	if (argc <= 1)
		exit(1);
	d = malloc_stack(argv);
	ps = malloc(sizeof(t_pushswap));
	ps->stack_a = malloc(d);
	ps->stack_b = malloc(d);
	while (argv[j])
	{
		check_digit(argv[j]);
		ps->stack_a[n] = malloc(ft_strlen(argv[j]));
		ps->stack_a[n] = argv[j];
		str = argv[j];
		if (str[i++] != 0)
			a += strlen(str);
		else
			a = str[i] + '0';
		i++;
		n++;
		j++;
	}
	check_duplicate(ps);
	if (check_order(ps) == 0)
		exit(0);
	print_stacks(ps);
	if (j == 3)
		two_sort(ps);
	if (j <= 4)
		small_small_sort(ps);
	else if (j >= 5 && j <= 6)
		small_sort(ps);
	else
	{
		push_half(ps);
		big_sort(ps);
	}
	print_stacks(ps);
	free(ps);
}
