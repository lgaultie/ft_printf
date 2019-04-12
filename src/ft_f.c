/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/12 14:18:19 by lgaultie         ###   ########.fr       */
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
	int		j;
	char	*final;
	char	*str_after;
	char	*str_after_copy;
	char	*tmp;

	j = 0;
	ap = (va_arg(data->ap, double));
	printf("ap original = %f\n", ap);
	if (!(before = ft_itoa(ap)))
		return (NULL);
	before[ft_strlen(before)] = '.';	//a faire plus proprement pour le malloc
	if (ap < 0)
		ap = -ap;
	ret = ap - (int)ap;
	after = ret;
	// printf("after = %d    ret = %f \n", after, ret);
	while ((ap - (int)ap) != 0.0 && (ap - (int)ap) > 0.0 && j < 6)
	{
		ret = ret * 10;
		after = ret;
		if (j == 0)
		{
			free(str_after);
			if (!(str_after = ft_itoa(after)))
			{
				free(before);
				return (NULL);
			}
		}
		else
		{
			if (!(str_after_copy = ft_itoa(after)))		//leaks
			{
				free(str_after);
				free(before);
				return (NULL);
			}
		}
		after = 0;
		ret = (ret - (int)ret);
		if (j != 0)
		{
			tmp = str_after;
			if (!(str_after = ft_strjoin(tmp, str_after_copy)))
				{
					free(before);
					free(str_after);
					free(str_after_copy);
					return (NULL);
				}
			free(tmp);
		}
		ap = ret;
		// printf(" ap = %f       ret = %f     str_after = %s \n", ap, ret, str_after);
		j++;
	}
	if (!(final = ft_strjoin(before, str_after)))
	{
		free(before);
		free(str_after);
		free(str_after_copy);
		return (NULL);
	}
	free(before);
	free(str_after);
	free(str_after_copy);
	return (final);
}
