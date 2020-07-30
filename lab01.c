#include <stdio.h>

int main(void) {
	char		c = 'a';
	short		s = 100;
	int			i = 100;
	long		l = 100;
	float		f = 100.0;
	double		d = 100.0;
	long double	ld = 100.0;
	short		a[10];
	int			b[10];

/* literals */
printf("size of 'a' is %lu\n", (unsigned long) sizeof('a'));
printf("size of '100' is %lu\n", (unsigned long) sizeof(100));
printf("size of '100.0' is %lu\n\n", (unsigned long) sizeof(100.0));

/* char */
printf("size of 'char' is %lu\n", (unsigned long) sizeof(char));
printf("size of 'c' is %lu\n\n", (unsigned long) sizeof(c));

/* short */
printf("size of 'short' is %lu\n", (unsigned long) sizeof(short));
printf("size of 's' is %lu\n\n", (unsigned long) sizeof(s));

/* int */
printf("size of 'int' is %lu\n", (unsigned long) sizeof(int));
printf("size of 'i' is %lu\n\n", (unsigned long) sizeof(i));

/* long */
printf("size of 'long' is %lu\n", (unsigned long) sizeof(long));
printf("size of 'l' is %lu\n\n", (unsigned long) sizeof(l));

/* float */
printf("size of 'float' is %lu\n", (unsigned long) sizeof(float));
printf("size of 'f' is %lu\n\n", (unsigned long) sizeof(f));

/* double */
printf("size of 'double' is %lu\n", (unsigned long) sizeof(double));
printf("size of 'd' is %lu\n\n", (unsigned long) sizeof(d));

/* long double */
printf("size of 'long double' is %lu\n", (unsigned long) sizeof(long double));
printf("size of 'ld' is %lu\n\n", (unsigned long) sizeof(ld));

/* arrays */
printf("size of 'a' is %lu\n", (unsigned long) sizeof(a));
printf("size of 'b' is %lu\n\n", (unsigned long) sizeof(b));

return 0;
}