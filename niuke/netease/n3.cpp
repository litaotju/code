#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;

struct corner{
    int row_start;
    int row_end;
    int col_start;
    int col_end;
};

int leastCorner(vector<vector <int> >  & value, corner & area){
    int row_start = area.row_start;
    int row_end = area.row_end;
    int col_start = area.col_start;
    int col_end = area.col_end;
    
    //计算每一行和每一列的价值
    int sum_all = 0;
    
    vector<int> sum_of_col, sum_of_row;
    for(int i= row_start; i<= row_end ; i++){
        int sum_of_i_row = 0;
        for(int j= col_start; j<= col_end; j++){
            sum_of_i_row += value[i][j];
            sum_all += value[i][j];
        }
        sum_of_row.push_back(sum_of_i_row);
    }
    
    for(int j=col_start; j<= col_end; j++){
        int sum_of_j_col = 0;
        for(int i= row_start; i<= row_end; i++)
            sum_of_j_col += value[i][j];
        sum_of_col.push_back(sum_of_j_col);
    }
    
    //计算达到一半的价值
    int row_half = 0, col_half =0;
    int row_now =row_start, col_now =col_start;
    while( row_now < sum_all/2){
        row_now += sum_of_row[row_half];
        row_half++;
    }
    while(col_now < sum_all/2){
        col_now += sum_of_col[col_half];
        col_half++;
    }
    area.row_end = 
    return 2;
}

int main(){
    int N, M;
    vector<vector<int> > value;
    cin>>N>>M;
    //总价值
    int sum = 0;
    for(int i =0; i<N; i++){
        vector<int> row;
        int val;
        for(int j=0; j<M; j++){
            cin>>val;
            sum += val;
            row.push_back(val);
        }
        value.push_back(row);
    }
    corner area = {0,N-1, 0, M-1};
    leastCorner(value, area);
    cout<<leastCorner(value, area);
    
}