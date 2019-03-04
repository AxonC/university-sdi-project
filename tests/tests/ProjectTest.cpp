#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <project/Project.h>
#include <project/Material.h>
#include "../mock/MockProject.h"

using ::testing::Return;
using ::testing::NiceMock;
using ::testing::Test;

using TrekStar::Project::Project;
using TrekStar::Material::Material;
using TrekStarTest::Mocks::MockProject;

namespace TrekStarTest {
    namespace Tests {
        class ProjectTest: public Test
        {
        public:
            ProjectTest() : project("Project", "A summary of a project")
            {}

            Project project;
        };


        TEST_F(ProjectTest, CanGetPairWithTitleAndSummary)
        {
            ASSERT_EQ(project.GetTitleSummary().second, "A summary of a project");
            ASSERT_EQ(project.GetTitleSummary().first, "Project");
        }

        TEST_F(ProjectTest, CanAddMaterialsWhenValid)
        {
            Material material;

            project.ReleaseProject();

            project.AddMaterials(material);

            EXPECT_EQ(project.GetMaterials().size(), 1);
        }
    }
}