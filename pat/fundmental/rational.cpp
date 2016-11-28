#include <cstdio>
struct rational{
int numberator;
int denominator;
rational(){}
rational(int numb, int denom): numberator(numb), denominator(denom){
}
};

unsigned int gcd(unsigned int a, unsigned int b){
if(0==b)
return a;
return gcd(b, a%b);
}

rational add(const rational & x, const rational & y){
    rational result;
    result.denominator = x.denominator * y.denominator;
    result.numberator = x.numberator * y.denominator + y.numberator * x.denominator;
    int _gcd = gcd(result.numberator, result.denominator);
    result.numberator /= _gcd;
    result.denominator /= _gcd;
    return result;
}

int main(){
int a,b, c,d;
scanf("%d/%d %d/%d", &a,&b, &c, &d);
rational x (a,b), y(c,d);
rational sum = add(x, y);
if(1==sum.denominator)
    printf("%d", sum.numberator);
else
    printf("%d/%d\n", sum.numberator, sum.denominator);

}