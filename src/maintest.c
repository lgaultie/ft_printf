/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:28:37 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/01 14:05:50 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_tests()
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	printf("----- Test 01 ----\n(%%s, SALUT)\n");
	str = ft_strdup("|%s|\n");
	tmp = ft_printf(str, "SAlUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|SAlUT|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 02 ----\n(%%d, 5)\n");
	str = ft_strdup("|%d|\n");
	tmp = ft_printf(str, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|5|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 03 ----\n(%%.7s, SALUT)\n");
	str = ft_strdup("|%.7s|\n");
	tmp = ft_printf(str, "SAlUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|SAlUT|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 04 ----\n(%%.3s, SALUT) - char * + accuracy\n");
	str = ft_strdup("|%.3s|\n");
	tmp = ft_printf(str, "SAlUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|SAl|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 05 ----\n(%%.7d, 5) - char * + accuracy\n");
	str = ft_strdup("|%.7d|\n");
	tmp = ft_printf(str, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|0000005|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 06 ----\n(%%.3d, 5) - char * + accuracy\n");
	str = ft_strdup("|%.3d|\n");
	tmp = ft_printf(str, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|005|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");


	printf("----- Test 07 ----\n(%%.*s, 7, SALUT) - char * + accuracy + *\n");
	str = ft_strdup("|%.*s|\n");
	tmp = ft_printf(str, 7, "SAlUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|SAlUT|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");;
	printf("---------------\n\n");

	printf("----- Test 08 ----\n(%%.*s, 3, SALUT) - char * + accuracy + *\n");
	str = ft_strdup("|%.*s|\n");
	tmp = ft_printf(str, 3, "SAlUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|SAl|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 09 ----\n(|%%.*d|, 7, 5) int + accuracy + *\n");
	str = ft_strdup("|%.*d|\n");
	tmp = ft_printf(str, 7, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|0000005|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 10 ----\n(|%%.*d|, 3, 5) int + accuracy + *\n");
	str = ft_strdup("|%.*d|\n");
	tmp = ft_printf(str, 3, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|005|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("NOOOON\n");
	printf("---------------\n\n");

	printf("----- Test 11 ----\n(|%%7s|, SALUT) int + accuracy + *\n");
	str = ft_strdup("|%7s|\n");
	tmp = ft_printf(str, "SALUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|  SALUT|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 12 ----\n(|%%3s|, SALUT) int + accuracy + *\n");
	str = ft_strdup("|%3s|\n");
	tmp = ft_printf(str, "SALUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|SALUT|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 13 ----\n(%%7d, 5) - int + Accuracy\n");
	str = ft_strdup("|%7d|\n");
	tmp = ft_printf(str, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|      5|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 14 ----\n(%%3d, 5) - int + Accuracy\n");
	str = ft_strdup("|%3d|\n");
	tmp = ft_printf(str, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|  5|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 15 ----\n(%%*s, 7,SALUT) -\n");
	str = ft_strdup("|%*s|\n");
	tmp = ft_printf(str, 7, "SALUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|  SALUT|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 16 ----\n(%%*s, 3, SALUT) -\n");
	str = ft_strdup("|%*s|\n");
	tmp = ft_printf(str, 3, "SALUT");
	printf("Before : OK\n");
	if ((ft_strcmp("|SALUT|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 17 ----\n(|%%*d|, 7, 5) - int + Width + *\n");
	str = ft_strdup("|%*d|\n");
	tmp = ft_printf(str, 7, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|      5|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 18 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%*d|\n");
	tmp = ft_printf(str, 3, 5);
	printf("Before : OK\n");
	if ((ft_strcmp("|  5|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("Score : %d/18\n\n", i);

	printf("----- Test 19 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|% %|\n");
	tmp = ft_printf(str);
	printf("Before : OK\n");
	if ((ft_strcmp("|%|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 20 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%1d|\n");
	tmp = ft_printf(str, -18);
	printf("Before : OK\n");
	if ((ft_strcmp("|-18|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 21 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%-1.0d|\n");
	tmp = ft_printf(str, -18);
	printf("Before : OK\n");
	if ((ft_strcmp("|-18|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 22 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%-6d|\n");
	tmp = ft_printf(str, 5000);
	printf("Before : OK\n");
	if ((ft_strcmp("|5000  |\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 23 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%+3.3d|\n");
	tmp = ft_printf(str, -18);
	printf("Before : OK\n");
	if ((ft_strcmp("|-018|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 24 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%+3.3d|\n");
	tmp = ft_printf(str, -18);
	printf("Before : OK\n");
	if ((ft_strcmp("|-018|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 25 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%+1.0d|\n");
	tmp = ft_printf(str, -18);
	printf("Before : OK\n");
	if ((ft_strcmp("|-18|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 26 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%8.9d|\n");
	tmp = ft_printf(str, -18);
	printf("Before : OK\n");
	if ((ft_strcmp("|-000000018|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 27 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%9d|\n");
	tmp = ft_printf(str, -18);
	printf("Before : OK\n");
	if ((ft_strcmp("|      -18|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 28 ----\n(|%%*d|, 3, 5) - int + Width + *\n");
	str = ft_strdup("|%+-8.6d|\n");
	tmp = ft_printf(str, 17);
	printf("Before : OK\n");
	if ((ft_strcmp("|+000017 |\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("Score : %d/28\n\n", i);
}
