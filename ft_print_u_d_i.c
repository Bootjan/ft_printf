/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:18:06 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/09 13:40:32 by bschaafs         ###   ########.fr       */
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
	sign = 0;
	len = 0;
	compute_sign_length(&n, &sign, &len);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (0);
	if (sign)
		out[0] = '-';
	while (len-- > sign)
	{
		out[len] = n % 10 + '0';
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
	sign = 0;
	len = 0;
	compute_sign_length(&n, &sign, &len);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (0);
	if (sign)
		out[0] = '-';
	while (len-- > sign)
	{
		out[len] = n % 10 + '0';
		n /= 10;
	}
	return (out);
}

void	ft_print_d(va_list *args, t_flags *flag)
{
	char	*out;
	int		amount;

	amount = 0;
	if (flag->ast)
		amount = va_arg(*args, int);
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

	amount = 0;
	if (flag->ast)
		amount = va_arg(*args, int);
	long_n = va_arg(*args, int);
	if (long_n < 0)
		long_n += MAX_U;
	out = ft_itou(long_n);
	ft_print_wflags(out, amount, flag);
	if (out)
		free(out);
}

void	ft_print_i(va_list *args, t_flags *flag)
{
	char	*out;
	int		amount;

	amount = 0;
	if (flag->ast)
		amount = va_arg(*args, int);
	out = ft_itoa(va_arg(*args, int));
	ft_print_wflags(out, amount, flag);
	if (out)
		free(out);
}
