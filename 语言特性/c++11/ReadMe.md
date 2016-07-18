本目录是一些演示C++11新特性用法的目录
支持c++11需要在编译的过程中加入选项 "-std=c++11"

# 本目录包含的c++11新特性主要有：

1. auto关键字，避免了类型声明的冗余，减少了代码的数量，使程序更简洁。

2. smart_pointer
    + 需要包含 <memory> 头文件
    + 可以使用的有： auto_ptr, shared_ptr, unique_ptr, weak_ptr等
    + 尽可能减少显式的delete和 raw_pointer, 如果需要的话，请尽可能的将他们封装在类内部。

3. range for

````c++
     vector<int> v = {1,2,3,4,5};
     //取值
     for( auto e:v){
         cout<<e;
     }
     //引用
     for(auto & e:v){
         e *= 2;
     }
````

4. nullptr
    + nullptr的使用不需要包含额外的头文件，直接当作关键之一样使用就OKAY了

5. non-member begin() and end()函数
    + 为容器提供了 非成员函数的 begin 和 end 返回容器迭代器的头和尾
    + 更加灵活，在使用自定义的其他类似容器的类时，重载这两个函数即可

6. lambda表达式