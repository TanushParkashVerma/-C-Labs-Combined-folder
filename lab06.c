#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "PASSED" : "**FAILED**", #PRED)


void min_max(const int a[], size_t n, int *pmin, int *pmax);

unsigned num_digits(unsigned long n);

int is_reversible(unsigned long n);




int main(void)
{
	const int a[] = { 1,2,5,6,7,8,3,2,5 };
	
	int x = 1234567;
	
	
	size_t n = 9;
	int min, max;
	int *pmin, *pmax;

	pmin = &min;
	pmax = &max;
	
	min_max(a, n, pmin, pmax);
	printf("Min:%d Max:%d\n", min, max);
	
	printf("Number:%u\n" , num_digits(x));
	
	if(is_reversible(x)==1)
	{
		printf("Its reversible");
	}
	else{
		printf("not reversible");
	}

	
	return 0;
}



void min_max(const int a[], size_t n, int *pmin, int *pmax)
{
	size_t i;
	*pmin = a[0];
	*pmax = a[0];
	for(i = 0; i < n; i++) {
		if (*pmin > a[i]) 
		{
			*pmin = a[i];
		}
		if (*pmax < a[i]) 
		{
			*pmax = a[i];
		}
				
	}
}


unsigned num_digits(unsigned long n)
{
	unsigned long i = 1;
	unsigned num = 0;
	while(n/i > 0){
		i *= 10; 
		num++;
	}
	return num;
}


int is_reversible(unsigned long n)
{
	unsigned long rev = 0;
	unsigned remainder;
	while(n!=0)
	{
		remainder = n%10;
		rev = (rev*10) + remainder;
		n = n/10;
		
	}
	if(n == rev)
		return 1;
	else
	{
		return 0;
	}
		
}









	

