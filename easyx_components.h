#ifndef EASYX_COMPONENTS
#define EASYX_COMPONENTS
#include "headerfile.h"

static bool MouseJug(int _x, int _y, int w, int h, ExMessage m);
static void wPieceDraw(int x, int y);
static void bPieceDraw(int x, int y);
static void easyAIcalculate(bool id, int &nx, int &ny, int count);
static void advancedAIcalculate(bool id, int &nx, int &ny, int count);
static void AIScanfAffect(bool id, int x, int y, int (&sum)[8][4], bool (&d)[8][4]);
static void AIScanfDefence(bool id, int x, int y, int (&sum)[8][4], bool (&d)[8][4]);
static void AIvoidscore(int x, int y, int (&sum)[8][4], bool (&d)[8][4], int (&weight)[16][16]);
static void AIvoidscoreEasy(int x, int y, int (&sum)[8][4], bool (&d)[8][4], int (&weight)[16][16]);

class Button{
	public:
		
		void ButtonCreate(int _x, int _y, int w, int h, char text[]){
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(192, 192, 192));
			fillroundrect(_x - w / 2, _y - h / 2, _x + w / 2, _y + h / 2, 10, 10);
			settextstyle(40, 0, "华文仿宋");
			settextcolor(WHITE);
			int tx = _x - w / 2 + (w - textwidth(text)) / 2;
			int ty = _y - h / 2 + (h - textheight(text)) / 2;
			outtextxy(tx, ty, text);
		}
		//创建普通按钮 
		
		void Buttonhomepage(int _x, int _y, int w, int h){
			setfillcolor(RGB(192, 192, 192));
			fillroundrect(_x - w / 2, _y - h / 2, _x + w / 2, _y + h / 2, 10, 10);
			settextstyle(40, 0, "华文仿宋");
			settextcolor(WHITE);
			char text[] = "回到首页";
			int tx = _x - w / 2 + (w - textwidth(text)) / 2;
			int ty = _y - h / 2 + (h - textheight(text)) / 2;
			outtextxy(tx, ty, text);
		}
		//创建返回首页按钮 
		
		void fileButtonCreate(int on, char dt[]){
			setbkmode(TRANSPARENT);
			if (on == 1){
				setfillcolor(RGB(255, 105, 180));
				fillroundrect(200, 220, 880, 270, 10, 10);
				settextstyle(40, 0, "黑体");
				settextcolor(BLACK);
				outtextxy(210, 225, dt);
			}
			else if (on == 2){
				setfillcolor(RGB(255, 105, 180));
				fillroundrect(200, 290, 880, 340, 10, 10);
				settextstyle(40, 0, "黑体");
				settextcolor(BLACK);
				outtextxy(210, 295, dt);
			}
			else if (on == 3){
				setfillcolor(RGB(255, 105, 180));
				fillroundrect(200, 360, 880, 410, 10, 10);
				settextstyle(40, 0, "黑体");
				settextcolor(BLACK);
				outtextxy(210, 365, dt);
			}
			else if (on == 4){
				setfillcolor(RGB(255, 105, 180));
				fillroundrect(200, 430, 880, 480, 10, 10);
				settextstyle(40, 0, "黑体");
				settextcolor(BLACK);
				outtextxy(210, 435, dt);
			}						
			else if(on == 5){
				setfillcolor(RGB(255, 105, 180));
				fillroundrect(200, 500, 880, 550, 10, 10);
				settextstyle(40, 0, "黑体");
				settextcolor(BLACK);
				outtextxy(210, 505, dt);					
			}				
		}
		//创建文档选择按钮 
};

class Page{
	public:
		
		void PageRefresh(){
			setbkcolor(RGB(252, 237, 255));
			cleardevice();
		}
		//页面刷新 
		
		void PageText(int x, int y, char text[], int size){
			settextstyle(size, 0, "黑体");
			settextcolor(BLACK);
			int tx = (x - textwidth(text)) / 2;
			int ty = y - textheight(text) / 2;
			outtextxy(tx, ty, text);
		}
		//页面文字生成 
		
