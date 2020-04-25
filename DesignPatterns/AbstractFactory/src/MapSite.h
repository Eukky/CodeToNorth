//定义方向和魔法
enum Direction {North, Sorth, East, West};
enum Power {IcePower, FirePower};

//Room和Wall和Door的基础类
//声明Enter()函数
class MapSite {
    public:
        virtual void Enter() = 0;
};