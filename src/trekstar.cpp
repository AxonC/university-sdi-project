#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include "file/fileOperations.cpp"
#include "listInformation.cpp"
#include "addInformation.cpp"
#include "saveInformation.cpp"

int main()
{
    std::string fileDirectory = boost::filesystem::current_path().parent_path().parent_path().string() + "/data/";

    std::vector<TrekStar::Project::Project> projects = TrekStar::File::importProjects(fileDirectory + "data.json");

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
            listProjects(projects);
        }
        else if ( command.substr(0, pos) == "lsm" )
        {
            listMaterials(projects, command.substr(pos + 1));
        }
        else if ( command.substr(0, pos) == "addp" )
        {
            addProject(projects, command.substr(pos + 1));
        }
        else if ( command.substr(0, pos) == "save" )
        {
            save(projects, fileDirectory + "saveData.json");
        }
    }

    return 0;
}
