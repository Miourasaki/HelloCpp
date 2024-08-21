#include <thread>

#include "../lib/IrisLog/IrisLog.h"

extern IrisLog::Logger logger;

void ChernoCpp()
{
    logger.info("Hello World!");
}