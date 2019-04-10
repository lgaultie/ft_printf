/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:57:52 by amamy             #+#    #+#             */
/*   Updated: 2019/04/10 13:15:58 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

# define F_ZERO 1
# define F_PLUS 2
# define F_MINUS 4
# define F_SHARP 8
# define F_SPACE 16
# define F_WIDTH 32
# define F_PRECIS 64
# define F_STAR 128
# define F_W_P 256
# define B_DONE 512
# define F_PLUS_MINUS 1024
# define F_H 2048
# define F_HH 4096
# define F_L 8192
# define F_LL 16384
# define AP_NEG 32768
# define F_UNSIGNED 65536
# define ONLY_CONV 131072
# define F_PERCENT 262144
# define F_S 524288
# define F_C_0 1048576
# define F_S_0 2097152
# define F0 4194304
# define TMP_S_M 8388608

typedef	struct	s_data
{
	va_list		ap;
	int			done;
	int			flag_sz;
	int			ap_sz;
	char		*buf;
	int			conv_sz;
	int			conv_t_sz;
	int			f;
	int			tmp;
	int			index_0;
	int			width_precis_minus;
	char		*tmp_s;
}				t_data;

int				ft_printf(const char *str, ...);
char			*ft_conv_di(t_data *data);
char			*ft_string(char *flag, t_data *data, int mode);
char			*ft_char(t_data *data);
char			*ft_got_flag(char *str, t_data *data);
char			*ft_next_p100(char *str, t_data *data);
char			*ft_analyse(char *str, t_data *data);
char			*ft_conv_dif(char *flags, t_data *data);
char			*ft_jonh_claude(char *flags, t_data *data);
char			*ft_conv_p(t_data *data);
char			*ft_precision_d(char *flags, t_data *data);
int				ft_precision_s(char *flags, t_data *data);
char			*ft_width(char *flags, t_data *data);
char			*ft_width2(int width, t_data *data);
char			*ft_octal(t_data *data);
char			*ft_hexa(t_data *data, int mode);
char			*ft_caps_x(t_data *data);
char			*ft_conv_u(t_data *data);
char			*ft_analyse_options(char *flags, t_data *data);
char			*ft_flag_conv(char *f, char *ret_conv, int i, t_data *d);
char			*ft_only_conv(char *flags, t_data *data);
char			*ft_which_flag(char *flag, char conv, t_data *data);
char			*ft_preci_width(char *flag, t_data *data);
char			*ft_plus(char *flag, t_data *data);
char			*ft_width_minus(char *flag, t_data *data);
char			*ft_minus(char *flag, t_data *data);
char			*ft_conv_hhhlll_u(t_data *data, int base, int mode);
char			*ft_conv_hhhlll(t_data *data);
char			*ft_preci_width_minus(char *flag, t_data *data);
char			*ft_width_s(char *flags, t_data *data);
char			*ibmul(unsigned long long v, unsigned int b, int m, t_data *d);
char			*itoa_base_m(unsigned int v, unsigned int b, int m, t_data *d);
char			*itoa_b_m_ui(unsigned int v, unsigned int b, int m, t_data *d);
char			*ft_flag_minus(int before, int after, char *final, t_data *d);
char			*ft_case2(char *final, int before, int after, t_data *data);
char			*ft_case3(char *final, int before, int after, t_data *data);
char			*ft_percent_percent(char *ret_flag, t_data *data);
int				ft_active_flag(char *flag, t_data *data);
char			*ft_special_cases(int i, char *f, t_data *d);
char			*ft_fwp_minus(char *final, t_data *data);
char			*ft_for_minus(char *ret_conv, char *flag, int i, t_data *data);

#endif
