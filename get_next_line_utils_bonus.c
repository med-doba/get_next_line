/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:17:08 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/28 01:19:02 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	char			*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (char *)dst;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (n == 0)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	size_t			l;
	size_t			i;
	int				j;

	j = 0;
	i = -1;
	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	l = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(l + 1);
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j])
	{
		ptr[i] = s2[j++];
		i++;
	}
	ptr[i] = '\0';
	return (free(s1), ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s1);
	ptr = malloc(n + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, n);
	ptr[n] = '\0';
	return (ptr);
}
