#ifndef CARD_H
#define CARD_H

/*Questa classe realizza una carta da gioco di un mazzo di carte francese.
il dato privato val e' utilizzato per rendere il confronto di carte piú 
agevole, dando ad gni carta un valore numerico da 1 a 13. L'asso puo' avere 
due valori, 1 oppure 14, dato che puo' stare anche alla destra di un K 
in una scala.*/

#include <string>
#include <iostream>
#include <sstream>
class Card{
	private:
		std::string value;
		std::string suit;
		int val;
	public:
		// Costruttore
		Card(const std::string& value_, const std::string& suit_);
		
		// Metodo per controllare l'esistenza di una carta
		bool Exist() const;
		
		// Metodo che ritorna il valore della carta
		inline std::string GetValue() const {
			return value;
		}

		// Setter che setta il valore intero della carta
		void SetIntValue(const int& val_);

		
		// Metodo che ritorna il seme della carta
		inline std::string GetSuit() const {
			return suit;
		}
		
		// Metodo che ritorna il valore numerico della carta
		inline int GetIntValue() const {
			return val;
		}
		
		// Metodo statico che compara il valore di due carte
		static bool CompareValue(const Card& left, const Card& right);
		
		// Metodo statico che compara il seme di due carte
		static bool CompareSuit(const Card& left, const Card& right);
		
};

// Operatore che confronta se due carte sono uguali
bool operator==(const Card& left, const Card& right);

// Operatore che stampa una carta
std::ostream& operator<<(std::ostream& out, const Card& card);

// Operatore che confronta due carte
bool operator<(const Card& left, const Card& right);

#endif
