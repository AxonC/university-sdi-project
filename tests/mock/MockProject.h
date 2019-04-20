#ifndef TREKSTAR_MOCKPROJECT_H
#define TREKSTAR_MOCKPROJECT_H

#include "gmock/gmock.h"

#include <model/project/Project.h>
#include <model/project/ProjectInterface.h>

using TrekStar::Project::Project;
using TrekStar::Project::ProjectInterface;

class MockProject : public ProjectInterface
{
public:
    MOCK_CONST_METHOD0(GetId, unsigned int());
    MOCK_CONST_METHOD0(GetTitle, std::string());
    MOCK_CONST_METHOD0(GetSummary, std::string());
    MOCK_CONST_METHOD0(GetReleased, bool());
    MOCK_CONST_METHOD0(GetPlayingInTheatres, bool());
};

#endif //TREKSTAR_MOCKPROJECT_H
