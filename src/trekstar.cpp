#include <iostream>
#include <fstream>
#include <vector>

#include "file/fileOperations.cpp"

int main()
{
    std::vector<std::string> files;
    files = read_directory("/Users/Matt/Documents/School/NTU/OneDrive - Nottingham Trent University/Year 2/SOFT20091 Software Design & Implementation/Assessment/Coursework Assignment/sdi-project/src/data");
    std::cout << files[2] << std::endl;

    std::ifstream dataFile ("data.txt");

    if ( ! isFileOpen(dataFile) )
    {
        std::cout << "Error: File not found." << std::endl;
        return 1;
    }

    if ( ! isFileOkay(dataFile) )
    {
        std::cout << "Error: There was an error reading the file, it may be corrupted." << std::endl;
        return 1;
    }

    //std::vector<Project> projects;

    std::cout << "Welcome to TrekStar Management System | Console" << std::endl;

    std::string command = "";

    while ( command != "q" && command != "quit" )
    {
        std::cout << "Available commands: " << std::endl;
        std::cout << " list projects - lsp" << std::endl;
        std::cout << " quit          - q" << std::endl;

        std::cout << "> ";
        std::cin >> command;
    }

    return 0;
}
