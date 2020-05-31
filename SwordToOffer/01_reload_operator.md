# 01. 赋值运算符函数

如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

```cpp
class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
　　 ~CMyString(void);

private:
　　 char* m_pData;
};
```

## 题解

传一个临时参数tmp,然后将tmp的m_pData值与this指针指向的值进行交换，就实现了运算符的重载。
注：tmp出了作用域会自动调用析构函数释放，所以当tmp区域与this指向的为同一区域时，tmp释放，则this指针指向的区域也释放了，就会出现问题，所以需要加上条件(this!=&str)。

### C++

```cpp
CMyString& CMyString::operator=(const CMyString& str)
{
　　　if (this != &str)
　　　{
　　　　CMyString temp(str);

　　　　char* data = temp.m_pData;
　　　　temp.m_pData = this->m_pData;
　　　　this->m_pData = data;
  　　}
　　  return *this;
}
```
