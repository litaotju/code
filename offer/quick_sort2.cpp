#include <stdio.h>

int partition(int data[], int p, int q){
	int x = data[q];
	int i = p-1;
	int tmp;
	for(int j = p; j <= q-1; j++){
		if( data[j] <= x){
			++i;
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
	}
	++i;
	tmp = data[i];
	data[i] = x;
	data[q] = tmp;
	return i;
}

void quick_sort( int data[], int p, int q){
	if(p < q){
		int r = partition(data, p, q);
		printf("%d\n", r);
		quick_sort(data, p, r-1);
		quick_sort(data, r+1, q);
	}
}

int main(){
	int data[] = {1, 34, 5, 6576, 12, 3};
	int length = 6;
	for(int i=0; i < length; i++){
		printf("<%d", data[i]);
	}
	printf("\n");
	quick_sort(data, 0, length-1);
	
	for(int i=0; i < length; i++){
		printf("<%d", data[i]);
	}
	printf("\n");
}
