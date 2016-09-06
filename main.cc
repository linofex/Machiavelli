#include "Machiavelli.h"

int main(){
	Deck deck;
	Table table;
	std::vector<PlayerBase*> players;
	int num;
	std::cout << "Inserisci il numero di giocatori: ";
	std::cin >> num;
	std::cin.ignore();
	for(int i = 0 ; i < num ; ++i){
		std::string name;
		std::cout << "Inserire il nome del giocatore " << i << std::endl;
		getline(std::cin >> std::skipws, name);
		players.push_back(new PlayerBase(name));
	}	
	Machiavelli Game(players, deck, table);
	Game.Game();
	for(int i = 0 ; i < num ; ++i){
         	delete players[i];
        }
}

