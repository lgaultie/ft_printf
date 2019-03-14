/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:57:52 by amamy             #+#    #+#             */
/*   Updated: 2019/03/14 23:04:09 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef	struct	s_data
{
	va_list		ap;
	int			flag_sz;
	int			ap_size;
	char 		*buf;
	int			conv_sz;
	int			conv_t_sz;
	int			done;
}				t_data;

//int		ft_printf(const char* str, ...);
char	*ft_printf(const char* str, ...);
char	*ft_got_flag(char *str, t_data *data);
char	*ft_next_p100(char *str, t_data *data);
char	*ft_analyse(char *str, t_data *data);
char	*ft_conv_dif(char *flags, t_data *data);
char	*ft_jonh_claude(char *flags, t_data *data);
char	*ft_conv_p(t_data *data);
// void	ft_flag_zero(char *flags, t_data *data);
// void	ft_flag_plus(char *flags, t_data *data);
// void	ft_flag_minus(char *flags, t_data *data);
// void	ft_flag_space(char *flags, t_data *data);
//void	ft_espaces(char *flags, t_data *data);
//void	ft_precision(char *flags, t_data *data);

#endif

// va_list		ap;
// int			flag_sz;
// int			ap_sz;
// int			ap_t_sz;
// char 		*buf;
