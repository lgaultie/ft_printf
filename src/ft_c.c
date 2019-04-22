/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:40:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 11:03:08 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_char: Deals with %c conversion, enable needed flag when ap == 0.
*/

char			*ft_char(t_data *data)
{
	char	ap;
	char	*final;

	if (!(final = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	ap = (va_arg(data->ap, int));
	data->ap_sz = 1;
	if (ap == 0)
	{
		data->f |= F_C_0;
		final[0] = 0;
		final[1] = '\0';
		data->index_0 = ft_strlen(data->buf);
	}
	else
	{
		final[0] = ap;
		final[1] = '\0';
	}
	data->conv_sz = 1;
	return (final);
}
