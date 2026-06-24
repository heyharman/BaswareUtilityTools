#include <windows.h>

#define PLUGIN_NAME L"Basware Utility Tools"

struct NppData
{
    HWND _nppHandle;
    HWND _scintillaMainHandle;
    HWND _scintillaSecondHandle;
};

typedef void (*PFUNCPLUGINCMD)();

struct ShortcutKey
{
    bool _isCtrl;
    bool _isAlt;
    bool _isShift;
    unsigned char _key;
};

struct FuncItem
{
    wchar_t _itemName[64];
    PFUNCPLUGINCMD _pFunc;
    int _cmdID;
    bool _init2Check;
    ShortcutKey* _pShKey;
};

NppData nppData;
const int nbFunc = 1;
FuncItem funcItem[nbFunc];

void about()
{
    MessageBox(
        nppData._nppHandle,
        L"Basware Utility Tools v1.0\n\nFirst working plugin build.\nNext step: Add Pretty Print XML.",
        PLUGIN_NAME,
        MB_OK | MB_ICONINFORMATION
    );
}

void setCommand(int index, const wchar_t* itemName, PFUNCPLUGINCMD functionPointer)
{
    if (index >= nbFunc)
    {
        return;
    }

    lstrcpynW(funcItem[index]._itemName, itemName, 64);
    funcItem[index]._pFunc = functionPointer;
    funcItem[index]._cmdID = 0;
    funcItem[index]._init2Check = false;
    funcItem[index]._pShKey = NULL;
}

extern "C" __declspec(dllexport) void setInfo(NppData notepadPlusData)
{
    nppData = notepadPlusData;
    setCommand(0, L"About", about);
}

extern "C" __declspec(dllexport) const wchar_t* getName()
{
    return PLUGIN_NAME;
}

extern "C" __declspec(dllexport) FuncItem* getFuncsArray(int* nbF)
{
    *nbF = nbFunc;
    return funcItem;
}

extern "C" __declspec(dllexport) void beNotified(void* notifyCode)
{
}

extern "C" __declspec(dllexport) LRESULT messageProc(UINT Message, WPARAM wParam, LPARAM lParam)
{
    return TRUE;
}

extern "C" __declspec(dllexport) BOOL isUnicode()
{
    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reasonForCall, LPVOID reserved)
{
    return TRUE;
}