		void pageNoticeWin(bool i){
			char text1[] = "白棋胜利";
			char text2[] = "黑棋胜利";
			
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(255, 250, 205));
			setlinecolor(RGB(255, 222, 173));
			fillroundrect(340, 310, 740, 410, 10, 10);
			settextstyle(50, 0 , "黑体");
			settextcolor(BLACK);
			int tx = 540 - (textwidth(text1) / 2);
			int ty = 360 - (textheight(text1) / 2);
			if (i){
				outtextxy(tx, ty, text1);
			}
			else{
				outtextxy(tx, ty, text2);
			}
		}
		//页面游戏胜利提示 
		
		void filePageNoticeWin(bool i){
			char text1[] = "白棋胜利";
			char text2[] = "黑棋胜利";
			
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(255, 250, 205));
			setlinecolor(RGB(255, 222, 173));
			fillroundrect(680, 310, 1000, 410, 10, 10);
			settextstyle(50, 0 , "黑体");
			settextcolor(BLACK);
			int tx = 840 - (textwidth(text1) / 2);
			int ty = 360 - (textheight(text1) / 2);
			if (i){
				outtextxy(tx, ty, text1);
			}
			else{
				outtextxy(tx, ty, text2);
			}
		}
		//页面游戏胜利提示 
		
		void pageNoticeWarning(){
			char text1[] = "警告！违法操作";			
			
			setbkmode(TRANSPARENT);
			setfillcolor(BLACK);
			fillroundrect(80, 20, 1000, 90, 10, 10);
			settextstyle(40, 0, "黑体");
			settextcolor(RED);
			int tx = 540 - (textwidth(text1) / 2);
			int ty = 55 - (textheight(text1) / 2);
			outtextxy(tx, ty, text1);
		}
		//页面警告 
		
		void pageTextRefresh(int a, int b ,int c, int d){
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(252, 237, 255));
			solidrectangle(a, b, c, d);
		}
		//页面文字内容刷新 
		
};

class Chessboard{
	public :
		void ChessboardDraw(){
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(232, 190, 97));
			fillroundrect(100, 110, 590, 600, 10, 10);
			
			setlinecolor(BLACK);
			for (int i = 0; i < 16; i ++){
				line(120 + i * 30, 130, 120 + i * 30, 580);
				line(120, 130 + i * 30, 570, 130 + i * 30);
				
				settextstyle(20, 0, "Consolas");
				settextcolor(BLACK);
				char number;
				if(i <= 9){
					char number = i + 48;
					outtextxy(117 + i * 30, 110, number);
					outtextxy(105, 120 + i * 30, number);
				}
				else{
					char number = i + 55;
					outtextxy(117 + i * 30, 110, number);
					outtextxy(105, 120 + i * 30, number);
				}
			}			
		}
		//棋盘生成 
		
		void wPieceDraw(int x, int y){
			setbkmode(TRANSPARENT);
			setfillcolor(WHITE);
			setlinecolor(BLACK);
			fillcircle(x, y ,8);
		}
		//白子生成 
		
		void bPieceDraw(int x, int y){
			setbkmode(TRANSPARENT);
			setfillcolor(BLACK);
			setlinecolor(BLACK);
			fillcircle(x, y ,8);
		}
		//黑子生成 
		
		void boardClear(){
			for (int i = 0; i < 16; i++){
				for (int j = 0; j < 16; j ++){
					c[i][j] = 2;
				}
			}
		}
		//清空棋盘 
		
};

class Game{
	public :
		int nx = 0, ny = 0;
		int lx = 0, ly = 0;
		int t = 0;
			
		void checkFall(bool n, bool &fl){
			ExMessage p;
			while (true){
				p = getmessage(EX_MOUSE);
					if (p.message == WM_LBUTTONDOWN){			
						for (int i = 0; i < 16; i++){
							for (int j = 0; j < 16; j++){															
								if (MouseJug(120 + i * 30 , 130 + j * 30 , 30 , 30, p)){
									if (c[i][j] != 0 && c[i][j] != 1){											
										c[i][j] = n;
										lx = nx;
										ly = ny;
										nx = i;
										ny = j;
										t = 1;											
										break;											
									}
								}
								if (MouseJug(900, 650, 200, 50, p)){
									nowindex = 0;
									t = 1;
									break;
								}
								if (MouseJug(540, 650, 200, 50, p)){
									fl = 1;
									t = 1;
									break;
								}
							}
							if (t == 1) break;	
						}
					}
					if(t == 1){
						t = 0;
						break;
					}
			}						
		}
		//落子检测 		
		
