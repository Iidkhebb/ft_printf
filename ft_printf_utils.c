/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:00:38 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/15 00:00:41 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr(const char *str, unsigned int *print_count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*print_count += write(1, "(null)", 6);
		return ;
	}
	while (str[i] != '\0')
	{
		*print_count += write(1, &str[i], 1);
		i++;
	}
	return ;
}

void	ft_puthex(unsigned int i, unsigned int nbr, const char str, unsigned int *print_count)
{
	char *base;

	if (str == 'X')
		base = "0123456789ABCDEF";
	else if (str == 'x')
	{
		base = "0123456789abcdef";
	}
	else if (str == 'u')
	{
		base = "0123456789";
		i = 10;
	}
	
	if (nbr >= i)
    {
        ft_puthex(i, nbr / i, str, print_count);
        ft_puthex(i, nbr % i, str, print_count);
    }
    else
        *print_count += write(1, base + nbr, 1);
}
void put_nbr(int i, int nbr, const char *base, unsigned int *print_count)
{
	if (nbr < -2147483647)
	{
		*print_count += write(1, "-2147483648", 11);
		return ;
	}
	else if (nbr < 0 && nbr > -2147483648)
	{
		nbr = -nbr;
		*print_count += write(1, "-", 1);
	}
	if (nbr >= i)
    {
		put_nbr(i, nbr / i, base, print_count);
        put_nbr(i, nbr % i, base, print_count);
    }
    else
        *print_count += write(1, base + nbr, 1);
}

void put_pointer(unsigned long i, unsigned long nbr, unsigned int *print_count)
{
	char *base;

	base = "0123456789abcdef";
	
	if (nbr >= i)
    {
        put_pointer(i, nbr / i, print_count);
        put_pointer(i, nbr % i, print_count);
    }
    else
        *print_count += write(1, base + nbr, 1);
}
