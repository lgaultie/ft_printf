/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:51:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/30 16:45:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_precision_d_else2(t_data *data, char *ret, int accuracy)
{
	int		i;

	i = 0;
	if (!(ret = ft_memalloc(sizeof(char) * (accuracy + 1))))
		return (NULL);
	if (data->flag & AP_NEG)
	{
		ret[i] = '-';
		i++;
		while (i < accuracy - data->ap_sz + 1)
			ret[i++] = '0';
	}
	else if (data->flag & F_PLUS)
	{
		ret[i] = '+';
		i++;
		while (i < accuracy - data->ap_sz + 1)
			ret[i++] = '0';
	}
	else
	{
		if (data->flag & F_MINUS && (ret[i++] = '-'))
			while (i < accuracy - data->ap_sz + 1)
				ret[i++] = '0';
		else
			while (i < accuracy - data->ap_sz)
				ret[i++] = '0';
	}
	return (ret);
}

static int		ft_precision_d_else(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
		return (-1);
	while (flags[i] < '0' || flags[i] > '9')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
	{
		while (flags[i] == '.' || flags[i] == '*')
			i++;
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
			return (-1);
		while (flags[i] >= '0' && flags[i] <= '9')
			conv[j++] = flags[i++];
	}
	conv[j] = '\0';
	i = ft_atoi(conv);
	free(conv);
	return (i);
}

/*
** s'occupe de la precision pour d: converti les chiffres de .123 en int,
** pour ensuite ecrire dans une str malloquée le bon nombre de '0'.
** C'est a dire 123 - ag_sz zeros.
*/

char			*ft_precision_d(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (flags[1] == '*' && (i = data->tmp))
		data->flag &= ~F_PRECIS & ~F_STAR;
	else
		i = ft_precision_d_else(flags, data);
	conv = NULL;
	if (i <= data->ap_sz)
	{
		if (data->flag & AP_NEG)
			return (ft_strdup("-"));
		else if (data->flag & F_PLUS)
			return (ft_strdup("+"));
		return (ft_strdup(""));
	}
	else
	{
		if (!(conv = ft_precision_d_else2(data, conv, i)))
			return (NULL);
	}
	return (conv);
}

/*
** ft_precision_s: returns a int which is the number of char to print.
*/

int				ft_precision_s(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (flags[1] == '*')
	{
		i = data->tmp;
		data->flag &= ~F_PRECIS & ~F_STAR;
	}
	else
	{
		while (flags[i] <= '0' || flags[i] >= '9')
			i++;
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
			return (0);
		while (flags[i] >= '0' && flags[i] <= '9' && flags[i] != '\0')
			conv[j++] = flags[i++];
		i = ft_atoi(conv);
		free(conv);
	}
	return (i);
}
