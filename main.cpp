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
    CreateLinkList_R(L); // ��������

    // ����GetVal����
    int v;
    if (GetVal(L, 3, v)) {
        std::cout << "��3��Ԫ��Ϊ��" << v << std::endl;
    } else {
        std::cout << "�����ڵ�3��Ԫ��" << std::endl;
    }

    if (GetVal(L, 5, v)) {
        std::cout << "��5��Ԫ��Ϊ��" << v << std::endl;
    } else {
        std::cout << "�����ڵ�5��Ԫ��" << std::endl;
    }

    if (GetVal(L, 7, v)) {
        std::cout << "��7��Ԫ��Ϊ��" << v << std::endl;
    } else {
        std::cout << "�����ڵ�7��Ԫ��" << std::endl;
    }
    return 0;
}
