/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:00:17 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/20 20:03:31 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_space(const char *str, char *data, unsigned int *print_count, int *i)
{
	int	nbr;
	int	len;
	int	tmp;

	nbr = ft_atoi(str);
	len = ft_strlen(data);
	tmp = ft_strlen(ft_itoa(nbr));
	if (*(str) != 's')
	{
		*i += tmp + 1 ;
		nbr -= len ;
		while (nbr-- > 0)
			*print_count += write(1, " ", 1);
		ft_putstr(data, print_count);
	}
	if (*str == 's' && *data == 0)
	{
		*i += 1;
	}
	else if (*str == 's' && *data != 0)
	{
		ft_putstr(data, print_count);
		*i += 1;
	}
}

void	conversions(const char *str, va_list data, unsigned int *print_count, int *i)
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
	else if (*str == 'd' || *str == 'i')
		put_nbr(10, va_arg(data, int), "0123456789", print_count);
	else if (*str == 'p')
	{
		ft_putstr("0x", print_count);
		put_pointer(16, va_arg(data, unsigned long), print_count);
	}
	else if (*str == ' ')
		is_space((str+1), va_arg(data, char *), print_count, i);
}

void	is_bonus(const char *str, va_list dest, unsigned int *print_count, int *i)
{
	int				nbr;
	unsigned int	hexa;

	if (*(str + 1) == 'd' || *(str + 1) == 'i' )
	{
		if (*str == '+' || *str == '-' || *str == ' ')
		{
			nbr = va_arg(dest, int);
			*i += 1;
			if (nbr >= 0 && (*str == '+' || *str == ' '))
				*print_count += write(1, str, 1);
		}
	}
	else if (*str == '#')
	{
		*i += 1;
		hexa = va_arg(dest, unsigned int);
		if (hexa == 0)
			return ;
		if (*(str + 1) == 'x')
			*print_count += write(1, "0x", 2);
		else if (*(str + 1) == 'X')
			*print_count += write(1, "0X", 2);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			data;
	va_list			dest;
	int	i;
	unsigned int	print_count;

	if (!str)
		return (-1);
	va_start(data, str);
	print_count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				print_count += write(1, "%", 1);
			va_copy(dest, data);
			is_bonus(&str[i + 1], dest, &print_count, &i);
			conversions(&str[i + 1], data, &print_count, &i);
			i++;
		}
		else
			print_count += write(1, &str[i], 1);
	}
	return (va_end(data), print_count);
}