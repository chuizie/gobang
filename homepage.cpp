#include "easyx_components.h"

using namespace std;

void Homepage(){
	Button BUTTON0_1;
	Button BUTTON0_2;
	Button BUTTON0_3;
	Page HOMEPAGE;
	
	HOMEPAGE.PageRefresh();
	char text0_title[] = "五子棋"; 
    HOMEPAGE.PageText(WIDTH, yTITLE, text0_title, 100);
	
	
	char text0_Button1[] = "PVP";
	BUTTON0_1.ButtonCreate(WIDTH / 2, 360, 250, 60, text0_Button1);
	
	char text0_Button2[] = "PVE";
	BUTTON0_2.ButtonCreate(WIDTH / 2, 450, 250, 60, text0_Button2);
	
	char text0_Button3[] = "对局回放";
	BUTTON0_3.ButtonCreate(WIDTH / 2, 540, 250, 60, text0_Button3);
	//按钮打印 

	ExMessage m;	  
	while (true){
		m = getmessage(EX_MOUSE);
			if (MouseJug(WIDTH / 2, 360, 250, 60, m)){
				if (m.message == WM_LBUTTONDOWN){
					HOMEPAGE.PageRefresh();
					nowindex = 4;
				}
			}
			//PVP
			
			if (MouseJug(WIDTH / 2, 450, 250, 60, m)){
				if (m.message == WM_LBUTTONDOWN){
					HOMEPAGE.PageRefresh();
					nowindex = 2;
				}
			}
			//PVE
			
			if (MouseJug(WIDTH / 2, 540, 250, 60, m)){
				if (m.message == WM_LBUTTONDOWN){
					HOMEPAGE.PageRefresh();
					nowindex = 3;
				}
			}	
			//对局回放
								
		if (nowindex != 0) break;
	}
}
