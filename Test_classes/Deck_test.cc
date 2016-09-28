#include "Deck.h"

class TestDeck{
	public:
		TestDeck(){
			std::cout << "Questa classe test instanzia due deck, uno\
			con costruttore di default chiamato deck e uno con file.txt\
			 personale chiamato deck1\n";
			Deck deck;
			Deck deck1("./Deck_test.txt");
			if(!deck.Pass()){
				std::cout << "ERRORE! Il costruttore di default ha \
						riscontrato un errore nella lettura del file.\n Test fallito\n";
				return;
			}
			else{
				std::cout << "CORRETTO! Costruttore di default corretto\n";
			}
			if(!deck1.Pass()){
				std::cout << "ERRORE! Il costruttore NON di default ha \
						riscontrato un errore nella lettura del file.\n Test fallito\n";
				return;
			}
			else{
				std::cout << "CORRETTO! Costruttore NON di default corretto\n";
			}
			if(deck.Empty()){
				if(!deck.deck.empty()){
					std::cout << "ERRORE! deck risulta vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck e' effettivamente vuoto;";
				}
			}
			else {
				if(deck.deck.empty()){
					std::cout << "ERRORE! deck risulta NON vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck e' effettivamente NON vuoto;";
				}
			}
			
			if(deck1.Empty()){
				if(!deck1.deck.empty()){
					std::cout << "ERRORE! deck1 risulta vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck1 e' effettivamente vuoto;";
				}
			}
			else {
				if(deck1.deck.empty()){
					std::cout << "ERRORE! deck1 risulta NON vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck1 e' effettivamente NON vuoto;";
				}
			}
			
			std::cout << "I due deck vengono svuotati e ripeto la prova\n";
			deck.deck.clear();
			deck1.deck.clear();
			
			
			
			if(deck.Empty()){
				if(!deck.deck.empty()){
					std::cout << "ERRORE! deck risulta vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck e' effettivamente vuoto;";
				}
			}
			else {
				if(deck.deck.empty()){
					std::cout << "ERRORE! deck risulta NON vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck e' effettivamente NON vuoto;";
				}
			}
			
			if(deck1.Empty()){
				if(!deck1.deck.empty()){
					std::cout << "ERRORE! deck1 risulta vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck1 e' effettivamente vuoto;";
				}
			}
			else {
				if(deck1.deck.empty()){
					std::cout << "ERRORE! deck1 risulta NON vuoto, ma non lo e'.\n";
				}
				else{
					std::cout << "CORRETTO! deck1 e' effettivamente NON vuoto;";
				}
			}
			
	}	
};

