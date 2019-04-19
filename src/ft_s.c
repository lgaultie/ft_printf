/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:40:43 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/19 19:12:26 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_string_1_if(char *ap, char *tmp, t_data *d, int mode)
{
	if (mode == 1)
	{
		if (tmp[0] == '\0')
			d->f |= F_S_0;
		d->conv_sz = ft_strlen(ap);
		d->ap_sz = ft_strlen(ap);
	}
	if (mode == 2)
	{
		if ((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS)))
		{
			d->f |= TMP_S_M;
			if (!(d->tmp_s = ft_strdup(ap)))
				return ;
		}
		else if (d->f & F_MINUS)
		{
			d->f |= TMP_S_M;
			if (!(d->tmp_s = ft_strdup(ap)))
				return ;
		}
	}
}

static char		*ft_string_1(t_data *d)
{
	char	*ap;
	char	*tmp;

	tmp = va_arg(d->ap, char*);
	if (tmp != NULL)
	{
		if (!(ap = ft_strdup(tmp)))
			return (NULL);
	}
	else
	{
		d->ap_sz = 6;
		d->conv_sz = 6;
		return (ft_strdup("(null)"));
	}
	if (((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS))) \
	|| (d->f & F_MINUS))
		ft_string_1_if(ap, tmp, d, 2);
	ft_string_1_if(ap, tmp, d, 1);
	if ((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS)))
		free(ap);
	if ((d->f & F_PRECIS || d->f & F_WIDTH) && (!(d->f & F_MINUS)))
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
		if (data->tmp_s)
		{
			if (!(ap = ft_strdup(data->tmp_s)))
				return (NULL);
			free(data->tmp_s);
		}
		else
		{
			if ((data->f & F_WIDTH) && !(data->f & F_W_P))
				return (ft_width_s(flag, data));
			else if (data->f & F_PRECIS && (data->f & F_W_P))
				return (ft_strsub("(null)", 0, ft_precision_s(flag, data)));
			else
			{
				if (!(ap = ft_strdup("(null)")))
					return (NULL);
			}
		}
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
		free(ap);
	}
	data->f |= F_S;
	return (final);
}
