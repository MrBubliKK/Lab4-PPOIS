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
		return nullptr; // Åñëè ýëåìåíò ñ óêàçàííûì ñîäåðæèìûì íå íàéäåí
	}

	vector<pair<Type, Type>> Get_edge(Type content1, Type content2) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
			if ((content1 == it->first) && (content2 == it->second)) {
				return it;
			}
		}
	}

	//Ïðÿìîé ìåòîä äîáàâëåíèÿ âåðøèíû
	void Add_top(Type content) {
		list_tops.push_back(new Top<Type>(content));
	}

	vector<Top<Type>*>& Get_list_tops() {
		return list_tops;
	}

	vector<pair<Type, Type>> Get_list_edges() {
		return list_edges;
	}

	//Ïðÿìîé ìåòîä äîáàâëåíèÿ ðåáðà
	void Add_edge(Type content1, Type content2) {
		list_edges.push_back({ content1, content2 });
	}

	//Èùåò îïðåäåëåííóþ âåðøèíó
	bool Search_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				return true;
			}
		}
		return false;
	}

	//Èùèåò ðåáðî
	bool Search_edge(Type content1, Type content2) {
		for (typename vector<pair<Type, Type>>::iterator it = list_edges.begin(); it != list_edges.end(); it++) {
			if ((content1 == it->first) && (content2 == it->second)) {
				return true;
			}
		}
		return false;
	}

	//Âûâîäèò êîëè÷åñòâî âåðøèí
	void Print_size_tops() {
		cout << "Êîëè÷åñòâî âåðøèí â ãðàôå: " << list_tops.size() << endl;
	}

	//Âûâîäèò êîëè÷åñòâî ðåáåð
	void Print_size_edges() {
		cout << "Êîëè÷åñòâî ðåáåð â ãðàôå: " << list_edges.size() << endl;
	}

	//Ïðÿìîé ìåòîä óäàëåíèÿ âåðøèíû
	bool Del_top(Type content) {
		for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
			if (content == (*it)->Get_content()) {
				list_tops.erase(it);
				return true;
			}
		}
		return false;
	}

	//Ïðÿìîé ìåòîä óäàëåíèÿ ðåáðà
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

	//Óäàëÿåò ðåáðà ñ óäàëåííîé âåðøèíîé
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

	//Ïîëíîöåííûé ìåòîä óäàëåíèÿ âåðøèíû
	bool Del_full_top(Type content) {
		try {
			if (!Search_top(content)) {
				throw "Òàêîé âåðøèíû íåò!\n";
			}
			Del_edges_top(content);
			Del_top(content);
			cout << "Âåðøèíà óäàëåíà.\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}


	//Ïîëíîöåííûé ìåòîä óäàëåíèÿ ðåáðà
	bool Del_full_edge(Type content1, Type content2) {
		try {
			if (!(Search_top(content1)) || !(Search_top(content2))) {
				throw "Îäíîé èç âåðøèí íå ñóùåñòâóåò!\n";
			}
			if (!Search_edge(content1, content2)) {
				throw "Òàêîãî ðåáðà íåò!\n";
			}

			Del_child_parent_top(content1, content2);
			Del_edge(content1, content2);
			cout << "Ðåáðî óäàëåíî.\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	//Ïîëíîöåííîûé ìåòîä äîáàâëåíèÿ âåðøèíû
	bool Add_full_top(Type content) {
		try {
			if (Search_top(content)) {
				throw "Òàêàÿ âåðøèíà óæå åñòü!\n";
			}
			Add_top(content);
			cout << "Âåðøèíà äîáàâëåíà.\n";
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

	//Ïîëíîöåííûé ìåòîä äîáàâëåíèÿ ðåáðà
	bool Add_full_edge(Type content1, Type content2) {
		try {
			if ((!Search_top(content1)) || (!Search_top(content2))) {
				throw "Îäíîé èç âåðøèí íå ñóùåñòâóåò!\n";
			}
			if (Search_edge(content1, content2)) {
				throw "Ðåáðî óæå ñóùåñòâóåò!\n";
			}
			Add_edge(content1, content2);
			Add_child_parent_top(content1, content2);
			cout << "Ðåáðî äîáàâëåíî. <" << content1 << ", " << content2 << ">\n";
			return true;
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	//Íàõîäèò ñòåïåíü âåðøèíû ãðàôà
	bool Find_degree_top(Type content) {
		// first + âõîäÿùèå ðåáðà
		// second - âûõîäÿùèå ðåáðà
		try {
			if (!Search_top(content)) {
				throw "Òàêîé âåðøèíû íåò!\n";
			}
			int first;
			int second;
			for (typename vector<Top<Type>*>::iterator it = list_tops.begin(); it != list_tops.end(); it++) {
				if (content == (*it)->Get_content()) {
					first = (Get_top(list_tops, content))->Get_parent_tops().size();
					second = (Get_top(list_tops, content))->Get_child_tops().size();
					cout << "Ñòåïåíü ãðàôà +: " << first << endl;
					cout << "Ñòåïåíü ãðàôà -: " << second << endl;
					return true;
				}
			}
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			return false;
		}
	}

	//Âîçâðàùåò ëèáî âòîðóþ, ëèáî ïåðâóþ ñòåïåíü ðåáðà
	int Change_one_two_degree(Type content1, Type content2) {
		if (content1 == content2) {
			return 1;
		}
		return 2;
	}

	//Íàõîäèò ñòåïåíü ðåáðà ãðàôà
	bool Find_degree_edge(Type content1, Type content2) {
		try {
			if (!Search_edge(content1, content2)) {
				throw "Òàêîãî ðåáðà íå ñóùåñòâóåò!\n";
			}
			int degree;
			cout << "Ñòåïåíü ðåáðà ãðàôà: " << Change_one_two_degree(content1, content2) << endl;
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
				throw "Òàêîé âåðøèíû íåò!\n";
			}
			cout << "Ðåáðà, èíöèäåíòíûå âåðøèíå: ";
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
				throw "Òàêîé âåðøèíû íåò!\n";
			}
			cout << "Âåðøèíû, ñìåæíûå ñ äàííîé: ";
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
