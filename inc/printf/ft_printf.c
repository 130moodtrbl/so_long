/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:49:16 by speters           #+#    #+#             */
/*   Updated: 2025/03/18 13:14:07 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	id_type(const char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (print_str(va_arg(args, char *)));
	else if (type == 'p')
		return (print_ptr(va_arg(args, unsigned long long)));
	else if (type == 'i' || type == 'd')
		return (print_int(va_arg(args, int)));
	else if (type == 'u')
		return (print_uns(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (print_hexa(va_arg(args, unsigned int), type));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		total_char;

	va_start(args, s);
	total_char = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			total_char += id_type(s[i + 1], args);
			i++;
		}
		else
		{
			total_char += ft_putchar(s[i]);
		}
	i++;
	}
	va_end(args);
	return (total_char);
}
