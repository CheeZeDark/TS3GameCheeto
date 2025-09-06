#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
typedef bool(WINAPI* World_SetTestingCheatsEnabledImpl_t)();
namespace TS3_Offset {
    uintptr_t GetMod() {
        return (uintptr_t)GetModuleHandleA("TS3W.exe");
    }
    uintptr_t ts3_settestcheat = GetMod() + 0x01162C04; //Our Real .data Offset
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
