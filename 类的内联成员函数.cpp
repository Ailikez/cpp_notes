/*
	* 1. inline + ��Ա����
	* 2. ���������嶨����������
*/
class MyClass1
{
public:
	inline void func1();
	MyClass1();//���캯���������в������������з���ֵ��voidҲ���У��������ǳ�ʼ��
	//��������ʱ�Զ����ù��캯�������ɺ�Ͳ����ڵ�����
	//һ��������ж�����캯��
	~MyClass1();

private:
	void func2() {}; //ע���и��ֺ�
};

MyClass1::MyClass1()
{
}

MyClass1::~MyClass1()
{
}

void MyClass1::func1()
{
}