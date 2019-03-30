/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_minus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:27:33 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/30 18:58:28 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*ft_preci_width_minus3(int i, int j, t_data *data)
// {
// 	(void)data;
// 	printf("%d %d\n", i, j);
// 	return ("");
// }
//
// char	*ft_preci_width_minus2(char *flag, t_data *data, int i, int j)
// {
// 	char	*final;
// 	char	*before;
// 	char	*after;
//
// 	if (!(before = malloc(sizeof(char) * data->flag_sz + 1)))
// 		return (NULL);
// 	if (!(after = malloc(sizeof(char) * data->flag_sz + 1)))
// 		return (NULL);
// 	while (flag[i] < '0' || flag[i] > '9')
// 		i++;
// 	while (flag[i] != '.')
// 		before[j++] = flag[i++];
// 	before[j] = '\0';
// 	j = 0;
// 	i++;
// 	while (flag[i + 1] != '\0')
// 		after[j++] = flag[i++];
// 	after[j] = '\0';
// 	i = ft_atoi(before);
// 	j = ft_atoi(after);
// 	free(before);
// 	free(after);
// 	if (!(final = ft_preci_width_minus3(i, j, data)))
// 		return (NULL);
// 	return (final);
// }
//
// char	*ft_preci_width_minus(char *flag, t_data *d)
// {
// 	int		i;
// 	int		j;
// 	char	*final;
//
// 	i = 0;
// 	j = 0;
// 	if (!(final = ft_preci_width_minus2(flag, d, i, j)))
// 		return (NULL);
// 	return (final);
// }
