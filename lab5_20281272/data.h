#pragma once
#define MAX_STR_LEN 2000
typedef struct configinfo {
	char filesavepath[MAX_STR_LEN]; //用于存放数据记录文件的存储目录
	char filename[MAX_STR_LEN]; //用于存储数据记录文件的文件名信息
	int number; //用于存放生成的记录条数
	int maxvalue1; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
	int minvalue1; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
	int maxvalue2; //用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
	int minvalue2; //用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
	int recordcount1; //用于存放数据记录文件需要随机生成记录条数时条数值的上限
	int recordcount2; //用于存放数据记录文件需要随机生成记录条数时条数值的下限
}CONF;

struct link {
	int item1; //数据记录三元组第一个元素
	int item2; //数据记录三元组第二个元素
	int item3; //数据记录三元组第三个元素
	link* nextNode;
};

typedef struct DataItem {
	int item1; //数据记录三元组第一个元素
	int item2; //数据记录三元组第二个元素
	int item3; //数据记录三元组第三个元素
} DATAITEM;
extern int sys_mode;//工作模式
extern DATAITEM* StructArray;
extern DATAITEM** PointerArray;
extern int** array2D;
extern link* head;  //头指针
extern link* end;  //尾指针
extern CONF data1;
extern int nCount_array2D;
extern int nCount_StructArray;
extern int nCount_PointerArray;
extern int nCount_link;
extern int last_slash;   //存储用户输入的文件名参数的最后一个斜杠的位置