/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:05:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/13 19:14:52 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	// printf("ap original = %f\n", ap);
	if (!(before = ft_itoa(ap)))
		return (NULL);
	tmp = before;
	if (!(before = ft_strjoin(tmp, ".")))
		return (NULL);
	free(tmp);
	if (ap < 0)
		ap = -ap;
	ret = ap - (int)ap;
	after = ret;
	// printf("after = %d   v ret = %f \n", after, ret);
	while ((ap - (int)ap) != 0.0 && (ap - (int)ap) > 0.0 && j < 6)
	{
		ret = ret * 10;
		after = ret;
		if (j == 0)
		{
			if (!(str_after = ft_itoa(after)))
			{
				free(before);
				return (NULL);
			}
		}
		else
		{
			if (j > 1)
				free(str_after_copy);
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
	if (j > 0)
		free(str_after);
	if (j > 1)
		free(str_after_copy);
	data->ap_sz = ft_strlen(final);
	data->conv_sz = ft_strlen(final);
	data->f |= FLOAT;
	return (final);
}
