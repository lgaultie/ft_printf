/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/08 21:37:54 by lgaultie         ###   ########.fr       */
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
	if ((data->f & F_SHARP) && (ft_strcmp(tmp, "0") != 0))
	{
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
		final = tmp;
	data->conv_sz = ft_strlen(final);
	if (ft_strcmp(tmp, "0") == 0)
	{
		if ((data->f & F_SHARP) && ((data->f & F_PRECIS) \
		|| data->f & F_WIDTH))
		{
			free(tmp);
			return (ft_strdup("0"));
		}
		if (((data->f & F_SHARP) || (data->f & F_PRECIS)) \
		&& !(data->f & F_WIDTH))
		{
			free(tmp);
			return (ft_strdup(""));
		}
		if ((data->f & F_SHARP) || (data->f & F_W_P))
		{
			free(tmp);
			return (ft_strdup(" "));
		}
	}
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
	tmp = ft_conv_hhhlll_u(data, 16, mode);
	if ( tmp[0] != '0' && tmp[1] != '\0' && (data->f & F_SHARP) \
	&& !(data->f & F_PRECIS) \
	&& !(data->f & F_W_P) && !(data->f & F_ZERO))
	{
		if (mode == 1)
			if (!(final = ft_strjoin("0x", tmp)))
				return (NULL);
		if (mode == 2)
			if (!(final = ft_strjoin("0X", tmp)))
				return (NULL);
		free(tmp);
	}
	else
		final = tmp;
	data->conv_sz = ft_strlen(final);
	if (ft_strcmp(tmp, "0") == 0)
	{
		if ((data->f & F_SHARP) && !(data->f & F_PRECIS))
		{
			free(tmp);
			return (ft_strdup("0"));
		}
		if ((data->f & F_SHARP) || (data->f & F_PRECIS))
		{
			free(tmp);
			return (ft_strdup(""));
		}
		if ((data->f & F_SHARP) || (data->f & F_W_P))
		{
			free(tmp);
			return (ft_strdup(" "));
		}
	}
	return (final);
}
