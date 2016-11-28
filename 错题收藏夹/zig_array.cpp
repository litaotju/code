//============================================================================
// Name        : lintcode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
lintcode 题：按照之字形遍历数组的答案
http://www.lintcode.com/zh-cn/problem/matrix-zigzag-traversal/#
*/

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
 vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int row = matrix.size();
        int col = matrix[0].size();
        enum {right=1, leftdown=2, down=3, rightup=4};
        
        int direction;
        int x = 0, y = 0;
        if(col > 1){
            direction = 1; //right
        }
        else{
            direction = 3; //down
        }
        result.push_back(matrix[x][y]);
        
        for(int i = 1; i< row*col; i++){
            switch(direction){
                case 1:{ //right
                    ++y;
                    if(row == 1)
                        break;
                    if(x == 0)
                        direction++; // leftdown
                    else{
                        assert(x==row-1);
                        direction = 4;
                    }
                    break;
                }
                case 2:{ //leftdown
                    ++x;
                    --y;
                    if(x == row-1){
                        direction --; //right
                    }
                    else if(y==0){
                        direction ++; // down
                    } 
                    //else do nothing
                    break;
                }
                case 3:{ //down
                    ++x;
                    if(col ==1)
                        break;
                    if(y==col-1)
                        direction = 2; //leftdown
                    else{
                        direction++; // rightup
                    }
                    break;
                }
                case 4:{ //rightup
                    --x;
                    ++y;
                    if(y==col-1){
                        //down
                        direction = 3;
                    }
                    else if (x == 0){
                        //right
                        direction = 1;
                    }
                    //else do nothing
                    break;
                }
            }
            //cout<<"x: "<< x<< " y: " << y<< " dir"<< direction <<endl;
            if( x <0 || x>row-1 || y<0 || y>col-1)
                cerr<<"Index wrong"<<endl;
            else
                result.push_back(matrix[x][y]);
        }
        return result;
    }
    
    
int main() {
	
	int M, N;
//	while(cin>>M>>N && M > 0 && N>0){
		vector<vector<int> > matrix;
	M = 3; N=4;
		for(int i =0; i <M; i++){
			vector<int> row;
			for(int j =0; j<N; j++){
				int X = M*(i-1)+j;
				//cin>>X;
				row.push_back(X);
			}
			matrix.push_back(row);
		}
		cout<<"Matrix en"<<endl;
		printZMatrix(matrix);
//	}
	
	return 0;
}
