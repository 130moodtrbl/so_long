/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:50:22 by speters           #+#    #+#             */
/*   Updated: 2025/03/18 13:02:18 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	hexa_conv(unsigned int nb, const char type)
{
	if (nb >= 16)
	{
		hexa_conv(nb / 16, type);
		hexa_conv(nb % 16, type);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			if (type == 'x')
				ft_putchar(nb - 10 + 'a');
			if (type == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
}

int	print_hexa(unsigned int nb, const char type)
{
	if (nb == 0)
		ft_putchar('0');
	else
	{
		hexa_conv(nb, type);
	}
	return (hexa_len(nb));
}
