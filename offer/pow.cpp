#include <cstdio>
#include <cassert>

#define OPTIMIZE

// 设置全局变量
bool g_InvalidInput = false;

//判断两个浮点数相等
bool equal(double a, double b)
{
    if( a-b <= 0.0000001 || b-a <= 0.0000001)
        return true;
    return false;
}

//当指数是无符号数时
double powerUnsignedExponent(double base, unsigned int exponent){
    double result = 1.0;
    for(int i =0; i < exponent; i++)
        result *= base;
    return result;
}

double powerUnsignedExponent2(double base, unsigned int exponent){
    if(0 == exponent){
        return 1;
    }
    if(1==exponent){
        return base;
    }
    
    //递归形式，同时 没有采用除法而是采用移位操作，加速运算
    double result = powerUnsignedExponent2(base, exponent >> 1);
    
    result *= result;
    if(exponent & 0x1 == 1){
        result *= base;
    }
    return result;
}


double power(double base, int exponent){
    g_InvalidInput = false;
    
    if( equal(0.0, base) && exponent < 0 ){
        g_InvalidInput = true;
        return 0;
    }
    
    unsigned int absExponent = (unsigned int) exponent;
    if( exponent < 0)
        absExponent = (unsigned int)(-exponent);
    
    #ifdef OPTIMIZE
        double result = powerUnsignedExponent2(base, absExponent);
    #else
        double result = powerUnsignedExponent(base, absExponent);
    #endif
    
    if(exponent <0){
        result = 1/ result;
    }
    return result;
}

int main(){
    printf( "1.4^2 = %.f\n" , power(1.4, 2));
    double r = power(0, -1);
    assert(r==0 && g_InvalidInput==true);
}
