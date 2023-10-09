/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:09:35 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/05 11:10:21 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;

	if (!src)
		return (dst);
	dest = dst;
	source = src;
	if (src < dst)
	{
		i = 0;
		while (i < n)
		{
			dest[n - i - 1] = source[n - i - 1];
			i++;
		}
	}
	else
	{
		i = n + 1;
		while (i-- > 1)
			dest[n - i] = source[n - i];
	}
	return (dst);
}
