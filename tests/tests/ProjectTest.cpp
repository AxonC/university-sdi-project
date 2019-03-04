#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <project/Project.h>

using ::testing::Return;
using ::testing::NiceMock;

using TrekStar::Project::Project;
//using TrekStarTest::Mocks::MockProject;

namespace TrekStarTest {
    namespace Tests {
        TEST(ProjectTest, CanGetPairWithTitleAndSummary)
        {
            std::string projectName("Project");
            std::string projectSummary("A summary of a project");
            Project project(projectName, projectSummary);

            ASSERT_EQ(project.GetTitleSummary().second, "A summary of a project");
        }
    }
}