/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:08:18 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 14:26:26 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_free_all: free and return or free, join and return the converted flag.
*/

static char		*ft_free_all(char *final, char *ap, char *for_s, int mode)
{
	char	*tmp;

	if (mode == 1 || mode == 0)
	{
		free(ap);
		if (mode == 0)
			free(final);
		return (NULL);
	}
	if (mode == 2)
	{
		tmp = final;
		if (!(final = ft_strjoin(for_s, tmp)))
			return (NULL);
		free(tmp);
		free(for_s);
		free(ap);
	}
	return (final);
}

/*
** ft_init_for_s: returns the converted flag. PRECIS + WIDTH on strings cases.
*/

static char		*ft_init_for_s(char *for_s, int a, int b, t_data *d)
{
	int		i;
	int		surplus;

	i = 0;
	surplus = (d->f & F_S_0) ? 0 : 1;
	if ((b >= a && a >= d->conv_sz) || (b < a && a >= d->conv_sz))
	{
		while (i < b - d->conv_sz)
			for_s[i++] = ' ';
	}
	if ((b >= a && a < d->conv_sz) || (b < a && a < d->conv_sz))
	{
		while (i < b - a)
			for_s[i++] = ' ';
	}
	return (for_s);
}

/*
** ft_init_wpm: Initialize data->width_precis_minus so we will know how much
** space or 0 is to be printed at the end of ret_conv in ft_flag_conv.
*/

static void		ft_init_wpm(int a, int b, char *ap, t_data *d)
{
	if (b > a)
		d->width_precis_minus = b - a;
	if (a >= b)
		d->width_precis_minus = b - d->conv_sz + 1;
	if (ap[0] == '\0' && b > a)
		d->width_precis_minus = b;
	if (ap[0] == '\0' && b <= a)
		d->width_precis_minus = a;
}

/*
** ft_init_final: deals with PRECIS + WIDTH on strings. Returns the final
** conversion.
*/

static char		*ft_init_final(int a, int b, char *ap, t_data *d)
{
	char	*final;

	if ((b <= a) || (b > a && a > d->conv_sz && !(d->f & F_S_0)) \
		|| (b > a && a < d->conv_sz && !(d->f & F_S_0)))
	{
		if (!(final = ft_strsub(ap, 0, a)))
			return (NULL);
	}
	else if (b > a && (d->f & F_S_0))
	{
		if (!(final = ft_strsub(ap, 0, b)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strdup("(null)")))
			return (NULL);
	}
	return (final);
}

/*
** ft_s: deals with PRECIS + WIDTH on strings. Returns the final conversion.
*/

char			*ft_s(char *final, int b, int a, t_data *d)
{
	char	*ap;
	char	*for_s;
	int		size;

	if (d->tmp_s)
	{
		if (!(ap = ft_strdup(d->tmp_s)))
			return (NULL);
		free(d->tmp_s);
	}
	else
	{
		if (!(ap = ft_strdup("(null)")))
			return (NULL);
		d->f |= F0;
	}
	free(final);
	if (!(final = ft_init_final(a, b, ap, d)))
		return (ft_free_all(final, final, final, 1));
	ft_init_wpm(a, b, ap, d);
	size = (b <= a) ? a : b;
	if (!(for_s = ft_memalloc(sizeof(char) * size + 1)))
		return (ft_free_all(final, final, final, 0));
	for_s = ft_init_for_s(for_s, a, b, d);
	return (ft_free_all(final, ap, for_s, 2));
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
** ft_case3: Deals with cases where before > after and after >= data->conv_sz.
** When ap is not negative.
*/

static char		*ft_not_ap_neg(int before, int after, char *final, t_data *d)
{
	int		i;
	int		surplus;
	// int		overage;

	i = 0;
	surplus = (d->f & F_SHARP && !(d->f & F_X_0) && d->f & F_X) ? 2 : 0;
	// overage = (d->f & F_O && d->f & F_C_0 && (before <= 0 || after <= 0)) ? 2 : 0;
	// while (before-- > (after + surplus + overage))
	if (before && !after && (d->f & F_O))
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
