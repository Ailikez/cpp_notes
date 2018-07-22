/* 
 * constexpr �ؼ��ֽ������εĺ����ĵ�����������ʱ������Ҳ����˵������ռ������ʱ�ڴ� 
 * constexpr ��һЩ���ƣ� 1. �ú���������һ����void���ͣ� 2.�ú���ֻ����һ����ִ����䣬������return���
 * 3.�ú��������������ѡ��using, typedef�Ϳ����
 * ��constexpr���εĺ����������������������ǵĶ�����Է���ͷ�ļ�
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
constexpr int factorial(int n)/* �׳� */
{
	return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main(void)
{
	cout << "factorial of 10 is " << factorial(10) << endl;
	cin.ignore();
	return 1;
}