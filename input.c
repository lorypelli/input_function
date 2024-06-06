#include <stdlib.h>

#include "input.h"

// funzione input

static str input(const str fname, str m, va_list args) {
    FILE *f = fopen(fname, "r"); //apro il file in modalità lettura
    if (m && f) { // se il messaggio e il file non sono nulli
        #ifndef SUPPRESS_WARNINGS
        printf("You provided a file and a message, but the message will be ignored\n");
        printf("Use SUPPRESS_WARNINGS macro to disable warnings\n");
        #endif
    }
    else if (!m && !f) { // se il messaggio e il file sono nulli
        m = "Enter Something: "; // uso il messaggio di default
    }
    if (!f) { // se il file è nullo
        #ifndef SUPPRESS_WARNINGS
        printf("File is NULL, stdin will be used instead\n");
        printf("Use SUPPRESS_WARNINGS macro to disable warnings\n");
        #endif
        f = stdin; // uso l'input della console
        vprintf(m, args); // stampo il messaggio dell'utente
    }
    size_t buffer_size = 4; // dimensione buffer
    str buffer = malloc(sizeof(char) * buffer_size); // creo un array di caratteri allocando dinamicamente la memoria
    if (!buffer) { // controllo se è nullo
        fprintf(stderr, "Buffer is NULL\n");
        free(buffer); // libero la memoria
        return "\0"; // ritorno il carattere nullo
    }
    int c = fgetc(f); // prendo un carattere dal file
    size_t i = 0; // contatore
    for (i = 0; f == stdin ? c != '\n' : !feof(f); i++) { // ciclo for per i vari caratteri
        buffer[i] = c; // assegno il carattere alla sua posizione nell'array
        if (i >= buffer_size - 1) { // se è maggiore o uguale della dimensione del buffer meno 1
            buffer_size *= 2; // moltiplico la dimensione per 2
            buffer = realloc(buffer, sizeof(char) * buffer_size); // rialloco la memoria
        }
        if (!buffer) { // controllo se è nullo
            fprintf(stderr, "Buffer is NULL\n");
            free(buffer); // libero la memoria
            return "\0"; // ritorno il carattere nullo
        }
        c = fgetc(f); // prendo un altro carattere dal file
    }
    buffer[i] = '\0'; // carattere terminatore della stringa
    length = i; // assegno la lunghezza della stringa
    if (f != stdin) { //stdin non deve essere chiuso
        fclose(f); //chiudo il file
    }
    return buffer; // ritorno i vari caratteri del file
}

// funzione validazione stringa

extern bool v_str(const str v, str m) {
    if (!v) { // se la stringa di validazione è nulla
        fprintf(stderr, "Value is NULL\n");
        return '\0'; // ritorno il carattere nullo
    }
    if (!m) { // se il messaggio è nullo
        m = "Enter Something: "; // uso quello di default
    }
    str s = s_in(m); // input con il messaggio
    size_t l = len(); // variabile lunghezza stringa
    if (l <= 0) { // se la lunghezza è zero o minore di zero
        fprintf(stderr, "Length is zero or less than zero\n");
        return '\0'; // ritorno il carattere nullo
    }
    for (size_t i = 0; i < l; i++) { // ciclo for per tutta la lunghezza della stringa
        if (s[i] != v[i]) { // se due caratteri sono diversi
            return false; // ritorno false
        }
    }
    return true; // ritorno true alla fine per indicare che tutti i caratteri sono uguali
}

// funzione riga per rigar

extern str ln(const str s) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return "\0"; // ritorno il carattere nullo
    }
    if (string && s != string) { // se la variabile globale stringa non è nulla e le due stringhe puntano ad indirizzi di memoria differenti
        #ifndef SUPPRESS_WARNINGS
        printf("You provided a string that is different from the one you started the function with, position will be set back to 0\n");
        printf("Use SUPPRESS_WARNINGS macro to disable warnings\n");
        #endif
        position = 0; // la posizione torna ad essere 0
    }
    size_t buffer_size = 4; // dimensione buffer
    str buffer = malloc(sizeof(char) * buffer_size); // creo un array di caratteri allocando dinamicamente la memoria
    if (!buffer) { // controllo se è nullo
        fprintf(stderr, "Buffer is NULL\n");
        free(buffer); // libero la memoria
        return "\0"; // ritorno il carattere nullo
    }
    size_t i = 0; // contatore
    for (i = position; s[i] != '\n' && s[i]; i++) { // ciclo for per i vari caratteri
        buffer[i - position] = s[i]; // assegno il carattere alla sua posizione
        if (i >= buffer_size - 1) { // se è maggiore o uguale della dimensione del buffer meno 1
            buffer_size *= 2; // moltiplico la dimensione per 2
            buffer = realloc(buffer, sizeof(char) * buffer_size); // rialloco la memoria
        }
        if (!buffer) { // controllo se è nullo
            fprintf(stderr, "Buffer is NULL\n");
            free(buffer); // libero la memoria
            return "\0"; // ritorno il carattere nullo
        }
    }
    if (!s[i]) { // se la stringa è finita
        position = 0; // la posizione torna ad essere 0
        string = NULL; // la variabile globale stringa diventa nulla
    }
    else if (!string || s == string) { // se la variabile globale stringa è nulla o i due indirizzi di memoria sono uguali
        position = i + 1; // assegno la posizione del carattere
    }
    buffer[i] = '\0'; // carattere terminatore della stringa
    if (!string || s == string) { // se la variabile globale stringa è nulla o i due indirizzi di memoria sono uguali
        string = s; // assegno la variabile globale stringa
    }
    return buffer; // ritorno riga per riga (chiamando più volte la funzione)
}

// funzione lunghezza

