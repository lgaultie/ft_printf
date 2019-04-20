/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:08:18 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/20 14:45:29 by amamy            ###   ########.fr       */
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

char			*ft_s(char *final, int before, int after, t_data *data)
{
	char	*ap;
	char	*for_s;
	char	*tmp;
	int		i;
	int		surplus;

	i = 0;
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
		data->f |= F0;
	}
	free(final);
	if (before <= after)
	{
		if (!(final = ft_strsub(ap, 0, after)))
			return (NULL);
	}
	else if (before > after && after > data->conv_sz && !(data->f & F_S_0))
	{
		if (!(final = ft_strsub(ap, 0, after)))
			return (NULL);
	}
	else if (before > after && after < data->conv_sz && !(data->f & F_S_0))
	{
		if (!(final = ft_strsub(ap, 0, after)))
			return (NULL);
	}
	else if (before > after && (data->f & F_S_0))
	{
		if (!(final = ft_strsub(ap, 0, before)))
			return (NULL);
	}
	if (before > after)
		data->width_precis_minus = before - after;
	if (after >= before)
		data->width_precis_minus = before - data->conv_sz + 1;
	if (ap[0] == '\0' && before > after)
		data->width_precis_minus = before;
	if (ap[0] == '\0' && before <= after)
		data->width_precis_minus = after;
	if (before <= after)
	{
		if (!(for_s = ft_memalloc(sizeof(char) * after + 1)))
			return (NULL);
	}
	if (before > after)
	{
		if (!(for_s = ft_memalloc(sizeof(char) * before + 1)))
			return (NULL);
	}
	surplus = 0;
	if (data->f & F_S_0)
		surplus++;
	if (before >= after && after >= data->conv_sz)
	{
		while (i < before - data->conv_sz)
			for_s[i++] = ' ';
	}
	if (before >= after && after < data->conv_sz)
	{
		while (i < before - after)
			for_s[i++] = ' ';
	}
	if (before < after && after >= data->conv_sz)
	{
		while (i < before - data->conv_sz)
			for_s[i++] = ' ';
	}
	if (before < after && after < data->conv_sz)
	{
		while (i < before - after)
			for_s[i++] = ' ';
	}
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
		if (data->f & F_AP_0 && after == 0)
		{
			data->f |= F0;
			final[i++] = ' ';
		}
	}
	return (final);
}

static char		*ft_not_ap_neg(int before, int after, char *final, t_data *d)
{
	int		i;
	int		surplus;
	// int		overage;

	i = 0;
	surplus = (d->f & F_SHARP && !(d->f & F_X_0) && d->f & F_X) ? 2 : 0;
	// overage = (d->f & F_O && d->f & F_C_0 && (before <= 0 || after <= 0)) ? 2 : 0;
	// while (before-- > (after + surplus + overage))
	if (before && !after && d->f & F_O)
		before--;
	while (before-- > (after + surplus))
		final[i++] = ' ';
	if (d->f & F_PLUS)
		final[i - 1] = '+';
	if (d->f & F_SHARP && !(d->f & F_X_0) && d->f & F_X)
	{
		final[i++] = '0';
		if (d->f & F_BIG_X)
			final[i++] = 'X';
		else
			final[i++] = 'x';
	}
	if (d->f & F_S_0 || d->f & F_S)
		while (after-- > d->conv_sz)
			final[i++] = ' ';
	else
		// while ((overage + after--) > d->conv_sz)
		while (after-- > d->conv_sz)
			final[i++] = '0';
	return (final);
}

char			*ft_case3(char *final, int before, int after, t_data *data)
{
	int		surplus;
	int		i;

	i = 0;
	surplus = 0;
	if (data->f & F_S)
		return (ft_s(final, before, after, data));
	if (!(data->f & AP_NEG)) //&& !(data->f & F_UNSIGNED))
	{
		if (!(final = ft_not_ap_neg(before, after, final, data)))
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
