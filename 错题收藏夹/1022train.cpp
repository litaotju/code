#include <iostream>
#include <stack>
#include <deque>
#include <cassert>
using namespace std;

int main(){
    int T;
    while(cin>>T){
        char in[10];
        char out[10];
        cin.ignore();
        
        cin.get(in, T+1, ' ');
        cin.ignore();
        cin.get(out, T+1, '\n');
        cin.ignore();
        
        stack<char> in_stack;
        deque <char> out_deque;
        
        //先把所有的输出推入一个双端队列。队列头，先出，队列尾后出
        int i=0;
        while( out[i] != '\0'){
            out_deque.push_back( out[i++] );
        }
        //记录结果
        char result [19];
        char * head = result;
        
        //每一个进站的火车，查看是否是即将出站的。如果是，就直接出站、
        i=0;
        while( in[i] !='\0' ){
            if( in[i] == out_deque.front() ){
                *(head++) = 'i';
                *(head++)= 'o';
                out_deque.pop_front();                
            }else{ //如果不是，先记录下该火车进站
                *(head++)= 'i';
                in_stack.push( in[i] );
            }
            ++i;
        }
        
        //判断，剩下的火车出站顺序能否满足
        while( !in_stack.empty() && in_stack.top()== out_deque.front() ){
            in_stack.pop();
            out_deque.pop_front();
            *(head++)='o';
        }
        *head='\0';
        
        //如果最后站里面还有火车。输出No.
        if( !in_stack.empty()){
            cout<<"No."<<endl<<"FINISH"<<endl;
            continue;
        }
        //如果最后站里面没有火车列。输出Yes
        else{
            head = result;
            cout<<"Yes."<<endl;
            while( *head != '\0'){
                if( *head=='i'){
                    cout<<"in"<<endl;
                }else{
                    cout<<"out"<<endl;
                }
                ++head;
            }
            cout<<"FINISH"<<endl;
        }
    }
    return 0;
}