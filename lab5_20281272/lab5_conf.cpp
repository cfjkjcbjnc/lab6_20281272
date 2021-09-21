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
* �������ƣ�sysCheck
* �������ܣ�����ļ��Ƿ���ȫ
* �����������
* ����ֵ�� int ����ȫ����1,����ȫ����0
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
			printf("����ģʽ����,������Ϊ�Զ�ģʽ\n");
			sys_mode = 1;
		}
        fclose(fp);
        return 1;
    }
    else {
        printf("ȱ�ٳ�ʼ���ļ�\n");
        return 0;
    }
}
/*
*�������ƣ�modifyconf
* �������ܣ��޸�������Ϣ�ļ�
* �����������
* ����ֵ�� ��
*/
void modifyconf()
{
	int number;
	char c;
	FILE* fp = NULL;
	while (1) {
		showCONF();
		if (scanf_s("%d", &number) == 0) {
			printf("����Ƿ��ַ�,����������.\n");
			c = getchar();
		}
		else {
			c = getchar();
			switch (number)
			{
			case 1:
				printf("�������������ļ�������(����·�����ļ���)\n");
				while (1) {
					gets_s(Name);
					if (checkName(Name)) {
						separate(Name, data1.filesavepath, data1.filename);
						break;
					}
					else {
						printf("����������Ϸ�,����������\n");
					}
				}
				break;
			case 2:
				printf("�������������ļ�������(����·�����ļ���)\n");
				while (1) {
					gets_s(Name);
					if (checkName(Name)) {
						separate(Name, data1.filesavepath, data1.filename);
						break;
					}
					else {
						printf("����������Ϸ�,����������\n");
					}
				}
				break;
			case 3:
				printf("�������һ������Ԫ�����ֵ(Ҫ������Сֵ)\n");
				while (1) {
					if (scanf_s("%d", &data1.maxvalue1) == 0) {
						printf("����Ƿ��ַ�,����������\n");
						c = getchar();
					}
					else if (data1.maxvalue1 < data1.minvalue1) {
						printf("���ֵ������Сֵ,����������\n");
					}
					else break;
				}
				break;
			case 4:
				printf("�������һ������Ԫ����Сֵ(ҪС�����ֵ)\n");
				while (1) {
					if (scanf_s("%d", &data1.minvalue1) == 0) {
						printf("����Ƿ��ַ�,����������\n");
						c = getchar();
					}
					else if (data1.maxvalue1 < data1.minvalue1) {
						printf("���ֵ������Сֵ,����������\n");
					}
					else break;
				}
				break;
			case 5:
				printf("�����������Ԫ�����ֵ(Ҫ������Сֵ)\n");
				while (1) {
					if (scanf_s("%d", &data1.maxvalue2) == 0) {
						printf("����Ƿ��ַ�,����������\n");
						c = getchar();
					}
					else if (data1.maxvalue2 < data1.minvalue2) {
						printf("���ֵ������Сֵ,����������\n");
					}
					else break;
				}
				break;
			case 6:
				printf("�����������Ԫ����Сֵ(ҪС�����ֵ)\n");
				while (1) {
					if (scanf_s("%d", &data1.minvalue2) == 0) {
						printf("����Ƿ��ַ�,����������\n");
						c = getchar();
					}
					else if (data1.maxvalue2 < data1.minvalue2) {
						printf("���ֵ������Сֵ,����������\n");
					}
					else break;
				}
				break;
			case 7:
				printf("�������¼�������ֵ(Ҫ������Сֵ)\n");
				while (1) {
					if (scanf_s("%d", &data1.recordcount1) == 0) {
						printf("����Ƿ��ַ�,����������\n");
						c = getchar();
					}
					else if (data1.recordcount1 < data1.recordcount2) {
						printf("���ֵ������Сֵ,����������\n");
					}
					else break;
				}
				break;
			case 8:
				printf("�������¼������Сֵ(ҪС�����ֵ)\n");
				while (1) {
					if (scanf_s("%d", &data1.recordcount2) == 0) {
						printf("����Ƿ��ַ�,����������\n");
						c = getchar();
					}
					else if (data1.recordcount1 < data1.recordcount2) {
						printf("���ֵ������Сֵ,����������\n");
					}
					else break;
				}
				break;
			case 9:
				printf("�����빤��ģʽ(1Ϊ�Զ�ģʽ,0Ϊ����ģʽ)\n");
				while (1) {
					if (scanf_s("%d", &sys_mode) == 0) {
						printf("����Ƿ��ַ�\n");
						c = getchar();
					}
					else if (sys_mode == 0 || sys_mode == 1) {
						break;
					}
					else {
						printf("���빤��ģʽ���Ϸ�\n");
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
				printf("����Ƿ��ַ�,����������.\n");
				break;
			}
		}
		if (number == 0) break;
	}
}
/*
* �������ƣ�checkName
* �������ܣ�����ļ��������Ƿ�Ϸ�
* ���������char* name �ļ�������
* ����ֵ�� int �Ϸ�����1,���Ϸ�����0
*/
int checkName(char* name)
{
	if (name == NULL) return 0;
	int n = strlen(name);
	if (n < 4) return 0;
	int count1 = 0;   // ��¼'/'��'\'�ĸ���
	int flag = 0;    //��¼':'�ĸ���
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
	}           //��β����.txt��.dat����0
	if (flag == 0) return 1; //�û�����������·��
	else          //�û�������Ǿ���·��
	{
		if (count1 == 0) return 0;
		else return 1;
	}
}
/*
* �������ƣ�separate
* �������ܣ����ļ����������
* ���������char* name �ļ�������,char* path Ŀ¼,char* filename�ļ���
* ����ֵ�� ��
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
