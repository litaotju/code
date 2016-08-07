#include <map>
#include <set>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

//拓扑排序
class Cmp {
public:
    int cmp(int g1, int g2, vector<vector<int> > records, int n) {
       	map<int, set<int> > graph;
        for(auto & edge: records){
            auto adj_iter = graph.find(edge[0]);
            if(adj_iter == graph.end()){
                auto adj_set = set<int>();
                graph[edge[0]] = adj_set;
            }
            graph[edge[0]].insert(edge[1]);
        }
        if( has_path(g1, g2, graph))
           return 1;
        if(has_path(g2, g1, graph))
           return -1;
        return 0;
    }
    
 private:
    typedef map<int, set<int> > Graph;
    
    bool has_path(int g1, int g2, Graph & graph){
        set<int> visited;
        deque<int> qq;
        qq.push_back(g1);
        
        while(!qq.empty()){
            //加载未被访问的节点
            for(auto next: graph[qq.front()]){
                if (visited.find(next)==visited.end())
                	qq.push_back(next);
            }
            //如果发现了 g2
            if(qq.front()==g2)
                return true;
            visited.insert(qq.front());
            qq.pop_front();
        }
        return false;
    }
};

int main(){
    Cmp cmp;
    vector< vector<int> > records = {{1,2},{2,4},{1,3},{4,3}};
    cout<<cmp.cmp(2, 3, records, 4)<<endl;
    cout<<cmp.cmp(1,2, records, 4)<<endl;
    return 0;
}