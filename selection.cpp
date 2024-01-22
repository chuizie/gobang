#include "easyx_components.h"

using namespace std;

void chessSelection(){
	Page PAGE1;
	Button BUTTON1_1;
	Button BUTTON1_2;
	Button BUTTON1_home;
	
	char text1_title[] = "棋子选择"; 
	PAGE1.PageText(WIDTH, yTITLE, text1_title, 100);
	
	char text1_button1[] = "黑棋（先手）"; 
	char text1_button2[] = "白棋（后手）";
	BUTTON1_1.ButtonCreate(WIDTH / 2 , 400, 250, 60 ,text1_button1);
	BUTTON1_2.ButtonCreate(WIDTH / 2 , 500, 250, 60 ,text1_button2);	
	BUTTON1_home.Buttonhomepage(950, 650, 200, 50);
	//按钮打印 
	
	ExMessage i;
	while(true){
		i = getmessage(EX_MOUSE);
		 
		if (MouseJug(WIDTH / 2, 400, 250, 60, i)){
			if (i.message == WM_LBUTTONDOWN){
				PAGE1.PageRefresh();
				nowindex = 5;
				identity = false;
			}
		}
		//黑棋 
		
		if (MouseJug(WIDTH / 2, 500, 250, 60, i)){
			if (i.message == WM_LBUTTONDOWN){
				PAGE1.PageRefresh();
				nowindex = 5;
				identity = true;
			}
		}
		//白棋 
			
		if (MouseJug(950, 650, 200, 50, i)){
			if (i.message == WM_LBUTTONDOWN){
				PAGE1.PageRefresh();
				nowindex = 0;
			}
		}
		//返回首页 

		
	if (nowindex != 1) break;
	}
}

void difficultySelection(){
	Page PAGE2;
	Button BUTTON2_1;
	Button BUTTON2_2;
	Button BUTTON2_home;
	
	char text2_title[] = "电脑难度选择";
	PAGE2.PageText(WIDTH, 200, text2_title, 100); 
	
	char text2_button1[] = "简单";
	char text2_button2[] = "困难";
	BUTTON2_1.ButtonCreate(WIDTH / 2, 400, 250, 60, text2_button1);
	BUTTON2_2.ButtonCreate(WIDTH / 2, 500, 250, 60, text2_button2);
	
	BUTTON2_home.Buttonhomepage(950, 650, 200, 50);
	
	ExMessage n;
	while(true){
		n = getmessage(EX_MOUSE);
			
		if (MouseJug(WIDTH / 2, 400, 250, 60, n)){
			if (n.message == WM_LBUTTONDOWN){
				PAGE2.PageRefresh();
				nowindex = 1;
				difficulty = true;
			}
		}
		//简单模式 
			
		if (MouseJug(WIDTH / 2, 500, 250, 60, n)){
			if (n.message == WM_LBUTTONDOWN){
				PAGE2.PageRefresh();
				nowindex = 1;
				difficulty = false;
			}
		}
		//困难模式 
			
		if (MouseJug(950, 650, 200, 50, n)){
			if (n.message == WM_LBUTTONDOWN){
				PAGE2.PageRefresh();
				nowindex = 0;
			}
		}
		//返回首页 
	
		
	if (nowindex != 2) break;
	}
	
}

