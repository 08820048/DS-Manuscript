/**
* Author: �˳�����
* Date: 2023/5/7
* Email: iliekxff@gmail.com
* Blog: https://waer.ltd
* Desc: main�������
**/

#include "LinkList/_LinkList.h"

int main()
{
    LinkList L = nullptr;
    CreateLinkList_R(L); //��������
    //��������
    std::cout<<"�����е�Ԫ��Ϊ��"<<std::endl;
    Node *p = L->next; //�ӵ�һ���ڵ㿪ʼ
    while (p != nullptr) {
        std::cout<<p->data<<" ";
        p = p->next; //����������һ���ڵ�
    }
    std::cout<<std::endl;
    return 0;
}
