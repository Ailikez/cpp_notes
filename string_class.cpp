/* string类使用方式介绍 */
/*
 * string类是一个模板类，他的定义如下
 *  typedef basic_string<char> string;
 * 使用string类主要包含头文件<string>
 * string对象初始化：
 *  - string s1("hello");
 *  - string s2(8, 'x');//调用俩参数的构造函数
 *  - string month = "March";
 *  不可以提供字符和整数为参数的构造函数
 *  错误初始化：
 *      string err1 = 'c';
 *      string err2('u');
 *      string err3 = 22;
 *      string err4(8);
 * 可以将字符赋值给string
 *  string s; s= 'n';
 * 构造的string太长而无法表达，则会抛出length_error异常
 * string对象的长度用成员函数length()读取：
 *  string s("hello");
 *  cout << s.length() << endl;
 * string支持流运算符，如 cin >> stringObj;
 * string支持getline函数，如 string s; getline(cin, s);
 * string的赋值和连接
 *  - 用'='赋值，string s1("cat"), s2; s2 = s1;
 *  - 用assign成员函数复制，string s1("cat"), s3; s3.assign(s1);
 *  - 用assign成员函数部分复制，string s1("cat pig"), s3; s3.assign(s1, 1, 3);//从下表为1复制三个字符到s3
 *  - 单个字符复制，s2[5] = s1[3] = 'a';
 *  - at()逐个访问string对象中的字符
 *      string s1("Hello");
 *      for(int i = 0; i < s1.length(); i++)
 *          cout << s1.at(i) << endl;
 *          //成员函数at()会做范围检查，如果超出范围会抛出out_of_range异常，下标运算符是不做范围检查的
 *  - 用'+'运算符连接字符串
 *      string s1("good"), s2("morning!");
 *      s1 += s2; cout << s1;
 *  - 用成员函数append连接字符串
 *      string s1("Good"), s2("morning!");
 *      s1.append(s2); cout << s1;
 *      s2.append(s1, 3, s1.size());//s1.size是s1的字符总数
 *      cout << s2;//下标为3开始，s1.size()个字符
 *      //如u过字符串内没有足够的字符，则复制到字符串最后一个字符
 * string比较
 *  - 用关系运算符比较string的大小
 *      - ==, >, >=, <, <=, !=
 *      - 返回值都是bool类型，成立返回true，否则返回false
 *      - 例如：
 *          string s1("Hello"), s2("Hello"), s3("Hell");
 *          bool b = (s1 == s2);
 *          cout << b << endl;
 *          b = (s1 == s3);//false
 *          cout << b <<endl;
 *          b = (s1 > s3);
 *          cout << b << endl;
 * 子串
 *  - 成员函数substr()
 *      string s1("hello world"), s2;
 *      s2 = s1.substr(4, 5);//下标4开始5个字符
 *      cout << s2 << endl;//"o wor"
 * 成员函数find()
 *  string s1("hello world");
 *  s1.find("lo");
 *  //在s1中 从前向后 查找"lo"第一次出现的位置
 *  //如果找到，返回"lo"开始的位置，即l所在的位置下标
 *  //没找到的话，返回string::npos(string中的静态常量)
 * 成员函数rfind()
 *  string s1("hello world");
 *  s1.rfind("lo");//从后向前找
 * 成员函数 find_first_of()
 *  s1.find_first_of("abcd");
 *  //从s1中从前向后查找"abcd"中 任意 一个字符 第一次 出现的地方
 *  //找到返回位置，找不到返回npos
 * 成员函数 find_last_of()
 *  s1.find_last_of("abcd");
 *  //从s1中从后向前查找"abcd"中 任意 一个字符 第一次 出现的地方
 *  //找到返回位置，找不到返回npos
 * 成员函数 find_first_not_of()
 *  s1.find_first_not_of("abcd");
 *  //在s1中从前向后查找 不包含在"abcd"中的字母 第一次 出现的地方
 * 成员函数 find_last_not_of()
 *  s1.find_last_not_of("abcd");
 *  //在s1中从后向前查找 不包含在"abcd"中的字母 第一次 出现的地方
 * 替换string中的字符
 *  - 成员函数erase()
 *      string s1("hello world");
 *      s1.erase(5);//去掉下标5之后的字符
 *      cout << s1 << s1.length() << s1.size();//hello55
 *  - 成员函数find()
 *      string s1("hello world");
 *      cout << s1.find("ll", 1) << endl;//从下标1开始查找,输出2
 *  - 成员函数replace()
 *      string s1("hello world");
 *      s1.replace(2, 3, "haha");//从下标2开始的3个字符 替换成"haha"
 *      cout << s1;//输出hehaha world
 *      s1 = "hello world";
 *      s1.replace(2, 3, "haha", 1, 2);//从下标2开始的3个字符 替换成"haha"中下标1开始的2个字符
 *      cout << s1;//输出heah world
 * 在字符串中插入字符
 *  - 成员函数insert()
 *      string s1("hello world");
 *      string s2("show insert");
 *      s1.insert(5, s2);//将s2插入到下标5的位置
 *      cout << s1 << endl;//输出helloshow insert world
 *      s1.insert(2, s2, 5, 3);//将s2中下标5开始的3个字符插入到s1中下标2的位置
 *      cout << s1 << endl;//输出heinslloshow insert world
 * 转换成c语言中char*字符串
 *  - 成员函数c_str()
 *      string s1("hello world");
 *      printf("%s\n", s1.c_str());
 *      //c_str()返回传统的const char *类型字符串
 *      //该字符串以'\0'结尾
 * */