extern size_t len(void) {
    if (length == -1) { // se la lunghezza è -1
        fprintf(stderr, "EOF Reached\n");
        return '\0'; // ritorno il carattere nullo
    }
    size_t local_length = length; // assegno la lunghezza ad una variabile locale
    length = -1; // assegno -1 alla variabile globale lunghezza
    return local_length; // ritorno la lunghezza della stringa
}

// funzione cambio carattere

extern void c_str(str s, const size_t p, const char c) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return; // non faccio altro
    }
    s[p] = c; // assegno il nuovo carattere alla sua posizione
}

//funzione copia file

extern void f_cpy(const str src, str dest) {
    FILE *in = fopen(src, "r"); //apro il file in modalità lettura
    FILE *out = fopen(dest, "w"); //apro il file in modalità scrittura
    while (!feof(in)) {
        int c = fgetc(in); //prendo un carattere dal file
        if (c != EOF) { //controllo che il carattere non sia EOF
            fputc(c, out); //inserisco il carattere nel file
        }
    }
    fclose(in); //chiudo il file
    fclose(out); //chiudo il file
}

// funzione concatenazione file

extern void f_cat(const str cname, const size_t n, const char sep, str fname, ...) {
    va_list args; // creo una lista di argomenti
    va_start(args, fname); // avvio la lista
    if (!fname) { // se il nome del file è nullo
        fprintf(stderr, "File name is NULL\n");
        return; // non faccio altro
    }
    FILE *f = fopen(fname, "r"); // apro il file in modalità lettura
    size_t j = 0; // contatore
    size_t buffer_size = 4; // dimensione buffer
    str buffer = malloc(sizeof(char) * buffer_size); // creo un array di caratteri allocando dinamicamente la memoria
    if (!buffer) { // controllo se è nullo
        fprintf(stderr, "Buffer is NULL\n");
        free(buffer); // libero la memoria
        return; // non faccio altro
    }
    for (size_t i = 0; j < n; i++) {
        int c = fgetc(f); // prendo un carattere dal file
        buffer[i] = c != EOF ? c : j < n - 1 ? sep : '\0'; // assegno il carattere alla sua posizione nell'array
        if (i >= buffer_size - 1) { // se è maggiore o uguale della dimensione del buffer meno 1
            buffer_size *= 2; // moltiplico la dimensione per 2
            buffer = realloc(buffer, sizeof(char) * buffer_size); // rialloco la memoria
        }
        if (!buffer) { // controllo se è nullo
            fprintf(stderr, "Buffer is NULL\n");
            free(buffer); // libero la memoria
            return; // non faccio altro
        }
        if (feof(f)) { // se ho raggiunto la fine del file
            fclose(f); // chiudo il file
            fname = va_arg(args, str); // prendo un elemento dalla lista
            f = fopen(fname, "r"); // apro il file in modalità lettura
            j++;
        }
    }
    FILE *out = fopen(cname, "w"); // apro il file in modalità scrittura
    fputs(buffer, out); // scrivo nel file
    fclose(out); // chiudo il file
    va_end(args); // interrompo la lista
    free(buffer); // libero la memoria
}

// funzione ripezione carattere

extern void f_repeat(FILE *f, const char c, const size_t n) {
    if (!f) { // se il file è nullo
        #ifndef SUPPRESS_WARNINGS
        printf("File is NULL, stdout will be used instead\n");
        printf("Use SUPPRESS_WARNINGS macro to disable warnings\n");
        #endif
        f = stdout; // uso l'output della console
    }
    for (size_t i = 0; i < n; i++) { // ciclo for per ripetere il carattere
        fputc(c, f); // metto un carattere alla volta nel file
    }
}

// funzione stringa

extern str in(const str fname, str s, ...) {
    va_list args; // creo una lista di argomenti
    va_start(args, s); // avvio la lista
    str res = input(fname, s, args); // chiamo la funzione input
    va_end(args); // interrompo la lista
    return res; // ritorno il risultato
}

// funzione carattere

extern char c(const str s) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; // ritorno il carattere nullo
    }
    char res = s[0]; // primo carattere dell'array
    free(s); // libero la memoria
    length = -1; // assegno -1 alla variabile globale lunghezza
    return res; // ritorno il risultato
}

// funzione intero

extern int i(const str s) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; // ritorno il carattere nullo
    }
    int res = atoi(s); // converto in int
    free(s); // libero la memoria
    length = -1; // assegno -1 alla variabile globale lunghezza
    return res; // ritorno il risultato
}

// funzione intero lungo

extern long l(const str s) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; // ritorno il carattere nullo
    }
    long res = atol(s); // converto in long
    free(s); // libero la memoria
    length = -1; // assegno -1 alla variabile globale lunghezza
    return res; // ritorno il risultato
}

// funzione intero lungo lungo

extern long long ll(const str s) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; // ritorno il carattere nullo
    }
    long long res = atoll(s); // converto in long long
    free(s); // libero la memoria
    length = -1; // assegno -1 alla variabile globale lunghezza
    return res; // ritorno il risultato
}

// funzione decimale

extern float f(const str s) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; // ritorno il carattere nullo
    }
    float res = atof(s); // converto in float
    free(s); // libero la memoria
    length = -1; // assegno -1 alla variabile globale lunghezza
    return res; // ritorno il risultato
}

// funzione decimale doppio

extern double d(const str s) {
    if (!s) { // se la stringa è nulla
        fprintf(stderr, "String is NULL\n");
        return '\0'; // ritorno il carattere nullo
    }
    double res = atof(s); // converto in double
    free(s); // libero la memoria
    length = -1; // assegno -1 alla variabile globale lunghezza
    return res; // ritorno il risultato
}