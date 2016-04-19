/*
ACM Coder 1003 Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6
*/
#include <cstdio>
int maxSubArray( int array[], int N, int & start, int & end){
    start= 0;
    end = 0;
    //最大和
    int maxSum = 0x80000000;
    //记录当前的状态
    int curSum = 0;
    int curStart =0;
    int curEnd = 0;
    
    //序号
    int index = 0;
    while(index < N){
        if(curSum < 0){
            curSum = array[index];
            //丢弃结果重新开始
            curStart = index;
            curEnd = index;
        }else{
            //当前子序列要加上index这个元素
            curSum += array[index];
            //所以当前子序列的尾部要进行改变
            curEnd = index;
        }
        //如果当前子序列比以前最大的要大，那么更新最大的子序列的状态
        if( curSum > maxSum){
            start = curStart;
            end = curEnd;
            maxSum = curSum;
        }
        index ++;
    }
    ++start;
    ++end;
    return maxSum;
}


int main(){
    int T;
    //scanf会自动的跳过空格或者换行，从输入流中提取中数字
    scanf("%d", &T);
    for(int i=1;i <=T; i++){
        int N;
        scanf("%d", &N);
        int *array = new int[N];
        for(int j=0; j <N; j++){
            scanf("%d", array+j);
        }
        int start=0;
        int end=0;
        int maxSum = maxSubArray(array,N, start, end);
        printf("Case %d:\n", i);
        printf("%d %d %d\n", maxSum, start, end);
        if( i < T)
            printf("\n");
    }
    
}