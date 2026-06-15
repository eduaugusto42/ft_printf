/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:44:46 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/06/15 15:22:56 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_handler(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	int		handler;
	size_t	count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			handler = ft_print_handler(++format, args);
			if (handler < 0)
				return (handler);
			count += handler;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

static int	ft_print_handler(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (*format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_print_dec(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int)));
	else if (*format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}
