#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "PASSED" : "**FAILED**", #PRED)
#define LINESIZE	1024



int get_word(const char prompt[], char word[], size_t n);
int is_valid_id(const char s[]);



int main(void)
{
	char s[10] ;
	
	
	
	while(get_word("Please enter",s,10))
	{
		if(is_valid_id(s))
		{
			s[0]='a';
			fprintf(stderr,"%s\n",s);
		}
	}

	
	return 0;
}




int get_word(const char prompt[], char word[], size_t n)
{
	char line[LINESIZE];
	char text[LINESIZE];
	while(1){
		printf("%s\n",prompt);
		
		if(!fgets(line,LINESIZE,stdin)){
			clearerr(stdin);
			return 0;
		}
		if(sscanf(line,"%s",text)==1){
			if(strlen(text) < n){
				strcpy(word,text);
				return 1;
			}
		}
	}
	
}




int is_valid_id(const char s[])
{
	size_t i;

	if (strlen(s) != 9)
		return 0;

	if (toupper(s[0]) != 'A')
		return 0;

	for (i = 1; s[i] != '\0'; i++) 
		if (!isdigit(s[i]))
			return 0;

	return 1;
	
}























