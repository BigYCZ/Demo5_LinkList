
#include "LinkList.h"
#include "stdio.h"

/** �������Ӧ��  */
/** ���õ�����Ļ������� ����A-B������������B�е�Ԫ�س����ڵ�����A�У����A��ɾ����Ԫ��   */
/** ���������ڵ�����A�е�ÿ��Ԫ��e���ڵ�����B�н��в��ң������B�д�����A����ͬ��Ԫ�أ���Ԫ�ش�A��ɾ�� */

/** �㷨������*/
/** A-B�㷨��ʵ��  */
void DeleteElement(LinkList A, LinkList B) {
    int position;
    DataType e;
    ListNode *p;
    /** ȡ������B�е�ÿ��Ԫ���뵥����A�е�Ԫ�رȽϣ���������ɾ��A������Ӧ�Ľڵ�  */
    for (int i = 1; i <= ListLenght(B); ++i) {
        p = Get(B, i);     //ȡ��B�еĽڵ㣬��ָ�뷵�ظ�p
        if (p) {
            position = LocatePos(A, p->date);  //�Ƚ�B�е�Ԫ���Ƿ���A�е�Ԫ�����
            if (position > 0)
                DeleteList(A, position, &e);      //�����ȣ������A��ɾ��
        }
    }
}

/********************************************************************************************/
/** �������  ��*/
void DeleteElement(LinkList A, LinkList B); //��A-B�ĺ�������

int main() {
    DataType a[] = {1,2,3,4,5,6};
    DataType b[] = {1,2,3};
    LinkList A, B;       //��������A��B
    ListNode *p;
    InitList(&A);       //��ʼ������A
    InitList(&B);       //��ʼ������B
    for (int i = 1; i <= sizeof(a) / sizeof(a[0]); i++)     //������a�е�Ԫ�ز��뵽������A��
    {
        if (InsertList(A, i, a[i - 1]) == 0) {
            printf("����λ�ò��Ϸ���");
            return 1;
        }
    }
    for (int i = 1; i <= sizeof(b) / sizeof(b[0]); i++)     //������b�е�Ԫ�ز��뵽������B��
    {
        if (InsertList(B, i, b[i - 1]) == 0) {
            printf("����λ�ò��Ϸ���");
            return 1;
        }
    }
    printf("��������A��Ԫ����%d����\n", ListLenght(A));
    for (int i = 1; i <= ListLenght(A); i++)     //���������A�е�Ԫ��
    {
        p = Get(A, i);      //���ص�����A�нڵ��ָ��
        if (p)
            printf("%4d", p->date);     //���������A��Ԫ��
    }
    printf("\n");
    printf("��������B��Ԫ����%d����\n", ListLenght(B));
    for (int i = 1; i <= ListLenght(B); i++) {
        p = Get(B, i);      //���ص�����B�нڵ��ָ��
        if (p)
            printf("%4d", p->date);     //���������B��Ԫ��
    }
    printf("\n");
    DeleteElement(A, B);     //���ڵ�����A�г��ֵ�B�е�Ԫ��ɾ������A-B
    printf("ִ�У�A-B����A�е�Ԫ�ػ���%d����\n", ListLenght(A));
    for (int i = 1; i <= ListLenght(A); i++) {
        p = Get(A, i);      //���ص�����A�нڵ��ָ��
        if (p)
            printf("%4d", p->date);     //���ɾ����A��Ԫ��
    }

}