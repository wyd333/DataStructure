#include "SList.h"

//�������ӡ
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//����ʱ--��̬����һ���ڵ�
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));	//����һ���µĽڵ�newnode
	newnode->data = x;	//��Ҫ��������ݷ���ýڵ�
	newnode->next = NULL;	//��ʼ���ýڵ��nextΪNULL����Ϊֻ�����룬��û�о���ʹ��

	return newnode;		//���¿��ٳ��Ľڵ㷵��
}

//β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ��β�ڵ��ָ��
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		// β�ڵ㣬�����½ڵ�
		tail->next = newnode;
	}
}

//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;
	free(*pphead);

	*pphead = next;
}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL)	// 1����
	{
		return;
	}
	else if ((*pphead)->next == NULL)	// 2��������ֻ��һ���ڵ�ʱ
	{
		free(*pphead);
		*pphead = NULL;
	}
	else	// 3����һ�����ϵĽڵ�
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		prev->next = NULL;
	}
}

//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SListNode* cur = phead;
	//while (cur != NULL)
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// ��pos��ǰ�����x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySListNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = newnode;
		newnode->next = pos;
	}
}

// ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
	}
}