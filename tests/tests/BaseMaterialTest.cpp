#include "TestCase.h"

#include <model/material/DVD.h>

using TrekStar::Material::DVD;
using TrekStarTests::Tests::TestCase;

namespace TrekStarTests {
    namespace Tests {
     class BaseMaterialTest : public TestCase
        {
         public:
            BaseMaterialTest() : exampleMaterial()
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


                malformedJson = {
                    {"id", 1},
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

                exampleMaterial.PopulateFromFile(j);
            }

            DVD exampleMaterial;
            json malformedJson;
        };

        TEST_F(BaseMaterialTest, BaseAttributesAreImportedCorrectly)
        {
            ASSERT_EQ("big movie", exampleMaterial.GetSide().GetContent());
            ASSERT_EQ("DTS", exampleMaterial.GetAudioFormat());
            ASSERT_EQ("dvd", exampleMaterial.GetFormat());
            ASSERT_EQ("16:9", exampleMaterial.GetFrameAspect());
            ASSERT_EQ(9.99, exampleMaterial.GetRetailPrice());
            ASSERT_EQ(120, exampleMaterial.GetRunTime());
            ASSERT_EQ("ENG", exampleMaterial.GetLanguage());
            ASSERT_EQ("ENG", exampleMaterial.GetSubtitles());
        }

        TEST_F(BaseMaterialTest, ExceptionIsThrownWhenAccessingMissingKey)
        {
            DVD material;

            ASSERT_THROW(material.PopulateFromFile(malformedJson), json::out_of_range);
        }
    }
}