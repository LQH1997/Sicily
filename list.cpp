#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct film {
	char name;
	int money;
	struct film * next;
};
int main() {
	struct film *head = NULL;
	struct film *current, *pre;
	char filmname[40];
	while(gets(filmname)!=NULL&&filmname[0] != '\0') {
		current = (struct film*) malloc(sizeof(struct film));
		if(head == NULL) head = current;
		else pre->next = current;
		strcpy(current->name,filmname);
		scanf("%d",&current->money);
	}
	current = head;
	while(current != head) {
		printf("%s %d",current->name,current->money);
		current = current->next;
	}
	}
