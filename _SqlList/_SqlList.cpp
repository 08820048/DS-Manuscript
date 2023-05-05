/**
* Author: �˳�����
* Date: 2023/5/3
* Email: iliekxff@gmail.com
* Blog: https://waer.ltd
* Desc: ˳���Ļ�������
**/

#include <iostream>
const int MaxSize = 100;
typedef int ElemType;
typedef struct
{
    ElemType *val;
    int length;
} SqlList;

void TestPrint(const std::string &str);
bool InitList(SqlList &L);
bool CreateList(SqlList &L);
bool GetVal(SqlList &L,int i,int &v);
int LocateVal(SqlList L,int v);
bool ListInsert(SqlList &L,int i,int v);
bool ListDelete(SqlList &L,int i,int &v);
// ��������
//��������д���������Դ���
#include <iostream>
using namespace std;
// ���Գ�ʼ������
void test_InitList() {
    SqlList L;
    bool res = InitList(L);
    if (res) {
        cout << "InitList����ͨ��" << endl;
    } else {
        cout << "InitList���Բ�ͨ��" << endl;
    }
}
// ���Դ�������
void test_CreateList() {
    SqlList L;
    bool res = CreateList(L);
    if (res) {
        cout << "CreateList����ͨ��" << endl;
    } else {
        cout << "CreateList���Բ�ͨ��" << endl;
    }
}
// ���Ի�ȡԪ�غ���
void test_GetVal() {
    SqlList L;
    bool res = InitList(L);
    if (!res) {
        cout << "GetVal���Բ�ͨ����˳����ʼ��ʧ��" << endl;
        return;
    }
    res = CreateList(L);
    if (!res) {
        cout << "GetVal���Բ�ͨ����˳�����ʧ��" << endl;
        return;
    }
    int i = 0;
    cout << "������Ҫ��ȡ�ĵڼ���Ԫ�ص�λ�ã�1-" << L.length << "����";
    cin >> i;
    int v;
    res = GetVal(L, i, v);
    if (res) {
        cout << "GetVal����ͨ������ȡ����" << i << "��Ԫ����" << v << endl;
    } else {
        cout << "GetVal���Բ�ͨ��" << endl;
    }
}
// ���Բ���Ԫ�غ���
void test_LocateVal() {
    SqlList L;
    bool res = InitList(L);
    if (!res) {
        cout << "LocateVal���Բ�ͨ����˳����ʼ��ʧ��" << endl;
        return;
    }
    res = CreateList(L);
    if (!res) {
        cout << "LocateVal���Բ�ͨ����˳�����ʧ��" << endl;
        return;
    }
    int v = 0;
    cout << "������Ҫ���ҵ�Ԫ��ֵ��";
    cin >> v;
    int index = LocateVal(L, v);
    if (index != -1) {
        cout << "LocateVal����ͨ����Ԫ��" << v << "��λ����" << index + 1 << endl;
    } else {
        cout << "LocateVal���Բ�ͨ��" << endl;
    }
}
// ���Բ���Ԫ�غ���
void test_ListInsert() {
    SqlList L;
    bool res = InitList(L);
    if (!res) {
        cout << "ListInsert���Բ�ͨ����˳����ʼ��ʧ��" << endl;
        return;
    }
    res = CreateList(L);
    if (!res) {
        cout << "ListInsert���Բ�ͨ����˳�����ʧ��" << endl;
        return;
    }
    cout << "������Ҫ�����λ�ú�ֵ��λ�ô�1��ʼ����";
    int i, v;
    cin >> i >> v;
    res = ListInsert(L, i, v);
    if (res) {
        cout << "ListInsert����ͨ��������ɹ����������б�Ϊ��";
        for (int j = 0; j < L.length; j++) {
            cout << L.val[j] << " ";
        }
        cout << endl;
    } else {
        cout << "ListInsert���Բ�ͨ��" << endl;
    }
}
// ����ɾ��Ԫ�غ���
void test_ListDelete() {
    SqlList L;
    bool res = InitList(L);
    if (!res) {
        cout << "ListDelete���Բ�ͨ����˳����ʼ��ʧ��" << endl;
        return;
    }
    res = CreateList(L);
    if (!res) {
        cout << "ListDelete���Բ�ͨ����˳�����ʧ��" << endl;
        return;
    }
    cout << "������Ҫɾ����λ�ã�λ�ô�1��ʼ����";
    int i;
    cin >> i;
    int v;
    res = ListDelete(L, i, v);
    if (res) {
        cout << "ListDelete����ͨ����ɾ���ɹ���ɾ����Ԫ��ֵΪ" << v << "��ɾ������б�Ϊ��";
        for (int j = 0; j < L.length; j++) {
            cout << L.val[j] << " ";
        }
        cout << endl;
    } else {
        cout << "ListDelete���Բ�ͨ��" << endl;
    }
}
// ������ں���
int main() {
    test_InitList();
    test_CreateList();
    test_GetVal();
    test_LocateVal();
    test_ListInsert();
    test_ListDelete();
    return 0;
}



