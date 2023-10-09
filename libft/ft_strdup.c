/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:10:16 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/05 11:21:48 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*out;

	size = ft_strlen(s1) + 1;
	out = (char *)malloc(size * sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, s1, size);
	return (out);
}
