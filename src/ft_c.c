/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:40:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 21:35:53 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_char_0:
** Enables needed flag when ap == 0 and save the index of the character.
*/

static void		ft_char_0(t_data *data)
{
	int nb_0;

	nb_0 = 0;
	if (data->f & F_C_02)
		nb_0 = (data->i_0[0] + 1);
	else
	{
		if (!(data->i_0 = ft_memalloc(sizeof(int) * 100)))
			return ;
		nb_0 = 1;
	}
	data->i_0[0] = nb_0;
	data->i_0[nb_0] = ft_strlen(data->buf);
	data->f |= F_C_02;
}

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
		data->f |= F_AP_0;
		final[0] = 0;
		final[1] = '\0';
		ft_char_0(data);
	}
	else
	{
		final[0] = ap;
		final[1] = '\0';
	}
	data->conv_sz = 1;
	return (final);
}
