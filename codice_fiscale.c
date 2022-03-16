/*****************************************************************************************************
Consegna: 
Programma che Ã¨ in grado di calcolare il codice fiscale di una persona 


Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 16/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#define MAX_CHAR    16
#define MAX_COGNOME 30
#define MAX_NOME    30
#define MAX_CONS    30
#define MAX_VOC     30

void  GotoXY(int x, int  y){
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);}

// PROCEDURA CHE CHIEDE IN INPUT:
// COGNOME
// NOME
void Cognome_Nome(char surname[], char name[]){
    bool error_surname  = FALSE,    // Segna un eventuale errore nel cognome
         error_name     = FALSE;    // Segna un eventuale errore nel nome
    int c,                          // Usata nei cicli for per il cognome
        n;                          // Usata nei cicli for per il nome
        
// COGNOME
    do{
        // Input cognome
        system("cls");
        error_surname = false;
        printf("Inserisci il tuo cognome-->");
        scanf("%s",surname);

        // Trasformo il cognome in maiuscolo
        for (c = 0; c < strlen(surname); c++){
            surname[c] = toupper(surname[c]);
        }

        // Controllo il cognome inserito 
        for (c = 0; c < strlen(surname); c++){
            if ((surname[c] < 'A' || surname[c] > 'Z') && surname[c] != ' ' && surname[c] != '\'')
                error_surname = true;
        }
    }while(error_surname == true);

// NOME
    do{
        // Input nome 
		error_name = false;
        printf("Inserisci il tuo nome-->");
        scanf("%s",name);

        // Trasformo il nome in maiuscolo
        for(n = 0; n < strlen(name); n++){
            name[n] = toupper(name[n]);
        }

        // Controllo il nome inserito 
        for (n = 0; n < strlen(name); n++){
            if ((name[n] < 'A' || name[n] > 'Z') && name[n] != ' ' && name[n] != '\'')
                error_name = true;
    	}
    }while(error_name == true);
}


// PROCEDURA CHE SELEZIONA TUTTE LE VOCALI DEL NOME E DEL COGNOME
void selezione_vocali(char surname[], char name[], char voc_surname[], char voc_name[]){
    int c,
        n;
    // Selezione delle vocali del cognome 
    for (c = 0; c < strlen(surname); c++){
        if (surname[c] == 'A' || surname[c] == 'E' || surname[c] == 'I' || surname[c] == 'O' || surname[c] == 'U')
            voc_surname[c] = surname[c];
    }

    // Selezione delle vocali del nome 
    for (n = 0; n < strlen(surname); n++){
        if (name[n] == 'A' || name[n] == 'E' || name[n] == 'I' || name[n] == 'O' || name[n]  == 'U')
            voc_name[n] = name[n];
    }
}


// PROCEDURA CHE SELEZIONA LE PRIMA 3 CONSONANTI DEL COGNOME E DEL NOME
void selezione_consonanti(char surname[], char name[], char cons_surname[], char cons_name[], char voc_surname[], char voc_name[]){
    char extra_char = 'X'	;		// Carattere aggiuntivo se il cognome o il nome non hanno consonanti
    int c					,		// Usata per quello che riguarda il cognome
        n					,		// USata per quello che riguarda il nome
        ct_surname			,		// Conta il numero di consonanti del cognome
        ct_name				;		// Conta il numero di consonanti del nome
// COGNOME
    // Selezione delle 3 consonanti del cognome 
    	for (c = 0; c < strlen(surname) && c < 5; c++){
        	if (surname[c] != 'A' && surname[c] != 'E' && surname[c] != 'I' && surname[c] != 'O' && surname[c] != 'U'){
            	cons_surname[c] = surname[c];
           		ct_surname++;
        	}
        	else{
        	}
   		}
    // Casi in cui il cognome ha meno di 3 consonanti 
    	if (ct_surname < 3){
        	// Caso con 0 consonanti 
        	if (ct_surname == 0){
            	printf("%c\n%c\n%c",voc_surname[0], voc_surname[1], extra_char);
        	}
        	// Caso con 1 consonante 
        	if (ct_surname == 1){
            	printf("%c\n%c\n%c",cons_surname[0], voc_surname[0], voc_surname[1]);
        	}
        	// Caso con 2 consonanti
        	if (ct_surname == 2){
            	printf("%c\n%c\n%c",cons_surname[0], cons_surname[1], voc_surname[0]);
        	}
    	}
    // Caso in cui il cognome ha più di 3 consonanti
    if(ct_surname >= 3){
    	for(c = 0; c < strlen(surname); c++)
    		printf("%c",cons_surname[c]);
    }
    

// NOME
    // Selezione delle 3 consonanti del nome 
    	for (n = 0; n < strlen(name) && n < 5; n++){
        	if (name[n] != 'A' && name[n] != 'E' && name[n] != 'I' && name[n] != 'O' && name[n] != 'U'){
            	cons_name[n] = name[n];
            	ct_name++;
        	}
        	else{      		
        	}
    	}

    // Caso in cui il nome ha meno di 3 consonanti 
    	if (ct_name < 3){
        	// Caso con 0 consonanti 
        	if (ct_name == 0)
            	printf("%c\n%c\n%c",voc_name[0], voc_name[1], extra_char);
        	// Caso con 1 consonante 
        	if (ct_name == 1)
            	printf("%c\n%c\n%c",cons_name[0], voc_name[0], voc_name[1]);
        	// Caso con 2 consonanti
        	if (ct_name == 2)
            	printf("%c\n%c\n%c",cons_name[0], cons_name[1], voc_name[0]);
    	}
    	
    // Caso in cui il nome ha piu di 3 consonanti
    	if (ct_name >= 3){
    		for(n = 0; n < strlen(name); n++)
    			printf("%c",cons_name[n]);
    	}
}


// PROCEDURA CHE CHIEDE ANNO, MESE E ANNO DI NASCITA
void nascita_Sesso(int year, char month, int day, int sex){
	char month_char;
	
	//Controllo se il giorno e maggiore di 31 nei mesi con 30 giorni
	do{
    
		//Inserimento e controllo del giorno inserito
	 	do{
	   		printf("\nInserisci il tuo giorno di nascita-->");
	   		scanf("%d",&day);
	  	}while(day < 1 || day > 31);	  
	  	
		//Inserimento e controllo mese inserito
		do{
	   		printf("Inserisci il tuo mese di nascita-->");
	   		scanf("%d",&month);
	  	}while(month < 1 || month > 12);	
	  	
	}while ((day > 30 && month == 4) ||
	  		(day > 30 && month == 6) ||
	  		(day > 30 && month == 9) ||
	  		(day > 30 && month == 11) );
	//Controllo il giorno se il mese è Febbraio
	while(day > 29 && month == 2){
	    printf("Inserisci un mese valido! -->");
	    scanf("%d",&month);
	};
	  
	//Inserimento e controllo dell'anno inserito 
	do{
		printf("Inserisci il tuo anno di nascita-->");
		scanf("%d",&year); 
	}while(year < 1 || year > 2022);
	//Controllo se l'anno è bisestile  
	while((day == 29 && month == 2 && year %  4	 == 1)||
		  (day == 29 && month == 2 && year % 100 == 1)||
		  (day == 29 && month == 2 && year % 400 == 1 )){
		printf("Inserisci una data valida! -->");
		scanf("%d",&year);
	}
	// Ottengo le decine dell'anno
	year %= 100;
	
	// Inserimento e controllo del sesso della persona
	printf("Inserisci il tuo sesso (0 se Femmina oppure 1 se Maschio)-->");
	scanf("%d",&sex);

	switch(month){
		case 1:
			month = 'A';
			break;
		case 2:
			month = 'B';
			break;
		case 3:
			month = 'C';
			break;
		case 4:
			month = 'D';
			break;
		case 5:
			month = 'E';
			break;
		case 6:
			month = 'H';
			break;
		case 7:
			month = 'L';
			break;
		case 8:
			month = 'M';
			break;
		case 9:
			month = 'P';
			break;
		case 10:
			month = 'R';
			break;
		case 11:
			month = 'S';
			break;
		case 12:	
			month = 'T';
			break;
	}
	
	// Stampa dell'anno, mese e giorno di nascita
	// Femmina
		if (sex == 0){
			day += 40;
			if (year < 10 && day < 10)
				printf("0%d%c0%d",year, month, day);
			if (year < 10 && day > 10)
				printf("0%d%c%d",year, month, day);
			if (year > 10 && day < 10)
				printf("%d%c0%d",year, month, day);
			if (year > 10 && day > 10)
				printf("%d%c%d",year, month, day);
		}
	// Maschio
		if (sex == 1){
			if (year < 10 && day < 10)
				printf("0%d%c0%d",year, month, day);
			if (year < 10 && day > 10)
				printf("0%d%c%d",year, month, day);
			if (year > 10 && day < 10)
				printf("%d%c0%d",year, month, day);
			if (year > 10 && day > 10)
				printf("%d%c%d",year, month, day);
		}
}


int main(){
    char codice_fiscale        [MAX_CHAR]   ,
         cognome               [MAX_COGNOME],
         nome                  [MAX_NOME]   ,
         consonanti_cognome    [MAX_CONS]   ,
         consonanti_nome       [MAX_CONS]   ,
         vocali_cognome        [MAX_VOC]    ,
         vocali_nome           [MAX_VOC]    ,
		 mese								;
	int anno								,
		giorno								,
		sesso								;	

    // INSERIMENTO COGNOME E NOME DA PARTE DELL'UTENTE
    Cognome_Nome(cognome, nome);

	// SALVATAGGIO DELLE VOCALI PRESENTI NEL NOME E NEL COGNOME  
    selezione_vocali(cognome, nome, vocali_cognome, vocali_nome);

    // SELEZIONE DELLE 3 CONSONANTI DEL NOME E DEL COGNOME
    selezione_consonanti(cognome, nome, consonanti_cognome, consonanti_nome, vocali_cognome, vocali_nome);
    
    // INSERIMENTO DELL'ANNO, MESE E GIORNO DI NASCITA
    nascita_Sesso(anno, mese, giorno, sesso);


	return 0;
}
