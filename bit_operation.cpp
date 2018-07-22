#include "main.h"
using std::cin;
using std::cout;
using std::endl;
/*
	* 1.异或可以用来将某变量中某些位取反，且保留其他位不变，0异或一个数不变，1异或一个数取反
	* 2.异或简单加密，值交换
	* 3.右移n位，相当于将左操作数除以2^n，结果往小里取整，如-25>>4 == -2
*/
uint32_t x = 0x87654321;
int main(void)
{
	cout << std::hex << x << endl;
	/* 最低字节除外全部置0 */
	cout << std::hex << (x & 0xFF) << endl;
	/* 最低字节除外全部取补 */
	cout << std::hex << ((x & 0xFF) + ~(0xFF | x)) << endl;
	/* 最低字节置1，其余不变 */
	cout << std::hex << (x | 0xFF) << endl;
	cin.ignore();
	return 0;
}