# 关键词所带来的差异

## struct与class的区别

如果一个`object`同时被声明为`static`和`extern`，则会产生不一致的错误的语言用法，但是`class`和`struct`并不会出现这样的错误。`class`的真正特性由声明本身来决定。对于`class`和`struct`而言，这样的不一致性错误，只是一种风格上的问题。

```cpp
//这两个声明会造成矛盾的存储空间
static int foo;
extern int foo;
```

## 策略性正确的struct

如果把单一元素的数组放在一个`struct`的尾端，则每个`struct object`可以拥有一个可变大小的数组。通过对`struct`本身和该字符串配置足够的内存，可以改变该数组的大小。

```cpp
struct mumble {
    /* stuff */
    char pc[1];
};

//从文件或标准装置取得一个字符串
//为struct本身和该字符串配置足够的内存

struct mumble *pmumb1 =  (struct mumble *)malloc(sizeof(struct mumble) + strlen(string) + 1);
strcpy(&mumble.pc, string);
```

如果将这个`struct`改用`class`来声明，而该`class`符合下列条件：

- 指定多个`access sections`，内涵数据
- 从另一个`class`派生而来
- 定义了一个或多个`virtual functions`

则该`struct`不一定能够顺利转化为`class`。

```cpp
class stumble {
public:
    // operations...
protected:
    //protected stuff
private:
    /* private stuff */
    char pc[1];
};
```

只有当`protected data`被放在`private data members`的前面，上述`struct`的操作才能够有效运行。同理，基类和派生类的`data members`的布局也没有强制规定，虚函数的存在也会使该操作的有效性成为一个问号，因此最好不要再`class`当中进行这种操作。

`C struct`在`C++`中的一个合理用途是，当需要传递一个复杂的`class object`中的全部或者某个部分到C函数中去，可以使用`struct`声明将数据封装起来，并保证拥有与`C`兼容的空间局。但是这项保证只能在组合的情况下存在，如果是继承而不是组合，编译器会决定是否应该由额外的`data members`被安插到`base stuct subobject`当中。
