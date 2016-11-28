#include <iostream>
using namespace std;

int getMaxFactor(int i1, int i2){
	int iMax = i1 > i2? i1: i2;
	int iMin = i1 > i2? i2: i1;
	if(iMax % iMin == 0){
		return iMin;
	} else{
		return getMaxFactor( iMin, iMax%iMin);
	}
}

int finalAbility(int initAbility, const int * monsterDeAbs, int numMonster){
	int curAbility = initAbility;
	for( int i=0; i<numMonster; i++){
		if(monsterDeAbs[i] <=  curAbility){
			curAbility += monsterDeAbs[i];
		} else{
			curAbility += getMaxFactor(curAbility, monsterDeAbs[i]);
		}
	}
	return curAbility;
}

int main(){
    
    int I;
    int J;
    cin>>I>>J;
    if(I and J){
        cout << I << J<<endl;
    }
    
	int numMonster;
	int initAbility;

	while(cin>>numMonster >> initAbility){
		int * monsterDeAbs = new int [numMonster];
		for(size_t i =0; i < numMonster; i++)
			cin>> *(monsterDeAbs+i);
		cout<<finalAbility(initAbility, monsterDeAbs, numMonster)<<endl;
		delete [] monsterDeAbs;
	}
	return 0;
}


