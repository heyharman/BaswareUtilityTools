#include <windows.h>
#include <string>

// Plugin name
const wchar_t pluginName[] = L"Basware Utility Tools";

// Simple message box (About)
void showAbout() {
    MessageBox(NULL, L"Basware Utility Tools v1.0\nCreated for Basware XML/JSON handling",
               pluginName, MB_OK);
}

// Required plugin functions (basic skeleton)

extern "C" __declspec(dllexport) void setInfo(void* data) {}
extern "C" __declspec(dllexport) const wchar_t* getName() { return pluginName; }
extern "C" __declspec(dllexport) int getFuncsArray(void** arr) { return 0; }
extern "C" __declspec(dllexport) void beNotified(void* notifyCode) {}
extern "C" __declspec(dllexport) LRESULT messageProc(UINT Message, WPARAM wParam, LPARAM lParam) { return TRUE; }
extern "C" __declspec(dllexport) BOOL isUnicode() { return TRUE; }

// Entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved) {
    return TRUE;
}
