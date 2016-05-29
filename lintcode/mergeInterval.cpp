#include <algorithm>
#include <vector>
#include <iostream>

//problem 156 合并区间

using namespace std;
//Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool compare(const Interval & a, const Interval &b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> result;
        if(intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        for(int i =1; i < intervals.size(); ++i){
            if(intervals[i].start <= result.back().end){
                Interval temp(result.back().start, max(intervals[i].end, result.back().end));
                result.pop_back();
                result.push_back(temp);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    
};

int main(){
    Interval a(1,4),b(0,3),c(3,5);
    vector<Interval> intervals, result;

    intervals.push_back(a);
    intervals.push_back(b);
    intervals.push_back(c);
    sort(intervals.begin(), intervals.end(), Solution::compare);
    for(int i=0; i<intervals.size(); ++i){
        cout<< intervals[i].start <<" -> "<<intervals[i].end <<endl;
    }
    Solution solution;
    result = solution.merge(intervals);
    for(int i=0; i<result.size(); ++i){
        cout<< result[i].start <<" -> "<<result[i].end <<endl;
    }
    return 0;
}