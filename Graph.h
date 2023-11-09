#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Top.h"
using namespace std;

template <typename Type>
class Graph {
private:
	vector<Top<Type>*> list_tops;
	vector<pair<Type, Type>> list_edges;

public:
	Top<Type>* Get_top(vector<Top<Type>*>& list_tops, Type& content) {
		for (Top<Type>* top : list_tops) {
			if (top->Get_content() == content) {
				return top;
			}
		}
		return nullptr; // ���� ������� � ��������� ���������� �� ������
	}

	vector<pair<Type, Type>> Get_edge(Type content1, Type content2) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
			if ((content1 == it->first) && (content2 == it->second)) {
				return it;
			}
		}
	}

	//������ ����� ���������� �������
	void Add_top(Type content) {
		list_tops.push_back(new Top<Type>(content));
	}

	vector<Top<Type>*>& Get_list_tops() {
		return list_tops;
	}

	vector<pair<Type, Type>> Get_list_edges() {
		return list_edges;
	}

	//������ ����� ���������� �����
	void Add_edge(Type content1, Type content2) {
		list_edges.push_back({ content1, content2 });
	}

	//���� ������������ �������
	bool Search_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				return true;
			}
		}
		return false;
	}

	//����� �����
	bool Search_edge(Type content1, Type content2) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
			if ((content1 == it->first) && (content2 == it->second)) {
				return true;
			}
		}
		return false;
	}

	//������� ���������� ������
	void Print_size_tops() {
		cout << "���������� ������ � �����: " << list_tops.size() << endl;
	}

	//������� ���������� �����
	void Print_size_edges() {
		cout << "���������� ����� � �����: " << list_edges.size() << endl;
	}

	//������ ����� �������� �������
	bool Del_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				list_tops.erase(it);
				return true;
			}
		}
		return false;
	}

	//������ ����� �������� �����
	bool Del_edge(Type content1, Type content2) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
			if ((content1 == it->first) && (content2 == it->second)) {
				list_edges.erase(it);
				return true;
			}
		}
		return false;
	}

	void Del_child_parent_top(Type content1, Type content2) {
		Top<Type>* top1 = Get_top(list_tops, content1);
		Top<Type>* top2 = Get_top(list_tops, content2);

		top1->Del_child_top(content2);
		top2->Del_parent_top(content1);
	}

	//������� ����� � ��������� ��������
	void Del_edges_top(Type content) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end();) {
			if ((content == it->first) || (content == it->second)) {
				Del_child_parent_top(it->first, it->second);
				it = list_edges.erase(it);
			}
			else {
				++it;
			}
		}
	}

	//����������� ����� �������� �������
	bool Del_full_top(Type content) {
		try {
			if (!Search_top(content)) {
				throw "����� ������� ���!\n";
			}
			Del_edges_top(content);
			Del_top(content);
			cout << "������� �������.\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}


	//����������� ����� �������� �����
	bool Del_full_edge(Type content1, Type content2) {
		try {
			if (!(Search_top(content1)) || !(Search_top(content2))) {
				throw "����� �� ������ �� ����������!\n";
			}
			if (!Search_edge(content1, content2)) {
				throw "������ ����� ���!\n";
			}

			Del_child_parent_top(content1, content2);
			Del_edge(content1, content2);
			cout << "����� �������.\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}
		/*if ((Search_top(content1)) && (Search_top(content2))) {
			if (Search_edge(content1, content2)) {
				Del_child_parent_top(content1, content2);
				Del_edge(content1, content2);
				cout << "����� �������.\n";
				return true;
			}
			cout << "������ ����� ���!\n";
			return false;
		}
		cout << "����� �� ������ �� ����������!\n";
		return false;
	}*/

	//������������ ����� ���������� �������
	bool Add_full_top(Type content) {
		try {
			if (Search_top(content)) {
				throw "����� ������� ��� ����!\n";
			}
			Add_top(content);
			cout << "������� ���������.\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	void Add_child_parent_top(Type content1, Type content2) {
		Top<Type>* top1 = Get_top(list_tops, content1);
		Top<Type>* top2 = Get_top(list_tops, content2);

		top1->Add_child_top(top2);
		top2->Add_parent_top(top1);
	}

	//����������� ����� ���������� �����
	bool Add_full_edge(Type content1, Type content2) {
		try {
			if ((!Search_top(content1)) || (!Search_top(content2))) {
				throw "����� �� ������ �� ����������!\n";
			}
			if (Search_edge(content1, content2)) {
				throw "����� ��� ����������!\n";
			}
			Add_edge(content1, content2);
			Add_child_parent_top(content1, content2);
			cout << "����� ���������. <" << content1 << ", " << content2 << ">\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	//������� ������� ������� �����
	bool Find_degree_top(Type content) {
		// first + �������� �����
		// second - ��������� �����
		try {
			if (!Search_top(content)) {
				throw "����� ������� ���!\n";
			}
			int first;
			int second;
			for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
				if (content == (*it)->Get_content()) {
					first = (Get_top(list_tops, content))->Get_parent_tops().size();
					second = (Get_top(list_tops, content))->Get_child_tops().size();
					cout << "������� ����� +: " << first << endl;
					cout << "������� ����� -: " << second << endl;
					return true;
				}
			}
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	//��������� ���� ������, ���� ������ ������� �����
	int Change_one_two_degree(Type content1, Type content2) {
		if (content1 == content2) {
			return 1;
		}
		return 2;
	}

	//������� ������� ����� �����
	bool Find_degree_edge(Type content1, Type content2) {
		try {
			if (!Search_edge(content1, content2)) {
				throw "������ ����� �� ����������!\n";
			}
			int degree;
			cout << "������� ����� �����: " << Change_one_two_degree(content1, content2) << endl;
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	bool Incident_edge(Type content) {
		try {
			if (!Search_top(content)) {
				throw "����� ������� ���!\n";
			}
			cout << "�����, ����������� �������: ";
			for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
				if (content == it->first) {
					cout << "<" << it->first << ", " << it->second << "> ";
				}
			}
			cout << endl;
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	bool Smeg_top(Type content) {
		try {
			if (!Search_top(content)) {
				throw "����� ������� ���!\n";
			}
			cout << "�������, ������� � ������: ";
			for (typename vector<Top<Type>*>::iterator it = Get_top(list_tops, content)->Get_child_tops().begin();
				it != Get_top(list_tops, content)->Get_child_tops().end(); it++) {
				cout << (*it)->Get_content() << " ";
			}
			cout << endl;
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}
		
};