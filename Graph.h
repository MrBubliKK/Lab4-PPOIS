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
		return nullptr; // Если элемент с указанным содержимым не найден
	}

	vector<pair<Type, Type>> Get_edge(Type content1, Type content2) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
			if ((content1 == it->first) && (content2 == it->second)) {
				return it;
			}
		}
	}

	//Прямой метод добавления вершины
	void Add_top(Type content) {
		list_tops.push_back(new Top<Type>(content));
	}

	vector<Top<Type>*>& Get_list_tops() {
		return list_tops;
	}

	vector<pair<Type, Type>> Get_list_edges() {
		return list_edges;
	}

	//Прямой метод добавления ребра
	void Add_edge(Type content1, Type content2) {
		list_edges.push_back({ content1, content2 });
	}

	//Ищет определенную вершину
	bool Search_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				return true;
			}
		}
		return false;
	}

	//Ищиет ребро
	bool Search_edge(Type content1, Type content2) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
			if ((content1 == it->first) && (content2 == it->second)) {
				return true;
			}
		}
		return false;
	}

	//Выводит количество вершин
	void Print_size_tops() {
		cout << "Количество вершин в графе: " << list_tops.size() << endl;
	}

	//Выводит количество ребер
	void Print_size_edges() {
		cout << "Количество ребер в графе: " << list_edges.size() << endl;
	}

	//Прямой метод удаления вершины
	bool Del_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				list_tops.erase(it);
				return true;
			}
		}
		return false;
	}

	//Прямой метод удаления ребра
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

	//Удаляет ребра с удаленной вершиной
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

	//Полноценный метод удаления вершины
	bool Del_full_top(Type content) {
		try {
			if (!Search_top(content)) {
				throw "Такой вершины нет!\n";
			}
			Del_edges_top(content);
			Del_top(content);
			cout << "Вершина удалена.\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}


	//Полноценный метод удаления ребра
	bool Del_full_edge(Type content1, Type content2) {
		try {
			if (!(Search_top(content1)) || !(Search_top(content2))) {
				throw "Одной из вершин не существует!\n";
			}
			if (!Search_edge(content1, content2)) {
				throw "Такого ребра нет!\n";
			}

			Del_child_parent_top(content1, content2);
			Del_edge(content1, content2);
			cout << "Ребро удалено.\n";
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
				cout << "Ребро удалено.\n";
				return true;
			}
			cout << "Такого ребра нет!\n";
			return false;
		}
		cout << "Одной из вершин не существует!\n";
		return false;
	}*/

	//Полноценноый метод добавления вершины
	bool Add_full_top(Type content) {
		try {
			if (Search_top(content)) {
				throw "Такая вершина уже есть!\n";
			}
			Add_top(content);
			cout << "Вершина добавлена.\n";
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

	//Полноценный метод добавления ребра
	bool Add_full_edge(Type content1, Type content2) {
		try {
			if ((!Search_top(content1)) || (!Search_top(content2))) {
				throw "Одной из вершин не существует!\n";
			}
			if (Search_edge(content1, content2)) {
				throw "Ребро уже существует!\n";
			}
			Add_edge(content1, content2);
			Add_child_parent_top(content1, content2);
			cout << "Ребро добавлено. <" << content1 << ", " << content2 << ">\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	//Находит степень вершины графа
	bool Find_degree_top(Type content) {
		// first + входящие ребра
		// second - выходящие ребра
		try {
			if (!Search_top(content)) {
				throw "Такой вершины нет!\n";
			}
			int first;
			int second;
			for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
				if (content == (*it)->Get_content()) {
					first = (Get_top(list_tops, content))->Get_parent_tops().size();
					second = (Get_top(list_tops, content))->Get_child_tops().size();
					cout << "Степень графа +: " << first << endl;
					cout << "Степень графа -: " << second << endl;
					return true;
				}
			}
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	//Возвращет либо вторую, либо первую степень ребра
	int Change_one_two_degree(Type content1, Type content2) {
		if (content1 == content2) {
			return 1;
		}
		return 2;
	}

	//Находит степень ребра графа
	bool Find_degree_edge(Type content1, Type content2) {
		try {
			if (!Search_edge(content1, content2)) {
				throw "Такого ребра не существует!\n";
			}
			int degree;
			cout << "Степень ребра графа: " << Change_one_two_degree(content1, content2) << endl;
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
				throw "Такой вершины нет!\n";
			}
			cout << "Ребра, инцидентные вершине: ";
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
				throw "Такой вершины нет!\n";
			}
			cout << "Вершины, смежные с данной: ";
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