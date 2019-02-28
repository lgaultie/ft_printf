/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:41:45 by lgaultie          #+#    #+#             */
/*   Updated: 2019/02/28 14:54:56 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	int			
	va_list		arg;


	va_start(ap, format);
	while (format[i] != '%')
		i++;
	if (format[i + 1] == d)
		va_arg(arg, int);
	if (format[i + 1] == s)
		va_arg(arg, char *);
	if (format[i + 1] == c)
		va_arg(arg, int);
	if (format[i + 1] == p)
		va_arg(arg, void *);
	//on envoie arg j'sais pas ou
	va_end(arg);
	return (
}
