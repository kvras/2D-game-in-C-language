/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:41:08 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/03 03:41:08 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int nb, int *len, int *erreur)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", len, erreur);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-', len, erreur);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10, len, erreur);
			ft_putnbr(nb % 10, len, erreur);
		}
		else
		{
			if (*erreur == -1)
				return ;
			ft_putchar(nb + 48, len, erreur);
		}
	}
}
