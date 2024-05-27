#include <Windows.h>
#include <intrin.h>
#include <iostream>
#include <tlhelp32.h>
#include <string>
#include <powrprof.h>

using namespace std;
void ListProcesses() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Bir i�lem g�r�nt�s� olu�tur
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        cout << "Error: Unable to create process snapshot!" << endl;
        return;
    }

    // Struct boyutunu ayarla
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // �lk i�lemi al
    if (!Process32First(hProcessSnap, &pe32)) {
        cout << "Error: Unable to retrieve process information!" << endl;
        CloseHandle(hProcessSnap);
        return;
    }

    // ��lemleri listele
    cout << "PID\tName" << endl;
    do {
        cout << pe32.th32ProcessID << "\t" << pe32.szExeFile << endl;
    } while (Process32Next(hProcessSnap, &pe32));

    // Kullan�lan kaynaklar� serbest b�rak
    CloseHandle(hProcessSnap);
}



bool TerminateProcessByID(DWORD processID) {
    // Belirtilen PID'ye sahip i�lemi a�
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);
    if (hProcess == NULL) {
        cout << "Error: Unable to open process with ID " << processID << endl;
        return false;
    }

    // ��lemi sonland�r
    if (!TerminateProcess(hProcess, 0)) {
        cout << "Error: Unable to terminate process with ID " << processID << endl;
        CloseHandle(hProcess);
        return false;
    }

    cout << "Process with ID " << processID << " terminated successfully." << endl;

    // Kullan�lan kaynaklar� serbest b�rak
    CloseHandle(hProcess);

    return true;
}




// Thread i�levi
DWORD WINAPI threadFunc(LPVOID lpParam) {
    int threadID = *((int*)lpParam);
    printf("Thread #%d calisiyor...\n", threadID);
    Sleep(3000); // 3 saniye uyku
    printf("Thread #%d tamamlandi.\n", threadID);
    return 0;
}







int main(){
	   int choice;

    do {
        // Men�y� yazd�r
        cout << "Please select an option:\n"
             << "1.Mesaj g�sterme                              2. Ayarlar� a�                       3. Bilgisayar� yeniden ba�lat\n"
             << "4.Bilgisayar� kapat                           5. i�lemleri  g�r�nt�leme            6. i�lem sonland�rma\n"
             << "7.                                         8. Hardware Settings             \n  9. Exit\n";

        cout << "Your Choice: ";
       
        cin >> choice;
        cout<<"\n";
        switch (choice) {
        
		
		
		
		
		
		     case 1:
              // MessageBox ile kullan�c�ya ileti g�sterme
    MessageBox(NULL, "Merhaba, bu bir MessageBox ileti penceresidir.", "Bilgi", MB_OK | MB_ICONINFORMATION);
     
   
                break;
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            case 2:
                cout << "Switching to Settings menu...\n";
                // Call the file management menu function here
                    // Ayarlara gitmek i�in ms-settings: URI'sini a�
    ShellExecute(NULL, "open", "ms-settings:", NULL, NULL, SW_SHOWNORMAL);
                break;
            
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			case 3:
                cout << "Bilgisayar� yeniden ba�lat...\n";
              
                 
    if (!ExitWindowsEx(EWX_REBOOT, 0)) {
        // Hata durumunda hata kodunu yazd�r
        DWORD dwError = GetLastError();
        printf("Bilgisayar yeniden baslatma hatasi: %lu\n", dwError);
        return 1;
    }

    printf("Bilgisayar yeniden baslatiliyor...\n");

                break;
           
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		    case 4:
                cout << "Switching to power management menu...\n";
                // Call the power management menu function here
                 // Bilgisayar� kapat
    if (!ExitWindowsEx(EWX_POWEROFF, 0)) {
        // Hata durumunda hata kodunu yazd�r
        DWORD dwError = GetLastError();
        printf("Bilgisayar kapatma hatasi: %lu\n", dwError);
        return 1;
    }

    printf("Bilgisayar kapatiliyor...\n");
                break;
          
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		    case 5:
                cout << "Switching to manage applications menu...\n";
                
    ListProcesses();

 
                break;
          
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		    case 6:
                cout << "Switching to system security menu...\n";
                // Call the system security menu function here
          DWORD processID;
    cout << "Enter the Process ID to terminate: ";
    cin >> processID;

    if (TerminateProcessByID(processID)) {
        cout << "Process terminated successfully." << endl;
    } else {
        cout << "Failed to terminate process." << endl;
    }


		
		        break;
          
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		    case 7:
      
	 
              
              
                break;
        
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		    case 8:
                cout << "Switching to hardware settings menu...\n";
                // Call the hardware settings menu function here
                break;
            case 9:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}