		void Fall(){
			if (c[nx][ny] == 0){
				bPieceDraw(120 + nx * 30, 130 + ny * 30);
			}
			
			if (c[nx][ny] == 1){
				wPieceDraw(120 + nx * 30, 130 + ny * 30);
			}
		}
		//落子打印 
		
		void lastNotice(int c, bool id){
			
			if (c == 1 && id == 1){
				bPieceDraw(120 + lx * 30, 130 + ly * 30);
			}
			
			if (c != 1){
				if (id){
					bPieceDraw(120 + lx * 30, 130 + ly * 30);
				}
				else {
					wPieceDraw(120 + lx * 30, 130 + ly * 30);
				}
			}
			setbkmode(TRANSPARENT);
			setfillcolor(RED);
			fillcircle(120 + nx * 30, 130 + ny * 30, 3);
		}
		//上次落子位置提示 
		
		bool check(int (*c)[16]){
	
			
			for (int i = 0; i <= 11; i++){
				for (int j = 0; j<= 11; j++){
					if ((c[i][j] == 0 && c[i + 1][j] == 0 && c[i + 2][j] == 0 && c[i + 3][j] == 0 && c[i + 4][j] == 0) ||
					(c[i][j] == 1 && c[i + 1][j] == 1 && c[i + 2][j] == 1 && c[i + 3][j] == 1 && c[i + 4][j] == 1) ||
					(c[i][j] == 0 && c[i][j + 1] == 0 && c[i][j + 2] == 0 && c[i][j + 3] == 0 && c[i][j + 4] == 0) ||	
					(c[i][j] == 1 && c[i][j + 1] == 1 && c[i][j + 2] == 1 && c[i][j + 3] == 1 && c[i][j + 4] == 1) ||
					(c[i][j] == 0 && c[i + 1][j + 1] == 0 && c[i + 2][j + 2] == 0 && c[i + 3][j + 3] == 0 && c[i + 4][j + 4] == 0) ||
					(c[i][j] == 1 && c[i + 1][j + 1] == 1 && c[i + 2][j + 2] == 1 && c[i + 3][j + 3] == 1 && c[i + 4][j + 4] == 1)) {
						return 1;
					}																
				}
			
					
				for (int j = 16; j >= 4; j--){
					if ((c[i][j] == 0 && c[i + 1][j - 1] == 0 && c[i + 2][j - 2] == 0 && c[i + 3][j - 3] == 0 && c [i + 4][j - 4] == 0) ||
					(c[i][j] == 1 && c[i + 1][j - 1] == 1 && c[i + 2][j - 2] == 1 && c[i + 3][j - 3] == 1 && c [i + 4][j - 4] == 1) 
					){
						return 1;
					}
				}
			}					
			return 0;
		}
		//游戏胜利检测 
		
		void easyAI(bool id, int count){
			lx = nx;
			ly = ny;
			easyAIcalculate(id, nx, ny, count);
		}
		//简单人机
		
		void advancedAI(bool id, int count){
			lx = nx;
			ly = ny;
			advancedAIcalculate(id, nx, ny, count);
		} 
		//困难人机 
};

static bool MouseJug(int _x, int _y, int w, int h, ExMessage m){
	if (m.x >= _x - w / 2 && m.x <= _x + w / 2 && m.y >= _y - h / 2 && m.y <= _y + h / 2){
	return true;
	}
	else return false;
}
//按钮对应鼠标位置判断 

static void wPieceDraw(int x, int y){
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	fillcircle(x, y ,8);
}
//白子打印 
		
static void bPieceDraw(int x, int y){
	setbkmode(TRANSPARENT);
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	fillcircle(x, y ,8);
}
//黑子打印 

