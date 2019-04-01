/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:28:37 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/01 21:04:54 by amamy            ###   ########.fr       */
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

	printf("----- Test 28 ----\n(|%%hhd|, (char)(-32768)\n");
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

	printf("----- Test 29 ----\n(|%%hd|, (short)(-32769)\n");
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

	printf("----- Test 30 ----\n(|%%hd|, (short)(32767)\n");
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

	printf("----- Test 31 ----\n(|%%hd|, (short)(32768)\n");
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


	printf("----- Test 32 ----\n(|%%ho|, (short)(65535)\n");
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

	printf("----- Test 33 ----\n(|%%ho|, (short)(65536)\n");
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

	printf("----- Test 34 ----\n(|%%ho|, (short)(0)\n");
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

	printf("----- Test 35 ----\n(|%%ho|, (short)(-1)\n");
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

	printf("----- Test 36 ----\n(|%%hhd|, (char)(-128)\n");
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

	printf("----- Test 37 ----\n(|%%hhd|, (char)(-129)\n");
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

	printf("----- Test 38 ----\n(|%%hhd|, (char)(127)\n");
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

	printf("----- Test 39 ----\n(|%%hhd|, (char)(128)\n");
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

	printf("----- Test 40 ----\n(|%%hho|, (char)(0)\n");
	str = ft_strdup("|%hhd|\n");
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

	printf("----- Test 41 ----\n(|%%hho|, (char)(-1)\n");
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

	printf("----- Test 42 ----\n(|%%hho|, (char)(255)\n");
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

	printf("----- Test 43 ----\n(|%%hho|, (char)(256)\n");
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

	printf("----- Test 44 ----\n(|%%ld|, (long)-9223372036854775808)\n");
	str = ft_strdup("|%ld|\n");
	tmp = ft_printf(str, (long)(-9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|-9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 45 ----\n(|%%ld|, (long)(9223372036854775807)\n");
	str = ft_strdup("|%ld|\n");
	tmp = ft_printf(str, (long)(9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 46 ----\n(|%%lld|, (long long)-9223372036854775807)\n");
	str = ft_strdup("|%lld|\n");
	tmp = ft_printf(str, (long long)(-9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|-9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 47 ----\n(|%%lld|, (long)(9223372036854775807)\n");
	str = ft_strdup("|%lld|\n");
	tmp = ft_printf(str, (long long)(9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");



















	printf("----- Test 48 ----\n(|%%lo|, (long)-9223372036854775808)\n");
	str = ft_strdup("|%lo|\n");
	tmp = ft_printf(str, (long)(-9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|-9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 45 ----\n(|%%ld|, (long)(9223372036854775807)\n");
	str = ft_strdup("|%ld|\n");
	tmp = ft_printf(str, (long)(9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 46 ----\n(|%%lld|, (long long)-9223372036854775807)\n");
	str = ft_strdup("|%lld|\n");
	tmp = ft_printf(str, (long long)(-9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|-9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("----- Test 47 ----\n(|%%lld|, (long)(9223372036854775807)\n");
	str = ft_strdup("|%lld|\n");
	tmp = ft_printf(str, (long long)(9223372036854775807));
	printf("Before : OK\n");
	if ((ft_strcmp("|9223372036854775807|\n", tmp) == 0))
	{
		i++;
		printf("\n----> OK <----\n\n");
	}
	else
		printf("XXXXXXXXXXXXXXXXXXXX  NOOOON  XXXXXXXXXXXXXXXXXXXX\n");
	printf("---------------\n\n");

	printf("Score : %d/47\n\n", i);
}
