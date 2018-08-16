#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main(int argc/* 最少为1，代表参数个数 */, char *argv[]/* 参数列表哦 */)
{
	/* 遍历参数列表 */
	for (int i = 0; i < argc; i++) 
	{
		cout << (argv[i]) << endl;
	}
	cin.ignore();
	return 0;
}