static void easyAIcalculate(bool id, int &nx, int &ny, int count){
	int sum[8][4];
	bool d[8][4];
	int weight[16][16];
	int jx, jy, jw = 0;
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 4; j++){
			sum[i][j] = 0;
			d[i][j] = 0;
		}			
	}
	for(int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			weight[i][j] = 0;
		}
	}
	//初始化
	 
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			if (c[i][j] == 2){
				AIScanfAffect(id, i, j, sum, d);
				AIScanfDefence(id, i, j, sum, d);
				AIvoidscoreEasy(i, j, sum, d, weight);
			}
		}
	}
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			if (weight[i][j] > jw){
				jx = i;
				jy = j;
				jw = weight[i][j];
			
			}		
		}	
	}
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			std::cout << weight[j][i] << " \t";
		} 
		std::cout << std::endl;
	}
	if (jw == 0){
		jx = 8;
		jy = 8;
	}
	nx = jx;
	ny = jy;
	c[nx][ny] = (int) id;
	std::cout << jx << " " << jy << std::endl;
	//AI下棋 	
}
//简单人机评分表

static void advancedAIcalculate(bool id, int &nx, int &ny, int count){
	int sum[8][4];
	bool d[8][4];
	int weight[16][16];
	int jx, jy, jw = 0;
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 4; j++){
			sum[i][j] = 0;
			d[i][j] = 0;
		}
	}
	for(int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			weight[i][j] = 0;
		}
	}
	//初始化
	 
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			if (c[i][j] == 2){
				AIScanfAffect(id, i, j, sum, d);
				AIScanfDefence(id, i, j, sum, d);
				AIvoidscore(i, j, sum, d, weight);
			}
		}
	}
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			if (weight[i][j] > jw){
				jx = i;
				jy = j;
				jw = weight[i][j];
			
			}
			std::cout << weight[j][i] << " \t";
		}	
		std::cout << std::endl;
	}
	if (jw == 0){
		jx = 8;
		jy = 8;
	}
	nx = jx;
	ny = jy;
	c[nx][ny] = (int) id;
	std::cout << jx << " " << jy << std::endl;
	//AI下棋 
} 
//困难人机评分表 

