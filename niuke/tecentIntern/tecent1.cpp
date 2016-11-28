#include <string>
#include <vector>
#include <iostream>
using namespace std;


int longestCommonSubstring(const string & A, const string & B){
    vector<vector<int> > m;
    if(A.empty()|| B.empty())
        return 0;
    int row = A.size();
    int col = B.size();
    //m[i][j] 指的是 A[i]和B[j]结尾的字符串的最长公共子串的长度
    for(int i=0; i<row; i++){
        m.push_back(vector<int>(col, 0));
    }

    for(int j = 0; j < col; j++){
        m[0][j] = A[0]==B[j] ? 1:0;
    }
    for(int i = 1; i< row; i++){
        m[i][0] = A[i] == B[0] ? 1:0;
    }

    for(int i =1; i< row; i++){
        for(int j = 1; j<col; j++){
            int temp =0;
            if(A[i]==B[j])
                temp = m[i-1][j-1]+1;
            else
                temp =  m[i-1][j-1];
            m[i][j] = max(max(m[i-1][j], m[i][j-1]), temp);
        }
    }
    return m[row-1][col-1];
}

int main(){
    string line;
    while(getline(cin,line)){
        string rline;
        for(int i = line.size()-1; i>=0; i--){
            rline += line[i];
        }
        cout<<line.size()-longestCommonSubstring(line, rline)<<endl;
        line.clear();
    }
}