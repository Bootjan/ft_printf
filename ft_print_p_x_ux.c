/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_x_ux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:10:46 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/10 14:33:58 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(va_list *args)
{
	char	*out;
	UL		args_n;
	size_t	size;

	args_n = 0;
	args_n = va_arg(*args, UL);
	out = base_converter(args_n, LOWER_16_BASE, ft_strlen(LOWER_16_BASE));
	if (!out)
		return (0);
	ft_putstr_fd("0x", 1);
	size = (int)ft_strlen(out) + 2;
	ft_putstr_fd(out, 1);
	if (out)
		free(out);
	return (size);
}

int	ft_print_x(va_list *args)
{
	char	*out;
	UL		args_n;
	size_t	size;

	args_n = 0;
	args_n = va_arg(*args, UL);
	out = base_converter(args_n, LOWER_16_BASE, ft_strlen(LOWER_16_BASE));
	if (!out)
		return (0);
	ft_putstr_fd(out, 1);
	size = (int)ft_strlen(out);
	if (out)
		free(out);
	return (size);
}

int	ft_print_upper_x(va_list *args)
{
	char	*out;
	UL		args_n;
	size_t	size;

	args_n = 0;
	args_n = va_arg(*args, UL);
	out = base_converter(args_n, UPPER_16_BASE, ft_strlen(UPPER_16_BASE));
	if (!out)
		return (0);
	ft_putstr_fd(out, 1);
	size = (int)ft_strlen(out);
	if (out)
		free(out);
	return (size);
}
