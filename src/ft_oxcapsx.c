/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxcapsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:12:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/03 18:41:55 by amamy            ###   ########.fr       */
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
	tmp = ft_conv_hhhlll_u(data, 8, 1);
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

/*
** ft_hexa :
** Called from ft_only_conv for conv x ans X, mode 1 is x, mode 2 is X
*/

char	*ft_hexa(t_data *data, int mode)
{
	char				*final;
	char				*tmp;

	data->flag |= F_UNSIGNED;
	tmp = ft_conv_hhhlll_u(data, 16, mode);
	if ((data->flag & F_SHARP) && (ft_strcmp(tmp, "0") != 0))
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
	return (final);
}
