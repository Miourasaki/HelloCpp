#include <iostream>

#include "../lib/IrisLog/IrisLog.h"

extern IrisLog::Logger logger;


class Vector2 {
public:
    float x,y;
    Vector2(float a,float b): x(a), y(b) {};

    Vector2 operator+(const Vector2& v2) const {
        const Vector2& v1 = *this;
        return {
            v1.x + v2.x,
            v1.y + v2.y
        };
    }

};


void ChernoCpp()
{
    logger.info("Hello World!");
    Vector2 v1(1,1);
    Vector2 v2(1,1);

    Vector2 v3 = v1 + v2;
    std::cout << v3.x << "," << v3.y << std::endl;
}