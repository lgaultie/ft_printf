/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/20 19:22:43 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_data *data)
{
	int		ap;
	int		ap_sz;
	char	*final;

	if (data->flag & F_STAR && (data->flag & F_WIDTH || data->flag & F_PRECIS))
		data->tmp = (va_arg(data->ap, int));
	ap = (va_arg(data->ap, int));
	ap_sz = ft_intlen(ap);
	data->ap_sz = ap_sz;
	if (!(final = ft_memalloc(sizeof(char) * (ap_sz + 1))))
		return (NULL);
	final = ft_itoa(ap);
	return (final);
}

char	*ft_conv_u(t_data *data)
{
	unsigned int	ap;
	int				ap_sz;
	char			*final;

	ap = (va_arg(data->ap, unsigned int));
	ap_sz = ft_intlen(ap);
	data->ap_sz = ap_sz;
	if (!(final = ft_memalloc(sizeof(char) * (ap_sz + 1))))
		return (NULL);
	final = ft_itoa_base_mode(ap, 10, 1);
	return (final);
}
