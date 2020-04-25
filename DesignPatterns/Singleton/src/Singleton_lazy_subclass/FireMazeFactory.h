#include "MazeFactory.h"
#include <iostream>
class FireMazeFactory : public MazeFactory {
    friend class MazeFactory;  //将父类设为友元，确保父类能够访问该构造函数
    private:
        FireMazeFactory() {}  //外界无法访问该类的构造函数
        
};