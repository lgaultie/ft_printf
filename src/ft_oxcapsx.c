/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/01 17:15:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octal(t_data *data)
{
	char				*final;
	unsigned long long	ap;
	char				*tmp;

	ap = ft_conv_hhhlll_u(data);
	data->ap_sz = ft_intlen(ap);
	if ((data->flag & F_SHARP) && ap != 0)
	{
		tmp = ft_itoa_b_m_ul((int)ap, 8, 1);
		if (!(final = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(final = ft_itoa_base_mode(ap, 8, 1)))
			return (NULL);
	}

	return (final);
}

char	*ft_hexa(t_data *data)
{
	char			*final;
	unsigned int	ap;
	char			*tmp;

	ap = (va_arg(data->ap, int));
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
	return (final);
}

char	*ft_caps_x(t_data *data)
{
	char			*final;
	unsigned int	ap;
	char			*tmp;

	ap = (va_arg(data->ap, int));
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
	return (final);
}
