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



