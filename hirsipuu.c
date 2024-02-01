#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>



// Lista sanoista, josta hirsipuupeli valitsee satunnaisesti
char sanat[][20] = 
{
    "kuoppa",
    "ostoskori",
    "ohjelmointi",
    "kieli",
    "auto",
    "kirous",
    "historia",
    "haava"
};

bool onkoSana(char[], char);
bool onkoValmis(char[], char[]);
void tulostaHirsipuu(int);
void tulostaKirjaimet(char[]);
void tulostaRuutu(char[], char[], char[]);

// Tämä palauttaa tosin, jos annettu kirjain löytyy sanasta;
// Muussa tapauksessa tulee epätosi.
bool onkoSana(char sana[], char kirjain)
{
  
    // Etsitään for loopissa pelaajan syötetty kirjain, jos se osuu piilotettuun sanaan
    // Jokaisessa kohdassa, jossa syötetty kirjain on sama kuin sanassa, palautuu tosi.
    // Jos kirjainta ei löydy loopin jälkeen, palauttaa epätosin

    for (int iter=0; iter<strlen(sana); iter++)
    {
        if (kirjain ==sana[iter])
            return true;
    }



    return false;
}


// Funtio palauttaa tosin, jos sana on arvattu oikein
// Muussa tapauksessa palauttaa epätosina
bool onkoValmis(char sala[], char oikeat[])
{
    // For looppi, jolla tarkastellaan salaisen sanan jokaista sijaintia
    // Jos kaikki salaisen sanan kirjaimet ovat oikeat arrayssa niin, palauta tosi, muussa tapauksessa palauta epätosi
    for (int iter = 0; iter < strlen(sala); iter++) 
    {
        for(int j=0; j<strlen(oikeat);j++)
        {
            if (sala[iter]==oikeat[j]&& iter==(strlen(sala)-1))
            {
                return true;
            }
        }
}


    return false;
}

// Tämä funktio tulostaa hirsipuun väärien arvauksien määrän mukaan
void tulostaHirsipuu(int montavaaraa)
{    
    printf("\t  ______\n");    
    printf("\t  |     |\n");    
    printf("\t  |     +\n");

    // Vasen käsi, pää ja oikea käsi
    printf("\t  |");
    if (montavaaraa > 0) printf("    \\");
    if (montavaaraa > 1) printf("O");
    if (montavaaraa > 2) printf("/");
    printf("\n");

    // Kroppa
    printf("\t  |");
    if (montavaaraa > 3) printf("     |");
    printf("\n");

    // Vasen ja oikea jalka
    printf("\t  |");
    if (montavaaraa > 4) printf("    /");
    if (montavaaraa > 5) printf(" \\");
    printf("\n");   
    printf("\t  |\n");    
    printf("\t__|__\n");
}

// Tämä funktio tulostaa kirjaimet arrayn kirjaimet listana ja niiden välissä on välilyönti
void tulostaKirjaimet(char kirjaimet[])
{
    int iter;

    for (iter = 0; iter < strlen(kirjaimet); iter++) 
    {
        printf("%c ", kirjaimet[iter]);
    }
}

// Tämä funktio tulostaa pelin ruudun
// Jos oikea kirjain piilotetusta sanasta on arvattu oikein, näyttää tämä kirjaimen, muussa tapauksessa '_'
void tulostaRuutu(char oikeat[], char vaarat[], char sala[])
{
    int iter;

    // Tyhjää ruudun (tyhmä ratkaisu, keksi parempi)
    for (iter = 0; iter < 25; iter++)
        printf("\n");

    // Tulostaa hirsipuun
    tulostaHirsipuu(strlen(vaarat));
    printf("\n");

    // Tulostaa tähän mennessä oikein ja väärin arvatut
    printf("Oikeat arvaukset: ");
    tulostaKirjaimet(oikeat);
    printf("\n");
    printf("Väärät arvaukset: ");
    tulostaKirjaimet(vaarat);
    printf("\n\n\n");

    // Tulostaa piilotetun sanan
    printf("\t");
    for (iter = 0; iter < strlen(sala); iter++) 
    {
        if (onkoSana(oikeat, sala[iter])) 
        {
            printf("%c ", sala[iter]);
        }
        else 
        {
            printf("_ ");
        }
    }
    printf("\n\n");
}

int main()
{
    // Tämä on indeksi salaiselle sanalle sanalistassa mikä on globaalina muuttujana ohjelman alussa
    int salaindeksi;

    // Tämä array sisältää kaikki käyttäjän oikein arvaamat kirjaimet
    char oikeat[20];

    // Tämä array sisältää kaikki käyttäjän väärin arvaamat kirjaimet
    char vaarat[7];

    // Tätä arvoa käytetään pelaajan sen hetkisen arvauksen tekemiseen loopissa
    char arvaus;    

    // Satunnaistetaan srandilla pelin sanalista
    srand(time(NULL));
    // Sitten talletetaan satunnainen annettu numero salaindeksiin, jonka peitto on 0 - 8 (sanojen määrä arrayssa) - 1
    salaindeksi = rand() % 8;

    // Oikeat array käyttöön, tässä täytetään nollilla. \0 on nollan ascii arvo
    for (int iter =0 ; iter<20; iter++)
    {
        oikeat[iter]='\0';
        
    }

    // Vaarat array käyttöön, tässä täytetään nollilla. \0 on nollan ascii arvo
    for(int j = 0 ;j<7;j++)
    {
        vaarat[j]='\0';
        
    }

    // While looppi, kun väärien arvausten määrä on suurempi tai yhtä suuri kuin 6 tai kun salaisen sanan kaikki kirjaimet on arvattu oikein
    while (strlen(vaarat)<6 && !onkoValmis(sanat[salaindeksi],oikeat)) 
    { 
        // Tulosta hirsipuuruutu
        tulostaRuutu(oikeat, vaarat, sanat[salaindeksi]);

        // Kysytään arvausta
        printf("\nAnna arvauksesi: ");
        scanf(" %c", &arvaus);

        // Tässä käytetään onkoSana funtiota eli, jos arvattu kirjain on piilotetussa sanassa, silloin arvaus menee oikeat arrayhin.
        // Muussa tapauksessa se menee vaarat arrayhin
        //
        if (onkoSana(sanat[salaindeksi],arvaus))
        {
            oikeat[strlen(oikeat)]=arvaus;
            
        }
        else
        {
            vaarat[strlen(vaarat)]=arvaus;
            
        }


    }

    // Tulostetaan lopullinen hirsipuu
    tulostaRuutu(oikeat, vaarat, sanat[salaindeksi]);

    // Lopuksi tulostetaan voittiko vai hävisikö pelaaja
    if(strlen(vaarat)>=6)
    {
        printf("Hävisit!\n");
        
    }
    else
    {
        printf("Voitit!\n");
        
    }


}