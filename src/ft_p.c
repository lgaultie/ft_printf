/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:57:13 by amamy             #+#    #+#             */
/*   Updated: 2019/04/10 16:50:54 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_freetmpitoa(char *tmp, char *ret_itoa)
{
	free(tmp);
	free(ret_itoa);
}

char			*ft_conv_p(t_data *data)
{
	unsigned long	ad;
	char			*final;
	char			*tmp;
	int				i;
	char			*ret_itoa;

	i = 0;
	data->conv_sz = 14;
	data->conv_t_sz += data->conv_sz;
	ad = (va_arg(data->ap, unsigned long));
	data->ap_sz = 15;
	if (!(tmp = ft_strdup("0x")))
		return (NULL);
	if (!(ret_itoa = ft_itoa_base(ad, 16)))
		return (NULL);
	if (!(final = ft_strjoin(tmp, ret_itoa)))
	{
		ft_freetmpitoa(tmp, ret_itoa);
		return (NULL);
	}
	while (final[i++] != '\0')
		final[i] = ft_tolower(final[i]);
	ft_freetmpitoa(tmp, ret_itoa);
	return (final);
}
