#include <iostream>
#include <cmath>
using namespace std;

int M =100;
double A = 0.618;
/*
本源代码主要实验了两种哈希函数的hash过程
*/

typedef int Data;

template<class Data>
class HashTable{
private:
    int tableSize;
    int (* hashFunc)(int);
    Data ** table;
    
    //禁止调用拷贝构造函数
    //因为含有 Data**指针，所以如果使用编译器默认的拷贝构造函数，会出现问题
    //Effective C++
    HashTable(const HashTable & right){
    }
    //同理，使得编译器不自动生成赋值操作符
    //禁止调用=赋值
    HashTable operator = (const HashTable & right){
    }
    
public:
    HashTable(int tableSize, int (*hashFunc)(int)):tableSize(tableSize),hashFunc(hashFunc){
        table = new Data*[tableSize];
        for(int i =0; i<tableSize; i++){
            table[i] = NULL;
        }
    }
    
    int getTableEntry(int key){
        return hashFunc(key);
    }
    
    Data * getLinkListHead(int key){
        return table[getTableEntry(key)];
    }
    
    ~HashTable(){
        delete []table;
    }
    
};
//直接取余数函数
int modHash(int key){
    return key % M;
}

//乘法哈希函数
int multiplicationHash(int key){
    double multi = A*key;
    return static_cast<int>(floor(M*(multi-floor(multi))));
}

int main(){
    int (*p)(int) ;
    while(true){
        cout<<"plz input M:";
        cin>>M;
        cout<<"plz input A:";
        cin>>A;
        p = modHash;
        HashTable<Data> table(M, p);
        cout<<table.getTableEntry(100) << table.getTableEntry(89)<<endl;        
        // // 会调用复制构造函数
         // HashTable<Data> table2 = table;
         // HashTable<Data> table3(M,p);
        // //会调用赋值操作符
         // table3 = table;
         p = multiplicationHash;
         HashTable<Data>table2(M,p);
         cout<< table2.getTableEntry(100) << table2.getTableEntry(89)<<endl;
    }
}