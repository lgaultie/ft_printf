/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/19 14:41:51 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*ft_analyse_flags(char *flags, t_data *data)
{
	int		len;
	char	*final;

	final = NULL;
	len = data->flag_sz;
	if (len == 1)
		final = ft_only_conv(flags, data);
	else
		final = ft_flag_conv(flags, data);
	return (final);
}

char	*ft_got_flag(char *str, t_data *data)
{
	int		x;
	char	*flags;
	char	*final;

	/* IDEE :
		ici, au lieu de chercher directement des conv qu'on connait, on peut chercher
		un char compris entre 65 et 90 (Maj) et entre 97 et 122 (minuscules). Pour
		les flags (hh, h, l, ll), verifier le char suivant
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
	if ((final = ft_analyse_flags(flags, data)) == NULL)
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
