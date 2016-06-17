#include <cstdio>

int getMinSession(int hp,int mp, int hpboss, bool playerTurn){
    int cnt = 0;
	int bossCnt = 0;
    while( hp >0 && hpboss >0){
        if(playerTurn){
            cnt++;
            if(mp >=10){ //如果可以实施魔法
                //playerDoMagicAttack();
				hpboss -= 60;
				mp -= 10;
            }else{ //不能施法时
                if(hpboss <= 17 ){ //如果可以直接杀死boss,则直接杀死
                    hpboss -= 17;
				}else if (hpboss > 60){
					mp += 4;
				}else{ //如果不能直接杀死，则根据当前的局势，来判定是否需要休息一个回合恢复魔法
					if (bossCnt == 3){
						hp -= 30;
					}else{
						hp -= 10;
					}
                    int sessionDoNothing = getMinSession( hp, mp+4, hpboss, true);
                    int sessionAttack = getMinSession(hp, mp, hpboss-17, true);
                    if (sessionDoNothing < 0 && sessionAttack <0){
                        return -1;
                    } else if( sessionDoNothing > 0 && sessionAttack >0 ){
                        //返回小的
                        return ( (sessionDoNothing < sessionAttack) ? sessionDoNothing: sessionAttack) + cnt;  
                    }else{
                        //返回赢的
                        return ( (sessionDoNothing > sessionAttack) ?sessionDoNothing : sessionAttack) + cnt;
                    }
                }
            }
        }else{
			bossCnt = (++bossCnt) % 5;
			if (bossCnt == 4){
				hp -= 30;
			}else{
				hp -= 10;
			}
        }
		playerTurn = !playerTurn;
    }
	if (hp <= 0){
		return -1;
	}
	else{
		return cnt;
	}
}
int main(){
	int hp, mp, hpboss;
    scanf_s("%d %d %d", &hp, &mp, &hpboss);
    printf("%d\n", getMinSession(hp, mp, hpboss, true) );
    return 0;
}