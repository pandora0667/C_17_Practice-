#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

typedef struct {
	int number;
	char title[SIZE];
}Book;

int main()
{
	Book *p; 
	int i = 0;

	p = (Book *)malloc( 2 * sizeof(Book) ); 
	if(p == NULL)
	{
		printf("동적메모리 할당 실패\n");
		exit(1);
	}

	p[0].number = 1;
	strcpy(p[0].title, "C Programming");
	
	p[1].number = 2;
	strcpy(p[1].title, "Node.js");

	for(i=0; i<2; i++)
		printf("\tnumber : %d, Title : %s \n", p[i].number, p[i].title);

	free(p);
	return 0;
}
	
