#include "file/fileOperations.cpp"
#include "information/listInformation.h"
#include "information/addInformation.h"
#include "information/saveInformation.h"

int main()
{
    std::vector<TrekStar::Project::Project> projects = TrekStar::File::importProjects("../../data/data.json");

    std::cout << "Welcome to TrekStar Management System | Console" << std::endl;
    std::cout << std::endl;
    std::cout << "Type 'help' to see all available commands" << std::endl;

    std::string command = "";
    while ( command != "q" && command != "quit" )
    {
        std::cout << std::endl;
        std::cout << "> ";
        std::getline(std::cin, command);

        std::string::size_type pos = command.find(' ');

        if ( command.substr(0, pos) == "help" )
        {
            std::cout << "Available commands: " << std::endl;
            std::cout << " list projects  - lsp" << std::endl;
            std::cout << " list materials - lsm [project number]" << std::endl;
            std::cout << " add project    - addp [project title]" << std::endl;
            std::cout << " save all data  - save" << std::endl;
            std::cout << " quit           - q" << std::endl;
        }
        else if ( command.substr(0, pos) == "lsp" )
        {
            TrekStar::Information::listProjects(projects);
        }
        else if ( command.substr(0, pos) == "lsm" )
        {
            TrekStar::Information::listMaterials(projects, command.substr(pos + 1));
        }
        else if ( command.substr(0, pos) == "addp" )
        {
            TrekStar::Information::addProject(projects, command.substr(pos + 1));
        }
        else if ( command.substr(0, pos) == "save" )
        {
            TrekStar::Information::save(projects, "../../data/saveData.json");
        }
    }

    return 0;
}