static void AIScanfAffect(bool id, int x, int y, int (&sum)[8][4], bool (&d)[8][4]){
	int ide, ode;	
	if (id){
		ide = 1;
		ode = 0;
	}
	else {
		ide = 0;
		ode = 1;
	}
	
	if (y != 0){
		for (int i = y - 1; i >= ((y <= 5) ? 0 : (y - 5)); i--){
			if (c[x][i] == ide && d[0][0] == 0){
				sum[0][0]++;
				if (sum[0][1] < 5 + (i - y + 1)){
					sum[0][1] = 5 + (i - y + 1);				
				}
				if (i != ((y <= 5) ? 0 : (y - 5)) && c[x][i - 1] == 2){
					d[0][2] = 1;
				}
			}
			if (c[x][i] == ode){
				d[0][0] = 1;
			}
		}			
	}
	//上 
	
	if (y != 15){
		for (int i = y + 1; i <= ((y >= 10) ? 15 : (y + 5)); i++){
			if (c[x][i] == ide && d[1][0] == 0){
				sum[1][0]++;
				if (sum[1][1] < 5 - (i - y - 1)){
					sum[1][1] = 5 - (i - y - 1);			
				}
				if (i != ((y >= 10) ? 15 : (y + 5)) && c[x][i + 1] == 2){
					d[1][2] = 1;
				}
			}
			if (c[x][i] == ode){
				d[1][0] = 1;
			}
		}		
	}
	//下
	
	if (x != 0){
		for (int i = x - 1; i >= ((x <= 5) ? 0 : (x - 5)); i--){
			if (c[i][y] == ide && d[2][0] == 0){
				sum[2][0]++; 
				if (sum[2][1] < 5 + (i - x + 1)){
					sum[2][1] = 5 + (i - x + 1);			
				} 
				if (i != ((x <= 5) ? 0 : (x - 5)) && c[i - 1][y] == 2){
					d[2][2] = 1;
				}
			}
			if (c[i][y] == ode){
				d[2][0] == 1;
			}
		} 		
	}
	//左
	
	if (x != 15){
		for (int i = x + 1; i <= ((x >= 10) ? 15 : (x + 5)); i++){
			if (c[i][y] == ide && d[3][0] == 0){
				sum[3][0]++;
				if (sum[3][1] < 5 - (i - x + 1)){
					sum[3][1] = 5 - (i - x + 1);			
				}
				if (i != ((x >= 10) ? 15 : (x + 5)) && c[i + 1][y] == 2){
					d[3][2] = 1;
				}
			}
			if (c[i][y] == ode){
				d[3][0] = 1;
			}
		} 		
	}

	//右
				
	int k = 0;
	if (x != 15 && y != 0){
		for (int i = x + 1; i <= ((x >= 10) ? 15 : (x + 5)); i++){
			k++; 
			if (y - i + x < 0) break;
			if (c[i][y - i + x] == ide && d[4][0] == 0){
				sum[4][0]++;
				if (sum[4][1] < 5 - ( i - x - 1)){
					sum[4][1] = 5 - (i - x - 1);			
				}
				if (i != ((x >= 10) ? 15 : (x + 5)) && y - i + x != 0 && c[i + 1][y - i + x - 1] == 2){
					d[4][2] = 1;
				}
			}
			if (c[i][y - i + x] == ode){
				d[4][0] = 1;
			}	
		}		
	}
	//右上
	
	k = 0;
	if (x != 0 && y != 0){
		for (int i = x - 1; i >= ((x <= 5) ? 0 : (x - 5)); i--){
			k++;
			if (y + i - x < 0) break;
			if (c[i][y + i - x] == ide && d[5][0] == 0){
				sum[5][0]++;
				if (sum[5][1] < 5 + (i - x + 1)){
					sum[5][1] = 5 + (i - x + 1);		
				}
				if (i != ((x <= 5) ? 0 : (x - 5)) && y + i - x != 0 && c[i - 1][y + i - x - 1] == 2){
					d[5][2] = 1;
				}
			}
			if (c[i][y + i - x] == ode){
				d[5][0] = 1;
			}
		}		
	}
	//左上
	
	k = 0;
	if (x != 15 & y != 15){
		for (int i = x + 1; i <= ((x >= 10) ? 15 : (x + 5)); i++){
			k++;
			if (y + i - x > 15) break;
			if (c[i][y + i - x] == ide && d[6][0] == 0){
				sum[6][0]++;
				if (sum[6][1] < 5 - (i - x - 1)){
					sum[6][1] = 5 - (i - x - 1);			
				}
				if (i != ((x >= 10) ? 15 : (x + 5)) && y + i - x != 15 && c[i + 1][y + i - x + 1] == 2){
					d[6][2] = 1;
				}
			}
			if (c[i][y + i - x] == ode){
				d[6][0] = 1;
			}
		} 		
	}
	//右下 
	
	k = 0;
	if (x != 0 && y != 15){
		for (int i = x - 1; i >= ((x <= 5) ? 0 : (x - 5)); i--){
			k++;
			if (y - i + x > 15) break;
			if (c[i][y - i + x] == ide && d[7][0] == 0){
				sum[7][0]++;
				if (sum[7][1] < 5 + (i - x + 1)){
					sum[7][1] = 5 + (i - x + 1);			
				}
				if (i != ((x <= 5) ? 0 : (x - 5)) && y - i + x != 15 && c[i - 1][y - i + x + 1] == 2){
					d[7][2] = 1;
				}
			}
			if (c[i][y - i + x] == ode){
				d[7][0] = 1;
			}
		}		
	}
	//左下 
	
}
//扫描空白位置(进攻)

