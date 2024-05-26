#include <stdlib.h>

#include "input.h"

//funzione input

static str input(FILE *f, str m, va_list args) {
    if (m && f && f != stdin) { //se il messaggio e il file non sono nulli
        #ifndef SUPPRESS_WARNINGS
        printf("You provided a file and a message, but the message will be ignored\n");
        printf("Use SUPPRESS_WARNINGS macro to disable warnings\n");
        #endif
    }
    else if (!m && (!f || f == stdin)) { //se il messaggio e il file sono nulli
        m = "Enter Something: "; //uso il messaggio di default
    }
    if (!f || f == stdin) { //se il file è nullo o è stdin
        #ifndef SUPPRESS_WARNINGS
        printf("File is NULL, stdin will be used instead\n");
        printf("Use SUPPRESS_WARNINGS macro to disable warnings\n");
        #endif
        f = stdin; //uso l'input della console
        vprintf(m, args); //stampo il messaggio dell'utente
    }
    size_t buffer_size = 4; //dimensione buffer
    str buffer = malloc(sizeof(char) * buffer_size); //creo un array di caratteri allocando dinamicamente la memoria
    if (!buffer) { //controllo se è nullo
        fprintf(stderr, "Buffer is NULL\n");
        free(buffer); //libero la memoria
        return "\0"; //ritorno il carattere nullo
    }
    int c = fgetc(f); //prendo un carattere dal file
    unsigned long long i = 0; //contatore
    for (i = 0; f == stdin ? c != '\n' : !feof(f); i++) { //ciclo for per i vari caratteri
        buffer[i] = c; //assegno il carattere alla sua posizione nell'array
        if (i >= buffer_size - 1) { //se è maggiore o uguale della dimensione del buffer meno 1
            buffer_size *= 2; //moltiplico la dimensione per 2
            buffer = realloc(buffer, sizeof(char) * buffer_size); //rialloco la memoria
        }
        if (!buffer) { //controllo se è nullo
            fprintf(stderr, "Buffer is NULL\n");
            free(buffer); //libero la memoria
            return "\0"; //ritorno il carattere nullo
        }
        c = fgetc(f); //prendo un'altro carattere dal file
    }
    buffer[i] = '\0'; //carattere terminatore della stringa
    length = i; //assegno la lunghezza della stringa
    return buffer; //ritorno i vari caratteri del file
}

//funzione validazione stringa

extern bool v_str(const str v, str m) {
    if (!v) { //se la stringa di validazione è nulla
        fprintf(stderr, "Value is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    if (!m) { //se il messaggio è nullo
        m = "Enter Something: "; //uso quello di default
    }
    str s = in(NULL, m); //input con il messaggio
    unsigned long long l = len(s); //variabile lunghezza stringa
    if (l <= 0) { //se la lunghezza è zero o minore di zero
        fprintf(stderr, "Length is zero or less than zero\n");
        return '\0'; //ritorno il carattere nullo
    }
    for (unsigned long long i = 0; i < l; i++) { //ciclo for per tutta la lunghezza della stringa
        if (s[i] != v[i]) { //se due caratteri sono diversi
            return false; //ritorno false
        }
    }
    return true; //ritorno true alla fine per indicare che tutti i caratteri sono uguali
}

//funzione riga per rigar

extern str ln(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return "\0"; //ritorno il carattere nullo
    }
    size_t buffer_size = 4; //dimensione buffer
    str buffer = malloc(sizeof(char) * buffer_size); //creo un array di caratteri allocando dinamicamente la memoria
    if (!buffer) { //controllo se è nullo
        fprintf(stderr, "Buffer is NULL\n");
        free(buffer); //libero la memoria
        return "\0"; //ritorno il carattere nullo
    }
    unsigned long long i = 0; //contatore
    for (i = position; s[i] != '\n' && s[i]; i++) { //ciclo for per i vari caratteri
        buffer[i - position] = s[i]; //assegno il carattere alla sua posizione
        if (i >= buffer_size - 1) { //se è maggiore o uguale della dimensione del buffer meno 1
            buffer_size *= 2; //moltiplico la dimensione per 2
            buffer = realloc(buffer, sizeof(char) * buffer_size); //rialloco la memoria
        }
        if (!buffer) { //controllo se è nullo
            fprintf(stderr, "Buffer is NULL\n");
            free(buffer); //libero la memoria
            return "\0"; //ritorno il carattere nullo
        }
    }
    if (!s[i]) { //se la stringa è finita
        position = 0; //la posizione torna ad essere 0
    }
    else {
        position = i + 1; //assegno la posizione del carattere
    }
    buffer[i] = '\0'; //carattere terminatore della stringa
    return buffer; //ritorno riga per riga (chiamando più volte la funzione)
}

//funzione lunghezza

extern unsigned long long len(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    if (length == -1) { //se la lunghezza è -1
        fprintf(stderr, "EOF Reached\n");
        return '\0'; //ritorno il carattere nullo
    }
    unsigned long long local_length = length; //assegno la lunghezza ad una variabile locale
    length = -1; //assegno -1 alla variabile globale lunghezza
    return local_length; //ritorno la lunghezza della stringa
}

//funzione cambio carattere

extern void c_str(str s, const int p, const char c) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return; //non faccio altro
    }
    s[p] = c; //assegno il nuovo carattere alla sua posizione
}

//funzione stringa

extern str in(FILE *f, str s, ...) {
    va_list args; //creo una lista di argomenti
    va_start(args, s); //avvio la lista
    if (!s && (!f || f == stdin)) { //se la stringa e il file sono nulli
        f = stdin;
        s = "Enter Something: ";
    }
    str res = input(f, s, args); //chiamo la funzione input
    va_end(args); //interrompo la lista
    return res; //ritorno il risultato
}

//funzione carattere

extern char c(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    char res = s[0]; //primo carattere dell'array
    free(s); //libero la memoria
    length = -1; //assegno -1 alla variabile globale lunghezza
    return res; //ritorno il risultato
}

//funzione intero

extern int i(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    int res = atoi(s); //converto in int
    free(s); //libero la memoria
    length = -1; //assegno -1 alla variabile globale lunghezza
    return res; //ritorno il risultato
}

//funzione intero lungo

extern long l(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    long res = atol(s); //converto in long
    free(s); //libero la memoria
    length = -1; //assegno -1 alla variabile globale lunghezza
    return res; //ritorno il risultato
}

//funzione intero lungo lungo

extern long long ll(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    long long res = atoll(s); //converto in long long
    free(s); //libero la memoria
    length = -1; //assegno -1 alla variabile globale lunghezza
    return res; //ritorno il risultato
}

//funzione decimale

extern float f(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    float res = atof(s); //converto in float
    free(s); //libero la memoria
    length = -1; //assegno -1 alla variabile globale lunghezza
    return res; //ritorno il risultato
}

//funzione decimale doppio

extern double d(const str s) {
    if (!s) { //se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; //ritorno il carattere nullo
    }
    double res = atof(s); //converto in double
    free(s); //libero la memoria
    length = -1; //assegno -1 alla variabile globale lunghezza
    return res; //ritorno il risultato
}