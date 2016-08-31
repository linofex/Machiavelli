#include "Machiavelli.h"
#include <iostream> 

void PrintOp(){
	std::cout << "\n***********************************************************" << std::endl;
	std::cout << "* Digita \"passo\" per passare o \"mossa\" per fare una mossa *" << std::endl;
	std::cout << "***********************************************************\n" << std::endl;
}

void PrintOp1(){
	std::cout << "\n****************************************************************" << std::endl;
	std::cout << "* Digita \"passo\" per passare o \"prendi\" per prendere una carta * \n* e cambiarla di posto \"ins\" per inserire carta \t       *" << std::endl;
	std::cout << "****************************************************************\n" << std::endl;
}

// metodo per distribuire le carte
// distribuisce una carta alla volta per ogni giocatore
void Machiavelli::DealCards() {
	for(int j = 0; j < 13 ; ++j) {
		for(int i = 0; i < players.size() ; ++i) {
			players[i]->AddCard(deck.GetCard());
		}
	}
}

// metodo che controlla se una certa combinazione e` un tris o un quadris
bool Machiavelli::IsTris(const std::vector<Card>& cards) const {
	if(cards.size() < 3 || cards.size() > 4) {
		return false;
	}
	for(int i = 0; i < cards.size(); ++i) {
		if(!Card::CompareValue(cards[0], cards[i])) {
			return false;
		}
		for(int j = i + 1 ; j <  cards.size(); ++j) {
			if (Card::CompareSuit(cards[i], cards[j])) {
				return false;
			}
		}
	}
	return true;
}

// metodo che controlla se una certa combinazione e` una scala
bool Machiavelli::IsStraight(const std::vector<Card>& cards) const {
	if (cards.size() < 3) {
		return false;
	}
// Primo ciclo for per vedere se le carte sono tutte dello stesso seme
	for (int i = 1; i < cards.size(); ++i) {
		if (Card::CompareSuit(cards[0], cards[i])) {
			return false;
		}
	}

// Secondo ciclo for per vedere se le carte formano una scala effettiva
	for (int i = 0; i < (cards.size() - 1); ++i) {
		if(cards[i].GetIntValue() != 13) { // carte diverse dai re
// If che controlla se la carta succ -1 é la stessa della carta i-esima
			if(cards[i].GetIntValue() != (cards[i+1].GetIntValue() - 1)) { 
				return false;
			}
		}
		else{
			if (cards[i + 1].GetIntValue() != 1) {
				return false;
			}
		}
	}
	return true;
}

// metodo che controlla la mossa del giocatore
bool Machiavelli::CheckMove(const t_map& table) const {
	t_map::const_iterator iter = table.begin();
	for(; iter != table.end(); ++iter) {
		if(!(this->IsTris(iter->second)) || !(this->IsStraight(iter->second))) {
			return false;
		}
	}
	return true;
}


// metodo che fa la mossa
bool Machiavelli::Move(PlayerBase* player_){
	std::string move;
	do {
		PrintOp();
		std::cin >> move;
	}while(move.compare("move") != 0 && move.compare("passo") != 0);
	if (move.compare("passo") == 0){
		if(deck.Empty()){
			std::cout << "Il mazzo e' vuoto, passi senza pescare carte.\n";
		}
		else {
			player_->AddCard(deck.GetCard());
		}
		return true;
	}
	else{
		int flag = 0; //flag per il passo senza prelevare una carta
		int move_flag = 0; //flag che evita mossa senza inserire carte
		t_map old_table = table.GetTable(); //tavolo vecchio
		std::vector<Card> old_cards = player_->GetCards(); //mazzo di carte in mano vecchio
		do{
			do {
				PrintOp1();
				std::cin >> move;
			}while(move.compare("prendi") != 0 && move.compare("passo") != 0 && move.compare("ins") != 0);
			if(move.compare("passo") == 0){
					if (flag == 0) {
						if(deck.Empty()){
							std::cout << "Il mazzo e' vuoto, passi senza pescare carte.\n";
						}
						else {
							player_->AddCard(deck.GetCard());
						}
					}
					return true;
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
						move_flag = 1;
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
				if (!table.FindCard(num, card)){
					std::cout <<  "Sul tavolo non c'e' la carta scelta, riprova"<< std::endl;
				}
				else{
					table.RemoveCard(num, card);
					std::cout << "Scegli mazzetto dove inserirla:\n";
					std::cin >> num;
					table.AddCard(num, card);
					flag = 1;
				}
			}
		}while(move.compare("passo") != 0 && move_flag == 0); // La mossa finisce con passo E flag_move == 0!
		if (CheckMove(table.GetTable())){
			return true;
		}
// Se la mossa non é valida, vengono settati i vecchi tavoli e mazzi
// COSA FARE PERO'?? pesca una carta?
		else { 
			player_->SetCards(old_cards);
			table.SetTable(old_table);
			return false;
		}
	}	
}

void Machiavelli::Game(){
	deck.Shuffle();
	DealCards();
	int win = 0;
	while(win == 0){
		for(int i = 0; i < players.size(); ++i){
			Move(players[i]);
			if(players[i]->Empty()){
				std::cout << "Il giocatore " << i << " vince!" << std::endl;
				win = 1;
				break;
			}
		}
	}
	return;
}
