/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:19:57 by amamy             #+#    #+#             */
/*   Updated: 2019/04/13 23:16:49 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_accuracy_size(char *flags, t_data *data)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	if (!(conv = ft_memalloc(sizeof(char) * (data->flag_sz - 1))))
		return (-1);
	while ((flags[i] < '0' || flags[i] > '9') && flags[i] != '\0')
		i++;
	while ((flags[i] >= '0' && flags[i] <= '9') && flags[i] != '\0')
	{
		while (flags[i] == '.' || flags[i] == '*')
			i++;
		while (flags[i] >= '0' && flags[i] <= '9')
			conv[j++] = flags[i++];
	}
	if (conv[0] == '\0')
		i = 0;
	else
		i = ft_atoi(conv);
	free(conv);
	return (i);
}


char *ft_float_accuracy(t_data *d, char *flag, char *str_after)
{
	char *final;
	char *tmp;
	int diff;
	int	i;
	int len;

	len = ft_strlen(str_after);
	i = ft_accuracy_size(flag, d);
	diff = i - len;
	i = 0;
	if (!(final = ft_memalloc(sizeof(char) * (diff + 1))))
		return (NULL);
	while (diff-- > 0)
		final[i++] = '0';
	tmp = final;
	if (!(final = ft_strjoin(str_after, tmp)))
		return (NULL);
	free (tmp);
	return (final);

}

void ft_free(char * bef, char *str_after, char *str_a_cp, int m)
{
	if (m == 1)
	{
		free(str_after);
		free(bef);
	}
	if (m == 2)
	{
		free(bef);
		free(str_after); // to not do if j == 0
		free(str_a_cp);
	}
}

char	*ft_missing_zeros(int len, char *str_after)
{
	char *final;
	char *tmp;
	int diff;
	int	i;

	diff = 6 - len;
	i = 0;
	if (!(final = ft_memalloc(sizeof(char) * (diff + 1))))
		return (NULL);
	while (diff-- > 0)
		final[i++] = '0';
	tmp = final;
	if (!(final = ft_strjoin(str_after, tmp)))
		return (NULL);
	free (tmp);
	return (final);
}

char	*ft_ffinal(char *bef, char *str_after, char *str_ar_cp, int j)
{
	char *final;
	char *tmp;
	int	len;

	len = ft_strlen(str_after);
	if (len < 6)
	{
		tmp = str_after;
		if (!(str_after = ft_missing_zeros(len, str_after)))
			return (NULL);
		free (tmp);
	}
	if (!(final = ft_strjoin(bef, str_after)))
	{
		ft_free(bef, str_after, str_ar_cp, 2);
		return (NULL);
	}
	free(bef);
	if (j > 0)
		free(str_after);
	if (j > 1)
		free(str_ar_cp);
	return (final);
}
