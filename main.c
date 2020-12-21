#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"

//int 		main(void)
//{
//	ft_printf("h",51);
//	printf("h",51);
//	return (0);
//}
char *ft_str_toupper(char *s)
{
	char *t = (char *)malloc(sizeof(char) + 1);
	int i= 0;

	while(*s)
		t[i++] = (char)ft_toupper(*s++);
	t[i] = '\0';
	return (t);
}

char *ft_str_toupper(char *s);

int 	main(void)
{
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	int d = -216;
//	printf("TESTO:|%-7d|\n", -14);
//	ft_printf("TESTM:|%-7d|\n", -14);
//
//	printf("%07d\n", -54);
//	ft_printf("%07d\n", -54);
////	ft_printf("%0d\n\n",d);
////
//	printf("%05d\n", 43);
//	ft_printf("%05d\n", 43);
//	printf("%-10.5d\n",d);
//	ft_printf("%-10.5d\n\n",d);
////
//	printf("%-5.0d\n",0);
//	ft_printf("%-5.0d\n",0);

	printf("%-8.5u number\n",0);
	ft_printf("%-8.5u number\n\n",0);
//
//	printf("%15.20d\n",d);
//	printf("%015.20d\n",d);
//	ft_printf("%15.20d\n",d);
//	ft_printf("%015.20d\n\n",d);
//
//	printf("%3d\n",d);
//	printf("%03d\n",d);
//	ft_printf("%3d\n",d);
//	ft_printf("%03d\n\n",d);
//
//	printf("%3.15d\n",d);
//	printf("%03.15d\n",d);
//	ft_printf("%3.15d\n",d);
//	ft_printf("%03.15d\n\n",d);
//
//	printf("%.d\n",d);
//	printf("%0.d\n",d);
//	ft_printf("%.d\n",d);
//	ft_printf("%0.d\n\n",d);
//
//	printf("%15.d\n",d);
//	printf("%015.d\n",d);
//	ft_printf("%15.d\n",d);
//	ft_printf("%015.d\n\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
//	printf("%d\n",d);
}

int		main1(void)
{
	//%[флаги][ширина][.точность][размер точности][тип]
	//%-052*.*x

	printf("\n\n--------f"
"t_printf bitches!-------------------------\n");

	char *str = "%015d";
//	char *str = "%1d";
	int d = 51777;
	int i = 51777;
	char c = '$';
	char  *s = "herrroo";
	unsigned int x = 127;
	int p = 51234;
	unsigned int u = -15;
	unsigned int X = -13;

//	printf("\nPROC:");

	int a = ft_printf(str, d);//,d,c,u,p,x,X);

	printf("[%d]",a);
	printf("\n");

//	printf("\nORIG:");

	int b =	printf(str, d);//,d,c,u,p,x,X);

	printf("[%d]",b);

//	printf("\n%s",ft_str_toupper("her"));
//	free(ft_str_toupper("her"));
//	printf("\nc:|%50.c|" , 'v');
	return (0);

}

int		main2()
{

	int		a;
	int		a1;
	int		b;


	a = printf("p->%%<-\n\n");
	b = ft_printf("f->%%<-\n\n");

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	a = printf("p->%*.p | %.3s<-\n\n", 0, NULL, "world");
	b = ft_printf("f->%*.p | %.3s<-\n\n", 0, NULL, "world");

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	a = printf("p->%*.p | %.3s<-\n\n", 0, &a1, "world");
	b = ft_printf("f->%*.p | %.3s<-\n\n", 0, &a1, "world");

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n", b);

	a = printf("p->%*.u | %.3u | %u<-\n\n", 10, 45678, -1234567u, 4294967295u);
	b = ft_printf("f->%*.u | %.3u | %u<-\n\n", 10, 45678, -1234567u, 4294967295u);

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n", b);

	// while (1);
	return 0;
}

int		main3()
{

	int		a;
	int		a1;
	int		b;


	a = printf("p->%%<-\n\n");
	b = ft_printf("f->%%<-\n\n");

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n", b);

	printf("____________________________________________\n\n");

//	a = printf("p->%*.p | %.3s | %p<-\n\n", 0, NULL, NULL, NULL);
//	b = ft_printf("f->%*.p | %.3s | %p<-\n\n", 0, NULL, NULL, NULL);

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	printf("____________________________________________\n\n");

	a = printf("p->%*.p | %.3s<-\n\n", 0, &a1, "world");
	b = ft_printf("f->%*.p | %.3s<-\n\n", 0, &a1, "world");

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	printf("____________________________________________\n\n");

	a = printf("p->%*.u | %.3u | %u<-\n\n", 10, 45678, -1234567u, 4294967295u);
	b = ft_printf("f->%*.u | %.3u | %u<-\n\n", 10, 45678, -1234567u, 4294967295u);

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	printf("____________________________________________\n\n");

	a = printf("p->%*.s | %.3s | %s<-\n\n", 10, "hello", "world", "lol");
	b = ft_printf("f->%*.s | %.3s | %s<-\n\n", 10, "hello", "world", "lol");

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	printf("____________________________________________\n\n");

	a = printf("p->%*.c | %.c | %c<-\n\n", 10, 'a', 'b', 'c');
	b = ft_printf("f->%*.c | %.c | %c<-\n\n", 10, 'a', 'b', 'c');

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	printf("____________________________________________\n\n");

	a = printf("p->%*.x | %.3x | %x<-\n\n", 10, -4, 87654, 45678);
	b = ft_printf("f->%*.x | %.3x | %x<-\n\n", 10, -4, 87654, 45678);

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	printf("____________________________________________\n\n");

	a = printf("p->%*.d | %.3d | %15.10d<-\n\n", 10, -4, 87654, -45678);
	b = ft_printf("f->%*.d | %.3d | %15.10d<-\n\n", 10, -4, 87654, -45678);

	printf("p: %d\n\n", a);
	ft_printf("f: %d\n\n", b);

	// while (1);
	return 0;
}

