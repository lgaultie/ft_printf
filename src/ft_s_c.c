/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:03 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/20 14:59:26 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(t_data *data)
{
	char	*ap;
	char	*final;

	ap = (va_arg(data->ap, char*));
	data->ap_sz = ft_strlen(ap);
	if (!(final =  ft_memalloc(sizeof(char) * (data->ap_sz + 1))))
		return (NULL);
	final = ap;
	return (final);
}

char	*ft_char(t_data *data)
{
	char	ap;
	char	*final;
	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (!(final =  ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	final[0] = ap;
	final[1] = '\0';
	return (final);
}
