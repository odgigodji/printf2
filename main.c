#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"

//int 		main(void)
//{
//	ft_printf("h",51);
//	printf("h",51);
//	return (0);
//}

char *ft_str_toupper(char *s);

int 	main0(void)
{
	int d = 123;
//	printf("TEST:|%3.5d|\n", d);
//	ft_printf("TEST:|%3.5d|\n", d);

	printf("%0d\n",d);
	ft_printf("%d\n",d);
	ft_printf("%0d\n\n",d);

	printf("%15d\n",d);
	printf("%015d\n",d);
	ft_printf("%15d\n",d);
	ft_printf("%015d\n\n",d);

	printf("%15.5d\n",d);
	printf("%015.5d\n",d);
	ft_printf("%15.5d\n",d);
	ft_printf("%015.5d\n\n",d);

	printf("%15.20d\n",d);
	printf("%015.20d\n",d);
	ft_printf("%15.20d\n",d);
	ft_printf("%015.20d\n\n",d);

	printf("%3d\n",d);
	printf("%03d\n",d);
	ft_printf("%3d\n",d);
	ft_printf("%03d\n\n",d);

	printf("%3.15d\n",d);
	printf("%03.15d\n",d);
	ft_printf("%3.15d\n",d);
	ft_printf("%03.15d\n\n",d);

	printf("%.d\n",d);
	printf("%0.d\n",d);
	ft_printf("%.d\n",d);
	ft_printf("%0.d\n\n",d);

	printf("%15.d\n",d);
	printf("%015.d\n",d);
	ft_printf("%15.d\n",d);
	ft_printf("%015.d\n\n",d);
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

int				main1(void)
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

char *ft_str_toupper(char *s)
{
	char *t = (char *)malloc(sizeof(char) + 1);
	int i= 0;

	while(*s)
		t[i++] = (char)ft_toupper(*s++);
	t[i] = '\0';
	return (t);
}

#include <stdio.h>

int		main1()
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
