#include <mutex>

class MazeFactory {
    public:
        static MazeFactory* Instance();
        static void DeleteInstance();
    protected:
        MazeFactory() {}  //将构造函数声明在protected中防止外界对其进行访问，并确保子类能够访问
    private:
        static MazeFactory* _instance;
        static std::mutex _mutex;
};