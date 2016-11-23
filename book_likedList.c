#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 50

typedef struct NODE { 
	char title[S_SIZE]; 
	int year;
	struct NODE *link;
} NODE;

int main()
{
	NODE *list = NULL; 
	NODE *prev, *p, *next;

	char buffer[S_SIZE];
	int year;
	
	while(1)
	{
		printf("책의 제목을 입력하세요 (종료하려면 -1) : ");
		fgets(buffer, S_SIZE, stdin);
		if(atoi(buffer) == -1)
			break;
		
		p = ( NODE* )malloc( sizeof(NODE) ); 
		if( p == NULL)
		{
			fprintf(stderr, "동적할당에 실패하였습니다. \n");
			exit(1);
		}
	
		strcpy(p -> title, buffer);

		printf("책의 출판 연도를 입력하세요 : ");
		fgets(buffer, S_SIZE, stdin);
		year = atoi(buffer);
		p -> year = year; 

		if(list == NULL)
			list = p;
		else 
			prev -> link = p; 

		p -> link = NULL; 
		prev = p; 
	}
	printf("\n"); 

	p = list; 

	while(p != NULL) 
	{
		printf("\t책의 제목 : %s \n\t출판연도 : %d \n", p -> title, p -> year);
		printf("-------------------------------------\n\n");

		p = p -> link; 
	}

	p = list; 

	while( p != NULL)
	{
		next = p -> link; 
		free(p);
		p = next;
	} 

	return 0;
}
