/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:02:31 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/09 14:02:34 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

t_flags	*ft_create_elem(void)
{
	t_flags	*out;

	out = 0;
	out = (t_flags *)malloc(sizeof(t_flags));
	if (!out)
		return (0);
	out->next = 0;
	out->zero = 0;
	out->dash = 0;
	out->dot = 0;
	out->ast = 0;
	return (out);
}

void	ft_list_push_back(t_flags **begin_list, t_flags *flag)
{
	t_flags	*current;

	if (!*begin_list)
	{
		*begin_list = flag;
		return ;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = flag;
}

void	free_fct(void *current)
{
	if (current)
		free(current);
}

void	ft_list_clear(t_flags *begin_list)
{
	t_flags	*current;
	t_flags	*next;

	current = begin_list;
	while (current)
	{
		next = 0;
		if (current->next)
			next = current->next;
		free_fct(current);
		current = next;
	}
}
