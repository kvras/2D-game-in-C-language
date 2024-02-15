/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:30 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/03 03:46:26 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunsigned(unsigned int nbr, int *len, int *erreur)
{
	if (nbr > 9)
	{
		ft_putunsigned(nbr / 10, len, erreur);
		ft_putunsigned(nbr % 10, len, erreur);
	}
	else
	{
		if (*erreur == -1)
			return ;
		ft_putchar(nbr + 48, len, erreur);
	}
}
