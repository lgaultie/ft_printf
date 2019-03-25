/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:51:16 by lgaultie          #+#    #+#             */
/*   Updated: 2019/03/25 18:24:12 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_d2(t_data *data, char *ret, int accuracy)
{
	int		i;

	i = 0;
	if (accuracy <= data->ap_sz)
	{
		if (data->flag & F_PLUS)
			return (ft_strdup("+"));
		return (ft_strdup(""));
	}
	else
	{
		if (!(ret = ft_memalloc(sizeof(char) * (accuracy + 1))))
			return (NULL);
		if (data->flag & F_PLUS)
		{
			ret[i] = '+';
			i++;
			while (i < accuracy - data->ap_sz + 1)
				ret[i++] = '0';
		}
		else
		{
			if (data->flag & F_MINUS)
			{
				ret[i++] = '-';
				while (i < accuracy - data->ap_sz + 1)
					ret[i++] = '0';
			}
			else
			{
				while (i < accuracy - data->ap_sz)
					ret[i++] = '0';
			}
		}
	}
	ret[i] = '\0';
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

	i = 0;
	j = 0;
	if (flags[1] == '*')
	{
		i = data->tmp;
		data->flag &= ~F_PRECIS & ~F_STAR;
	}
	else
	{
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))	//flag_size + 1 - 2 pour le % et d
			return (NULL);
		printf("flags = %s\n", flags);
		while (flags[i] < '0' || flags[i] > '9')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9')
		{
			while (flags[i] == '.' || flags[i] == '*')
				i++;
			if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
				return (NULL);
			while (flags[i] >= '0' && flags[i] <= '9')
					conv[j++] = flags[i++];
			conv[j] = '\0';
			i = ft_atoi(conv);
			free(conv);
		}
	}
	ret = NULL;
	if (!(ret = ft_precision_d2(data, ret, i)))
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
	if (flags[1] == '*')
	{
		i = data->tmp;
		data->flag &= ~F_PRECIS & ~F_STAR;
	}
	else
	{
		while (flags[i] <= '0' && flags[i] >= '9')
			i++;
		if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
			return (0);
		while (flags[i] < '0' || flags[i] > '9')
				conv[j++] = flags[i++];
		i = ft_atoi(conv);
		free(conv);
	}
	if (i < data->ap_sz)
		return (i);
	return (data->ap_sz);
}

char	*ft_preci_width2(int before, int after, t_data *data)
{
	int		i;
	char	*final;
	int		minus;

	i = 0;
	minus = 0;
	if (data->flag & F_MINUS)
		minus = 1;
	if (!(final = malloc(sizeof(char) * (before + after + data->ap_sz + 1))))
		return (NULL);
	if (before == after || before < after)
	{
		if (data->flag & F_PLUS)
		{
			final[i++] = '+';
			while (i < after - data->ap_sz + 1)
				final[i++] = '0';
		}
		else
		{
			while (i < after - data->ap_sz)
				final[i++] = '0';
		}
	}
	if (after < data->ap_sz && before > after)
	{
		if (data->flag & F_PLUS)
			final[i++] = '+';
		while (i < before - data->ap_sz)
			final[i++] = ' ';
	}
	if ((after > data->ap_sz && before > after) || (after == data->ap_sz))
	{
		if (minus == 0)
		{
			while (before > after)
			{
				final[i++] = ' ';
				before--;
			}
		}
		if (data->flag & F_PLUS)
			final[i - 1] = '+';
		while (after > data->ap_sz)
		{
			final[i++] = '0';
			after--;
		}
	}
	final[i] = '\0';
	return (final);
}

char	*ft_preci_width(char *flag, t_data *data)
{
	int		i;
	int		j;
	char	*final;
	char	*before;
	char	*after;

	i = 0;
	j = 0;
	if (!(before = malloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	if (!(after = malloc(sizeof(char) * data->flag_sz + 1)))
		return (NULL);
	while (flag[i] < '0' || flag[i] > '9')
		i++;
	while (flag[i] != '.')
		before[j++] = flag[i++];
	before[j] = '\0';
	j = 0;
	i++;
	while (flag[i + 1] != '\0')
		after[j++] = flag[i++];
	after[j] = '\0';
	i = ft_atoi(before);
	j = ft_atoi(after);
	free(before);
	free(after);
	if (!(final = ft_preci_width2(i, j, data)))
		return (NULL);
	return (final);
}
