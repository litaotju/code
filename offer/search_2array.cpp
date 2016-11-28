#include <vector>
#include <stdio.h>

using namespace std;

    int searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<vector<int> >:: size_type rows, row;
        vector<int>::size_type columns, column;
        
        rows = matrix.size();
        if(rows==0){
            return 0;
        }
        columns = matrix[0].size();
        row = 0;
        column = columns -1;
        
        int ret =0;
        
        while(row < rows && column >=0 ){
            if(matrix[row][column] == target){
                ++ ret;
                ++ row;
                --column;
            }
            else if(matrix[row][column] < target){
                ++ row;
            }
            else{
                -- column;
            }
        }
        
        return ret;
    }


int main(){
	vector< vector<int> > matrix;
	vector<int> row1;
	row1.push_back(1);
	row1.push_back(3);
	row1.push_back(7);
	
	vector<int> row2;
	row2.push_back(5);
	row2.push_back(7);
	row2.push_back(10);
	
	matrix.push_back(row1);
	matrix.push_back(row2);
	
	printf("%d", searchMatrix(matrix, 7));
}