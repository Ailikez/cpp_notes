// /***********************************************************
// * Function         :  验证位域
// *
// * Result           :  a = 1, b = -2, c = 3, d = -2, e = -4
// *                     a = 3, b = 0, c = 7, d = -1, e = -3
// *
// * Result Analysis  : 之所以出现负数的原因是由于int型默认是有符号型的，所以两位的位域赋值2时就会溢出，
// *                    成为10，高位是表示符号，1表示负号。10取反加1之后就是10，也就是2，所以值是-2
// * *******************************************************/
//
// #include <stdio.h>
// #include <stdint.h>
// #define  SYS_OK         0
// #define  SYS_FAILED     1
// uint32_t ret_a_int_val();
// typedef int SYS_TYPE;
// struct bit_st
// {
//     int a: 3; //第一个字节的0~2位
//     int  : 0; //这里是说明的第二点，空域。下一个位域b将会从下一个字节开始，位3~7为全0。
//     int b: 2; //下一个字节也就是第二个字节的0~1位
//     int c: 5; //第二个字节紧接b之后的2~6位
//     int d: 2; //这里是说明的第一点，d占用第三个字节的0~1位，因为前面一个字节只剩下一位不能存放d，所以另起一个字节存放。
//     int  : 2; //这里说明的是第三点，d域后的两个位2~3不能使用。
//     int e: 3; //存放在第三个字节的第4~6位
// }data, *pData;
// struct bit_field_ptr_type
// {
//     uintptr_t pa;
//     uintptr_t pb;
//     uintptr_t pc;
//     uintptr_t pd;
//     uintptr_t pe;
// }bit_field_ptra_info;
// SYS_TYPE main()
// {
//     data.a = 1;
//     data.b = 2; //注意此处b只占2位，所以取值范围为-2~1，超过-2或者1就出现错误，所以赋值时注意位域的范围
//     data.c = 3;
//     data.d = 2;
//     data.e = 4;
//     // 以下注释为非法操作，尝试获取bitfield中某一个成员的地址，最小粒度是字节，不能获取某个bit的地址
//     // bit_field_ptra_info.pa = &(data.a);
//     // bit_field_ptra_info.pb = &data.b;
//     // bit_field_ptra_info.pc = &data.c;
//     // bit_field_ptra_info.pd = &data.d;
//     // bit_field_ptra_info.pe = &data.e;
//     printf("a = %d, b = %d, c = %d, d = %d, e = %d\r\n",
//         data.a, data.b, data.c, data.d, data.e); //结构体操作
//     pData = &data;
//     pData->a = 3;
//     pData->b &= 1;
//     pData->c |= 5;
//     pData->d ^= 1;
//     pData->e = 5;
//     printf("a = %d, b = %d, c = %d, d = %d, e = %d\r\n",
//         pData->a, pData->b, pData->c, pData->d, pData->e); //结构体指针操作
//     uint32_t x = ret_a_int_val();
//     return SYS_OK;
// }
// uint32_t ret_a_int_val()
// {
//     uint32_t x;
//     x = 1 + 2;
//     return;
// }
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int num_of_int;
    cin >> num_of_int;
    vector<int> num_tab(num_of_int);
    vector<int>::iterator iter = num_tab.begin();
    for (; iter < num_tab.end(); ++iter)
      cin >> *iter;
    iter = num_tab.end()-1;
    for(; iter >= num_tab.begin();--iter)
      cout << *iter << " ";
    return 0;
}
