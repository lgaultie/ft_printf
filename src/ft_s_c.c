/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/09 13:31:18 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_string_1(t_data *data)
{
	char	*ap;
	char	*tmp;

	tmp = (va_arg(data->ap, char*));
	if (tmp != NULL)
	{
		if (!(ap = ft_strdup(tmp)))
			return (NULL);
	}
	else
		return (ft_strdup("(null)"));
	if (tmp[0] == '\0')
		data->f |= F_S_0;
	if ((data->f & F_PRECIS || data->f & F_WIDTH) && (!(data->f & F_MINUS)))
		if (!(data->tmp_s = ft_strdup(ap)))
			return (NULL);
	data->conv_sz = ft_strlen(ap);
	data->ap_sz = ft_strlen(ap);
	data->tmp_s = (data->f & F_MINUS) ? ft_strdup(ap) : data->tmp_s;
	if ((data->f & F_PRECIS || data->f & F_WIDTH) && (!(data->f & F_MINUS)))
		free(ap);
	if ((data->f & F_PRECIS || data->f & F_WIDTH) && (!(data->f & F_MINUS)))
		if (!(ap = ft_strdup("")))
			return (NULL);
	return (ap);
}

char			*ft_s_width(char *flag, char *ap, t_data *data)
{
	char	*final;
	char	*ret_width;

	data->ap_sz = ft_strlen(ap);
	if (!(ret_width = ft_width_s(flag, data)))
		return (NULL);
	if (!(final = ft_strjoin(ret_width, ap)))
		return (NULL);
	free(ret_width);
	return (final);
}

char			*ft_s_fwp(char *flag, char *ap, t_data *data)
{
	char	*final;
	char	*tmp;
	char	*ret_width;

	data->ap_sz = ft_precision_s(flag, data);
	if (!(final = ft_strsub(ap, 0, data->ap_sz)))
		return (NULL);
	if (!(ret_width = ft_width_s(flag, data)))
		return (NULL);
	tmp = final;
	if (!(final = ft_strjoin(ret_width, tmp)))
		return (NULL);
	free(tmp);
	free(ret_width);
	return (final);
}

char			*ft_string(char *flag, t_data *data, int mode)
{
	char	*ap;
	char	*final;

	if (mode == 0)
		if (!(final = ft_string_1(data)))
			return (NULL);
	if (mode == 1)
	{
		if (!(ap = ft_strdup(data->tmp_s)))
			return (NULL);
		free(data->tmp_s);
		if (data->f & F_PRECIS && !(data->f & F_W_P))
		{
			data->ap_sz = ft_precision_s(flag, data);
			if (!(final = ft_strsub(ap, 0, data->ap_sz)))
				return (NULL);
		}
		if (data->f & F_WIDTH && !(data->f & F_W_P))
			if (!(final = ft_s_width(flag, ap, data)))
				return (NULL);
		if (data->f & F_W_P)
			if (!(final = ft_s_fwp(flag, ap, data)))
				return (NULL);
	}
	return (final);
}

char			*ft_char(t_data *data)
{
	char	ap;
	char	*final;

	if (!(final = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (ap == 0)
	{
		data->f |= F_C_0;
		final[0] = 0;
		final[1] = '\0';
		data->index_0 = ft_strlen(data->buf);
	}
	else
	{
		final[0] = ap;
		final[1] = '\0';
	}
	data->conv_sz = 1;
	return (final);
}
