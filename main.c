#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Programul indeplineste conditiile, doar ca in vectorul de siruri am si "\n" ca si element, pe pozitiile impare,
titluri[1], titluri[3]...etc. M-am tot documentat, dar in C nu cred ca este posibil sa ignori newline sau nu am
gasit eu o solutie. De aceea apare asa ciudat la sortare, face sort si pentru newline pentru ca sunt elemente in
vector. Am 20 de elemente, 10 titluri si 10 newline :D. Daca cumva se putea face mai ok as vrea sa imi explicati
va rog frumos.
*/

// vector de String-uri
char titlu[20][100];
// numarul de elemente din vetorul titlu, marimea vectorului
int numar_titluri = sizeof titlu / sizeof titlu[0];

int main()
{
    // am apelat functiile pentru rezolvarea problemei
    citire_afisare_titluri_vector();
    printf("\n\n\n");
    printf("Vectorul sortat invers este: \n");
    printf("\n\n\n");
    sortare_titluri();
    afisare_sortare_inversa();


    return 0;
}

// functia de citire din fisier si de afisare
void citire_afisare_titluri_vector()
{

FILE *f;
int i;
// verific sa nu fie gol fisierul
if (( f = fopen ( "titluri.txt", "r" )) == NULL )
{
// daca este gol afisez mesajul de mai jos si inchei programul
printf ("Fiserul nu se poate deschide" );
return -1;
}
else
// daca fisierul nu este gol atunci iterez prin vector de la 0 la marime(numar_titluri)
// si prin fgets citest din fisierul f un string pana la "\n" si il pun pe pozitia titlu[i]
// fac acest lucru pana la sizeof(titlu) si dupa aceea il afisez
for (i = 0; i < numar_titluri; i++) {
    fgets (titlu[i], sizeof(titlu), f);
    printf("%s", titlu[i]);

}

fclose(f);

}

// intai fac sortarea vectorului in ordine alfabetica
// functia pentru sortare
void sortare_titluri(){
    int i, j, compara;
    // declar un string(21 este cel mai mare string :D) unde am sa salvez valoarea lui titlu[j] pentru swap
    char s[21];
//folosesc 2 for loop pentru a putea verifica fiecare element
       for(i = 1; i <= numar_titluri; i++)
          for(j = 0; j <= numar_titluri - i; j++){
            // folosesc strcmp pentru a putea compara cate 2 string-uri pe rand
            compara = strcmp(titlu[j], titlu[j+1]);
          // daca compara este mai mare decat 0 atunci string 2 este mai mic decat string 1
          // si in acest caz le fac swap la prin strcpy
            if(compara > 0) {
              strcpy(s, titlu[j]);
              strcpy(titlu[j], titlu[j+1]);
              strcpy(titlu[j+1], s);

              }
          }

}

//functia pentru afisare in ordine descrescatoare a vectorului de stringuri
void afisare_sortare_inversa() {
    int i;
             for(i = numar_titluri; i >= 0; i--){
                puts(titlu[i]);
             }

    }






