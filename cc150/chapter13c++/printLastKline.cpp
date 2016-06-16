#include <cstdlib>  //atoi
#include <string>   // string class
#include <fstream>  //ifstream
#include <iostream> //cout
using namespace std; 

//const int K = 10;
void printLastKLines(string filename, int K=10){
    //使用文件名初始化 ifstream
    //也可以使用默认构造函数，然后使用open成员函数来打开文件
    ifstream file(filename);
    
    string *lines = new string[K];
    int line = 0;
    
    // ifstream::good() 判断文件的状态是否良好
    while(file.good()){
        //从文件输入流中获取一行，存储到 lines[line%K]中
        //使用了环形数组来存储最新的K行
        getline(file, lines[line%K]);
        ++line;
    }
    int start, count;
    //如果总共读取的行数小于K，那么就只需要打印所有读取的行就可以了
    if(line < K){
        start = 0;
        count = line;
    }else{
        start = line %K;
        count = K;
    }
    
    for(int i =0; i<count; i++){
        cout<<K-i<<" : " << lines[(start+i)%K]<<endl;
    }
    file.close();
}

int main(int argc, char **argv){
    if(argc != 2 && argc!=3){
        cout<<"Useage: printL.exe filename [linenum<default=10>]"<<endl;
    }else if(argc==3){
        printLastKLines(argv[1], atoi(argv[2]));
    }else if(argc==2){
        printLastKLines(argv[1]);
    }
}