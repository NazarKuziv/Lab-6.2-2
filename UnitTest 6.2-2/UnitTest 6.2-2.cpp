#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.2-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest622
{
	TEST_CLASS(UnitTest622)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 6;
			int t[n] = { 1, 2, 3, 4, 5, 6 };

			int Min = Search(t, n, 2, 0);

			Castling(t, n, Min, 1, 2, 0);

			Assert::AreEqual(Min, 2);
			Assert::AreEqual( t[0], 2);
			Assert::AreEqual(t[1], 1);
		}
	};
}
