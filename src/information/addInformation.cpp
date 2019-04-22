#include <iostream>

#include "addInformation.h"

using TrekStar::Project::Project;

namespace TrekStar
{
    namespace Information
    {
        void addProject(std::vector<TrekStar::Project::Project> & projects)
        {
            std::string title;
            std::string summary;
            std::string releasedString;
            bool released = false;
            std::string playingInTheatresString;
            bool playingInTheatres = false;
            std::vector<std::string> keywords;

            std::cout << "Title: ";
            std::cin >> title;

            std::cout << "Summary: ";
            std::cin >> summary;

            while ( releasedString != "y" && releasedString != "n" )
            {
                std::cout << "Released? (y/n): ";
                std::cin >> releasedString;
            }
            if ( releasedString == "y" )
            {
                released = true;
            }

            while ( playingInTheatresString != "y" && playingInTheatresString != "n" )
            {
                std::cout << "Playing in theatres? (y/n): ";
                std::cin >> playingInTheatresString;
            }
            if ( playingInTheatresString == "y" )
            {
                playingInTheatres = true;
            }

            unsigned int noOfKeywords;
            std::cout << "Number of keywords: ";
            std::cin >> noOfKeywords;

            std::string currentKeyword;
            for ( int i = 0; i < noOfKeywords; i++ )
            {
                std::cout << "Keyword #" << i << ": ";
                std::cin >> currentKeyword;
                keywords.push_back(currentKeyword);
            }

            projects.push_back(TrekStar::Project::Project(title, summary, released, playingInTheatres, keywords));
        }
    }
}