#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "GraphTests.cpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WorkFunctionsTests {
	TEST_CLASS(LabWorkFunctions) {
public:
	TEST_METHOD(Check_add) {
		Graph<int> gr;
		stringstream input;
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		input << "1\n";
		Assert::IsTrue(Add_top(gr));
		input << "2\n";
		Assert::IsTrue(Add_top(gr));
		input << "1 2\n";
		Assert::IsTrue(Add_edge(gr));
	}

	TEST_METHOD(Check_del) {
		Graph<int> gr;
		stringstream input;
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		input << "1\n";
		Add_top(gr);
		input << "2\n";
		Add_top(gr);
		input << "1 2\n";
		Add_edge(gr);
		input << "1 2\n";
		Assert::IsTrue(Del_edge(gr));
		input << "2\n";
		Assert::IsTrue(Del_top(gr));
		input << "1\n";
		Assert::IsTrue(Del_top(gr));
	}

	TEST_METHOD(Check_degree) {
		Graph<int> gr;
		stringstream input;
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		input << "1\n";
		Add_top(gr);
		input << "2\n";
		Add_top(gr);
		input << "1 2\n";
		Add_edge(gr);
		input << "1\n";
		Assert::IsTrue(Get_degree_top(gr));
		input << "1 2\n";
		Assert::IsTrue(Get_degree_edge(gr));
	}

	TEST_METHOD(Check_check) {
		Graph<int> gr;
		stringstream input;
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		input << "1\n";
		Add_top(gr);
		input << "2\n";
		Add_top(gr);
		input << "1 2\n";
		Add_edge(gr);
		input << "1\n";
		Assert::IsTrue(Check_top(gr));
		input << "3\n";
		Assert::IsFalse(Check_top(gr));
		input << "1 2\n";
		Assert::IsTrue(Check_edge(gr));
		input << "1 3\n";
		Assert::IsFalse(Check_edge(gr));
	}

	TEST_METHOD(Check_incident_smeg) {
		Graph<int> gr;
		stringstream input;
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		input << "1\n";
		Add_top(gr);
		input << "2\n";
		Add_top(gr);
		input << "1 2\n";
		Add_edge(gr);
		input << "1\n";
		Assert::IsTrue(Smeg_top(gr));
		input << "1 2\n";
		Assert::IsTrue(Incident_edge(gr));
	}
	};
}