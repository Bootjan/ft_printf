/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:54:27 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/09 13:40:21 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

int	ft_get_atoi(char *format, int i)
{
	int	atoi;

	atoi = 0;
	atoi = ft_atoi(format + i + 2);
	if (!ft_isdigit(format[i + 2]))
		atoi = 1;
	return (atoi);
}

void	compute_sign_length(long *n, long *sign, long *len)
{
	long	buf_n;

	buf_n = *n / 10;
	*len = 1;
	while (buf_n)
	{
		(*len)++;
		buf_n /= 10;
	}
	if (*n < 0)
	{
		*sign = 1;
		(*len)++;
		*n *= -1;
	}
}
