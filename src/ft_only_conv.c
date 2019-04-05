/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:45:40 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/05 15:28:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_p100: handles the %% case.
*/

static char		*ft_p100(t_data *data)
{
	char	*final;

	data->conv_sz = 1;
	data->conv_t_sz += data->conv_sz;
	if (!(final = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	final[0] = '%';
	final[1] = '\0';
	return (final);
}

/*
** ft_only_conv1,2,3: call the appropriate function for each conversion,
** and returns the converted sentence.
*/

static char		*ft_only_conv3(char *flags, t_data *data)
{
	char	*final;

	if (flags[0] == 'o')
	{
		if (!(final = ft_octal(data)))
			return (NULL);
	}
	else if (flags[0] == 'x')
	{
		if (!(final = ft_hexa(data, 1)))
			return (NULL);
	}
	else if (flags[0] == 'X')
	{
		if (!(final = ft_hexa(data, 2)))
			return (NULL);
	}
	else if (flags[0] == '%')
	{
		if (!(final = ft_p100(data)))
			return (NULL);
	}
	else
		final = NULL;
	return (final);
}

static char		*ft_only_conv2(char *f, t_data *data)
{
	char	*final;

	if (f[0] == 'u')
	{
		if (!(final = ft_conv_u(data)))
			return (NULL);
	}
	else if (f[0] == 'p')
	{
		if (!(final = ft_conv_p(data)))
			return (NULL);
	}
	else if (f[0] == 'c')
	{
		if (!(final = ft_char(data)))
			return (NULL);
	}
	else if (f[0] == 'o' || f[0] == 'x' || f[0] == 'X' || f[0] == '%')
	{
		if (!(final = ft_only_conv3(f, data)))
			return (NULL);
	}
	else
		final = NULL;
	return (final);
}

char			*ft_only_conv(char *flags, t_data *data)
{
	char	*final;

	if (flags[0] == 'd' || flags[0] == 'i' || flags[0] == 'f')
	{
		if (!(final = ft_conv_di(data)))
			return (NULL);
	}
	else if (flags[0] == 's')
	{
		if (!(final = ft_string(flags, data, 0)))
			return (NULL);
	}
	else if (flags[0] == 'u' || flags[0] == 'c' || flags[0] == 'o' \
	|| flags[0] == 'x' || flags[0] == 'X' || flags[0] == 'p' || flags[0] == '%')
	{
		if (!(final = ft_only_conv2(flags, data)))
			return (NULL);
	}
	else
		final = NULL;
	return (final);
}
