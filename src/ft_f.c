/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/12 00:37:03 by amamy            ###   ########.fr       */
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

char	*ft_conv_f(t_data *data)
{
	float	ap;
	float	f_decimal;
	int		integer;
	int		decimal;
	char	*before;
	// char	*final;

	ap = (va_arg(data->ap, double));
	if (!(before = ft_itoa(ap)))
		return (NULL);
	f_decimal = ap - (int)ap;
	decimal = 0;
	integer = ap;
	ap -= integer;
	printf("ap : %f\n", ap);
	printf("f_deci : %f\n", f_decimal);
	// if (ap != 0)
	// {
	// 	ap *= 10;
	// 	ft_putstr("lol\n");
	// }
	// while ((ap - f_decimal) != 0.0)
	// {
	// 		printf("%d\n", decimal);
	// 	ap *= 10;
	// 	decimal = ap;
	// }

		ap *= 10;
		decimal = ap;
		printf("ap : %f\n", ap);
		printf("decimal : %d\n", decimal);
		ap *= 10;
		decimal = ap;
		printf("ap : %f\n", ap);
		printf("decimal : %d\n", decimal);
		ap *= 10;
		decimal = ap;
		printf("ap : %f\n", ap);
		printf("decimal : %d\n", decimal);

		printf("ap - f_deci : %f", (ap - f_decimal));
	// if (!(before = ft_itoa((long long)ap)))
	// 	return (NULL);

	//final = ft_strjoin(before, ".");

	//final = ft_strjoin(final, "64543");		//Lololol
	return (before);
}
