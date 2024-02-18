/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:36:51 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/18 17:45:33 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char *original, char c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_itoa(int nbr);
#endif