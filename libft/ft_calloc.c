/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:03:06 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/10 22:38:05 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total_size;

	total_size = size * nmemb;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	if (size > 0)
		ft_bzero(result, total_size);
	return (result);
}
