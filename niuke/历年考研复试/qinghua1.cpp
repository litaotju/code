#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int lessInFront = 0;

struct Record{
    string name;
    int grade;
    Record & operator = (Record & rhs){
        this->name = rhs.name;
        this->grade = rhs.grade;
        return *this;
    }
};

int partition(Record records[], int start, int end){
    Record pivot = records[start];
    int low = start, high = end;
    if(lessInFront == 1){
        while(low < high){
            while(low < high && records[high].grade > pivot.grade) high--;
            records[low] = records[high];
            while(low < high && records[low].grade <= pivot.grade) low++;
            records[high] = records[low];
        }
    }else{
        while(low < high){
            while(low < high && records[high].grade < pivot.grade) high--;
            records[low] = records[high];
            while(low < high && records[low].grade >= pivot.grade) low++;
            records[high] = records[low];
        }
    }
    records[low] = pivot;
    return low;
}


void quick_sort(Record records[], int start, int end){
    if(start < end){
        int mid = partition(records, start, end);
        quick_sort(records, start, mid-1);
        quick_sort(records, mid+1, end);
    }
}


void sort(Record records[], int N){
    quick_sort(records, 0, N-1);
}

int main(){
    int N;
    while(cin>>N){
        cin>>lessInFront;
        Record * grades = new Record[N];
        for(int i=0; i<N; i++){
        	string name;
            int grade;
            cin>>name>>grade;
            grades[i].name = name;
            grades[i].grade = grade;
        }
    	sort(grades, N);    
        for(int i =0; i<N; i++){
            cout<<grades[i].name <<" "<<grades[i].grade<<endl;
            //printf("%s %d\n", grades[i].name, grades[i].grade);
        }
        delete [] grades;
    }
}