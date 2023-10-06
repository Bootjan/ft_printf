/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:18:06 by bootjan           #+#    #+#             */
/*   Updated: 2023/07/19 15:21:18 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_itod(long n)
{
	long	len;
	long	sign;
	char	*out;

	if (n > 2147483647 || n < -2147483647)
		return (0);
	sign = n;
	len = 1;
	while (sign /= 10)
		len++;
	sign = n >= 0 ? 0 : 1;
	len = n < 0 ? len + 1 : len;
	out = ft_strnew((size_t)(len + 1));
	if (!out)
		return (0);
	if (sign)
		out[0] = '-';
	n = n < 0 ? -n : n;
	while (len-- > sign)
	{
		out[len] = n <= 9 ? n + '0' : n % 10 + '0';
		n /= 10;
	}
	return (out);
}

char	*ft_itou(long n)
{
	long	len;
	long	sign;
	char	*out;

	if (n == -2147483648)
		return (out = ft_strdup("-2147483648"));
	sign = n;
	len = 1;
	while (sign /= 10)
		len++;
	sign = n >= 0 ? 0 : 1;
	len = n < 0 ? len + 1 : len;
	out = ft_strnew((size_t)(len + 1));
	if (!out)
		return (0);
	if (sign)
		out[0] = '-';
	n = n < 0 ? -n : n;
	while (len-- > sign)
	{
		out[len] = n <= 9 ? n + '0' : n % 10 + '0';
		n /= 10;
	}
	return (out);
}

void	ft_print_d(va_list *args, t_flags *flag)
{
	char	*out;
	int		amount;

	amount = flag->ast == 1 ? va_arg(*args, int) : 0;
	out = ft_itod(va_arg(*args, int));
	ft_print_wflags(out, amount, flag);
	if (out)
		free(out);
}

void	ft_print_u(va_list *args, t_flags *flag)
{
	long	long_n;
	char	*out;
	int		amount;

	amount = flag->ast == 1 ? va_arg(*args, int) : 0;
	long_n = va_arg(*args, int);
	long_n = long_n < 0 ? MAX_U + long_n : long_n;
	out = ft_itou(long_n);
	ft_print_wflags(out, amount, flag);
	if (out)
		free(out);
}

void	ft_print_i(va_list *args, t_flags *flag)
{
	char	*out;
	int		amount;

	amount = flag->ast == 1 ? va_arg(*args, int) : 0;
	out = ft_itoa(va_arg(*args, int));
	ft_print_wflags(out, amount, flag);
	if (out)
		free(out);
}
