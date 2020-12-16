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

int				main(void)
{
	//%[флаги][ширина][.точность][размер точности][тип]
	//%-052*.*x
//	ft_printf("MY:%-0", 5, "Hello", "world");
//	ft_parser("0000----");
	//printf("ORIG:%-50s", "hellomfqz");
//	char *str = "-*d";
//	t_spec *spec;
//	spec = (t_spec *)malloc(sizeof(t_spec*));

//	if (!(spec = ft_parser("025d", 51)))
//		return (0);

//	ft_processor(spec);

//	printf("flag = '%c'\n",spec -> flag);
//	printf("%s",spec -> content);

//	free(spec);



	printf("\n\n--------f"
"t_printf bitches!-------------------------\n");

	char *str = "123%012d";
//	char *str = "%1d";
	int d = -51777;
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


//char    ft_putnbr_base(unsigned int nb, int base)
//{
//	if (nb >= 10)
//	{
//		if (base < 10)
//			ft_putnbr_base(nb / 10, base);
//		else
//		{
//			return (nb + 55);
//		}
//	}
//	return (nb + 48);
//}
//void  ft_res(unsigned int nb, int base, char **str)
//{
//	static int   i;
//	if (nb > base)
//		ft_res(nb / base, base, &str);
//	*(str[i++]) = ft_putnbr_base(nb % base, base);
//}
//char  *ft_itoa_base(unsigned int nb, int base)
//{
//	unsigned int  n;
//	char          *str;
//	int           count = 0;
//	n = nb;
//	while (n != 0)
//	{
//		n /= 10;
//		count++;
//	}
//	str = (char*)malloc(count + 1);
//	str[count + 1] = '\0';
//	ft_res(nb, base, &str);
//	return (str);
//}
//
//int				main(void)
//{
//	//%[флаги][ширина][.точность][размер точности][тип]
//	//%-052*.*x
////	ft_printf("MY:%-0", 5, "Hello", "world");
////	ft_parser("0000----");
//	//printf("ORIG:%-50s", "hellomfqz");
////	char *str = "-*d";
//	t_spec *spec;
////	spec = (t_spec *)malloc(sizeof(t_spec*));
//	if (!(spec = ft_parser("*s",10,"777a")))
//		return (0);
//	ft_processor(spec);
////	printf("flag = '%c'\n",spec -> flag);
////	printf("%s",spec -> content);
//	free(spec);
//	printf("\nORIG:\n%*s",10,"777a");
//
//
////	char *nb;
////	nb = ft_itoa_base(26, 16);
////
////	printf("-----atoi-----\n");
////	printf("%s",nb);
////	return (0);
//}