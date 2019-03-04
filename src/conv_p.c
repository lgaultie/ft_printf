/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:57:13 by amamy             #+#    #+#             */
/*   Updated: 2019/03/04 20:19:40 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_p(char *format, t_data *data)
{
	unsigned long	ad;
	char

	(void)format;
	ft_putstr("Conv_P : ");
	ad = (va_arg(data->ap, unsigned long));
	ft_putnbr(ad);
	return (NULL);
}
