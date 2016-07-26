#include "Table.h"

Table::PrintTable() const{
	m_map::const_iterator iter = table.begin();
	for(; iter != table.end(); ++iter){
		std::cout<< iter->first;
		for(int i = 0; i<iter->second.size(): ++i){
			std::cout<<iter-second[i] << " ";
		}
		std::cout<<std::endl;
	}
}
