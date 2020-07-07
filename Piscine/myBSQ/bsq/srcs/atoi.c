/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skweon <skweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:14:55 by skweon            #+#    #+#             */
/*   Updated: 2020/06/18 02:22:27 by skweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		ft_atoi(char *str)
{
	int	sign;
	int	atoi;
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? -sign : sign;
		i++;
	}
	atoi = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		atoi = atoi * 10 + (str[i] - '0');
		i++;
	}
	atoi = (sign == 1) ? atoi : -atoi;
	return (atoi);
}
