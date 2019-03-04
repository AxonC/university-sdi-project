#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <project/Project.h>
#include <project/Material.h>
#include "../mock/MockProject.h"

using ::testing::Return;
using ::testing::NiceMock;

using TrekStar::Project::Project;
using TrekStar::Material::Material;
using TrekStarTest::Mocks::MockProject;

namespace TrekStarTest {
    namespace Tests {
        TEST(ProjectTest, CanGetPairWithTitleAndSummary)
        {
            std::string projectName("Project");
            std::string projectSummary("A summary of a project");
            Project project(projectName, projectSummary);

            ASSERT_EQ(project.GetTitleSummary().second, "A summary of a project");
            ASSERT_EQ(project.GetTitleSummary().first, "Project");
        }

        TEST(ProjectTest, CanAddMaterialsWhenValid)
        {
            std::string projectName("Project");
            std::string projectSummary("A summary of a project");
            Project project(projectName, projectSummary, true);
            Material material;

            project.ReleaseProject();

            project.AddMaterials(material);

            EXPECT_EQ(project.GetMaterials().size(), 1);
        }
    }
}