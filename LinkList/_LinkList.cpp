/**
* Author: �˳�����
* Date: 2023/5/7
* Email: iliekxff@gmail.com
* Blog: https://waer.ltd
* Desc: ��������庯����ʵ��
**/
#include "_LinkList.h"
#include <iostream>

/**
 * ��ʼ��������
 * @param L ������
 * @return bool
 */
bool InitLinkList(LinkList &L)
{
    L = new Node; // ��������L
    if(!L)
        return false;
    L->next = nullptr; // ָ��ָ��nullptr
    return true;
}

/**
 * ������Ĵ���-ͷ�巨
 * @param L ������
 */
void CreateLinkList_H(LinkList &L)
{
    int n;
    LinkList s; // ����һ��ָ�����
    L = new Node;
    L->next = nullptr; //����һ��������
    std::cout <<"������ڵ����n:" <<std::endl;
    std::cin >> n;
    std::cout <<"����������n���ڵ��ֵ:" << std::endl;
    while (n--)
    {
        s = new Node; // �����½ڵ�s
        std::cin >> s->data; // ������Ľڵ�ֵ�����½ڵ��������data
        s->next = L->next;
        L->next = s; // ���½ڵ�s���뵽L�ڵ�֮��
    }
}

/**
 * ������Ĵ���-β�巨
 * @param L ������
 */
void CreateLinkList_R(LinkList &L)
{
    int n; //����ڵ�����
    LinkList s,R;
    L = new Node;
    L->next = nullptr;
    R = L;
    std::cout <<"����ڵ����:" << std::endl;
    std::cin >> n;
    std::cout <<"��������n��Ԫ��:" << std::endl;
    while (n--)
    {
        s = new Node; // �����µĽڵ�
        std::cin >> s->data; // ���½ڵ㸳ֵ
        s->next = nullptr; // ���½ڵ��nextָ�����ÿ�
        R->next = s; // ���½ڵ���뵽��ǰ�ڵ�֮��
        R = s; // ���βָ��ĸ�ֵ������βָ���ָ��
    }
}

/**
 * ��ȡ�������еĵ�i���ڵ������
 * @param L ������
 * @param i Ҫ��ȡԪ�ص�Ŀ��ڵ�
 * @param v �ݴ��ȡ���Ľڵ�ֵ
 * @return bool
 */
bool GetVal(LinkList L,int i,int &v)
{
    int j = 1;
    LinkList  p;
    p = L->next; // ��pָ��ͷ�ڵ�
    while (j<i && p)
    {
        p = p->next;
        j++;
    }
    if(!p || j>i)
        return false;
    v = p->data; //��Ŀ��ֵ�ݴ浽v��
    return true;
}

/**
 * ���ҵ������е�ָ���ڵ�ֵ
 * @param L ������
 * @param e Ҫ���ҵ�Ŀ��ֵ
 * @return bool
 */
bool LocateVal(LinkList L,int v)
{
    LinkList p;
    p = L->next;
    while (p&&p->data != v)
        p = p->next;
    if(!p) // ��������β��������ʧ��
        return false;
    return true;
}
