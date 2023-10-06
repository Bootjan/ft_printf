/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:22:17 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/05 19:57:50 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

void	print_value(va_list *args, char type, t_flags *flag)
{
	if (type == 's')
		ft_print_s(args, flag);
	else if (type == 'c')
		ft_print_c(args, flag);
	else if (type == 'p')
		ft_print_p(args, flag);
	else if (type == 'x')
		ft_print_x(args, flag);
	else if (type == 'X')
		ft_print_X(args, flag);
	else if (type == 'i')
		ft_print_i(args, flag);
	else if (type == 'd')
		ft_print_d(args, flag);
	else if (type == 'u')
		ft_print_u(args, flag);
	else if (type == '%')
		ft_print_per(args, flag);
	else
		ft_printf("<Bad type>");
}

int	is_type(char c)
{
	int	i;

	i = 0;
	while ("scpxXidu%%"[i])
		if (c == "scpxXidu%%"[i++])
			return (1);
	return (0);
}

int	print_variable(va_list *args, char *format, t_flags **flags)
{
	int	skip;

	skip = 1;
	while (*format && !is_type(*format))
	{
		skip++;
		format++;
	}
	print_value(args, *format, *flags);
	(*flags) = (*flags)->next;
	return (skip);
}

void	compute_flags(char *format, t_flags **flags)
{
	int		i;
	t_flags	*flag;
	int		atoi;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag = 0;
			flag = ft_create_elem();
			atoi = ft_atoi(format + i + 2);
			if (format[i + 1] == '0')
				flag->zero = atoi > 0 ? atoi : 1;
			if (format[i + 1] == '.')
				flag->dot = atoi > 0 ? atoi : 1;
			if (format[i + 1] == '*' || format[i + 2] == '*')
				flag->ast = 1;
			if (format[i + 1] == '-')
				flag->dash = atoi > 0 ? atoi : 1;
			ft_list_push_back(flags, flag);
			i++;
		}
		i++;
	}
}

void	ft_printf(char *format, ...)
{
	va_list	args;
	t_flags	*flags;
	t_flags	*free_flags;

	flags = 0;
	compute_flags(format, &flags);
	free_flags = flags;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			format += print_variable(&args, format + 1, &flags);
		else
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	ft_list_clear(free_flags);
}
