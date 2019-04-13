/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:19:57 by amamy             #+#    #+#             */
/*   Updated: 2019/04/13 21:40:37 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
