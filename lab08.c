#include <stdio.h>
#include <stdlib.h>

#define IDSIZE 10
#define NAMESIZE 20
#define BLOCK 2

typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	char id[IDSIZE];
	name name;
	int score;
} record;

typedef struct record_list record_list;
struct record_list{
	record *data;
	size_t nalloc;
	size_t nused;
};

void list_init(record_list *plist){
	(*plist).data = 0;
	(*plist).nalloc = 0;
	(*plist).nused = 0;
}


void list_clear(record_list *plist){
	free((*plist).data);
	(*plist).nalloc = 0;
	(*plist).nused = 0;
	printf("Cleared\n" );

	
}

int list_insert(record_list *plist, const record *prec){
	if((*plist).nalloc == (*plist).nused){
		record *temp = realloc(plist->data, ((*plist).nalloc + BLOCK) * sizeof(record));
		if(temp == 0){
			fprintf(stderr,"unable to allocate memory");
			return 0;
		}
		
		(*plist).data = temp;
		(*plist).nalloc = ((*plist).nalloc) + BLOCK;
	}
	
	(*plist).data[(*plist).nused] = *prec;
	(*plist).nused++;
	
	return 1;
}


void print_record(const record *prec)
{
	printf("%s : %s, %s : %d \n",(*prec).id,(*prec).name.last,(*prec).name.first,(*prec).score);
	
}




int main(void){

	
	record_list R1;
    record myRecord = {"A01060474",{"verma","tanush"},100};

	list_init(&R1);
	list_insert(&R1, &myRecord);
	list_insert(&R1, &myRecord);
	list_insert(&R1, &myRecord);
	list_insert(&R1, &myRecord);
	
    print_record(&R1.data[0]);
	print_record(&R1.data[1]);
    print_record(&R1.data[2]);
	print_record(&R1.data[3]);
    list_clear(&R1);

    
	
	
	return 0;
}