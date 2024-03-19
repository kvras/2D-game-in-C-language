/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:21 by miguiji           #+#    #+#             */
/*   Updated: 2024/03/19 21:06:46 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_putstr(char *string, int *len, int *erreur)
{
	if (string == NULL)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (*string)
	{
		if (*erreur == -1)
			return ;
		ft_putchar(*string, len, erreur);
		string++;
	}
}
