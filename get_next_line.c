/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:30:09 by med-doba          #+#    #+#             */
/*   Updated: 2021/12/28 16:37:30 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endline(char *str)
{
	int i;
	
	i = 0;
	
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;		
	}
	return (-1);
}

char	*sendline(char *akm)
{
	char	*ptr;
	int		index;

	index = endline(akm);
	if(index != -1)
	{
		ptr = malloc(sizeof(char) * (index + 2));
		if (!ptr)
			return (NULL);
		ft_memcpy(ptr, akm, index);
		ptr[index] = '\n';
		ptr[index + 1] = '\0';
	}
	else if(*akm != '\0' && index == -1)
	{
		ptr = ft_strdup(akm);
		free(akm);
	}
	else
		return (free(akm),NULL);
	return (ptr);
}

char *update(char *str)
{
	int	i;
	char *rtn;
	
	rtn = NULL;
	i = endline(str);
	if (i != -1)
	{
		rtn = ft_strdup(str + i + 1);
		free(str);
		str = rtn;
	}
	else if (i == -1 && *str != '\0')
		return (NULL);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char	*rtn;
	char	*tab;
	static char	*ptr = NULL;
	int	n;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab = malloc(BUFFER_SIZE + 1);
	if (!tab)
		return (free(tab), NULL);
	n = 1;
	while (endline(ptr) == -1 && n != 0)
	{
		n = read(fd, tab, BUFFER_SIZE);
		if (n == -1)
		{
			free(ptr);
			free(tab);
			return (NULL);
		}
		tab[n] = '\0';
		ptr = ft_strjoin(ptr, tab);
	}
	free(tab);
	rtn = sendline(ptr);
	ptr = update(ptr);
	return (rtn);
}

// int main ()
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
	
// }
