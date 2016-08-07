#include<vector>
#include <iostream>
using namespace std;

int main(){
    int buget, N;
    cin>>buget>>N;
    int v, p, q;
    // price, value
    vector< vector<int> > value;
    for(int i=0; i<N; i++){
        cin>>v>>p>>q;
        if( q==0 ){
            vector<int> temp {v, v*p};
            value.push_back(temp);
        }
        else{
            value[q-1][0] += v;
            value[q-1][1] += v*p;
        }
    }
    
    //背包问题
    int cur_row  = 0;
    vector< vector<int> > matrix(2, vector<int>(buget+1, 0));
    for(int i=0; i < value.size(); i++){
        for( int j = 1; j <= buget; j++){
            cur_row = i%2;
            if( value[i][0] <= j){
            matrix[cur_row][j] = max(matrix[1-cur_row][ j-value[i][0] ] + value[i][1], //买了当前这一件
                                        matrix[1-cur_row][j]); //没买当前这一件
            }else{
                matrix[cur_row][j] = matrix[1-cur_row][j];
            }
        }
    }
    cout<<matrix[cur_row][buget]<<endl;
}