#ifndef HEADERFILE
#define HEADERFILE

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <wingdi.h>
#include <windows.h>
#include <Gdiplus.h>
#include <fstream> 
#include <time.h>
#include <vector>
#include <string>
#include <io.h>


const int WIDTH = 1080;
const int HEIGHT = 720;
const int yTITLE = 200;

extern bool identity;	//��� trueΪ���壬false���� 
extern bool difficulty; //�Ѷ� trueΪ�򵥣�falseΪ���� 
extern bool error;
extern int nowindex;
extern int c[16][16];// 2Ϊ�գ� 0Ϊ�ڣ� 1Ϊ�� 
//extern int weight[16][16];
extern char gamereplay[30] ;

extern std::string GET_LOCAL_FILE_COMM;
extern std::string ECHO_TO_TMP;
extern std::string DELETE_TMP;
extern std::string DELETE_LOCAL_FILE_COMM;
#endif

