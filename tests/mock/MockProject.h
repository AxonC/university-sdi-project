#pragma once
#include "gmock/gmock.h"

#include "project/ProjectInterface.h"

namespace TrekStarTest {
    namespace Mocks {
        class MockProject: public TrekStar::Project::ProjectInterface
        {
        public:
            MOCK_METHOD1(SetSummary, void(std::string contents));
            MOCK_CONST_METHOD0(GetSummary, std::string());
            MOCK_METHOD0(GetTitleSummary, std::pair<std::string, std::string>());
        };
    }
}