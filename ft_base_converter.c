/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:18:18 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/10 14:44:22 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*push_front(char *str, char c)
{
	size_t	size;
	char	*out;
	size_t	i;

	size = 0;
	if (str)
		size = ft_strlen(str);
	out = ft_calloc(size + 2, sizeof(char));
	if (!out)
		return (NULL);
	out[0] = c;
	i = 0;
	while (i < size)
	{
		out[i + 1] = str[i];
		i++;
	}
	if (str)
		free(str);
	return (out);
}

char	*base_converter(unsigned long n, char *base, int base_len)
{
	char	*out;

	out = ft_calloc(2, sizeof(char));
	if (!out)
		return (0);
	if (n == 0)
	{
		out[0] = '0';
		return (out);
	}
	while (n > 0)
	{
		out = push_front(out, base[n % base_len]);
		n /= base_len;
	}
	return (out);
}
