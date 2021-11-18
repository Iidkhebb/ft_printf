/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:00:17 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/19 00:30:50 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversions(const char *str, va_list data, unsigned int *print_count)
{
	int	c;

	if (*str == 'c')
	{
		c = va_arg(data, int);
		*print_count += write(1, &c, 1);
	}
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		ft_puthex(16, va_arg(data, unsigned int), *str, print_count);
	else if (*str == 's')
		ft_putstr(va_arg(data, const char *), print_count);
	else if ((*str == 'd' || *str == 'i') || (*str == '+' || *str == '-'))
		put_nbr(10, va_arg(data, int), "0123456789", print_count);
	else if (*str == 'p')
	{
		ft_putstr("0x", print_count);
		put_pointer(16, va_arg(data, unsigned long), print_count);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			data;
	unsigned int	i;
	unsigned int	print_count;

	if (!str)
		return (-1);
	va_start(data, str);
	print_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				print_count += write(1, "%", 1);
			else
				conversions(&str[i + 1], data, &print_count);
			i++;
		}
		else
			print_count += write(1, &str[i], 1);
		i++;
	}
	va_end(data);
	return (print_count);
}