static void AIScanfDefence(bool id, int x, int y, int (&sum)[8][4], bool (&d)[8][4]){
	int ide, ode;	
	if (id){
		ide = 1;
		ode = 0;
	}
	else {
		ide = 0;
		ode = 1;
	}
	
	if (y != 0){
		for (int i = y - 1; i >= ((y <= 5) ? 0 : (y - 5)); i--){
			if (c[x][i] == ode && d[0][1] == 0){
				sum[0][2]++;
				if (sum[0][3] < 5 + (i - y + 1)){
					sum[0][3] = 5 + (i - y + 1);			
				}if (i != ((y <= 5) ? 0 : (y - 5)) && c[x][i - 1] == 2){
					d[0][3] = 1;
				}
			}
			if (c[x][i] == ide){
				d[1][0] = 1;
			}
		}	
	}

	//上 
	
	if (y != 15){
		for (int i = y + 1; i <= ((y >= 10) ? 15 : (y + 5)); i++){
			if (c[x][i] == ode && d[1][1] == 0){
				sum[1][2]++;
				if (sum[1][3] < 5 - (i - y - 1)){
					sum[1][3] = 5 - (i - y - 1);			
				}
				if (i != ((y >= 10) ? 15 : (y + 5)) && c[x][i + 1] == 2){
					d[1][3] = 1;
				}
			}
			if (c[x][i] == ide){
				d[1][1] = 1;
			}
		}		
	}

	//下
	
	if (x != 0){
		for (int i = x - 1; i >= ((x <= 5) ? 0 : (x - 5)); i--){
			if (c[i][y] == ode && d[2][1] == 0){
				sum[2][2]++; 
				if (sum[2][3] < 5 + (i - x + 1)){
					sum[2][3] = 5 + (i - x + 1);			
				} 
				if (i != ((x <= 5) ? 0 : (x - 5)) && c[i - 1][y] == 2){
					d[2][3] = 1;
				}
			}
			if (c[i][y] == ide){
				d[2][1] == 1;
			}
		}		
	}
 
	//左
	
	if (x != 15){
		for (int i = x + 1; i <= ((x >= 10) ? 15 : (x + 5)); i++){
			if (c[i][y] == ode && d[3][1] == 0){
				sum[3][2]++;
				if (sum[3][3] < 5 - (i - x + 1)){
					sum[3][3] = 5 - (i - x + 1);			
				}
				if (i != ((x >= 10) ? 15 : (x + 5)) && c[i + 1][y] == 2){
					d[3][3] = 1;
				} 
			}
			if (c[i][y] == ide){
				d[3][1] = 1;
			}
		} 		
	}

	//右
				
	int k = 0;
	if (x != 15 && y != 0){
		for (int i = x + 1; i <= ((x >= 10) ? 15 : (x + 5)); i++){
			k++; 
			if (y - i + x < 0) break;
			if (c[i][y - i + x] == ode && d[4][1] == 0){
				sum[4][2]++;
				if (sum[4][3] < 5 - (i - x  - 1)){
					sum[4][3] = 5 - (i - x - 1);			
				}
				if (i != ((x >= 10) ? 15 : (x + 5)) && y - i + x != 0 && c[i + 1][y - i + x - 1] == 2){
					d[4][3] = 1;
				}
			}
			if (c[i][y - i + x] == ide){
				d[4][1] = 1;
			}	
		} 		
	}

	//右上
	
	k = 0;
	if (x != 0 && y != 0){
		for (int i = x - 1; i >= ((x <= 5) ? 0 : (x - 5)); i--){
			k++;
			if (y + i - x < 0) break;
			if (c[i][y + i - x] == ode && d[5][1] == 0){
				sum[5][2]++;
				if (sum[5][3] < 5 + (i - x + 1)){
					sum[5][3] = 5 + (i - x + 1);			
				} 
				if (i != ((x <= 5) ? 0 : (x - 5)) && y + i - x != 0 && c[i - 1][y + i - x - 1] == 2){
					d[5][3] = 1;
				}
			}
			if (c[i][y + i - x] == ide){
				d[5][1] = 1;
			}
		}	
	}

	//左上
	
	k = 0;
	if (x != 15 && y != 15){
		for (int i = x + 1; i <= ((x >= 10) ? 15 : (x + 5)); i++){
			k++;
			if (y + i - x > 15) break;
			if (c[i][y + i - x] == ode && d[6][1] == 0){
				sum[6][2]++;
				if (sum[6][3] < 5 -(i - x - 1)){
					sum[6][3] = 5 - (i - x - 1);			
				}
				if (i != ((x >= 10) ? 15 : (x + 5)) && y + i - x != 15 && c[i + 1][y + i - x + 1] == 2){
					d[6][3] = 1;
				}
			}
			if (c[i][y + i - x] == ide){
				d[6][1] = 1;
			}
		} 	
	}

	//右下 
	
	k = 0;
	if (x != 0 && y != 15){
		for (int i = x - 1; i >= ((x <= 5) ? 0 : (x - 5)); i--){
			k++;
			if (y - i + x > 15) break;
			if (c[i][y - i + x] == ode && d[7][1] == 0){
				sum[7][2]++;
				if (sum[7][3] < 5 + (i - x + 1)){
					sum[7][3] = 5 + (i - x + 1);			
				}
				if (i != ((x <= 5) ? 0 : (x - 5)) && y - i + x != 15 && c[i - 1][y - i + x + 1] == 2){
					d[7][3] = 1;
				}
			}
			if (c[i][y - i + x] == ide){
				d[7][1] = 1;
			}
		}		
	}

	//左下 
}
//扫描空白位置(防守)  

