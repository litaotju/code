#include <algorithm>
#include <vector>
#include <utility>  // pair, make_pair
#include <iostream> 
#include <cstdio>
using namespace std;

bool compareTask( const pair<int, int> & A, const pair<int, int> &B){
    //开始时间优先
    if(A.first != B.first)
        return A.first < B.first;
    //如果开始时间相等，短任务优先
    return A.second < B.second;
}

double averagaWaitTime(const vector<pair<int, int> > & tasks){
    if(tasks.empty() && tasks.size()<=1)
        return 0;
    
    int waitTimeTotal = 0;
    int waitTimeThisTask = 0;
    int LastTaskFinishTime = tasks.front().first + tasks.front().second;
    
    for(int i = 1 ; i< tasks.size(); i++){
        //上一个任务结束的时间， 减去 应该开始的时间
        waitTimeThisTask = LastTaskFinishTime - tasks[i].first;
        if(waitTimeThisTask < 0)
            waitTimeThisTask = 0;
        //更新上一个任务结束的时间
        LastTaskFinishTime = LastTaskFinishTime + tasks[i].second;
        //更新总的等待时间
        waitTimeTotal += waitTimeThisTask;
    }
    return static_cast<double>(waitTimeTotal)/ tasks.size();
}

int main(){
    int N;
    while(cin>>N && N>0){
        vector<pair<int, int> > task;
        int beginTime, duringTime;
        for(int i =0; i<N; i++){
            cin>>beginTime>>duringTime;
            task.push_back( pair<int,int>(beginTime, duringTime) );
        }
        sort(begin(task),end(task), compareTask);
        // for(auto & e: task){
            // cout<<e.first<<" "<<e.second<<endl;
        // }
        
        //使用下面的方法设置 固定小数位的浮点数输出
        cout.setf( ios::fixed, ios::floatfield);
        cout.precision(4);
        cout<< averagaWaitTime(task)<<endl;
        
        ////等效于上面的方式
        //printf("%.4f\n", averagaWaitTime(task));
    }
}