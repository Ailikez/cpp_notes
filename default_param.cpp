#include "main.h"
/*
	* 意义在于提高程序扩充性
*/
void func(int x1, int x2 = 2, int x3 = 3) { return; }
void mian(void)
{
	func(10); //func(10, 2, 3)
	func(10, 8); //func(10, 8, 3)
//	func(10,  ,8); //报错哦，右边要连续



}