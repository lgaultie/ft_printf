/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_width_accuracy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:52:37 by amamy             #+#    #+#             */
/*   Updated: 2019/04/22 11:54:12 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_float_w_a(t_data *d, t_float *ft, char *flag)
{
	int		accuracy;
	int		i;
	char	*tmp;

	ft->width = 0;
	accuracy = 0;
	i = 0;
	if (!(tmp = ft_memalloc(sizeof(char) * (d->flag_sz - 1))))
		return (-1);
	while (flag[i] >= '0' && flag[i] <= '9')
		tmp[ft->width++] = flag[i++];
	ft->width = ft_atoi(tmp);
	free(tmp);
	accuracy = ft_accuracy_size(&flag[i], d);
	return (accuracy);
}

char	*ft_float_w_a_width(char *final, t_float *ft, t_data *d)
{
	char	*tmp;
	char	*tmp2;
	int		diff;
	int		len;

	len = (final) ? ft_strlen(final) : 0;
	if (ft->width < 0)
		d->f &= ~F_W_P;
	if (len > ft->width)
		return (final);
	else
		diff = ft->width - len;
	if (!(tmp = ft_memalloc(sizeof(char) * (ft->width + 1))))
		return (NULL);
	while (diff-- > 0)
		tmp[diff] = ' ';
	tmp2 = final;
	if (!(final = ft_strjoin(tmp, tmp2)))
	{
		ft_free(ft, 0, 2);
		return (NULL);
	}
	free(tmp);
	free(tmp2);
	return (final);
}
