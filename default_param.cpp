#include "main.h"
/*
	* ����������߳���������
*/
void func(int x1, int x2 = 2, int x3 = 3) { return; }
void mian(void)
{
	func(10); //func(10, 2, 3)
	func(10, 8); //func(10, 8, 3)
//	func(10,  ,8); //����Ŷ���ұ�Ҫ����



}