#include "lab5_call.h"
#include"stdafx.h"
/*
* �������ƣ�callLab4
* �������ܣ�����������lab4.exe
* ���������char* number ��¼����,char* filename �ļ���,char format �ļ���ʽ
* ����ֵ�� ��
*/	
void callLab4(const char* number, char* filename, char format)
{
	char str[1000];
	sprintf_s(str, "lab4.exe %s %s %c", number, filename, format);
	system(str);
}
