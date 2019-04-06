/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/06 15:40:01 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_string_1(t_data *data)
{
	char	*ap;
	char	*tmp;

	tmp = (va_arg(data->ap, char*));
	if (tmp != NULL)
		ap = ft_strdup(tmp);
	else
		return (ft_strdup("(null)"));
	if (tmp[0] == '\0')
		data->flag |= F_S_0;
	if ((data->flag & F_PRECIS || data->flag & F_WIDTH) \
	&& (!(data->flag & F_MINUS)))
		data->tmp_s = ft_strdup(ap);
	data->conv_sz = ft_strlen(ap);
	data->ap_sz = ft_strlen(ap);
	if (data->flag & F_MINUS)
		data->tmp_s = ap;
	if ((data->flag & F_PRECIS || data->flag & F_WIDTH) \
	&& (!(data->flag & F_MINUS)))
	{
		free (ap);
		ap = ft_strdup("");
	}
	return (ap);
}

char		*ft_string(char *flag, t_data *data, int mode)
{
	char	*ap;
	char	*final;
	char	*ret_width;
	char	*tmp;

	if (mode == 0)
	{
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
		}
	}
	return (final);
}

char		*ft_char(t_data *data)
{
	char	ap;
	char	*final;

	if (!(final = ft_memalloc(sizeof(char) * 2)))
	return (NULL);
	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (ap == 0)
	{
		data->flag |= F_C_0;
		final[0] = 0;
		final[1] = '\0';
		data->tmp = ft_strlen(data->buf);
	}
	else
	{
		final[0] = ap;
		final[1] = '\0';
	}
	data->conv_sz = 1;
	return (final);
}
