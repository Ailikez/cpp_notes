/*
	* ʵ�������Զ�ת��
	* ֻ��һ������
	* ���Ǹ��ƹ������
	* ����ϵͳ�Զ�����->ת�����캯��->����һ����ʱ����/��ʱ����
*/
#include "main.h"
class Complex
{
public:
	double
		real, imag;
	Complex(double r, double i);
	Complex(int i);//����ת�����캯��

private:

};

Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
Complex::Complex(int i)//����ת�����캯��
{
	cout << "Type transform Constructor called" << endl;
	real = i;
	imag = 0;
}
int main() {
	Complex c1(7, 8);
	Complex c2 = 12;
	c1 = 9;//9��ת������ʱComplex����
	cout << c1.real << "," << c1.imag;
	cin.ignore();
	return 0;
}
/*
�����
Type transform Constructor called
Type transform Constructor called
9,0
*/