static void AIvoidscore(int x, int y, int (&sum)[8][4], bool (&d)[8][4], int (&weight)[16][16]){
	for (int i = 0; i < 8; i++){
		if (sum[i][0] == 4 && sum[i][1] == 5){
			weight[x][y] += 200000;
			
			if (d[i][2]){
				weight[x][y] += 100000;
			}
		}
		//活四冲四 
		
		if (sum[i][2] == 4 && sum[i][3] == 5){
			weight[x][y] += 80000;
			
			if (d[i][3]){
				weight[x][y] += 100000;
			}
			else{
				weight[x][y] -= 80000;
			}
		}
		//对子活四冲四防守 
		
		if (sum[i][0] == 3 ){
			weight[x][y] += 500;
			if (sum[i][1] == 5){
				weight[x][y] += 10000;
				if (i > 3){
					weight[x][y] += 500;
				}
				
				if (d[i][2]){
					weight[x][y] += 10000;
				}
			}
			if (sum[i][1] == 4){
				weight[x][y] += 100;
				if (i > 3){
					weight[x][y] += 10;
				}
			}
		} 
		//活三冲三 
		
		if (sum[i][2] == 3){
			weight[x][y] += 800;
			if (sum[i][3] == 5){
				weight[x][y] += 16000;
				if (i > 3){
					weight[x][y] += 600;
				}
				
				if (!d[i][3]){
					weight[x][y] += 10000;
				}
				else {
					weight[x][y] -= 2000;
				}
			}
			if (sum[i][3] == 4){
				weight[x][y] += 500;
				if (i > 3){
					weight[x][y] += 10;
				}
			}
		} 
		//对子活三冲三防守
		 
		if (sum[i][0] == 2){
			weight[x][y] += 40;
			if (sum[i][1] == 5){
				weight[x][y] += 800;
				if (i > 3){
					weight[x][y] += 200;
				}
				
				if (d[i][2]){
					weight[x][y] += 500;
				}
				else{
					weight[x][y] -= 100;
				}
			}
			if (sum[i][1] == 4){
				weight[x][y] += 10;
				if (i > 3){
					weight[x][y] += 1;
				}
			} 
		}
		//活二冲二
		
		if (sum[i][2] == 2){
			weight[x][y] += 30;
			if (sum[i][3] == 5){
				weight[x][y] += 400;
				if (i > 3){
					weight[x][y] += 1;
				}
				
				if (d[i][3]){
					weight[x][y] += 50;
				}
				else{
					weight[x][y] -= 10;
				}
			}
			if (sum[i][3] == 4){
				weight[x][y] += 5;
				if (i > 3){
					weight[x][y] += 1;
				}
			} 
		}
		//对子活二冲二防守 
		
		if (sum[i][0] == 1){
			weight[x][y] += 5;
			if (sum[i][1] == 5){
				weight[x][y] += 5;
				if (i > 3){
					weight[x][y] += 5;
				} 
				
				if (!d[i][2]){
					weight[x][y] += 5;
				}
				else{
					weight[x][y] -= 3;
				}
			}
			if (sum[i][1] == 4){
				weight[x][y] += 1;
				if (i > 3){
					weight[x][y] += 1;
				}
			}
		}
		//活一
		
		if (sum[i][2] == 1){
			weight[x][y] += 4;
			if (sum[i][3] == 5){
				weight[x][y] += 4;
				if (i > 3){
					weight[x][y] += 4;
				} 
				
				if (d[i][3]){
					weight[x][y] += 2;
				}
				else {
					weight[x][y] -= 2 ;
				}
			}	
			if (sum[i][3] == 4){
				weight[x][y] += 1;
				if (i > 3){
					weight[x][y] += 1;
				}
			}
		}
		//对子活一 
		
		if (sum[i][0] == 0 || sum[i][2] == 0){
			weight[x][y] += 0;
		}
	}
	
	for (int i = 0; i < 8; i ++){
		for (int j = 0; j < 4; j++){
			sum[i][j] = 0;
		}
		for (int j = 0; j < 2; j++){
			d[i][j] = 0;
		}
	}
}
//AI评分表（困难人机）

