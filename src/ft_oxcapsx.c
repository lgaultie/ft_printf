/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/09 15:31:32 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octal(t_data *data)
{
	char				*final;
	char					*tmp;

	data->f |= F_UNSIGNED;
	if (!(tmp = ft_conv_hhhlll_u(data, 8, 1)))
		return (NULL);
	if ((data->f & F_SHARP) && !(data->f & F_C_0))
	{
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
	}
	else
	// else if (!(data->f & F_C_0))
		if (!(final = ft_strdup(tmp)))
			return (NULL);
	if (data->f & F_C_0)
	{
		if ((data->f & F_SHARP) && ((data->f & F_PRECIS) \
		|| data->f & F_WIDTH))
		{
			if (!(final = (ft_strdup("0"))))
				return (NULL);
		}
		else if ((data->f & F_SHARP || data->f & F_PRECIS) \
		&& !(data->f & F_WIDTH))
		{
			if (!(final = (ft_strdup(""))))
				return (NULL);
		}
		else if ((data->f & F_SHARP) || (data->f & F_W_P))
		{
			if (!(final = (ft_strdup(" "))))
				return (NULL);
		}
		data->f &= ~F_C_0;
	}
	data->conv_sz = ft_strlen(final);
	free(tmp);
	return (final);
}

/*
** ft_hexa :
** Called from ft_only_conv for conv x ans X, mode 1 is x, mode 2 is X
*/

char	*ft_hexa(t_data *d, int mode)
{
	char				*final;
	char				*tmp;

	d->f |= F_UNSIGNED;
	if (!(tmp = ft_conv_hhhlll_u(d, 16, mode)))
		return (NULL);
	if ( !(d->f & F_C_0) && (d->f & F_SHARP) \
	&& !(d->f & F_PRECIS) && !(d->f & F_W_P) && !(d->f & F_ZERO))
	{
		if (mode == 1)
			if (!(final = ft_strjoin("0x", tmp)))
				return (NULL);
		if (mode == 2)
			if (!(final = ft_strjoin("0X", tmp)))
				return (NULL);
	}
	else
	// else if (!(d->f & F_C_0))
		if (!(final = ft_strdup(tmp)))
			return (NULL);
	if (d->f & F_C_0)
	{
		if ((d->f & F_SHARP) && !(d->f & F_PRECIS))
		{
			if (!(final = (ft_strdup("0"))))
				return (NULL);
		}
		else if (d->f & F_SHARP || d->f & F_PRECIS)
		{
			if (!(final = (ft_strdup(""))))
				return (NULL);
		}
		else if ((d->f & F_SHARP || d->f & F_W_P) && !(d->f & F_PRECIS))
		{
			if (!(final = ft_strdup(" ")))
				return (NULL);
		}
	d->f &= ~F_C_0;
	}
	free(tmp);
	d->conv_sz = ft_strlen(final);
	return (final);
}
