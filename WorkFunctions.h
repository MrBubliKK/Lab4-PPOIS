#pragma once
#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

template <typename Type>
//��������� �������
bool Add_top(Graph<Type>& gr) {
	Type content{};
	cout << "������� ���������� �������: ";
	cin >> content;
	return gr.Add_full_top(content);
}

template <typename Type>
//��������� �����
bool Add_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "������� ������������ �������: ";
	cin >> content1;
	cout << "������� �������� �������: ";
	cin >> content2;
	return gr.Add_full_edge(content1, content2);
}

template <typename Type>
//������� �������
bool Del_top(Graph<Type>& gr) {
	Type content{};
	cout << "������� ���������� ������: ";
	cin >> content;
	return gr.Del_full_top(content);
}

template <typename Type>
//������� �����
bool Del_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "������� ������������ �������: ";
	cin >> content1;
	cout << "������� �������� �������: ";
	cin >> content2;
	return gr.Del_full_edge(content1, content2);
}

template <typename Type>
//������� ������� �������
bool Get_degree_top(Graph<Type>& gr) {
	Type content{};
	cout << "������� ���������� �������: ";
	cin >> content;
	return gr.Find_degree_top(content);
}

template <typename Type>
//������� ������� �����
bool Get_degree_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "������� ������������ �������: ";
	cin >> content1;
	cout << "������� �������� �������: ";
	cin >> content2;
	return gr.Find_degree_edge(content1, content2);
}

template <typename Type>
//��������� ������� ������� � �����
bool Check_top(Graph<Type>& gr) {
	Type content{};
	cout << "������� ���������� �������: ";
	cin >> content;
	if (gr.Search_top(content)) {
		cout << "����� ������� ����.\n";
		return true;
	}
	else {
		cout << "����� ������� ���.\n";
		return false;
	}
}

template <typename Type>
//��������� ������� ����� � �����
bool Check_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "������� ������������ �����: ";
	cin >> content1;
	cout << "������� �������� �����: ";
	cin >> content2;
	if (gr.Search_edge(content1, content2)) {
		cout << "����� ����� ����.\n";
		return true;
	}
	else {
		cout << "������ ����� ���.\n";
		return false;
	}
}

template <typename Type>
//��������� �����, ����������� �������
bool Incident_edge(Graph<Type>& gr) {
	Type content{};
	cout << "������� ���������� �������: ";
	cin >> content;
	return gr.Incident_edge(content);
}

template <typename Type>
//���������� �������, ������� � ������
bool Smeg_top(Graph<Type>& gr) {
	Type content{};
	cout << "������� ���������� �������: ";
	cin >> content;
	return gr.Smeg_top(content);
}

template <typename Type>
//�������� ������� ������
void Work_method(Graph<Type>& gr) {
	string change;
	while (true) {
		cout << "'addtop' - �������� �������   'deltop' - ������� �������\n";
		cout << "'addedge' - �������� �����   'deledge' - ������� �����\n";
		cout << "'degreetop' - ������� �������   'degreeedge' - ������� �����\n";
		cout << "'inctop' - ������������� �������   'smegtop' - ��������� �������\n";
		cout << "'checktop' - ������� �������   'checkedge' - ������� �����\n";
		cout << "'exit' - �����\n";
		cin >> change;
		if (change == "addtop") {
			Add_top(gr);
			continue;
		}
		else if (change == "deltop") {
			Del_top(gr);
			continue;
		}
		else if (change == "addedge") {
			Add_edge(gr);
			continue;
		}
		else if (change == "deledge") {
			Del_edge(gr);
			continue;
		}
		else if (change == "degreetop") {
			Get_degree_top(gr);
			continue;
		}
		else if (change == "degreeedge") {
			Get_degree_edge(gr);
			continue;
		}
		else if (change == "inctop") {
			Incident_edge(gr);
			continue;
		}
		else if (change == "smegtop") {
			Smeg_top(gr);
			continue;
		}
		else if (change == "checktop") {
			Check_top(gr);
			continue;
		}
		else if (change == "checkedge") {
			Check_edge(gr);
			continue;
		}
		else if (change == "exit") {
			return;
		}
		else {
			cout << "������������ ������!\n";
			continue;
		}
	}
}
