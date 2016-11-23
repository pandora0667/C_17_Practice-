#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 100
double *scores = NULL; 

int addScore(double newScore);

int main()
{
	int i, size; 
	double value, total  = 0.0;

	size = 3;
	for( i=0; i<size; i++)
	{
		printf("성적 : ");
		scanf("%lf", &value);
		addScore(value);
	}

	for( i=0; i<size; i++)
		total += scores[i];
	
	printf("평균 : %f\n", total/size);
	free(scores);

	return 0;
}

int addScore(double newScore)
{
	static int limit = 0; // 동적배열의 최대크기 
	static int count = 0; // 현재 동적배열의 크기
	
	if( count < limit )
		scores[count ++] = newScore;
	else 
	{
		int newLimit = limit + INCREMENT;

		double *newArray = realloc( scores, newLimit*sizeof(double) );
		if( newArray == NULL)
			fprintf(stderr, "메모리 할당 오류\n"); 
		else 
		{
			scores = newArray;
			limit = newLimit;
			scores[count++] = newScore;
		}

		return 0; 
	}
}

