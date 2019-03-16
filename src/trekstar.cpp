#include <iostream>

int main()
{
    std::cout << "Welcome to TrekStar Management System | Console" << std::endl;

    std::string command = "";

    while ( command != "q" && command != "quit" )
    {
        std::cout << "Available commands: " << std::endl;
        std::cout << " - list projects (or lsp)" << std::endl;
        std::cout << " - quit          (or q)" << std::endl;

        std::cin >> command;
    }

    return 0;
}
