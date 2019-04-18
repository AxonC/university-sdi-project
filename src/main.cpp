#include "command/CommandHandler.h"
#include "file/fileOperations.h"
#include "information/listInformation.h"
#include "information/addInformation.h"
#include "information/saveInformation.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>
#include <QIcon>
#include <QObject>
#include <QString>

#include "GUI/backend.h"

void runCommandLine()
{
    const std::string FILE_PATH = "../../data/data.json";

    std::vector<TrekStar::Project::Project> projects = TrekStar::File::importProjects(FILE_PATH);

    std::cout << "Welcome to TrekStar Management System | Console" << std::endl;
    std::cout << std::endl;
    std::cout << "Type 'help' to see all available commands" << std::endl;

    TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
            {
                    {"help", "view available commands"},
                    {"lsp",  "list projects"},
                    {"lsm",  "list materials"},
                    {"addp", "add project"},
                    {"save", "save all data to file"},
                    {"q",    "quit project"}
            }
    );

    std::string commandInput;
    while ( commandInput != "q" && commandInput != "quit" )
    {
        std::cout << std::endl;
        std::cout << "> ";
        std::getline(std::cin, commandInput);

        StringPair tokenisedCommand = commandHandler.tokeniseCommand(commandInput);

        if ( commandHandler.isValidCommand(tokenisedCommand.first) )
        {
            if ( tokenisedCommand.first == "help" )
            {
                std::cout << "Available commands: " << std::endl;

                for ( const auto & currentCommand : commandHandler.GetCommands() )
                {
                    std::cout << currentCommand.first << " - " << currentCommand.second << std::endl;
                }
            }
            else if ( tokenisedCommand.first == "lsp" )
            {
                TrekStar::Information::listProjects(projects);
            }
            else if ( tokenisedCommand.first == "lsm" )
            {
                try
                {
                    TrekStar::Information::listMaterials(projects, commandHandler.getIntegerValue(tokenisedCommand.second));
                }
                catch ( std::invalid_argument )
                {
                    std::cout << "Invalid parameter, please try again." << std::endl;
                }
            }
            else if ( tokenisedCommand.first == "addp" )
            {
                TrekStar::Information::addProject(projects, tokenisedCommand.second);

            }
            else if ( tokenisedCommand.first == "save" )
            {
                TrekStar::Information::save(projects, FILE_PATH);
            }
        }
        else
        {
            std::cout << "'" << tokenisedCommand.first << "'" << " is not a valid command. Type 'help' to see all available commands" << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    runCommandLine();

    QGuiApplication::setApplicationName("TrekstarGUI");
    QGuiApplication::setOrganizationName("NTU");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QIcon::setThemeName("trekstar");

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");

    QQuickStyle::setStyle("Material");


    QSettings settings;
    QString style = QQuickStyle::name();
    if (!style.isEmpty())
        settings.setValue("style", style);
    else
        QQuickStyle::setStyle(settings.value("style").toString());

    QQmlApplicationEngine engine;
    engine.addImportPath("../../src/GUI/");
    //engine.addImportPath("GUI/");
    engine.rootContext()->setContextProperty("availableStyles", QQuickStyle::availableStyles());
    engine.load(QUrl("../../src/GUI/main.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
