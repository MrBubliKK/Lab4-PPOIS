#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "TopTests.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphTests {
	TEST_CLASS(Labgraph) {
public:
	TEST_METHOD(Check_add_top_edge) {
		Graph<int> gr;
		gr.Add_top(1);
		gr.Add_top(2);
		gr.Add_edge(1, 2);
		int cont = 2;
		Assert::AreEqual(2, gr.Get_top(gr.Get_list_tops(), cont)->Get_content());
		int res = gr.Get_list_tops().size();
		Assert::AreEqual(2, res);
		res = gr.Get_list_edges().size();
		Assert::AreEqual(1, res);
		gr.Get_size_tops();
		gr.Get_size_edges();
	}

	TEST_METHOD(Check_search) {
		Graph<int> gr;
		gr.Add_top(1);
		gr.Add_top(2);
		gr.Add_edge(1, 2);
		Assert::IsTrue(gr.Search_top(1));
		Assert::IsFalse(gr.Search_top(3));
		Assert::IsFalse(gr.Search_edge(2, 3));
		Assert::IsTrue(gr.Search_edge(1, 2));	
	}

	TEST_METHOD(Check_del) {
		Graph<int> gr;
		gr.Add_top(1);
		gr.Add_top(2);
		gr.Add_edge(1, 2);
		Assert::IsTrue(gr.Del_top(1));
		Assert::IsFalse(gr.Del_top(1));
		gr.Add_top(1);
		Assert::IsTrue(gr.Del_edge(1, 2));
		Assert::IsFalse(gr.Del_edge(1, 2));
		Assert::IsTrue(gr.Del_full_top(1));
		Assert::IsFalse(gr.Del_full_top(1));
		gr.Add_top(1);
		gr.Add_edge(1, 2);
		Assert::IsTrue(gr.Del_full_edge(1, 2));
		Assert::IsFalse(gr.Del_full_edge(1, 2));
		gr.Del_top(1);
		Assert::IsFalse(gr.Del_full_edge(1, 2));
	}

	TEST_METHOD(Check_add_full) {
		Graph<int> gr;
		Assert::IsTrue(gr.Add_full_top(1));
		Assert::IsFalse(gr.Add_full_top(1));
		gr.Add_full_top(2);
		Assert::IsTrue(gr.Add_full_edge(1, 2));
		Assert::IsFalse(gr.Add_full_edge(1, 2));
		Assert::IsFalse(gr.Add_full_edge(1, 3));
	}

	TEST_METHOD(Check_find_degree_top) {
		Graph<int> gr;
		gr.Add_full_top(1);
		gr.Add_full_top(2);
		gr.Add_full_edge(1, 2);
		Assert::IsTrue(gr.Find_degree_top(1));
		Assert::IsFalse(gr.Find_degree_top(3));
	}

	TEST_METHOD(Check_one_two_degree) {
		Graph<int> gr;
		Assert::AreEqual(1, gr.Change_one_two_degree(1, 1));
		Assert::AreEqual(2, gr.Change_one_two_degree(1, 2));
	}

	TEST_METHOD(Check_find_degree_edge) {
		Graph<int> gr;
		gr.Add_full_top(1);
		gr.Add_full_top(2);
		gr.Add_full_edge(1, 2);
		Assert::IsTrue(gr.Find_degree_edge(1, 2));
		Assert::IsFalse(gr.Find_degree_edge(1, 3));
	}

	TEST_METHOD(Check_incident_edge) {
		Graph<int> gr;
		gr.Add_full_top(1);
		gr.Add_full_top(2);
		gr.Add_full_edge(1, 2);
		Assert::IsTrue(gr.Incident_edge(1));
		Assert::IsFalse(gr.Incident_edge(3));
	}

	TEST_METHOD(Check_smeg_top) {
		Graph<int> gr;
		gr.Add_full_top(1);
		gr.Add_full_top(2);
		gr.Add_full_edge(1, 2);
		Assert::IsTrue(gr.Smeg_top(1));
		Assert::IsFalse(gr.Smeg_top(3));
	}
	
	};
}