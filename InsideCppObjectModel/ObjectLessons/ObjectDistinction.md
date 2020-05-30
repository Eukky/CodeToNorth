# 对象的差异

`C++`程序设计模型直接支持3中程序设计范式。

1. 程序模型`(procedural model)`

   这个模型和`C`一样，例如字符串处理程序，可以使用字符数组和`C`函数库中的`str*`函数族群。

   ```cpp
   char boy[] = "Danny";
   char *p_son;

   p_son = new char[strlen(boy) + 1];
   strcpy(p_son, boy);

   if(!strcmp(p_son, boy)){
       take_to_disneyland(boy);
   }
   ```

2. 抽象数据类型模型`(abstract data type model)`

   这个模型所谓的抽象是和一组表达式一起提供的，那时其运算定义仍然隐而未明。

   ```cpp
   String girl = "Anna";
   String daughter;

   //String::operator=();
   daughter = girl;

   //String::operator==();
   if(girl == daughter){
       take_to_disneyland(girl);
   }
   ```

3. 面向对象模型`(object-oriented model)`

   这个模型中有一些彼此相关的类型，通过一个抽象的基类被封装起来。

   ```cpp
   //Library_materials可以包含Book, Video, Laptop等子类
   void check_in(Library_materials *pmat){
       if(pmat->late()){
           pmat->fine();
       }
       pmat->check_in();
       if(Lender *plend = pmat->reserved()){
           pmat->notify(plend);
       }
   }
   ```

纯粹以一种范式来编写程序有助于整体行为的良好稳固。如果混用了多种不同的范式，在没有谨慎处理的情况下可能会发生一些难以预料的后果，例如在实现多态时并没有使用指针或者引用导致对象被裁切而无法完成多态的实现。

```cpp
//class Book : public Library_materials();
Book book;

//导致book被裁切
Library_material thing1;
thing1 = book;

//将thing2参考到book，调用Book::check_in()
Library_material& thing2 = book;
thing2.check_in();
```

在`C++`中，多态值存在与一个个`public class`体系中。`Nonpublic`的派生行为以及`void*`的指针可以说是多态的，但是并没有被语言明确的支持，必须由程序员通过显示的转换操作来管理。

`C++`能够以下列方法支持多态：

1. 经由一组隐式的转化操作。例如把一个派生类指针转化为一个指向基类的指针。

   ```cpp
   shape *ps = new circle();
   ```

2. 经由虚函数的机制。

   ```cpp
   ps->rotate();
   ```

3. 经由`dynamaic_cast`和`typeid`运算符。

   ```cpp
   if(circle *pc = dynamic_cast<circle*>(ps))
   ```

多态的主要用途是经由一个共同的接口来影响类型的封装，这个接口通常被定义在一个抽象的基类中。这个共享接口由虚函数的机制引发，它可以在执行期间根据对象的真正类型来解析出到底是哪一个函数实例被调用。

一般而言，一个类对象所需要的内存由一下三部分组成：

1. 非静态成员变量的总和大小。
2. 任何由于对其的需求而填补的空间。
3. 为了支持虚函数而内部产生的额外负担。

但是一个指针，不管指向哪一种数据类型，指针本身的大小是固定的。

## 指针的类型

以内存需求的观点来说，不同类型的指针并没有什么不同。它们都需要足够的内存来放置一个机器地址。指向不同类型的指针之间的差异，体现在其所寻址出来的对象类型的不同。指针的类型会教导编译器如何去解释某个特定地址中的内存内容及其大小。

一个指向地址`1000`的整数指针，在`32`位的机器上将涵盖地址空间`1000～1003`。

如果是一个指向对象的指针，将横跨这个对象所拥有的整个地址空间。

如果是一个指向地址`1000`而类型为`void*`的指针，无法得知将涵盖怎样的地址空间。因此`void*`的指针只能够持有一个地址，而无法通过它操作所指的对象。

## 加上多态

```cpp
//所需存储空间为 4+8+4=16
class ZooAnimal {
public:
    ZooAnimal();
    virtual ~ZooAnimal();

    virtual void rotate();
protected:
    int loc; //4bytes
    String name; //8bytes
    // __vptr__ZooAnimal 4bytes
};

//所需空间为 16+4+4=24
class Bear : public ZooAnimal {
public:
    Bear();
    virtual ~Bear();

    void rotate();
    virtual void dance();
protected:
    enum Dances {...};
    Dances dances_known; //4bytes
    int cell_block; //4bytes
};

Bear b("Yogi");
ZooAnimal *pz = &b; //指向一个Bear对象，但是只包含其中的ZooAnimal subobject
Bear *pb = &b; //指向一个Bear对象，包含整个Bear object
Bear &rb = *pb;
```

`Bear`的三个实例`b, pb, rb`，其中无论是指针还是引用，都只需要一个字的空间，而`Bear`对象则需要`24bytes`，也就是`ZooAnimal`的`16bytes`加上`Bear`所带来的`8bytes`。

除了在`ZooAnimal subobject`中出现的成员，无法使用`pz`来直接处理`Bear`的任何成员，唯一的例外是通过虚函数来进行。

```cpp
pz->cell_block; //不合法，cell_block不是ZooAnimal的成员

(static_cast<Bear*>(pz))->cell_block; //合法，经过显式类型转换

if(Bear* pb2 = dynamic_cast<Bear*>(pz)){
    pb2->cell_block; //合法，是一个runtime operation，成本较高
}

pb->cell_block; //合法，cell_block是Bear的成员
```

如果将一个基类对象直接初始化为一个派生类对象，派生类对象就会被切割以塞入较小的基类对象的内存中，因此将失去派生类的特性，导致多态不再被呈现。一个指针或引用之所以支持多态，是因为它们并不引发内存中任何与类型有关的内存委托操作，会受到改变的，只有它们所指向的饿内存的大小和解释内容方式而已。因此在`C++`中，通过`class`的指针和引用来支持多态，这样的程序设计风格被称为面向对象。
