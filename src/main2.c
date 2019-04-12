/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:30:17 by lgaultie          #+#    #+#             */
/*   Updated: 2019/04/11 19:37:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int test1 = 1000000000;
	short int test2 = 10000;
	char test3 = 42;
	long int test4 = 4000000000;
	long long int test5 = 8000000000;
	int *test6 = &test1;
	unsigned short test7 = 100;
	unsigned long test8 = 4000000000;
	unsigned long long test9 = 8000000000;
	unsigned int test10 = 4294967295;
	char *test11 = NULL;
	char *test12 = 0x0;
	int test13 = INT_MAX;

	printf("VRAI PRINTF:\n");
	printf("-----Test normaux-----\n");
	printf("test printf\n");
	ft_printf("test printf\n");
//	printf("\0");
//	ft_printf("\0");
	printf("");
	ft_printf("");
	printf("-----Test %%c-----\n");
	printf("%c\n", 'k');
	ft_printf("%c\n", 'k');
	printf("%c\n", '\n');
	ft_printf("%c\n", '\n');
	printf("%c\n", '\0');
	ft_printf("%c\n", '\0');
	printf("test avec 0 : '%c'\n", 0);
	ft_printf("test avec 0 : '%c'\n", 0);
	printf("-----Test %%s-----\n");
	printf("%s\n", "POULOULOU");
	ft_printf("%s\n", "POULOULOU");
	printf("%s\n", "\0");
	ft_printf("%s\n", "\0");
	printf("%s", "JURE LE YA UN RETOUR LIGNE\n");
	ft_printf("%s", "JURE LE YA UN RETOUR LIGNE\n");
	printf("-----Test %%p-----\n");
	printf("%p\n", test6);
	ft_printf("%p\n", test6);
	printf("%p\n", test11);
	ft_printf("%p\n", test11);
	printf("%p\n", test12);
	ft_printf("%p\n", test12);
	printf("-----Test %%%%-----\n");
	printf("%%\n");
	ft_printf("%%\n");
	printf("-----Test %%d et %%i-----\n");
	printf("%d\n", test1);
	ft_printf("%d\n", test1);
	printf("%i\n", test1);
	ft_printf("%i\n", test1);
	printf("%d\n", test13);
	ft_printf("%d\n", test13);
	printf("%hd\n", test2);
	ft_printf("%hd\n", test2);
	printf("%hi\n", test2);
	ft_printf("%hi\n", test2);
	printf("%hhd\n", test3);
	ft_printf("%hhd\n", test3);
	printf("%hhi\n", test3);
	ft_printf("%hhi\n", test3);
	printf("%ld\n", test4);
	ft_printf("%ld\n", test4);
	printf("%li\n",test4);
	ft_printf("%li\n",test4);
	printf("%lld\n", test5);
	ft_printf("%lld\n", test5);
	printf("%lli\n", test5);
	ft_printf("%lli\n", test5);
	printf("-----Test %%o-----\n");
	printf("%o\n", 1000);
	ft_printf("%o\n", 1000);
	printf("%o\n", 0x1000);
	ft_printf("%o\n", 0x1000);
	printf("%ho\n", test7);
	ft_printf("%ho\n", test7);
	printf("%hho\n", test3);
	ft_printf("%hho\n", test3);
	printf("%lo\n", test8);
	ft_printf("%lo\n", test8);
	printf("%llo\n", test9);
	ft_printf("%llo\n", test9);
	printf("-----Test %%u-----\n");
	printf("%u\n", 1000);
	ft_printf("%u\n", 1000);
	printf("%u\n", test10);
	ft_printf("%u\n", test10);
	printf("%u\n", -1);
	ft_printf("%u\n", -1);
	printf("%u\n", -100);
	ft_printf("%u\n", -100);
	printf("%hu\n", test7);
	ft_printf("%hu\n", test7);
	printf("%hhu\n", test3);
	ft_printf("%hhu\n", test3);
	printf("%lu\n", test8);
	ft_printf("%lu\n", test8);
	printf("%llu\n", test9);
	ft_printf("%llu\n", test9);
	printf("-----Test %%x et %%X-----\n");
	printf("%x\n", 1000);
	ft_printf("%x\n", 1000);
	printf("%hx\n", test7);
	ft_printf("%hx\n", test7);
	printf("%hhx\n", test3);
	ft_printf("%hhx\n", test3);
	printf("%lx\n", test8);
	ft_printf("%lx\n", test8);
	printf("%llx\n", test9);
	ft_printf("%llx\n", test9);
	printf("%X\n", 1000);
	ft_printf("%X\n", 1000);
	printf("%hX\n", test7);
	ft_printf("%hX\n", test7);
	printf("%hhX\n", test3);
	ft_printf("%hhX\n", test3);
	printf("%lX\n", test8);
	ft_printf("%lX\n", test8);
	printf("%llX\n", test9);
	ft_printf("%llX\n", test9);
	printf("-----Test Minwidth-----\n");
	printf("Pourcent c: '%10c'\n", 'o');
	ft_printf("Pourcent c: '%10c'\n", 'o');
	printf("Pourcent c: '%-10c'\n", 'o');
	ft_printf("Pourcent c: '%-10c'\n", 'o');
	printf("Pourcent s: '%10s'\n", "hihihi");
	ft_printf("Pourcent s: '%10s'\n", "hihihi");
	printf("Pourcent s: '%-10s'\n", "hihihi");
	ft_printf("Pourcent s: '%-10s'\n", "hihihi");
	printf("Pourcent s: '%10s'\n", "hohohohohohohoho");
	ft_printf("Pourcent s: '%10s'\n", "hohohohohohohoho");
	printf("Pourcent s: '%-10s'\n", "hohohohohohohoho");
	ft_printf("Pourcent s: '%-10s'\n", "hohohohohohohoho");
	printf("Pourcent p: '%20p'\n", test6);
	ft_printf("Pourcent p: '%20p'\n", test6);
	printf("Pourcent p: '%-20p'\n", test6);
	ft_printf("Pourcent p: '%-20p'\n", test6);
	printf("Pourcent di: '%10d'\n", 42);
	ft_printf("Pourcent di: '%10d'\n", 42);
	printf("Pourcent di: '%-10d'\n", 42);
	ft_printf("Pourcent di: '%-10d'\n", 42);
	printf("Pourcent di: '%10d'\n", -1000);
	ft_printf("Pourcent di: '%10d'\n", -1000);
	printf("Pourcent di: '%-10d'\n", -1000);
	ft_printf("Pourcent di: '%-10d'\n", -1000);
	printf("Pourcent o: '%10o' \n", 1000);
	ft_printf("Pourcent o: '%10o' \n", 1000);
	printf("Pourcent o: '%-10o'\n", 1000);
	ft_printf("Pourcent o: '%-10o'\n", 1000);
	printf("Pourcent u: '%10u'\n", 100);
	ft_printf("Pourcent u: '%10u'\n", 100);
	printf("Pourcent u: '%-10u'\n", 100);
	ft_printf("Pourcent u: '%-10u'\n", 100);
	printf("Pourcent x: '%10x'\n", 1000);
	ft_printf("Pourcent x: '%10x'\n", 1000);
	printf("Pourcent X: '%10X'\n", 1000);
	ft_printf("Pourcent X: '%10X'\n", 1000);
	printf("Pourcent X: '%-10X'\n", 1000);
	ft_printf("Pourcent X: '%-10X'\n", 1000);
	printf("Pourcent pourcent : '%10%'\n");
	ft_printf("Pourcent pourcent : '%10%'\n");
	printf("Pourcent pourcent : '%-10%'\n");
	ft_printf("Pourcent pourcent : '%-10%'\n");
	printf("-----Test precision-----\n");
//	printf("Pourcent c: '%.10c'\n", 'o');
//	ft_printf("Pourcent c: '%.10c'\n", 'o');
	printf("Pourcent s: '%.10s'\n", "hohohohohohohoho");
	ft_printf("Pourcent s: '%.10s'\n", "hohohohohohohoho");
//	printf("Pourcent p: '%.20p'\n", test6);
//	ft_printf("Pourcent p: '%.20p'\n", test6);
	printf("Pourcent d: '%.10d'\n", 42);
	ft_printf("Pourcent d: '%.10d'\n", 42);
	printf("Pourcent o: '%.10o' \n", 1000);
	ft_printf("Pourcent o: '%.10o' \n", 1000);
	printf("Pourcent u: '%.10u'\n", 100);
	ft_printf("Pourcent u: '%.10u'\n", 100);
	printf("Pourcent x: '%.10x'\n", 1000);
	ft_printf("Pourcent x: '%.10x'\n", 1000);
	printf("Pourcent X: '%.10X'\n", 1000);
	ft_printf("Pourcent X: '%.10X'\n", 1000);
	printf("Pourcent pourcent : '%.10%'\n");
	ft_printf("Pourcent pourcent : '%.10%'\n");
	printf("Pourcent D: '%5.d' '%5.0d'\n", 0, 0);
	ft_printf("Pourcent D: '%5.d' '%5.0d'\n", 0, 0);
	printf("-----Test +- #0-----\n");
	printf("espace positif '% d'\n", 1000);
	ft_printf("espace positif '% d'\n", 1000);
	printf("espace negatif '% d'\n", -1000);
	ft_printf("espace negatif '% d'\n", -1000);
	printf("plus positif '%+d'\n", 1000);
	ft_printf("plus positif '%+d'\n", 1000);
	printf("plus negatif '%+d'\n", -1000);
	ft_printf("plus negatif '%+d'\n", -1000);
	printf("moins positif '%-10d'\n", 1000);
	ft_printf("moins positif '%-10d'\n", 1000);
	printf("moins negatif '%-10d'\n", -1000);
	ft_printf("moins negatif '%-10d'\n", -1000);
	printf("zero positif '%010d'\n", 1000);
	ft_printf("zero positif '%010d'\n", 1000);
	printf("zero negatif '%010d'\n", -1000);
	ft_printf("zero negatif '%010d'\n", -1000);
	printf("zero negatif '%010.06d'\n", -1000);
	ft_printf("zero negatif '%10.06d'\n", -1000);
	//printf("zero + prec '%-010d'\n", -1000);
	ft_printf("zero + prec '%-010d'\n", -1000);
	printf("----------------------------------\n");
	printf("VALEURS DE RETOUR de \\0 = %d\n", printf("%c", '\0'));
	printf("VALEURS DE RETOUR de \\0 = %d\n", ft_printf("%c", '\0'));
	printf("------1------\n");
	printf("|%s|\n", "this is a string");
	ft_printf("|%s|\n", "this is a string");
	printf("------2-------\n");
	printf("|%s|\n", NULL);
	ft_printf("|%s|\n", NULL);
	printf("------3-------\n");
	printf("|%s|\n", "lol");
	ft_printf("|%s|\n", "lol");
	printf("------4-------\n");
	printf("|%llx|\n", (long long)10);
	ft_printf("|%llx|\n", (long long)10);
	printf("------5-------\n");
	printf("|%-20s| is a string\n", "this");
	ft_printf("|%-20s| is a string\n", "this");
	printf("------6-------\n");
	printf("|%-2s| is a string\n", "this");
	ft_printf("|%-2s| is a string\n", "this");
	printf("------7-------\n");
	printf("|%-.2s| is a string\n", "this");
	ft_printf("|%-.2s| is a string\n", "this");
	printf("------8-------\n");
	printf("|%-5.2s| is a string\n", "this");
	ft_printf("|%-5.2s| is a string\n", "this");
	printf("------9-------\n");
	printf("|%-7.7s| is a string\n", "this");
	ft_printf("|%-7.7s| is a string\n", "this");
	printf("-----10-------\n");
	printf("|%-5.2s| is a string\n", "");
	ft_printf("|%-5.2s| is a string\n", "");
	printf("-----11-------\n");
	printf("|%-1.0d|\n", -18);
	ft_printf("|%-1.0d|\n", -18);
	printf("-----12-------\n");
	printf("|%#10o|\n", 524);
	ft_printf("|%#10o|\n", 524);
	printf("-----13-------\n");
	printf("|%08x|\n", 42);
	ft_printf("|%08x|\n", 42);
	printf("-----14-------\n");
	printf("|%10.08x|\n", 42);
	ft_printf("|%10.08x|\n", 42);
	printf("-----15-------\n");
	printf("|%.8x|\n", 42);
	ft_printf("|%.8x|\n", 42);
	printf("-----16-------\n");
	printf("|%-5.2s| is a string\n", "");
	ft_printf("|%-5.2s| is a string\n", "");
	printf("-----17-------\n");
	printf("|%+d|\n", -42);
	ft_printf("|%+d|\n", -42);
	printf("-----18-------\n");
	printf("|% d|\n", -42);
	ft_printf("|% d|\n", -42);
	printf("-----19-------\n");
	printf("|%+5d|\n", 42);
	ft_printf("|%+5d|\n", 42);
	printf("-----20-------\n");
	printf("|%+4.5d|\n", 42);
	ft_printf("|%+4.5d|\n", 42);
	printf("-----21-------\n");
	printf("|%+.5d|\n", 42);
	ft_printf("|%+.5d|\n", 42);
	printf("-----22-------\n");
	printf("|%05d|\n", -42);
	ft_printf("|%05d|\n", -42);
	printf("-----23-------\n");
	printf("|%03.2d|\n", -1);
	ft_printf("|%03.2d|\n", -1);
	printf("-----24-------\n");
	printf("|%#o|\n", 42);
	ft_printf("|%#o|\n", 42);
	printf("-----25-------\n");
	printf("|%#5x|\n", 42);
	ft_printf("|%#5x|\n", 42);
	printf("-----26-------\n");
	printf("|%#05x|\n", 42);
	ft_printf("|%#05x|\n", 42);
	printf("-----27-------\n");
	printf("|%#.05x|\n", 42);
	ft_printf("|%#.05x|\n", 42);
	printf("-----28-------\n");
	printf("|%#08o|\n", 42);
	ft_printf("|%#08o|\n", 42);
	printf("-----29-------\n");
	printf("|%+05d|\n", 42);
	ft_printf("|%+05d|\n", 42);
	printf("-----30-------\n");
	printf("|%0+5d|\n", -42);
	ft_printf("|%0+5d|\n", -42);
	printf("-----31-------\n");
	printf("|%0+5d|\n", 42);
	ft_printf("|%0+5d|\n", 42);
	printf("-----32-------\n");
	printf("|%#10.05x|\n", 42);
	ft_printf("|%#10.05x|\n", 42);
	printf("-----33-------\n");
	printf("|%-20.8o|\n", -42);
	ft_printf("|%-20.8o|\n", -42);
	printf("-----34-------\n");
	printf("|%-20.15o|\n", -42);
	ft_printf("|%-20.15o|\n", -42);
	printf("-----35-------\n");
	printf("|%-3.6o|\n", -17);
	ft_printf("|%-3.6o|\n", -17);
	printf("-----36-------\n");
	printf("|%.0s|\n", "salutttt");
	ft_printf("|%.0s|\n", "salutttt");
	printf("-----37-------\n");
	printf("|% %|\n");
	ft_printf("|% %|\n");
	printf("-----38-------\n");
	printf("%% |%2.11u|\n", 18);
	ft_printf("%% |%2.11u|\n", 18);
	printf("-----39-------\n");
	printf("|%07.5d|,|%d|\n",150789, 17);
	ft_printf("|%07.5d|,|%d|\n",150789, 17);
	printf("-----40-------\n");
	printf("|%00.05d| \n", 7);
	ft_printf("|%00.05d| \n", 7);
	printf("-----41-------\n");
	printf("|%05.2d|\n", 7);
	ft_printf("|%05.2d|\n", 7);
	printf("-----42-------\n");
	printf("|%5%|\n");
	ft_printf("|%5%|\n");
	printf("-----43-------\n");
	printf("|%.5%|\n");
	ft_printf("|%.5%|\n");
	printf("-----44-------\n");
	printf("|%-.5%|\n");
	ft_printf("|%-.5%|\n");
	printf("-----45-------\n");
	printf("|%8.5%|\n");
	ft_printf("|%8.5%|\n");
	printf("-----46-------\n");
	printf("|%+8.5%|\n");
	ft_printf("|%+8.5%|\n");
	printf("-----47-------\n");
	printf("|%-5%|\n");
	ft_printf("|%-5%|\n");
	printf("-----48-------\n");
	printf("|%-8.5%|\n");
	ft_printf("|%-8.5%|\n");
	printf("-----49-------\n");
	printf("|%+-8.5%|\n");
	ft_printf("|%+-8.5%|\n");
	printf("-----50-------\n");
	printf("|%-8.5%|\n");
	ft_printf("|%-8.5%|\n");
	printf("-----51-------\n");
	printf("|%5.2s| is a string\n", "this");
	ft_printf("|%5.2s| is a string\n", "this");
	printf("-----52-------\n");
	printf("|%12s| is a string\n", "this");
	ft_printf("|%12s| is a string\n", "this");
	printf("-----53-------\n");
	printf("|%#.x| |%#.0x|\n", 0, 0);
	ft_printf("|%#.x| |%#.0x|\n", 0, 0);
	printf("-----54-------\n");
	printf("|%5.x| |%5.0x|\n", 0, 0);
	ft_printf("|%5.x| |%5.0x|\n", 0, 0);
	printf("-----55-------\n");
	printf("|%.x| |%.0x|\n", 0, 0);
	ft_printf("|%.x| |%.0x|\n", 0, 0);
	printf("vrai printf avec +d '%+d'\n", -42);
	ft_printf("mien printf avec +d '%+d'\n", -42);
	//printf("vrai printf avec + d '%+ d'\n", -42);
	ft_printf("mien printf avec + d '%+ d'\n", -42);
	//printf("vrai printf avec +  d '%+  d'\n", -42);
	ft_printf("mien printf avec +  d '%+  d'\n", -42);
	printf("vrai printf avec #0x '%#0x'\n", 0);
	ft_printf("mien printf avec #0x '%#0x'\n", 0);
	printf("vrai printf avec #x '%#x'\n", 42);
	ft_printf("mien printf avec #x '%#x'\n", 42);
	printf("vrai printf avec #x '%#8x'\n", 42);
	ft_printf("mien printf avec #x '%#8x'\n", 42);
	printf("vrai printf avec 2x '%2x'\n", 542);
	ft_printf("mien printf avec 2x '%2x'\n", 542);
	printf("vrai printf avec #6o '%2o'\n", 542);
	ft_printf("mien printf avec #6o '%2o'\n", 542);
	//printf("vrai printf avec lu '%lu'\n", -42);
	ft_printf("mien printf avec lu '%lu'\n", -42);
	//printf("vrai printf avec -#08.15x '%#-08.15x'\n", 42);
	ft_printf("mien printf avec -#08.15x '%#-08.15x'\n", 42);
	//printf("vrai printf avec #-08x '%#-08x'\n", 42);
	ft_printf("mien printf avec #-08x '%#-08x'\n", 42);
	// printf("@moulitest: '%#.x' '%#.0x'\n", 0, 0);
	// ft_printf("@moulitest: '%#.x' '%#.0x'\n", 0, 0);
	// printf("vrai printf avec lu '%lu'\n", -42);
	ft_printf("mien printf avec lu '%lu'\n", -42);
	printf("vrai printf avec .0o '%.0o'\n", 0);
	ft_printf("mien printf avec .0o '%.0o'\n", 0);
	printf("vrai printf avec lld '%lld'\n", (long long)LLONG_MIN);
	ft_printf("mien printf avec lld '%lld'\n", (long long)LLONG_MIN);
	printf("vrai printf avec #6o '%#6o'\n", 2500);
	ft_printf("mien printf avec #6o '%#6o'\n", 2500);
	printf("vrai printf avec -#6o '%-#6o'\n", 2500);
	ft_printf("mien printf avec -#6o '%-#6o'\n", 2500);
	printf("vrai printf avec -.2s '%-.2s'\n", "");
	ft_printf("mien printf avec -.2s '%-.2s'\n", "");
	printf("vrai printf avec ho '%ho'\n", (short)-127);
    ft_printf("mien printf avec ho '%ho'\n", (short)-127);
    printf("vrai avec '%#8x'\n", 50);
    ft_printf("mien avec '%#8x'\n", 50);
    printf("%lu\n", (long)-42);
	ft_printf("%lu\n", (long)-42);
	printf("--------------Basic test 42 fc--------------------\n");
	printf("");
	ft_printf("");
	printf("\\n");
	ft_printf("\\n");
    printf("test\n");
	ft_printf("test\n");
    printf("test\\n");
	ft_printf("test\\n");
    printf("1234\n");
	ft_printf("1234\n");
    printf("%%\n");
	ft_printf("%%\n");
    printf("%5%\n");
	ft_printf("%5%\n");
    printf("%-5%\n");
	ft_printf("%-5%\n");
	printf("%.0%\n");
	ft_printf("%.0%\n");
	//printf("%%\n", "test");
	ft_printf("%%\n", "test");
	//printf("%   %\n", "test");
	ft_printf("%   %\n", "test");
	printf("%x\n", 42);
	ft_printf("%x\n", 42);
	printf("%X\n", 42);
	ft_printf("%X\n", 42);
	printf("%x\n", 0);
	ft_printf("%x\n", 0);
	printf("%X\n", 0);
	ft_printf("%X\n", 0);
	printf("%x\n", -42);
	ft_printf("%x\n", -42);
	printf("%X\n", -42);
	ft_printf("%X\n", -42);
	//printf("%x\n", 4294967296);
	ft_printf("%x\n", 4294967296);
	//printf("%X\n", 4294967296);
	ft_printf("%X\n", 4294967296);
	printf("%x\n", test1);
	ft_printf("%x\n", test1);
	printf("%10x\n", 42);
	ft_printf("%10x\n", 42);
  	printf("%-10x\n", 42);
	ft_printf("%-10x\n", 42);
  	printf("%lx\n", 4294967296);
	ft_printf("%lx\n", 4294967296);
  //	printf("%llX\n", 4294967296);
	ft_printf("%llX\n", 4294967296);
  //	printf("%hx\n", 4294967296);
	ft_printf("%hx\n", 4294967296);
//	printf("%hhX\n", 4294967296);
  	ft_printf("%hhX\n", 4294967296);
//	printf("%llx\n", 9223372036854775807);
	ft_printf("%llx\n", 9223372036854775807);
//	printf("%llx\n", 9223372036854775808);
//	ft_printf("%llx\n", 9223372036854775808);
	printf("%010x\n", 542);
	ft_printf("%010x\n", 542);
	printf("%-15x\n", 542);
	ft_printf("%-15x\n", 542);
	printf("%2x\n", 542);
	ft_printf("%2x\n", 542);
	printf("%.2x\n", 5427);
	ft_printf("%.2x\n", 5427);
	printf("%5.2x\n", 5427);
	ft_printf("%5.2x\n", 5427);
	printf("%#x\n", 42);
	ft_printf("%#x\n", 42);
	//printf("%#llx\n", 9223372036854775807);
	ft_printf("%#llx\n", 9223372036854775807);
	printf("%#x\n", 0);
	ft_printf("%#x\n", 0);
	printf("%#x\n", 42);
	ft_printf("%#x\n", 42);
	printf("%#X\n", 42);
	ft_printf("%#X\n", 42);
	printf("%#8x\n", 42);
	ft_printf("%#8x\n", 42);
	printf("%#08x\n", 42);
	ft_printf("%#08x\n", 42);
//	printf("%#-08x\n", 42);
	ft_printf("%#-08x\n", 42);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %.x %.0x\n", 0, 0);
	ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	printf("@moulitest: %5.x %5.0x\n", 0, 0);
	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("%s\n", "abc");
	ft_printf("%s\n", "abc");
	printf("%s\n", "this is a string");
	ft_printf("%s\n", "this is a string");
	printf("%s \n", "this is a string");
	ft_printf("%s \n", "this is a string");
	printf("%s  \n", "this is a string");
	ft_printf("%s  \n", "this is a string");
	printf("this is a %s\n", "string");
	ft_printf("this is a %s\n", "string");
	printf("this is a %s\n", "string");
	ft_printf("%s is a string\n", "this");
	printf("Line Feed %s\n", "\\n");
	ft_printf("Line Feed %s\n", "\\n");
	printf("%10s is a string\n", "this");
	ft_printf("%10s is a string\n", "this");
	printf("%.2s is a string\n", "this");
	ft_printf("%.2s is a string\n", "this");
	printf("%5.2s is a string\n", "this");
	ft_printf("%5.2s is a string\n", "this");
	printf("%10s is a string\n", "");
	ft_printf("%10s is a string\n", "");
	printf("%.2s is a string\n", "");
	ft_printf("%.2s is a string\n", "");
	printf("%5.2s is a string\n", "");
	ft_printf("%5.2s is a string\n", "");
	printf("%-10s is a string\n", "this");
	ft_printf("%-10s is a string\n", "this");
	printf("%-.2s is a string\n", "this");
	ft_printf("%-.2s is a string\n", "this");
	printf("%-5.2s is a string\n", "this");
	ft_printf("%-5.2s is a string\n", "this");
	printf("%-10s is a string\n", "");
	ft_printf("%-10s is a string\n", "");
	printf("%-.2s is a string\n", "");
	ft_printf("%-.2s is a string\n", "");
	printf("%-5.2s is a string\n", "");
	ft_printf("%-5.2s is a string\n", "");
	printf("%s %s\n", "this", "is");
	ft_printf("%s %s\n", "this", "is");
	printf("%s %s %s\n", "this", "is", "a");
	ft_printf("%s %s %s\n", "this", "is", "a");
	printf("%s %s %s %s\n", "this", "is", "a", "multi");
	ft_printf("%s %s %s %s\n", "this", "is", "a", "multi");
//	printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	printf("@moulitest: %s\n", NULL);
	ft_printf("@moulitest: %s\n", NULL);
//	printf("%.2c\n", NULL);
	ft_printf("%.2c\n", NULL);
	printf("%s %s\n", NULL, "string");
	ft_printf("%s %s\n", NULL, "string");
	printf("%c\n", 42);
	ft_printf("%c\n", 42);
	printf("%5c\n", 42);
	ft_printf("%5c\n", 42);
	printf("%-5c\n", 42);
	ft_printf("%-5c\n", 42);
	printf("@moulitest: %c\n", 0);
	ft_printf("@moulitest: %c\n", 0);
	printf("%2c\n", 0);
	ft_printf("%2c\n", 0);
	printf("null %c and text\n", 0);
	ft_printf("null %c and text\n", 0);
	//printf("% c\n", 0);
	ft_printf("% c\n", 0);
	printf("%o\n", 40);
	ft_printf("%o\n", 40);
	printf("%5o\n", 41);
	ft_printf("%5o\n", 41);
	printf("%05o\n", 42);
	ft_printf("%05o\n", 42);
	printf("%-5o\n", 2500);
	ft_printf("%-5o\n", 2500);
	printf("%#6o\n", 2500);
	ft_printf("%#6o\n", 2500);
	printf("%-#6o\n", 2500);
	ft_printf("%-#6o\n", 2500);
//	printf("%-05o\n", 2500);
	ft_printf("%-05o\n", 2500);
	printf("%-5.10o\n", 2500);
	ft_printf("%-5.10o\n", 2500);
	printf("%-10.5o\n", 2500);
	ft_printf("%-10.5o\n", 2500);
	printf("@moulitest: %o\n", 0);
	ft_printf("@moulitest: %o\n", 0);
	printf("@moulitest: %.o %.0o\n", 0, 0);
	ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	printf("@moulitest: %5.o %5.0o\n", 0, 0);
	ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
	printf("@moulitest: %#.o %#.0o\n", 0, 0);
	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	printf("@moulitest: %.10o\n", 42);
	ft_printf("@moulitest: %.10o\n", 42);
	printf("%d\n", 1);
	ft_printf("%d\n", 1);
	printf("the %d\n", 1);
	ft_printf("the %d\n", 1);
	printf("%d is one\n", 1);
	ft_printf("%d is one\n", 1);
	printf("%d\n", -1);
	ft_printf("%d\n", -1);
	printf("%d\n", 4242);
	ft_printf("%d\n", 4242);
	printf("%d\n", -4242);
	ft_printf("%d\n", -4242);
	printf("%d\n", 2147483647);
	ft_printf("%d\n", 2147483647);
//	printf("%d\n", 2147483648);
	ft_printf("%d\n", 2147483648);
//	printf("%d\n", -2147483648);
	ft_printf("%d\n", -2147483648);
//	printf("%d\n", -2147483649);
	ft_printf("%d\n", -2147483649);
	printf("% d\n", 42);
	ft_printf("% d\n", 42);
	printf("% d\n", -42);
	ft_printf("% d\n", -42);
	printf("%+d\n", 42);
	ft_printf("%+d\n", 42);
	printf("%+d\n", -42);
	ft_printf("%+d\n", -42);
	printf("%+d\n", 0);
	ft_printf("%+d\n", 0);
	//printf("%+d", 4242424242424242424242);
	//ft_printf("%+d", 4242424242424242424242);
//	printf("% +d\n", 42);
	ft_printf("% +d\n", 42);
//	printf("% +d\n", -42);
	ft_printf("% +d\n", -42);
//	printf("%+ d\n", 42);
	ft_printf("%+ d\n", 42);
//	printf("%+ d\n", -42);
	ft_printf("%+ d\n", -42);
//	printf("%  +d\n", 42);
	ft_printf("%  +d\n", 42);
//	printf("%  +d\n", -42);
	ft_printf("%  +d\n", -42);
//	printf("%+  d\n", 42);
	ft_printf("%+  d\n", 42);
//	printf("%+  d\n", -42);
	ft_printf("%+  d\n", -42);
//	printf("% ++d\n", 42);
	ft_printf("% ++d\n", 42);
//	printf("% ++d\n", -42);
	ft_printf("% ++d\n", -42);
//	printf("%++ d\n", 42);
	ft_printf("%++ d\n", 42);
//	printf("%++ d\n", -42);
	ft_printf("%++ d\n", -42);
	printf("%0d\n", -42);
	ft_printf("%0d\n", -42);
	printf("%00d\n", -42);
	ft_printf("%00d\n", -42);
	printf("%5d\n", 42);
	ft_printf("%5d\n", 42);
	printf("%05d\n", 42);
	ft_printf("%05d\n", 42);
	printf("%0+5d\n", 42);
	ft_printf("%0+5d\n", 42);
	printf("%5d\n", -42);
	ft_printf("%5d\n", -42);
	printf("%05d\n", -42);
	ft_printf("%05d\n", -42);
	printf("%0+5d\n", -42);
	ft_printf("%0+5d\n", -42);
	printf("%-5d\n", 42);
	ft_printf("%-5d\n", 42);
//	printf("%-05d\n", 42);
	ft_printf("%-05d\n", 42);
	printf("%-5d\n", -42);
	ft_printf("%-5d\n", -42);
//	printf("%-05d\n", -42);
	ft_printf("%-05d\n", -42);
//	printf("%hd\n", 32767);
	ft_printf("%hd\n", 32767);
	//printf("%hd\n", −32768);
	//ft_printf("%hd\n", −32768);
//	printf("%hd\n", 32768);
	ft_printf("%hd\n", 32768);
	//printf("%hd\n", −32769);
	//ft_printf("%hd\n", −32769);
//	printf("%hhd\n", 127);
	ft_printf("%hhd\n", 127);
//	printf("%hhd\n", 128);
	ft_printf("%hhd\n", 128);
//	printf("%hhd\n", -128);
	ft_printf("%hhd\n", -128);
//	printf("%hhd\n", -129);
	ft_printf("%hhd\n", -129);
//	printf("%ld\n", 2147483647);
	ft_printf("%ld\n", 2147483647);
	printf("%ld\n", -2147483648);
	ft_printf("%ld\n", -2147483648);
	printf("%ld\n", 2147483648);
	ft_printf("%ld\n", 2147483648);
	printf("%ld\n", -2147483649);
	ft_printf("%ld\n", -2147483649);
//	printf("%lld\n", 9223372036854775807);
	ft_printf("%lld\n", 9223372036854775807);
//	printf("%lld\n", -9223372036854775808);
//	ft_printf("%lld\n", -9223372036854775808);
	printf("%d\n", 1);
	ft_printf("%d\n", 1);
	printf("%d %d\n", 1, -2);
	ft_printf("%d %d\n", 1, -2);
	printf("%d %d %d\n", 1, -2, 33);
	ft_printf("%d %d %d\n", 1, -2, 33);
	printf("%d %d %d %d\n", 1, -2, 33, 42);
	ft_printf("%d %d %d %d\n", 1, -2, 33, 42);
//	printf("%d %d %d %d gg!\n", 1, -2, 33, 42, 0);
	ft_printf("%d %d %d %d gg!\n", 1, -2, 33, 42, 0);
	printf("%4.15d\n", 42);
	ft_printf("%4.15d\n", 42);
	printf("%.2d\n", 4242);
	ft_printf("%.2d\n", 4242);
	printf("%.10d\n", 4242);
	ft_printf("%.10d\n", 4242);
	printf("%10.5d\n", 4242);
	ft_printf("%10.5d\n", 4242);
	printf("%-10.5d\n", 4242);
	ft_printf("%-10.5d\n", 4242);
	printf("% 10.5d\n", 4242);
	ft_printf("% 10.5d\n", 4242);
	printf("%+10.5d\n", 4242);
	ft_printf("%+10.5d\n", 4242);
	printf("%-+10.5d\n", 4242);
	ft_printf("%-+10.5d\n", 4242);
	printf("%03.2d\n", 0);
	ft_printf("%03.2d\n", 0);
	printf("%03.2d\n", 1);
	ft_printf("%03.2d\n", 1);
	printf("%03.2d\n", -1);
	ft_printf("%03.2d\n", -1);
	printf("@moulitest: %.10d\n", -42);
	ft_printf("@moulitest: %.10d\n", -42);
	printf("@moulitest: %.d %.0d\n", 42, 43);
	ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	printf("@moulitest: %.d %.0d\n", 0, 0);
	ft_printf("@moulitest: %.d %.0d\n", 0, 0);
	printf("@moulitest: %5.d %5.0d\n", 0, 0);
	ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
	printf("%u\n", 0);
	ft_printf("%u\n", 0);
	printf("%u\n", 1);
	ft_printf("%u\n", 1);
	ft_printf("%u\n", -1);
	ft_printf("%u\n", -1);
//	printf("%u\n", 4294967295);
	ft_printf("%u\n", 4294967295);
//	printf("%u\n", 4294967296);
	ft_printf("%u\n", 4294967296);
//	printf("%5u\n", 4294967295);
	ft_printf("%5u\n", 4294967295);
//	printf("%15u\n", 4294967295);
	ft_printf("%15u\n", 4294967295);
//	printf("%-15u\n", 4294967295);
	ft_printf("%-15u\n", 4294967295);
//	printf("%015u\n", 4294967295);
	ft_printf("%015u\n", 4294967295);
//	printf("% u\n", 4294967295);
	ft_printf("% u\n", 4294967295);
//	printf("%+u\n", 4294967295);
	ft_printf("%+u\n", 4294967295);
	printf("%lu\n", 4294967295);
	ft_printf("%lu\n", 4294967295);
	printf("%lu\n", 4294967296);
	ft_printf("%lu\n", 4294967296);
	ft_printf("%lu\n", -42);
	ft_printf("%lu\n", -42);
//	printf("%llu\n", 4999999999);
	ft_printf("%llu\n", 4999999999);
	printf("@moulitest: %.5u\n", 42);
	ft_printf("@moulitest: %.5u\n", 42);
	return (0);
}
