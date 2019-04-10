/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/10 17:53:10 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_f(t_data *data)
{
	float	ap;
	char	*before;
	char	*final;

	ap = (va_arg(data->ap, double));
	if (!(before = ft_itoa((long long)ap)))
		return (NULL);
	final = ft_strjoin(before, ".");
	//printf("before = %s      ap = %f\n",before, ap);

	final = ft_strjoin(final, "645353");//Lololol
	return (final);
}
