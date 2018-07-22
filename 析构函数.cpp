/*
	* destructor����Ա������һ�֣�������������ͬ��ǰ���~��û�в����ͷ���ֵ��һ�������һ��
	* ��������ʱ�Զ����ã���������ǰ�����ƺ��ͷ�ʹ�õĿռ�ȵ�
	* ûд�ĵĻ��������Զ����ɣ����ǲ��漰�ͷ��û�������ڴ��ͷŵ�������
	* delete new������Ķ���Ҳ�ᵼ��destructor������
*/
#include "main.h"

class String
{
public:
	String();
	~String();

private:
	char *p;
};

String::String()
{
	p = new char[10];
}

String::~String()
{
	cout << "destructor called" << endl;
	delete[] p;
}

class Demo
{
public:
	Demo(int i);
	~Demo();

private:
	int id;
};

Demo::Demo(int i)
{
	id = i;
	//cout << "id=" << id << " Constructed!" << endl;
	PRINT("id=%d Constructed!\n", id);
}

Demo::~Demo()
{
	//cout << "id=" << id << " Destructed!" << endl;
	PRINT("id=%d Destructed!\n", id);
}
Demo d1(1);
void Func()
{
	PRINT("Func called\n");
	static Demo d2(2);
	Demo d3(3);
	PRINT("Func called end\n");
}
int main(void) 
{
	Demo d4(4);
	d4 = 6;//ע����������ɶ
	PRINT("main\n");
	{Demo d5(5);}//���������ϻᱻ�������뿪�����������
	Func();
	PRINT("main end\n");
	return 0;
	/* �ȱ�����Ķ������������ */
}
/*
id=1 Constructed!
id=4 Constructed!
id=6 Constructed!
id=6 Destructed!
main
id=5 Constructed!
id=5 Destructed!
id=2 Constructed!
id=3 Constructed!
Func called
id=3 Destructed!
main end
id=6 Destructed!
id=2 Destructed!
id=1 Destructed!
*/