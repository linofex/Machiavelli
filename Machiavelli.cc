#include "Machiavelli.h"
#include <iostream> 
#include <cstdlib>
#include <algorithm>


void PrintOp(){
	std::cout << "\n*****************************************" << std::endl;
	std::cout << "* Digita \t  \t  \t \t*\n*\t\"passo\" per passare\t \t*\n*\t\"mossa\" per fare una mossa \t*" << std::endl;
	std::cout << "*****************************************\n" << std::endl;
}

void PrintOp1(){
	std::cout << "\n*****************************************************************" << std::endl;
	std::cout << "* Digita \t\t\t\t\t\t\t*\n*\t\"passo\"   per passare \t\t\t\t\t*\n*\t\"prendi\"  per prendere una carta e cambiarla di posto \t* \n*\t\"ins\"\t  per inserire una carta \t\t\t*\n*\t\"esc\"\t  per riniziare la mossa\t\t\t*"<< std::endl;
	std::cout << "*****************************************************************\n" << std::endl;
}
//ciao

int ChooseNum(){
	bool flag = false;
	int num; 	
	do{
		std::cin >> num;
		if (!std::cin.good()) {
     			std::cin.clear();
        		//std::string ignore;
        		//std::cin >> ignore;
       			while(getchar() != '\n');				
       			continue;
    		}
    		flag = true;
    	}while(!flag);
    	return num;
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
bool Machiavelli::CheckMove(){
	Table::Iterator iter(table);
	while(iter.HasNext()){
		Table::icards c = iter.GetNext();
		if(c.change_){
			//std::cout<< "check"<< std::endl;
			iter.SetChangeF();
			if(!(this->IsTris(*(c.cards_))) && !(this->IsStraight((*c.cards_)))) {
				return false;
			}
		}
	}
	return true;
}


// metodo che fa la mossa
bool Machiavelli::Move(PlayerBase* player_){
	//std::cout << "\033[2J\033[1;1H";
	std::cout << "\nTurno del giocatore: "<< player_->GetName() << std::endl;
	if(!table.Empty()){
		table.PrintTable();
	}
	std::cout << "Le tue carte: " << std::endl;
	player_->SeeCards();
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
		        std::cout << "\033[2J\033[1;1H";
			Card dcard = deck.GetCard();
			player_->AddCard(dcard);
			std::cout <<"La carta "<< dcard << " e' stata aggiunta al tuo mazzo di carte.\n";
		}
		return true;
		std::cout << "\033[2J\033[1;1H";
	}
	else{
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
				if(move != "prendi"  && move != "passo" != 0 && move !="ins" && move !="esc"){		
					while(getchar() != '\n');				
				}
			}while(move != "prendi"  && move != "passo" != 0 && move !="ins" && move !="esc");
			
			 if (move=="ins"){
				std::string cards;
				std::string value;
				std::string suit;
				int num;
				table.PrintTable(); 
				std::cout << "\nScegliere le carte da inserire => ";
				std::cin.ignore();
				std::getline(std::cin, cards);
				if(cards.size() == 0){
					std::cout << "Carte non inserite." << std::endl;
					continue;
				}
				else if(cards == "esc"){
					continue;
				}
				std::stringstream s(cards);
				std::cout <<"Le carte scelte sono: "<< cards << "  Confermi? (s/n) => " ;
				std::string dec;
				std::cin >> dec;
				if(dec == "no" || dec == "n" || dec == "NO"){
					continue;
				}
				while(s >> value) {
					suit = value[value.size() -1];
					value.erase(value.size() -1);
					Card card(value, suit);
					if (!(player_->FindCard(card))){
						std::cout <<  "La carta " << card << "non e' presente. "<< std::endl;
					}
					else if(player_->FindCard(card)) {
						std::cout << "Scegliere il mazzetto dove inserire la carta: " << card << "=> ";
						int num = ChooseNum();
						if(table.AddCard(num , card)){
						//	std::cout << "\nCarta inserita correttamente e tolta dalle carte che hai in mano. \n";
		                                        player_->RemoveCard(card);
		                                        move_flag = true;
						}
					}
				}
				/*
				if(table.Empty()){
				std::cout << "\nTavolo vuoto\n";
				}
				else{
					table.PrintTable();
				}
				*/
			}
			else if (move == "prendi") {
				if(table.Empty()){
                                        std::cout << "\nIl tavolo é vuoto!"<< std::endl;
                                        continue;
                                }
                                else{
                                 table.PrintTable();
                                } 
                                std::string cards;
				std::string value;
				std::string suit;
				std::cout << "\nScegliere la carte da prendere => ";
				std::cin.ignore();
				std::getline(std::cin, cards);
				if(cards.size() == 0){
					std::cout << "Carte non inserite." << std::endl;
					continue;
				}
							
				else if(cards == "esc"){
					continue;
				}
				std::cout <<"Le carte scelte sono: "<< cards << "  Confermi? (s/n) => ";
				std::string dec;
				std::cin >> dec;
				if(dec == "no" || dec == "n" || dec == "NO"|| dec == "N"){
					continue;
				}
				std::stringstream s(cards);
				while(s >> value) {
					suit = value[value.size() -1];
					value.erase(value.size() -1);
					Card card(value, suit);
					bool flag = false;
					std::cout << "Scegliere il mazzetto dove prendere la carta "<< card << "=> ";
					int num = ChooseNum();
					if (!(table.FindCard(num, card))){
						std::cout <<  "La carta "<< card <<"scelta non e' presente nel mazzetto del tavolo."<< std::endl;
					}
					else {
						if(!table.RemoveCard(num, card)){
							std::cout << "Carta non presente";
							continue;
						}
						std::cout << "Scegli mazzetto dove inserire la carta: " << card << "=> ";
						int num_1 = ChooseNum();
						if(table.AddCard(num_1, card)){
							std::cout << "\nCarta "<<card<<"aggiunta correttamente al mazzetto "<< num_1 << std::endl;
							change_flag = true;
						}
						else{
							table.AddCard(num, card);
						}
				
					}
				}
				
			}
	
			else if(move == "esc" && (move_flag == true || change_flag ==true)){
				table.SetTable(old_table);
				player_->SetCards(old_cards);
				std::cout << "Tavolo e carte ripristinate\n";
				change_flag = move_flag = false;				
			}
			table.UpdateTable(); // Cancella mazzi vuoti e ordina le scale
			table.PrintTable(); //stampa il tavolo
		}while(move !="passo");
		//table.UpdateTable(); // Cancella mazzi vuoti		
		std::cout << "\033[2J\033[1;1H";
		if (move_flag == false && change_flag == false){
			if(deck.Empty()){
				std::cout <<"Il mazzo e' vuoto, passi senza pescare carte.\n";
			}
			else {
				Card dcard = deck.GetCard();
				player_->AddCard(dcard);
				std::cout <<"La carta "<< dcard << " e' stata aggiunta al tuo mazzo di carte.\n";
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
				Card dcard = deck.GetCard();
				player_->AddCard(dcard);
				std::cout <<"La carta "<< dcard << " e' stata aggiunta al tuo mazzo di carte.\n";
			}
			return false;
		}
		
		else if (CheckMove()){
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
				Card dcard = deck.GetCard();
				player_->AddCard(dcard);
				std::cout <<"La carta "<< dcard << " e' stata aggiunta al tuo mazzo di carte.\n";
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
