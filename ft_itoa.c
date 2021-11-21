/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:58:28 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/20 19:58:32 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_str(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	num;

	num = n;
	i = len_str(n) - 1;
	str = (char *)malloc((len_str(n) + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len_str(n)] = '\0';
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[i] = '-';
	if (n == 0)
		str[i] = '0';
	return (str);
}
