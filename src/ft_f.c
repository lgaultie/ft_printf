/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/11 23:49:49 by lgaultie         ###   ########.fr       */
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
// 	printf("before = %d  size_before = %d   position = %d\n", before, size_before, position);
// 	printf("n = %f     n_copy = %f     nb copie en int = %d      nb en float = %f\n", n, n_copy, nb, (float)nb);
//
// 	size = size_before + 6 + 1;
// 	if (sign == 1)
// 	{
// 		size++;
// 		position++;
// 	}
// 	while (n_copy - (float)nb != 0.0 && n_copy - (float)nb > 0.0 && i < size)
// 	{
// 		if (i == position)
// 			str[i] = '.';
// 		else if (i == size)
// 			str[i] = '\0';
// 		else if (i == 0 && sign == 1)
// 			str[i] = '-';
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
	char	*before;
	float	ret;
	int		after;
	char	*str;
	int		i;
	char	*final;

	ap = (va_arg(data->ap, double));

	if (!(before = ft_itoa(ap)))
		return (NULL);


	before[ft_strlen(before)] = '.';	//a faire plus proprement pour le malloc


	ret = ap - (int)ap;
	i = ap;
	ret = ret * 10;
	after = ret;
	// printf("after = %d     ret = %f\n",after, ret);
	// printf("ap = %f, (float)i = %f\n   ap - (float)ap = %f\n", ap, (float)i, ap - (int)ap);
	while (after != 0.0 && after > 0.0 && (ap - (int)ap) != 0.0 \
	&& (ap - (int)ap) > 0.0)
	{
		ret = ret * 10;
		ap = ret;
	}
	after = (int)ret;

	if (!(str = ft_itoa(after)))
	{
		free(before);
		return (NULL);
	}
	//printf("ret = %f     before = %s    str = %s    after = %d \n",ret, before, str, after);
	if (!(final = ft_strjoin(before, str)))
	{
		free(before);
		free(str);
		return (NULL);
	}
	free(before);
	free(str);
	return (final);
}
