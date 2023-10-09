/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per_s_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:10:44 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/09 13:31:17 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_print_s(va_list *args, t_flags *flag)
{
	int		size;
	int		amount;
	char	*str;

	amount = flag->dash;
	if (flag->ast == 1)
		amount = va_arg(*args, int);
	str = va_arg(*args, char *);
	size = (int)ft_strlen(str);
	while (flag->dash == 0 && amount-- > size)
		ft_putchar(' ');
	ft_putstr(str);
	while (flag->dash > 0 && amount-- > size)
		ft_putchar(' ');
}

void	ft_print_c(va_list *args, t_flags *flag)
{
	int		amount;
	char	c;

	amount = flag->dash;
	if (flag->ast == 1)
		amount = va_arg(*args, int);
	c = va_arg(*args, int);
	while (flag->dash == 0 && amount-- > 1)
		ft_putchar(' ');
	ft_putchar(c);
	while (flag->dash > 0 && amount-- > 1)
		ft_putchar(' ');
}

void	ft_print_per(va_list *args, t_flags *flag)
{
	int	amount;

	amount = flag->dash;
	if (flag->ast == 1)
		amount = va_arg(*args, int);
	while (flag->dash == 0 && amount-- > 1)
		ft_putchar(' ');
	ft_putchar('%');
	while (flag->dash > 0 && amount-- > 1)
		ft_putchar(' ');
}
