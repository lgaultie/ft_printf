/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 12:03:58 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_for_c_0: for %o conversions.
** when ap is 0, we have to return an empty string, or only a
** space or 0 depending on the flags.
*/

static char		*ft_for_c_o(char *final, t_data *d)
{
	if (((d->f & F_SHARP) && ((d->f & F_PRECIS) || d->f & F_WIDTH)) \
		|| (d->f & F_SHARP && !(d->f & F_PRECIS) && !(d->f & F_WIDTH)))
	{
		free(final);
		if (!(final = (ft_strdup("0"))))
			return (NULL);
	}
	else if ((d->f & F_SHARP || d->f & F_PRECIS) && !(d->f & F_WIDTH))
	{
		free(final);
		if (!(final = (ft_strdup(""))))
			return (NULL);
	}
	else if (((d->f & F_SHARP) || (d->f & F_W_P)))
	{
		free(final);
		if (!(final = (ft_strdup(" "))))
			return (NULL);
	}
	d->f &= ~F_C_0;
	return (final);
}

/*
** ft_octal: deals with %o cases.
*/

char			*ft_octal(t_data *d)
{
	char	*final;
	char	*tmp;

	d->f |= F_UNSIGNED;
	d->f |= F_O;
	if (!(tmp = ft_conv_hhhlll_u(d, 8, 1)))
		return (NULL);
	if ((d->f & F_SHARP) && !(d->f & F_C_0))
	{
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strdup(tmp)))
			return (NULL);
	}
	if (d->f & F_C_0)
	{
		if (!(final = ft_for_c_o(final, d)))
			return (NULL);
	}
	d->conv_sz = ft_strlen(final);
	free(tmp);
	return (final);
}

/*
** ft_join_sharp: when we have to return | 0x34234|, we have to join 0x
** on the conversion and not the flag.
*/

static char		*ft_join_sharp(char *tmp, int mode)
{
	char	*final;

	if (mode == 1)
		if (!(final = ft_strjoin("0x", tmp)))
			return (NULL);
	if (mode == 2)
		if (!(final = ft_strjoin("0X", tmp)))
			return (NULL);
	return (final);
}

/*
** ft_hexa_is_0: when ap is 0, we have to return an empty string, or only a
** space or 0 depending on the flags.
*/

static char		*ft_hexa_is_0(char *final, t_data *d)
{
	d->f |= F_X_0;
	if ((d->f & F_SHARP) && !(d->f & F_PRECIS) && !(d->f & F_W_P))
	{
		free(final);
		if (!(final = (ft_strdup("0"))))
			return (NULL);
	}
	else if (d->f & F_SHARP || d->f & F_PRECIS)
	{
		free(final);
		if (!(final = (ft_strdup(""))))
			return (NULL);
	}
	else if ((d->f & F_SHARP || d->f & F_W_P) && !(d->f & F_PRECIS))
	{
		free(final);
		if (!(final = ft_strdup(" ")))
			return (NULL);
	}
	d->f &= ~F_C_0;
	return (final);
}

/*
** ft_hexa :
** Called from ft_only_conv for conv x ans X, mode 1 is x, mode 2 is X
*/

char			*ft_hexa(t_data *d, int mode)
{
	char	*final;
	char	*tmp;

	d->f |= F_UNSIGNED;
	d->f |= F_X;
	if (!(tmp = ft_conv_hhhlll_u(d, 16, mode)))
		return (NULL);
	if (!(d->f & F_C_0) && (d->f & F_SHARP) && !(d->f & F_PRECIS) \
		&& !(d->f & F_W_P) && !(d->f & F_ZERO))
	{
		if (!(final = ft_join_sharp(tmp, mode)))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strdup(tmp)))
			return (NULL);
	}
	if (d->f & F_C_0)
		if (!(final = ft_hexa_is_0(final, d)))
			return (NULL);
	free(tmp);
	d->conv_sz = ft_strlen(final);
	return (final);
}
