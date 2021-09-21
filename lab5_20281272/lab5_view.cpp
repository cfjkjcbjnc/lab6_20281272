#include"stdafx.h"
#include"lab5_view.h"
#include"data.h"
#include"sort.h"
/*
* 函数名称：showMenu
* 函数功能：打印菜单
* 输入参数：无
* 返回值： 无
*/
void showMenu() {
	printf("陈益山的实验6程序:\n");
	printf("1.调用实验 4 程序生成记录文件并排序（文本方式）\n");
	printf("2.调用实验 4 程序生成记录文件并排序（二进制方式）\n");
	printf("3.读取指定数据记录文件并排序（二维数组存储方式）\n");
	printf("4.读取指定数据记录文件并排序（结构体数组存储方式）\n");
	printf("5.读取指定数据记录文件并排序（指针数组存储方式）\n");
	printf("6.读取指定数据记录文件并排序（链表存储方式）\n");
	printf("7.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（文本方式输出，二维数组方式存储）\n");
	printf("8.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（文本方式输出，结构体数组方式存储）\n");
	printf("9.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（文本方式输出，指针数组方式存储）\n");
	printf("10.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（文本方式输出，链表方式存储）\n");
	printf("11.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（二进制方式输出，二维数组方式存储）\n");
	printf("12.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（二进制方式输出，结构体数组方式存储）\n");
	printf("13.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（二进制方式输出，指针数组方式存储）\n");
	printf("14.调用实验 4 生成数据记录文件，同时读取数据记录文件并排序（二进制方式输出，链表方式存储）\n");
	printf("15.重新设置配置参数值\n");
	printf("0.退出\n");
	if (sys_mode == 1) {
		printf("当前工作模式:自动模式\n");
	}
	else {
		printf("当前工作模式:交互模式\n");
	}
	printf("请输入您要执行的程序序号:\n");
}
/*
* 函数名称：show2DArray
* 函数功能：输出二维数组的内容,并清空二维数组
* 输入参数：无
* 返回值： 无
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
* 函数名称：showStructArray
* 函数功能：输出结构体数组的内容,并清空结构体数组
* 输入参数：无
* 返回值： 无
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
* 函数名称：showPointerArray
* 函数功能：输出指针数组的内容,并清空指针数组
* 输入参数：无
* 返回值： 无
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
* 函数名称：showLink
* 函数功能：输出链表的内容,并清空链表
* 输入参数：无
* 返回值： 无
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
* 函数名称：showCONF
* 函数功能：输出当前的配置信息内容
* 输入参数：无
* 返回值： 无
*/
void showCONF()
{
	printf("当前配置文件参数如下\n");
	printf("1.存储路径:%s\n", data1.filesavepath);
	printf("2.文件名:%s\n", data1.filename);
	printf("3.第一、二个元素最大值:%d\n", data1.maxvalue1);
	printf("4.第一、二个元素最小值:%d\n", data1.minvalue1);
	printf("5.第三个元素最大值:%d\n", data1.maxvalue2);
	printf("6.第三个元素最小值:%d\n", data1.minvalue2);
	printf("7.记录条数最大值:%d\n", data1.recordcount1);
	printf("8.记录条数最小值:%d\n", data1.recordcount2);
	printf("9.工作模式:%d\n", sys_mode);
	printf("0.保存并退出\n");
	printf("请输入你要修改的序号\n");
}
