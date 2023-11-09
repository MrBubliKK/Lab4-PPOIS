#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Type>
class Top {
private:
	Type content;
	vector<Top*> child_tops;
	vector<Top*> parent_tops;

public:
	Top(Type content) :
		content(content) {}

	Type Get_content() {
		return this->content;
	}

	void Add_child_top(Top* top) {
		child_tops.push_back(top);
	}

	vector<Top*>& Get_child_tops() {
		return child_tops;
	}

	void Add_parent_top(Top* top) {
		parent_tops.push_back(top);
	}

	vector<Top*>& Get_parent_tops() {
		return parent_tops;
	}

	void Del_child_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = child_tops.begin(); it != child_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				child_tops.erase(it);
				return;
			}
		}
	}

	void Del_parent_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = parent_tops.begin(); it != parent_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				parent_tops.erase(it);
				return;
			}
		}
	}

	//»щет дочернюю точку
	bool Search_child_top(Type content) {
		for (typename vector<Top*>::iterator it = child_tops.begin(); it != child_tops.end; it++) {
			if (content == (*it)->Get_content()) {
				return true;
			}
		}
		return false;
	}

	//»щет родительскую точку
	bool Search_parent_top(Type content) {
		for (typename vector<Top*>::iterator it = parent_tops.begin(); it != parent_tops.end; it++) {
			if (content == (*it)->Get_content()) {
				return true;
			}
		}
		return false;
	}

};
