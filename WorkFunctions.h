#pragma once
#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

template <typename Type>
//Добавляет вершину
bool Add_top(Graph<Type>& gr) {
	Type content{};
	cout << "Введите содержимое вершины: ";
	cin >> content;
	return gr.Add_full_top(content);
}

template <typename Type>
//Добавляет ребро
bool Add_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "Введите родительскую вершину: ";
	cin >> content1;
	cout << "Введите дочернюю вершину: ";
	cin >> content2;
	return gr.Add_full_edge(content1, content2);
}

template <typename Type>
//Удаляет вершину
bool Del_top(Graph<Type>& gr) {
	Type content{};
	cout << "Введите содержимое вершиы: ";
	cin >> content;
	return gr.Del_full_top(content);
}

template <typename Type>
//Удаляет ребро
bool Del_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "Введите родительскую вершину: ";
	cin >> content1;
	cout << "Введите дочернюю вершину: ";
	cin >> content2;
	return gr.Del_full_edge(content1, content2);
}

template <typename Type>
//Выводит степень вершины
bool Get_degree_top(Graph<Type>& gr) {
	Type content{};
	cout << "Введите содержимое вершины: ";
	cin >> content;
	return gr.Find_degree_top(content);
}

template <typename Type>
//Выводит степень ребра
bool Get_degree_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "Введите родительскую вершину: ";
	cin >> content1;
	cout << "Введите дочернюю вершину: ";
	cin >> content2;
	return gr.Find_degree_edge(content1, content2);
}

template <typename Type>
//Проверяет наличие вершины в графе
bool Check_top(Graph<Type>& gr) {
	Type content{};
	cout << "Введите содержимое вершины: ";
	cin >> content;
	if (gr.Search_top(content)) {
		cout << "Такая вершина есть.\n";
		return true;
	}
	else {
		cout << "Такой вершины нет.\n";
		return false;
	}
}

template <typename Type>
//Проверяет наличие ребра в графе
bool Check_edge(Graph<Type>& gr) {
	Type content1{}, content2{};
	cout << "Введите родительскую точку: ";
	cin >> content1;
	cout << "Введите дочернюю точку: ";
	cin >> content2;
	if (gr.Search_edge(content1, content2)) {
		cout << "Такое ребро есть.\n";
		return true;
	}
	else {
		cout << "Такого ребра нет.\n";
		return false;
	}
}

template <typename Type>
//Вовращает ребра, инцидентные вершине
bool Incident_edge(Graph<Type>& gr) {
	Type content{};
	cout << "Введите содержимое вершины: ";
	cin >> content;
	return gr.Incident_edge(content);
}

template <typename Type>
//Возвращает вершины, смежные с данной
bool Smeg_top(Graph<Type>& gr) {
	Type content{};
	cout << "Введите содержимое вершины: ";
	cin >> content;
	return gr.Smeg_top(content);
}

template <typename Type>
//Основная функция работы
void Work_method(Graph<Type>& gr) {
	string change;
	while (true) {
		cout << "'addtop' - Добавить вершину   'deltop' - Удалить вершину\n";
		cout << "'addedge' - Добавить ребро   'deledge' - Удалить ребро\n";
		cout << "'degreetop' - Степень вершины   'degreeedge' - Степень ребра\n";
		cout << "'inctop' - Инцедентность вершины   'smegtop' - Смежность вершины\n";
		cout << "'checktop' - Наличие вершины   'checkedge' - Наличие ребра\n";
		cout << "'exit' - Выход\n";
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
			cout << "Некорректные данные!\n";
			continue;
		}
	}
}
