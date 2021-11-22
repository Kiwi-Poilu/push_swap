/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:44:05 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/11 21:44:06 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <sys/param.h>

//main.c
int	is_number(char *nb);
int	ft_putstr(char *str);
void sort_a(int *a, int *b, int low, int high, int stack_size);
void sort_b(int *a, int *b, int low, int high, int stack_size);
//operations.c
void move_PUSH(int *a, int *b, int stack_size);
void move_rotate(int *stack,int stack_size);
void    move_reverse_rotate(int *stack, int stack_size);

//get_infos.c
int get_highest(const int *stack, int stack_size);
int check_empty_stack(const int *stack, int stack_size);
int	contain_greater_equal(const int *stack, int mid, int stack_size);
int contain_lower(const int *stack, int mid, int stack_size);
int get_stack_size(const int *stack);
int is_sorted(const int *stack, int stack_size);

//utils.c
int		check_nb(char **av);
int		check_dup(int *stack, int stack_size);
int 	ft_atoi(char *str);

//utils2.c
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int ft_isspace(int c);
int ft_isupper(int c);

//ft_strtol.c
int ft_strtol(const char *nptr);

void display_stack(int *stack, int stack_size);

#endif
