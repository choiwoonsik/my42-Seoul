/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:10:39 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/02 18:47:14 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int		n;
	int		k;

	n = 0;
	while (*(dest + n) != '\0')
	{
		n++;
	}
	k = n;
	n = 0;
	while (*(src + n) != '\0')
	{
		*(dest + k++) = *(src + n++);
	}
	*(dest + k) = '\0';
	return (dest);
}
