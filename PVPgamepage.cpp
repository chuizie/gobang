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
	char text4_1[] = "��ǰ������"; 
	char text4_2[] = {0, 0, 0};
	char text4_3[] = "��ǰ�ֵ���";
	char text4_4[] = "����Ծ�";
	char text4_5[] = "�����ʼ";
	char text4_6[] = "�ص���ҳ";
	char text4_7[] = "����";
	char text4_8[] = "����";
	char text4_9[] = "��Ч����";
	char text4_10[] = "�Ծֻطű���ɹ�";
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
	sprintf(name, "%d.%d.%d_%d��%02d.txt",1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min);
	string namep = "gamereplay\\" + (string)name;
	fp = fopen(namep.c_str(), "w+");
	fprintf(fp, "Nygaard_gobang_game\n");
	//���ݵ�ǰʱ�䴴�����ļ������¶Ծ� 
	
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
	//��Ϸ��ʼǰ����ѡ�� 

	while (1){			
		if (backHomeJuge){
			break;
		}
		//������ҳ����ת 
		
		if(!nowGameIdentity){
			gameCount ++;
		} 
		//��ǰ�����Ĵ��� 
		
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
		//ҳ����Ϣ��ʾ��ˢ�� 
 	
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
		//���Ӽ���ӡ�봢�� 


		if (nowindex == 0){
			backHomeJuge = 1;
			break;
		}
		//������ҳ����ת 
		
		if (game.check(c)){
			GamePage.pageNoticeWin(nowGameIdentity);
			if (nowGameIdentity){
				fprintf(fp, "����ʤ��");
			}
			else{
				fprintf(fp, "����ʤ��");
			}
			break;
		}
		//ʤ���жϼ���Ӧ�ļ����� 
		
		if (gameFileSaveJug != 1){
			if (nowGameIdentity == 0){
				nowGameIdentity = 1;
			}
			else{
				nowGameIdentity = 0;
			}
		}
		//���ת��	
		
		if (gameFileSaveJug == 1){
			gameFileSaveJug = 0;
			gameCount --;
		}		
	}
	//�Ծ���ѭ��	

		
	if (!backHomeJuge){
		while(1){
			m = getmessage(EX_MOUSE);
				if(m.message == WM_LBUTTONDOWN){
					if (MouseJug(900, 650, 200, 50, m)){
						backHomeJuge = 1;
						nowindex = 0;
						break;	
					}
					//������ҳ 
					else if (MouseJug(540, 650, 200, 50, m)){
						gameFileSave = 1;
						GamePage.PageText(600, 50, text4_10, 50);
						continue;
					}
					//����Ծ� 
				}
    		
		}	
	}
	//�Ծֽ�����ť�ж� 
	
	if (!gameFileSave){
		fclose(fp);
		delpathlss = name;
		delpath += delpathlss;
		system(delpath.c_str());
	}
	else{
		fclose(fp);
	}
	//�����������������Ծ������ļ�������ɾ���ļ� 

	
}

