/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:08:06 by bootjan           #+#    #+#             */
/*   Updated: 2023/07/19 14:35:58 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	compute_amount(t_flags *flag, char *out, int amount)
{
	if (flag->zero > 0 || flag->dot > 0)
	{
		amount = amount == 0 ? flag->zero : amount;
		amount = amount == 0 ? flag->dot : amount;
		amount = flag->dot > 0 && out[0] == '-' ? amount + 1 : amount;
	}
	if (flag->dash > 0)
		amount = amount == 0 ? flag->dash : amount;
	return (amount);
}

void	ft_print_wflags(char *out, int amount, t_flags *flag)
{
	int	zero_space;
	int	size;
	
	zero_space = 1;
	size = (int)ft_strlen(out);
	if (flag->zero > 0 || flag->dot > 0)
		zero_space = 0;
	if (flag->dash > 0)
		zero_space = 2;
	amount = compute_amount(flag, out, amount);
	while (zero_space == 1 && amount-- > size)
		ft_putchar(' ');
	if (out[0] == '-')
		ft_putchar(out[0]);
	while (zero_space == 0 && amount-- > size)
		ft_putchar('0');
	ft_putstr(out[0] == '-' ? &out[1] : out);
	while (zero_space == 2 && amount-- > size)
		ft_putchar(' ');
}
