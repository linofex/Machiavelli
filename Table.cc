#include "Table.h"
#include <algorithm>
#include <iostream>
#include <string>

void Table::PrintTable() const {
	if(table.empty()){
		return;
	}
	std::cout << "Tavolo:" << std::endl;
	t_map::const_iterator iter = table.begin(); 
	for(; iter != table.end(); ++iter){
		if(!(iter->second.empty())){
			std::cout<<"Mazzetto: " << iter->first<< std::endl;
			std::vector<Card>::const_iterator it = iter->second.begin();
			for(; it != iter->second.end(); ++it ){
			std::cout << *it;
			}
		std::cout<<std::endl;
		std::cout<<std::endl;
		}
	}
}

bool Table::UpdateTable(){
	if(table.empty()){
		return true;
	}
	t_map::iterator iter = table.begin(); 
	for(; iter != table.end(); ++iter){
		if((iter->second.empty())){
			table.erase(iter);
		}
	
	}
	return true;
}


bool Table::Empty() const {
	return table.empty();
}


bool Table::AddCard(const int& i, const Card& card){
	t_map::iterator iter = table.find(i);
	if (iter != table.end()){
		table[i].push_back(card);
		return true;
	}
	else{
		std::cout << "Mazzetto non trovato, crearne uno nuovo? (s/n) => ";
		std::string dec;
		std::cin>>dec;
		if(dec == "si" || dec == "s" || dec == "SI"){
			this->AddCard(card);
			return true;
		}
		else {
			std::cout << "Carta "<< card << "reinserita nelle carte sul tavolo nel mazzaetto "<<i<<std::endl;
			return false;
		}
	}
}

void Table::AddCard(const Card& card){
	table[++n_set].push_back(card);
}

bool Table::FindCard(const int& i, const Card& card){
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
	table = table_;
	n_set = table.size();
}

