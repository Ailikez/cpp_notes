/*
    * 继承："是"的关系
    *   - 基类A，B是基类A的派生类
    *   - 逻辑上要求：一个B对象也是一个A对象
    * 复合关系："有"的关系
    *   - 类C中“有”成员变量k，k是类D的的对象，则C和D是复合关系
    *   - 一般逻辑上要求：D对象是C对象的固有属性或者组成部分
*/
/*
    * 继承关系的使用
    *   写了一个CMan类代表男性
    *   后来发现需要写一个CWoman类代表女性
    *   明显一个女人不可能是一个男人，所以不能继承，同理分析不能复合
    *   所以抽象出二者共同特点写一个CHuman类，CMan和CWoman都从CHuman类派生
    * 复合关系的使用
    *   1.几何形体程序中，需要写点类，也需要写圆类
    *   明显两者是复合关系 -- 每一个圆都‘有’着自己的圆心（点对象）
    *   2.写一个小区养狗管理程序，需要写一个业主类还需要写一个狗类
    *   一个业主最多10条狗，一条狗只有一个主人
    *   这里很容易犯错误
    *   错误写法1. 🐶中有人，人中有🐶
    *       class CDog;
    *       class CMaster
    *       {
    *           CDog dogs[10];
    *       };
    *       class CDog
    *       {
    *           CMaster m;
    *       };
    *       //循环定义，编译器都算不出这两个类的大小
    *   错误写法2. 如何维护不同的相同主人的狗类里面的主人信息一致性？
    *       class CDog;
    *       class CMaster
    *       {
    *           CDog *dogs[10];
    *       };
    *       class CDog
    *       {
    *           CMaster m;//怎么能是狗中有人呢？？
    *       };
    *   过得去的写法.
    *       class CMaster;//CMsater必须提前声明，不能先写CMaster后写CDog
    *       class CDog
    *       {
    *           CMaster *pm;
    *       };
    *       class CMaster
    *       {
    *           CDog dogs[10];//人中有🐶，不满足复合关系啊
    *           //而且访问狗得通过主人类
    *       };
    *   正确方法：
    *       class CMaster;
    *       class CDog
    *       {
    *           CMaster *pm;//为狗类设置一个指向业主的指针
    *       };
    *       class CMaster
    *       {
    *           CDog *dogs[10];//为业主类设置一个指向狗的指针数组
    *       };
*/
class CPoint
{
    double x,y;
    friend class CCircle;//使CCircle类可以操作圆心
};
class CCircle
{
    double r;
    CPoint center;
};