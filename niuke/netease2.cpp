#include <iostream>
#include <math.h>
//using namespace std;

int getDistance(int x1, int y1, int x2, int y2){
	int xD = x1-x2; 
	int yD = y1-y2;
	return xD*xD + yD* yD;
}

int main(){
	int x[4], y[4];
	int R;
	int demage = 0;
	//cout << getDistance(0,3,4,0) <<endl;
	std::cin>>R>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3]>>x[0]>>y[0];
	for( int8_t i = 1; i< 4; i++){
		if(getDistance(x[i],y[i], x[0],y[0]) <= R*R){
			demage += 1;
		}
	}
	std::cout << demage<<"x" <<std::endl;
	return 0;
}