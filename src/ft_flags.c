/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:22:30 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 18:34:59 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_flag_conv: join the converted conversion with converted flags.
*/

char	*ft_flag_conv(char *flag, t_data *data)
{
	char	*final;
	char	*ret_conv;
	char	*ret_flag;
	char	*ret_flag2;
	char	*ret;
	char	*tmp;
	int		i;

	i = ft_active_flag(flag, data);
	if (flag[i] != '%' && !(data->flag & F_PERCENT))
	{
		if (!(ret_conv = ft_only_conv(&flag[i], data)))
			return (NULL);
		if (ret_conv[0] == '\0' && data->flag & F_SHARP \
		&& !(data->flag & F_WIDTH))
			return (ret_conv);
	}
	if (!(data->flag & F_PERCENT) && (data->flag & F_MINUS) \
	&& (data->flag & F_WIDTH) && !(data->flag & F_PRECIS) \
	&& !(data->flag & F_W_P) && !(data->flag & F_PLUS))
	{
		if (data->flag & AP_NEG && !(data->flag & F_UNSIGNED) \
		&& (flag[i] != 's' || flag[i] != 'c'))
		{
			if (!(ret_conv = ft_strjoin("-", ret_conv)))
				return (NULL);
		}
		if (!(ret_flag2 = ft_width_minus(flag, data)))
			return (NULL);
		if (!(final = ft_strjoin(ret_conv, ret_flag2)))
			return (NULL);
		free(ret_conv);
		free(ret_flag2);
		return (final);
	}
	if (data->flag & F_PERCENT)
	{
		if (!(data->flag & F_MINUS))
		{
			data->conv_sz = 1;
			if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
				return (NULL);
			if (!(final = ft_strjoin(ret_flag, "%")))
				return (NULL);
			free(ret_flag);
			return (final);
		}
		if (data->flag & F_MINUS)
		{
			data->conv_sz = 1;
			i--;
			if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
				return (NULL);
			if (!(final = ft_strjoin("%", ret_flag)))
				return (NULL);
			free(ret_flag);
			return (final);
		}
	}
	if (data->flag & F_SPACE && data->flag & AP_NEG)
		return (ret_conv);
	if (!(ret_flag = ft_which_flag(flag, flag[i], data)))
		return (NULL);
	if (data->flag & F_AFTER_IS_0)
	{
		free(ret_conv);
		return (ret_flag);
	}
	if (data->flag & F_SHARP && data->flag & F_ZERO \
	&& !(data->flag & F_PRECIS) && !(data->flag & F_W_P) && (flag[i] == 'x' \
	|| flag[i] == 'X'))
	{
		if (flag[i] == 'X')
		{
			ret_flag[0] = '0';
			ret_flag[1] = 'X';
		}
		if (flag[i] == 'x')
		{
			ret_flag[0] = '0';
			ret_flag[1] = 'x';
		}
	}
	if (data->flag & F_SHARP && data->flag & F_ZERO && data->flag & F_PRECIS \
	&& !(data->flag & F_W_P) && (flag[i] == 'x' \
	|| flag[i] == 'X'))
	{
		if (flag[i] == 'X')
		{
			tmp = ret_flag;
			if (!(ret_flag = ft_strjoin("0X", tmp)))
				return (NULL);
			free(tmp);
		}
		if (flag[i] == 'x')
		{
			tmp = ret_flag;
			if (!(ret_flag = ft_strjoin("0x", tmp)))
				return (NULL);
			free(tmp);
		}
	}
	if ((data->flag & F_PRECIS) && (flag[i] == 's' || flag[i] == 'c'))
	{
		free(ret_conv);
		return (ret_flag);
	}
	if (flag[i] == '%')
	{
		if (!(final = ft_percent_percent(ret_flag, data)))
			return (NULL);
		free(ret_flag);
		return (final);
	}
	if (flag[i] == 's' && (data->flag & F_MINUS) && (data->flag & F_W_P))
	{
		final = ft_strdup(ret_flag);
	}
	else
	{
		if (!(final = ft_strjoin(ret_flag, ret_conv)))
			return (NULL);
	}
	if (data->flag & F_W_P && data->flag & F_MINUS)
	{
		i = 0;
		if (!(ret = ft_memalloc(sizeof(char) * (data->width_precis_minus + 1))))
			return (NULL);
		if (!(data->flag & F_PLUS))
		{
			while (i < data->width_precis_minus)
				ret[i++] = ' ';
		}
		else
		{
			while (i < data->width_precis_minus)
				ret[i++] = ' ';
		}
		tmp = final;
		if (!(final = ft_strjoin(tmp, ret)))
			return (NULL);
		free(ret);
		free(tmp);
	}
	free(ret_conv);
	free(ret_flag);
	return (final);
}
