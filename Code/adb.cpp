#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    std::string adb_path = "C:\\path\\to\\adb.exe"; // Replace with the actual path to your adb.exe

    // Construct the ADB command
    std::string command = adb_path + " devices";

    // Execute the command
    system(command.c_str());

    return 0;
}
