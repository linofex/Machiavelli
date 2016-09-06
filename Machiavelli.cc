#include "Machiavelli.h"
#include <iostream> 
#include <cstdlib>
void PrintOp(){
	std::cout << "\n***********************************************************" << std::endl;
	std::cout << "* Digita \"passo\" per passare o \"mossa\" per fare una mossa *" << std::endl;
	std::cout << "***********************************************************\n" << std::endl;
}

void PrintOp1(){
	std::cout << "\n****************************************************************" << std::endl;
	std::cout << "* Digita \"passo\" per passare o \"prendi\" per prendere una carta * \n* e cambiarla di posto \"ins\" per inserire una carta \t      *\n* o" << std::endl;
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
			std::cout <<"Nuova carta aggiunta al tuo mazzo di carte.\n";
		}
		return true;
	}
	else{
		//bool flag = false; //flag per il passo senza prelevare una carta
		bool move_flag = false; //flag che evita mossa senza inserire carte
		bool change_flag = false; // flag che non aggiorna il tavolo con passo dopo ins
					 // senza che si faccia niente.
		t_map old_table = table.GetTable(); //tavolo vecchio
		int old_n_set = table.GetNset(); //n_set vecchi
		std::vector<Card> old_cards = player_->GetCards(); //mazzo di carte in mano vecchio
		do{
			do {
				PrintOp1();
				std::cout << "Le tue carte: " << std::endl;
				player_->SeeCards();
				std::cout<<std::endl;
				std::cin >> move;
			}while(move != "prendi"  && move != "passo" != 0 && move !="ins");
			
			 if (move=="ins"){
			 	int flag_cards = 0;
				std::string cards;
				std::string value;
				std::string suit;
				char s_num;
				int num;
				table.PrintTable(); 
				std::cout << "\nScegliere in ordine: il numero del mazzo (o aggiungine uno) e la carta da inserire.\n";
				//player_->SeeCards();
				std::cin >> s_num;
				std::cin.ignore();
				std::getline(std::cin, cards);
				if(cards.size() == 0){
					std::cout << "Carte non inserite." << std::endl;
					continue;
				}
				std::stringstream s(cards);
				if(isdigit(s_num)){
					num = atoi(&s_num);
				}
				else{
					continue;
				}
				std::cout <<"Le carte scelte sono: "<< cards << "  Confermi? (s/n)" << std::endl;
				std::string dec;
				std::cin >> dec;
				if(dec == "no" || dec == "n" || dec == "NO"){
					continue;
				}
				while(s >> value) {
					suit = value[value.size() -1];
					value.erase(value.size() -1);
					Card card(value, suit);
					if (!(player_->FindCard(card)) && flag_cards == 0){
						flag_cards = 1;
						std::cout <<  "Non hai almeno una delle carte scelte."<< std::endl;
					}
					else if(player_->FindCard(card)) {
						if(table.AddCard(num , card)){
						//	std::cout << "\nCarta inserita correttamente e tolta dalle carte che hai in mano. \n";
		                                        player_->RemoveCard(card);
						}
					}
				}
				if(table.Empty()){
				std::cout << "\nTavolo vuoto\n";
				}
				else{
					table.PrintTable();
				}
				move_flag = true;
				}
			else if (move == "prendi") {
				if(table.Empty()){
                                        std::cout << "\nIl tavolo é vuoto!"<< std::endl;
                                        continue;
                                }
                                else{
                                 table.PrintTable();
                                }

				std::string value;
				std::string suit;
				int num; 
				std::cout << "\nScegliere in ordine: il numero del mazzo (o aggiungine uno) e la carta da prendere.\n";
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
						change_flag = true;
						table.PrintTable();
					}
				}
			}
		}while(move !="passo");
		
		std::cout << "\033[2J\033[1;1H";
		if (move_flag == false && change_flag == false){
			if(deck.Empty()){
				std::cout <<"Il mazzo e' vuoto, passi senza pescare carte.\n";
			}
			else {
				player_->AddCard(deck.GetCard());
				std::cout <<"Nuova carta aggiunta al tuo mazzo di carte.\n";
			}
		}
		else if (move_flag == false && change_flag == true){
			std::cout << "\nPer fare una mossa e' necessario INSERIRE almeno una carta!\n";
			std::cout << "\nMossa NON valida, ripristino tavolo e carte giocatore.\n";
			player_->SetCards(old_cards);
			table.SetTable(old_table);
			if(deck.Empty()){
				std::cout <<"Il mazzo e' vuoto, passi senza pescare carte.\n";
			}
			else {
				player_->AddCard(deck.GetCard());
				std::cout <<"Nuova carta aggiunta al tuo mazzo di carte.\n";
			}
			return false;
		}
		else if (CheckMove(table.GetTable())){
			std::cout<< "\nMossa valida"<< std::endl;
			return true;
		}	
		else { 
			std::cout<< "\nMossa NON valida, ripristino tavolo e carte giocatore." << std::endl;
			player_->SetCards(old_cards);
			if(deck.Empty()){
				std::cout <<"Il mazzo e' vuoto, passi senza pescare carte.\n";
			}
			else {
				player_->AddCard(deck.GetCard());
				std::cout <<"Nuova carta aggiunta al tuo mazzo di carte.\n";
			}
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
