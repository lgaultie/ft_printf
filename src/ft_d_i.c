/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:11 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/14 19:08:29 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_data *data)
{
	int		ap;
	int		ap_sz;
	char	*final;

	ap = (va_arg(data->ap, int));
	ap_sz = ft_intlen(ap);
	if (!(final = malloc(sizeof(char) * (ap_sz + 1))))
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
	if (!(final = malloc(sizeof(char) * (ap_sz + 1))))
		return (NULL);
	final = ft_itoa_base(ap, 10, 1);
	return (final);
}
