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

	//flags
	int pos_first_ace = -1;
	int pos_second_ace = -1;
	bool flag_k = false;
	bool flag_two = false;
	
	// Ciclo for che conta Assi, K e 2
	for(int i = 0; i < cards->size(); ++i) {
		// se la carta é un asso e ce ne e' giá uno, aggiungi il secondo
		if(((*cards)[i].GetValue() == "A") && pos_first_ace == -1) {
			pos_first_ace = i;
			(*cards)[pos_first_ace].SetIntValue(1);
		}
		// Indice primo asso
		else if((*cards)[i].GetValue() == "A") {
			pos_second_ace = i;
			(*cards)[pos_second_ace].SetIntValue(1);
		}
		// Presenza di K
		else if((*cards)[i].GetIntValue() == 13) {
			flag_k = true;
		}
		//Presenza di 2
		else if((*cards)[i].GetIntValue() == 2) {
			flag_two = true;
		}
	}
	
	// questo blocco di codice setta il valore numerico dell'asso a 14 se
	// ce ne sono 2, uno viene setta a 14, se ne é solo uno, viene messo a 14
	// solo se c'é un k
	if(pos_first_ace != -1) {
		if(pos_second_ace != -1 && (*cards)[pos_first_ace].GetIntValue() == 1) {
			(*cards)[pos_second_ace].SetIntValue(14);
		}
		else if(flag_k) {
			(*cards)[pos_first_ace].SetIntValue(14);
		}
	}
	//Ordine della scala
	std::sort(cards->begin(), cards->end());
}


void Table::UpdateTable(){
	if(table.empty()){
		return;
	}
	t_map::iterator iter = table.begin(); 
	for(; iter != table.end(); ++iter){
		 if (iter->second.change && !(iter->second.cards.empty()) ){
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
		if(dec == "si" || dec == "s" || dec == "SI"|| dec == "S"){
			this->AddCard(card);
			return true;
		}
		else {
			std::cout << "Carta "<< card << "reinserita nella posizione precedente. "<<std::endl;
			return false;
		}
	}
}

void Table::AddCard(const Card& card){
	table[++n_set].cards.push_back(card);
	table[n_set].change = true;
}

bool Table::FindCard(const int& i, const Card& card) const{
	std::vector<Card>::const_iterator iter = table.at(i).cards.begin();
	for(; iter != table.at(i).cards.end() ; ++iter){ 
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
		return false;
	}
	else {		
		return false;
	}
			
}

void Table::SetTable(const t_map& table_){
	table = table_;
	n_set = table.size();
}

