/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:21:11 by bootjan           #+#    #+#             */
/*   Updated: 2023/10/09 13:40:15 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

# define MAX_U 4294967296

typedef struct s_flags
{
	struct s_flags	*next;
	int				dash;
	int				zero;
	int				dot;
	int				ast;
}	t_flags;

void	ft_putchar(char c);
void	ft_putstr(const char *s);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_print_u(va_list *args, t_flags *flag);
void	ft_print_d(va_list *args, t_flags *flag);
void	ft_print_i(va_list *args, t_flags *flag);
void	ft_print_p(va_list *args, t_flags *flag);
void	ft_print_x(va_list *args, t_flags *flag);
void	ft_print_ux(va_list *args, t_flags *flag);
void	ft_print_per(va_list *args, t_flags *flag);
void	ft_print_s(va_list *args, t_flags *flag);
void	ft_print_c(va_list *args, t_flags *flag);
void	ft_print_wflags(char *out, int amount, t_flags *flag);
t_flags	*ft_create_elem(void);
int		ft_atoi(const char *str);
void	ft_list_push_back(t_flags **begin_list, t_flags *flag);
void	ft_list_clear(t_flags *begin_list);
size_t	ft_strlen(const char *s);
void	ft_printf(char *format, ...);
int		ft_get_atoi(char *format, int i);
void	compute_sign_length(long *n, long *sign, long *len);

#endif
