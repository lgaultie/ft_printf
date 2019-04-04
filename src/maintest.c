/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:28:37 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/04 15:39:02 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	ft_tests()
{
	char	*str;
	char	*tmp;
	int		i;
	int		total;

	i = 0;
	total = 0;
	printf("----- Test %d ----\n(%%s, SALUT)\n", ++total);
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

	printf("----- Test %d ----\n(%%d, 5)\n", ++total);
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

	printf("----- Test %d ----\n(%%.7s, SALUT)\n", ++total);
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

	printf("----- Test %d ----\n(%%.3s, SALUT)\n", ++total);
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

	printf("----- Test %d ----\n(%%.7d, 5)\n", ++total);
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

	printf("----- Test %d ----\n(%%.3d, 5)\n", ++total);
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


	// printf("----- Test %d ----\n(%%.*s, 7, SALUT)\n", ++total);
	// str = ft_strdup("|%.*s|\n");
	// tmp = ft_printf(str, 7, "SAlUT");
	// printf("Before : OK\n");
	// if ((ft_strcmp("|SAlUT|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");;
	// printf("---------------\n\n");

	// printf("----- Test %d ----\n(%%.*s, 3, SALUT)\n", ++total);
	// str = ft_strdup("|%.*s|\n");
	// tmp = ft_printf(str, 3, "SAlUT");
	// printf("Before : OK\n");
	// if ((ft_strcmp("|SAl|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	// printf("---------------\n\n");

	// printf("----- Test %d ----\n(|%%.*d|, 7, 5)\n", ++total);
	// str = ft_strdup("|%.*d|\n");
	// tmp = ft_printf(str, 7, 5);
	// printf("Before : OK\n");
	// if ((ft_strcmp("|0000005|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	// printf("---------------\n\n");

	// printf("----- Test %d ----\n(|%%.*d|, 3, 5)\n", ++total);
	// str = ft_strdup("|%.*d|\n");
	// tmp = ft_printf(str, 3, 5);
	// printf("Before : OK\n");
	// if ((ft_strcmp("|005|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("NOOOON\n");
	// printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%7s|, SALUT)\n", ++total);
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

	printf("----- Test %d ----\n(|%%3s|, SALUT)\n", ++total);
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

	printf("----- Test %d ----\n(%%7d, 5)\n", ++total);
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

	printf("----- Test %d ----\n(%%3d, 5)\n", ++total);
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


// test bonus
	// printf("----- Test %d ----\n(%%*s, 7,SALUT)\n", ++total);
	// str = ft_strdup("|%*s|\n");
	// tmp = ft_printf(str, 7, "SALUT");
	// printf("Before : OK\n");
	// if ((ft_strcmp("|  SALUT|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	// printf("---------------\n\n");

	// printf("----- Test %d ----\n(%%*s, 3, SALUT)\n", ++total);
	// str = ft_strdup("|%*s|\n");
	// tmp = ft_printf(str, 3, "SALUT");
	// printf("Before : OK\n");
	// if ((ft_strcmp("|SALUT|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	// printf("---------------\n\n");

	// printf("----- Test %d ----\n(|%%*d|, 7, 5)\n", ++total);
	// str = ft_strdup("|%*d|\n");
	// tmp = ft_printf(str, 7, 5);
	// printf("Before : OK\n");
	// if ((ft_strcmp("|      5|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	// printf("---------------\n\n");

	// printf("----- Test %d ----\n(|%%*d|, 3, 5)\n", ++total);
	// str = ft_strdup("|%*d|\n");
	// tmp = ft_printf(str, 3, 5);
	// printf("Before : OK\n");
	// if ((ft_strcmp("|  5|\n", tmp) == 0))
	// {
	// 	i++;
	// 	printf("\n----> OK <----\n\n");
	// }
	// else
	// 	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	// printf("---------------\n\n");


	printf("----- Test %d ----\n(|%% %%|)\n", ++total);
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

	printf("----- Test %d ----\n(|%%1d|, -18)\n", ++total);
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

	printf("----- Test %d ----\n(|%%-1.0d|, -18)\n", ++total);
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

	printf("----- Test %d ----\n(|%%-6d|, 5000)\n", ++total);
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

	printf("----- Test %d ----\n(|%%+3.3d|, -18)\n", ++total);
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

	printf("----- Test %d ----\n(|%%+3.3d|, -18)\n", ++total);
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

	printf("----- Test %d ----\n(|%%+1.0d|, -18)\n", ++total);
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

	printf("----- Test %d ----\n(|%%8.9.d|, -18)\n", ++total);
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

	printf("----- Test %d ----\n(|%%9d|, -18)\n", ++total);
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

	printf("----- Test %d ----\n(|%%hd|, (short)(-32768)\n", ++total);
	str = ft_strdup("|%hd|\n");
	tmp = ft_printf(str, (short)(-32768));
	printf("Before : OK\n");
	if ((ft_strcmp("|-32768|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hd|, (short)(-32769)\n", ++total);
	str = ft_strdup("|%hd|\n");
	tmp = ft_printf(str, (short)(-32769));
	printf("Before : OK\n");
	if ((ft_strcmp("|32767|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hd|, (short)(32767)\n", ++total);
	str = ft_strdup("|%hd|\n");
	tmp = ft_printf(str, (short)(32767));
	printf("Before : OK\n");
	if ((ft_strcmp("|32767|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hd|, (short)(32768)\n", ++total);
	str = ft_strdup("|%hd|\n");
	tmp = ft_printf(str, (short)(32768));
	printf("Before : OK\n");
	if ((ft_strcmp("|-32768|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");


	printf("----- Test %d ----\n(|%%ho|, (short)(65535)\n", ++total);
	str = ft_strdup("|%ho|\n");
	tmp = ft_printf(str, (short)(65535));
	printf("Before : OK\n");
	if ((ft_strcmp("|177777|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%ho|, (short)(65536)\n", ++total);
	str = ft_strdup("|%ho|\n");
	tmp = ft_printf(str, (short)(65536));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%ho|, (short)(0)\n", ++total);
	str = ft_strdup("|%ho|\n");
	tmp = ft_printf(str, (short)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%ho|, (short)(-1)\n", ++total);
	str = ft_strdup("|%ho|\n");
	tmp = ft_printf(str, (short)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|177777|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
	printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhd|, (char)(-128)\n", ++total);
	str = ft_strdup("|%hhd|\n");
	tmp = ft_printf(str, (char)(-128));
	printf("Before : OK\n");
	if ((ft_strcmp("|-128|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhd|, (char)(-129)\n", ++total);
	str = ft_strdup("|%hhd|\n");
	tmp = ft_printf(str, (char)(-129));
	printf("Before : OK\n");
	if ((ft_strcmp("|127|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhd|, (char)(127)\n", ++total);
	str = ft_strdup("|%hhd|\n");
	tmp = ft_printf(str, (char)(127));
	printf("Before : OK\n");
	if ((ft_strcmp("|127|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhd|, (char)(128)\n", ++total);
	str = ft_strdup("|%hhd|\n");
	tmp = ft_printf(str, (char)(128));
	printf("Before : OK\n");
	if ((ft_strcmp("|-128|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hho|, (char)(0)\n", ++total);
	str = ft_strdup("|%hho|\n");
	tmp = ft_printf(str, (char)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hho|, (char)(-1)\n", ++total);
	str = ft_strdup("|%hho|\n");
	tmp = ft_printf(str, (char)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|377|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hho|, (char)(255)\n", ++total);
	str = ft_strdup("|%hho|\n");
	tmp = ft_printf(str, (char)(255));
	printf("Before : OK\n");
	if ((ft_strcmp("|377|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hho|, (char)(256)\n", ++total);
	str = ft_strdup("|%hho|\n");
	tmp = ft_printf(str, (char)(256));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%ld|, (long)-9223372036854775808)\n", ++total);
	str = ft_strdup("|%ld|\n");
	tmp = ft_printf(str, (long)(LONG_MIN));
	printf("Before : OK\n");
	if ((ft_strcmp("|-9223372036854775808|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%ld|, (long)(9223372036854775807)\n", ++total);
	str = ft_strdup("|%ld|\n");
	tmp = ft_printf(str, (long)(LONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lld|, (long long)-9223372036854775808)\n", ++total);
	str = ft_strdup("|%lld|\n");
	tmp = ft_printf(str, (long long)(LLONG_MIN));
	printf("Before : OK\n");
	if ((ft_strcmp("|-9223372036854775808|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lld|, (long)(9223372036854775807)\n", ++total);
	str = ft_strdup("|%lld|\n");
	tmp = ft_printf(str, (long long)(LLONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lo|, (long)LONG_MIN)\n", ++total);
	str = ft_strdup("|%lo|\n");
	tmp = ft_printf(str, (long)(LONG_MIN));
	printf("Before : OK\n");
	if ((ft_strcmp("|1000000000000000000000|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lo|, (long)LONG_MAX)\n", ++total);
	str = ft_strdup("|%lo|\n");
	tmp = ft_printf(str, (long)(LONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|777777777777777777777|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llo|, (long long)LONG_MIN)\n", ++total);
	str = ft_strdup("|%llo|\n");
	tmp = ft_printf(str, (long long)(LLONG_MIN));
	printf("Before : OK\n");
	if ((ft_strcmp("|1000000000000000000000|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llo|, (long long)LONG_MAX)\n", ++total);
	str = ft_strdup("|%llo|\n");
	tmp = ft_printf(str, (long long)(LONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|777777777777777777777|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhu|, (char)(0)\n", ++total);
	str = ft_strdup("|%hhu|\n");
	tmp = ft_printf(str, (char)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhu|, (char)(-1)\n", ++total);
	str = ft_strdup("|%hhu|\n");
	tmp = ft_printf(str, (char)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|255|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhu|, (char)(255)\n", ++total);
	str = ft_strdup("|%hhu|\n");
	tmp = ft_printf(str, (char)(255));
	printf("Before : OK\n");
	if ((ft_strcmp("|255|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhu|, (char)(256)\n", ++total);
	str = ft_strdup("|%hhu|\n");
	tmp = ft_printf(str, (char)(256));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hu|, (short)(0)\n", ++total);
	str = ft_strdup("|%hu|\n");
	tmp = ft_printf(str, (short)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hu|, (short)(-1)\n", ++total);
	str = ft_strdup("|%hu|\n");
	tmp = ft_printf(str, (short)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|65535|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hu|, (short)(65535)\n", ++total);
	str = ft_strdup("|%hu|\n");
	tmp = ft_printf(str, (short)(65535));
	printf("Before : OK\n");
	if ((ft_strcmp("|65535|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hu|, (short)(65536)\n", ++total);
	str = ft_strdup("|%hu|\n");
	tmp = ft_printf(str, (short)(65536));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lu|, (long)(0)\n", ++total);
	str = ft_strdup("|%lu|\n");
	tmp = ft_printf(str, (long)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lu|, (long)(-1)\n", ++total);
	str = ft_strdup("|%lu|\n");
	tmp = ft_printf(str, (long)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|18446744073709551615|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lu|, (long)(LONG_MAX)\n", ++total);
	str = ft_strdup("|%lu|\n");
	tmp = ft_printf(str, (long)(LONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lu|, (long)(LONG_MAX + 1)\n", ++total);
	str = ft_strdup("|%lu|\n");
	tmp = ft_printf(str, (long)(LONG_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775808|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");



	printf("----- Test %d ----\n(|%%llu|, (long long)(0)\n", ++total);
	str = ft_strdup("|%llu|\n");
	tmp = ft_printf(str, (long long)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llu|, (long long)(-1)\n", ++total);
	str = ft_strdup("|%llu|\n");
	tmp = ft_printf(str, (long)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|18446744073709551615|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llu|, (long long)(LLONG_MAX)\n", ++total);
	str = ft_strdup("|%llu|\n");
	tmp = ft_printf(str, (long)(LLONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llu|, (long long)(LLONG_MAX + 1)\n", ++total);
	str = ft_strdup("|%llu|\n");
	tmp = ft_printf(str, (long)(LLONG_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775808|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhx|, (char)(0)\n", ++total);
	str = ft_strdup("|%hhx|\n");
	tmp = ft_printf(str, (char)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhx|, (char)(-1)\n", ++total);
	str = ft_strdup("|%hhx|\n");
	tmp = ft_printf(str, (char)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|ff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhx|, (char)(255)\n", ++total);
	str = ft_strdup("|%hhx|\n");
	tmp = ft_printf(str, (char)(255));
	printf("Before : OK\n");
	if ((ft_strcmp("|ff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhx|, (char)(256)\n", ++total);
	str = ft_strdup("|%hhx|\n");
	tmp = ft_printf(str, (char)(256));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hx|, (short)(0)\n", ++total);
	str = ft_strdup("|%hx|\n");
	tmp = ft_printf(str, (short)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hx|, (short)(-1)\n", ++total);
	str = ft_strdup("|%hx|\n");
	tmp = ft_printf(str, (short)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|ffff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hx|, (short)(65535)\n", ++total);
	str = ft_strdup("|%hx|\n");
	tmp = ft_printf(str, (short)(USHRT_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|ffff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hx|, (short)(65535)\n", ++total);
	str = ft_strdup("|%hx|\n");
	tmp = ft_printf(str, (short)(USHRT_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lx|, (long)(0)\n", ++total);
	str = ft_strdup("|%lx|\n");
	tmp = ft_printf(str, (long)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lx|, (long)(-1)\n", ++total);
	str = ft_strdup("|%lx|\n");
	tmp = ft_printf(str, (long)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|ffffffffffffffff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lx|, (long)(LONG_MAX)\n", ++total);
	str = ft_strdup("|%lx|\n");
	tmp = ft_printf(str, (long)(LONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|7fffffffffffffff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lx|, (LONG_MAX + 1)(0)\n", ++total);
	str = ft_strdup("|%lx|\n");
	tmp = ft_printf(str, (long)(LONG_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|8000000000000000|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llx|, (long long)(0)\n", ++total);
	str = ft_strdup("|%llx|\n");
	tmp = ft_printf(str, (long long)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llx|, (long long)(0)\n", ++total);
	str = ft_strdup("|%llx|\n");
	tmp = ft_printf(str, (long long)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|ffffffffffffffff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llx|, (long long)(LLONG_MAX)\n", ++total);
	str = ft_strdup("|%llx|\n");
	tmp = ft_printf(str, (long long)(LLONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|7fffffffffffffff|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llx|, (long long)(LLONG_MAX + 1)\n", ++total);
	str = ft_strdup("|%llx|\n");
	tmp = ft_printf(str, (long long)(LLONG_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|8000000000000000|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhX|, (char)(0)\n", ++total);
	str = ft_strdup("|%hhX|\n");
	tmp = ft_printf(str, (char)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhX|, (char)(-1)\n", ++total);
	str = ft_strdup("|%hhX|\n");
	tmp = ft_printf(str, (char)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|FF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhX|, (char)(255)\n", ++total);
	str = ft_strdup("|%hhX|\n");
	tmp = ft_printf(str, (char)(255));
	printf("Before : OK\n");
	if ((ft_strcmp("|FF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hhX|, (char)(256)\n", ++total);
	str = ft_strdup("|%hhX|\n");
	tmp = ft_printf(str, (char)(256));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hX|, (short)(0)\n", ++total);
	str = ft_strdup("|%hX|\n");
	tmp = ft_printf(str, (short)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hX|, (short)(-1)\n", ++total);
	str = ft_strdup("|%hX|\n");
	tmp = ft_printf(str, (short)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|FFFF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hX|, (short)(65535)\n", ++total);
	str = ft_strdup("|%hX|\n");
	tmp = ft_printf(str, (short)(USHRT_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|FFFF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%hX|, (short)(65535)\n", ++total);
	str = ft_strdup("|%hX|\n");
	tmp = ft_printf(str, (short)(USHRT_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lX|, (long)(0)\n", ++total);
	str = ft_strdup("|%lX|\n");
	tmp = ft_printf(str, (long)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lX|, (long)(-1)\n", ++total);
	str = ft_strdup("|%lX|\n");
	tmp = ft_printf(str, (long)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|FFFFFFFFFFFFFFFF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lX|, (long)(LONG_MAX)\n", ++total);
	str = ft_strdup("|%lX|\n");
	tmp = ft_printf(str, (long)(LONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|7FFFFFFFFFFFFFFF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%lX|, (LONG_MAX + 1)(0)\n", ++total);
	str = ft_strdup("|%lX|\n");
	tmp = ft_printf(str, (long)(LONG_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|8000000000000000|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llX|, (long long)(0)\n", ++total);
	str = ft_strdup("|%llX|\n");
	tmp = ft_printf(str, (long long)(0));
	printf("Before : OK\n");
	if ((ft_strcmp("|0|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llX|, (long long)(0)\n", ++total);
	str = ft_strdup("|%llX|\n");
	tmp = ft_printf(str, (long long)(-1));
	printf("Before : OK\n");
	if ((ft_strcmp("|FFFFFFFFFFFFFFFF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llX|, (long long)(LLONG_MAX)\n", ++total);
	str = ft_strdup("|%llX|\n");
	tmp = ft_printf(str, (long long)(LLONG_MAX));
	printf("Before : OK\n");
	if ((ft_strcmp("|7FFFFFFFFFFFFFFF|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test %d ----\n(|%%llX|, (long long)(LLONG_MAX + 1)\n", ++total);
	str = ft_strdup("|%llX|\n");
	tmp = ft_printf(str, (long long)(LLONG_MAX + 1));
	printf("Before : OK\n");
	if ((ft_strcmp("|8000000000000000|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");


	printf("Score : %d/%d\n\n", i, total);
}
