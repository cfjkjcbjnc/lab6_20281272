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
*�������ƣ�checkFileType
* �������ܣ�����ļ�����
* ���������char* �ļ���
* ����ֵ�� char ��Ϊ�ı��ļ�����'t',��Ϊ�������ļ�����'d',�����󷵻�0
*/
char checkFileType(char* filename)
{
	char*p=strrchr(filename,'.');
	if (p == NULL) {
		printf("�ļ���ȱ�ٺ�׺\n");
		return 0;
	}
	else if (!strcmp(p, ".txt")) {
		return 't';
	}
	else if (!strcmp(p, ".dat")) {
		return 'd';
	}
	else {
		printf("�ļ�����׺����\n");
		return 0;
	}
}
/*
* �������ƣ�loadTo2DArray
* �������ܣ������ݱ��浽��ά������
* ���������char* filename �ļ���
* ����ֵ�� ��
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
			printf("��ȡ���ݳɹ�\n");
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
			printf("���ݶ�ȡ�ɹ�\n");
			fclose(fp);
		}
		else {
			printf("�ļ���ʽ����\n");
		}
	}
	else {
		printf("�ļ�������\n");
		nCount_array2D = 0;
	}
}
/*
* �������ƣ�loadToStructArray
* �������ܣ������ݱ��浽�ṹ��������
* ���������char* filename �ļ���
* ����ֵ�� ��
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
				printf("�ļ���ʧ��\n");
				return;
			}
			else{
				fscanf_s(fp, "%d", &nCount_StructArray);
				StructArray = (DATAITEM*)malloc(sizeof(DataItem)*nCount_StructArray);
				for (i = 0; i < nCount_StructArray; i++) {
					fscanf_s(fp, "%d %d %d", &StructArray[i].item1, &StructArray[i].item2, &StructArray[i].item3);
				}
				printf("���ݶ�ȡ�ɹ�\n");
				fclose(fp);
			}
		}
		else if (format == 'd') {
			fopen_s(&fp, filename, "rb");
			if (fp == NULL) {
				printf("�ļ���ʧ��\n");
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
				printf("���ݶ�ȡ�ɹ�\n");
				fclose(fp);
			}
		}
		else {
			printf("�ļ���ʽ����\n");
		}
	}
	else {
		printf("�ļ�������\n");
		nCount_StructArray = 0;
	}
}
/*
* �������ƣ�loadToPointerArray
* �������ܣ������ݱ��浽ָ��������
* ���������char* filename �ļ���
* ����ֵ�� ��
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
				printf("�ļ���ʧ��\n");
				return;
			}
			else {
				fscanf_s(fp, "%d", &nCount_PointerArray);
				PointerArray = (DATAITEM**)malloc(sizeof(DataItem*) * nCount_PointerArray);
				for (i = 0; i < nCount_PointerArray; i++) {
					PointerArray[i] = (DATAITEM*)malloc(sizeof(DATAITEM));
					fscanf_s(fp, "%d %d %d", &PointerArray[i]->item1, &PointerArray[i]->item2, &PointerArray[i]->item3);
				}
				printf("���ݶ�ȡ�ɹ�\n");
				fclose(fp);
			}
		}
		else if (format == 'd') {
			fopen_s(&fp, filename, "rb");
			if (fp == NULL) {
				printf("�ļ���ʧ��\n");
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
				printf("���ݶ�ȡ�ɹ�\n");
				fclose(fp);
			}
		}
		else {
			printf("�ļ���ʽ����\n");
		}
	}
	else {
		printf("�ļ�������\n");
		nCount_PointerArray = 0;
	}
}
/*
* �������ƣ�loadTolink
* �������ܣ������ݱ��浽������
* ���������char* filename �ļ���
* ����ֵ�� ��
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
				printf("�ļ���ʧ��\n");
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
				printf("���ݶ�ȡ�ɹ�\n");
				fclose(fp);
			}
		}
		else if (format == 'd') {
			fopen_s(&fp, filename, "rb");
			if (fp == NULL) {
				printf("�ļ���ʧ��\n");
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
				printf("���ݶ�ȡ�ɹ�\n");
				fclose(fp);
			}
		}
		else {
			printf("�ļ���ʽ����\n");
		}
	}
	else {
		printf("�ļ�������\n");
		nCount_link = 0;
	}
}
