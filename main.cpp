#include <process.h>

#ifdef _WIN32

#include "win/trigger_datetime_update.h"

#endif

void trigger_time_update_process();

int main() {
    trigger_time_update_process();
}
