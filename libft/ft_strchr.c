/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:36:46 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/16 12:22:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	d;
	int		i;

	i = 0;
	d = (char)c;
	str = (char*)s;
	while (str[i] != d && str[i] != '\0')
		i++;
	if (str[i] == d)
		return ((char*)&str[i]);
	return (NULL);
}
