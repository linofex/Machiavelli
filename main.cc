#include "Machiavelli.h"
#include "PlayerHuman.h"


// In questo main si nota che l'owernship é esterna alla classe machiavelli,
// volendo era possibile gestire i giocatori all'intero del costruttore 
// di machiavelli e deallocarli nel distruttore.

int main(){
	Deck deck;
	if(!deck.Pass()){
		return 0;
	}
	std::vector<PlayerBase*> players;
	int num;
	do{
		std::cout << "Inserisci il numero di giocatori (da 2 a 8): ";
		num = ChooseNum();
	}while(num < 2 || num > 8);
	std::cin.ignore();// ignora l'invio
	for(int i = 1 ; i <= num ; ++i){
		std::string name;
		std::cout << "Inserire il nome del giocatore " << i << std::endl;
		getline(std::cin, name);
		if(name.size() == 0){
			players.push_back(new PlayerHuman());
		}
		else {
			players.push_back(new PlayerHuman(name));
		}
	}
	std::cout << "\033[2J\033[1;1H";	
	Table table;
	Machiavelli Game(players, deck, table);
	Game.Game();
	for(int i = 0 ; i < players.size() ; ++i){
         	delete players[i];
        }
}

