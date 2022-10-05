/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquesada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:48 by aquesada          #+#    #+#             */
/*   Updated: 2022/02/02 18:53:58 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_separate_b(char **readbuffer, int i)
{
	char	*line;
	char	*tempbuf;

	line = ft_substr(*readbuffer, 0, i);
	tempbuf = ft_strdup((*readbuffer) + i + 1);
	free (*readbuffer);
	*readbuffer = tempbuf;
	if ((*readbuffer)[0] == '\0')
	{
		free (tempbuf);
		*readbuffer = NULL;
	}
	return (line);
}

static char	*ft_rearrange_b(char *buff, char **readbuffer, ssize_t read_bytes)
{
	char	*tempbuf;
	char	*ret;
	int		i;

	if (*readbuffer == NULL)
		*readbuffer = ft_strdup(buff);
	else if (read_bytes != 0)
	{
		tempbuf = ft_strdup(*readbuffer);
		free (*readbuffer);
		*readbuffer = ft_strjoin(tempbuf, buff);
		free (tempbuf);
	}
	i = 0;
	while ((*readbuffer)[i] != '\n' && (*readbuffer)[i] != '\0')
		i++;
	if ((*readbuffer)[i] == '\n')
	{
		ret = ft_separate_b(readbuffer, i);
		if (ret)
			return (ret);
	}
	return (NULL);
}

static char	*ft_check_ifn(char **readbuffer)
{
	int		i;
	char	*line;
	char	*rest;

	i = 0;
	while ((*readbuffer)[i] != '\n' && (*readbuffer)[i] != '\0')
		i++;
	if ((*readbuffer)[0] == '\0')
	{
		free (*readbuffer);
		*readbuffer = NULL;
	}
	else if ((*readbuffer)[i] == '\n')
	{
		line = ft_substr(*readbuffer, 0, i);
		rest = ft_strdup((*readbuffer) + i + 1);
		free (*readbuffer);
		*readbuffer = rest;
		return (line);
	}
	return (NULL);
}

static int	ft_init_read(int fd, char *buff, char **readbuffer)
{
	int	read_bytes;

	if (BUFFER_SIZE < 1)
		return (-1);
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes == -1)
		return (read_bytes);
	(buff)[read_bytes] = '\0';
	if ((buff)[0] == '\0' && *readbuffer == NULL)
		read_bytes = -1;
	return (read_bytes);
}

char	*ft_eof(char **line, char **buf)
{
	*line = *buf;
	*buf = NULL;
	return (*line);
}


char	*get_next_line(int fd)
{
	static char		*readbuffer[10240];
	char			buff[BUFFER_SIZE + 1];
	char			*line;
	ssize_t			read_bytes;

	while (1)
	{
		if (readbuffer[fd])
		{
			line = ft_check_ifn(&readbuffer[fd]);
			if (line != NULL)
				return (line);
		}
		read_bytes = ft_init_read(fd, buff, &readbuffer[fd]);
		if (read_bytes == -1 || fd < 0)
			return (NULL);
		line = ft_rearrange_b(buff, &readbuffer[fd], read_bytes);
		if (line != NULL)
			return (line);
		if (read_bytes == 0 && readbuffer[fd] != NULL)
			return (ft_eof(&line, &readbuffer[fd]));
	}
	return (NULL);
}