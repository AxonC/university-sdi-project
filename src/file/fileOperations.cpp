#include "pch.h"
#include "fileOperations.h"

#include "../model/project/BoxOfficeReport.h"
#include "../model/project/Project.h"
#include "../model/material/Material.h"
#include "../model/material/MaterialFactory.h"
#include "../model/people/Crew.h"
#include "../model/material/BoxSet.h"

namespace TrekStar
{
    namespace File
    {
        /**
            Creates a new project.

            @param json string containing serialised data for a single project.
            @return object containing the created project.
        */
        Project::Project createProject(const json & jsonString)
        {
            Project::SerialisedProject serialised = Project::SerialisedProject();
            try
            {
                serialised = jsonString.get<Project::SerialisedProject>();
            }
            catch ( json::out_of_range & )
            {
                // TODO: Concept exception logic
            }

            return Project::Project(serialised);
        }


        /**
            Creates a number of materials.

            @param json string containing serialised data for multiple material.
            @return vector of created materials.
        */
        MaterialVector createMaterials(const json & jsonString)
        {
            MaterialVector materials;
            std::shared_ptr<Material::Material> currentMaterial;
            std::string format;

            for ( auto && value: jsonString )
            {
                std::vector<std::string> object;
                format = value.at("format");

                currentMaterial = Material::MaterialFactory::Create(format);

                if ( currentMaterial != nullptr )
                {
                    currentMaterial->PopulateFromFile(value);
                    materials.push_back(currentMaterial);
                }
                else
                {
                    throw std::domain_error("Material format is not supported.");
                }
            }

            return materials;
        }


        /**
            Creates a new of crew.

            @param json string containing serialised data for multiple crew.
            @return vector of created crew.
        */
        CrewVector createCrew(const json & jsonString)
        {
            CrewVector crewVector;

            for ( auto && item : jsonString )
            {
                std::shared_ptr<People::Crew> newCrew = std::make_shared<People::Crew>(item.get<People::SerializedCrew>());
                crewVector.push_back(newCrew);
            }

            return crewVector;
        }


        /**
            Creates a number of BoxOfficeReports.

            @param json string containing serialised data for multiple material.
            @return vector of created BoxOfficeReports.
        */
        BoxOfficeReportVector createBoxOfficeReports(const json & jsonString)
        {
            BoxOfficeReportVector reports;

            for ( auto && item : jsonString )
            {
                std::shared_ptr<Project::BoxOfficeReport> newReport = std::make_shared<Project::BoxOfficeReport>(item.get<Project::SerialisedBoxOfficeReport>());
                reports.push_back(newReport);
            }

            return reports;
        }

        /**
            Obtains project information from a file.

            @param string containing the file path of the JSON file.
            @return a vector of projects obtained from the JSON file.
        */
        ProjectVector importProjects(const std::string & filePath)
        {
            TrekStar::Project::Project currentProject;
            ProjectVector projects;

            std::ifstream dataFile(filePath);
			json jsonStream;
			try
			{
				jsonStream = json::parse(dataFile);
			}
			catch (json::parse_error &e)
			{
				std::cerr << e.what() << std::endl;
			}

            for ( auto &it : jsonStream )
            {
                // ensure that there is a key called details
                if ( it.find("details") != it.end() )
                {
                    currentProject = createProject(it.at("details"));
                }

                if ( it.find("boxOfficeReports") != it.end() )
                {
                    currentProject.AddBoxOfficeReports(createBoxOfficeReports(it.at("boxOfficeReports")));
                }

                if ( it.find("crew") != it.end() )
                {
                    currentProject.AddCrew(createCrew(it.at("crew")));
                }

                if ( it.find("materials") != it.end() && currentProject.CanAddMaterial() )
                {
                    currentProject.AddMaterials(createMaterials(it.at("materials")));
                }

                projects.push_back(currentProject);
            }

            return projects;
        }

    }
}
