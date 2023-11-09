#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "../WorkFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TopTests {
	TEST_CLASS(LabTop) {
public:
	TEST_METHOD(Check_getter_setter) {
		Top<int> t1(1);
		Top<int> t2(2);
		Top<int> t3(3);
		Assert::AreEqual(1, t1.Get_content());
		t1.Add_child_top(&t2);
		int res = t1.Get_child_tops().size();
		Assert::AreEqual(1, res);
		t1.Add_parent_top(&t3);
		res = t1.Get_parent_tops().size();
		Assert::AreEqual(1, res);
	}

	TEST_METHOD(Check_del_tops) {
		Top<int> t1(1);
		Top<int> t2(2);
		Top<int> t3(3);
		Top<int> t4(4);
		Top<int> t5(5);
		t1.Add_child_top(&t4);
		t1.Add_child_top(&t2);
		t1.Add_parent_top(&t5);
		t1.Add_parent_top(&t3);
		t1.Del_child_top(2);
		t1.Del_parent_top(3);
		int res = t1.Get_child_tops().size();
		Assert::AreEqual(1, res);
		res = t1.Get_parent_tops().size();
		Assert::AreEqual(1, res);
	}
	};


}