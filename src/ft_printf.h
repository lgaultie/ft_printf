/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:57:52 by amamy             #+#    #+#             */
/*   Updated: 2019/03/05 12:07:32 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>
# include <stdio.h>

typedef	struct	s_data
{
	va_list		ap;
	int			flag_size;
	int			ap_size;
	char 		*buf;
	int			conv_sz;
	int			conv_t_sz;
}				t_data;

int		ft_printf(const char* str, ...);
char	*ft_conv_dif(char *flags, t_data *data);
void	ft_flag_zero(char *flags, t_data *data);
void	ft_flag_plus(char *flags, t_data *data);
void	ft_flag_minus(char *flags, t_data *data);
void	ft_flag_space(char *flags, t_data *data);
void	ft_espaces(char *flags, t_data *data);
void	ft_precision(char *flags, t_data *data);

#endif

// va_list		ap;
// int			flag_sz;
// int			ap_sz;
// int			ap_t_sz;
// char 		*buf;
