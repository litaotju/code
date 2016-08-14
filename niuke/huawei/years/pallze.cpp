#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <utility>
using namespace std;


int main(){
    int m, n;
    while(cin>>m>>n){
        vector<vector<int> > paza (m, vector<int>(n, 0));
        int can = 0;
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>can;
                paza[i][j] = can;
            }
        }
        vector<vector<int> > dis (m, vector<int>(n, 10000));
        vector<vector<int> > prevX(m, vector<int>(n, 0));
        vector<vector<int> > prevY(m, vector<int>(n, 0));
        dis[0][0] = 0;
        for(int i = 0; i<m*n-1; i++){
            for(int row = 0; row < m; row++){
                for(int col = 0; col < n; col++){
                    if(paza[row][col]==1)
                        continue;
                    int before, after;
                    after = dis[row][col]+1;
                    int x = row-1, y = col;
                    if (x>=0 && paza[x][y]==0){
                        before =  dis[x][y];
                        if (after < before){
                            prevX[x][y] = row;
                            prevY[x][y] = col;
                            dis[x][y] = after;
                        }
                    }
                    x = row+1;
                    if(x<m && paza[x][y]==0){
                        before =  dis[x][y];
                        if (after < before){
                            prevX[x][y] = row;
                            prevY[x][y] = col;
                            dis[x][y] = after;
                        }
                    }
                    x = row; y = col-1;
                    if( y>=0 && paza[x][y]==0){
                        before =  dis[x][y];
                        if (after < before){
                            prevX[x][y] = row;
                            prevY[x][y] = col;
                            dis[x][y] = after;
                        }
                    }
                    y = col+1;
                    if(y<n && paza[x][y]==0){
                        before =  dis[x][y];
                        if (after < before){
                            prevX[x][y] = row;
                            prevY[x][y] = col;
                            dis[x][y] = after;
                        }
                    }
                }
            }    
        }
        
        stack< pair<int, int> > steps;
        auto last = make_pair<int, int>(m-1, n-1);
        steps.push(last);
        int x = prevX[m-1][n-1], y = prevY[m-1][n-1];
        while(x!=0 || y!=0){
            steps.push( pair<int,int>(x, y) );
            int nextX = prevX[x][y];
            int nextY = prevY[x][y];
            x = nextX;
            y = nextY;
        }
        printf("(0,0)\n");
        while(!steps.empty()){
            x = steps.top().first, y = steps.top().second;
            printf("(%d,%d)\n", x, y);
            steps.pop();
        }
    }
}