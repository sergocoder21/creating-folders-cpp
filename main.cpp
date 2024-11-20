#include <iostream>
#include <filesystem>
#include <string>

int main() {
    if (!std::filesystem::exists(std::filesystem::path("."))) {
        std::cerr << "Error: File system not supported" << std::endl;
        return 1;
    }

    std::string folderName;

    std::cout << "Name folder: ";
    std::getline(std::cin, folderName);

    try {
        if (std::filesystem::create_directory(folderName)) {
            std::cout << "Folder '" << folderName << "' successfully created" << std::endl;
        } else {
            std::cout << "Folder '" << folderName << "' already exists" << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error creating folder: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}