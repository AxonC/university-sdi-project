#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <material/DVD/DVD.h>
#include <material/BoxSet/BoxSet.h>

using TrekStar::Material::DVD;
using TrekStar::Material::BoxSet;

namespace TrekStarTest {
    namespace Tests {
        class DVDTest : public testing::Test
        {
         public:
            // Default state of Material every time a test fixture is run
            DVDTest() :  material()
            {
                json j = {
                    {"id", 1},
                    {"content", "big movie"},
                    {"audioFormat", "DTS"},
                    {"format", "dvd"},
                    {"frameAspect", "16:9"},
                    {"retailPrice", 9.99},
                    {"runTime", 120},
                    {"language", "ENG"},
                    {"subtitles", "ENG"},
                    {"bonusFeatures", {"Directors Comments"}},
                    {"additionalLanguageTracks", {"FRA", "GER"}},
                    {"additionalSubtitleTracks", {"FRA", "GER"}}
                };

                material.PopulateFromFile(j);
            }

            DVD material;
        };

        TEST_F(DVDTest, CorrectlyImportsFromFile)
        {
            ASSERT_EQ("big movie", material.GetSide().GetContent());
            ASSERT_EQ("DTS", material.GetAudioFormat());
            ASSERT_EQ("ENG", material.GetLanguage());
            ASSERT_EQ(120, material.GetRunTime());
        }
    }
}