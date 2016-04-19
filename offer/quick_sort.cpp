#include <stdio.h>

int partition(int data[], int start, int end){
	int i = start - 1;
	int x = data[end];
	int tmp;
	for (int j = start; j <= end - 1; j++){
		if (data[j] <= x){
			tmp = data[++i];
			data[i] = data[j];
			data[j] = tmp;
		}
	}

	tmp = data[i + 1]; 
	data[i + 1] = x;
	data[end] = tmp;

	return i+1;
}

void quick_sort(int data[], int start, int end){
	if (start < end){
		int q = partition(data, start, end);
		quick_sort(data, start, q - 1);
		quick_sort(data, q + 1, end);
	}
}

int main(int argc, char ** argv){

	int data[] = { 1, 45, 43453, 32, 132 , 1823, 777};
	int length = 7;

	for (int i = 0; i < length; i++){
		printf("%d<", data[i]);
	}
	printf("\n");
	
	quick_sort(data, 0, length-1);

	for (int i = 0; i < length; i++){
		printf("%d<", data[i]);
	}
	printf("\n");
}