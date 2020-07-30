#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define IDSIZE 10
#define NAMESIZE 20
#define LINESIZE 1024
typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	char id[IDSIZE];
	name name;
	int score;
} record;

int read_record(record *prec){
	char line[LINESIZE];
	size_t i;
	char id[LINESIZE];
	char last[LINESIZE];
	char first[LINESIZE]; 
	int score;
	int id_counter = 0;

	/*printf("Enter here:\n");*/
	
	if( !fgets(line, LINESIZE, stdin) ){
		clearerr(stdin);
		return 0;
	}
	
	if(sscanf(line, "%s %s %s %d", id, first, last, &score) < 4){
		return -1;
	}
	
	/*id check*/
	if(id[0] != 'a'){
		return -1;
	}
	
	for(i = 0; id[i] != '\0'; i++){
		id_counter++;
	}
	if(id_counter != IDSIZE - 1){
		return -1;
	}
	
	/*save to prec*/
	strcpy((*prec).id, id);
		
	if(strlen(first) >= NAMESIZE){
		return -1;
	}
	
	if(strlen(last) >= NAMESIZE){
		return -1;
	}
		
	for(i = 0; first[i] != '\0'; i++){
		(*prec).name.first[i] = tolower(first[i]);
	}
	(*prec).name.first[i] = '\0';
	

	for(i = 0; last[i] != '\0'; i++){
		(*prec).name.last[i] = tolower(last[i]);
	}
	(*prec).name.last[i] = '\0';

	
	(*prec).score = score;

	return 1;	
}

void print_record(const record *prec){
	printf("%s : %s, %s : %d\n",(*prec).id,(*prec).name.last,(*prec).name.first,(*prec).score);
}

int strcmp_name(const name p, const name q){
	const name *pp = &p;
	const name *qq = &q;
	int n = strcmp(pp->last, qq->last);
	if(n!=0){
		return n;
	}
	return strcmp(pp->first, qq->first);
}

int cmp_score_desc_id_asc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = qq->score - pp->score;
	if(n!=0){
		return n;
	}
	return strcmp(pp->id, qq->id);
}

int cmp_name_asc_id_desc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = strcmp_name(pp->name, qq->name);
	if(n!=0){
		return n;
	}
	return strcmp(qq->id, pp->id);
}

int cmp_score_desc_name_asc_id_asc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = qq->score - pp->score;
	int m;
	if(n!=0){
		return n;
	}
	m = strcmp_name(pp->name, qq->name);
	if(m!=0){
		return m;
	}
	return strcmp(pp->id, qq->id);
}



void sort_score_desc_id_asc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_score_desc_id_asc);
}

void sort_name_asc_id_desc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_name_asc_id_desc);
}
 
void sort_score_desc_name_asc_id_asc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_score_desc_name_asc_id_asc);
}



int main(){
   
	
	record a[]={{"a12345678",{"C","A"},10},{"b12345678",{"S","T"},20},
	{"c12345678",{"c","a"},30}};
	
	sort_score_desc_id_asc(a,3);
	
	print_record(&a[0]);
	print_record(&a[1]);
	print_record(&a[2]);
	
	
	return 0;
}