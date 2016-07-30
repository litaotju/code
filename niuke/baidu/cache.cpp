#include <iostream>
#include <deque>
#include <set>
using namespace std;
int main(){
    int N, M;
    while(cin>>N>>M){
        int nextPage;
        int cntPageFault =0;
        deque<int> fifo;
        set<int> cache;
        for(int i=0; i<M; i++){
            cin>>nextPage;
            //新页
            if(cache.find(nextPage)==cache.end()){
                //cache满
                if(fifo.size() >= N){
                    cache.erase(fifo.front());
                    fifo.pop_front();
                    cache.insert(nextPage);
                    fifo.push_back(nextPage);
                }
                //cache不满
                else{
                    cache.insert(nextPage);
                    fifo.push_back(nextPage);
                }
                cntPageFault++;
            }
            //老页面
            else{
                continue;
            }
        }
        cout<<cntPageFault<<endl;
    }
    return 0;
}