#ifndef _KFORGE_LIBRARY_H_
#define _KFORGE_LIBRARY_H_

// max arguments for KfCall(): 4 over the registers and 9 over the stack
#define MAX_ARGS (4 + 9)

// convert KfCall() call arguments
#define KF_ARG(_val_) ((PVOID)(_val_))

// convert KfCall() return value
#define KF_RET(_val_) ((PVOID *)(_val_))

#ifdef __cplusplus

extern "C"
{

#endif

BOOL KfGetSyscallNumber(char *lpszProcName, PDWORD pdwRet);
PVOID KfGetKernelProcAddress(char *lpszProcName);
PVOID KfGetKernelZwProcAddress(char *lpszProcName);

BOOL KfInit(void);
BOOL KfUninit(void);

BOOL KfCall(char *lpszName, PVOID *Args, DWORD dwArgsCount, PVOID *pRetVal);
BOOL KfCallAddr(PVOID FuncAddr, PVOID *Args, DWORD dwArgsCount, PVOID *pRetVal);

PVOID KfMemCopy(PVOID Dst, PVOID Src, DWORD Size);

PVOID KfHeapAlloc(DWORD Size);
PVOID KfHeapAllocData(DWORD Size, PVOID Data);
BOOL KfHeapFree(PVOID Addr);

#ifdef __cplusplus

}

#endif
#endif