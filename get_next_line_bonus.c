/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:16:01 by med-doba          #+#    #+#             */
/*   Updated: 2021/12/29 20:27:34 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	endline(char *ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*sendline(char *ptr)
{
	char	*rtn;
	int		index;

	index = endline(ptr);
	if (index != -1)
	{
		rtn = malloc(sizeof(char) * (index + 2));
		if (!rtn)
			return (NULL);
		ft_memcpy(rtn, ptr, index);
		rtn[index] = '\n';
		rtn[index + 1] = '\0';
	}
	else if (*ptr != '\0' && index == -1)
	{
		rtn = ft_strdup(ptr);
		free(ptr);
	}
	else
		return (free(ptr), NULL);
	return (rtn);
}

char	*update(char *ptr)
{
	int		i;
	char	*rtn;

	rtn = NULL;
	i = endline(ptr);
	if (i != -1)
	{
		rtn = ft_strdup(ptr + i + 1);
		free(ptr);
		ptr = rtn;
	}
	else if (i == -1 && *ptr != '\0')
		return (NULL);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	char		*tab;
	static char	*ptr[10240];
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab = malloc(BUFFER_SIZE + 1);
	if (!tab)
		return (free(tab), NULL);
	n = 1;
	while (endline(ptr[fd]) == -1 && n != 0)
	{
		n = read(fd, tab, BUFFER_SIZE);
		if (n == -1)
			return (free(ptr[fd]), free(tab), NULL);
		tab[n] = '\0';
		ptr[fd] = ft_strjoin(ptr[fd], tab);
	}
	free(tab);
	rtn = sendline(ptr[fd]);
	ptr[fd] = update(ptr[fd]);
	return (rtn);
}
