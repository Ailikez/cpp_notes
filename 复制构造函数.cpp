/*
	* ֻ��һ������������ͬ���������ã����� X::X( X& ) �� X::X(const X &)
	* û���������Ĭ�����ɣ�Ĭ�ϸ��ƹ��캯����ɸ��ƹ���
	* ������X::X(X)������ʽ�����������������
	* ʲôʱ�������ã�
		* 1.��һ������ȥ��ʼ������һ��ͬ��Ķ���ʱ��
			Complex c2(c1); �ȼ��� Complex c2 = c1;//��ʼ�����Ǹ�ֵ
		* 2.ĳ���������β�ʱ��A�Ķ��󣬸ú���������ʱ����A�ĸ��ƹ��캯��Ҳ�ᱻ��������ʼ���βΡ�
			void Func(A a1){}
			void main(){ A a2; Func(a2); }
		* 3.��������ֵ����A�Ķ��󣬺�������ʱ����á�

	* Ϊɶ�Լ�Ҫд���ƹ��캯��
		��
*/
#include "main.h"
using std::cout;
using std::cin;
class Complex
{
public:
	double real, imag;
};

Complex c1;//����ȱʡ�޲εĹ��캯��
Complex c2(c1);//����ȱʡ�ĸ��ƹ��캯������c2��ʼ���ɺ�c1һ��

class Complex2
{
public:
	double real, imag;
	Complex2(double _r, double _i) { real = _r; imag = _i; }
	Complex2(const Complex2 &c)
	{
		real = c.real;
		imag = c.imag;
		cout << "copy completed" << endl;
	}
};
Complex2 c3(1.2, 3.4);//����ȱʡ�޲εĹ��캯��
Complex2 c4(c3);//����ȱʡ�ĸ��ƹ��캯������c2��ʼ���ɺ�c1һ��
void main() { cin.ignore(); }