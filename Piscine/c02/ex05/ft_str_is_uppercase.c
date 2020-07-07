/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 14:08:08 by wchoi             #+#    #+#             */
/*   Updated: 2020/05/31 14:25:44 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_uppercase(char *str)
{
	int		n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if ((*(str + n) > 'Z') || (*(str + n) < 'A'))
			return (0);
		n++;
	}
	return (1);
}
