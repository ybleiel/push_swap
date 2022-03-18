/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:45:52 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/18 16:20:10 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_pushswap{
	char **stack_a;
	char **stack_b;
} t_pushswap;

void	swap_a(t_pushswap *ps);
void	swap_b(t_pushswap *ps);
void	swap_swap(t_pushswap *ps);
void	push_b(t_pushswap *ps);
void	push_a(t_pushswap *ps);
void	rotate_a(t_pushswap *ps);
void	rotate_b(t_pushswap *ps);
void	rotate_rotate(t_pushswap *ps);
void	reverse_rotate_a(t_pushswap *ps);
void	reverse_rotate_b(t_pushswap *ps);
void	reverse_rotate_rotate(t_pushswap *ps);
int		ft_atoi(const char *str);
void	big_sort(t_pushswap *ps);
void	small_small_sort(t_pushswap *ps);
void	check_digit(char *str);
size_t	ft_strlen(const char *s);
void	small_sort(t_pushswap *ps);
void	push_back(t_pushswap *ps);
int		check_order(t_pushswap *ps);
void	two_sort(t_pushswap *ps);
void	check_max(t_pushswap *ps);
int		search_snr(t_pushswap *ps);
void	push_half(t_pushswap *ps);


#endif