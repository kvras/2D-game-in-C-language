/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:30 by miguiji           #+#    #+#             */
/*   Updated: 2024/03/19 21:06:46 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_putadresse(void *ptr, int *len, int *erreur)
{
	ft_putchar('0', len, erreur);
	if (*erreur == -1)
		return ;
	ft_putchar('x', len, erreur);
	if (*erreur == -1)
		return ;
	ft_puthex((unsigned long long)ptr, 'x', len, erreur);
}
