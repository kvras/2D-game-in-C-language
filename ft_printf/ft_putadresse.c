/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:30 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/03 03:40:12 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
