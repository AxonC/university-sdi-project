#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <algorithm>

#include <model/project/Project.h>
#include <model/material/DVD.h>
#include <model/people/Crew.h>

#include <controller/project/ProjectController.h>
#include <view/project/ProjectView.h>

#include "../mock/MockProject.h"
#include "../mock/MockProjectView.h"

using TrekStar::People::Crew;
using TrekStar::Material::DVD;
using TrekStar::Project::Project;
using TrekStar::Project::ProjectView;
using TrekStar::Project::ProjectController;
using TrekStar::Material::Material;

using ::testing::NiceMock;

namespace TrekStarTest {
    namespace Tests {
        class ProjectTest: public testing::Test
        {
        public:
            // Default state of a project every time a test is ran.
            ProjectTest() : project("Project", "A summary of a project", false, true, {"hello", "keyword"}),
                            releasedProject("Project 2", "A summary of a project", true, false, {"keyword", "keyword 2"})
            {
                releasedProject.ReleaseProject();
            }

            // surpresses console output by redirecting the std::cout stream
            virtual void SetUp() {
              storedStreambuf_ = std::cout.rdbuf();
              std::cout.rdbuf(nullptr);
            }

            virtual void TearDown() {
              std::cout.rdbuf(storedStreambuf_);
            }

            Project project;
            Project releasedProject;
            std::shared_ptr<DVD> material = std::make_shared<DVD>();
            std::shared_ptr<Crew> crewMember = std::make_shared<Crew>();
            std::streambuf* storedStreambuf_;
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

        TEST_F(ProjectTest, CanAddACrewMemberToAProject)
        {
            project.AddCrew(crewMember);

            EXPECT_EQ(project.GetCrew().size(), 1);
        }

        TEST_F(ProjectTest, CantRemoveACrewMemberWhenNotPresent)
        {
            std::shared_ptr<Crew> unassignedCrew = std::make_shared<Crew>();

            ASSERT_THROW(project.RemoveCrew(unassignedCrew), std::out_of_range);
        }

        TEST_F(ProjectTest, ControllerPresentsProjectDetails)
        {
            NiceMock<MockProject> mockProject;
            ProjectView projectView(mockProject);

            EXPECT_CALL(mockProject, GetTitle()).Times(1);
            EXPECT_CALL(mockProject, GetSummary()).Times(1);
            EXPECT_CALL(mockProject, GetReleased()).Times(1);
            EXPECT_CALL(mockProject, GetPlayingInTheatres()).Times(1);

            ProjectController controller(mockProject, projectView);
            controller.ListProjects();
        }
    }
}