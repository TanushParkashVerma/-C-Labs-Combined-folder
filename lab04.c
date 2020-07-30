#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "PASSED" : "**FAILED**", #PRED)


void squeeze_spaces(void);
void format_words(void);



int main(void)
{
	format_words();
	
	return 0;
}

void squeeze_spaces(void){
	int c;
	int spacecount = 0;
	while((c = getchar()) != EOF){
		if(isspace(c)){
			spacecount ++;
			if(spacecount <= 1){
			   putchar(c);
			}
		}else{
			putchar(c);
			spacecount = 0;			
		}	
	}
	
}



void format_words(void){
	int c;
	int counter = 1;
	while ((c = getchar()) != EOF){
		if(isspace(c) || c == '\'' || c == '\"'){
			counter = 1;
			putchar(c);		
		}else{
			if(counter == 1){
				putchar(toupper(c));
				counter = 0;
			}else{
				putchar(tolower(c));
				counter = 0;		
			}
		}
	}
	
}
