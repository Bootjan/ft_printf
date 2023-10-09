/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:52:43 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/05 11:33:09 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;
	char	*current;
	size_t	i;

	out = 0;
	current = (char *)s;
	i = 0;
	while (current[i])
	{
		if (current[i] == c)
			out = &current[i];
		i++;
	}
	if (c == 0)
		out = &current[i];
	return (out);
}
