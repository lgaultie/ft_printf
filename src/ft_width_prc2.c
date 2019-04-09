/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:08:18 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 22:12:57 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_free_all(char *final, char *tmp, char *ap, char *for_s)
{
	if (!(final = ft_strjoin(for_s, tmp)))
		return (NULL);
	free(tmp);
	free(for_s);
	free(ap);
	return (final);
}

static char		*ft_s(char *final, int before, int after, t_data *data)
{
	char	*ap;
	char	*for_s;
	char	*tmp;
	int		i;

	i = 0;
	ap = ft_strdup(data->tmp_s);
	free(data->tmp_s);
	free(final);
	if (!(final = ft_strsub(ap, 0, after)))
		return (NULL);
	if (before > after)
		data->width_precis_minus = before - after;
	if (after >= before)
		data->width_precis_minus = before - data->conv_sz;
	if (ap[0] == '\0' && before > after)
		data->width_precis_minus = before;
	if (ap[0] == '\0' && before <= after)
		data->width_precis_minus = after;
	if (!(for_s = ft_memalloc(sizeof(char) * before - after + 1)))
		return (NULL);
	while (i < before - after)
		for_s[i++] = ' ';
	tmp = final;
	return (ft_free_all(final, tmp, ap, for_s));
}

char			*ft_case2(char *final, int before, int after, t_data *data)
{
	int		i;

	i = 0;
	if (data->f & F_S)
		return (ft_s(final, before, after, data));
	if (data->f & AP_NEG)
	{
		while (i < before - data->conv_sz - 1)
			final[i++] = ' ';
		final[i++] = '-';
	}
	if (!(data->f & AP_NEG))
	{
		if (data->f & F_PLUS)
			final[i++] = '+';
		while (i < before - data->conv_sz)
			final[i++] = ' ';
		if (after == 0)
		{
			data->f |= F0;
			final[i++] = ' ';
		}
	}
	return (final);
}

static char		*ft_ap_neg(int before, int after, char *final, t_data *data)
{
	int		i;
	int		surplus;

	i = 0;
	surplus = (data->f & F_SHARP) ? 2 : 0;
	while (before-- > after + surplus)
		final[i++] = ' ';
	if (data->f & F_PLUS)
		final[i - 1] = '+';
	if (data->f & F_SHARP)
	{
		final[i++] = '0';
		final[i++] = 'x';
	}
	if (data->f & F_S_0)
	{
		while (after-- > data->conv_sz)
			final[i++] = ' ';
	}
	else
	{
		while (after-- > data->conv_sz)
			final[i++] = '0';
	}
	return (final);
}

char			*ft_case3(char *final, int before, int after, t_data *data)
{
	int		surplus;
	int		i;

	i = 0;
	surplus = 0;
	if (!(data->f & AP_NEG))
	{
		if (!(final = ft_ap_neg(before, after, final, data)))
			return (NULL);
	}
	else if (data->f & AP_NEG)
	{
		while (before-- > after + 1)
			final[i++] = ' ';
		final[i++] = '-';
		while (after-- > data->conv_sz)
			final[i++] = '0';
	}
	return (final);
}
