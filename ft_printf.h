/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:00:31 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/15 00:00:32 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int     ft_printf(const char *str, ...);
void    ft_putstr(const char *str, unsigned int *print_count);
void    ft_put_unsigned_nb(unsigned int nb,  unsigned int *print_count);
void    ft_puthex(unsigned long int, unsigned long int nbr, const char str, unsigned int *print_count);
void    put_nbr(int i, int nbr, const char *base, unsigned int *print_count);

#endif