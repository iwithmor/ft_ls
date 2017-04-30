/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:12:34 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/09 23:12:37 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char		*gnl_strdup(const char *s1)
{
	char	*result;

	if (!s1)
		return (NULL);
	result = (char *)malloc(ft_strlen((const char *)s1) + 1);
	if (!result)
		return (NULL);
	return (ft_strcpy(result, s1));
}

static char	*buf_concat(char *s1, char *s2)
{
	char	*res;
	int		s1len;
	int		s2len;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	s1len = ft_strlen((const char *)s1);
	s2len = ft_strlen((const char *)s2);
	res = (char *)malloc(s1len + s2len + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(&res[s1len], s2);
	res[s1len + s2len] = '\0';
	free(s1);
	return (res);
}

static int	read_file(const int fd, char **rest)
{
	char	buf[BUFF_SIZE + 1];
	int		bytesread;
	int		count;

	count = 0;
	*rest = gnl_strdup("");
	while ((bytesread = read(fd, buf, BUFF_SIZE)) > 0)
	{
		++count;
		buf[bytesread] = '\0';
		*rest = buf_concat(*rest, buf);
		if (BUFF_SIZE == 1 && *buf == '\n')
			break ;
	}
	if (bytesread < 0)
		return (-1);
	return (count);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	data;
	int				count;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	count = 0;
	if (fd != data.fd && (data.rest))
		bzero((void *)(data.rest), ft_strlen(data.rest));
	data.fd = fd;
	if (!(data.rest) || ft_strlen(data.rest) == 0)
	{
		if ((count = read_file(fd, &(data.rest))) < 1)
			return (count);
	}
	if ((tmp = ft_strchr(data.rest, '\n')))
		*line = ft_strsub(data.rest, 0, tmp++ - (data.rest));
	else
		*line = gnl_strdup((const char *)(data.rest));
	if (tmp)
		data.rest = ft_strncpy(data.rest, tmp, ft_strlen(data.rest));
	else
		bzero((void *)(data.rest), ft_strlen(data.rest));
	return (1);
}
