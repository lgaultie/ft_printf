/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:51:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/19 10:53:56 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_d2(t_data *data, char *ret, int accuracy)
{
	int		i;

	i = 0;
	// printf("accuracy = %d\n", accuracy);
	// printf("data->ap_sz = %d\n", data->ap_sz);
	//data->ap_sz est totalement pétée..............
	if (accuracy <= data->ap_sz)
		return ("");	//on imprime rien, osef de flag si precision < taille ap
	else
	{
		if (!(ret = malloc(sizeof(char) * (accuracy + 1))))
			return (NULL);
		while (i < accuracy - data->ap_sz)
		{
			ret[i] = '0';
			i++;
		}
	}
	ret[i] = '\0';
	//printf("ret = %s\n", ret);
	return (ret);
}

/*
** s'occupe de la precision pour d: converti les chiffres de .123 en int,
** pour ensuite ecrire dans une str malloquée le bon nombre de '0'.
** C'est a dire 123 - ag_sz zeros.
*/

char	*ft_precision_d(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;
	char	*ret;
	int		accuracy;

	i = 0;
	j = 0;
	if (!(conv = malloc(sizeof(char) * (data->flag_sz - 1))))	//flag_size + 1 - 2 pour le % et d
		return (NULL);
	//printf("flags = %s\n", flags);
	while (flags[i] == '%' || flags[i] == '.')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
	{
			conv[j] = flags[i];
			i++;
			j++;
			//printf("conv = %s\n", conv);
	}
	conv[j] = '\0';
	accuracy = ft_atoi(conv);
	free(conv);
	ret = NULL;
	if (!(ret = ft_precision_d2(data, ret, accuracy)))
		return (NULL);
	return (ret);
}

/*
** precision_s: retourne un int qui indique le nombre de caractere de l'argv
** variadique a imprimer.
*/
int		ft_precision_s(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = malloc(sizeof(char) * (data->flag_sz - 1))))
		return (0);
	while (flags[i] == '%' || flags[i] == '.')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
	{
			conv[j] = flags[i];
			i++;
			j++;
	}
	conv[j] = '\0';
	i = ft_atoi(conv);
	free(conv);
	if (i < data->ap_sz)
		return (i);
	return (data->ap_sz);
}
