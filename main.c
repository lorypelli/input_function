#include <stdio.h>

#include "input.h"

int main(void) {
    c_config(); // funzione per creare il file di configurazione
    str string = s_in("Inserisci una stringa: "); // prendo una stringa con la funzione input
    printf("%s\n", string); // stampo i vari caratteri presi in input
    printf("Length: %zu\n", len(string)); // stampo la lunghezza della stringa
    char character = c(s_in("Inserisci un carattere: ")); // trasformo in carattere l'input
    printf("%c\n", character); // stampo il carattere
    int integer_number = i(s_in("Inserisci un numero (intero): ")); // trasformo in intero l'input
    printf("%d\n", integer_number); // stampo il numero intero
    float floating_number = f(s_in("Inserisci un numero (decimale): ")); // transformo in decimale l'input
    printf("%f\n", floating_number); // stampo il numero decimale
    double double_number = d(s_in("Inserisci un numero (decimale doppio): ")); // transformo in decimale doppio l'input
    printf("%lf\n", double_number); // stampo il numero decimale doppio
    long long_number = l(s_in("Inserisci un numero (intero lungo): ")); // transformo in intero lungo l'input
    printf("%ld\n", long_number); // stampo il numero intero lungo
    long long long_long_number = ll(s_in("Inserisci un numero (intero lungo lungo): ")); // transformo in intero lungo lungo l'input
    printf("%lld\n", long_long_number); // stampo il numero intero lungo lungo
    bool valid = v_str("Test di validazione!", NULL); // input con test di validazione
    if (valid) { // se è valido
        printf("Validazione passata!\n"); // stampo che è valido
    }
    else { // altrimenti
        printf("Validazione non passata\n"); // stampo che non è valido
    }
    bool valid2 = v_str("Test di validazione!", "Messaggio personalizzato: "); // input con test di validazione e messaggio personalizzato
    if (valid2) { // se è valido
        printf("Validazione passata!\n"); // stampo che è valido
    }
    else { // altrimenti
        printf("Validazione non passata\n"); // stampo che non è valido
    }
    str file_string = f_in("test.txt"); // leggo il contenuto del file e lo assegno ad una stringa
    printf("%s\n", file_string); // stampo la stringa
    printf("Length: %zu\n", len(file_string)); // stampo la lunghezza della stringa
    char file_character = c(file_string); // transformo in carattere il file
    printf("%c\n", file_character); // stampo il carattere
    int p = i(s_in("Inserisci la posizione del carattere: ")); // chiedo all'utente di inserire la posizione del carattere
    char r = c(s_in("Inserisci il carattere da rimpiazzare: ")); // chiedo all'utente di inserire il carattere da rimpiazzare
    c_str(string, p, r); // modifico il carattere
    printf("%s\n", string); // stampo la stringa con il carattere modificato
    int n = i(s_in("Inserisci la lunghezza dell'array: ")); // chiedo all'utente di inserire la lunghezza dell'array
    int int_arr[n]; // creo un array di n elementi
    for (int j = 0; j < n; j++) { // ciclo for per popolare l'array
        int_arr[j] = i(s_in("Inserisci l'elemento %d: ", j + 1)); // chiedo all'utente di inserire un elemento dell'array
        printf("%d\n", int_arr[j]); // stampo l'elemento
    }
    file_string = f_in("test_line.txt"); // leggo il contenuto del file e lo assegno ad una stringa
    str line = ln(file_string); // funzione per stampare riga per riga la stringa
    printf("%s\n", line); // stampo la prima riga
    line = ln(file_string); // richiamo la funzione
    printf("%s\n", line); // stampo la seconda riga
    line = ln(file_string); // richiamo la funzione
    printf("%s\n", line); // stampo la terza riga
    f_cat("concat.txt", 3, '\n', "f1.txt", "f2.txt", "f3.txt"); // concateno tra loro più file usando \n come separatore
    f_cpy("src.txt", "dest.txt"); // copio un file in un altro
    r = c(s_in("Inserisci il carattere da ripetere: ")); // chiedo all'utente di inserire il carattere da ripetere
    n = i(s_in("Inserisci quante volte ripeterlo: ")); // chiedo all'utente di inserire quante volte ripeterlo
    f_repeat("repeat.txt", r, n, false); // ripeto quel carattere nel file tante volte
    str new_content = f_replace("replace.txt", '!', '.'); // rimpiazzo un carattere dal file
    printf("%s\n", new_content); // stampo il nuovo contenuto del file
    bool b = b_in("Sei sicuro? "); // messaggio di test per gli input booleani
    if (b) { // se risponde di sì
        printf("L'utente ha risposto di sì\n"); // stampo che ha risposto di sì
    }
    else { // altrimenti
        printf("L'utente ha risposto di no\n"); // stampo che ha risposto di no
    }
    n = i(s_in("Inserisci la lunghezza dell'array: ")); // chiedo all'utente di inserire la lunghezza dell'array
    str str_arr[n]; // creo un array di n elementi
    for (int j = 0; j < n; j++) { // ciclo for per popolare l'array
        b = b_in("Vuoi inserire l'elemento %d? ", j + 1); // chiedo all'utente se vuole continuare ad inserire gli elementi
        if (b) { // se risponde di sì
            str_arr[j] = s_in("Inserisci l'elemento %d: ", j + 1); // chiedo all'utente di inserire un elemento dell'array
        }
        else { // altrimenti
            str_arr[j] = ""; // stringa vuota
        }
        printf("%s\n", str_arr[j]); // stampo l'elemento
    }
    int c = sel_in(3, NULL, "Prima opzione", "Seconda opzione", "Terza opzione"); // select menu
    switch (c) { // switch per il valore di c
        case 1: {
            printf("Hai scelto la prima opzione\n");
            break;
        }
        case 2: {
            printf("Hai scelto la seconda opzione\n");
            break;
        }
        case 3: {
            printf("Hai scelto la terza opzione\n");
            break;
        }
    }
    c = sel_in(3, "Seleziona un'opzione > ", "Prima opzione", "Seconda opzione", "Terza opzione"); // select menu con messaggio personalizzato
    switch (c) {
        case 1: { // switch per il valore di c
            printf("Hai scelto la prima opzione\n");
            break;
        }
        case 2: {
            printf("Hai scelto la seconda opzione\n");
            break;
        }
        case 3: {
            printf("Hai scelto la terza opzione\n");
            break;
        }
    }
    return 0;
}