# Machiavelli
A game with cards

Questo gioco é stato scelto come progetto da portare per un esame di programmazione software in linguaggio c++.

**REGOLE**

Si tratta di un gioco di carte giocato da 2 fino ad un massimo di 6-8 giocatori. Ogni giocatore parte con 13 carte.
Vi sono due principali azioni che il giocatore di turno può decidere di svolgere:
  Depositare sul tavolo di gioco una o più combinazioni di carte valide 
  Pescare una carta dal mazzo se non si possono fare combinazioni.

Per combinazione valida si intende:

Tre o quattro carte dello stesso valore e di semi diversi (Ad esempio: 7♥ 7♠ 7♦)
Scale di almeno tre carte di valore consecutivo dello stesso seme (Ad esempio: 3♠ 4♠ 5♠)
Aggiunta di una o più carte alle combinazioni presenti sul tavolo (Ad esempio: aggiunta del 2♠ alla combinazione precedente e/o aggiunta del 7♣ al tris del primo esempio)
Una volta terminata la propria giocata, si deve passare la mano al giocatore successivo. Quando viene pescata una carta dal tallone si deve obbligatoriamente passare senza depositare carte sul tavolo.

É inoltre possibile cambiare posto alle carte nel tavolo per creare nuove composizioni con le carte che il giocatore ha in mano.

Il gioco finisce quando un giocatore rimane senza carte.

**Struttura del gioco creato**

Il gioco da noi creato si svolge utilizzando il terminale del pc, durante la mossa sono elencati tutti i comandi che si possono usare per svolgerla.
Oltre ai comandi descritti nei box é possibile anche digitare `esc` quando il gioco chiede le carte da *prendere/inserire*, cosí da riportare il gioco alla scelta della mossa da fare.
Nel caso in cui il giocatore sbagli a confermare le giuste carte e ci sono delle carte che non voleva inserire/prendere, quando deve scegliere il mazzetto, digitando `-1`, salterá la carta.

Una volta che il giocatore rimane senza carte, il gioco controlla che la mossa sia giusta e se lo é, lo termina; il giocatore ha VINTO!
