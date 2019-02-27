/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:50:20 by amamy             #+#    #+#             */
/*   Updated: 2018/11/17 11:12:44 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			counter;
	int				find;
	unsigned char	*dsts;
	unsigned char	*srcs;
	unsigned char	cs;

	find = 0;
	dsts = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	cs = (unsigned char)c;
	counter = 0;
	while (counter < n)
	{
		dsts[counter] = srcs[counter];
		if (srcs[counter] == cs)
			return (dsts + counter + 1);
		counter++;
	}
	return (NULL);
}
