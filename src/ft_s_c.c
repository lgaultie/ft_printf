/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/04 13:20:29 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_string_1_PW(char *ap, t_data *data)
{
	if (data->flag & F_STAR)
	{
		data->tmp = (va_arg(data->ap, int));
		data->tmp_s = (va_arg(data->ap, char *));
	}
	else
		data->tmp_s = ft_strdup(ap);
}


static char	*ft_string_1(t_data *data)
{
	char	*ap;

	if (!(data->flag & F_STAR))
		ap = ft_strdup((va_arg(data->ap, char*)));
	// if (!(data->flag & F_STAR) && ap == NULL)
	// 	return (ft_strdup("(null)"));
	if ((data->flag & F_PRECIS || data->flag & F_WIDTH) \
	&& (!(data->flag & F_MINUS)))
	{
		ft_string_1_PW(ap, data);
	}
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