//мжйник для интов
int main4(void)
{
    int i = 10;

    printf("origin just a number: |%i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom just a number: |%i|\n\n", i);

    printf("just width\n\n");

    printf("origin w > len: |%10i|\n", i); // w - len пробелов слева число без изменений
    ft_printf("custom w > len: |%10i|\n", i);

    printf("origin w < len: |%1i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w < len: |%1i|\n", i);

    printf("origin w = len: |%2i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w = len: |%2i|\n", i);

    printf("origin w < 0    |%*i|\n", -4, i); // w - len пробелов справа, минус ширины перешел во флаг минус число без изменений
    ft_printf("custom w < 0    |%*i|\n", -4, i);

    printf("origin w = 0    |%*i|\n", 0, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = 0    |%*i|\n\n", 0, i);
//
//
    printf("just precision\n\n");

    printf("origin p > len: |%.6i|\n", i); // p - len нулей слева число без изменений
    ft_printf("custom p > len: |%.6i|\n", i);

    printf("origin p < len: |%.1i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom p < len: |%.1i|\n", i);

    printf("origin p = len: |%.2i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom p = len: |%.2i|\n", i);

    printf("origin p < 0:   |%.*i|\n", -5, i); // нет пробелов нигде число без изменений
    ft_printf("custom p < 0:   |%.*i|\n", -5, i);

    printf("origin p = 0:   |%.*i|\n", 0, i); // нет пробелов нигде число без изменений
    ft_printf("custom p = 0:   |%.*i|\n\n", 0, i);

    printf("origin just a dot: |%.i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom just a dot: |%.i|\n\n", i);
//
    printf("origin width and precision\n\n");

    printf("origin w > len && p > len: |%12.10i|\n", i); // w - p пробелов слева если w > p && p - len нулей слева число без изменений
    ft_printf("custom w > len && p > len: |%12.10i|\n", i);

    printf("origin w > len && p < len: |%10.1i|\n", i); // w - len пробелов слева число без изменений
    ft_printf("custom w > len && p < len: |%10.1i|\n", i);

    printf("origin w > len && p = len: |%10.2i|\n", i); // w - len пробелов слева число без изменений
    ft_printf("custom w > len && p = len: |%10.2i|\n", i);

    printf("origin w > len && p < 0:   |%10.*i|\n", -3, i); // w - len пробелов слева число без изменений
    ft_printf("custom w > len && p < 0:   |%10.*i|\n", -3, i);

    printf("origin w > len && p = 0:   |%10.*i|\n", 0, i); // w - len пробелов слева число без изменений
    ft_printf("custom w > len && p = 0:   |%10.*i|\n\n", 0, i);
//
//
//
    printf("origin w < len && p > len: |%1.10i|\n", i); // p - len нулей слева число без изменений
    ft_printf("custom w < len && p > len: |%1.10i|\n", i);

    printf("origin w < len && p < len: |%1.1i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w < len && p < len: |%1.1i|\n", i);

    printf("origin w < len && p = len: |%1.2i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w < len && p = len: |%1.2i|\n", i);

    printf("origin w < len && p < 0:   |%1.*i|\n", -3, i); // нет пробелов нигде число без изменений
    ft_printf("custom w < len && p < 0:   |%1.*i|\n", -3, i);

    printf("origin w < len && p = 0:   |%1.*i|\n", 0, i); // нет пробелов нигде число без изменений
    ft_printf("custom w < len && p = 0:   |%1.*i|\n\n", 0, i);


    printf("origin w = len && p > len: |%2.10i|\n", i); // p - len нулей слева число без изменений
    ft_printf("custom w = len && p > len: |%2.10i|\n", i);

    printf("origin w = len && p < len: |%2.1i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w = len && p < len: |%2.1i|\n", i);

    printf("origin w = len && p = len: |%2.2i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w = len && p = len: |%2.2i|\n", i);

    printf("origin w = len && p < 0:   |%2.*i|\n", -3, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = len && p < 0:   |%2.*i|\n", -3, i);

    printf("origin w = len && p = 0:   |%2.*i|\n", 0, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = len && p = 0:   |%2.*i|\n\n", 0, i);
//
//
//
    printf("origin w < 0 && p > len: |%*.12i|\n", -10, i); // p - len нулей слева число без изменений
    ft_printf("custom w < 0 && p > len: |%*.12i|\n", -10, i);

    printf("origin w < 0 && p < len: |%*.1i|\n", -3, i); // w - len пробелов справа, минус ширины перешел во флаг минус число без изменений
    ft_printf("custom w < 0 && p < len: |%*.1i|\n", -3, i);

    printf("origin w < 0 && p = len: |%*.2i|\n", -3, i); // w - len пробелов справа, минус ширины перешел во флаг минус число без изменений
    ft_printf("custom w < 0 && p = len: |%*.2i|\n", -3, i);

    printf("origin w < 0 && p < 0:   |%*.*i|\n", -3, -3, i); // w - len пробелов справа, минус ширины перешел во флаг минус число без изменений
    ft_printf("custom w < 0 && p < 0:   |%*.*i|\n", -3, -3, i);

    printf("origin w < 0 && p = 0:   |%*.*i|\n", -3, 0, i); // w - len пробелов справа, минус ширины перешел во флаг минус число без изменений
    ft_printf("custom w < 0 && p = 0:   |%*.*i|\n\n", -3, 0, i);



    printf("origin w = 0 && p > len: |%*.10i|\n", 0, i); // p - len нулей слева число без изменений
    ft_printf("custom w = 0 && p > len: |%*.10i|\n", 0, i);

    printf("origin w = 0 && p < len: |%*.1i|\n",  0, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = 0 && p < len: |%*.1i|\n",  0, i);

    printf("origin w = 0 && p = len: |%*.2i|\n",  0, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = 0 && p = len: |%*.2i|\n",  0, i);

    printf("origin w = 0 && p < 0:   |%*.*i|\n",  0, -3, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = 0 && p < 0:   |%*.*i|\n",  0, -3, i);

    printf("origin w = 0 && p = 0:   |%*.*i|\n",  0, 0, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = 0 && p = 0:   |%*.*i|\n\n",  0, 0, i);
//
    printf("add minus\n\n");

    printf("origin just minus: |%-i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom just minus: |%-i|\n\n", i);

    printf("- width\n\n");

    printf("origin w > len: |%-10i|\n", i); // w- len пробелов справа число без изменений
    ft_printf("custom w > len: |%-10i|\n", i);

    printf("origin w < len: |%-1i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w < len: |%-1i|\n", i);

    printf("origin w = len: |%-2i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom w = len: |%-2i|\n", i);

    printf("origin w < 0    |%-*i|\n", -4, i); //
    ft_printf("custom w < 0    |%-*i|\n", -4, i);

    printf("origin w = 0    |%-*i|\n", 0, i); // нет пробелов нигде число без изменений
    ft_printf("custom w = 0    |%-*i|\n\n", 0, i);
//
    printf("- precision\n\n");

    printf("origin p > len: |%-.6i|\n", i); // p - len нулей слева число без изменений
    ft_printf("custom p > len: |%-.6i|\n", i);

    printf("origin p < len: |%-.1i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom p < len: |%-.1i|\n", i);

    printf("origin p = len: |%-.2i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom p = len: |%-.2i|\n", i);

    printf("origin p < 0:   |%-.*i|\n", -5, i); // нет пробелов нигде число без изменений
    ft_printf("custom p < 0:   |%-.*i|\n", -5, i);

    printf("origin p = 0:   |%-.*i|\n", 0, i); // нет пробелов нигде число без изменений
    ft_printf("custom p = 0:   |%-.*i|\n", 0, i);

    printf("origin just a dot: |%-.i|\n", i); // нет пробелов нигде число без изменений
    ft_printf("custom just a dot: |%-.i|\n\n", i);


    printf("- width and precision\n\n");


    printf("origin w > len && p > len: |%-12.10i|\n", i); // p - len нулей слева, и w - p пробелов справа число без изменений
    ft_printf("custom w > len && p > len: |%-12.10i|\n", i);

    printf("origin w > len && p < len: |%-10.1i|\n", i); // w - len пробелов справа число без изменений
    ft_printf("custom w > len && p < len: |%-10.1i|\n", i);

    printf("origin w > len && p = len: |%-10.2i|\n", i); // w - len пробелов справа число без изменений
    ft_printf("custom w > len && p = len: |%-10.2i|\n", i);

    printf("origin w > len && p < 0:   |%-10.*i|\n", -3, i); // w - len пробелов справа число без изменений
    ft_printf("custom w > len && p < 0:   |%-10.*i|\n", -3, i);

    printf("origin w > len && p = 0:   |%-10.*i|\n", 0, i); // w - len пробелов справа число без изменений
    ft_printf("custom w > len && p = 0:   |%-10.*i|\n\n", 0, i);


    printf("origin w < len && p > len: |%-1.10i|\n", i); //  p - len нулей слева число без изменений
    ft_printf("custom w < len && p > len: |%-1.10i|\n", i);

    printf("origin w < len && p < len: |%-1.1i|\n", i); // число без изменений
    ft_printf("custom w < len && p < len: |%-1.1i|\n", i);

    printf("origin w < len && p = len: |%-1.2i|\n", i); // число без изменений
    ft_printf("custom w < len && p = len: |%-1.2i|\n", i);

    printf("origin w < len && p < 0:   |%-1.*i|\n", -3, i); // число без изменений
    ft_printf("custom w < len && p < 0:   |%-1.*i|\n", -3, i);

    printf("origin w < len && p = 0:   |%-1.*i|\n", 0, i); // число без изменений
    ft_printf("custom w < len && p = 0:   |%-1.*i|\n\n", 0, i);



    printf("origin w = len && p > len: |%-2.10i|\n", i); //  p - len нулей слева число без изменений
    ft_printf("custom w = len && p > len: |%-2.10i|\n", i);

    printf("origin w = len && p < len: |%-2.1i|\n", i); // число без изменений
    ft_printf("custom w = len && p < len: |%-2.1i|\n", i);

    printf("origin w = len && p = len: |%-2.2i|\n", i); // число без изменений
    ft_printf("custom w = len && p = len: |%-2.2i|\n", i);

    printf("origin w = len && p < 0:   |%-2.*i|\n", -3, i); // число без изменений
    ft_printf("custom w = len && p < 0:   |%-2.*i|\n", -3, i);

    printf("origin w = len && p = 0:   |%-2.*i|\n", 0, i); // число без изменений
    ft_printf("custom w = len && p = 0:   |%-2.*i|\n\n", 0, i);



    printf("origin w < 0 && p > len: |%-*.10i|\n", -12, i); // минус ширины перешел во флаг минус p - len нулей слева, и w - p пробелов справа число без изменений
    ft_printf("custom w < 0 && p > len: |%-*.10i|\n", -12, i);

    printf("origin w < 0 && p < len: |%-*.1i|\n", -3, i); //  минус ширины перешел во флаг минус w - len пробелов справа
    ft_printf("custom w < 0 && p < len: |%-*.1i|\n", -3, i);

    printf("origin w < 0 && p = len: |%-*.2i|\n", -3, i); // минус ширины перешел во флаг минус w - len пробелов справа
    ft_printf("custom w < 0 && p = len: |%-*.2i|\n", -3, i);

    printf("origin w < 0 && p < 0:   |%-*.*i|\n", -3, -3, i); // минус ширины перешел во флаг минус w - len пробелов справа
    ft_printf("custom w < 0 && p < 0:   |%-*.*i|\n", -3, -3, i);

    printf("origin w < 0 && p = 0:   |%*.*i|\n", -3, 0, i); // минус ширины перешел во флаг минус w - len пробелов справа
    ft_printf("custom w < 0 && p = 0:   |%*.*i|\n\n", -3, 0, i);



    printf("origin w = 0 && p > len: |%-*.10i|\n", 0, i); // число без изменений
    ft_printf("custom w = 0 && p > len: |%-*.10i|\n", 0, i);

    printf("origin w = 0 && p < len: |%-*.1i|\n",  0, i); // число без изменений
    ft_printf("custom w = 0 && p < len: |%-*.1i|\n",  0, i);

    printf("origin w = 0 && p = len: |%-*.2i|\n",  0, i); // число без изменений
    ft_printf("custom w = 0 && p = len: |%-*.2i|\n",  0, i);

    printf("origin w = 0 && p < 0:   |%-*.*i|\n",  0, -3, i); // число без изменений
    ft_printf("custom w = 0 && p < 0:   |%-*.*i|\n",  0, -3, i);

    printf("origin w = 0 && p = 0:   |%-*.*i|\n",  0, 0, i); // число без изменений
    ft_printf("custom w = 0 && p = 0:   |%-*.*i|\n\n",  0, 0, i);


    printf("origin just zero: |%0i|\n", i); // число без изменений
    ft_printf("custom just zero: |%0i|\n\n", i);


    printf("0 width\n\n");

    printf("origin w > len: |%010i|\n", i); // w - len нулей слева
    ft_printf("custom w > len: |%010i|\n", i);

    printf("origin w < len: |%01i|\n", i); // число без изменений
    ft_printf("custom w < len: |%01i|\n", i);

    printf("origin w = len: |%02i|\n", i); // число без изменений
    ft_printf("custom w = len: |%02i|\n", i);

    printf("origin w < 0   |%0*i|\n", -4, i); // |-w| - len - пробелов справа (минус ширины перешел во флаг минус)
    ft_printf("custom w < 0   |%0*i|\n", -4, i);

    printf("origin w = 0   |%0*i|\n", 0, i); // число без изменений
    ft_printf("custom w = 0   |%0*i|\n\n", 0, i);


    printf("0 precision\n\n");

    printf("origin p > len: |%0.6i|\n", i); // p - len нулей слева
    ft_printf("custom p > len: |%0.6i|\n", i);

    printf("origin p < len: |%0.1i|\n", i); // число без изменений
    ft_printf("custom p < len: |%0.1i|\n", i);

    printf("origin p = len: |%0.2i|\n", i); // число без изменений
    ft_printf("custom p = len: |%0.2i|\n", i);

    printf("origin p < 0:   |%0.*i|\n", -5, i); // число без изменений
    ft_printf("custom p < 0:   |%0.*i|\n", -5, i);

    printf("origin p = 0:   |%0.*i|\n", 0, i); // число без изменений
    ft_printf("custom p = 0:   |%0.*i|\n", 0, i);

    printf("origin just a dot: |%0.i|\n", i); // число без изменений
    ft_printf("custom just a dot: |%0.i|\n\n", i);


    printf("0 width and precision\n\n");

    printf("origin w > len && p > len: |%0*.10i|\n", 12, i); // w - p пробелов слева потом p - len нулей и потом число без изменений
    ft_printf("custom w > len && p > len: |%0*.10i|\n", 12, i);

    printf("origin w > len && p < len: |%010.1i|\n", i); // w - len пробелов слева
    ft_printf("custom w > len && p < len: |%010.1i|\n", i);

    printf("origin w > len && p = len: |%010.2i|\n", i); // w - len пробелов слева
    ft_printf("custom w > len && p = len: |%010.2i|\n", i);

    printf("origin w > len && p < 0:   |%010.*i|\n", -3, i); // p - len нулей слева
    ft_printf("custom w > len && p < 0:   |%010.*i|\n", -3, i);

    printf("origin w > len && p = 0:   |%010.*i|\n", 0, i);// w - len пробелов слева
    ft_printf("custom w > len && p = 0:   |%010.*i|\n\n", 0, i);


    printf("origin w < len && p > len: |%01.10i|\n", i); // p -len нулей слева
    ft_printf("custom w < len && p > len: |%01.10i|\n", i);

    printf("origin w < len && p < len: |%01.1i|\n", i); // число без изменений
    ft_printf("custom w < len && p < len: |%01.1i|\n", i);

    printf("origin w < len && p = len: |%01.2i|\n", i); // число без изменений
    ft_printf("custom w < len && p = len: |%01.2i|\n", i);

    printf("origin w < len && p < 0:   |%01.*i|\n", -3, i); // число без изменений
    ft_printf("custom w < len && p < 0:   |%01.*i|\n", -3, i);

    printf("origin w < len && p = 0:   |%01.*i|\n", 0, i); // число без изменений
    ft_printf("custom w < len && p = 0:   |%01.*i|\n\n", 0, i);


    printf("origin w = len && p > len: |%02.10i|\n", i); // p -len нулей слева
    ft_printf("custom w = len && p > len: |%02.10i|\n", i);

    printf("origin w = len && p < len: |%02.1i|\n", i); // число без изменений
    ft_printf("custom w = len && p < len: |%02.1i|\n", i);

    printf("origin w = len && p = len: |%02.2i|\n", i); // число без изменений
    ft_printf("custom w = len && p = len: |%02.2i|\n", i);

    printf("origin w = len && p < 0:   |%02.*i|\n", -3, i); // число без изменений
    ft_printf("custom w = len && p < 0:   |%02.*i|\n", -3, i);

    printf("origin w = len && p = 0:   |%02.*i|\n", 0, i); // число без изменений
    ft_printf("custom w = len && p = 0:   |%02.*i|\n\n", 0, i);


    printf("origin w < 0 && p > len: |%0*.10i|\n", -12, i); // w - p пробелов слева потом p - len нулей и потом число без изменений
    ft_printf("custom w < 0 && p > len: |%0*.10i|\n", -12, i);

    printf("origin w < 0 && p < len: |%0*.1i|\n", -3, i); // w - len пробелов справа
    ft_printf("custom w < 0 && p < len: |%0*.1i|\n", -3, i);

    printf("origin w < 0 && p = len: |%0*.2i|\n", -3, i); // w - len пробелов справа
    ft_printf("custom w < 0 && p = len: |%0*.2i|\n", -3, i);

    printf("origin w < 0 && p < 0:   |%0*.*i|\n", -3, -3, i); // w - len пробелов справа
    ft_printf("custom w < 0 && p < 0:   |%0*.*i|\n", -3, -3, i);

    printf("origin w < 0 && p = 0:   |%0*.*i|\n", -3, 0, i); // w - len пробелов справа
    ft_printf("custom w < 0 && p = 0:   |%0*.*i|\n\n", -3, 0, i);


    printf("origin w = 0 && p > len: |%0*.10i|\n", 0, i); // p - len нулей справа
    ft_printf("custom w = 0 && p > len: |%0*.10i|\n", 0, i);

    printf("origin w = 0 && p < len: |%0*.1i|\n",  0, i); // число без изменений
    ft_printf("custom w = 0 && p < len: |%0*.1i|\n",  0, i);

    printf("origin w = 0 && p = len: |%0*.2i|\n",  0, i); // число без изменений
    ft_printf("custom w = 0 && p = len: |%0*.2i|\n",  0, i);

    printf("origin w = 0 && p < 0:   |%0*.*i|\n",  0, -3, i); // число без изменений
    ft_printf("custom w = 0 && p < 0:   |%0*.*i|\n",  0, -3, i);

    printf("origin w = 0 && p = 0:   |%0*.*i|\n",  0, 0, i); // число без изменений
    ft_printf("custom w = 0 && p = 0:   |%0*.*i|\n\n",  0, 0, i);
}

//мэйник для проверки стрok
int main5(void)
{
	char *str = "abcde";

	//ft_printf("%s please %s\n\n", "jesus", "help");

	printf("origin just a string: |%s|\n", str); // ниче
	ft_printf("custom just a string: |%s|\n\n", str); // ниче
//

	printf("origin w = len: |%5s|\n", str); // ниче
	ft_printf("custom w = len: |%5s|\n", str); // ниче
////
	printf("origin w < 0    |%*s|\n", -4, str); // ниче
	ft_printf("custom w < 0    |%*s|\n", -4, str); // ниче

	printf("origin w = 0    |%*s|\n", 0, str); // ниче
	ft_printf("custom w = 0    |%*s|\n\n", 0, str); // ниче
//////
//////
	printf("just precision\n\n");

	printf("origin p > len: |%.6s|\n", str); // ниче
	ft_printf("custom p > len: |%.6s|\n", str); // ниче

	printf("origin p < len: |%.3s|\n", str); // только "точность" символов
	ft_printf("custom p < len: |%.3s|\n", str); // только "точность" символов

	printf("origin p = len: |%.5s|\n", str); // ниче
	ft_printf("custom p = len: |%.5s|\n", str); // ниче

	printf("origin p < 0:   |%.*s|\n", -5, str); // ниче
	ft_printf("custom p < 0:   |%.*s|\n", -5, str); // ниче

	printf("origin p = 0:   |%.*s|\n", 0, str); // не выводит НИЧЕГО
	ft_printf("custom p = 0:   |%.*s|\n\n", 0, str); // не выводит НИЧЕГО

	printf("origin just a dot: |%.s|\n", str); // не выводит НИЧЕГО
	ft_printf("custom just a dot: |%.s|\n\n", str); // не выводит НИЧЕГО
//
	printf("origin width and precision\n\n");

	printf("origin w > len && p > len: |%10.10s|\n", str); // пробелы слева длиной "ширина - длина строки"
	ft_printf("custom w > len && p > len: |%10.10s|\n", str); // пробелы слева длиной "ширина - длина строки"

	printf("origin w > len && p < len: |%10.3s|\n", str); // только "точность" символов и проблемы слева длиной "ширина - длина строки"
	ft_printf("custom w > len && p < len: |%10.3s|\n", str); // только "точность" символов и проблемы слева длиной "ширина - длина строки"

	printf("origin w > len && p = len: |%10.5s|\n", str); // пробелы слева длиной "ширина - длина строки"
	ft_printf("custom w > len && p = len: |%10.5s|\n", str); // пробелы слева длиной "ширина - длина строки"

	printf("origin w > len && p < 0:   |%10.*s|\n", -3, str); // пробелы слева длиной "ширина - длина строки"
	ft_printf("custom w > len && p < 0:   |%10.*s|\n", -3, str); // пробелы слева длиной "ширина - длина строки"

	printf("origin w > len && p = 0:   |%10.*s|\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина
	ft_printf("custom w > len && p = 0:   |%10.*s|\n\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина



	printf("origin w < len && p > len: |%3.10s|\n", str); // ниче
	ft_printf("custom w < len && p > len: |%3.10s|\n", str); // ниче

	printf("origin w < len && p < len: |%3.3s|\n", str); //  только "точность" символов
	ft_printf("custom w < len && p < len: |%3.3s|\n", str); //  только "точность" символов

	printf("origin w < len && p = len: |%3.5s|\n", str); // ниче
	ft_printf("custom w < len && p = len: |%3.5s|\n", str); // ниче

	printf("origin w < len && p < 0:   |%3.*s|\n", -3, str); // ниче
	ft_printf("custom w < len && p < 0:   |%3.*s|\n", -3, str); // ниче

	printf("origin w < len && p = 0:   |%3.*s|\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = точность
	ft_printf("custom w < len && p = 0:   |%3.*s|\n\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = точность
//////
//////
	printf("origin w = len && p > len: |%5.10s|\n", str); // ниче
	ft_printf("custom w = len && p > len: |%5.10s|\n", str); // ниче

	printf("origin w = len && p < len: |%5.3s|\n", str); // только "точность" символов и пробелы слева длиной "ширина - длина строки"
	ft_printf("custom w = len && p < len: |%5.3s|\n", str); // только "точность" символов и пробелы слева длиной "ширина - длина строки"

	printf("origin w = len && p = len: |%5.5s|\n", str); // ниче
	ft_printf("custom w = len && p = len: |%5.5s|\n", str); // ниче

	printf("origin w = len && p < 0:   |%5.*s|\n", -3, str); // ниче
	ft_printf("custom w = len && p < 0:   |%5.*s|\n", -3, str); // ниче
////
	printf("origin w = len && p = 0:   |%5.*s|\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина
	ft_printf("custom w = len && p = 0:   |%5.*s|\n\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина
////
////
////
	printf("origin w < 0 && p > len: |%*.10s|\n", -3, str); // ниче
	ft_printf("custom w < 0 && p > len: |%*.10s|\n", -3, str); // ниче

	printf("origin w < 0 && p < len: |%*.3s|\n", -3, str); // только "точность" символов
	ft_printf("custom w < 0 && p < len: |%*.3s|\n", -3, str); // только "точность" символов

	printf("origin w < 0 && p = len: |%*.5s|\n", -3, str); // ниче
	ft_printf("custom w < 0 && p = len: |%*.5s|\n", -3, str); // ниче
//
	printf("origin w < 0 && p < 0:   |%*.*s|\n", -3, -3, str); // ниче
	///////////////////////////-----
	ft_printf("custom w < 0 && p < 0:   |%*.*s|\n", -3, -3, str); // ниче

	printf("origin w < 0 && p = 0:   |%*.*s|\n", -3, 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = точность
	ft_printf("custom w < 0 && p = 0:   |%*.*s|\n\n", -3, 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = точность
////
//
//
	printf("origin w = 0 && p > len: |%*.10s|\n", 0, str); // ниче
	ft_printf("custom w = 0 && p > len: |%*.10s|\n", 0, str); // ниче

	printf("origin w = 0 && p < len: |%*.3s|\n",  0, str); // только "точность" символов
	ft_printf("custom w = 0 && p < len: |%*.3s|\n",  0, str); // только "точность" символов

	printf("origin w = 0 && p = len: |%*.5s|\n",  0, str); // ниче
	ft_printf("custom w = 0 && p = len: |%*.5s|\n",  0, str); // ниче

	printf("origin w = 0 && p < 0:   |%*.*s|\n",  0, -3, str); // ниче
	ft_printf("custom w = 0 && p < 0:   |%*.*s|\n",  0, -3, str); // ниче

	printf("origin w = 0 && p = 0:   |%*.*s|\n",  0, 0, str); // не выводит НИЧЕГО
	ft_printf("custom w = 0 && p = 0:   |%*.*s|\n\n",  0, 0, str); // не выводит НИЧЕГО
////
	printf("add minus\n\n");

	printf("just minus: |%-s|\n", str); // ниче
	ft_printf("just minus: |%-s|\n\n", str); // ниче

	printf("- width\n\n");

	printf("w > len: |%-10s|\n", str); // справа пробелы
	ft_printf("w > len: |%-10s|\n", str); // справа пробелы

	printf("w < len: |%-3s|\n", str); // ниче
	ft_printf("w < len: |%-3s|\n", str); // ниче

	printf("w = len: |%-5s|\n", str); // ниче
	ft_printf("w = len: |%-5s|\n", str); // ниче

	printf("w < 0   |%-*s|\n", -4, str); // ниче
	ft_printf("w < 0   |%-*s|\n", -4, str); // ниче

	printf("w = 0   |%-*s|\n", 0, str); // ниче
	ft_printf("w = 0   |%-*s|\n\n", 0, str); // ниче
////
	printf("- precision\n\n");

	printf("p > len: |%-.6s|\n", str); // ниче
	ft_printf("p > len: |%-.6s|\n", str); // ниче

	printf("p < len: |%-.3s|\n", str); // только "точность" символов
	ft_printf("p < len: |%-.3s|\n", str); // только "точность" символов

	printf("p = len: |%-.5s|\n", str); // ниче
	ft_printf("p = len: |%-.5s|\n", str); // ниче

	printf("p < 0:   |%-.*s|\n", -5, str); // ниче
	ft_printf("p < 0:   |%-.*s|\n", -5, str); // ниче

	printf("p = 0:   |%-.*s|\n", 0, str); // не выводит НИЧЕГО
	ft_printf("p = 0:   |%-.*s|\n", 0, str); // не выводит НИЧЕГО

	printf("just a dot: |%-.s|\n", str); // не выводит НИЧЕГО
	ft_printf("just a dot: |%-.s|\n\n", str); // не выводит НИЧЕГО

	printf("- width and precision\n\n");

	printf("w > len && p > len: |%-10.10s|\n", str); // пробелы справа длиной "ширина - длина строки"
	ft_printf("w > len && p > len: |%-10.10s|\n", str); // пробелы справа длиной "ширина - длина строки"

	printf("w > len && p < len: |%-10.3s|\n", str); // только "точность" символов и пробелы справа длиной "ширина - длина строки"
	ft_printf("w > len && p < len: |%-10.3s|\n", str); // только "точность" символов и пробелы справа длиной "ширина - длина строки"

	printf("w > len && p = len: |%-10.5s|\n", str); // пробелы справа длиной "ширина - длина строки"
	ft_printf("w > len && p = len: |%-10.5s|\n", str); // пробелы справа длиной "ширина - длина строки"

	printf("w > len && p < 0:   |%-10.*s|\n", -3, str); // пробелы справа длиной "ширина - длина строки"
	ft_printf("w > len && p < 0:   |%-10.*s|\n", -3, str); // пробелы справа длиной "ширина - длина строки"

	printf("w > len && p = 0:   |%-10.*s|\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина
	ft_printf("w > len && p = 0:   |%-10.*s|\n\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина
////
////
	printf("w < len && p > len: |%-3.10s|\n", str); // ниче
	ft_printf("w < len && p > len: |%-3.10s|\n", str); // ниче

	printf("w < len && p < len: |%-3.3s|\n", str); // только "точность" символов и пробелы справа длиной "ширина - длина строки"
	ft_printf("w < len && p < len: |%-3.3s|\n", str); // только "точность" символов и пробелы справа длиной "ширина - длина строки"

	printf("w < len && p = len: |%-3.5s|\n", str); // ниче
	ft_printf("w < len && p = len: |%-3.5s|\n", str); // ниче

	printf("w < len && p < 0:   |%-3.*s|\n", -3, str); // ниче
	ft_printf("w < len && p < 0:   |%-3.*s|\n", -3, str); // ниче

	printf("w < len && p = 0:   |%-3.*s|\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина
	ft_printf("w < len && p = 0:   |%-3.*s|\n\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина

	printf("w = len && p > len: |%-5.10s|\n", str); // ниче
	ft_printf("w = len && p > len: |%-5.10s|\n", str); // ниче

	printf("w = len && p < len: |%-5.3s|\n", str); // только "точность" символов и пробелы справа длиной "ширина - длина строки"
	ft_printf("w = len && p < len: |%-5.3s|\n", str); // только "точность" символов и пробелы справа длиной "ширина - длина строки"
//
	printf("w = len && p = len: |%-5.5s|\n", str); // ниче
	ft_printf("w = len && p = len: |%-5.5s|\n", str); // ниче

	printf("w = len && p < 0:   |%-5.*s|\n", -3, str); // ниче
	ft_printf("w = len && p < 0:   |%-5.*s|\n", -3, str); // ниче

	printf("w = len && p = 0:   |%-5.*s|\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина
	ft_printf("w = len && p = 0:   |%-5.*s|\n\n", 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = ширина

	printf("w < 0 && p > len: |%-*.10s|\n", -3, str); // ниче
	ft_printf("w < 0 && p > len: |%-*.10s|\n", -3, str); // ниче

	printf("w < 0 && p < len: |%-*.3s|\n", -3, str); // только "точность" символов
	ft_printf("w < 0 && p < len: |%-*.3s|\n", -3, str); // только "точность" символов

	printf("w < 0 && p = len: |%-*.5s|\n", -3, str); // ниче
	ft_printf("w < 0 && p = len: |%-*.5s|\n", -3, str); // ниче

	printf("w < 0 && p < 0:   |%-*.*s|\n", -3, -3, str); // ниче
	ft_printf("w < 0 && p < 0:   |%-*.*s|\n", -3, -3, str); // ниче
//
	printf("w < 0 && p = 0:   |%*.*s|\n", -3, 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = точность
	ft_printf("w < 0 && p = 0:   |%*.*s|\n\n", -3, 0, str); // ЕСЛИ ТОЧНОСТЬ 0 то НИЧЕГО НЕ ПЕЧАТАЙ и тут пробелов = точность

	printf("w = 0 && p > len: |%-*.10s|\n", 0, str); // ниче
	ft_printf("w = 0 && p > len: |%-*.10s|\n", 0, str); // ниче

	printf("w = 0 && p < len: |%-*.3s|\n",  0, str); // только "точность" символов
	ft_printf("w = 0 && p < len: |%-*.3s|\n",  0, str); // только "точность" символов

	printf("w = 0 && p = len: |%-*.5s|\n",  0, str); // ниче
	ft_printf("w = 0 && p = len: |%-*.5s|\n",  0, str); // ниче

	printf("w = 0 && p < 0:   |%-*.*s|\n",  0, -3, str); // ниче
	ft_printf("w = 0 && p < 0:   |%-*.*s|\n",  0, -3, str); // ниче

	printf("w = 0 && p = 0:   |%-*.*s|\n",  0, 0, str); // не выводит НИЧЕГО
	ft_printf("w = 0 && p = 0:   |%-*.*s|\n\n",  0, 0, str); // не выводит НИЧЕГО

//
//
	printf("just zero: |%0s|\n", str);
	ft_printf("just zero: |%0s|\n\n", str);


	printf("0 width\n\n");

	printf("w > len: |%010s|\n", str);
	ft_printf("w > len: |%010s|\n", str);

	printf("w < len: |%03s|\n", str);
	ft_printf("w < len: |%03s|\n", str);

	printf("w = len: |%05s|\n", str);
	ft_printf("w = len: |%05s|\n", str);

	printf("w < 0   |%0*s|\n", -4, str);
	ft_printf("w < 0   |%0*s|\n", -4, str);


	printf("w = 0   |%0*s|\n", 0, str);
	ft_printf("w = 0   |%0*s|\n\n", 0, str);


	printf("0 precision\n\n");

	printf("p > len: |%0.6s|\n", str);
	ft_printf("p > len: |%0.6s|\n", str);

	printf("p < len: |%0.3s|\n", str);
	ft_printf("p < len: |%0.3s|\n", str);

	printf("p = len: |%0.5s|\n", str);
	ft_printf("p = len: |%0.5s|\n", str);

	printf("p < 0:   |%0.*s|\n", -5, str);
	ft_printf("p < 0:   |%0.*s|\n", -5, str);

	printf("p = 0:   |%0.*s|\n", 0, str);
	ft_printf("p = 0:   |%0.*s|\n", 0, str);

	printf("just a dot: |%0.s|\n", str);
	ft_printf("just a dot: |%0.s|\n\n", str);

//
	printf("0 width and precision\n\n");

	printf("w > len && p > len: |%010.10s|\n", str);
	ft_printf("w > len && p > len: |%010.10s|\n", str);

	printf("w > len && p < len: |%010.3s|\n", str);
	ft_printf("w > len && p < len: |%010.3s|\n", str);

	printf("w > len && p = len: |%010.5s|\n", str);
	ft_printf("w > len && p = len: |%010.5s|\n", str);

	printf("w > len && p < 0:   |%010.*s|\n", -3, str);
	ft_printf("w > len && p < 0:   |%010.*s|\n", -3, str);

	printf("w > len && p = 0:   |%010.*s|\n", 0, str);
	ft_printf("w > len && p = 0:   |%010.*s|\n\n", 0, str);


	printf("w < len && p > len: |%03.10s|\n", str);
	ft_printf("w < len && p > len: |%03.10s|\n", str);

	printf("w < len && p < len: |%03.3s|\n", str);
	ft_printf("w < len && p < len: |%03.3s|\n", str);

	printf("w < len && p = len: |%03.5s|\n", str);
	ft_printf("w < len && p = len: |%03.5s|\n", str);

	printf("w < len && p < 0:   |%03.*s|\n", -3, str);
	ft_printf("w < len && p < 0:   |%03.*s|\n", -3, str);

	printf("w < len && p = 0:   |%03.*s|\n", 0, str);
	ft_printf("w < len && p = 0:   |%03.*s|\n\n", 0, str);
//
//
	printf("w = len && p > len: |%05.10s|\n", str);
	ft_printf("w = len && p > len: |%05.10s|\n", str);

	printf("w = len && p < len: |%05.3s|\n", str);
	ft_printf("w = len && p < len: |%05.3s|\n", str);

	printf("w = len && p = len: |%05.5s|\n", str);
	ft_printf("w = len && p = len: |%05.5s|\n", str);

	printf("w = len && p < 0:   |%05.*s|\n", -3, str);
	ft_printf("w = len && p < 0:   |%05.*s|\n", -3, str);

	printf("w = len && p = 0:   |%05.*s|\n", 0, str);
	ft_printf("w = len && p = 0:   |%05.*s|\n\n", 0, str);

//
	printf("w < 0 && p > len: |%0*.10s|\n", -3, str);
	ft_printf("w < 0 && p > len: |%0*.10s|\n", -3, str);

	printf("w < 0 && p < len: |%0*.3s|\n", -3, str);
	ft_printf("w < 0 && p < len: |%0*.3s|\n", -3, str);

	printf("w < 0 && p = len: |%0*.5s|\n", -3, str);
	ft_printf("w < 0 && p = len: |%0*.5s|\n", -3, str);

	printf("w < 0 && p < 0:   |%0*.*s|\n", -3, -3, str);
	ft_printf("w < 0 && p < 0:   |%0*.*s|\n", -3, -3, str);

	printf("w < 0 && p = 0:   |%0*.*s|\n", -3, 0, str);
	ft_printf("w < 0 && p = 0:   |%0*.*s|\n\n", -3, 0, str);


	printf("w = 0 && p > len: |%0*.10s|\n", 0, str);
	ft_printf("w = 0 && p > len: |%0*.10s|\n", 0, str);

	printf("w = 0 && p < len: |%0*.3s|\n",  0, str);
	ft_printf("w = 0 && p < len: |%0*.3s|\n",  0, str);

	printf("w = 0 && p = len: |%0*.5s|\n",  0, str);
	ft_printf("w = 0 && p = len: |%0*.5s|\n",  0, str);

	printf("w = 0 && p < 0:   |%0*.*s|\n",  0, -3, str);
	ft_printf("w = 0 && p < 0:   |%0*.*s|\n",  0, -3, str);

	printf("w = 0 && p = 0:   |%0*.*s|\n",  0, 0, str);
	ft_printf("w = 0 && p = 0:   |%0*.*s|\n\n",  0, 0, str);

	return 0;
}
