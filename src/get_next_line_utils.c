/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:26:28 by miguiji           #+#    #+#             */
/*   Updated: 2024/03/19 21:06:46 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	void			*str2;

	i = 0;
	str2 = str;
	while (i < len)
	{
		*((char *)str2) = c;
		str2++;
		i++;
	}
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)dst;
	while (i < len)
	{
		*ptr = *((unsigned char *)src);
		i++;
		src++;
		ptr++;
	}
	return (dst);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(str);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = (char *)ft_memcpy(ptr, str, len);
	ptr[len] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (0);
	while (i < len && (str + start)[i])
	{
		ptr[i] = (str + start)[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
