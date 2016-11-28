#include <iostream>
#include <string>
#include <map>

using namespace std;
int main(int argc, char * argv[]){
    int N;
    while(cin>>N){
        if( N == 0)
            break;
        map<string, int> fre;
        for(int i=0; i<N; i++){
            string color;
            cin>>color;
            if( fre.find(color)!= fre.end())
                fre[color] += 1;
            else   
                fre[color] = 1;
        }
        int max = 0;
        string max_string = "";
        for( map<string, int>::const_iterator it= fre.begin(); it!=fre.end(); it++){
            if( it->second > max){
                max_string = it->first;
                max = it->second;
            }
        }
        cout<<max_string<<endl;
    }
}