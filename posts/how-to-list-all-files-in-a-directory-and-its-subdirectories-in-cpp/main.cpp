/**
 * @file main.cpp
 *
 * @brief This program prints all files in a directory
 * and all its subdirectories. It takes one input argument,
 * which is the path to iterate through. The program checks
 * that a path is provided, and that that path exists.
 *
 * @author addictivesynthesis.com
 * Contact: info@addictivesynthesis.com
 *
 */

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Error: path is missing.\n";
        return 1;
    }

    const fs::path path { argv[1] };
    if (!fs::exists(path)) {
        std::cout << "Error: path does not exist.\n";
        return 1;
    }

    const fs::directory_options directory_options { fs::directory_options::skip_permission_denied };
    const fs::recursive_directory_iterator directory_iterator { path, directory_options };

    for(const fs::directory_entry& entry: directory_iterator) {
        if (entry.is_regular_file()) {
            std::cout << entry << "\n";
        }
    }
    
    return 0;
}