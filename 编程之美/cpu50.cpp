#include <unistd.h>

int main(){
	while(true){
		for(int i=0; i < 9600000000; i++)
			;
		sleep(100);
	}
	return 0;
}