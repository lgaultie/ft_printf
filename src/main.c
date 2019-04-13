/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:30 by amamy             #+#    #+#             */
/*   Updated: 2019/04/14 00:32:42 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

void	ft_tests();
// ----------------- BITWISE ---------------------
// i |= 2; // active le bit 2
// if (i & 2) // check if bit 2 is enable
// i &= ~2;// disable bit 2

//NORMEEEEEEE
//fichier oxcapsx.c a faire
//fichier plus_minus chelou
// fichiers de la libft a faire (comme itoa base)

int main(int argc, char **argv)
{
	long double		i;
	// char	*s = NULL;

	// tests de pute
	// char	*s = NULL;
	// printf("|%20s|\n", s);
	// ft_printf("|%20s|\n", s);
	// printf("--------------\n");
	// printf("|%.2s|\n", s);
	// ft_printf("|%.2s|\n", s);
	// printf("--------------\n");
	// printf("|%10.4s|\n", s);
	// ft_printf("|%10.4s|\n", s);
	// printf("--------------\n");
	// printf("|%-10.4s|\n", s);
	// ft_printf("|%-10.4s|\n", s);
	// printf("--------------\n");
	// printf("|%40f|\n", 123.321);
	// ft_printf("|%40f|\n", 123.321);
	// printf("--------------\n");
	// printf("|%34p|\n", s);
	// ft_printf("|%34p|\n", s);
	// printf("--------------\n");
	// printf("|%40f|\n", 123.321);
	// ft_printf("|%40f|\n", 123.321);
	// printf("--------------\n");
	// printf("|%4f|\n", 123.321);
	// ft_printf("|%4f|\n", 123.321);
	// printf("--------------\n");
	// printf("|%4.f|\n", 123.321);
	// ft_printf("|%4.f|\n", 123.321);


	(void)argc;
	(void)argv;
	i = 1231.234234231;
	char *str = ft_strdup("o");
	// printf("%lf\n", 243.5);
	//printf("%l13.42f\n", 243.5);
	// ft_printf("%f\n", DBL_MAX);
	// ft_printf("%f\n", 1.7976931348623157E+308);


	// printf("|%46.23s|\n", str);
	// ft_printf("|%46.23s|\n", str);
	printf("|%20s|\n", str);		//dans width+precis2 ft_ap_not_neg
	ft_printf("|%20s|\n", str);
	printf("--------------\n");
	printf("|%.20s|\n", str);		//dans width+precis2 ft_ap_not_neg
	ft_printf("|%.20s|\n", str);
	printf("--------------\n");
	printf("|%-4.2s|\n", str);		//dans width+precis2 ft_ap_not_neg
	ft_printf("|%-4.2s|\n", str);
	printf("--------------\n");
	printf("|%4.2s|\n", str);		//dans width+precis2 ft_ap_not_neg
	ft_printf("|%4.2s|\n", str);
	printf("--------------\n");
	printf("|%4.23s|    |%d|     |%40d|   |%d|   |%.d|  |%3.5d|\n", str, -5, 123, 42, 2, 5);
	ft_printf("|%4.23s|    |%d|     |%40d|   |%d|   |%.d|  |%3.5d|\n", str, -5, 123, 42, 2, 5);
	// printf("|%40f|\n", 123.321);
	// ft_printf("|%40f|\n", 123.321);
	// printf("--------------\n");
	// printf("|%4f|\n", 123.321);
	// ft_printf("|%4f|\n", 123.321);
	// printf("--------------\n");
	// printf("--------------\n");
	// printf("--------------\n");
	// printf("--------------\n");
	// //faut itoa les f en s pour les passer dans la fonction s de precision
	// printf("|%.1f|\n", 123.321);
	// ft_printf("|%.1f|\n", 123.321);
	// printf("--------------\n");
	// printf("|%.114f|\n", 123.321);
	// ft_printf("|%.114f|\n", 123.321);
	// printf("--------------\n");
	// printf("|%4.f|\n", 123.321);
	// ft_printf("|%4.f|\n", 123.321);

		//
		// printf("%lf\n", -132.55555724);
		// ft_printf("%lf\n", -132.55555724);		//avec les flags aussi ?
		// printf("--------------\n");
		// printf("%f\n", 132.55555724);
		// ft_printf("%f\n", 132.55555724);
		// printf("--------------\n");
		// printf("%lf\n", 243.552017);
		// ft_printf("%lf\n", 243.552017);
		// printf("--------------\n");
		// printf("%Lf\n", i);
		// // ft_printf("%Lf\n", i);
		// printf("--------------\n");
		// printf("%f\n", -10.011012365432);
		// ft_printf("%f\n", -10.011012365432);			//fail il oublie le 0

	// 	printf("--------------\n");
	// 	printf("\\n\n");
	// 	ft_printf("\\n\n");
	// 	printf("--------------\n");
	// 	printf("%%\\n\n");
	// 	ft_printf("%%\\n\n");
	// 	printf("--------------\n");
	// 	printf("%d\\n\n", 42);
	// 	ft_printf("%d\\n\n", 42);
	// 	printf("--------------\n");
	// 	printf("%d%d\\n\n", 42, 41);
	// 	ft_printf("%d%d\\n\n", 42, 41);
	// 	printf("--------------\n");
	// 	printf("%d%d%d\\n\n", 42, 43, 44);
	// 	ft_printf("%d%d%d\\n\n", 42, 43, 44);
	// 	printf("--------------\n");
	// 	//printf("%ld\\n\n", 2147483647);
	// 	ft_printf("%ld\\n\n", 2147483647);
	// 	printf("--------------\n");
	// 	//printf("%lld\\n\n", 9223372036854775807);
	// 	ft_printf("%lld\\n\n", 9223372036854775807);
	// 	printf("--------------\n");
	// 	printf("%x\\n\n", 505);
	// 	ft_printf("%x\\n\n", 505);
	// 	printf("--------------\n");
	// 	printf("%X\\n\n", 505);
	// 	ft_printf("%X\\n\n", 505);
	// 	printf("--------------\n");
	// 	printf("%20.15d\\n\n", 54321);
	// 	ft_printf("%20.15d\\n\n", 54321);
	// 	printf("--------------\n");
	// 	printf("%-10d\\n\n", 3);
	// 	ft_printf("%-10d\\n\n", 3);
	// 	printf("--------------\n");
	// 	printf("% d\\n\n", 3);
	// 	ft_printf("% d\\n\n", 3);
	// 	printf("--------------\n");
	// 	printf("%+d\\n\n", 3);
	// 	ft_printf("%+d\\n\n", 3);
	// 	printf("--------------\n");
	// 	printf("%010d\\n\n", 1);
	// 	ft_printf("%010d\\n\n", 1);
	// 	printf("--------------\n");
	// 	//printf("%hhd\\n\n", 0);
	// 	ft_printf("%hhd\\n\n", 0);
	// 	printf("--------------\n");
	// 	//printf("%u\\n\n", 4294967295);
	// 	ft_printf("%u\\n\n", 4294967295);
	// 	printf("--------------\n");
	// 	printf("%o\\n\n", 40);
	// 	ft_printf("%o\\n\n", 40);
	// 	printf("--------------\n");
	// 	//printf("%%#08x\\n\n", 42);
	// 	ft_printf("%%#08x\\n\n", 42);
	// 	printf("--------------\n");
	// 	printf("%x\\n\n", 1000);
	// 	ft_printf("%x\\n\n", 1000);
	// 	printf("--------------\n");
	// 	printf("%#X\\n\n", 1000);
	// 	ft_printf("%#X\\n\n", 1000);
	// 	printf("--------------\n");
	// 	printf("%s\\n\n", NULL);
	// 	ft_printf("%s\\n\n", NULL);
	// 	printf("--------------\n");
	// 	printf("%s%s\\n\n", "test", "test");
	// 	ft_printf("%s%s\\n\n", "test", "test");
	// 	printf("--------------\n");
	// 	printf("%s%s%s\\n\n", "test", "test", "test");
	// 	ft_printf("%s%s%s\\n\n", "test", "test", "test");
	//
	//
	//
	// ////////////////////// DEBUT DES TESTS
	// printf("|%s|\n", "this is a string");
	// ft_printf("|%s|\n", "this is a string");
	// printf("--------------\n");
	// printf("|%s|\n", NULL);
	// ft_printf("|%s|\n", NULL);
	// printf("--------------\n");
	// printf("|%s|\n", "lol");
	// ft_printf("|%s|\n", "lol");
	// printf("--------------\n");
	// printf("|%llx|\n", (long long)10);
	// ft_printf("|%llx|\n", (long long)10);		//JUMP untialiazed value
	// printf("--------------\n");
	// printf("|%-20s| is a string\n", "this");
	// ft_printf("|%-20s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-2s| is a string\n", "this");
	// ft_printf("|%-2s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-.2s| is a string\n", "this");
	// ft_printf("|%-.2s| is a string\n", "this");		//JUMP untialiazed value
	// printf("--------------\n");
	// printf("|%-5.2s| is a string\n", "this");
	// ft_printf("|%-5.2s| is a string\n", "this");
	// printf("--------------\n");
	// printf("|%-7.7s| is a string\n", "this");
	// ft_printf("|%-7.7s| is a string\n", "this");
	// printf("--------10------\n");
	// printf("|%-5.2s| is a string\n", "");
	// ft_printf("|%-5.2s| is a string\n", "");
	// printf("--------------\n");
	// printf("|%-1.0d|\n", -18);
	// ft_printf("|%-1.0d|\n", -18);
	// printf("--------------\n");
	// printf("|%#10o|\n", 524);
	// ft_printf("|%#10o|\n", 524);			//INVALID READ SIZE OF 1 SUR CMP DE OCTAL
	// printf("--------------\n");
	// printf("|%08x|\n", 42);
	// ft_printf("|%08x|\n", 42);
	// printf("--------------\n");
	// printf("|%10.08x|\n", 42);
	// ft_printf("|%10.08x|\n", 42);
	// printf("--------------\n");
	// printf("|%.8x|\n", 42);
	// ft_printf("|%.8x|\n", 42);
	// printf("--------------\n");
	// printf("|%-5.2s| is a string\n", "");
	// ft_printf("|%-5.2s| is a string\n", "");
	// printf("--------------\n");
	// printf("|%+d|\n", -42);
	// ft_printf("|%+d|\n", -42);
	// printf("--------------\n");
	// printf("|% d|\n", -42);
	// ft_printf("|% d|\n", -42);
	// printf("--------------\n");
	// printf("|%+5d|\n", 42);
	// ft_printf("|%+5d|\n", 42);
	// printf("-------20-------\n");
	// printf("|%+4.5d|\n", 42);
	// ft_printf("|%+4.5d|\n", 42);						//Invalid read of size 1
	// printf("--------------\n");
	// printf("|%+.5d|\n", 42);
	// ft_printf("|%+.5d|\n", 42);
	// printf("--------------\n");
	// printf("|%05d|\n", -42);
	// ft_printf("|%05d|\n", -42);						//Meme invalid read size 1 sur ret_flag
	// printf("--------------\n");
	// printf("|%03.2d|\n", -1);
	// ft_printf("|%03.2d|\n", -1);
	// printf("--------------\n");
	// printf("|%#o|\n", 42);
	// ft_printf("|%#o|\n", 42);					//invalid read size sur CMP
	// printf("--------------\n");
	// printf("|%#5x|\n", 42);
	// ft_printf("|%#5x|\n", 42);				//invalid read size sur CMP
	// printf("--------------\n");
	// printf("|%#05x|\n", 42);
	// ft_printf("|%#05x|\n", 42);
	// printf("--------------\n");
	// printf("|%#.05x|\n", 42);
	// ft_printf("|%#.05x|\n", 42);
	// printf("--------------\n");
	// printf("|%#08o|\n", 42);
	// ft_printf("|%#08o|\n", 42);					//invalid read size sur CMP
	// printf("--------------\n");
	// printf("|%+05d|\n", 42);
	// ft_printf("|%+05d|\n", 42);
	// printf("-------30-------\n");
	// printf("|%0+5d|\n", -42);
	// ft_printf("|%0+5d|\n", -42);				//invlaid read size sur strjoing ret_flag
	// // printf("--------------\n");
	// printf("|%0+5d|\n", 42);
	// ft_printf("|%0+5d|\n", 42);
	// printf("--------------\n");
	// printf("|%#10.05x|\n", 42);
	// ft_printf("|%#10.05x|\n", 42);
	// printf("--------------\n");
	// printf("|%-20.8o|\n", -42);
	// ft_printf("|%-20.8o|\n", -42);
	// printf("--------------\n");
	// printf("|%-20.15o|\n", -42);
	// ft_printf("|%-20.15o|\n", -42);
	// printf("--------------\n");
	// printf("|%-3.6o|\n", -17);
	// ft_printf("|%-3.6o|\n", -17);
	// printf("--------------\n");
	// printf("|%.0s|\n", "salutttt");
	// ft_printf("|%.0s|\n", "salutttt");
	// printf("--------------\n");
	// printf("|% %|\n");
	// ft_printf("|% %|\n");
	// printf("--------------\n");
	// printf("%% |%2.11u|\n", 18);
	// ft_printf("%% |%2.11u|\n", 18);
	// printf("--------------\n");
	// printf("|%07.5d|,|%d|\n",150789, 17);
	// ft_printf("|%07.5d|,|%d|\n",150789, 17);
	// printf("--------40------\n");
	// printf("|%00.05d| \n", 7);
	// ft_printf("|%00.05d| \n", 7);
	// printf("--------------\n");
	// printf("|%05.2d|\n", 7);
	// ft_printf("|%05.2d|\n", 7);
	// printf("--------------\n");
	// printf("|%5%|\n");
	// ft_printf("|%5%|\n");
	// printf("--------------\n");
	// printf("|%.5%|\n");
	// ft_printf("|%.5%|\n");
	// printf("--------------\n");
	// printf("|%-.5%|\n");
	// ft_printf("|%-.5%|\n");
	// printf("--------------\n");
	// printf("|%8.5%|\n");
	// ft_printf("|%8.5%|\n");
	// printf("--------------\n");
	// printf("|%+8.5%|\n");
	// ft_printf("|%+8.5%|\n");
	// printf("--------------\n");
	// printf("|%-5%|\n");
	// ft_printf("|%-5%|\n");
	// printf("--------------\n");
	// printf("|%-8.5%|\n");
	// ft_printf("|%-8.5%|\n");
	// printf("--------------\n");
	// printf("|%-8.5%|\n");
	// ft_printf("|%-8.5%|\n");
	// printf("--------50------\n");
	// printf("|%5.2s| is a string\n", "this");
	// ft_printf("|%5.2s| is a string\n", "this");			//Conditional jump or move depends on uninitialised value(s)
	// printf("--------------\n");
	// printf("|%12s| is a string\n", "this");
	// ft_printf("|%12s| is a string\n", "this");
	// printf("--------------\n");
	// printf("vrai: |%#10o|\n", 0);
	// ft_printf("faux: |%#10o|\n", 0);
	// printf("--------------\n");
	// printf("vrai: |%#.10o|\n", 0);
	// ft_printf("faux: |%#.10o|\n", 0);
	// printf("--------------\n");
	// printf("vrai |%+-8.5%|\n");
	// ft_printf("mine |%+-8.5%|\n");
	// printf("--------------\n");
	// printf("|%5.x| |%5.0x|\n", 0, 0);
	// ft_printf("|%5.x| |%5.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%#.x| |%#.0x|\n", 0, 0);
	// ft_printf("|%#.x| |%#.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%.x| |%.0x|\n", 0, 0);
	// ft_printf("|%.x| |%.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%#x|\n", 0);
	// ft_printf("|%#x|\n", 0);
	// printf("--------------\n");
	// printf("|%.o| |%.0o|\n", 0, 0);
	// ft_printf("|%.o| |%.0o|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%#.o| |%#.0o|\n", 0, 0);
	// ft_printf("|%#.o| |%#.0o|\n", 0, 0);				////invalid read size sur CMP
	// printf("--------------\n");
	// printf("|%#.x| |%#.0x|\n", 0, 0);
	// ft_printf("|%#.x| |%#.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%.d| |%.0d|\n", 0, 0);
	// ft_printf("|%.d| |%.0d|\n", 0, 0);
	// printf("--------------\n");
	// printf("|%5.d| |%5.0d|\n", 0, 0);
	// ft_printf("|%5.d| |%5.0d|\n", 0, 0);			//invlaid read size sur strjoing ret_flag
	// printf("--------60------\n");
	// printf("|%03.2d|\n", 0);
	// ft_printf("|%03.2d|\n", 0);
	// printf("--------------\n");
	// printf("|%5.2s| is a string\n", "");
	// ft_printf("|%5.2s| is a string\n", "");
	// printf("--------------\n");
	// printf("|%20p|\n", s);				//avec char *s = NULL;
	// ft_printf("|%20p|\n", s);				//avec char *s = NULL;
	// printf("--------------\n");
	// printf("|%-20p|\n", s);				//avec char *s = NULL;
	// ft_printf("|%-20p|\n", s);				//avec char *s = NULL;
	// printf("--------------\n");
	// printf("--------------\n");
	// printf("--------------\n");
	// ft_printf("%jd\\n\n", 9223372036854775807);
	// ft_printf("%zd\\n\n", 4294967295);
	// ft_printf("%\\n\n");
	// ft_printf("%U\\n\n", 4294967295);
	// ft_printf("%S\\n\n", L"ݗݜशব");
	// ft_printf("%C\\n\n", 15000);
	// ft_printf("%-05d\n", -42);
	// ft_printf("%p\\n\n", &ft_printf);


	// ft_printf("%#-08x", 42);
	// ft_printf("%-05o", 2500);
	// ft_printf("%-05d", 42);
	// ft_printf("% u", 4294967295);
	// ft_printf("%+u", 4294967295);

	return 0;
}
