#ifndef TABLE_H
#define TABLE_H

/*Questa classe realizza un tavolo in cui ci sono le combinazioni di carte. 
E' possibile stampare il tavolo, inserirne un altro,  rimuovere e aggiungere 
singole carte.
*/

#include <map>
#include <vector>
#include "Card.h"

// Questa struttura e' composta da un vettore di carte che rappresenta il mazzetto
// e un  valore booleano se il mazzetto e' stato cambiato.
struct vector_m{
	std::vector<Card> cards;
	bool change;
};

typedef std::map<int, vector_m> t_map;

class Table{
	private:
		
		t_map table; //mappa che num mazzetto --> mazzetto
		int n_set; // variabile che tiene il conto dei mazzetti 
		// Questo metodo privato ordina una scala e inserisce l'asso
		// nel posto giusto. Prende in input un puntatore al mazzo
		void SetStraight(std::vector<Card>* cards); 
	public:
		// Costruttore di default 
		Table():n_set(0){}
		// Costruttore che prende in input un tavolo giá fatto
		Table(const t_map& table_):table(table_){
			n_set = table.size();
		}
		// Metodo const che stampa il tavolo
		void PrintTable() const;
		
		// Getter che ritorna il tavolo. 
		// Ritorna una const reference perché puo' essere pesante ritornare
		// per copia
		inline const t_map& GetTable() const { 
			return table; 
		}
		
		//Getter che ritorna il numero di mazzetti
		inline int GetNset()const{
			return n_set;
		}
		
		// Setter che setta il tavolo
		void SetTable(const t_map& table_);
		
		// Metodo che aggiunge una carta ad un nuovo mazzetto
		// numerato con n_set
		void AddCard(const Card& card );
		
		// Metodo che aggiunge una carta ad un mazzetto i e ritorna
		// se l'ha aggiunta o meno
		bool AddCard(const int& i, const Card& card);
		
		// Metodo che rimuove una carta da un mazzetto i e ritorna
		// se l'ha rimossa o meno
		bool RemoveCard(const int& i, const Card& card);
		
		// Metodo che cerca una carta in un mazzetto i e ritorna 
		// se l'ha trovata 
		bool FindCard(const int& i, const Card& card) const;
		
		// Metodo che sistema il tavolo (toglie i mazzetti vuoti)
		void UpdateTable();
		
		// Metodo che controlla se il tavolo e' vuoto
		bool Empty() const;

// Iteratore che itera nel tavolo

		// Questa struct serve per ritorna il mazzetto e lo stato della
		// sua modifica
		struct icards{
			const std::vector<Card> * cards_;
			bool change_;
		};
		
		// Iteratore non const, perché il tavolo puo' essere modificato
		class Iterator{
			private:
				t_map::iterator iter;
				Table* itable;
		
			public:
				Iterator(Table& table_){
					itable = &table_;
					iter= itable->table.begin();
				}
				// Questo metodo ritorna il mazzetto
				inline icards GetNext(){
					icards c = {NULL, false};
					c.cards_ = &(iter->second.cards);
					c.change_ = iter->second.change;
					++iter;
					return c;
				}
				
				// Questo metodo setta lo stato del mazzetto false
				void SetChangeF(){
					(--iter)->second.change = false;
					++iter;
				}
				
				// Questo metodo setta lo stato del mazzetto true
				void SetChangeT(){
					(--iter)->second.change = true;
					++iter;
				}
				// Questo metodo ritorna se il tavolo é finito
				inline bool HasNext() const {
					return iter != itable->table.end();
				}
		};

	friend class Iterator;	
};

#endif
