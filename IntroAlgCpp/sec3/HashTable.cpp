#include <iostream>
#include <cmath>
using namespace std;

int M =100;
double A = 0.618;
/*
��Դ������Ҫʵ�������ֹ�ϣ������hash����
*/

typedef int Data;

template<class Data>
class HashTable{
private:
    int tableSize;
    int (* hashFunc)(int);
    Data ** table;
    
    //��ֹ���ÿ������캯��
    //��Ϊ���� Data**ָ�룬��������ʹ�ñ�����Ĭ�ϵĿ������캯��������������
    //Effective C++
    HashTable(const HashTable & right){
    }
    //ͬ����ʹ�ñ��������Զ����ɸ�ֵ������
    //��ֹ����=��ֵ
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
//ֱ��ȡ��������
int modHash(int key){
    return key % M;
}

//�˷���ϣ����
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
        // // �����ø��ƹ��캯��
         // HashTable<Data> table2 = table;
         // HashTable<Data> table3(M,p);
        // //�����ø�ֵ������
         // table3 = table;
         p = multiplicationHash;
         HashTable<Data>table2(M,p);
         cout<< table2.getTableEntry(100) << table2.getTableEntry(89)<<endl;
    }
