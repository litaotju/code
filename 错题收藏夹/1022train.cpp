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
        
        //�Ȱ����е��������һ��˫�˶��С�����ͷ���ȳ�������β���
        int i=0;
        while( out[i] != '\0'){
            out_deque.push_back( out[i++] );
        }
        //��¼���
        char result [19];
        char * head = result;
        
        //ÿһ����վ�Ļ𳵣��鿴�Ƿ��Ǽ�����վ�ġ�����ǣ���ֱ�ӳ�վ��
        i=0;
        while( in[i] !='\0' ){
            if( in[i] == out_deque.front() ){
                *(head++) = 'i';
                *(head++)= 'o';
                out_deque.pop_front();                
            }else{ //������ǣ��ȼ�¼�¸û𳵽�վ
                *(head++)= 'i';
                in_stack.push( in[i] );
            }
            ++i;
        }
        
        //�жϣ�ʣ�µĻ𳵳�վ˳���ܷ�����
        while( !in_stack.empty() && in_stack.top()== out_deque.front() ){
            in_stack.pop();
            out_deque.pop_front();
            *(head++)='o';
        }
        *head='\0';
        
        //������վ���滹�л𳵡����No.
        if( !in_stack.empty()){
            cout<<"No."<<endl<<"FINISH"<<endl;
            continue;
        }
        //������վ����û�л��С����Yes
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