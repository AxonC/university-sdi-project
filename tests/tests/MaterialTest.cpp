#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <project/Material.h>

using TrekStar::Material::Material;

namespace TrekStarTest {
    namespace Tests {
        class MaterialTest : public testing::Test
        {
         public:
            // Default state of Material every time a test fixture is run
            MaterialTest() :  material(1, "Test Material")
            {}

            Material material;
        };

        TEST_F(MaterialTest, CorrectlyDetectsEquality)
        {
            Material material2(1, "Test Material");

            ASSERT_TRUE(material == material2);
        }

        TEST_F(MaterialTest, CorrectlyDetectsInEquality)
        {
            Material material2(2, "Test Material");

            ASSERT_TRUE(material != material2);
            ASSERT_FALSE(material == material2);
        }
    }
}