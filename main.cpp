
#include "LinkList.h"
#include "stdio.h"

/** 单链表的应用  */
/** 利用单链表的基本运算 ，求A-B。即若单链表B中的元素出现在单链表A中，则从A中删除该元素   */
/** 分析：对于单链表A中的每个元素e，在单链表B中进行查找，如果在B中存在与A中相同的元素，则将元素从A中删除 */

/** 算法描述：*/
/** A-B算法的实现  */
void DeleteElement(LinkList A, LinkList B) {
    int position;
    DataType e;
    ListNode *p;
    /** 取出链表B中的每个元素与单链表A中的元素比较，如果相等则删除A中所对应的节点  */
    for (int i = 1; i <= ListLenght(B); ++i) {
        p = Get(B, i);     //取出B中的节点，将指针返回给p
        if (p) {
            position = LocatePos(A, p->date);  //比较B中的元素是否与A中的元素相等
            if (position > 0)
                DeleteList(A, position, &e);      //如果相等，则将其从A中删除
        }
    }
}

/********************************************************************************************/
/** 程序测试  ：*/
void DeleteElement(LinkList A, LinkList B); //求A-B的函数声明

int main() {
    DataType a[] = {1,2,3,4,5,6};
    DataType b[] = {1,2,3};
    LinkList A, B;       //声明链表A，B
    ListNode *p;
    InitList(&A);       //初始化链表A
    InitList(&B);       //初始化链表B
    for (int i = 1; i <= sizeof(a) / sizeof(a[0]); i++)     //把数组a中的元素插入到单链表A中
    {
        if (InsertList(A, i, a[i - 1]) == 0) {
            printf("插入位置不合法！");
            return 1;
        }
    }
    for (int i = 1; i <= sizeof(b) / sizeof(b[0]); i++)     //把数组b中的元素插入到单链表B中
    {
        if (InsertList(B, i, b[i - 1]) == 0) {
            printf("插入位置不合法！");
            return 1;
        }
    }
    printf("单链表中A的元素有%d个：\n", ListLenght(A));
    for (int i = 1; i <= ListLenght(A); i++)     //输出单链表A中的元素
    {
        p = Get(A, i);      //返回单链表A中节点的指针
        if (p)
            printf("%4d", p->date);     //输出单链表A中元素
    }
    printf("\n");
    printf("单链表中B的元素有%d个：\n", ListLenght(B));
    for (int i = 1; i <= ListLenght(B); i++) {
        p = Get(B, i);      //返回单链表B中节点的指针
        if (p)
            printf("%4d", p->date);     //输出单链表B中元素
    }
    printf("\n");
    DeleteElement(A, B);     //将在单链表A中出现的B中的元素删除：即A-B
    printf("执行（A-B）后，A中的元素还有%d个：\n", ListLenght(A));
    for (int i = 1; i <= ListLenght(A); i++) {
        p = Get(A, i);      //返回单链表A中节点的指针
        if (p)
            printf("%4d", p->date);     //输出删除后A中元素
    }

}