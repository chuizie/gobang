#include "easyx_components.h"
//index
//首页  == 0
//棋子选择页 == 1
//难度选择页 == 2
//回放目录 == 3
//PVP游戏界面 == 4
//PVE游戏界面 == 5
//回放游戏界面 == 6 

using namespace std;

void Homepage();
void chessSelection();
void difficultySelection();
void GameReplaylag();
void PVPGamePage();
void PVEGamePage();
void gameReplayPage();


int main(){
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			c[i][j] = 2;
		}
	}
	
	initgraph(WIDTH, HEIGHT);
	Homepage();
	int lastindex = 0;
	
	do {
		switch (nowindex){
			case 0 :
				lastindex = nowindex;
				Homepage();
				break;
			
			case 1 :
				lastindex = nowindex;
				chessSelection();
				break;
			
			case 2 :				
				lastindex = nowindex;
				difficultySelection();
				break;
				
			case 3 :
				lastindex = nowindex;
				GameReplaylag();
				break;
			
			case 4 :
				lastindex = nowindex;
				PVPGamePage();				
				break;	
				
			case 5 : 
				lastindex = nowindex;
				PVEGamePage();
				break;
			
			case 6 :
				lastindex = nowindex;
				gameReplayPage();
				break;
			
		}
	}while(nowindex != lastindex);
	
	
	
	getchar();
	return 0;
}





