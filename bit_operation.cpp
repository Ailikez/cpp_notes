#include "main.h"
using std::cin;
using std::cout;
using std::endl;
/*
	* 1.������������ĳ������ĳЩλȡ�����ұ�������λ���䣬0���һ�������䣬1���һ����ȡ��
	* 2.���򵥼��ܣ�ֵ����
	* 3.����nλ���൱�ڽ������������2^n�������С��ȡ������-25>>4 == -2
*/
uint32_t x = 0x87654321;
int main(void)
{
	cout << std::hex << x << endl;
	/* ����ֽڳ���ȫ����0 */
	cout << std::hex << (x & 0xFF) << endl;
	/* ����ֽڳ���ȫ��ȡ�� */
	cout << std::hex << ((x & 0xFF) + ~(0xFF | x)) << endl;
	/* ����ֽ���1�����಻�� */
	cout << std::hex << (x | 0xFF) << endl;
	cin.ignore();
	return 0;
}