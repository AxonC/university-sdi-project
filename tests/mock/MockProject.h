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
    MOCK_CONST_METHOD0(GetMaterials, std::vector<std::shared_ptr<TrekStar::Material::Material>>());
    MOCK_CONST_METHOD0(GetReleased, bool());
    MOCK_CONST_METHOD0(GetPlayingInTheatres, bool());
    MOCK_CONST_METHOD0(GetKeywords, std::vector<std::string>());
    MOCK_CONST_METHOD0(GetMaterialFormats, std::vector<std::string>());

    MOCK_METHOD1(SetTitle, void(const std::string &));
    MOCK_METHOD1(SetSummary, void(const std::string &));
    MOCK_METHOD1(SetReleased, void(const bool &));
    MOCK_METHOD1(SetPlayingInTheatres, void(const bool &));
    MOCK_METHOD2(SetKeyword, void(const unsigned int &, const std::string &));

    MOCK_CONST_METHOD0(GetCrew, std::vector<std::shared_ptr<TrekStar::People::Crew>>());

    MOCK_METHOD1(AddMaterial, void(const std::shared_ptr<TrekStar::Material::Material> &));
    MOCK_METHOD1(RemoveMaterial, void(const std::shared_ptr<TrekStar::Material::Material> &));
    MOCK_CONST_METHOD0(CanAddMaterial, bool());
    MOCK_METHOD1(FindActor, std::shared_ptr<TrekStar::People::Crew>(std::string &));

    MOCK_METHOD1(AddCrew, void(const std::shared_ptr<TrekStar::People::Crew> &));
    MOCK_METHOD1(RemoveCrew, void(const std::shared_ptr<TrekStar::People::Crew> &));

    MOCK_CONST_METHOD0(GetBoxOfficeReports, std::vector<std::shared_ptr<TrekStar::Project::BoxOfficeReport>>());
    MOCK_METHOD1(AddBoxOfficeReport, void(const std::shared_ptr<TrekStar::Project::BoxOfficeReport> &));
    MOCK_METHOD1(AddBoxOfficeReports, void(const std::vector<std::shared_ptr<TrekStar::Project::BoxOfficeReport>> &));
    MOCK_CONST_METHOD0(GetTotalBoxOfficeRevenue, unsigned long long int());
    MOCK_METHOD1(RemoveBoxOfficeReport, void(const std::shared_ptr<TrekStar::Project::BoxOfficeReport> &));
};

#endif //TREKSTAR_MOCKPROJECT_H
