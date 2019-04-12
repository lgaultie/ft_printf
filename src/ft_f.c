/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/12 14:51:10 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char			*ft_itoa_float(float n)
// {
// 	char	*str;
// 	int		counter;
// 	int		sign;
// 	int		size_after;
// 	int		size_before;
// 	int		position;
// 	float	n_copy;
// 	int		size;
// 	int		i;
// 	int		nb;
// 	int		before;
//
// 	i = 0;
// 	nb = n;
// 	counter = 0;
// 	sign = 0;
// 	n_copy = n;
// 	size_after = 0;
// 	size_before = 0;
// 	if (!(str = (char*)malloc(sizeof(char) * 100)))
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		n = -1;
// 		sign = 1;
// 	}
// 	before = (int)n;
// 	size_before = ft_intlen(before);
// 	position = size_before;
// 	// while (n_copy > 1)
// 	// {
// 	// 	n_copy /= 10;
// 	// 	size_before++;
// 	// }
// 	// printf("before = %d  size_before = %d   position = %d\n", before, size_before, position);
// 	// printf("n = %f     n_copy = %f     nb copie en int = %d      nb en float = %f\n", n, n_copy, nb, (float)nb);
//
// 	size = size_before + 6 + 1;
// 	if (sign == 1)
// 	{
// 		size++;
// 		position++;
// 	}
// 	while (n != 0.0 && i < size)
// 	{
// 		if (i == position)
// 			str[i] = '.';
// 		else if (i == size)
// 			str[i] = '\0';
// 		else if (i < position)
// 		{
// 			while (n != 0.0)
// 			{
// 				str[counter] = ((int)n % 10) + 48;
// 				n = n / 10;
// 				counter--;
// 			}
// 		}
// 		else if (i > position)
// 		{
// 			while (n != 0.0)
// 			{
// 				str[counter] = ((int)n % 10) + 48;
// 				n = n / 0.1;
// 				counter--;
// 			}
// 		}
// 		i++;
// 	}
// 	return (str);
// }
// static void ft_bridge_itoa(char *decimal, int f_decimal, int mode)
// {
// 	decimal = ft_itoa((int)f_decimal, mode);
// 	ft_putstr("la\n");
// }

// char	*ft_conv_f(t_data *data)
// {
// 	float	ap;
// 	float	f_decimal;
// 	int		integer;
// 	char	*int_;
// 	char	*decimal;
// 	char	*final;
// 	int		zeros;
// 	int i;
//
//
// 	i = 0;
// 	zeros  = 0;
// 	ap = (va_arg(data->ap, double));
// 	f_decimal = ap - (int)ap;
// 	integer = (int)ap;
// 	ap -= integer;
// 	printf("ap : %f\n", ap);
// 	printf("f_deci : %f\n\n", f_decimal);
//
// 	while ((ap - (int)ap) > 0.001)
// 	{
// 		printf("f_deci = %f\nap - (int)ap : %f\n", f_decimal, (ap - (int)ap));
// 		f_decimal *= 10;
// 		ap = f_decimal;
// 		if ((int)ap == 0)
// 			zeros++;
// 	}
// 	if (!(int_ = ft_itoa(ap, 2, (ft_nb_len_base(integer, 10) + 2))))
// 		return (NULL);
// 	int_[ft_strlen(int_)] = '.';
// 	if (!(int_ = ft_itoa(ap, 2, (ft_nb_len_base(integer, 10) + 2))))
// 	return (NULL);
// 	if (!(decimal = (char*)ft_memalloc(sizeof(char) * ft_nb_len_base((int)f_decimal, 10) + 1 + zeros)))
// 		return (NULL);
// 	while (zeros-- > 0)
// 		decimal[i++] = '0';
// 	printf("i : %d\n", i);
// 	if (i != 0)
// 	{
// 		ft_putstr(decimal);
// 		ft_bridge_itoa(&decimal[i], (int)f_decimal, 2);
// 	}
// 	if (!(final = ft_strjoin(int_, decimal)))
// 		return  (NULL);
// 	return (final);
// }
