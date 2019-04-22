/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwp2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:56:36 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 15:44:43 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_case3: Deals with cases where before > after and after >= data->conv_sz.
** When ap is not negative.
*/

static char		*ft_not_ap_neg(int before, int after, char *final, t_data *d)
{
	int		i;
	int		surplus;

	i = 0;
	surplus = (d->f & F_SHARP && !(d->f & F_X_0) && d->f & F_X) ? 2 : 0;
	before = (before && !after && d->f & F_O) ? before-- : before;
	if (after + surplus == 0)
		before = before - d->conv_sz;
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
		while (after-- > d->conv_sz)
			final[i++] = '0';
	return (final);
}

/*
** ft_case3: Deals with cases where before > after and after >= data->conv_sz.
*/

char			*ft_case3(char *final, int before, int after, t_data *data)
{
	int		surplus;
	int		i;

	i = 0;
	surplus = 0;
	if (data->f & F_S)
		return (ft_s(final, before, after, data));
	if (!(data->f & AP_NEG))
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

/*
** ft_case2: Deals with cases where before > after and after < data->conv_sz.
*/

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

/*
** ft_case1: Deals with cases where before == or < after.
*/

char			*ft_case1(char *final, int i, int after, t_data *data)
{
	if (data->f & AP_NEG)
	{
		final[i++] = '-';
		while (i < after - data->conv_sz + 1)
			final[i++] = '0';
	}
	else if (data->f & F_PLUS)
	{
		final[i++] = '+';
		while (i < after - data->conv_sz + 1)
			final[i++] = '0';
	}
	else
	{
		while (i < after - data->conv_sz)
			final[i++] = '0';
	}
	return (final);
}
