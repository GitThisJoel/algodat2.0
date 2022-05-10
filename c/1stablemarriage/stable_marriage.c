#include <stdlib.h>
#include <stdio.h>

unsigned int** alloc_matrix(unsigned int side)
{
	int i;
	unsigned int **matrix;
	matrix = calloc(side, sizeof(unsigned int*));
	for (i = 0; i < side; i++) 
	{
		matrix[i] = calloc(side, sizeof(unsigned int));
	}
	return matrix;
}

void free_matrix(unsigned int** matrix, unsigned int side) 
{
	int i;
	for (i = 0; i < side; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void print_matrix(unsigned int** matrix, unsigned int side) 
{
	int i, j;
	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++) 
			printf("%u\t", matrix[i][j]);
		printf("\n");
	}
}

int main()
{
	int i, j;
	unsigned int N;
	scanf("%u", &N);
	
	unsigned int **women;
	unsigned int **men;
	
	women = alloc_matrix(N);
	men = alloc_matrix(N);
	
	unsigned int *persons;
	persons = calloc(N, sizeof(unsigned int));
	
	unsigned int person; 	
	unsigned int temp;

	for (i = 0; i < 2*N; i++) {
		scanf("%u", &person);
		for (j = 0; j < N; j++) {
			scanf("%u", &temp);
			
			if (persons[person-1] > 0) // first women then men
				women[person-1][j] = temp-1;
			else
				men[person-1][j] = temp-1;
		}
		persons[person-1] += 1;
	}
	
	print_matrix(women, N);	
	print_matrix(men, N);	

	free_matrix(women, N);
	free_matrix(men, N);
	return 0;
}

