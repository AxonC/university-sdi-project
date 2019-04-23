#ifndef TREKSTAR_MOCKPROJECTVIEW_H
#define TREKSTAR_MOCKPROJECTVIEW_H

#include "gmock/gmock.h"

#include <view/project/ProjectView.h>

using TrekStar::Project::ProjectView;

class MockProjectView: public ProjectView
{
public:
    explicit MockProjectView(ProjectInterface& model) : ProjectView(model) {}
    MOCK_METHOD0(PresentAll, void());
    MOCK_METHOD0(GetModel, ProjectInterface*());
};

#endif //TREKSTAR_MOCKPROJECTVIEW_H
