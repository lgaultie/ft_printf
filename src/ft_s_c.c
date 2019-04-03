/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/03 15:21:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_string_1(t_data *data)
{
	char	*ap;

	if (!(data->flag & F_STAR))
		ap = (va_arg(data->ap, char*));
	if ((data->flag & F_PRECIS || data->flag & F_WIDTH) \
	&& !(data->flag & F_MINUS))
	{
		if (data->flag & F_STAR)
		{
			data->tmp = (va_arg(data->ap, int));
			data->tmp_s = (va_arg(data->ap, char *));
		}
		if ((data->flag & F_PRECIS || data->flag & F_WIDTH)
		&& (!(data->flag & F_STAR)))
			data->tmp_s = ft_strdup(ap);
		data->ap_sz = ft_strlen(ap);
		data->conv_sz = ft_strlen(ap);
		return (ft_strdup(""));
	}
	data->tmp_s = ap;
	data->conv_sz = ft_strlen(ap);
	data->ap_sz = ft_strlen(ap);
	return (ft_strdup(ap));
}

char		*ft_string(char *flag, t_data *data, int mode)
{
	char	*ap;
	char	*final;
	char	*ret_width;
	char	*tmp;

	if (mode == 0)
	{
		// ft_putstr("\nici dans ft_s_c.c mode 0");
		if (!(final = ft_string_1(data)))
			return (NULL);
	}
	if (mode == 1)
	{
		ap = data->tmp_s;
		if (data->flag & F_PRECIS && !(data->flag & F_W_P))
		{
			data->ap_sz = ft_precision_s(flag, data);
			if (!(final = ft_strsub(ap, 0, data->ap_sz)))
				return (NULL);
		}
		if (data->flag & F_WIDTH && !(data->flag & F_W_P))
		{
			data->ap_sz = ft_strlen(ap);
			ret_width = ft_width_s(flag, data);
			if (!(final = ft_strjoin(ret_width, ap)))
				return (NULL);
			free(ret_width);
		}
		if (data->flag & F_W_P)
		{
			data->ap_sz = ft_precision_s(flag, data);
			if (!(final = ft_strsub(ap, 0, data->ap_sz)))
				return (NULL);
			ret_width = ft_width_s(flag, data);
			tmp = final;
			if (!(final = ft_strjoin(ret_width, tmp)))
				return (NULL);
			free(tmp);
			free(ret_width);
			// printf("final dans string1 = |%s|\n\n", final);
		}
	}
	return (final);
}

char		*ft_char(t_data *data)
{
	char	ap;
	char	*final;

	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (!(final = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	final[0] = ap;
	final[1] = '\0';
	return (final);
}
