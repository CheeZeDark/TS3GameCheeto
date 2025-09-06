// dllmain.cpp : Defines the entry point for the DLL application.
#include "includes.hpp"

DWORD WINAPI Thread() {
    AllocateConsole();
    cout << "Welcome to my new Cheeto for The Sims 3... Created By CheeZeDark(Rikko Matsumato)" << endl;
    World_SetTestingCheatsEnabledImpl_t SetTestingCheats = *(World_SetTestingCheatsEnabledImpl_t*)TS3_Offset::ps3_settestcheat;
    SetTestingCheats(true);
    cout << "Success" << endl;
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

