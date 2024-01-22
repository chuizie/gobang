#include "headerfile.h"

int nowindex = 0;
bool identity = 0;
bool difficulty = 0;
bool error = 0;
int c[16][16];
//int weight[16][16];
char gamereplay[] = {"\0"};

std::string GET_LOCAL_FILE_COMM = "cd saves && for /f \"delims=\" %a in (\'dir /b/a-d/oN *.*\') do echo %a";
std::string ECHO_TO_TMP = " >> _read_tmp";
std::string DELETE_TMP = "cd saves && del _read_tmp";
std::string DELETE_LOCAL_FILE_COMM = "cd saves && del \"";

