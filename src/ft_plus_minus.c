/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:13:41 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/22 11:32:20 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_plus: when flag PLUS and MINUS are both activated, it decides which one
** is to be printed or not.
*/

char	*ft_plus(char *flag, t_data *data)
{
	char	*final;

	(void)flag;
	(void)data;
	if (data->f & F_PLUS_MINUS)
	{
		if (!(final = ft_strdup("-")))
			return (NULL);
	}
	else if (!(data->f & AP_NEG))
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

/*
** ft_minus: is called by which_flag file.
*/

char	*ft_minus(char *flag, t_data *data)
{
	char	*final;

	(void)flag;
	free(data->tmp_s);
	if (!(final = ft_strnew(0)))
		return (NULL);
	return (final);
}
