#include "Table.h"
#include <algorithm>
#include <iostream>
#include <string>

void Table::PrintTable() const {
	if(table.empty()){
		return;
	}
	std::cout << "\nTAVOLO:" << std::endl;
	t_map::const_iterator iter = table.begin(); 
	for(; iter != table.end(); ++iter){
		if(!(iter->second.cards.empty())){
			std::cout<<"Mazzetto " << iter->first<< ": ";
			std::vector<Card>::const_iterator it = iter->second.cards.begin();
			for(; it != iter->second.cards.end(); ++it ){
			std::cout << *it;
			}
		std::cout<<std::endl;
		std::cout<<std::endl;
		}
	}
}

void Table::SetStraight(std::vector<Card>* cards){
	if(cards->size() < 3) {
		return;
	}
	for(int i = 1; i < cards->size(); ++i) {
		if(!Card::CompareSuit((*cards)[0], (*cards)[i])) {
			return;
		}
	}	
	//flags
	int pos_first_ace = -1;
	int pos_second_ace = -1;
	int flag_k = 0;
	int flag_two = 0;
	
	//
	for(int i = 0; i < cards->size(); ++i) {
		if(((*cards)[i].GetValue() == "A") && pos_first_ace == -1) {
			pos_first_ace = i;
		}
		else if((*cards)[i].GetValue() == "A") {
			pos_second_ace = i;
		}
		else if((*cards)[i].GetIntValue() == 13) {
			flag_k = 1;
		}
		else if((*cards)[i].GetIntValue() == 2) {
			flag_two = 1;
		}
	}
	
	if(pos_first_ace != -1) {
		if(pos_second_ace != -1) {
			(*cards)[pos_second_ace].SetIntValue(14);
		}
		else if(flag_k == 1) {
			(*cards)[pos_first_ace].SetIntValue(14);
		}
	}
	std::sort(cards->begin(), cards->end());
}



void Table::UpdateTable(){
	if(table.empty()){
		return;
	}
	t_map::iterator iter = table.begin(); 
	for(; iter != table.end(); ++iter){
		if((iter->second.cards.empty())){
			table.erase(iter);
		}
		else if (iter->second.change){
			//std::cout<< "check Up"<< std::endl;
			SetStraight(&(iter->second.cards));
		}
	
	}
	return;
}


bool Table::Empty() const {
	return table.empty();
}


bool Table::AddCard(const int& i, const Card& card){
	t_map::iterator iter = table.find(i);
	if (iter != table.end()){
		table[i].cards.push_back(card);
		table[i].change = true;
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
	table[++n_set].cards.push_back(card);
	table[n_set].change = true;
}

bool Table::FindCard(const int& i, const Card& card){
	std::vector<Card>::const_iterator iter = table[i].cards.begin();
	for(; iter != table[i].cards.end() ; ++iter){ 
		if(*iter == card){
			return true;
		}
	}
	return false;	
}

bool Table::RemoveCard(const int& i, const Card& card){
	t_map::iterator iter = table.find(i);
	if (iter != table.end()){
		std::vector<Card>::iterator it = table[i].cards.begin();
		for(; it!= table[i].cards.end(); ++it){
			if (*it == card){
				table[i].cards.erase(it);
				table[i].change = true;
				return true;
			}
		}
	}
	else {		
		return false;
	}
			
}

void Table::SetTable(const t_map& table_){
	table = table_;
	n_set = table.size();
}

