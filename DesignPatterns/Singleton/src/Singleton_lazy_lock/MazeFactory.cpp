#include "MazeFactory.h"

MazeFactory* MazeFactory::_instance = 0;
std::mutex MazeFactory::_mutex;

MazeFactory* MazeFactory::Instance() {
    //使用两个if判断语句的双检锁，只有判断指针为空时才加锁
    //避免每次调用都加锁
    if(_instance == 0) {
        std::unique_lock<std::mutex> lock(_mutex);  //加锁
        if(_instance == 0) {
            _instance = new MazeFactory();
        }
    }
    return _instance;
}

void MazeFactory::DeleteInstance() {
    std::unique_lock<std::mutex> lock(_mutex);  //加锁
    if(_instance != 0) {
        delete _instance;
        _instance = 0;
    }
}