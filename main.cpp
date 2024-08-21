#include <iostream>
#include <cstring>

#include "lib/IrisLog/IrisLog.h"

using namespace IrisLog;

IrisLog::Logger logger(
        LogLevel::ALL,
        LogOutputTime::DataTime,
        true,
        true
);


int main(int argc, char *argv[])
{
    for (int i = 0; i < argc ; i++) {
        if (i == 0) continue;

        if (strcmp(argv[i],"--IrisLog.Option.UnColorful") == 0) {
            logger.setOutColorful(false);
        }

    }


    logger.debug("Hello IrisLog! 你好 鸢尾日志！");

    std::cout << "Please choice project with ProjectCODEID list ↓" << std::endl;
    std::cout << "\t\t\t\tHelloWorld -> 0" << std::endl;

}



