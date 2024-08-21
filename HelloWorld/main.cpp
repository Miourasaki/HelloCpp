#include <thread>
#include <chrono>

#include "../lib/IrisLog/IrisLog.h"

extern IrisLog::Logger logger;

void helloWorld()
{
    for (int i = 0 ; i < 10; i++)
    {
        logger.trace("Hello World!");
        logger.debug("Hello World!");
        logger.info("Hello World!");
        logger.warn("Hello World!");
        logger.error("Hello World!");
        logger.fatal("Hello World!");
        std::this_thread::sleep_for(std::chrono::seconds (1)); // 暂停 5 秒
    }
}