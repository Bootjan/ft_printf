/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:53:18 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/06 10:36:05 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*out;
	size_t	i;

	out = (char *)s;
	i = 0;
	while (out[i])
	{
		if (out[i] == c)
			return (&out[i]);
		i++;
	}
	if (c == 0)
		return (&out[i]);
	return (NULL);
}
