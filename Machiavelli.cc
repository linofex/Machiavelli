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
	for (int i=0 ; i < players.size() ; ++i ){
		players[i]->SortCard();
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
		if (!Card::CompareSuit(cards[0], cards[i])) {
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
		if(!(this->IsTris(iter->second)) && !(this->IsStraight(iter->second))) {
			return false;
		}
	}
	return true;
}


// metodo che fa la mossa
bool Machiavelli::Move(PlayerBase* player_){
	std::cout << "\nTurno del giocatore: "<< player_->GetName() << std::endl;
	std::cout << "Le tue carte: " << std::endl;
	player_->SeeCards();
	if(!table.Empty()){
		table.PrintTable();
	}
	std::string move;
	do {
		PrintOp();
		std::cin >> move;
	}while(move !="mossa"  && move != "passo");
	if (move=="passo"){
		if(deck.Empty()){
			std::cout << "\nIl mazzo e' vuoto, passi senza pescare carte.\n";
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
			}while(move != "prendi"  && move != "passo" != 0 && move !="ins");
			if(move=="passo"){
					if (flag == 0) {
						if(deck.Empty()){
							std::cout <<"Il mazzo e' vuoto, passi senza pescare carte.\n";
						}
						else {
							player_->AddCard(deck.GetCard());
							std::cout <<"Nuova carta aggiunta al tuo mazzo di carte.\n";
						}
					}
			}
			else if (move=="ins"){
					std::string value;
					std::string suit;
					int num;
					table.PrintTable(); 
					std::cout << "\nScegliere in ordine: il numero del mazzo (o aggiungine uno) e la carta da inserire:\n";
					player_->SeeCards();
					std::cin >> num >> value >> suit;
					Card card(value, suit);
					std::cout << card;
					if (!(player_->FindCard(card))){
						std::cout <<  "Non hai la carta scelta, riprova."<< std::endl;
					}
					else{
						if(table.AddCard(num , card)){
							std::cout << "\nCarta inserita correttamente e tolta dalle carte che hai in mano. \n";
	                                                player_->RemoveCard(card);
						}
						if(table.Empty()){
							std::cout << "\nTavolo vuoto\n";
						}
						else{
							table.PrintTable();
						}
						flag = 1;
						move_flag = 1;
					}
			}
			else {
				std::string value;
				std::string suit;
				int num; 
				if(table.Empty()){
					std::cout << "\nIl tavolo é vuoto!"<< std::endl;
					continue;
				}
				else{
				 table.PrintTable();
				}
				std::cout << "\nScegliere in ordine: il numero del mazzo (o aggiungine uno) e la carta da prendere:\n";
				std::cin >> num >> value >> suit;
				Card card(value, suit);
				if (!table.FindCard(num, card)){
					std::cout << "\nSul tavolo non c'e' la carta scelta, riprova."<< std::endl;
				}
				else{
					if(table.RemoveCard(num, card)){
						std::cout<< "\nCarta rimossa correttamente dal mazzetto." << num << std::endl;
						table.PrintTable();
					}
					else{
						continue;
					}
					std::cout << "\nScegli mazzetto dove inserirla:\n";
					std::cin >> num;
					if(table.AddCard(num, card)){
						std::cout << "\nCarta aggiunta correttamente al mazzetto "<< num << std::endl;
						table.PrintTable();
					}
				}
			}
		}while(move !="passo");
	
		if (move_flag == 0){
			std::cout << "\nPer fare una mossa e' necessario Inserire almeno una carta!\n";
			std::cout << "\nMossa NON valida, ripristino tavolo e carte giocatore.\n";
			player_->AddCard(deck.GetCard());
			std::cout << "\nNuova carta aggiunta al tuo mazzo di carte.\n";
			player_->SetCards(old_cards);
			table.SetTable(old_table);
			return false;
		}
		else if (CheckMove(table.GetTable())){
			std::cout<< "\nMossa valida"<< std::endl;
			return true;
		}	
// Se la mossa non é valida, vengono settati i vecchi tavoli e mazzi
// COSA FARE PERO'?? pesca una carta?
		else { 
			std::cout<< "\nMossa NON valida, ripristino tavolo e carte giocatore." << std::endl;
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
