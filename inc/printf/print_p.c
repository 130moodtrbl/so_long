/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:49:43 by speters           #+#    #+#             */
/*   Updated: 2025/03/18 13:02:16 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

int	ptr_conv(unsigned long long nb)
{
	if (nb >= 16)
	{
		ptr_conv(nb / 16);
		ptr_conv(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
	return (nb);
}

int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		print_str("(nil)");
		return (5);
	}
	len += print_str("0x");
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ptr_conv(ptr);
		len += ptr_len(ptr);
	}
	return (len);
}

/*int	main(void)
{
	char slt[] = "wolfblood";
	print_ptr((unsigned long long)&slt);
}*/
