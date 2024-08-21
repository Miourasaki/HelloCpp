#include <iostream>
#include <cstring>

#include "lib/IrisLog/IrisLog.h"
#include "main.h"

using namespace IrisLog;

IrisLog::Logger logger(
        LogLevel::ALL,
        LogOutputTime::DataTime,
        true,
        true
);


int main(int argc, char *argv[])
{
    logger.optionUseArgv(argc, argv);
    int out = 0;
    for (int i = 0; i < argc; i++)
    {
        if (i == 0) continue;
        if (i == 1) out = argv[i][0] - 48;
    }


    logger.debug("Hello IrisLog! 你好 鸢尾日志！\n");

    std::cout << "😆👉  Please choice project with ProjectCODEID list ↓" << std::endl;
    std::cout << "\t\tHelloWorld\t -> 0" << std::endl;
    std::cout << "\t\tChernoCpp\t -> 1" << std::endl;

    if (!out) std::cin >> out;
    std::cout << std::endl << std::endl ;
    switch (out)
    {
        default:
        case 0:
            helloWorld();
            break;
        case 1:
            ChernoCpp();
            break;
    }

}



