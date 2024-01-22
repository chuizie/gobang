#include "easyx_components.h"

using namespace std;

void chessSelection(){
	Page PAGE1;
	Button BUTTON1_1;
	Button BUTTON1_2;
	Button BUTTON1_home;
	
	char text1_title[] = "����ѡ��"; 
	PAGE1.PageText(WIDTH, yTITLE, text1_title, 100);
	
	char text1_button1[] = "���壨���֣�"; 
	char text1_button2[] = "���壨���֣�";
	BUTTON1_1.ButtonCreate(WIDTH / 2 , 400, 250, 60 ,text1_button1);
	BUTTON1_2.ButtonCreate(WIDTH / 2 , 500, 250, 60 ,text1_button2);	
	BUTTON1_home.Buttonhomepage(950, 650, 200, 50);
	//��ť��ӡ 
	
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
		//���� 
		
		if (MouseJug(WIDTH / 2, 500, 250, 60, i)){
			if (i.message == WM_LBUTTONDOWN){
				PAGE1.PageRefresh();
				nowindex = 5;
				identity = true;
			}
		}
		//���� 
			
		if (MouseJug(950, 650, 200, 50, i)){
			if (i.message == WM_LBUTTONDOWN){
				PAGE1.PageRefresh();
				nowindex = 0;
			}
		}
		//������ҳ 

		
	if (nowindex != 1) break;
	}
}

void difficultySelection(){
	Page PAGE2;
	Button BUTTON2_1;
	Button BUTTON2_2;
	Button BUTTON2_home;
	
	char text2_title[] = "�����Ѷ�ѡ��";
	PAGE2.PageText(WIDTH, 200, text2_title, 100); 
	
	char text2_button1[] = "��";
	char text2_button2[] = "����";
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
		//��ģʽ 
			
		if (MouseJug(WIDTH / 2, 500, 250, 60, n)){
			if (n.message == WM_LBUTTONDOWN){
				PAGE2.PageRefresh();
				nowindex = 1;
				difficulty = false;
			}
		}
		//����ģʽ 
			
		if (MouseJug(950, 650, 200, 50, n)){
			if (n.message == WM_LBUTTONDOWN){
				PAGE2.PageRefresh();
				nowindex = 0;
			}
		}
		//������ҳ 
	
		
	if (nowindex != 2) break;
	}
	
}