static void AIvoidscoreEasy(int x, int y, int (&sum)[8][4], bool (&d)[8][4], int (&weight)[16][16]){
	for (int i = 0; i < 8; i++){
		if (sum[i][0] == 4 && sum[i][1] == 5){
			weight[x][y] += 100000;
			if (sum[i][1] == 5){
				weight[x][y] += 100000;
			}
		}
		//活四冲四 
		
		if (sum[i][2] == 4 && sum[i][3] == 5){
			weight[x][y] += 80000;
			if (sum[i][3] == 5){
				weight[x][y] += 80000;
			}
		}
		//对子活四冲四防守 
		
		if (sum[i][0] == 3){
			weight[x][y] += 5000;
			if (sum[i][1] == 5){
				weight[x][y] += 5000;
				if (i > 3){
					weight[x][y] += 5000;
				}
			}
			if (sum[i][1] == 4){
				weight[x][y] += 1000;
				if (i > 3){
					weight[x][y] += 1000;
				}
			}
		} 
		//活三冲三 
		
		if (sum[i][2] == 3){
			weight[x][y] += 800;
			if (sum[i][3] == 5){
				weight[x][y] += 800;
				if (i > 3){
					weight[x][y] += 600;
				}
			}
			if (sum[i][3] == 4){
				weight[x][y] += 200;
				if (i > 3){
					weight[x][y] += 100;
				}
			}
		} 
		//对子活三冲三防守
		 
		if (sum[i][0] == 2){
			weight[x][y] += 400;
			if (sum[i][1] == 5){
				weight[x][y] += 400;
				if (i > 3){
					weight[x][y] += 200;
				}
			}
			if (sum[i][1] == 4){
				weight[x][y] += 100;
				if (i > 3){
					weight[x][y] += 100;
				}
			} 
		}
		//活二冲二
		
		if (sum[i][2] == 2){
			weight[x][y] += 40;
			if (sum[i][3] == 5){
				weight[x][y] += 40;
				if (i > 3){
					weight[x][y] += 10;
				}
			}
			if (sum[i][3] == 4){
				weight[x][y] += 10;
				if (i > 3){
					weight[x][y] += 5;
				}
			} 
		}
		//对子活二冲二防守 
		
		if (sum[i][0] == 1){
			weight[x][y] += 5;
			if (sum[i][1] == 5){
				weight[x][y] += 5;
				if (i > 3){
					weight[x][y] += 5;
				} 
			}
			if (sum[i][1] == 4){
				weight[x][y] += 1;
				if (i > 3){
					weight[x][y] += 1;
				}
			}
		}
		//活一
		
		if (sum[i][2] == 1){
			weight[x][y] += 4;
			if (sum[i][3] == 5){
				weight[x][y] += 4;
				if (i > 3){
					weight[x][y] += 4;
				} 
			}
			if (sum[i][3] == 4){
				weight[x][y] += 1;
				if (i > 3){
					weight[x][y] += 1;
				}
			}
		}
		//对子活一 
		
		if (sum[i][0] == 0 || sum[i][2] == 0){
			weight[x][y] += 0;
		}
	}
	
	for (int i = 0; i < 8; i ++){
		for (int j = 0; j < 4; j++){
			sum[i][j] = 0;
		}
		for (int j = 0; j < 2; j++){
			d[i][j] = 0;
		}
	}
}
//AI评分表（简单人机）

#endif

