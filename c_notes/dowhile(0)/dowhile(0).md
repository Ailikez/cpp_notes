# do{...}while(0)的意义和用法

>  On October 9, 2012, in C语言, 语言学习, by sponge
>
> http://www.spongeliu.com/

linux内核和其他一些开源的代码中，经常会遇到这样的代码：

```c
do{
 ...
}while(0)
```

这样的代码一看就不是一个循环，do..while 表面上在这里一点意义都没有，那么为什么要这么用呢？

实际上，do{...}while(0) 的作用远大于美化你的代码。查了些资料，总结起来这样写主要有以下几点好处：

**1、辅助定义复杂的宏，避免引用的时候出错：**

举例来说，假设你需要定义这样一个宏：

```c
#define DOSOMETHING()\
           foo1();\
           foo2();
```
这个宏的本意是，当调用 DOSOMETHING() 时，函数 foo1() 和 foo2() 都会被调用。

但是如果你在调用的时候这么写：

```c
if(a>0)
    DOSOMETHING();
```


因为宏在预处理的时候会直接被展开，你实际上写的代码是这个样子的：

```c
if(a>0)
    foo1();
	foo2();
```


这就出现了问题，因为无论a是否大于0，foo2()都会被执行，导致程序出错。那么仅仅使用 {} 将 foo1() 和 foo2() 包起来行么？我们在写代码的时候都习惯在语句右面加上分号，如果在宏中使用 {}，代码里就相当于这样写了：“{...};”，展开后就是这个样子：

```c++
if(a>0)
{
    foo1();
    foo2();
};
```


这样甚至不会编译通过。所以，很多人才采用了`do{...}while(0);`

```c
#define DOSOMETHING() \
do{ \
	foo1();\
	foo2();\
}while(0)
```

```c
if(a>0)
    DOSOMETHING();
```

这样，宏被展开后，才会保留初始的语义。GCC 提供了 Statement-Expressions 用以替代 `do{...}while(0);` 所以你也可以这样定义宏：

```c
#define DOSOMETHING() ({\
	foo1(); \
    foo2(); \
})
```
**2、避免使用goto对程序流进行统一的控制：**

有些函数中，在函数return之前我们经常会进行一些收尾的工作，比如free掉一块函数开始malloc的内存，goto一直都是一个比较简便的方法：

```c
int foo()
{
    somestruct* ptr = malloc(...);
    dosomething...;
    if(error)
    {
        goto END;
    }

    dosomething...;
    if(error)
    {
        goto END;
    }
    dosomething...;
    END:
    free(ptr);
    return 0;
}
```


由于 goto 不符合软件工程的结构化，而且有可能使得代码难懂，所以很多人都不倡导使用，那这个时候就可以用 do{}while(0) 来进行统一的管理：

```c
int foo()
{
    somestruct* ptr = malloc(...);

    do{
        dosomething...;
        if(error)
        {
            break;
        }

        dosomething...;
        if(error)
        {
            break;
        }
        dosomething...;
    }while(0);

    free(ptr);
    return 0;
}
```


这里将函数主体使用 do()while(0) 包含起来，使用 break 来代替 goto，后续的处理工作在 while 之后，就能够达到同样的效果。

 **3、避免空宏引起的 warning**

内核中由于不同架构的限制，很多时候会用到空宏，在编译的时候，空宏会给出warning，为了避免这样的warning，就可以使用do{}while(0)来定义空宏：`#define EMPTYMICRO do{}while(0)`

**4、定义一个单独的函数块来实现复杂的操作：**

当你的功能很复杂，变量很多你又不愿意增加一个函数的时候，使用do{}while(0);，将你的代码写在里面，里面可以定义变量而不用考虑变量名会同函数之前或者之后的重复。