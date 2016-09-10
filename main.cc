#include "Machiavelli.h"
#include "PlayerHuman.h"

int main(){
	Deck deck;
	Table table;
	std::vector<PlayerBase*> players;
	int num;
	std::cout << "Inserisci il numero di giocatori: ";
	std::cin >> num;
	std::cin.ignore();
	for(int i = 1 ; i <= num ; ++i){
		std::string name;
		std::cout << "Inserire il nome del giocatore " << i << std::endl;
		getline(std::cin >> std::skipws, name);
		if(name.size() == 0){
			players.push_back(new PlayerHuman());
		}
		else {
			players.push_back(new PlayerHuman(name));
		}
	}
	std::cout << "\033[2J\033[1;1H";	
	Machiavelli Game(players, deck, table);
	Game.Game();
	for(int i = 0 ; i < num ; ++i){
         	delete players[i];
        }
}

