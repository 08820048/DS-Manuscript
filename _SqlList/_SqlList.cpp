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

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    //���Գ�ʼ������
    TestPrint("------------------��ʼ����������---------------");
    SqlList L;
    if (!InitList(L))
        cout <<"��ʼ��ʧ��!" << endl;
    cout << "��ʼ���ɹ�!" << endl;
    // ���Դ�������
    TestPrint("------------------������������---------------");
    if (!CreateList(L))
    {
        cout <<"����ʧ��!" << endl;
    }
    cout <<"�����ɹ�!" << endl;

    cout << "����Ԫ��֮��˳���ĳ���:" << L.length <<"\n";
    cout <<"˳����Ԫ��Ϊ:" << endl;
    for(int i=0;i<L.length;i++)
    {
        cout <<L.val[i] << " ";
    }
    cout << endl;
    // ���Ի�ȡԪ�غ���
    TestPrint("------------------ȡֵ��������---------------");
    int v;
    if (!GetVal(L,3,v))
    {
        cout <<"��ȡʧ��!";
    }
    cout <<"��" << 3 << "��λ�õ�Ԫ��Ϊ:" << v <<endl;
    // ���Բ��Һ���
    TestPrint("------------------���Һ�������---------------");
    v = -2;
    int index = LocateVal(L,v);
    if (index != -1)
        cout <<"Ԫ��" << v <<"������Ϊ:" << index <<endl;
    else
        cout <<"����ʧ��!";

    delete[] L.val;

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
    while(x!=-1) //��������-1ʱ��������
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