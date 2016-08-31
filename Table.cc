#include "Table.h"
#include <algorithm>
#include <iostream>
#include <string>
void Table::PrintTable() const{
	t_map::const_iterator iter = table.begin();
	for(; iter != table.end(); ++iter){
		std::cout<< iter->first;
		std::vector<Card>::const_iterator it = iter->second.begin();
		for(; it != iter->second.end(); ++it ){
			std::cout << *it << " "; 
		}
		std::cout<<std::endl;
	}
}

bool Table::AddCard(const int& i, const Card& card){
	t_map::iterator iter = table.find(i);
	if (iter != table.end()){
		table[i].push_back(card);
		return true;
	}
	else{
		std::cout << "Mazzetto non trovato, crearne uno nuovo? (si o  no)\n";
		std::string dec;
		std::cin>>dec;
		if(dec.compare("si")==0){
			this->AddCard(card);
			return true;
		}
		else {
			return false;
		}
	}
}

void Table::AddCard(const Card& card){
	table[n_set].push_back(card);
}

bool Table::FindCard(const int& i, const Card& card) {
	std::vector<Card>::const_iterator iter = table[i].begin();
	for(; iter != table[i].end() ; ++iter){ 
		if(*iter == card){
			return true;
		}
	}
	
	return false;
	
}

bool Table::RemoveCard(const int& i, const Card& card){
	t_map::iterator iter = table.find(i);
	if (iter != table.end()){
		std::vector<Card>::iterator it = table[i].begin();
		for(; it!= table[i].end(); ++it){
			if (*it == card){
				table[i].erase(it);
				return true;
			}
		}
	}
	else {
		std::cout << "Carta non presente";
		return false;
	}
			
}

void Table::SetTable(const t_map& table_){
	table= table_;
}

