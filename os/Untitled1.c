#include <stdio.h>
#include <windows.h>
int main(void) { 
	STARTUPINFO si; 
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si)); 
	si.cb=sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(NULL,"c:\\WINDOWS\\system32\\mspaint.exe",NULL,NULL,FALSE,0,NULL,NULL, &si, &pi)){ 
		fprintf(stderr,"create fail"); return -1; 
	}
	if (!CreateProcess(NULL,"c:\\WINDOWS\\system32\\notepad.exe",NULL,NULL,FALSE,0,NULL,NULL, &si, &pi)){ 
		fprintf(stderr,"create fail"); return -1; 
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child complete"); 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
 }

