#include "input.h"

int main(void) {
    str string = s_in("Provide a string: "); //prendo una stringa con la funzione input
    printf("%s\n", string); //stampo i vari caratteri presi in input
    printf("Length: %zu\n", len()); //stampo la lunghezza della stringa
    char character = c(s_in("Provide a character: ")); //trasformo in carattere l'input
    printf("%c\n", character); //stampo il carattere
    int integer_number = i(s_in("Provide a number (integer): ")); //trasformo in intero l'input
    printf("%d\n", integer_number); //stampo il numero intero
    float floating_number = f(s_in("Provide a number (float): ")); //transformo in decimale l'input
    printf("%f\n", floating_number); //stampo il numero decimale
    double double_number = d(s_in("Provide a number (double): ")); //transformo in decimale doppio l'input
    printf("%lf\n", double_number); //stampo il numero decimale doppio
    long long_number = l(s_in("Provide a number (long): ")); //transformo in intero lungo l'input
    printf("%ld\n", long_number); //stampo il numero intero lungo
    long long long_long_number = ll(s_in("Provide a number (long long): ")); //transformo in intero lungo lungo l'input
    printf("%lld\n", long_long_number); //stampo il numero intero lungo lungo
    bool valid = v_str("Validation Test!", NULL); //input con test di validazione
    if (!valid) { //se non è valido
        printf("Validation Not Passed!\n"); //stampo che non è valido
    }
    else { //altrimenti
        printf("Validation Passed!\n"); //stampo che è valido
    }
    bool valid2 = v_str("Validation Test!", "Custom Message: "); //input con test di validazione e messaggio personalizzato
    if (!valid2) { //se non è valido
        printf("Validation Not Passed!\n"); //stampo che non è valido
    }
    else { //altrimenti
        printf("Validation Passed!\n"); //stampo che è valido
    }
    FILE *f = fopen("test.txt", "r"); //apro il file
    str file_string = f_in(f); //leggo il contenuto del file e lo assegno ad una stringa
    fclose(f); //chiudo il file
    printf("%s\n", file_string); //stampo la stringa
    printf("Length: %zu\n", len()); //stampo la lunghezza della stringa
    char file_character = c(file_string); //transformo in carattere il file
    printf("%c\n", file_character); //stampo il carattere
    int p = i(s_in("Inserisci la posizione del carattere: ")); //chiedo all'utente di inserire la posizione del carattere
    char r = c(s_in("Inserisci il carattere da rimpiazzare: ")); //chiedo all'utente di inserire il carattere da rimpiazzare
    c_str(string, p, r); //modifico il carattere
    printf("%s\n", string); //stampo la stringa con il carattere modificato
    int n = i(s_in("Inserisci un numero: ")); //chiedo all'utente di inserire un numero
    int arr[n]; //creo un array di n elementi
    for (int j = 0; j < n; j++) { //ciclo for per popolare l'array
        arr[j] = i(s_in("Inserisci l'elemento %d: ", j + 1));
        printf("%d\n", arr[j]); //stampo l'elemento
    }
    f = fopen("test_line.txt", "r"); //apro il file
    file_string = f_in(f); //leggo il contenuto del file e lo assegno ad una stringa
    fclose(f); //chiudo il file
    str line = ln(file_string); //funzione per stampare riga per riga la stringa
    printf("%s\n", line); //stampo la prima riga
    line = ln(file_string); //richiamo la funzione
    printf("%s\n", line); //stampo la seconda riga
    line = ln(file_string); //richiamo la funzione
    printf("%s\n", line); //stampo la terza riga
    f_cat("concat.txt", 3, '\n', "f1.txt", "f2.txt", "f3.txt"); //concateno tra loro più file usando \n come separatore
    return 0;
}