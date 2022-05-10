#include <stdio.h>

#define unsigned int UI

UI N;
int i, j; 

UI** alloc_matrix(UI side)
{
	UI **matrix;
	table = calloc(n, sizeof(UI*));
	for (i = 0; i < side; i++) 
	{
		table[i] = calloc(side, sizeof(UI));
	}
	return matrix;
}

void free_matrix(UI** matrix, UI side) 
{
	for (i = 0; i < side; i++) {
		free(matrix[i]);
	}
	free(matrix);
}


int main()
{
	scanf("%d", &N);
	
	UI **men;
	UI **women;
	
	men = alloc_matrix(N);
	women = alloc_matrix(N);
	
	persons = calloc(N, sizeof(UI));
	UI person; 
	
	UI temp;
	for (i = 0; i < 2*N; i++) {
		person = scanf("%u", &person);
		person -= 1;
		for (j = 0; j < N; j++) {
			temp = scanf("%u", &temp);
			temp -= 1;
			if (persons[person] > 0) // first women than men
				women[person][j] = temp;
			else
				men[person][j] = temp;
		}
		persons[person] += 1	
	}
	
	free_matrix(men, N);
	free_matrix(women, N);
	return 0;
}

