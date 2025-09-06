#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
typedef bool(WINAPI* World_SetTestingCheatsEnabledImpl_t)(bool enabled);
namespace TS3_Offset {
    uintptr_t GetMod() {
        return (uintptr_t)GetModuleHandleA("TS3W.exe");
    }
    uintptr_t GetTestingCheat_FuncAddress() 
    {
        uintptr_t ts3_settestcheat = GetMod() + 0x787020; //Our Real .text Offset to Calling Function!!!
        return ts3_settestcheat;
    }
}
namespace MH {
#include <MinHook.h>
}

void AllocateConsole() {
    FILE* fp;
    AllocConsole();
    freopen_s(&fp, "CONOUT$", "w", stdout);
    SetConsoleTitleA("TS3GameCheeto by CheeZeDark(Rikko Matsumato)");
}
