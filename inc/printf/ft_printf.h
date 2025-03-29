/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:51:00 by speters           #+#    #+#             */
/*   Updated: 2025/03/18 13:02:08 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		print_hexa(unsigned int nb, const char type);
int		print_ptr(unsigned long long ptr);
int		print_uns(unsigned int nb);
int		print_int(int nb);
void	ft_putstr(char *str);
int		print_str(char *str);
int		print_str(char *str);
int		ft_putchar(char c);

#endif
