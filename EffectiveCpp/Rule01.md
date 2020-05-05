# 视C++为一个语言联邦

C++可以看作由4个次语言组成的语言联邦。

- C：C++以C为基础。区块，语句，预处理，内置数据类型，数组，指针等概念都来自与C，许多时候C++对问题的解法不过是较高级的C的解法。。当C++以C的成分工作时，高效编程守则映照出C语言的局限：没有模板，没有异常，没有重载等。

- Object-Oriented C++：这部分也是C with Classes所诉求的：类，封装，继承，多态，虚函数等，这一部分是面向对象设计在C++上最直接的实施。

- Template C++：C++范型编程，也是大多数程序员经验最少的部分。模板相关的考虑已经弥漫整个C++，它威力强大，能够带来称之为模板元编程的崭新编程范型。但是模版元编程相关的规则很少影响C++主流编程。

- STL：STL是C++的标准模版库。它对容器，迭代器，算法，以及函数对象的规约由极佳的紧密配合和协调。STL有自己特殊的办事方式，当使用STL工作时必须遵守它的规约。