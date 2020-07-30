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

typedef struct node node;

struct node{
	record data;
	node *next;
	
};

typedef node *record_list;




void list_init(record_list *plist){
	*plist = 0;
}

void list_clear(record_list *plist){
	node *p;
	node *q;
	for(p=*plist;p!=0;p=q){
		q=p->next;
		free(p);
	}
	*plist = 0;
}

int list_insert(record_list *plist, const record *prec){
	node *newnode = malloc(sizeof(node));
	if(newnode == 0){
		return 0;
	}
	newnode->data = *prec;
	newnode->next = *plist;
	*plist = newnode;
	return 1;
}

void list_process(const record_list *plist, void (*f)(const record *))
{
	node *p;
	for(p=*plist; p!=0; p=p->next)
	{
		f(&(*plist)->data);
	}
	
}

void print_record(const record *prec)
{
	printf("%s : %s, %s : %d \n",(*prec).id,(*prec).name.last,(*prec).name.first,(*prec).score);
	
}

int main(void){
	
	
    
	
	
	return 0;
}