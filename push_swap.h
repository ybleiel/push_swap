/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:45:52 by ybleiel           #+#    #+#             */
/*   Updated: 2022/04/05 16:47:38 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pushswap{
	char	**stack_a;
	char	**stack_b;
	int		*index;
}	t_pushswap;

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
void	small_small_sort(t_pushswap *ps);
void	check_digit(char *str);
size_t	ft_strlen(const char *s);
void	small_sort(t_pushswap *ps);
void	push_back(t_pushswap *ps);
int		check_order(t_pushswap *ps);
void	two_sort(t_pushswap *ps);
void	check_max(unsigned int j, int m);
void	check_duplicate(t_pushswap *ps);
int		search_snr(t_pushswap *ps);
void	print_stacks(t_pushswap *ps);
void	big_sort(t_pushswap *ps);
void	index_sort(t_pushswap *ps);
void	push_stackb(t_pushswap *ps);
int		count_elements(t_pushswap *ps);

#endif