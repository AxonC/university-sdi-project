#include <gtest/gtest.h>

#include <structures/Stack.h>

using TrekStar::Structures::Stack;

namespace TrekStarTests {
    namespace Tests {
        class StackTest: public testing::Test
            {
         public:
            StackTest()
            = default;

          Stack<int> stack;
          Stack<int> usedStack{1};
        };

        TEST_F(StackTest, AnElementCanBeAddedToAStack)
        {
            int element{5};

            stack.push(element);

            ASSERT_EQ(stack[0], element);
        }

        TEST_F(StackTest, AnElementCanBePoppedFromStack)
        {
            usedStack.pop();

            ASSERT_TRUE(usedStack.isEmpty());
        }
    }
}