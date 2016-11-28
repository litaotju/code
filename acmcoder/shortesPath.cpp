#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    char chars[4];
    while( cin.get(chars, 4) ){
        cin.ignore();
        char max_c, min_c, mid_c;
        max_c = max( chars[0], max( chars[1], chars[2]) );
        min_c = min( chars[0], min( chars[1], chars[2]) );
        for(int i=0; i< 3; i++)
            if( chars[i] != max_c && chars[i]!=min_c)
                mid_c = chars[i];
        cout<<min_c<<" "<< mid_c<< " " <<max_c<<endl;
    }
}