#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

int main() {
    if (!filesystem::exists(std::filesystem::path("."))) {
        cerr << "Error: File system not supported" << endl;
        return 1;
    }

    string folderName;

    cout << "Name folder: ";
    getline(cin, folderName);

    try {
        if (filesystem::create_directory(folderName)) {
            cout << "Folder '" << folderName << "' successfully created" << endl;
        } else {
            cout << "Folder '" << folderName << "' already exists" << endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        cerr << "Error creating folder: " << e.what() << endl;
        return 1;
    }

    return 0;
}
