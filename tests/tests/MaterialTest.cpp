#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <project/DVD.h>

using TrekStar::Material::DVD;

namespace TrekStarTest {
    namespace Tests {
        class MaterialTest : public testing::Test
        {
         public:
            // Default state of Material every time a test fixture is run
            MaterialTest() :  material(1, "Test Material")
            {}

            DVD material;
        };

        TEST_F(MaterialTest, CorrectlyDetectsEquality)
        {
            DVD material2(1, "Test Material");

            ASSERT_TRUE(material == material2);
        }

        TEST_F(MaterialTest, CorrectlyDetectsInEquality)
        {
            DVD material2(2, "Test Material");

            ASSERT_TRUE(material != material2);
            ASSERT_FALSE(material == material2);
        }
    }
}