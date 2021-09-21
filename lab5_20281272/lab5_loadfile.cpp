#include "lab5_loadfile.h"
#include"stdafx.h"
#include"data.h"
#define R_OK 4
#define W_OK 2
#define X_OK 1
#define F_OK 0
DATAITEM* StructArray;
DATAITEM** PointerArray;
int** array2D;
link* head=NULL;
int nCount_array2D;
int nCount_StructArray;
int nCount_PointerArray;
int nCount_link;
link* end = head;
/*
*函数名称：checkFileType
* 函数功能：检查文件类型
* 输入参数：char* 文件名
* 返回值： char 若为文本文件返回't',若为二进制文件返回'd',若错误返回0
*/
char checkFileType(char* filename)
{
	char*p=strrchr(filename,'.');
	if (p == NULL) {
		printf("文件名缺少后缀\n");
		return 0;
	}
	else if (!strcmp(p, ".txt")) {
		return 't';
	}
	else if (!strcmp(p, ".dat")) {
		return 'd';
	}
	else {
		printf("文件名后缀错误\n");
		return 0;
	}
}
/*
* 函数名称：loadTo2DArray
* 函数功能：将数据保存到二维数组中
* 输入参数：char* filename 文件名
* 返回值： 无
*/
void loadTo2DArray(char* filename)
{
	FILE* fp = NULL;
	char format = checkFileType(filename);
	int i;
	if (!_access(filename, 0)) {
		if (format == 't') {
			fopen_s(&fp, filename, "r");
			fscanf_s(fp, "%d", &nCount_array2D);
			array2D = (int**)malloc(sizeof(int*) * nCount_array2D);
			for (i = 0; i < nCount_array2D; i++) {
				array2D[i] = (int*)malloc(sizeof(int) * 3);
				fscanf_s(fp, "%d %d %d", &array2D[i][0], &array2D[i][1], &array2D[i][2]);
			}
			printf("读取数据成功\n");
			fclose(fp);
		}
		else if (format == 'd') {
			fopen_s(&fp, filename, "rb");
			fread(&nCount_array2D, sizeof(int), 1, fp);
			array2D = (int**)malloc(sizeof(int*) * nCount_array2D);
			for (i = 0; i < nCount_array2D; i++) {
				array2D[i] = (int*)malloc(sizeof(int) * 3);
				fread(array2D[i], sizeof(int), 3, fp);
			}
			printf("数据读取成功\n");
			fclose(fp);
		}
		else {
			printf("文件格式错误\n");
		}
	}
	else {
		printf("文件不存在\n");
		nCount_array2D = 0;
	}
}
/*
* 函数名称：loadToStructArray
* 函数功能：将数据保存到结构体数组中
* 输入参数：char* filename 文件名
* 返回值： 无
*/
void loadToStructArray(char* filename)
{
	FILE* fp = NULL;
	int i;
	char format = checkFileType(filename);
	if (!_access(filename, 0)) {
		if (format == 't') {
			fopen_s(&fp, filename, "r");
			if (fp == NULL) {
				printf("文件打开失败\n");
				return;
			}
			else{
				fscanf_s(fp, "%d", &nCount_StructArray);
				StructArray = (DATAITEM*)malloc(sizeof(DataItem)*nCount_StructArray);
				for (i = 0; i < nCount_StructArray; i++) {
					fscanf_s(fp, "%d %d %d", &StructArray[i].item1, &StructArray[i].item2, &StructArray[i].item3);
				}
				printf("数据读取成功\n");
				fclose(fp);
			}
		}
		else if (format == 'd') {
			fopen_s(&fp, filename, "rb");
			if (fp == NULL) {
				printf("文件打开失败\n");
				return;
			}
			else {
				fread(&nCount_StructArray, sizeof(int), 1, fp);
				StructArray = (DATAITEM*)malloc(sizeof(DATAITEM) * nCount_StructArray);
				for (i = 0; i < nCount_StructArray; i++) {
					fread(&StructArray[i].item1, sizeof(int), 1, fp);
					fread(&StructArray[i].item2, sizeof(int), 1, fp);
					fread(&StructArray[i].item3, sizeof(int), 1, fp);
				}
				printf("数据读取成功\n");
				fclose(fp);
			}
		}
		else {
			printf("文件格式错误\n");
		}
	}
	else {
		printf("文件不存在\n");
		nCount_StructArray = 0;
	}
}
/*
* 函数名称：loadToPointerArray
* 函数功能：将数据保存到指针数组中
* 输入参数：char* filename 文件名
* 返回值： 无
*/
void loadToPointerArray(char* filename)
{
	FILE* fp = NULL;
	int i;
	char format = checkFileType(filename);
	if (!_access(filename, 0)) {
		if (format == 't') {
			fopen_s(&fp, filename, "r");
			if (fp == NULL) {
				printf("文件打开失败\n");
				return;
			}
			else {
				fscanf_s(fp, "%d", &nCount_PointerArray);
				PointerArray = (DATAITEM**)malloc(sizeof(DataItem*) * nCount_PointerArray);
				for (i = 0; i < nCount_PointerArray; i++) {
					PointerArray[i] = (DATAITEM*)malloc(sizeof(DATAITEM));
					fscanf_s(fp, "%d %d %d", &PointerArray[i]->item1, &PointerArray[i]->item2, &PointerArray[i]->item3);
				}
				printf("数据读取成功\n");
				fclose(fp);
			}
		}
		else if (format == 'd') {
			fopen_s(&fp, filename, "rb");
			if (fp == NULL) {
				printf("文件打开失败\n");
				return;
			}
			else {
				fread(&nCount_PointerArray, sizeof(int), 1, fp);
				PointerArray = (DATAITEM**)malloc(sizeof(DataItem*) * nCount_PointerArray);
				for (i = 0; i < nCount_PointerArray; i++) {
					PointerArray[i] = (DATAITEM*)malloc(sizeof(DATAITEM));
					fread(&PointerArray[i]->item1, sizeof(int), 1, fp);
					fread(&PointerArray[i]->item2, sizeof(int), 1, fp);
					fread(&PointerArray[i]->item3, sizeof(int), 1, fp);
				}
				printf("数据读取成功\n");
				fclose(fp);
			}
		}
		else {
			printf("文件格式错误\n");
		}
	}
	else {
		printf("文件不存在\n");
		nCount_PointerArray = 0;
	}
}
/*
* 函数名称：loadTolink
* 函数功能：将数据保存到链表中
* 输入参数：char* filename 文件名
* 返回值： 无
*/
void loadTolink(char* filename)
{
	link* p=NULL, * end=head;
	FILE* fp = NULL;
	int i;
	char format = checkFileType(filename);
	if (!_access(filename, 0)) {
		if (format == 't') {
			fopen_s(&fp, filename, "r");
			if (fp == NULL) {
				printf("文件打开失败\n");
				return;
			}
			else {
				fscanf_s(fp, "%d", &nCount_link);
				for (i = 0; i < nCount_link; i++) {
					p = (link*)malloc(sizeof(link));
					fscanf_s(fp, "%d %d %d", &p->item1, &p->item2, &p->item3);
					p->nextNode = NULL;
					if (head == NULL) {
						head = p;
						end = p;
					}
					else {
						end->nextNode = p;
						end = p;
					}
				}
				printf("数据读取成功\n");
				fclose(fp);
			}
		}
		else if (format == 'd') {
			fopen_s(&fp, filename, "rb");
			if (fp == NULL) {
				printf("文件打开失败\n");
				return;
			}
			else {
				fread(&nCount_link, sizeof(int), 1, fp);
				for (i = 0; i < nCount_link; i++) {
					p = (link*)malloc(sizeof(link));
					p->nextNode = NULL;
					fread(&p->item1, sizeof(int), 1, fp);
					fread(&p->item2, sizeof(int), 1, fp);
					fread(&p->item3, sizeof(int), 1, fp);
					if (head == NULL) {
						head = p;
						end = p;
					}
					else {
						end->nextNode = p;
						end = p;
					}
				}
				printf("数据读取成功\n");
				fclose(fp);
			}
		}
		else {
			printf("文件格式错误\n");
		}
	}
	else {
		printf("文件不存在\n");
		nCount_link = 0;
	}
}
