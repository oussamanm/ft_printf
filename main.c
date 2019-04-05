#include "./includes/ft_printf.h"
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
	/*ft_printf("-test first:%28s and sec:-\n","aabbccddee");
	printf("-test first:%8s and sec:-\n\n","aabbccddee");*/

	/*ft_printf("-test first:%+8.10d:-\n",1337);
	   printf("-test first:%+8.10d:-\n",1337);*/
	//short int i_short = 1234;
	//int  i_long = 3123123123;
	//printf("size = %lu\n",sizeof(long));
	//printf("size lon lon %lu\n",sizeof(long long));

	int 	rtn1,rtn2;
	rtn1 = rtn2 = 0;
	printf("------------------- Type d,i ------------------- \n");
	printf("\n-------1--------\n");
	rtn1 =	 printf("|%08hd|",(short int )-123);
	printf("\n");
	rtn2 = ft_printf("|%08hd|",(short int )-123);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------2-------\n");
	rtn1 =	 printf("|%.li|",(long int)0);
	printf("\n");
	rtn2 = ft_printf("|%.li|",(long int)0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n-------3--------\n");
	rtn1 =	 printf("|%.d|",0);
	printf("\n");
	rtn2 = ft_printf("|%.d|",0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");
	
	printf("\n--------4-------\n");
	rtn1 =	 printf("|%+.d|",-123);
	printf("\n");
	rtn2 = ft_printf("|%+.d|",-123);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------5-------\n");
	rtn1 =	 printf("|% 20.10d|",13377);
	printf("\n");
	rtn2 = ft_printf("|% 20.10d|",13377);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n-------6--------\n");
	rtn1 =	 printf("|%+-8d|",12345678);
	printf("\n");
	rtn2 = ft_printf("|%+-8d|",12345678);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n------7---------\n");
	rtn1 =	 printf("|%.d|",0);
	printf("\n");
	rtn2 = ft_printf("|%.d|",0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");
	
	printf("\n--------8-------\n");
	rtn1 =	 printf("|%8.d|",0);
	printf("\n");
	rtn2 = ft_printf("|%8.d|",0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------9-------\n");
	rtn1 =	 printf("|% 10d|",13377);
	printf("\n");
	rtn2 = ft_printf("|% 10d|",13377);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------10-------\n");
	rtn1 =	 printf("|%+015d|",12345678);
	printf("\n");
	rtn2 = ft_printf("|%+015d|",12345678);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n--------11-------\n");
	rtn1 =	 printf("|%010d|",0);
	printf("\n");
	rtn2 = ft_printf("|%010d|",0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------12-------\n");
	rtn1 =	 printf("|% d|",0);
	printf("\n");
	rtn2 = ft_printf("|% d|",0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------13-------\n");
	rtn1 =	 printf("|%-15.15d|",12345678);
	printf("\n");
	rtn2 = ft_printf("|%-15.15d|",12345678);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("------------------- Type %% ------------------- \n");

	printf("\n--------12-------\n");
	rtn1 =	 printf("|% %|");
	printf("\n");
	rtn2 = ft_printf("|% %|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------13-------\n");
	rtn1 =	 printf("|%%%%%010%|");
	printf("\n");
	rtn2 = ft_printf("|%%%%%010%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------12-------\n");
	rtn1 =	 printf("|%+20.10%|");
	printf("\n");
	rtn2 = ft_printf("|%+20.10%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------13-------\n");
	rtn1 =	 printf("|%15%|");
	printf("\n");
	rtn2 = ft_printf("|%15%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------13-------\n");
	rtn1 =	 printf("|%.%|");
	printf("\n");
	rtn2 = ft_printf("|%.%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------12-------\n");
	rtn1 =	 printf("|% 2%|");
	printf("\n");
	rtn2 = ft_printf("|% 2%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------13-------\n");
	rtn1 =	 printf("|% -30%|");
	printf("\n");
	rtn2 = ft_printf("|% -30%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------12-------\n");
	rtn1 =	 printf("|%%|");
	printf("\n");
	rtn2 = ft_printf("|%%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n--------13-------\n");
	rtn1 =	 printf("|%% %% %%%0%|");
	printf("\n");
	rtn2 = ft_printf("|%% %% %%%0%|");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	
	float flt  = 0.1231321;
	double dbl = 250.1321354534564;
	long double ldb = 250.1321354534564;

	printf("\n-------1-------\n");
	rtn1 =	 printf("|%f|",flt);
	printf("\n");
	rtn2 = ft_printf("|%f|",flt);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------2-------\n");
	rtn1 =	 printf("|%+10lf|",dbl);
	printf("\n");
	rtn2 = ft_printf("|%+10lf|",dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n---------3------\n");
	rtn1 =	  printf("|%+030lf|",dbl);
	printf("\n");
	rtn2 = ft_printf("|%+030lf|",dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n---------4------\n");
	rtn1 =	  printf("|%+20lf|",dbl);
	printf("\n");
	rtn2 = ft_printf("|%+20lf|",dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n---------5------\n");
	rtn1 =	  printf("|%+15.10lf|",dbl);
	printf("\n");
	rtn2 = ft_printf("|%+15.10lf|",dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n---------6------\n");
	rtn1 =	  printf("|%#030lf|",-dbl);
	printf("\n");
	rtn2 = ft_printf("|%#030lf|",-dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n---------7------\n");
	rtn1 =	  printf("|% 010.12lf|",+dbl);
	printf("\n");
	rtn2 = ft_printf("|% 010.12lf|",+dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------8-------\n");
	rtn1 =	  printf("|%+.30lf|",dbl);
	printf("\n");
	rtn2 = ft_printf("|%+.30lf|",dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------9-------\n");
	rtn1 =	  printf("|% .lf|",-dbl);
	printf("\n");
	rtn2 = ft_printf("|% .lf|",-dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------10-------\n");
	rtn1 =	 printf("|%-20.10lf|",dbl);
	printf("\n");
	rtn2 = ft_printf("|%-20.10lf|",dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------12-------\n");
	rtn1 =	 printf("|%.100Lf|",ldb);
	printf("\n");
	rtn2 = ft_printf("|%.100Lf|",ldb);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------13-------\n");
	rtn1 =	  printf("|%#.100Lf|",(long double)0);
	printf("\n");
	rtn2 = ft_printf("|%#.100Lf|",(long double)0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------14-------\n");
	rtn1 =	  printf("|%#+.Lf|",(long double)0);
	printf("\n");
	rtn2 = ft_printf("|%#+.Lf|",(long double)0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------15-------\n");
	rtn1 =	  printf("|%#.10Lf|",(long double)0);
	printf("\n");
	rtn2 = ft_printf("|%#.10Lf|",(long double)0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	//// NaN and Infinity
	float ninf=-INFINITY;
	float ninf2=INFINITY;

	printf("\n--------16-------\n");
	rtn1 =	  printf("|%f|",2.0*ninf);
	printf("\n");
	rtn2 = ft_printf("|%f|",2.0*ninf);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------17-------\n");
	rtn1 =	  printf("|% .10f|",sqrt (-1));
	printf("\n");
	rtn2 = ft_printf("|% .10f|",sqrt (-1));
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n--------18-------\n");
	rtn1 =	  printf("|%#-10f|",sqrt (-1));
	printf("\n");
	rtn2 = ft_printf("|%#-10f|",sqrt (-1));
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n-------- Max -------\n");
	rtn1 =	  printf("|%#.100Lf|",LDBL_MAX);
	printf("\n");
	rtn2 = ft_printf("|%#.100Lf|",LDBL_MAX);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n-------- 1 -------\n");
	rtn1 =	  printf("|%lf|",(double)0);
	printf("\n");
	rtn2 = ft_printf("|%lf|",(double)0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- 2 -------\n");
	rtn1 =	  printf("|%lf|",dbl);
	printf("\n");
	rtn2 = ft_printf("|%lf|",dbl);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


	printf("\n-------- 1 -------\n");
	rtn1 = 	 printf ("|cc%#.4X et %#0012x %#04hX !!|\n", 0xaef, 0xe, (unsigned short)0);
	rtn2 = ft_printf ("|cc%#.4X et %#0012x %#04hX !!|\n", 0xaef, 0xe, (unsigned short)0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- 2 -------\n");
	rtn1 = 	  printf ("|osef ! %#9llX et %-12hhx|\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
	rtn2 = ft_printf ("|osef ! %#9llX et %-12hhx|\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- 3 -------\n");
	rtn1 = 	  printf ("|osef ! %#9llX|\n", (unsigned long long)-1248759650);
	rtn2 = ft_printf ("|osef ! %#9llX|\n", (unsigned long long)-1248759650);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- 4 -------\n");
	rtn1 =    printf ("|%-12hhx|\n",(unsigned char)-1478223695);
	rtn2 = ft_printf ("|%-12hhx|\n",(unsigned char)-1478223695);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- 5 -------\n");
	rtn1 =    printf ("|%20.10lx|\n",(unsigned long)-1478223695);
	rtn2 = ft_printf ("|%20.10lx|\n",(unsigned long)-1478223695);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- 6 -------\n");
	rtn1 =    printf ("|%10.hhx|\n",(unsigned char)0);
	rtn2 = ft_printf ("|%10.hhx|\n",(unsigned char)0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("------------------- Type s,c ------------------- \n");
	int i = 0;

	printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%.s|","");
	printf("\n");
	rtn2 = ft_printf("|%.s|","");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%-10.s|","abdsdasd");
	printf("\n");
	rtn2 = ft_printf("|%-10.s|","abdsdasd");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%-5.10s|","oussama nouamane");
	printf("\n");
	rtn2 = ft_printf("|%-5.10s|","oussama nouamane");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%100s|",NULL);
	printf("\n");
	rtn2 = ft_printf("|%100s|",NULL);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%.%%% %-20s|","aaaa");
	printf("\n");
	rtn2 = ft_printf("|%.%%% %-20s|","aaaa");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%.2s|",NULL);
	printf("\n");
	rtn2 = ft_printf("|%.2s|",NULL);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%s|","\0\0");
	printf("\n");
	rtn2 = ft_printf("|%s|","\0\0");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%10s|","\0");
	printf("\n");
	rtn2 = ft_printf("|%10s|","\0");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%.0s|","asdasdasdasdasdasd");
	printf("\n");
	rtn2 = ft_printf("|%.0s|","asdasdasdasdasdasd");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");


		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%.s|","");
	printf("\n");
	rtn2 = ft_printf("|%.s|","");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%-10.s|","abdsdasd");
	printf("\n");
	rtn2 = ft_printf("|%-10.s|","abdsdasd");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%-5.10s|","oussama nouamane");
	printf("\n");
	rtn2 = ft_printf("|%-5.10s|","oussama nouamane");
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	////  ------------------- C ----------------///

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%100c|",0);
	printf("\n");
	rtn2 = ft_printf("|%100c|",0);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%.%%% %-20c|",-1);
	printf("\n");
	rtn2 = ft_printf("|%.%%% %-20c|",-1);
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%-102c|",'c');
	printf("\n");
	rtn2 = ft_printf("|%-102c|",'c');
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%c|",'\0');
	printf("\n");
	rtn2 = ft_printf("|%c|",'\0');
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%10c|",'A');
	printf("\n");
	rtn2 = ft_printf("|%10c|",'A');
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

		printf("\n-------- %d -------\n",i++);
	rtn1 =	  printf("|%-1c|",'A');
	printf("\n");
	rtn2 = ft_printf("|%-1c|",'A');
	printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n---------------\n");

	
	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%x", -42);printf("\n");
	rtn2 = printf("%x", -42);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%X", -42);printf("\n");
	rtn2 =printf("%X", -42);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%x", (unsigned int)4294967296);printf("\n");
	rtn2 =printf("%x", (unsigned int)4294967296);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%X", (unsigned int)4294967296);printf("\n");
	rtn2 =printf("%X", (unsigned int)4294967296);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%hx", (unsigned short)4294967296);printf("\n");
	rtn2 =printf("%hx", (unsigned short)4294967296);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");


	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("%hhX", (unsigned char)4294967296);printf("\n");
	rtn2 =printf("%hhX", (unsigned char)4294967296);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("%lx", 4294967295);printf("\n");
	rtn2 =printf("%lx", 4294967295);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("%lx", 4294967296);printf("\n");
	rtn2 =printf("%lx", 4294967296);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("%lx", -4294967296);printf("\n");
	rtn2 =printf("%lx", -4294967296);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%lx", -4294967297);printf("\n");
	rtn2 = printf("%lx", -4294967297);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("%2c", 0);printf("\n");
	rtn2 = printf("%2c", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("@moulitest: %c", 0);printf("\n");
	rtn2 = printf("@moulitest: %c", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("%2c", 0);printf("\n");
	rtn2 = printf("%2c", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("null %c and text", 0);printf("\n");
	rtn2 = printf("null %c and text", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%c", 0);printf("\n");
	rtn2 = printf("%c", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("------------------- Type o ------------------- \n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%#-5o", 2500);printf("\n");
	rtn2 = printf("%#-5o", 2500);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%5.o", 0);printf("\n");
	rtn2 = 	   printf("%5.o", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 =  ft_printf("%10.0o", 0);printf("\n");
	rtn2 = 	   printf("%10.0o", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("@moulitest: %#.o %#.0o", 0, 0);printf("\n");
	rtn2 = 	   printf("@moulitest: %#.o %#.0o", 0, 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 = ft_printf("@moulitest: %#10.o", 0);printf("\n");
	rtn2 = 	   printf("@moulitest: %#10.o", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		printf("\n");


	/////// ***** Type o //////////////
	printf("\n-------- %d -------\n",i++);
	rtn1 =    printf ("|%#o|\n", 0);
	rtn2 = ft_printf ("|%#o|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%#.o|\n", 0);
	rtn2 =ft_printf ("|%#.o|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%#10o|\n", 0);
	rtn2 = ft_printf ("|%#10o|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%0.0o|\n", 0);
	rtn2 =ft_printf ("|%0.0o|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%#12.9o|\n", 12);
	rtn2 =ft_printf ("|%#12.9o|\n", 12);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%#o|\n", -12322);
	rtn2 =ft_printf ("|%#o|\n", -12322);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%llo|\n", INT64_MAX);
	rtn2 =ft_printf ("|%llo|\n", INT64_MAX);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%hho|\n", (unsigned char)12);
	rtn2 =ft_printf ("|%hho|\n", (unsigned char)12);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|t%04.2o%#2oet %#-8.3o titi|\n", 0, 0, 0);
	rtn2 =ft_printf ("|t%04.2o%#2oet %#-8.3o titi|\n", 0, 0, 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|toto %###.0o%#.o et %#.1o !|\n", 0, 0, 0);
	rtn2 =ft_printf ("|toto %###.0o%#.o et %#.1o !|\n", 0, 0, 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
		

	printf("------------------- Type u ------------------- \n");
	printf("\n-------- %d -------\n",i++);
	rtn1 =    printf ("|%u|\n", 0);
	rtn2 = ft_printf ("|%u|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%10.u|\n", 0);
	rtn2 =ft_printf ("|%10.u|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%10u|\n", 0);
	rtn2 = ft_printf ("|%10u|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =    printf ("|%0.0u|\n", 0);
	rtn2 = ft_printf ("|%0.0u|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%12.9u|\n", 12);
	rtn2 =ft_printf ("|%12.9u|\n", 12);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%u|\n", -12322);
	rtn2 =ft_printf ("|%u|\n", -12322);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%llu|\n", INT64_MAX);
	rtn2 =ft_printf ("|%llu|\n", INT64_MAX);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|%hhu|\n", (unsigned char)12);
	rtn2 =ft_printf ("|%hhu|\n", (unsigned char)12);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =   printf ("|t%04.2u%2uet %-8.3u titi|\n", 0, 0, 0);
	rtn2 =ft_printf ("|t%04.2u%2uet %-8.3u titi|\n", 0, 0, 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	////////////// **** Type x,X ///////////
	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%#7.5X|\n", 0xab);
	rtn2 =ft_printf ("|%#7.5X|\n", 0xab);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);
	

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%#7.5x|\n", 0xab);
	rtn2 =ft_printf ("|%#7.5x|\n", 0xab);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
	rtn2 =ft_printf ("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%#0012x|\n", 0xe);
	rtn2 =ft_printf ("|%#0012x|\n", 0xe);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%0012hx|\n", (unsigned short)0xab);
	rtn2 =ft_printf ("|%0012hx|\n", (unsigned short)0xab);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|cc%#.4X et %#0012x %#04hX !!|\n", 0xaef, 0xe, (unsigned short)0);
	rtn2 =ft_printf ("|cc%#.4X et %#0012x %#04hX !!|\n", 0xaef, 0xe, (unsigned short)0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|osef ! %#llX|\n", (unsigned long long)-1248759650);
	rtn2 =ft_printf ("|osef ! %#llX|\n", (unsigned long long)-1248759650);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|{rsed}osef ! %#9llX{eoc}|\n", (unsigned long long)-1248759650);
	rtn2 =ft_printf ("|{rsed}osef ! %#9llX{eoc}|\n", (unsigned long long)-1248759650);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%-12hhx|\n",(unsigned char)-1478223695);
	rtn2 =ft_printf ("|%-12hhx|\n",(unsigned char)-1478223695);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%#04X|\n",0);
	rtn2 =ft_printf ("|%#04X|\n",0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%.4X|\n",0x037a);
	rtn2 =ft_printf ("|%.4X|\n",0x037a);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|toto %0##0.4X amd %#4.2x et c'est fini |\n", 0x037a, 0x9e);
	rtn2 =ft_printf ("|toto %0##0.4X amd %#4.2x et c'est fini |\n", 0x037a, 0x9e);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|toto %##.0x et %#.X and %#.1x|\n", 0, 0, 0);
	rtn2 =ft_printf ("|toto %##.0x et %#.X and %#.1x|\n", 0, 0, 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%0#10.0x %0#x|\n", 12345, 0);
	rtn2 =ft_printf ("|%0#10.0x %0#x|\n", 12345, 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%#0x|\n", 0);
	rtn2 =ft_printf ("|%#0x|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%#10.2x|\n", 0);
	rtn2 =ft_printf ("|%#10.2x|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);	
	rtn1 =printf ("|%.10x|\n", 0x1234abcd);
	rtn2 =ft_printf ("|%.10x|\n", 0x1234abcd);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);


	printf("\n-------- %d -------\n",i++);	
    rtn1 =printf ("|%0#10.0x|\n", 0);
 	rtn2 =ft_printf ("|%0#10.0x|\n", 0);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

printf("hani \n");
     rtn1 =printf ("|%10.6x|", 15);
	 rtn2 =printf("\n");
 	ft_printf ("|%10.6x|", 15);



/////// ********* Type p **********/

	int d;
	char *str = "asdasd";

	printf("\n-------- %d -------\n",i++);
	rtn1 =    printf ("|%p|\n", &d);
	rtn2 = ft_printf ("|%p|\n", &d);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =    printf ("|%p|\n", &d);
	rtn2 = ft_printf ("|%p|\n", &d);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =    printf ("|%-20p|\n", str);
	rtn2 = ft_printf ("|%-20p|\n", str);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("\n-------- %d -------\n",i++);
	rtn1 =    printf ("|%20p|\n", str);
	rtn2 = ft_printf ("|%20p|\n", str);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	printf("------------------- Type color and date ------------------- \n");

	printf("\n-------- 1 -------\n");
	//rtn1 =    printf ("|test color {red} %20s|\n","oussama amasdasdasd");
	rtn2 = ft_printf ("|test color {red} %20s|\n","oussama amasdasdasd");
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	ft_putstr("\n-------- 2 -------\n");
	//rtn1 =    printf ("|test date {date} and {green} %20s|\n","oussama amasdasdasd");
	rtn2 = ft_printf ("|test date {date} and {green} %20s|\n","oussama amasdasdasd");
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	ft_putstr("\n-------- 3 -------\n");
	//rtn1 =    printf ("|{red} {eoc %20d|\n", 1337);
	rtn2 = ft_printf ("|{red} {eoc %20d|\n", 1337);
		printf("\nrtn1 = %d and rtn2 = %d \n",rtn1,rtn2);

	ft_putstr("\n-------- 4 -------\n");
	rtn1 = ft_printf ("|{red}oussama{eoc}%5d|",1337);
	printf("\nrtn1 = %d\n",rtn1);

	ft_putstr("\n-------- 5 -------\n");
	rtn1 = ft_printf ("|{red oussama{eoc}%5d|",1337);
	printf("\nrtn1 = %d\n",rtn1);

	ft_putstr("\n-------- 6 -------\n");
	rtn1 = ft_printf ("|{green} oussama{eeoc}%5d|",1337);
	printf("\nrtn1 = %d\n",rtn1);

   	printf ("|osef ! %#9llX et %-12hhx|\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
	ft_printf ("|osef ! %#9llX et %-12hhx|\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
	
	printf("float : %.25lf\n", 1.00000000000000014);
	ft_printf("float : %.25lf\n", 1.00000000000000014);
	
	printf("\n-------- xxxxx -------\n");
	rtn1 = ft_printf("date now:%k");
	printf("\nrtn = %d \n",rtn1);

	printf("\n-------- bin -------\n");
	rtn1 = ft_printf("|%bs|","s");
	ft_printf("\nrtn = %d \n",rtn1);

	exit (0);
}