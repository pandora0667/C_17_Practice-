#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define S_SIZE 100

typedef struct movie {
	char title[S_SIZE]; 
	double rating;
} MOVIE; 

int main()
{
	MOVIE *movies; 
	int size, i;

	printf("몇 편이나 저장하시겠습니까? : "); 
	scanf("%d", &size); 
	getchar();

	movies = (MOVIE *)malloc( sizeof(MOVIE) * size );
	if( movies == NULL)
	{
		fprintf(stderr, "동적 메모리 할당 오류!!\n");
		exit(1);
	}

	for(i=0; i<size; i++) 
	{
		printf("영화제목 : ");
		fgets(movies[i].title, S_SIZE, stdin);

		printf("영화평점 : ");
		scanf("%lf", &(movies[i].rating));
		getchar();
	}

	printf("===========================\n"); 
	printf("제목 \t 평점\n"); 
	printf("===========================\n"); 
	
	for(i=0; i<size; i++)
		printf("%s \t %f\n", movies[i].title, movies[i].rating); 
		
	printf("===========================\n"); 
	free(movies); 
	return 0; 
} 


