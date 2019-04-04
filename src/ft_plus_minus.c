/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:13:41 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/04 14:49:06 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_plus(char *flag, t_data *data)
{
	char	*final;

	(void)flag;
	(void)data;
	if (data->flag & F_PLUS_MINUS)
	{
		if (!(final = ft_strdup("-")))
			return (NULL);
	}
	else if (!(data->flag & AP_NEG))
	{
		if (!(final = ft_strdup("+")))
			return (NULL);
	}
	else
	{
		if (!(final = ft_strnew(0)))
			return (NULL);
	}
	return (final);
}

char	*ft_minus(char *flag, t_data *data)
{
	char	*final;

	(void)flag;
	(void)data;
	final = ft_strnew(0);
	return (final);
}
