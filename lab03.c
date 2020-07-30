#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "PASSED" : "**FAILED**", #PRED)


size_t str_replace_all(char s[], int oldc, int newc);

int str_replace_last(char s[], int oldc, int newc);

int str_all_digits(const char s[]);


int str_equal(const char s[], const char t[]);



int main(void)
{
	char s[] = "hello world";
	char s2[]= "hello world";
	char s3[]= "hello world";
	
	char s5[] = "my people";
	char s6[] = "my people";
	char s7[] = "my peeps";
	
	CHECK(str_replace_all(s,'l','x')==3);
	CHECK(strcmp(s,"hexxo worxd")==0);
	
	
	CHECK(str_replace_all(s,'o','t')==2);
	CHECK(strcmp(s,"hexxo worxd")==0);
	CHECK(str_replace_all(s,'h','y')==1);
	CHECK(strcmp(s,"hexxo worxd")==0);
	
	CHECK(str_replace_last(s,'d','h')==1);
	CHECK(str_replace_last(s,'h','g')==1);
	CHECK(str_replace_last(s,'w','k')==1);
	
	
	CHECK(str_all_digits(s5));
	CHECK(str_all_digits(s2));
	CHECK(str_all_digits(s7));
	
	CHECK(str_equal(s5, s6));
	CHECK(str_equal(s2, s3));
	CHECK(str_equal(s7, s6));
	
	CHECK(str_equal("hell","hello")==0);
	CHECK(str_equal("hello","hell")==0);
	
	return 0;
}


size_t str_replace_all(char s[], int oldc, int newc)
{
	size_t i = 0;
	size_t count = 0;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == (char)oldc){
			s[i] =(char)newc;
			count++;
		}
	}
	return count;
	
}



int str_replace_last(char s[], int oldc, int newc)
{
	size_t i = 0;
	int index = -1;
	for(i = 0; s[i] != '\0'; i++){
			if(s[i] == (char)oldc){
				index = i;
			}
	}
	
	if(index != -1){
		s[index] = (char)newc;
		return 1;
	}
	return 0;
	
}

int str_all_digits(const char s[])
{
	
	size_t i = 0;
	for(i = 0; s[i] != '\0'; i++){
		if(!isdigit((int)s[i])){
			return 0;
		}
	}
	return 1;

	
}


int str_equal(const char s[], const char t[])
{
	size_t i;
	
	for (i = 0; s[i] != '\0' || t[i] != '\0'; i++)
	{
		if(s[i] != t[i])
			return 0;
	}
	return 1;
	

	
}

