/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:57:13 by amamy             #+#    #+#             */
/*   Updated: 2019/03/15 01:12:52 by takou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_p(t_data *data)
{
	unsigned long	ad;
	char			*final;
	char			*tmp;
	int				i;

	i = 0;
	data->conv_sz = 14;
	data->conv_t_sz += data->conv_sz;
	ad = (va_arg(data->ap, unsigned long));
	if (!(tmp = ft_strdup("0x")))
		return (NULL);
	if (!(final = ft_strjoin(tmp, ft_itoa_base(ad, 16, 2))))
		return (NULL);
	while (final[i] != '\0')
	{
		final[i] = ft_tolower(final[i]);
		i++;
	}
	return (final);
}
