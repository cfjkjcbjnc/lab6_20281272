#include "lab5_call.h"
#include"stdafx.h"
/*
* 函数名称：callLab4
* 函数功能：将参数传给lab4.exe
* 输入参数：char* number 记录条数,char* filename 文件名,char format 文件格式
* 返回值： 无
*/	
void callLab4(const char* number, char* filename, char format)
{
	char str[1000];
	sprintf_s(str, "lab4.exe %s %s %c", number, filename, format);
	system(str);
}
