#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.2.2/9.2.2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
       
        TEST_METHOD(TestErrorMsg)
        {
            std::stringstream buffer;
            std::streambuf* oldCerrBuffer = std::cerr.rdbuf(buffer.rdbuf());

            ERROR_MSG("Test error");

            std::cerr.rdbuf(oldCerrBuffer);
            std::string errorOutput = buffer.str();

            Assert::IsTrue(errorOutput.find("Error: Test error") != std::string::npos, L"ERROR_MSG did not print error message.");
            Assert::IsTrue(errorOutput.find("File:") != std::string::npos, L"ERROR_MSG did not print file information.");
            Assert::IsTrue(errorOutput.find("Line:") != std::string::npos, L"ERROR_MSG did not print line information.");
            Assert::IsTrue(errorOutput.find("Date:") != std::string::npos, L"ERROR_MSG did not print date information.");
            Assert::IsTrue(errorOutput.find("Time:") != std::string::npos, L"ERROR_MSG did not print time information.");
        }
    };
}
