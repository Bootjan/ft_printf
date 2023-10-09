/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:08:06 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/09 13:29:40 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	compute_amount(t_flags *flag, char *out, int amount)
{
	amount = flag->zero + flag->dot + flag->dash;
	if (flag->dot > 0 && out[0] == '-')
		amount++;
	return (amount);
}

void	ft_print_wflags(char *out, int amount, t_flags *flag)
{
	int	zero_space;
	int	size;

	zero_space = 1;
	size = ft_strlen(out);
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
	if (out[0] == '-')
		ft_putstr(&out[1]);
	else
		ft_putstr(out);
	while (zero_space == 2 && amount-- > size)
		ft_putchar(' ');
}
