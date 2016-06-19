#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned int numType;


int partition(numType * data, int start, int end){
	numType x = data[end];
	int i = start -1;
	for(int j = start; j < end; j++ ){
		if(data[j] <= x){
			++i;
			swap( *(data+i), *(data+j) );
		}
	}
	++i;
	swap( *(data+i), *(data+end));
	return i;
}

void quick_sort(numType * data, int start, int end){
	if( start < end){
		int index = partition(data, start, end);
		quick_sort(data, start, index-1);
		quick_sort(data, index+1, end);
	}
}

vector<numType> deleteAndSort(numType *data , int start, int end ){
   	vector<numType> result;
	if(end == start){
		result.push_back(data[start]);
		return result;
	}
	quick_sort(data, 0, end);
	int  last = 0, cur = 1;
	result.push_back(data[last]);
	while( cur <= end){
		if( data[cur] == data[last]){
			cur++;
		}else{
			result.push_back(data[cur]);
			last = cur;
			cur ++;
		}
	}
	return result;
}
int main(){
    vector<numType> inputs;
    numType n;
	cin>> n;
	numType * data = new numType [n];
	for(unsigned int i =0; i< n; i++){
		cin >> *(data+i);
    }
    vector<numType> OutputArray;
	OutputArray = deleteAndSort(data, 0, n-1);
 	for(int i =0; i<OutputArray.size(); i++){
        cout << OutputArray[i] <<endl;
    }
}