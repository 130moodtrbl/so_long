/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:50:02 by speters           #+#    #+#             */
/*   Updated: 2025/03/18 13:08:12 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar(45);
		n = -nb;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

int	print_int(int n)
{
	int				nb;
	unsigned int	res;

	nb = n;
	res = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		res++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		res++;
	}
	ft_putnbr(n);
	if (n == -2147483648)
		return (11);
	return (res);
}

int	uns_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*uns_itoa(unsigned int n)
{
	char	*nb;
	int		len;

	len = uns_len(n);
	nb = (char *)malloc(sizeof(char) *(len + 1));
	if (!nb)
	{
		return (0);
	}
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nb);
}

int	print_uns(unsigned int n)
{
	char	*nb;
	int		len;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	else
	{
		nb = uns_itoa(n);
		len = print_str(nb);
		free(nb);
	}
	return (len);
}
