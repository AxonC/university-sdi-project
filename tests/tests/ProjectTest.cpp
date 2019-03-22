#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <algorithm>

#include <project/Project.h>
//#include <project/Material.h>
#include <project/DVD.h>

using TrekStar::Project::Project;
using TrekStar::Material::Material;
using TrekStar::Material::DVD;

namespace TrekStarTest {
    namespace Tests {
        class ProjectTest: public testing::Test
        {
        public:
            // Default state of a project every time a test is ran.
            ProjectTest() : project("Project", "A summary of a project"),
                            releasedProject("Project 2", "A summary of a project")
            {
                releasedProject.ReleaseProject();
            }

            Project project;
            Project releasedProject;
            std::shared_ptr<DVD> material = std::make_shared<DVD>();
        };


        TEST_F(ProjectTest, CanGetPairWithTitleAndSummary)
        {
            ASSERT_EQ(project.GetTitleSummary().second, "A summary of a project");
            ASSERT_EQ(project.GetTitleSummary().first, "Project");
        }

        TEST_F(ProjectTest, CanAddMaterialsWhenValid)
        {
            releasedProject.ReleaseProject();

            releasedProject.AddMaterials(material);

            EXPECT_EQ(releasedProject.GetMaterials().size(), 1);
        }

        TEST_F(ProjectTest, CantAddMaterialsWhenNotReleased)
        {
            std::shared_ptr<DVD> material = std::make_shared<DVD>();

            project.AddMaterials(material);

            EXPECT_EQ(project.GetMaterials().size(), 0);
        }

        TEST_F(ProjectTest, CanRemoveMaterialWhenAssociatedWithProject)
        {
            releasedProject.AddMaterials(material);

            releasedProject.RemoveMaterial(material);

            EXPECT_EQ(releasedProject.GetMaterials().size(), 0);
        }

        TEST_F(ProjectTest, CantRemoveMaterialWhenNotAssociatedWithProject)
        {
            ASSERT_THROW(project.RemoveMaterial(material), std::out_of_range);
        }
    }
}