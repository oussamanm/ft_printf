#include "includes/ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <math.h>

void	ft_print_bin(long n);

//cspdiouexXbvgrkf%"
int main(void)
{
	//double	val = 0;
	//double	val = NAN;
	//long double	val = LDBL_MAX;
	//float		val2 = 1.79769;
	//double			valf = 3.40282e+38;
	//double			val = 7.31960296494528966981362954694E-304;
	double		val2 = 5.5626846514486572442618911564E-309;
	//int	val2 = 625;
	//d.d = val;
	char	*val = "hello World";
	//printf("\n--------Lf-------\n");
	//ft_printf("%s\n",ft_l_double_cal(&d));
//	printf("----ft_printf--\n");
	int n1 = ft_printf("ft_printf : %-50.70lf\n",val2);
	int n2 = printf("printf    : %-50.70lf\n", val2);
	printf("Result : %d and %d\n", n1, n2);
	//printf("------printf----\n");
	//printf("%.00Lf\n",val);
	//ft_l_double_cal(&d);
	//printf("%.200Lf\n",val);
/*	ft_printf("ft_printf Hello World\t %f\n", val);
	ft_printf("ft_printf Hello World\t %f\n", val);
	printf("printf Hello World\t %lf\n", val);
	printf("printf Hello World\t %lf \n", val);
	printf("printf Hello World\t %lf\n", val);*/
 /*int a = 253; 
  	printf("|{red}%10.2u{eoc}|\n", 5485);
  	ft_printf("|{red}%10.2u|\n", 5485);

    printf("|{red}%10.2u{eoc}|\n", 5485);
    ft_printf("|{red}%10.2u{eoc}|\n", 5485);

    printf("|{red}%10p{eoc}|\n", &a);
    ft_printf("|{red}%10p{eoc}|\n", &a);


    printf("|{red}%c{eoc}|\n", 'B');
    ft_printf("|{red}%c{eoc} contient : {green}%c{eoc}|\n", 'B');
      printf("|{green}%- .35d{eoc}|\n", -5468);
  	ft_printf("|{green}%- .35d{eoc}|", -5468);*/
  	   printf("|%- .35d|\n", -54687);
  	ft_printf("|%- .35d|\n\n", -54687);
	printf("\n---------------------------------\n");
  	   printf("|%- .10d|\n", 54687);
  	ft_printf("|%- .10d|\n\n", 54687);

  	   printf("|{green}%45.1d{eoc}|\n", 546876);
  	ft_printf("|{green}%45.1d{eoc}|\n", 546876);
  	   printf("|%100.d|\n", 546876);
  	ft_printf("|%100.d|\n\n", 546876);
  	   printf("|%-32.50d|\n", 546876);
  	ft_printf("|%-32.50d|\n\n", 546876);
  	   printf("|%.50d|\n", 546876);
  	ft_printf("|%.50d|\n\n", 546876);
  	   printf("|%.2d|\n", 546876);
  	ft_printf("|%.2d|\n\n", 546876);
  	   printf("|%-.3d|\n", 546876);
  	ft_printf("|%-.3d|\n\n", 546876);
  	   printf("|%-.100d|\n", 546876);
  	ft_printf("|%-.100d|\n\n", 546876);
  	   printf("|%4d|\n", 546876);
  	ft_printf("|%4d|\n\n", 546876);
  	   printf("|%5d|\n", 546876);
  	ft_printf("|%5d|\n\n", 546876);
  	   printf("|%-3d|\n", 546876);
  	ft_printf("|%-3d|\n\n", 546876);
  	   printf("|%-52d|\n", 546876);
  	ft_printf("|%-52d|\n\n", 546876);
	   printf("|%+08.10i|\n", -13);
	ft_printf("|%+08.10i|\n", -13);
printf("\n---------------------------------\n");
	   printf("|%+08.2i|\n", -13);
	ft_printf("|%+08.2i|\n", -13);
	   printf("|%+03.10i|\n", -13);
	ft_printf("|%+03.10i|\n", -13);
	   printf("|%+02.1i|\n", -113);
	ft_printf("|%+02.1i|\n", -113);
	   printf("|%08i|\n", -71);
	ft_printf("|%08i|\n", -71);

	 printf("|%5d|\n", -714);
ft_printf("|%5d|\n", -714);

   printf("|%00+10.4d|\n", 0);
ft_printf("|%00+10.4d|\n", 0);

printf ("|%+++d|\n", 0);
ft_printf ("|%+++d|\n", 0);

printf ("|%#X|\n", 0);
ft_printf ("|%#X|\n", 0);

printf ("|%.5d|\n", -7144);
ft_printf ("|%.5d|\n", -7144);

printf ("|%08o|\n", 013);
ft_printf ("|%08o|\n", 013);

printf ("|%2u|\n", 17894);
ft_printf ("|%2u|\n", 17894);

printf ("|%.u|\n", 0);
ft_printf ("|%.u|\n", 0);

printf ("|%08i|\n", -71);
ft_printf ("|%08i|\n", -71);

printf ("|%4d|\n", 1);
ft_printf ("|%4d|\n", 1);

printf ("|%2u|\n", 17894);
ft_printf ("|%2u|\n", 17894);

printf ("|%5d|\n", -17894);
ft_printf ("|%5d|\n", -17894);

printf ("|%08i|\n", -17894);
ft_printf ("|%08i|\n", -17894);
printf("---**-*-*00+10.4d-*-*-*----\n");

printf ("|%12.5d|\n", -17894);
ft_printf ("|%12.5d|\n", -17894);

printf ("|%4d|\n", 0);
ft_printf ("|%4d|\n", 0);

printf ("|%10.4d|\n", 0);
ft_printf ("|%10.4d|\n", 0);

printf ("|%00+10.4d|\n", 15);
ft_printf ("|%00+10.4d|\n", 15);
printf("---**-*-*-*-*-*----\n");

printf ("|%.5d|\n", 4);
ft_printf ("|%.5d|\n", 4);
printf ("|%d|\n", -21);
ft_printf ("|%d|\n", -21);

printf("---**-*-|4.1d|*-*-*-*----\n");
printf ("|%4.1d|\n", -71455);
ft_printf ("|%4.1d|\n", -71455);

printf ("|%4.d|\n", -71455);
ft_printf ("|%4.d|\n", -71455);

printf ("|%15.1d|\n", -71455);
ft_printf ("|%15.1d|\n", -71455);

printf ("|%15.d|\n", -71455);
ft_printf ("|%15.d|\n", -71455);

printf ("|%-d|\n", -714);
ft_printf ("|%-d|\n", -714);
printf("---**-*-*-*-*-*----\n");
printf ("|%1d|\n", -4444);
ft_printf ("|%1d|\n", -4444);
printf("---**-*-*-*-*-*----\n");
printf ("|%-1d|\n", -714);
ft_printf ("|%-1d|\n", -714);
printf("---**-*-*-*-*-*----\n");
printf ("|%.d|\n", -714);
ft_printf ("|%.d|\n", -714);

printf ("|%-.d|\n", -714);
ft_printf ("|%-.d|\n", -714);

printf ("|%.1d|\n", -714);
ft_printf ("|%.1d|\n", -714);

printf ("|%-.1d|\n", -714);
ft_printf ("|%-.1d|\n", -714);

printf ("|%4.3d|\n", 1255);
ft_printf ("|%4.3d|\n", 1255);

printf ("|%10.9d|\n", 2121);
ft_printf ("|%10.9d|\n", 2121);

printf ("|%2.15d|\n", 232);
ft_printf ("|%2.15d|\n", 232);

printf ("|%10.4d|\n", 4555);
ft_printf ("|%10.4d|\n", 4555);


   printf ("|%.0d|\n", 0);
ft_printf ("|%.0d|\n", 0);

	 printf ("|%+.i|\n", 0);
ft_printf ("|%+.i|\n", 0);


	 printf ("|%2.5hd|\n", (short)-2345);
ft_printf ("|%2.5hd|\n", (short)-2345);

	 printf ("|% 1.3hhd|\n", (char)-2345);
ft_printf ("|% 1.3hhd|\n", (char)-2345);

   printf ("|% 20.12ld|\n", 0x11ffaa147);
ft_printf ("|% 20.12ld|\n", 0x11ffaa147);

   printf ("|% 20.12lld|\n", (long long)0x11ffaa147);
ft_printf ("|% 20.12lld|\n", (long long)0x11ffaa147);


   printf ("|toto%.0d et %+.i et  !!!|\n", 0, 0);
ft_printf ("|toto%.0d et %+.i et  !!!|\n", 0, 0);

   printf ("|%#o|\n", 0);
ft_printf ("|%#o|\n", 0);
printf ("|%#o|\n", 1000);
ft_printf ("|%#o|\n", 1000);
   printf ("|%3d|\n", 0xa43);
ft_printf ("|%3d|\n", 0xa43);
   printf ("|%.10d|\n", 0x1234abcd);
ft_printf ("|%.10d|\n", 0x1234abcd);

   printf ("|%20d|\n", 0x123456bc);
ft_printf ("|%20d|\n", 0x123456bc);

   printf ("|%20.5s|\n", "asdasd");
ft_printf ("|%20.5s|\n", "asdasd");

printf("|%%|\n");
ft_printf("|%%|\n");
printf("|% %|\n");
ft_printf("|% %|\n");
printf("|%#%|\n");
ft_printf("|%#%|\n");
printf("|%.8%|\n");
ft_printf("|%.8%|\n");
printf("|%8%|\n");
ft_printf("|%8%|\n");
printf("|%+8%|\n");
ft_printf("|%+8%|\n");
   printf("|%------8%|\n");
ft_printf("|%------8%|\n");
printf("|%10d|\n", 455);
ft_printf("|%10d|\n", 455);
printf("|%08i|\n", 455);
ft_printf("|%08i|\n", 455);
   printf ("|{red}%#o{eoc}|\n", 1000);
ft_printf ("|{red}%#o{eoc}|\n", 1000);

   printf ("|%d|\n", 0xff7744);
ft_printf ("|%d|\n", 0xff7744);

   printf ("|%#X|\n", 0);
ft_printf ("|%#X|\n", 0);

   printf ("|%#x|\n", 0x78aa);
ft_printf ("|%#x|\n", 0x78aa);

   printf ("|%#x|\n", 0xff7744);
ft_printf ("|%#x|\n", 0xff7744);

printf("\n---------------------------------\n");

   printf("|%-4c| |%-c| ??\n", '\0', 0);
ft_printf("|%-4c| |%-c| ??\n", '\0', 0);

   printf ("|%lx|\n", (unsigned long)-178965423);
ft_printf ("|%lx|\n", (unsigned long)-178965423);


printf ("|%llx|\n", (unsigned long long)0xaaffee11996677);
ft_printf ("|%llx|\n", (unsigned long long)0xaaffee11996677);


   printf ("|%#o|\n", 0);
ft_printf ("|%#o|\n", 0);

   printf ("|%#o|\n", 1000);
ft_printf ("|%#o|\n", 1000);

   printf ("|%1o|\n", 0);
ft_printf ("|%1o|\n", 0);

   printf ("|%.2o|\n", 0);
ft_printf ("|%.2o|\n", 0);

   printf ("|%#4o|\n", 0);
ft_printf ("|%#4o|\n", 0);

   printf ("|%llo|\n", (unsigned long long)-127);
ft_printf ("|%llo|\n", (unsigned long long)-127);

    printf("|t%04.2o%#2oet %#-8.3o titi|\n", 0, 0, 0);
 ft_printf("|t%04.2o%#2oet %#-8.3o titi|\n", 0, 0, 0);

   printf ("|%#7.5X|\n", 0xab);
ft_printf ("|%#7.5X|\n", 0xab);

printf ("|%#7.5x|\n", 0xab);
ft_printf ("|%#7.5x|\n", 0xab);

   printf ("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
ft_printf ("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);


   printf ("|%#0012x|\n", 0xe);
ft_printf ("|%#0012x|\n", 0xe);

   printf ("|%0012d|\n", 0xab);
ft_printf ("|%0012d|\n", 0xab);


   printf ("|cc%#.4X et %#0012x %#04hX !!|\n", 0xaef, 0xe, (unsigned short)0);
ft_printf ("|cc%#.4X et %#0012x %#04hX !!|\n", 0xaef, 0xe, (unsigned short)0);

   printf ("|osef ! %#9llX et %-12hhx|\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
ft_printf ("|osef ! %#9llX et %-12hhx|\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);

   printf ("|{red}osef ! %#9llX{eoc}|\n", (unsigned long long)-1248759650);
ft_printf ("|{red}osef ! %#9llX{eoc}|\n", (unsigned long long)-1248759650);

   printf ("|%-12hhx|\n",(unsigned char)-1478223695);
ft_printf ("|%-12hhx|\n",(unsigned char)-1478223695);

   printf ("|%#04X|\n",0);
ft_printf ("|%#04X|\n",0);


   printf ("|%.4X|\n",0x037a);
ft_printf ("|%.4X|\n",0x037a);

   printf ("|toto %0##0.4X%#4.2xet c'est fini |\n", 0x037a, 0x9e);
ft_printf ("|toto %0##0.4X%#4.2xet c'est fini |\n", 0x037a, 0x9e);

   printf ("|toto %##.0xet %#.X%###.1x|\n", 0, 0, 0);
ft_printf ("|toto %##.0xet %#.X%###.1x|\n", 0, 0, 0);

   printf ("|%0#10.0x %0#x|\n", 12345, 0);
ft_printf ("|%0#10.0x %0#x|\n", 12345, 0);


printf ("|%#0x|\n", 0);
ft_printf ("|%#0x|\n", 0);

   printf ("|%#10.2x|\n", 0);
ft_printf ("|%#10.2x|\n", 0);

   printf ("|%.10x|\n", 0x1234abcd);
ft_printf ("|%.10x|\n", 0x1234abcd);


    printf ("|%0#10.0x|\n", 0);
 ft_printf ("|%0#10.0x|\n", 0);


 printf("|%f|\n", (float)(0x7fc00000));
ft_printf("|%f|\n", (float)(0x7fc00000));


   printf("| %-+12.7d and %0 4i %04.2% et %c titi|\n", 125, 124, 256);
ft_printf("| %-+12.7d and %0 4i %04.2% et %c titi|\n", 125, 124, 256);


   printf ("|%0 4i|\n", 124);
ft_printf ("|%0 4i|\n", 124);

   printf ("|%#10.2x|\n", 0);
ft_printf ("|%#10.2x|\n", 0);

   printf ("|et %c titi|\n", 256);
ft_printf ("|et %c titi|\n", 256);


return 0;
}
