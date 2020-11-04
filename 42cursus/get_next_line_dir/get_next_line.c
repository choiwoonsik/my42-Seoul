/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:47:12 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/07 15:33:47 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_last(char *page)
{
	int				i;

	i = 0;
	while (page[i] != '\0')
	{
		if (page[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		make_new_line(char **line, char **page, int fd, int check_last)
{
	int		n;
	char	*tmp;

	page[fd][check_last] = '\0';
	*line = ft_strdup(page[fd]);
	n = ft_strlen(page[fd] + check_last + 1);
	if (n == 0)
	{
		free(page[fd]);
		page[fd] = NULL;
		return (1);
	}
	tmp = ft_strdup(page[fd] + check_last + 1);
	free(page[fd]);
	page[fd] = tmp;
	return (1);
}

int		ret_func(int fd, char **page, char **line, int check_last)
{
	int		pos;

	if (check_last < 0)
		return (-1);
	if (page[fd] && (pos = get_last(page[fd])) >= 0)
		return (make_new_line(line, page, fd, pos));
	else if (page[fd])
	{
		*line = page[fd];
		page[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*page[4096];
	char			buf[BUFFER_SIZE + 1];
	int				check_last;
	int				pos;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((check_last = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[check_last] = '\0';
		page[fd] = ft_strjoin(page[fd], buf);
		if ((pos = get_last(page[fd])) >= 0)
			return (make_new_line(line, page, fd, pos));
	}
	return (ret_func(fd, page, line, check_last));
}

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("text", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
}