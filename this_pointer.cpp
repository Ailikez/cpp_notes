#include <iostream>
using std::cout;
using std::endl;
using std::cin;
//刚开始没有c++编译器时，先将C++翻译成C再用c编译器
//this指针的作用是指向成员函数所作用的对象
class Complex {
public:
  double real, imag;
  void Print() { cout << real << ',' << imag << endl; }
  Complex(double r, double i) : real(r), imag(i) {}
  Complex AddOne() {
    this->real++;//等价于real++
    this->Print();
    return *this;//this指针指向AddOne所作用的对象
  }
};
/* 神奇的例子 */
class A {
  int i;
public:
  void Hello() { cout << "Hello!" << endl; }
  //翻译成 void Hello(A *this){ cout << "Hello!" << endl; }
  void Hello2() { cout << i << "Hello!" << endl; }
  //翻译成 void Hello2(A *this){ cout << this->i << "Hello!" << endl; }
};
int main() {
  Complex c1(1, 1), c2(0, 0);
  c2 = c1.AddOne();
  /* 神奇的例子 */
  A *p = NULL;
  p->Hello();//翻译成 Hello(p), 因为Hello里面并没有和对象产生关系，所以不论this指向啥都无所谓
  p->Hello2();//会炸，因为Hello2里面有这么一句: this->i
  return 0;
}
/*
  * 最后，静态成员函数不能使用this指针
  * 因为静态成员函数并不具体作用于某个对象
  * 它翻译出来的参数并不会多出this指针
  *
*/
