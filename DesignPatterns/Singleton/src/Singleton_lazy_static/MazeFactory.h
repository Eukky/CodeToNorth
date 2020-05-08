#include <mutex>

class MazeFactory {
    public:
        static MazeFactory& Instance();
    protected:
        MazeFactory() {}  //将构造函数声明在protected中防止外界对其进行访问，并确保子类能够访问
};