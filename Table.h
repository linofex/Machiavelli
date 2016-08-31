#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <vector>
#include "Card.h"

typedef std::map<int, std::vector<Card> > t_map;

class Table{
	private:
		
		t_map table;
		int n_set; //Optional
	public:
		Table(const t_map& table_):table(table_), n_set(0){
			t_map::const_iterator iter = table.begin();
			while(iter != table.end()){
				n_set++;
			}
		}
		Table():n_set(0){}
		void PrintTable() const;
		inline t_map GetTable(){ return table; }
		void SetTable(const t_map& table_);
		void AddCard(const Card& card );
		bool AddCard(const int& i, const Card& card);
		bool RemoveCard(const int& i, const Card& card);
		bool FindCard(const int& i, const Card& card);
		inline void UpdateTable(const t_map& table_){ 
			table = table_;
		}
};

#endif
