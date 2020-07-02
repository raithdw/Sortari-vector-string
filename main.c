#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

FILE *f;  // declar o variabila de tip FILE
int i, j;
char titlu[SIZE][100];  // un vector de String-uri
char c[50]; // un String

int main()
{
    // am apelat functiile pentru rezolvarea problemei
    citire_afisare_titluri_vector();
    printf("\n\n");
    printf("Vectorul sortat invers este: \n");
    printf("\n\n\n");
    sortare_titluri();
    afisare_titluri_sortate();

    return 0;
}

void citire_afisare_titluri_vector()   // functia de citire din fisier si de afisare
{

f = fopen("titluri.txt", "r"); // deschid fisierul f

if(f == NULL) // verific daca exista fisierul pe care vreau sa il deschid, daca nu exista atunci inchei programul cu mesajul de mai jos
    {
        printf("Fisierul nu poate fi deschis\n");
        exit(1); // functie din C library pentru terminarea programului
    }


for (i = 0; i < SIZE; i++) {
    fscanf(f,"%s", c);  // folosesc fscanf ca sa citesc stringurile pe rand pana la \n din fisier
    strncpy(titlu[i], c, c[SIZE-1]);  // copiez in vectorul titlu stringurile salvate in vectorul c
    printf("%s\n\n", titlu[i]);  // afisez vectorul cu toate titlurile de carti

}

fclose(f);
}

void sortare_titluri(){  // functia corecta de sortare inversa a vectorului de stringuri
char temp [50]; // un vector temporar unde am sa salvez stringurile pentru a le compara pe rand
    for(i = 0; i < SIZE; i++){
        for(j = i + 1; j < SIZE; j++){
            if(strcmp(titlu[i],titlu[j]) < 0){  // aici fac sortarea descrescatoare
                strcpy(titlu[i],titlu[j]);      // copiez string [j] in string[i]
                strcpy(titlu[j],temp);          // copiez string[temp] in string[j]
            }                                   // si am facut swap la elemente
        }

    }

}

void afisare_titluri_sortate() {        // functie de printat array-ul
    for(i = 0; i < SIZE; i++){
     printf("%s\n\n", titlu[i]);
    }

}









