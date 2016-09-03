class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        int * pUglyNumbers = new int[index];
        pUglyNumbers[0] = 1;
        int nextUglyNumberIndex = 1;
        int *pMulti2 = pUglyNumbers;
        int *pMulti3 = pUglyNumbers;
        int *pMulti5 = pUglyNumbers;
        while(nextUglyNumberIndex < index){
            int min = Min(*pMulti2 *2, *pMulti3*3, *pMulti5*5);
            pUglyNumbers[nextUglyNumberIndex] = min;
            while( *pMulti2 * 2 <= min ){
                pMulti2 ++;
            }
            while(*pMulti3 *3 <= min){
                pMulti3 ++;
            }
            while(*pMulti5 * 5<= min){
                pMulti5 ++;
            }
            ++ nextUglyNumberIndex;
        }
        int ugly = pUglyNumbers[nextUglyNumberIndex-1];
        delete [] pUglyNumbers;
        return ugly;
    }
};


int Min(int a, int b, int c){
    int min = (a<b)? a: b;
    int min = min < c ? min : c;
    return min;
}


