/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaaugu <eduaaugu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:44:46 by eduaaugu          #+#    #+#             */
/*   Updated: 2026/06/11 16:26:26 by eduaaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_handler(const char *format, va_list args);

int ft_printf(const char *format, ...)
{
	va_list	args; // TODO Initialize the variable

	while (*format)
	{
		if (*format == '%')
			ft_print_handler(++format, args);
		ft_putchar_fd(*format, 1);
		format++;
	}
	return (0); // TODO Return the number of characters printed
}

static void	ft_print_handler(const char *format, va_list args)
{
	// TODO Dispatch table
}
