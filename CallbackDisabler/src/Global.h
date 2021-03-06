#pragma once

#ifndef GLOBAL_H
#define GLOBAL_H



#define kprintf(FORMAT, ...)				DbgPrintEx(77, 0, FORMAT, __VA_ARGS__)

#define DeviceName							L"\\Device\\RTKT00"
#define DosDeviceName						L"\\DosDevices\\RTKT00"

#define CTL_GET_DRIVERINFO					CTL_CODE(FILE_DEVICE_UNKNOWN, 0x701, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define CTL_DISABLE_OB_CALLBACKS			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x702, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define CTL_RESTORE_OB_CALLBACKS			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x703, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define CTL_DISABLE_IMAGE_CALLBACK			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x704, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define CTL_DISABLE_PROCESS_CALLBACK		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x705, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define CTL_DISABLE_THREAD_CALLBACK			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x706, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

typedef struct _Module
{
	UINT64 Base, Size;
}Module, *PModule;

typedef struct _DRIVERNAME
{
	wchar_t Name[32];
}DRIVERNAME, *PDRIVERNAME;

typedef struct _DYNDATA
{
	UINT64 CallbackListOffset;

}DYNDATA, *PDYNDATA;

extern DYNDATA g_DynData;
extern Module DriverInfo;
extern PDRIVER_OBJECT g_pDriverObject;


#endif // !GLOBAL_H