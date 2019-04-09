/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/09 14:09:55 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octal(t_data *data)
{
	char				*final;
	char				*tmp;
	unsigned long long	ap;

	(void)ap;
	data->f |= F_UNSIGNED;
	if (!(tmp = ft_conv_hhhlll_u(data, 8, 1)))
		return (NULL);
	if ((data->f & F_SHARP) && !(data->f & F_C_0))
	{
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
	}
	else if (!(data->f & F_C_0))
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

char	*ft_hexa(t_data *data, int mode)
{
	char				*final;
	char				*tmp;

	data->f |= F_UNSIGNED;
	if (!(tmp = ft_conv_hhhlll_u(data, 16, mode)))
		return (NULL);
	if (tmp[0] != '0' && tmp[1] != '\0' && (data->f & F_SHARP) \
	&& !(data->f & F_PRECIS) && !(data->f & F_W_P) && !(data->f & F_ZERO))
	{
		if (mode == 1)
			if (!(final = ft_strjoin("0x", tmp)))
				return (NULL);
		if (mode == 2)
			if (!(final = ft_strjoin("0X", tmp)))
				return (NULL);
		// free(tmp);
	}
	else
		data->f |= B_DONE;
	if (tmp[0] == '0' && tmp[1] == '\0' && (data->f & F_SHARP) \
	&& !(data->f & F_PRECIS))
	{
		if (!(final = (ft_strdup("0"))))
			return (NULL);
	}
	else if (tmp[0] == '0' && tmp[1] == '\0' && ((data->f & F_SHARP) \
	|| data->f & F_PRECIS))
	{
		if (!(final = (ft_strdup(""))))
			return (NULL);
	}
	else if (tmp[0] == '0' && tmp[1] == '\0' && (data->f & F_SHARP \
	|| data->f & F_W_P) && !(data->f & F_PRECIS))
	{
			if (!(final = ft_strdup(" ")))
			return (NULL);
	}
	else if (data->f & B_DONE)
	{
		data->f &= ~ B_DONE;
		final = ft_strdup(tmp);
	}
	free(tmp);
	data->conv_sz = ft_strlen(final);
	return (final);
}
