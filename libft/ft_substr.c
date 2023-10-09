/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:30:59 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/06 10:43:23 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;
	int		j;

	out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	j = 0;
	while (s[j] && start--)
		j++;
	if (!s[j])
		return ("");
	i = 0;
	while (s[j] && len--)
		out[i++] = s[j++];
	out[i] = '\0';
	return (out);
}
