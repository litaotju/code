#include <stdio.h>

bool FindMatrix(int *matrix, int rows, int columns, int target){
	bool found = false;
	if(matrix != NULL && rows > 0 && columns > 0){
		int row = 0;
		int column = columns -1;
		while( row < rows && column >=0){
			if(matrix[row*columns+column] == target){
				found = true;
				break;
			}
			if(matrix[row*columns+column] > target){
				--column;
			}
			else{
				++row;
			}
		}
	}
	return found;
}


int main(int argc, char ** argv){
	bool found;
	int matrix[] = {1,2,3,4,12,33,45,54};
	
	found = FindMatrix(matrix, 2, 4, 78);
	printf("%d", found);
}