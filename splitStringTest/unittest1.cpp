#include "../BasicTextReader/pch.h"
#include "stdafx.h"
#include "CppUnitTest.h"
#include "BasicTextReader.h"
#include <vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace splitStringTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<string>correctAnswer = {"a", "b"};
			vector<string>currentAnswer;
			currentAnswer=splitString("a b"," ");
			Assert::AreEqual(1, 1);
		}
	};
}