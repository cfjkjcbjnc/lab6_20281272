#include "lab5_conf.h"
#include"data.h"
#include"stdafx.h"
#include"lab5_view.h"
#define R_OK 4
#define W_OK 2
#define X_OK 1
#define F_OK 0
CONF data1;
int sys_mode;
int last_slash=-1;
char Name[1000];
/*
* 函数名称：sysCheck
* 函数功能：检查文件是否齐全
* 输入参数：无
* 返回值： int 若齐全返回1,不齐全返回0
*/
int sysCheck()
{
    FILE* fp = NULL;
    if (!_access("lab4.exe", 0) && !_access("conf.ini", 0) && !_access("lab5.ini", 0)) {
        fopen_s(&fp, "conf.ini", "r");
        fgets(data1.filesavepath, 2000, fp);
        fgets(data1.filename, 2000, fp);
        data1.filesavepath[strlen(data1.filesavepath) - 1] = '\0';
        data1.filename[strlen(data1.filename) - 1] = '\0';
        fscanf_s(fp, "%d %d %d %d %d %d", &data1.maxvalue1, &data1.minvalue1, &data1.maxvalue2, &data1.minvalue2, &data1.recordcount1, &data1.recordcount2);
        fclose(fp);
        fopen_s(&fp, "lab5.ini", "r");
        fscanf_s(fp, "%d", &sys_mode);
		if (sys_mode != 1 && sys_mode != 0) {
			printf("工作模式错误,将调整为自动模式\n");
			sys_mode = 1;
		}
        fclose(fp);
        return 1;
    }
    else {
        printf("缺少初始化文件\n");
        return 0;
    }
}
/*
*函数名称：modifyconf
* 函数功能：修改配置信息文件
* 输入参数：无
* 返回值： 无
*/
void modifyconf()
{
	int number;
	char c;
	FILE* fp = NULL;
	while (1) {
		showCONF();
		if (scanf_s("%d", &number) == 0) {
			printf("输入非法字符,请重新输入.\n");
			c = getchar();
		}
		else {
			c = getchar();
			switch (number)
			{
			case 1:
				printf("请输入完整的文件名参数(包含路径和文件名)\n");
				while (1) {
					gets_s(Name);
					if (checkName(Name)) {
						separate(Name, data1.filesavepath, data1.filename);
						break;
					}
					else {
						printf("输入参数不合法,请重新输入\n");
					}
				}
				break;
			case 2:
				printf("请输入完整的文件名参数(包含路径和文件名)\n");
				while (1) {
					gets_s(Name);
					if (checkName(Name)) {
						separate(Name, data1.filesavepath, data1.filename);
						break;
					}
					else {
						printf("输入参数不合法,请重新输入\n");
					}
				}
				break;
			case 3:
				printf("请输入第一、二个元素最大值(要大于最小值)\n");
				while (1) {
					if (scanf_s("%d", &data1.maxvalue1) == 0) {
						printf("输入非法字符,请重新输入\n");
						c = getchar();
					}
					else if (data1.maxvalue1 < data1.minvalue1) {
						printf("最大值大于最小值,请重新输入\n");
					}
					else break;
				}
				break;
			case 4:
				printf("请输入第一、二个元素最小值(要小于最大值)\n");
				while (1) {
					if (scanf_s("%d", &data1.minvalue1) == 0) {
						printf("输入非法字符,请重新输入\n");
						c = getchar();
					}
					else if (data1.maxvalue1 < data1.minvalue1) {
						printf("最大值大于最小值,请重新输入\n");
					}
					else break;
				}
				break;
			case 5:
				printf("请输入第三个元素最大值(要大于最小值)\n");
				while (1) {
					if (scanf_s("%d", &data1.maxvalue2) == 0) {
						printf("输入非法字符,请重新输入\n");
						c = getchar();
					}
					else if (data1.maxvalue2 < data1.minvalue2) {
						printf("最大值大于最小值,请重新输入\n");
					}
					else break;
				}
				break;
			case 6:
				printf("请输入第三个元素最小值(要小于最大值)\n");
				while (1) {
					if (scanf_s("%d", &data1.minvalue2) == 0) {
						printf("输入非法字符,请重新输入\n");
						c = getchar();
					}
					else if (data1.maxvalue2 < data1.minvalue2) {
						printf("最大值大于最小值,请重新输入\n");
					}
					else break;
				}
				break;
			case 7:
				printf("请输入记录条数最大值(要大于最小值)\n");
				while (1) {
					if (scanf_s("%d", &data1.recordcount1) == 0) {
						printf("输入非法字符,请重新输入\n");
						c = getchar();
					}
					else if (data1.recordcount1 < data1.recordcount2) {
						printf("最大值大于最小值,请重新输入\n");
					}
					else break;
				}
				break;
			case 8:
				printf("请输入记录条数最小值(要小于最大值)\n");
				while (1) {
					if (scanf_s("%d", &data1.recordcount2) == 0) {
						printf("输入非法字符,请重新输入\n");
						c = getchar();
					}
					else if (data1.recordcount1 < data1.recordcount2) {
						printf("最大值大于最小值,请重新输入\n");
					}
					else break;
				}
				break;
			case 9:
				printf("请输入工作模式(1为自动模式,0为交互模式)\n");
				while (1) {
					if (scanf_s("%d", &sys_mode) == 0) {
						printf("输入非法字符\n");
						c = getchar();
					}
					else if (sys_mode == 0 || sys_mode == 1) {
						break;
					}
					else {
						printf("输入工作模式不合法\n");
					}
				}
				break;
			case 0:
				fopen_s(&fp, "conf.ini", "w");
				fprintf(fp, "%s\n%s\n", data1.filesavepath, data1.filename);
				fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d", data1.maxvalue1, data1.minvalue1, data1.maxvalue2, data1.minvalue2, data1.recordcount1, data1.recordcount2);
				fclose(fp);
				fopen_s(&fp, "lab5.ini", "w");
				fprintf(fp, "%d", sys_mode);
				fclose(fp);
				break;
			default:
				printf("输入非法字符,请重新输入.\n");
				break;
			}
		}
		if (number == 0) break;
	}
}
/*
* 函数名称：checkName
* 函数功能：检查文件名参数是否合法
* 输入参数：char* name 文件名参数
* 返回值： int 合法返回1,不合法返回0
*/
int checkName(char* name)
{
	if (name == NULL) return 0;
	int n = strlen(name);
	if (n < 4) return 0;
	int count1 = 0;   // 记录'/'和'\'的个数
	int flag = 0;    //记录':'的个数
	int i = 0;
	for (i = 0; name[i] != '\0'; i++)
	{
		if (name[i] == '/' || name[i] == '\\')
		{
			last_slash = i;
			count1++;
		}
		if (last_slash == 0) return 0;
		if (name[i] == ':') flag++;
		if (flag > 1) return 0;
		if (name[i] == '*' || name[i] == '?' || name[i] == '\"' || name[i] == '>' || name[i] == '<' || name[i] == '|') return 0;
	}
	if (name[n - 1] != 't' || name[n - 2] != 'x' || name[n - 3] != 't' || name[n - 4] != '.')
	{
		if (name[n - 1] != 't' || name[n - 2] != 'a' || name[n - 3] != 'd' || name[n - 4] != '.')
			return 0;
	}           //结尾不是.txt或.dat返回0
	if (flag == 0) return 1; //用户输入的是相对路径
	else          //用户输入的是绝对路径
	{
		if (count1 == 0) return 0;
		else return 1;
	}
}
/*
* 函数名称：separate
* 函数功能：将文件名参数拆分
* 输入参数：char* name 文件名参数,char* path 目录,char* filename文件名
* 返回值： 无
*/
void separate(char* name, char* path, char* filename)
{
	char* c;
	int len = strlen(name);
	int i, j = -1;
	if (last_slash != -1)
	{
		for (i = 0; i < len; i++) {
			if (name[i] == '\\' || name[i] == '/') j = i;
		}
		c = name + j + 1;
		strncpy_s(path, 1000, name, j + 1);
		strcpy_s(filename, 1000, c);
	}
	else
	{
		strcpy_s(filename, 1000, name);
	}
}
