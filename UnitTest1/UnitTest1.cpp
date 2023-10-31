#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.1r/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int array[1]{};
			int size = 7;
			ZeroFun(array, size);
			Assert::AreEqual(3, 3);
		}
	};
}
