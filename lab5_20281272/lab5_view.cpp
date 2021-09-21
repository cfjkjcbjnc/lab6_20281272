#include"stdafx.h"
#include"lab5_view.h"
#include"data.h"
#include"sort.h"
/*
* �������ƣ�showMenu
* �������ܣ���ӡ�˵�
* �����������
* ����ֵ�� ��
*/
void showMenu() {
	printf("����ɽ��ʵ��6����:\n");
	printf("1.����ʵ�� 4 �������ɼ�¼�ļ��������ı���ʽ��\n");
	printf("2.����ʵ�� 4 �������ɼ�¼�ļ������򣨶����Ʒ�ʽ��\n");
	printf("3.��ȡָ�����ݼ�¼�ļ������򣨶�ά����洢��ʽ��\n");
	printf("4.��ȡָ�����ݼ�¼�ļ������򣨽ṹ������洢��ʽ��\n");
	printf("5.��ȡָ�����ݼ�¼�ļ�������ָ������洢��ʽ��\n");
	printf("6.��ȡָ�����ݼ�¼�ļ�����������洢��ʽ��\n");
	printf("7.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ�������ά���鷽ʽ�洢��\n");
	printf("8.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ������ṹ�����鷽ʽ�洢��\n");
	printf("9.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ�����ָ�����鷽ʽ�洢��\n");
	printf("10.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ���������ʽ�洢��\n");
	printf("11.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�������ά���鷽ʽ�洢��\n");
	printf("12.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ������ṹ�����鷽ʽ�洢��\n");
	printf("13.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�����ָ�����鷽ʽ�洢��\n");
	printf("14.����ʵ�� 4 �������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ���������ʽ�洢��\n");
	printf("15.�����������ò���ֵ\n");
	printf("0.�˳�\n");
	if (sys_mode == 1) {
		printf("��ǰ����ģʽ:�Զ�ģʽ\n");
	}
	else {
		printf("��ǰ����ģʽ:����ģʽ\n");
	}
	printf("��������Ҫִ�еĳ������:\n");
}
/*
* �������ƣ�show2DArray
* �������ܣ������ά���������,����ն�ά����
* �����������
* ����ֵ�� ��
*/
void show2DArray()
{
	int i;
	qsort(array2D, nCount_array2D, sizeof(int*), cmp_array);
	printf("%d\n", nCount_array2D);
	for (i = 0; i < nCount_array2D; i++) {
		printf("%d %d %d\n", array2D[i][0], array2D[i][1], array2D[i][2]);
		free(array2D[i]);
	}
	free(array2D);
}
/*
* �������ƣ�showStructArray
* �������ܣ�����ṹ�����������,����սṹ������
* �����������
* ����ֵ�� ��
*/
void showStructArray()
{
	int i;
	qsort(StructArray, nCount_StructArray, sizeof(StructArray[0]), cmp_struct);
	printf("%d\n", nCount_StructArray);
	if (StructArray != NULL) {
		for (i = 0; i < nCount_StructArray; i++) {
			printf("%d %d %d\n", StructArray[i].item1, StructArray[i].item2, StructArray[i].item3);
		}
	}
	free(StructArray);
}
/*
* �������ƣ�showPointerArray
* �������ܣ����ָ�����������,�����ָ������
* �����������
* ����ֵ�� ��
*/
void showPointerArray()
{
	int i;
	qsort(PointerArray, nCount_PointerArray, sizeof(DATAITEM*), cmp_PointerArray);
	printf("%d\n", nCount_PointerArray);
	if (PointerArray != NULL) {
		for (i = 0; i < nCount_PointerArray; i++) {
			printf("%d %d %d\n", PointerArray[i]->item1, PointerArray[i]->item2, PointerArray[i]->item3);
			free(PointerArray[i]);
		}
	}
	free(PointerArray);
}
/*
* �������ƣ�showLink
* �������ܣ�������������,���������
* �����������
* ����ֵ�� ��
*/
void showLink()
{
	int i;
	link* p,*r;
	sort_link();
	printf("%d\n", nCount_link);
	if (head != NULL) {
		for (p = head; p; p = r) {
			r = p->nextNode;
			printf("%d %d %d\n", p->item1, p->item2, p->item3);
			free(p);
		}
	}
	head = NULL;
}
/*
* �������ƣ�showCONF
* �������ܣ������ǰ��������Ϣ����
* �����������
* ����ֵ�� ��
*/
void showCONF()
{
	printf("��ǰ�����ļ���������\n");
	printf("1.�洢·��:%s\n", data1.filesavepath);
	printf("2.�ļ���:%s\n", data1.filename);
	printf("3.��һ������Ԫ�����ֵ:%d\n", data1.maxvalue1);
	printf("4.��һ������Ԫ����Сֵ:%d\n", data1.minvalue1);
	printf("5.������Ԫ�����ֵ:%d\n", data1.maxvalue2);
	printf("6.������Ԫ����Сֵ:%d\n", data1.minvalue2);
	printf("7.��¼�������ֵ:%d\n", data1.recordcount1);
	printf("8.��¼������Сֵ:%d\n", data1.recordcount2);
	printf("9.����ģʽ:%d\n", sys_mode);
	printf("0.���沢�˳�\n");
	printf("��������Ҫ�޸ĵ����\n");
}
