/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/15 15:22:37 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*ft_p100(t_data *data)
{
	data->conv_sz = 1;
	data->conv_t_sz += data->conv_sz;
	return ("%");
}

char	*ft_jean_connard(char *flags, t_data *data)
{
	int		len;
	char	*final;

	len = data->flag_sz - 1;
	if (flags[len] == 'd' || flags[len] == 'i' || flags[len] == 'f')
		final =	ft_conv_di(data);
	else if (flags[len] == 's')
		final = ft_string(data);
	else if (flags[len] == '%')
		final = ft_p100(data);
	else if (flags[len] == 'p')
		final = ft_conv_p(data);
	else if (flags[len] == 'u')
	 	final = ft_conv_u(data);
	else if (flags[len] == 'c')
		final = ft_char(data);
	else if (flags[len] == 'o')
		final = ft_octal(data);
	else if (flags[len] == 'x')
		final = ft_hexa(data);
	else if (flags[len] == 'X')
	 	final = ft_caps_x(data);
	else
		final = (NULL);
	return (final);
}

char	*ft_got_flag(char *str, t_data *data)
{
	int		x;
	char	*flags;
	char	*final;

	/* IDEE :
		ici, au lieu de chercher directement des conv qu'on connait,
		on peut chercher un char compris entre 65 et 90 (Maj)
		et entre 97 et 122 (minuscules).
		Pour les flags (hh, h, l, ll), verifier le char suivant
	*/
	x = 0;
	while (str[x] != 'c' && str[x] != 's' && str[x] != 'p' && str[x] != 'd' \
		&& str[x] != 'i' && str[x] != 'o' && str[x] != 'u' && str[x] != '%'	\
		&& str[x] != 'x' && str[x] != 'X' && str[x] != 'f')
	{
		x++;
	}
	if (str[x] == '%')
		data->flag_sz = 1;
	else
		data->flag_sz = x + 1;
	if (!(flags = malloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	flags = ft_strncpy(flags, str, data->flag_sz);
	if ((final = ft_jean_connard(flags, data)) == NULL)
		return (NULL);
	free(flags);
	return (final);
}

int		ft_print_format(char *format, t_data *data)
{
	int		len;

	if (!(data->buf = ft_strnew(0)))
		return (-1);
	data->buf = ft_analyse(format, data);
	ft_putstr(data->buf);
	len = ft_strlen(data->buf);
	//free(data->buf); to uncom when not in tests
	return (len);
}

//int		ft_printf(const char *format, ...) Not for tests
char		*ft_printf(const char *format, ...) // for tests
{
	int			len;
	t_data		*data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
		//return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	//free(data); to uncom when not in tests
	//return (len); For realease
	return (data->buf);
}
