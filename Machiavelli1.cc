#include "Machiavelli.h"
#include <sstream>
#include <iostream> 

void PrintOp(){
	std::cout<<"***********************************************************"<<std::endl;
	std::cout<<"* Digita \"passo\" per passare o \"mossa\" per fare una mossa *"<<std::endl;
	std::cout<<"***********************************************************"<<std::endl;
}

void PrintOp1(){
	std::cout<<"****************************************************************"<<std::endl;
	std::cout<<"* Digita \"passo\" per passare o \"prendi\" per prendere una carta * \n* e cambiarla di posto \"ins\" per inserire carta \t       *"<<std::endl;
	std::cout<<"****************************************************************"<< std::endl;
}

void Machiavelli::DealCards(){
	int cards_num = 13;
	for (int j = 0; j < 13 ; ++j){
		for(int i = 0; i < players.size() ; ++i){
			players[i]->AddCard(deck.GetCard());
		}
	}
}


bool Machiavelli::IsTris(const std::vector<Card>& cards)const {
	if (cards.size() < 3) {return 0;}
	for (int i = 0; i < cards.size();++i){
		if (Card::CompareValue(cards[0], cards[i]) != 0){
			    	return 0;
		}
		for(int j = i+1 ; j <  cards.size(); ++j){
			if (Card::CompareSuit(cards[i], cards[j]) == 0){
				return 0;
			}
		}
	}
	return 1;
}
bool Machiavelli::IsStraight(const std::vector<Card>& cards)const {
	if (cards.size() < 3) {return 0;}
	for (int i = 0; i < cards.size();++i){
		if (Card::CompareSuit(cards[0], cards[i]) != 0){
			return 0;
		}
		if(cards[cards.size()-2].GetIntValue() == 13 && cards[cards.size()-1].GetIntValue() != 1){return 0;} 
		if(cards[i].GetIntValue() != 13){ 
			if(i < (cards.size() - 1) && cards[i].GetIntValue() != (cards[i+1].GetIntValue() -1)){
				return 0;
			}
		}
		else{
			if (cards[i+1].GetIntValue() != 1) {return 0;}
		}
		
	}
	return 1;
	
}


bool Machiavelli::CheckMove(const t_map& table)const {
	t_map::const_iterator iter = table.begin();
	for(; iter != table.end(); ++iter){
		if(!(this->IsTris(iter->second)) || !(this->IsStraight(iter->second))){
			return 0;
		}
	}
	return 1;
}

bool Machiavelli::Move(PlayerBase* player_){
	std::string move;
	do {
		PrintOp();
		std::cin >> move;
	}while(move.compare("move") != 0 || move.compare("passo") != 0);
	if (move.compare("passo") == 0){
		player_->AddCard(deck.GetCard());
		return 1;
	}
	else{
		int flag = 0;
		Table new_table = table;
		do{
			do {
				PrintOp1();
				std::cin >> move;
			}while(move.compare("prendi") != 0 || move.compare("passo") != 0 || move.compare("ins"));
			if(move.compare("passo") == 0){
					if (flag)
						player_->AddCard(deck.GetCard());
					return 1;
			}
			else if (move.compare("ins") == 0){
					std::string value;
					std::string suit;
					int num;
					table.PrintTable(); 
					std::cout << "Scegliere in ordine: il numero del mazzo (o aggiungine uno) e la carta da inserire\n";
					player_->SeeCards();
					std::cin >> num >> value >> suit;
					Card card(value, suit);
					if (!player_->FindCard(card)){
						std::cout <<  "Non hai la carta scelta, riprova"<< std::endl;
					}
					else{
						new_table.AddCard(num , card);
						flag=1;
					}
					}
				else {
					std::string value;
					std::string suit;
					int num;
					table.PrintTable(); 
					std::cout << "Scegliere in ordine: il numero del mazzo (o aggiungine uno) e la carta da prendere\n";
					std::cin >> num >> value >> suit;
					Card card(value, suit);
					if (!new_table.FindCard(num, card)){
						std::cout <<  "Sul tavolo non c'e' la carta scelta, riprova"<< std::endl;
					}
					else{
						new_table.RemoveCard(num, card);
						std::cout << "Scegli mazzetto dove inserirla:\n";
						std::cin >> num;
						new_table.AddCard(num, card);
						flag = 1;
					}
					}
			}	while(move.compare("passo") != 0);
		if (CheckMove(new_table.GetTable())){
			return 1;
			table = new_table;
		}
		else {return 0;}
		}
		
	}
	


