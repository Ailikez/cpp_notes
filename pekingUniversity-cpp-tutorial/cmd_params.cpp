#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main(int argc/* ����Ϊ1������������� */, char *argv[]/* �����б�Ŷ */)
{
	/* ���������б� */
	for (int i = 0; i < argc; i++) 
	{
		cout << (argv[i]) << endl;
	}
	cin.ignore();
	return 0;
}
