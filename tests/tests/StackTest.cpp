#include "TestCase.h"

#include <structures/Stack.h>

using TrekStar::Structures::Stack;
using TrekStarTests::Tests::TestCase;

namespace TrekStarTests {
    namespace Tests {
        class StackTest: public TestCase
            {
            public:
                StackTest() : TestCase() {}

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

        TEST_F(StackTest, AnEmptyStackIsDetectedCorrectly)
        {
            ASSERT_FALSE(usedStack.isEmpty());
            ASSERT_TRUE(stack.isEmpty());
        }

        TEST_F(StackTest, AStackCanBeAccessedByIndex)
        {
            ASSERT_EQ(usedStack[0], 1);
        }

        TEST_F(StackTest, AnExceptionIsThrownWhenNotPresent)
        {
            ASSERT_THROW(stack[5], std::out_of_range);
        }

        TEST_F(StackTest, UnderlyingVectorCanBeAccessed)
        {
            ASSERT_NO_THROW(stack.data());
        }
    }
}