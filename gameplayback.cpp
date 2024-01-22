#include "easyx_components.h"

using namespace std;

void createGameDate() {
	char cwd[256];
	_getcwd(cwd, 256);
	string path = cwd; path += "\\gamereplay";
	if(access(path.c_str(), 0) == -1) mkdir(path.c_str());
}

void makeBat() {
	ofstream fout("makelist.bat");
	fout << "@echo off" << endl;
	fout << "cd gamereplay" << endl;
	fout << "dir /b > datalist1.txt" << endl;
	fout << "findstr /v \"datalist\" datalist1.txt > datalist.txt" << endl;
	fout << "del datalist1.txt" << endl;
	fout << "cd.." << endl;
	fout.close();
}

void getList(vector<string>&gamefile, int &gameCount) {
	system("makelist.bat");
	ifstream inFile("gamereplay\\datalist.txt");
	string line;
	while(getline(inFile, line)){
		gamefile.push_back(line);
		gameCount++;
	}
	inFile.close();
}


void GameReplaylag(){
	Page PAGE3;
	Button BUTTON3_home;
	Button BUTTON3_1;
	Button BUTTON3_2;
	Button BUTTON3_3;
	Button BUTTON3_4;
	Button BUTTON3_5;
	Button BUTTON3_L;
	Button BUTTON3_N;
	
	char text3_title[] = "对局回放";
	char text3_l[] = "上一页";
	char text3_n[] = "下一页";
	char text3_1[] = "左键打开右键删除";
	char gamef[5][30]; 
	vector<string>gamefile;
	int pageCount = 0;
	int nowPageGame = 0;
	int gameCount = 0;
	int nowPage = 1;
	bool backhome = 0;
	bool gotogamereplay = 0;
	bool lpage = 0;
	bool npage = 0;
	bool gameButton[5];
	string delpath = "del gamereplay\\" ;
	string delpathlss;
 
	backhome = 0;
	//初始化
	
	PAGE3.PageText(1080, 80, text3_title, 50);
	PAGE3.PageText(1080, 150, text3_1, 25);
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(218, 112, 214));
	fillroundrect(180, 200, 900, 570, 10, 10);
	BUTTON3_home.Buttonhomepage(950, 650, 200, 50);	
	//页面构造 

	do{
		delpath = "del gamereplay\\" ;
		delpathlss = "0";
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(218, 112, 214));
		fillroundrect(180, 200, 900, 570, 10, 10);
		pageCount = 0;
		nowPageGame = 0;
		gameCount = 0;
		lpage = 0;
		npage = 0;
		for (int i = 0; i < 5; i++){
			gameButton[i] = 0;
		}
		for (int i = 0; i < 30; i++){
			gamereplay[i] = 0;
		}
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 30; j++){
				gamef[i][j] = 0;
			}
		} 
		//初始化 
		
		gamefile.clear();
		makeBat();
		getList(gamefile, gameCount);
		//扫描文件

		if(gameCount % 5 == 0){
			pageCount = gameCount / 5;
		}
		else{
			pageCount = gameCount / 5 + 1;
		}
		//最大页面数量计算

		if (gameCount % 5 == 0 && gameCount != 0){
			nowPageGame = 5;
		}
		else {
			nowPageGame = gameCount % 5;
		}
		cout << nowPageGame << endl;
		//当前页面回放数量计算

		if (nowPage != 1){		
			BUTTON3_L.ButtonCreate(440, 620, 150, 60, text3_l);	
			lpage = 1;	
		}
		if (nowPage != pageCount){
			BUTTON3_N.ButtonCreate(640, 620, 150, 60, text3_n);
			npage = 1;
		}
		//翻页按钮打印
		
		switch(pageCount){
			case 1 :
				if(gameCount <= 5){
					for (int i = 0; i < gameCount; i++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				else{
					for (int i = 0; i < 5; i ++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				break;
			
			case 2 :
				if(gameCount <= 10){
					for (int i = 5; i < gameCount; i++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				else{
					for (int i = 5; i < 10; i ++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}	
				break;

			case 3 :
				if(gameCount <= 15){
					for (int i = 10; i < gameCount; i++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				else{
					for (int i = 10; i < 15; i ++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				break;

			case 4:
				if(gameCount <= 20){
					for (int i = 15; i < gameCount; i++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				else{
					for (int i = 15; i < 20; i ++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				break;

			case 5 :
				if(gameCount <= 25){
					for (int i = 20; i < gameCount; i++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				else{
					for (int i = 20; i < 25; i ++){
						for (int j = 0; j < 30; j++){
							gamef[i][j] = gamefile[i][j];
						}
					}
				}
				break;
		}
//		//将游戏回放与按钮匹配，游戏回放存储数最大为25
		
		switch (nowPageGame){
			case 1 :
				BUTTON3_1.fileButtonCreate(1, gamef[0]);
				gameButton[0] = 1;
				for (int i = 1; i < 5; i++){
					gameButton[i] = 0;
				}
				break;

			case 2 :
				BUTTON3_1.fileButtonCreate(1, gamef[0]);
				BUTTON3_2.fileButtonCreate(2, gamef[1]);
				for (int i = 0; i < 2; i++){
					gameButton[i] = 1;
				}
				for (int i = 2; i < 5; i++){
					gameButton[i] = 0;
				}
				break;

			case 3 :
				BUTTON3_1.fileButtonCreate(1, gamef[0]);
				BUTTON3_2.fileButtonCreate(2, gamef[1]);
				BUTTON3_3.fileButtonCreate(3, gamef[2]);
				for (int i = 0; i < 3; i++){
					gameButton[i] = 1;
				}
				for (int i = 3; i < 5; i++){
					gameButton[i] = 0;
				}
				break;

			case 4 :
				BUTTON3_1.fileButtonCreate(1, gamef[0]);
				BUTTON3_2.fileButtonCreate(2, gamef[1]);
				BUTTON3_3.fileButtonCreate(3, gamef[2]);
				BUTTON3_4.fileButtonCreate(4, gamef[3]);
				for (int i = 0; i < 4; i++){
					gameButton[i] = 1;
				}
				gameButton[4] = 0;
				break;
			
			case 5 :
				BUTTON3_1.fileButtonCreate(1, gamef[0]);
				BUTTON3_2.fileButtonCreate(2, gamef[1]);
				BUTTON3_3.fileButtonCreate(3, gamef[2]);
				BUTTON3_4.fileButtonCreate(4, gamef[3]);
				BUTTON3_5.fileButtonCreate(5, gamef[4]);
				for (int i = 0; i < 5; i++){
					gameButton[i] = 1;
				}		
				break;

		}
		//打印回放对局按钮

		ExMessage p;
		while(true){
			p = getmessage(EX_MOUSE);
				if (MouseJug(440, 620, 150, 60, p) && lpage){
					if (p.message == WM_LBUTTONDOWN){
						nowPage--;
						break;
					}
				}
				//上一页
			
				if (MouseJug(640, 620, 150, 60, p) && npage){
					if (p.message == WM_LBUTTONDOWN){
						nowPage++;
						break;
					}
				}
				//下一页

				if (MouseJug(540, 245, 680, 50, p) && gameButton[0]){
					if (p.message == WM_LBUTTONDOWN){
						nowindex = 6;
						strcpy(gamereplay, gamef[0]);
						gotogamereplay = 1;
						break;
					}
					if (p.message == WM_RBUTTONDOWN){
						delpathlss = gamef[0];
						delpath += delpathlss;
						system(delpath.c_str());
						break;
					}
				}
				//game1

				if (MouseJug(540, 315, 680, 50, p) && gameButton[1]){
					if (p.message == WM_LBUTTONDOWN){
						nowindex = 6;
						strcpy(gamereplay, gamef[1]);
						gotogamereplay = 1;
						break;
					}
					if (p.message == WM_RBUTTONDOWN){
						delpathlss = gamef[1];
						delpath += delpathlss;
						system(delpath.c_str());
						break;
					}
				}
				//game2

				if (MouseJug(540, 385, 680, 50, p) && gameButton[2]){
					if (p.message == WM_LBUTTONDOWN){
						nowindex = 6;
						strcpy(gamereplay, gamef[2]);
						gotogamereplay = 1;
						break;
					}
					if (p.message == WM_RBUTTONDOWN){
						delpathlss = gamef[2];
						delpath += delpathlss;
						system(delpath.c_str());
						break;
					}
				}
				//game3

				if (MouseJug(540, 455, 680, 50, p) && gameButton[3]){
					if (p.message == WM_LBUTTONDOWN){
						nowindex = 6;
						strcpy(gamereplay, gamef[3]);
						gotogamereplay = 1;
						break;
					}
					if (p.message == WM_RBUTTONDOWN){
						delpathlss = gamef[3];
						delpath += delpathlss;
						system(delpath.c_str());
						break;
					} 
				}  
				//game4

				if (MouseJug(540, 525, 680, 50, p) && gameButton[4]){
					if (p.message == WM_LBUTTONDOWN){
						nowindex = 6;
						strcpy(gamereplay, gamef[4]);
						gotogamereplay = 1;
						break;
					}
					if (p.message == WM_RBUTTONDOWN){
						delpathlss = gamef[4];
						delpath += delpathlss;
						system(delpath.c_str());
						break;
					}
				}
				//game5

				if (MouseJug(950, 650, 200, 50, p)){
					if (p.message == WM_LBUTTONDOWN){
						backhome = 1;
						nowindex = 0;
						break;						
					}
				}
			
		}

	}while(!backhome && !gotogamereplay);
}


void gameReplayPage(){
	Page GamePage;
	Page WarnningPage;
	Chessboard Board;
	Button BUTTON6_home_page;
	Button BUTTON6_home_warn;
	Game game;
	
	char text6_1[] = {"警告！文件非法"};
	int gameCount = 0;
	bool nowIdentity = 0;
	ExMessage p;

	string path = "gamereplay\\";
	string pathlss = gamereplay;
	path += pathlss;		
	ifstream inFile(path);
	string checkLine = "Nygaard_gobang_game";
	string line;
	getline(inFile, line);
	//文件打开与检验是否为合法文件 
	
	if (line != checkLine){
		WarnningPage.PageRefresh();
		WarnningPage.PageText(1080, 300, text6_1, 100);
		BUTTON6_home_warn.Buttonhomepage(540, 450, 200, 70);
		
		while(1){
			p = getmessage(EX_MOUSE);	
			if (MouseJug(540, 450, 200, 70, p)){
				if (p.message == WM_LBUTTONDOWN){
					nowindex = 0;
					break;
				}
			}				
		}
	}//非法文件操作 
	else{
		GamePage.PageRefresh();
		Board.boardClear();
		Board.ChessboardDraw();
		BUTTON6_home_page.Buttonhomepage(900, 650, 200, 50);
		
		int fx = 0, fy = 0;
		game.lx = 0;
		game.ly = 0;
		game.nx = 0;
		game.ny = 0;
		
		while(1){
			gameCount++;			
			inFile >> fx;
			inFile >> fy;
			game.lx = game.nx;
			game.ly = game.ny;
			game.nx = fx;
			game.ny = fy;
			c[game.nx][game.ny] = (int)nowIdentity;
			game.Fall();
			game.lastNotice(gameCount, nowIdentity);
			if (game.check(c)){
				GamePage.filePageNoticeWin(nowIdentity);
				break;
			}
			Sleep(2000);
			if (nowIdentity){
				nowIdentity = 0;
			}
			else nowIdentity = 1;
		}
		inFile.close();
		
		while(true){
			p = getmessage(EX_MOUSE);
			if (MouseJug(900, 650, 200, 50, p)){
				if (p.message == WM_LBUTTONDOWN){
					nowindex = 0;
					break;
				}
			}
		}
		
		
		
	}//合法文件操作 
	
}
