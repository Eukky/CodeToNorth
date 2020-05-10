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
