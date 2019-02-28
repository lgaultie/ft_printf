/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:41:45 by lgaultie          #+#    #+#             */
/*   Updated: 2019/02/28 19:43:54 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_percent(const char *format)
{
	ft_putstr(format);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (format[i++] != '%' && format[i] != '\0')
	if (format[i] == '%')
		//len = ft_analyse(format);
		len = 1;
	else
	{
		ft_no_percent(format);
		len = ft_strlen((char *)format);
	}
	return (len);
}

int		main()
{
	ft_printf("salut");
	return (0);
}
