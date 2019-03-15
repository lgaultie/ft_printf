/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_x_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:58:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/15 15:40:16 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base_mode(unsigned int value, unsigned int base, int mode)
{
	char			*str;
	char			*tab;
	unsigned int	tmp;
	int				size;

	size = 0;
	if (mode == 1)
		tab = "0123456789abcdef";
	else if (mode == 2)
		tab = "0123456789ABCDEF";
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}

char	*ft_octal(t_data *data)
{
	char			*final;
	unsigned int	ap;

	ap = (va_arg(data->ap, int));
	final = ft_itoa_base_mode(ap, 8, 1);
	return (final);
}

char	*ft_hexa(t_data *data)
{
	char			*final;
	unsigned int	ap;

	ap = (va_arg(data->ap, int));
	final = ft_itoa_base_mode(ap, 16, 1);
	return (final);
}

char	*ft_caps_x(t_data *data)
{
	char			*final;
	unsigned int	ap;

	ap = (va_arg(data->ap, int));
	final = ft_itoa_base_mode(ap, 16, 2);
	return (final);
}
