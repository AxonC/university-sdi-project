#include "TestCase.h"

#include <model/material/DVD.h>
#include <model/material/BoxSet.h>

using TrekStar::Material::DVD;
using TrekStar::Material::BoxSet;
using TrekStarTests::Tests::TestCase;
using ::testing::ElementsAre;

namespace TrekStarTest {
    namespace Tests {
     class DVDTest : public TestCase
        {
         public:
            // Default state of Material every time a test fixture is run
            DVDTest() :  TestCase(), material()
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

        TEST_F(DVDTest, ImportsDVDSpecificInformationFromFile)
        {
            EXPECT_THAT(material.GetSide().GetAdditionalLanguageTracks(), ElementsAre("FRA", "GER"));
            EXPECT_THAT(material.GetSide().GetAdditionalSubtitleTracks(), ElementsAre("FRA", "GER"));
            EXPECT_THAT(material.GetSide().GetBonusFeatures(), ElementsAre("Directors Comments"));
        }

        TEST_F(DVDTest, CanBeExportedToSerialisedType)
        {
            auto serialised = material.ExportToSerialised();

            ASSERT_EQ("big movie", serialised->sideOne.content);
            ASSERT_EQ("dvd", serialised->material.format);
            ASSERT_EQ("ENG", serialised->material.language);
        }
    }
}