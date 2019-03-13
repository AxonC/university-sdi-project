#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <project/Material.h>

using TrekStar::Material::Material;

namespace TrekStarTest {
    namespace Tests {
        class MaterialTest : public testing::Test
        {
         public:
            MaterialTest() :  material(1, "Test Material")
            {}

            Material material;
        };

        TEST_F(MaterialTest, CorrectlyDetectsEquality)
        {
            Material material2(1, "Test Material");

            ASSERT_TRUE(material == material2);
        }
    }
}