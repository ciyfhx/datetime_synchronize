#include "trigger_datetime_update.h"

BOOL checkForUACPermission() {
    BOOL fRet = FALSE;
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_ELEVATION Elevation;
        DWORD cbSize = sizeof(TOKEN_ELEVATION);
        if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
            fRet = Elevation.TokenIsElevated;
        }
    }
    if (hToken) {
        CloseHandle(hToken);
    }
    return fRet;
}

void trigger_time_update_process() {
    if (checkForUACPermission()) {
        int result = system(TRIGGER_UPDATE_COMMAND);
        if (!result) {
            printf_s("%s", "Starting w32time service\n");
            //Start w32time service on windows
            system("net start w32time");
            //Rerun command
            trigger_time_update_process();
        }else{
            printf_s("%s", "Finished syncing datetime\n");
        }
    }else{
        printf_s("%s", "Unable to resync datetime due to lack of permission\n");
    }
}