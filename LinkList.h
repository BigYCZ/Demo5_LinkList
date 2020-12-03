//
// Created by Yuecaizheng on 2020/11/29.
//

#ifndef DEMO5_LINKLIST_LINKLIST_H
#define DEMO5_LINKLIST_LINKLIST_H

#include <cstdlib>
#include "stdio.h"


typedef int DataType;
/** 定义单链表结构体 */
typedef struct Node {
    DataType date;      //数据域
    struct Node *next;  //指针域
} ListNode, *LinkList;  //ListNode为链表的节点类型，LinkList为指向链表节点的指针类型

/** 单链表的基本运算 */

/** 单链表的初始化 */
void InitList(LinkList *h) {
    if ((*h = (LinkList) malloc(sizeof(ListNode))) == NULL)      //为头节点分配一个存储空间
        exit(-1);
    (*h)->next = NULL;        //将单链表的头节点指针域置为空
}

/** 判断单链表是否为空 */
int ListEmpty(LinkList h) {
    if (h->next == NULL)        //若为空
        return 1;           //返回1
    else
        return 0;           //否则返回0
}

/** 按序号查找操作，链表是一种随机存储结构，只能从头指针开始存取元素。因此，要查找单链表中的第 i个元素，需要从单链表的
 * 头指针h出发，利用节点的next域依次访问链表的结点，并进行比较操作。利用计数器从0开始计数，当计数器为i时，就找到了第i个节点 */

/** 查找单链表中第i个节点 ，查找成功返回该节点的指针，否则返回NUll */
ListNode *Get(LinkList h, int i) {
    ListNode *p;
    int j;
    if (ListEmpty(h))       //查找第i个元素之前，判断链表是否为空
        return NULL;
    if (i < 1)              //判断序号是否合法
        return NULL;
    j = 0;
    p = h;
    while (p->next != NULL && j < i) {      //链表的头指针指向next域，不等于空且计数器小于i
        p = p->next;            //开始赋值给p
        j++;            //计数器增加
    }
    if (j == i)     //如果找到第i个节点
        return p;   //返回指针p
    else
        return NULL;    //否则返回Null
}

/** 按内容查找操作 */

/** 查找线性表中元素值e的元素，查找成功返回对应元素的节点指针，否则返回Null */
ListNode *LocateElement(LinkList h, DataType e) {
    ListNode *p;
    p = h->next;      //指针p指向第一个节点
    while (p) {
        if (p->date != e)  //如果当前元素值与e不相等
            p = p->next;  //则继续查找
        else
            break;      //否则，推出循环，停止查找
    }
    return p;       //返回节点的指针
}

/** 定位操作。定位操作是指按内容查找并返回节点的序号的操作。从单链表的头指针出发，依次访问每个节点
 * 并将节点的值与e比较，如果相等，返回该序号表示成功。如果没有值与e相等的元素，返回0表示失败*/

/** 查找线性表中元素值为e的元素，查找成功返回对应元素的序号，否则返回0 */
int LocatePos(LinkList h, DataType e) {
    ListNode *p;
    int i;
    if (ListEmpty(h))       //查找第i个元素之前，判断链表是否为空
        return 0;
    p = h->next;      //从第一个节点开始查找
    i = 1;
    while (p) {
        if (p->date == e)      //找到值与e相等的元素
            return 1;       //返回该序号
        else {
            p = p->next;      //否认则继续查找
            i++;
        }
    }
    if (!p)         //如果没有找到值与e先等元素，返回0，表示失败
        return 0;
}

/** 插入操作。插入操作就是将元素e插入到链表中指定的位置i，插入成功返回1，否则返回0  */

/**  在单链表中第i个位置插入值为e的节点。插入成功返回1，失败返回0  */
int InsertList(LinkList h, int i, DataType e) {
    ListNode *p, *previous;
    int j;
    previous = h;     //指针p指向头节点
    j = 0;
    while (previous->next != NULL && j < i - 1) {    //找到第i-1个节点，即第i个节点的前驱节点
        previous = previous->next;
        j++;
    }
    if (j != i - 1) {
        printf("插入位置错误\n");
        return 0;
    }
    /** 新生成一个节点，并将e赋值给该节点的数据与 */
    if ((p = (ListNode *) malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    p->date = e;
    //插入节点操作
    p->next = previous->next;
    previous->next = p;
    return 1;
}
/** PS:插入节点的操作不能反过来，先执行 previous->next=p 操作，后执行 p->next=previous->next */

/** 删除操作。删除操作就是将单链表中的第i个节点删除，其他节点仍然构成一个单链表。删除成功返回1，否则返回0 */
/** 删除单链表中的第i个位置的节点。删除成功返回1，失败返回0 */
int DeleteList(LinkList h, int i, DataType *e) {
    ListNode *previous, *p;
    int j;
    previous = h;
    j = 0;
    while (previous->next != NULL && previous->next->next != NULL && j < i - 1)     //寻找的过程中确保被删除的节点存在
    {
        previous = previous->next;
        j++;
    }
    if (j != i - 1)      //如果没有找到要删除的节点位置，说明删除错误
    {
        printf("删除位置错误！");
        return 0;
    }
    p = previous->next;
    *e = p->date;
    /** 将前驱节点的指针域指向要删除节点的下一个节点，也就是将p指向的节点与单链表断开 */
    previous->next = p->next;
    free(p);        //释放p指向的节点
    return 1;
}
/** PS：在寻找第i-1个节点（被删除节点的前驱节点）时，要保证被删除节点存在，即 previous->next->next!=NULL
 * 如果没有该判断条件，且要删除的节点在链表中不存在，就会执行循环后出现p指向NULL指针域，从而造成错误 */


/** 求表长 */
/** 求线性表的表长 */
int ListLenght(LinkList h) {
    ListNode *p;
    int count = 0;
    p = h;
    while (p->next != NULL) {
        p = p->next;
        count++;
    }
    return count;
}

/** 销毁链表  */
void DestroyList(LinkList h) {
    ListNode *p, *q;
    p = h;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }

}

#endif //DEMO5_LINKLIST_LINKLIST_H
