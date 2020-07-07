/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:44:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/05/29 23:02:14 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}
