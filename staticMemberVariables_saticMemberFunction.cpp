#include "main.h"
/*
	* ��ͨ��Ա����ÿ���������Լ����Ե�һ�ݣ���̬��Ա����һ����һ�ݣ����ж�����
	* sizeof��������Ὣ��̬��Ա�����������
*/
/*
	* ��ͨ��Ա�����������������ĳ�����󣬾�̬��Ա������������������ĳ������
*/
/*
	* ��̬��Ա(����/����)����Ҫͨ������Ϳ��Է��ʵ�
	* 1.����::��̬��Ա��
	* 2.������.��̬��Ա��(ע�⣬�����������ڶ����ϣ�ֻ��һ��д������)
	* 3.ָ��->��̬��Ա��
	* 4.����.��̬��Ա��
	* ��̬���������Ͼ���ȫ�ֱ���������һ�����󶼲������ˣ���ľ�̬�������Ǵ���
	* ���壺 ����ĳЩ�������ص�ȫ�ֱ����ͺ���д�������棬����ȥ����һ�����壬��������ά��
*/
class CRectangle
{
public:
	CRectangle(int _w, int _h);
	CRectangle(int _w);
	~CRectangle();
	static void PrintTotal();//��̬��Ա����
private:
	int w, h;
	/*
		* ����Ҫ��ʱ֪�������������������������ȫ�ֱ�������¼��д��������ͱ侲̬��Ա��
	*/
	static int nTotalAera;//��̬��Ա����
	static int nTotalNumber;
};

CRectangle::CRectangle(int _w, int _h)
{
	w = _w, h = _h;
	nTotalAera += w * h;
	nTotalNumber ++;
	PRINT("Constructor called\n");
	/*ע��˴�������BUG*/
	/*�������ж����ô˺�������*/
	/*���ø��ƹ��캯��������ʱ�����صĶ���ʱ��������������*/
}
//���ƹ��캯��Ҫ�Լ���д�Ż���BUG
CRectangle::CRectangle(int _w)//����ת�����캯��
{
	PRINT("Type transform Constructor called\n");
	w = _w, h = 3;
	/*����Ҫ��Ӧ����ȫ�ֱ�����ok*/
}
CRectangle::~CRectangle()
{
	nTotalAera -= w * h;
	nTotalNumber--;
	PRINT("Destructor called\n");
	/* ע��˴�������BUG */
	/* ���ø��ƹ��캯��������ʱ�����صĶ�������ʱ��������������ʹ����ƽ���޹ʼ��� */
	/* ����һ����CRectangle����Ϊ���������ĺ���ʱ */
	/* ����һ����CRectangle����Ϊ��������ֵʱ */
	/* ����ת���������ɵ���ʱ��������ʱ */
}
void CRectangle::PrintTotal()
{
	/* �ھ�̬��Ա�����в��ܷ��ʷǾ�̬��Ա����Ҳ���ܵ��÷Ǿ�̬��Ա��������Ϊ��̬��Ա�����������ĳ������� */
	PRINT("%d,%d\n", nTotalNumber, nTotalAera);
}
/* �����ڶ�������ļ��жԾ�̬��Ա��������һ���������߳�ʼ�����������ͨ�������Ӳ���ͨ�� */
int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalAera = 0;

int main()
{
	CRectangle r1(3, 3), r2(2, 2);
	//CRectangle::PrintTotal();
	//{CRectangle r3(4,4); CRectangle::PrintTotal();}
	CRectangle::PrintTotal();
	r1 = 3;
	CRectangle::PrintTotal();
	r1.PrintTotal();
	return 0;
}