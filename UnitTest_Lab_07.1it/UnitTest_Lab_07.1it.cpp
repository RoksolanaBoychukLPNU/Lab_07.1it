#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.1it/Lab_07.1it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest711
{
    TEST_CLASS(UnitTest711)
    {
    public:
        TEST_METHOD(TestCalc)
        {
            int r0[3] = { 5, 7, -2 };   // підходять: 5, -2
            int r1[3] = { 4, -6, 9 };   // підходить: -6
            int* a[2] = { r0, r1 };
            int S, k;
            Calc(a, 2, 3, S, k);
            Assert::AreEqual(-3, S);    // 5 + (-2) + (-6)
            Assert::AreEqual(3, k);
            Assert::AreEqual(0, a[0][0]);
            Assert::AreEqual(7, a[0][1]);
        }

        TEST_METHOD(TestSort)
        {
            int r0[3] = { 2, 1, 1 };
            int r1[3] = { 1, 5, 0 };
            int r2[3] = { 1, 5, 8 };
            int* a[3] = { r0, r1, r2 };
            Sort(a, 3, 3);
            // ↑ за 1-м стовпчиком, ↑ за 2-м, ↓ за 3-м
            Assert::AreEqual(8, a[0][2]);
            Assert::AreEqual(0, a[1][2]);
            Assert::AreEqual(2, a[2][0]);
        }
    };
}
