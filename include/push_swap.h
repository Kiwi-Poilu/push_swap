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

typedef struct	s_stack
{
	int *a;
	int	*b;
}				t_stack;

//main.c
int	is_number(char *nb);
int	ft_putstr(char *str);


//sort.c
void	three(int *a);
void	five(int *a, int *b);
void	fill_stack(int ac, const int *t, int *a);
void sort_a(t_stack *stack, int low, int high, int stack_size);
void sort_b(t_stack	*stack, int low, int high, int stack_size);

//operations.c
void move_push(int *a, int *b, int stack_size);
void move_rotate(int *stack,int stack_size);
void move_reverse_rotate(int *stack, int stack_size);
void move_swap(int *stack);

void run_pa(int *a, int *b, int stack_size);
void run_pb(int *a, int *b, int stack_size);
void run_ra(int *a, int stack_size);
void run_rb(int *b, int stack_size);
void run_rra(int *a, int stack_size);
void run_rrb(int *b, int stack_size);
void run_sa(int *a);
void run_sb(int *b);

//get_infos.c
int get_highest(const int *stack);
int check_empty_stack(const int *stack, int stack_size);
int	contain_greater_equal(const int *stack, int mid, int stack_size);
int contain_lower(const int *stack, int mid, int stack_size);
int get_stack_size(const int *stack);
int is_sorted(const int *stack, int stack_size);

//get_infos2.c
int	get_highest2(const int *stack, int stack_size);

//utils.c
int		check_nb(char **av);
int		check_dup(int *stack, int stack_size);

//utils2.c
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int ft_isspace(int c);
int ft_isupper(int c);
void	*ft_memset(void *b, int c, size_t len);

//ft_strtol.c
int ft_strtol(const char *nptr);

int	find_target(int *a, int b);
void	rotate_for_target(int *a, int target);

//compensate.c
void compensate_ra(int *a, int stack_size, int r_count);
void compensate_rra(int *a, int stack_size, int r_count);
void compensate_rb(int *b, int stack_size, int r_count);
void compensate_rrb(int *b, int stack_size, int r_count);

#endif
