#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <vector>

class Table{
	private:
		typedef std::map<int, std::vector<std::string> > m_map:
		m_map table;
		int n_set; //Optional
	public:
	
		void PrintTable() const;
		
		inline void UpdateTable(const m_map& table_){ 
			table = table_;
		}
};

#endif

