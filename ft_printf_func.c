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
	while (str[i] != '\0')
	{
		*print_count += write(1, &str[i], 1);
		i++;
	}
}
void ft_put_unsigned_nb(unsigned int nb,  unsigned int *print_count)
{
	unsigned int rz;
	if (nb > 9)
		ft_put_unsigned_nb(nb / 10, print_count);
	rz  =(nb % 10) + 48;
	print_count += write(1, &rz, 1);
}

void	ft_putnbr(int nb, unsigned int *print_count)
{	
	char rz;
	if (nb < -2147483647)
	{
		print_count += write(1, "-2147483648", 11);
	}
	if (nb < 0 && nb > -2147483648)
	{
		nb = -nb;
		print_count += write(1, "-", 1);
	}
	if (nb < 10 && nb >= 0 )
	{
		rz = (nb + 48);
		print_count += write(1, &rz, 1);
	}	
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, print_count);
		rz = (nb % 10 + 48);
		print_count += write(1, &rz, 1);
	}	
}

void ft_puthex_void(int i, unsigned long nbr, char *base, unsigned int *print_count)
{
	if (nbr >= i)
    {
        ft_puthex_void(i, nbr / i, base, print_count);
        ft_puthex_void(i, nbr % i, base, print_count);
    }
    else
        *print_count += write(1, base + nbr, 1);
}

void	ft_puthex(int i, unsigned int nbr, char str, unsigned int *print_count)
{
	char *base;
	if (str == 'X')
		base = "0123456789ABCDEF";
	else if (str == 'x')
		base = "0123456789abcdef";
	
	if (nbr >= i)
    {
        ft_puthex(i, nbr / i, str, print_count);
        ft_puthex(i, nbr % i, str, print_count);
    }
    else
        *print_count += write(1, base + nbr, 1);
}

