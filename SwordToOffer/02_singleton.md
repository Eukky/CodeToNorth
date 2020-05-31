# 02. 实现单例模式

实现单例模式

## 题解

保证该类只能拥有一个实例，实现方式有以下几种。

### C++

- 懒汉模式（线程不安全）

```cpp
class Singleton {
    public:
        static Singleton* Instance() {
            if(_instance == 0) {
                _instance = new Singleton();
            }
            return _instance;
        }
        static void DeleteInstance() {
            if(_instance != 0) {
                delete _instance;
                _instance = 0;
            }
        }
    protected:
        Singleton() {}  //将构造函数声明在protected中防止外界对其进行访问，并确保子类能够访问
    private:
        static Singleton* _instance;
};
```

- 懒汉模式加锁（线程安全）

```cpp
class Singleton {
    public:
        static Singleton* Instance() {
            if(_instance == 0) {
                std::unique_lock<std::mutex> lock(_mutex);  //加锁
                if(_instance == 0) {
                    _instance = new Singleton();
                }
            }
            return _instance;
        }
        static void DeleteInstance() {
            std::unique_lock<std::mutex> lock(_mutex);  //加锁
            if(_instance != 0) {
                delete _instance;
                _instance = 0;
            }
        }
    protected:
        Singleton() {}  //将构造函数声明在protected中防止外界对其进行访问，并确保子类能够访问
    private:
        static Singleton* _instance;
        static std::mutex _mutex;
};
```

- 静态成员变量实现单例（线程安全）

```cpp
class Singleton {
    public:
        static Singleton& Instance() {
            static MazeFactory instance;
            return instance;
        }
    protected:
        Singleton() {}  //将构造函数声明在protected中防止外界对其进行访问，并确保子类能够访问
};
```

- 饿汉模式

```cpp
MazeFactory* MazeFactory::_instance = new MazeFactory();

class Singleton {
    public:
        static Singleton* Instance() {
            return _instance;
        }
        static void DeleteInstance() {
            if(_instance != 0) {
            delete _instance;
            _instance = 0;
    }
        }
    protected:
        Singleton() {}  //将构造函数声明在protected中防止外界对其进行访问，并确保子类能够访问
    private:
        static Singleton* _instance;
};
```
