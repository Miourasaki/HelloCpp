#include <thread>
#include <chrono>

#include "../lib/IrisLog/IrisLog.h"

extern IrisLog::Logger logger;

void helloWorld()
{
    for (int i = 0 ; i < 10; i++)
    {
        logger.debug("Hello World!");
        std::this_thread::sleep_for(std::chrono::seconds (1)); // 暂停 5 秒
    }
}