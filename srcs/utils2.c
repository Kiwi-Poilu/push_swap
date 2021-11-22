/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:08:44 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/22 22:08:47 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\r'
		|| c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
