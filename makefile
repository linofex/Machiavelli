CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
Card.o: Card.cc
	${CC}-c Card.cc

Deck.o: Deck.cc 
	${CC} -c Deck.cc

Machiavelli.o: Machiavelli.cc 
	${CC} -c Machiavelli.cc

Table.o: Table.cc 
	${CC} -c Table.cc

PlayerBase.o: PlayerBase.cc 
	$[CC] -c PlayerBase.cc

main.o: main.cc 
	${CC} -c main.cc
	

#Linking progetto
machiavelli: Deck.o Card.o Machiavelli.o Table.o PlayerBase.cc main.o
	${LD} -o machiavelli Deck.o Card.o Machiavelli.o Table.o PlayerBase.cc main.o

machiavelli_test: Deck.o Card.o Machiavelli.o Table.o PlayerBase.cc main_test.cc
	${LD} -o machiavelli_test Deck.o Card.o Machiavelli.o Table.o PlayerBase.cc main_test.cc
	
#cancella tutto quello che é stato compilato
clean :
	rm -f *.o machiavelli machiavelli_test
