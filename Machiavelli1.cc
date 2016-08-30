#include "Machiavelli.h"
#include <sstream>
#include <iostream> 

// This function prints the menu of each move
void PrintOp(){
	std::cout<<"***********************************************************"<<std::endl;
	std::cout<<"* Digita \"passo\" per passare o \"mossa\" per fare una mossa *"<<std::endl;
	std::cout<<"***********************************************************"<<std::endl;
}

// This function prints the menu of each move
void PrintOp1(){
	std::cout<<"****************************************************************"<<std::endl;
	std::cout<<"* Digita \"passo\" per passare o \"prendi\" per prendere una carta * \n* e cambiarla di posto \"ins\" per inserire carta \t       *"<<std::endl;
	std::cout<<"****************************************************************"<< std::endl;
}

// This method deals the cards 
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
			    	return false;
		}
		for(int j = i+1 ; j <  cards.size(); ++j){
			if (Card::CompareSuit(cards[i], cards[j]) == 0){
				return false;
			}
		}
	}
	return 1;
}
bool Machiavelli::IsStraight(const std::vector<Card>& cards)const {
	if (cards.size() < 3) {
		return false;
	}
	for (int i = 0; i < cards.size();++i){
		if (Card::CompareSuit(cards[0], cards[i])){
			return false;
		}
		if(cards[cards.size()-2].GetIntValue() == 13 && cards[cards.size()-1].GetIntValue() != 1){return false;} 
		if(cards[i].GetIntValue() != 13){ 
			if(i < (cards.size() - 1) && cards[i].GetIntValue() != (cards[i+1].GetIntValue() -1)){
				return false;
			}
		}
		else{
			if (cards[i+1].GetIntValue() != 1) {return false;}
		}
		
	}
	return 1;
	
}


bool Machiavelli::CheckMove(const t_map& table)const {
	t_map::const_iterator iter = table.begin();
	for(; iter != table.end(); ++iter){
		if(!(this->IsTris(iter->second)) || !(this->IsStraight(iter->second))){
			return false;
		}
	}
	return true;
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
		int flag_move = 0;
		t_map old_table = table.GetTable();
		std::vector<Card> old_cards = player_->GetCards();
		do{
			do {
				PrintOp1();
				std::cin >> move;
			}while(move.compare("prendi") != 0 || move.compare("passo") != 0 || move.compare("ins"));
			if(move.compare("passo") == 0){
					if (flag == 0)
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
						table.AddCard(num , card);
						player_->RemoveCard(card);
						flag = 1;
						flag_move = 1;
					}
					}
				else {
					std::string value;
					std::string suit;
					int num;
					table.PrintTable(); 
					std::cout << "Scegliere in ordine: il numero del mazzo e la carta da prendere\n";
					std::cin >> num >> value >> suit;
					Card card(value, suit);
					if (!table.FindCard(num, card)){
						std::cout <<  "Sul tavolo non c'e' la carta scelta, o mazzo erratp. Riprova"<< std::endl;
					}
					else{
						table.RemoveCard(num, card);
						std::cout << "Scegli mazzetto dove inserirla:\n";
						std::cin >> num;
						table.AddCard(num, card);
						flag = 1;
					}
				}
			}while(move.compare("passo") != 0 && flag_move != 0);
		if (CheckMove(table.GetTable())){
			return 1;
		}
		else {
			player_->SetCards(old_cards);
			table.SetTable(old_table);
			return 0;
		}
		}
		
	}
	


