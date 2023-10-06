/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_x_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:26:17 by bootjan           #+#    #+#             */
/*   Updated: 2023/07/19 16:56:36 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

char	*trim_string(char *s, int size)
{
	int		i;
	char	*out;

	out = (char *)malloc((size + 1) * sizeof(char));
	if (!out)
		return (0);
	i = 0;
	while (i < size)
	{
		out[i] = s[8 - size + i];
		i++;
	}
	out[i] = 0;
	if (s)
		free(s);
	return (out);
}

char	*base_converter(long n, char *base, int base_len)
{
	char	*out;
	int		i;

	out = ft_strnew(9);
	if (!out)
		return (0);
	i = 0;
	while (n > 0)
	{
		out[7 - i++] = base[n % base_len];
		n /= base_len;
	}
	out = trim_string(out, i);
	return (out);
}

void	ft_print_p(va_list *args, t_flags *flag)
{
	char	*out;
	int		amount;
	int		size;

	amount = flag->ast == 1 ? va_arg(*args, int) : flag->dash;
	out = base_converter(va_arg(*args, int), "0123456789abcdef", 16);
	if (!out)
		return ;
	size = ft_strlen(out) + 3;
	while (flag->dash == 0 && amount-- > size)
		ft_putchar(' ');
	ft_putstr("0x1");
	ft_putstr(out);
	while (flag->dash > 0 && amount-- > size)
		ft_putchar(' ');
	if (out)
		free(out);
}

void	ft_print_x(va_list *args, t_flags *flag)
{
	long	conv_n;
	char	*out;
	int		amount;

	amount = flag->ast == 1 ? va_arg(*args, int) : 0;
	conv_n = va_arg(*args, int);
	conv_n = conv_n < 0 ? MAX_U + conv_n : conv_n;
	out = base_converter(conv_n, "0123456789abcdef", 16);
	if (!out)
		return ;
	ft_print_wflags(out, amount, flag);
	if (out)
		free(out);
}

void	ft_print_X(va_list *args, t_flags *flag)
{
	long	conv_n;
	char	*out;
	int		amount;

	amount = flag->ast == 1 ? va_arg(*args, int) : 0;
	conv_n = va_arg(*args, int);
	conv_n = conv_n < 0 ? MAX_U + conv_n : conv_n;
	out = base_converter(conv_n, "0123456789ABCDEF", 16);
	if (!out)
		return ;
	ft_print_wflags(out, amount, flag);
	if (out)
		free(out);
}
