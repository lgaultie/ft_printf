/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/19 22:00:39 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_minus_s(int before, int after, char *final, t_data *data)
{
	char	*ap;

	if (data->tmp_s)
	{
		if (!(ap = ft_strdup(data->tmp_s)))
			return (NULL);
		free(data->tmp_s);
	}
	else
	{
		if (!(ap = ft_strdup("(null)")))
			return (NULL);
	}
	free(final);
	if (!(final = ft_strsub(ap, 0, after)))
		return (NULL);
	if (before > after && after >= data->conv_sz)
		data->width_precis_minus = before - data->conv_sz;
	else if (before > after && after < data->conv_sz)
		data->width_precis_minus = before - after;
	else if (after > before && after >= data->conv_sz)
		data->width_precis_minus = 0;
	else if (after == before && after >= data->conv_sz)
		data->width_precis_minus = after - data->conv_sz;
	else if (after >= before && after < data->conv_sz)
		data->width_precis_minus = 0;
	else if (ap[0] == '\0' && before > after && after >= data->conv_sz)
		data->width_precis_minus = before;
	else if (ap[0] == '\0' && before <= after && after >= data->conv_sz)
		data->width_precis_minus = before;
	free(ap);
	return (final);
}

static char		*ft_else(char *final, int before, int after, t_data *data)
{
	int		surplus;
	int		i;

	surplus = 0;
	i = 0;
	if (data->f & F_PLUS)
	{
		surplus = 1;
		final[i++] = '+';
	}
	while (i < after - data->conv_sz + surplus)
		final[i++] = '0';
	final[i] = '\0';
	if (before > after)
		data->width_precis_minus = before - i - data->conv_sz;
	return (final);
}

char			*ft_flag_minus(int before, int after, char *final, t_data *data)
{
	int		i;

	i = 0;
	if (data->f & F_S)
	{
		if (!(final = ft_minus_s(before, after, final, data)))
			return (NULL);
	}
	else
	{
		if (data->f & AP_NEG && !(data->f & F_UNSIGNED))
		{
			final[i++] = '-';
			while (i < after - data->conv_sz + 1)
				final[i++] = '0';
			final[i] = '\0';
			if (after == 0)
				data->width_precis_minus = 0;
		}
		else
			ft_else(final, before, after, data);
	}
	return (final);
}
