#include "main.h"
/*
	* ��Ա����: һ����ĳ�Ա����һ����Ķ���
	* ������Ա�����������Ƿ����
	* ����๹�캯���ĳ�ʼ���б���������Ĺ��캯��ʱ����ӳ�ʼ���б��б��ڲ�������
		����:���캯��(������):��Ա����1(������),��Ա����2(������),...
		{
			...
		}
	* ��������������ʱ��
		s1.ִ�����г�Ա����Ĺ��캯��
		s2.ִ�з����Ĺ��캯��
	* ��Ա����Ĺ��캯������˳��
		1.�Ͷ����Ա�����е�˵��˳��һ��
		2.���ڳ�Ա��ʼ���б��г��ֵ�˳���޹�
	* ��������������ʱ��
		s1.ִ�з�������������
		s2.ִ�г�Ա�������������
	* �ȹ���ĺ������������������
*/
class CTyre //��̥��
{
private:
	int radius;
	int width;
public:
	CTyre(int r, int w) :radius(r), width(w) { PRINT("CTyre constructor called\n"); } //��ʼ���б�ʽ
	~CTyre() { PRINT("CTyre destructor called\n"); };
};
class CEngine
{
public:
	CEngine() { PRINT("CEngine constructor called\n"); };
	~CEngine() { PRINT("CEngine destructor called\n"); };
private:

};

class CCar 
{
private:
	int price;
	CTyre tyre;
	CEngine engine;
public:
	CCar(int p, int tr, int tw);
	~CCar() { PRINT("CCar destructor called\n"); };
};

CCar::CCar(int p, int tr, int tw) :price(p), tyre(tr, tw){ PRINT("CCar constructor called\n"); };//ע���зֺ�

int main()
{
	CCar car1(20000, 17, 225);
	return 0;
}
/*
//�ȹ���ĺ������������������
output:
	CTyre constructor called
	CEngine constructor called
	CCar constructor called
	CCar destructor called
	CEngine destructor called
	CTyre destructor called
*/