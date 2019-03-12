/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:06 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/12 16:59:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** ft_next_p100_i
** Used to get size from index [0] to the next conversion
** mode 0 : size untouched.
** mode 1 : size with %% understood as %.
** mode 2 : index of next %.
*/

char	*ft_jean_connard(char *flags, t_data *data)
{
	int		len;
	char	*final;

	len = data->flag_sz - 1;
	if (flags[len] == 'd' || flags[len] == 'i' || flags[len] == 'f')
	{
		final = ft_conv_dif(flags, data);
	}
	else if (flags[len] == 's')
	{
		final = ft_jonh_claude(flags, data);
	}
	// if (flags[len] == 'c' || flags[len] == 's')
	// 	ft_conv_cs(flags, data);
	// if (flags[len] == 'o' || flags[len] == 'x' || flags[len] == 'X')
	// 	ft_conv_oxX(flags, data);
	// if (flags[len] == 'p')
	// 	ft_conv_p(flags, data);
	// if (flags[len] == 'u')
	// 	ft_conv_u(flags, data);
	else
		final = (NULL);
//	ft_putstr("avant return\n");
	return (final);
}

char	*ft_got_flag(char *str, t_data *data)
{
	int		x;
	char	*flags;
	char	*final;
	/* IDEE :
		ici, au lieu de chercher directement des conv qu'on connait, on peut chercher un char compris entre 65 et 90 (Maj) et entre 97 et 122 (minuscules). Pour les flags (hh, h, l, ll), verifier le char suivant
	*/

	x = 0;
	while (str[x] != 'c' && str[x] != 's' && str[x] != 'p' && str[x] != 'd' \
		&& str[x] != 'i' && str[x] != 'o' && str[x] != 'u' \
		&& str[x] != 'x' && str[x] != 'X' && str[x] != 'f')
	{
		x++;
	}
	data->flag_sz = x + 1;

	//printf("flag_sz : %d\n", data->flag_sz);
	if (!(flags = malloc(sizeof(char) * (data->flag_sz + 1))))
		return (NULL);
	flags = ft_strncpy(flags, str, data->flag_sz);
	if ((final = ft_jean_connard(flags, data)) == NULL)
		return (NULL);
	free(flags);
//	printf("got flag return : |%s|\n", final);
	return (final);
}

int		ft_print_format(char *format, t_data *data)
{
	int		len;
	int		i;

	i = 0;
	while (format[i] == '%' && format[i + 1] == '%')
	{
		ft_putstr("%");
		i = i + 2;
	}
	if (!(data->buf = ft_next_p100(&format[i], data)))
        return (-1);
	data->buf = ft_analyse(&format[i], data);
	ft_putstr(data->buf);
	len = ft_strlen(data->buf);
	free(data->buf);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int			len;
	t_data		*data;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	va_start(data->ap, format);
	len = ft_print_format((char*)format, data);
	va_end(data->ap);
	free(data);
	return (len);
}
