# Progetto di programmazione 2022

L'obiettivo del progetto era sviluppare un gioco rogue-like in C++, utilizzando solo ncurses.h come libreria per la grafica.    
All'interno del gioco è possibile muoversi tra le stanze, combattere i nemici, raccogliere artefatti e usare abilità speciali.   
Le stanze vengono generate all'infinito e non c'è una fine o uno scopo se non fare il punteggio maggiore possibile.   

Il progetto è stato sviluppato in ambiente unix, perché lo richiede la libreria ncurses.h, disponibile solo per linux.

Per lanciare il gioco basta scaricare la cartella ed eseguore il comando make da terminale.  

## cose da fare:   
commenti nel codice (in particolare cosa fanno gli artefatti e i nemici)  
non va la creazione di artefatti   
rimuovere i warning (-w)
ridurre le stanze senza porte

-caratteri unicode:    
\u265E cavallo
♡      cuore vuoto
\u26BF chiave
\u26E8 scudo


-stanze:  
rimettere la condizione per cambiare stanza    


-menu:  
chiusura corretta delle finestre    
controllo che la finestra del terminale sia abbastanza grande per il gioco prima di iniziare   

-statistiche  
scoreboard con il prunteggio(esperienza)
statboard con statitiche,chivi,artefatti, poteri

Legenda dei colori:  
- rosso nemici
- viola boss nemici
- blu artefatti  
- grigio porte  

Numero  Stanza              Rarità        
0   - stanza vuota      solo all'inizio        
1   - muri rand               0        
2   - stanza artefatti        1        
3   - sottostanza lt          8        
4   - sottostanza rt          8        
5   - sottostanza lt          8        
6   - sottostanza lb          8        
7   - croce negativa          8        
8   - sottostanza c no porte  10        
9   - blocchi muri rand       10        
10  - muri rand               8        
11  - maze contrentico        3                  
12  - maze spirale            2        
13  - sottostanza c porte_l   6        
14  - tempio                  4        
15  - sottostanze chrome      4        
16  - sottostanza esagonale   7        
17  - quadrati pieni  x       10        
18  - quadrati pieni  +       10        
19  - croci casuali           7        
20  - s orizzontale           8        
21  - 4 angoli                10        
22  - pacman                  5        
23  - muro bloccante r        0        
24  - muro bloccante l        0        
25  - muro bloccante t        0        
26  - muro bloccante b        0        
27  - boss turret             1        
28  - 4 turret                8        
29  - 16 turret (passaggio)   6        
30  - muro t                  10        
31  - muro b                  10        
32  - muro l                  10        
33  - muro r                  10        
34  - 4 sottostanze rand      15        
35  - 3 sottostanze rand vert 15        
36  - 3 sottostanze rand oriz 15        
37  - boss stalker            1        
38  - boss shooter            1        
39  - croce                   6        
40  - labirinto               3          