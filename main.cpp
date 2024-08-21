#include <iostream>

#include "log/IrisLog.h"
using namespace IrisLog;

class Test {
public:
    int x,y,z;
    bool change(int a, int b , int c) {
        x = a;
        y = b;
        z = c;
        return true;
    }

};

IrisLog::Logger logger;


int main() {

    logger.setLevel(LogLevel::Debug);

    logger.info("Hello World!");
}




