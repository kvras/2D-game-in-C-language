/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:30 by miguiji           #+#    #+#             */
/*   Updated: 2024/03/19 21:06:46 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
