/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/03 12:40:25 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octal(t_data *data)
{
	char				*final;
	char				*tmp;
	unsigned long long	ap;

	(void)ap;
	data->flag |= F_UNSIGNED;
	tmp = ft_conv_hhhlll_u(data, 8);
	if ((data->flag & F_SHARP) && (ft_strcmp(tmp, "0") != 0))
	{
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
		final = tmp;
	data->conv_sz = ft_strlen(final);
	return (final);
}

char	*ft_hexa(t_data *data)
{
	char			*final;
	int				ap;
	char			*tmp;

	data->flag |= F_UNSIGNED;
	ap = (va_arg(data->ap, int));
	if (ap < 0)
		data->flag |= AP_NEG;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && (ap != 0))
	{
		tmp = ft_itoa_base_mode(ap, 16, 1);
		{
			if (!(final = ft_strjoin("0x", tmp)))
				return (NULL);
		}
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 16, 1)))
			return (NULL);
	}
	data->conv_sz = ft_strlen(final);
	return (final);
}

char	*ft_caps_x(t_data *data)
{
	char			*final;
	int				ap;
	char			*tmp;

	data->flag |= F_UNSIGNED;
	ap = (va_arg(data->ap, int));
	if (ap < 0)
		data->flag |= AP_NEG;
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && (ap != 0))
	{
		tmp = ft_itoa_base_mode(ap, 16, 2);
		if (!(final = ft_strjoin("0X", tmp)))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 16, 2)))
			return (NULL);
	}
	data->conv_sz = ft_strlen(final);
	return (final);
}