void TestPrint(const std::string &str)
{
    std::cout << "[" <<str <<"]" << std::endl;
}

/**
 * ˳���ĳ�ʼ��
 * @param L ˳��������
 * @return bool
 */
bool InitList(SqlList &L)
{
    L.val = new int[MaxSize]; // ��̬����һ��MaxSize��С�Ŀռ�
    if (!L.val) return false; //����ʧ��
    L.length = 0; //�����ȳ�ʼ��Ϊ0
    return true; // ����ɹ�
}


/**
 * ˳���Ĵ���
 * @param L ˳��������
 * @return bool
 */
bool CreateList(SqlList &L)
{
    int i = 0,x=0;
    std::cin >> x;
    while(x!=-10) //��������-1ʱ��������
    {
        if(L.length == MaxSize)
        {
            std::cout <<"Ŷ�𣡱����ˡ�";
            return false;
        }
        L.val[i++] = x; // #3 ��˳������Ԫ�ز���������
        L.length++; //#4 ���ȵ���
        std::cin >> x;
    }
    return true;
}


/**
 * ��ȡ��n��Ԫ��
 * @param L ������
 * @param i λ��
 * @param v �洢��ȡ����Ԫ��ֵ
 * @return bool
 */
bool GetVal(SqlList &L,int i,int &v)
{
    if (i < 1 || i > L.length)
    {
        std::cout <<"�Ƿ�λ��";
        return false;
    }
    v = L.val[i-1];
    return true;
}


/**
 * ����ָ��Ԫ��
 * @param L  ˳���
 * @param v ָ��Ԫ��
 * @return �ɹ�����Ԫ��������ʧ�ܷ���-1
 */
int  LocateVal(SqlList L,int v)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if (L.val[i] == v) return i;
    }
    return -1;
}

/**
 * ��˳����i��λ�ò���һ��Ԫ��v
 * @param L ˳���
 * @param i ��i��λ��
 * @param v �������Ŀ��Ԫ��
 * @return bool
 */
bool ListInsert(SqlList &L,int i,int v)
{
    if (i<1 || i > L.length + 1) return false; //����λ�úϷ����ж�
    if (L.length == MaxSize) return false; //�������޷�����
    for (int j = L.length-1;j >=i-1;j--) // ��λ
        L.val[j+1] = L.val[j];
    L.val[i-1] = v; // ����
    L.length++;
    return true; //��ɲ���
}

/**
 * ɾ����i��Ԫ��
 * @param L ˳���
 * @param i ��i��Ԫ��
 * @param v �ݴ��ɾ����Ԫ��
 * @return bool
 */
bool ListDelete(SqlList &L,int i,int &v)
{
    if (i < 1 || i >L.length) return false; //�Ϸ����ж�
    v = L.val[i-1]; // �ݴ��ɾ����Ԫ�أ����ȷ������Ҫ����ɾ��Ԫ�ص�����£�����ʡ����һ��
    for (int j = i;j <= L.length-1;j++)
        L.val[j-1] = L.val[j]; //��i�������Ԫ��������ǰ�ƶ�
    L.length--;
    return true;
}