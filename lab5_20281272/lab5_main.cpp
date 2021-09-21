#include"stdafx.h"
#include"lab5_view.h"
#include"lab5_loadfile.h"
#include"lab5_conf.h"
#include"data.h"
#include"lab5_conf.h"
#include"lab5_call.h"
#include"lab5_main.h"
char _FILENAME[1000];
char _NUMBER[100];
/*
* �������ƣ�run
* �������ܣ�ʵ��ʵ����Ĺ���
* ���������int argc �����в�������,char* argv[] �����в���ֵ
* ����ֵ�� ��
*/
void run(int argc, char* argv[]) {
	srand(time(NULL));
	int number;
	char c;
	FILE* fp = NULL;
	char filename[1000];
	if (sysCheck()) {
		while (1) {
			//����ģʽ
			if (sys_mode == 0) {
				showMenu();
				if (scanf_s("%d", &number) == 0) {
					printf("����Ƿ��ַ�,����������.\n");
					c = getchar();
				}
				else {
					c = getchar();
					switch (number)
					{
					case 0:
						break;
					case 1:
						input();
						callLab4(_NUMBER, _FILENAME, 't');
						break;
					case 2:
						input();
						callLab4(_NUMBER, _FILENAME, 'd');
						break;
					case 3:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadTo2DArray(filename);
						show2DArray();
						break;
					case 4:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadToStructArray(filename);
						showStructArray();
						break;
					case 5:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadToPointerArray(filename);
						showPointerArray();
						break;
					case 6:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadTolink(filename);
						showLink();
						break;
					case 7:
						input();
						modifyextension(_FILENAME, "t");
						callLab4(_NUMBER, _FILENAME, 't');
						loadTo2DArray(_FILENAME);
						show2DArray();
						break;
					case 8:
						input();
						modifyextension(_FILENAME, "t");
						callLab4(_NUMBER, _FILENAME, 't');
						loadToStructArray(_FILENAME);
						showStructArray();
						break;
					case 9:
						input();
						modifyextension(_FILENAME, "t");
						callLab4(_NUMBER, _FILENAME, 't');
						loadToPointerArray(_FILENAME);
						showPointerArray();
						break;
					case 10:
						input();
						modifyextension(_FILENAME, "t");
						callLab4(_NUMBER, _FILENAME, 't');
						loadTolink(_FILENAME);
						showLink();
						break;
					case 11:
						input();
						modifyextension(_FILENAME, "d");
						callLab4(_NUMBER, _FILENAME, 'd');
						loadTo2DArray(_FILENAME);
						show2DArray();
						break;
					case 12:
						input();
						modifyextension(_FILENAME, "d");
						callLab4(_NUMBER, _FILENAME, 'd');
						loadToStructArray(_FILENAME);
						showStructArray();
						break;
					case 13:
						input();
						modifyextension(_FILENAME, "d");
						callLab4(_NUMBER, _FILENAME, 'd');
						loadToPointerArray(_FILENAME);
						showPointerArray();
						break;
					case 14:
						input();
						modifyextension(_FILENAME, "d");
						callLab4(_NUMBER, _FILENAME, 'd');
						loadTolink(_FILENAME);
						showLink();
						break;
					case 15:
						modifyconf();
						break;
					default:
						printf("����Ƿ��ַ�,����������.\n");
						break;
					}
				}
				system("pause");
				system("cls");
				if (number == 0) break;
			}
			//�Զ�ģʽ
			else {
				showMenu();
				if (scanf_s("%d", &number) == 0) {
					printf("����Ƿ��ַ�,����������.\n");
					c = getchar();
				}
				else {
					c = getchar();
					switch (number)
					{
					case 0:
						break;
					case 1:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						callLab4("r", filename, 't');
						break;
					case 2:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						callLab4("r", filename, 'd');
						break;
					case 3:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadTo2DArray(filename);
						show2DArray();
						break;
					case 4:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadToStructArray(filename);
						showStructArray();
						break;
					case 5:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadToPointerArray(filename);
						showPointerArray();
						break;
					case 6:
						printf("�������ļ�������\n");
						gets_s(filename);
						loadTolink(filename);
						showLink();
						break;
					case 7:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "t");
						callLab4("r", filename, 't');
						loadTo2DArray(filename);
						show2DArray();
						break;
					case 8:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "t");
						callLab4("r", filename, 't');
						loadToStructArray(filename);
						showStructArray();
						break;
					case 9:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "t");
						callLab4("r", filename, 't');
						loadToPointerArray(filename);
						showPointerArray();
						break;
					case 10:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "t");
						callLab4("r", filename, 't');
						loadTolink(filename);
						showLink();
						break;
					case 11:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "d");
						callLab4("r", filename, 'd');
						loadTo2DArray(filename);
						show2DArray();
						break;
					case 12:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "d");
						callLab4("r", filename, 'd');
						loadToStructArray(filename);
						showStructArray();
						break;
					case 13:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "d");
						callLab4("r", filename, 'd');
						loadToPointerArray(filename);
						showPointerArray();
						break;
					case 14:
						sprintf_s(filename, "%s%s", data1.filesavepath, data1.filename);
						modifyextension(filename, "d");
						callLab4("r", filename, 'd');
						loadTolink(filename);
						showLink();
						break;
					case 15:
						modifyconf();
						break;
					default:
						printf("����Ƿ��ַ�,����������.\n");
						break;
					}
				}
				system("pause");
				system("cls");
				if (number == 0) break;
			}
		}
	}
	else {
		printf("ȱʧ�ļ�\n");
		return;
	}
}
/*
* �������ƣ�input
* �������ܣ�����ģʽ���û�������
* �����������
* ����ֵ�� ��
*/
void input() {
	printf("�������¼����,����'r'�������\n");
	gets_s(_NUMBER);
	printf("�������ļ�������\n");
	while (1) {
		gets_s(_FILENAME);
		if (checkName(_FILENAME)) break;
		else printf("���벻�Ϸ�,����������\n");
	}
}
/*
* �������ƣ�modifyextension
* �������ܣ��޸��ļ��ĺ�׺
* ���������char* filename �ļ���,const char* format �ļ���ʽ
* ����ֵ�� ��
*/
void modifyextension(char* filename, const char* format) {
	int n = strlen(filename);
	if (!strcmp(format, "t")) {
		filename[n - 4] = '.';
		filename[n - 3] = 't';
		filename[n - 2] = 'x';
		filename[n - 1] = 't';
	}
	else if (!strcmp(format, "d")) {
		filename[n - 4] = '.';
		filename[n - 3] = 'd';
		filename[n - 2] = 'a';
		filename[n - 1] = 't';
	}
	else printf("��ʽ�����޸�ʧ��");
}