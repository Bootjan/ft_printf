/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:18:18 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/10 13:23:27 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*trim_string(char *s, int size)
{
	int		i;
	char	*out;

	out = ft_calloc(size + 1, sizeof(char));
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

	out = ft_calloc(9, sizeof(char));
	if (!out)
		return (0);
	if (n == 0)
	{
		out[0] = '0';
		return (out);
	}
	i = 0;
	while (n > 0)
	{
		out[7 - i++] = base[n % base_len];
		n /= base_len;
	}
	out = trim_string(out, i);
	return (out);
}
