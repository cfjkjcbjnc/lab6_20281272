#include"sort.h"
#include"stdafx.h"
#include"data.h"
int cmp_array(const void* a, const void* b)
{
	return (*(int**)a)[2] - (*(int**)b)[2];
}

int cmp_struct(const void* a, const void* b)
{
	DATAITEM* aa = (DATAITEM*)a;
	DATAITEM* bb = (DATAITEM*)b;
	return aa->item3 - bb->item3;
}

int cmp_PointerArray(const void* a, const void* b)
{
	return (*(DATAITEM**)a)->item3 - (*(DATAITEM**)b)->item3;
}

void sort_link()
{
	int i, j,t;
	link* p;
	for (i = 0; i < nCount_link; i++) {
		p = head;
		for (j = 0; j < nCount_link - i - 1; j++) {
			if (p->item3 > p->nextNode->item3) {
				t = p->item1;
				p->item1 = p->nextNode->item1;
				p->nextNode->item1 = t;
				t = p->item2;
				p->item2 = p->nextNode->item2;
				p->nextNode->item2 = t;
				t = p->item3;
				p->item3 = p->nextNode->item3;
				p->nextNode->item3 = t;
			}
			p = p->nextNode;
		}
	}
}
