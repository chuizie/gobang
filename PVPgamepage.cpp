#include "easyx_components.h"

using namespace std;

void PVPGamePage(){
	Page GamePage;
	Chessboard Board;
	Button BUTTON4_home;
	Button BUTTON4_save;
	Button BUTTON4_start;
	Game game;
	
	int gameCount = 0;
	bool nowGameIdentity = 0;
	bool backHomeJuge = 0;
	bool gameFileSave = 0;
	bool gameFileSaveJug = 0;
	char text4_1[] = "当前局数："; 
	char text4_2[] = {0, 0, 0};
	char text4_3[] = "当前轮到：";
	char text4_4[] = "保存对局";
	char text4_5[] = "点击开始";
	char text4_6[] = "回到首页";
	char text4_7[] = "黑棋";
	char text4_8[] = "白棋";
	char text4_9[] = "无效操作";
	char text4_10[] = "对局回放保存成功";
	string delpath = "del gamereplay\\" ;
	string delpathlss;
	ExMessage m;
	FILE *fp = NULL;

	Board.ChessboardDraw();
	GamePage.PageText(1650, 200, text4_1, 50);
	GamePage.PageText(1650, 300, text4_3, 50);
	BUTTON4_home.ButtonCreate(900, 650 ,200, 50, text4_6);
	BUTTON4_save.ButtonCreate(540, 650, 200, 50, text4_4);
	BUTTON4_start.ButtonCreate(180, 650, 200, 50, text4_5);
	
	Board.boardClear();
	
	time_t curtime;
	struct tm *p;
	char name[256] = {0};	
	time(&curtime);
	p = localtime(&curtime);
	sprintf(name, "%d.%d.%d_%d：%02d.txt",1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min);
	string namep = "gamereplay\\" + (string)name;
	fp = fopen(namep.c_str(), "w+");
	fprintf(fp, "Nygaard_gobang_game\n");
	//根据当前时间创建新文件储存新对局 
	
	while(1){
		m = getmessage(EX_MOUSE);
			if(m.message == WM_LBUTTONDOWN){
				if (MouseJug(900, 650, 200, 50, m)){
					backHomeJuge = 1;
					nowindex = 0;
					break;
				}
				else if (MouseJug(540, 650, 200, 50, m)){
					gameFileSave = 1;	
					GamePage.PageText(600, 50, text4_10, 50);				
					continue;
				}
				else if (MouseJug(180, 650, 200, 50, m)){
					GamePage.pageTextRefresh(100, 20, 300, 90);
					break;
				}
			}
		
	}
	//游戏开始前界面选项 

	while (1){			
		if (backHomeJuge){
			break;
		}
		//返回首页的跳转 
		
		if(!nowGameIdentity){
			gameCount ++;
		} 
		//当前局数的处理 
		
		if (gameCount <= 9){
			text4_2[0] = gameCount + 48;
		}
		else {
			text4_2[0] = gameCount / 10 + 48;
			text4_2[1] = gameCount % 10 + 48;
		}
		GamePage.pageTextRefresh(925, 170, 980, 230);
		GamePage.PageText(1900, 200, text4_2, 50);
		GamePage.pageTextRefresh(925, 270, 980, 330);
		if (nowGameIdentity){
			GamePage.PageText(1950, 300, text4_8, 50);
		}
		else{
			GamePage.PageText(1950, 300, text4_7, 50);
		}
		//页面信息提示及刷新 
 	
	 	game.checkFall(nowGameIdentity, gameFileSaveJug);
		if (gameFileSaveJug != 1){		
			game.Fall();
			game.lastNotice(gameCount, nowGameIdentity);		
			fprintf(fp, "%d %d\n", game.nx, game.ny);
		}
		if (gameFileSaveJug == 1){
			GamePage.PageText(600, 50, text4_10, 50);
			gameFileSave = 1;
		}
		//落子检测打印与储存 


		if (nowindex == 0){
			backHomeJuge = 1;
			break;
		}
		//返回首页的跳转 
		
		if (game.check(c)){
			GamePage.pageNoticeWin(nowGameIdentity);
			if (nowGameIdentity){
				fprintf(fp, "白棋胜利");
			}
			else{
				fprintf(fp, "黑棋胜利");
			}
			break;
		}
		//胜负判断及对应文件储存 
		
		if (gameFileSaveJug != 1){
			if (nowGameIdentity == 0){
				nowGameIdentity = 1;
			}
			else{
				nowGameIdentity = 0;
			}
		}
		//身份转换	
		
		if (gameFileSaveJug == 1){
			gameFileSaveJug = 0;
			gameCount --;
		}		
	}
	//对局中循环	

		
	if (!backHomeJuge){
		while(1){
			m = getmessage(EX_MOUSE);
				if(m.message == WM_LBUTTONDOWN){
					if (MouseJug(900, 650, 200, 50, m)){
						backHomeJuge = 1;
						nowindex = 0;
						break;	
					}
					//返回首页 
					else if (MouseJug(540, 650, 200, 50, m)){
						gameFileSave = 1;
						GamePage.PageText(600, 50, text4_10, 50);
						continue;
					}
					//保存对局 
				}
    		
		}	
	}
	//对局结束后按钮判断 
	
	if (!gameFileSave){
		fclose(fp);
		delpathlss = name;
		delpath += delpathlss;
		system(delpath.c_str());
	}
	else{
		fclose(fp);
	}
	//结束后若点击过保存对局则保留文件，否则删除文件 

	
}

