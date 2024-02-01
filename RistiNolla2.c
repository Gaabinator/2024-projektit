#include <stdio.h>
 
// Luodaan globaali 2D array jota voidaan käyttää loopeissa
char kentta[3][3];
 

void luokentta();
void naytakentta(int, int);
int kentanPaivitys(int, char);
int tarkistaVoittaja(char);
void pelaaRistinolla();

// Luo kenttä
void luokentta()
{   //tyhjät
    for (int iter = 0; iter < 3; iter++)  
    {
        for (int j = 0; j < 3; j++)
        {
            kentta[iter][j] = ' ';
        }
    }
    int laske = 1; // aloittaa laskemisen 1sta nollan sijaan kentässä
    printf("\n\n\t  ");
    for(int iter = 0; iter < 3; iter++) 
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d", laske++); 
            if (j < 2) // loopataan tolpat  
            {
                printf("  |  ");
            }
        }
        if (iter < 2)
        printf("\n\t----------------\n\t  "); // viivat
    }
    printf("\n\n\n");
}
 
// Näytetään kenttä
void naytakentta(int x, int y)
{
    printf("\n\n\t  ");
    for (int iter = 0; iter < 3; iter++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", kentta[iter][j]);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (iter < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}
 


// Kentän päivitys
int kentanPaivitys(int solu, char pelaajaMerkki)
{
    int rivi = (solu - 1) / 3;
    int sarake = (solu - 1) % 3;
    int onkoOK = 1;
 
    // tarkistetaan onko solussa merkkiä
    if (kentta[rivi][sarake] != ' ')
    {
        printf("\nOle tarkkana: Valitussa paikassa on jo merkki!\n");
        onkoOK = 0;
    }
 
    // onko oikea paikka kentässä ja solussa
    else
    {
        kentta[rivi][sarake] = pelaajaMerkki;
    }
    naytakentta(rivi, sarake);
 
    return onkoOK;
}
 
// Rakenna funktio, jossa tarkistetaan voittaja. Eli käydään läpi jokainen ruutu/solu kentän pysty/vaaka-riveissä, samoin myös ristiin.
// Voittajan tarkistus funktio
int tarkistaVoittaja(char tv)
{
    // tarkistetaan kaikki rivit
    if (kentta[0][0] == tv && kentta[0][1] == tv && kentta[0][2] == tv ||
      kentta[1][0] == tv && kentta[1][1] == tv && kentta[1][2] == tv ||
      kentta[2][0] == tv && kentta[2][1] == tv && kentta[2][2] == tv)
    {
        return 1;
      }
      // tarkistetaan kaikki sarakkeet
    else if (kentta[0][0] == tv && kentta[1][0] == tv && kentta[2][0] == tv ||
           kentta[0][1] == tv && kentta[1][1] == tv && kentta[2][1] == tv ||
           kentta[0][2] == tv && kentta[1][2] == tv && kentta[2][2] == tv)
    {
        return 1;
    }
    // tarkistetaan ristiin
    else if (kentta[0][0] == tv && kentta[1][1] == tv && kentta[2][2] == tv ||
           kentta[0][2] == tv && kentta[1][1] == tv && kentta[2][0] == tv)
    {
        return 1;
    }
 
    // Ei ole voittajaa
    return 0;
}
 

// Peli alkaa tästä
void pelaaRistinolla()
{
    int tuomio = 0;
    int solu = 0;
    int laskuri = 0;
    int tulosPaivitys = 1;
 
    char pelaajaMerkki = ' ';
 
    // Aloita pelaamaan peliä
    while (!tuomio && laskuri < 9)
    {
        if (laskuri % 2 == 0)
        {
            // pelaaja 1
            printf("\nPelaaja 1 [ X ] : ");
            pelaajaMerkki = 'X';
        }
        else
        {
            // pelaaja 2
            printf("\nPelaaja 2 [ O ] : ");
            pelaajaMerkki = 'O';
        }
        scanf("%d", &solu);
        if (solu > 0 && solu < 10)
        {
            tulosPaivitys = kentanPaivitys(solu, pelaajaMerkki);
            // jos päivitys mahdollista
            if (tulosPaivitys)
            {
                tuomio = tarkistaVoittaja(pelaajaMerkki);
                // Tulostaa pelin voittajan
                if (tuomio)
                {
                    printf("\t *** Pelaaja %d voitti!! ***\n", pelaajaMerkki == 'X' ? 1 : 2);
                }
                laskuri++;
            }
        }
        else if (solu == -1)
        {
            printf("\n\tPeli lopetettu\n");
            return;
        }
        else
        {
            printf("\nSyötä oikea luku solulle\n");
        }
    }
 
    // Kukaan ei voittanut peliä

    if (!tuomio && laskuri == 9)
    {
        printf("\n\t *** Tasapeli...  ***\n");
    }
    printf("\n\t --- Peli ohi --- \n");
}

 
int main()
{

    // Printtaa ohjeistus ja tervetuloviesti
    printf("!! Tervetuloa ristonolla peliin !!\n\n"); 
    printf("\n* Ohjeet \n\n");
    printf("\nPelaajan 1 merkki = X");
    printf("\nPelaajan 2 merkki = O");
    printf("\nVoit sammuttaa pelin pelaajan vuorolla syöttämällä -1\n");
 
    printf("\n\n* Solujen numerot kentässä\n");
    luokentta();
 
    char startti = ' ';
    printf("\n> Paina Enter pelataksesi...");
 
    scanf("%c", &startti);
 
    if (startti)
    {
        int pelaajanValinta = 1;
        // aloita peli uudelleen
        while (pelaajanValinta)
        {
            pelaaRistinolla();
            printf("\n* Valikko\n");
            printf("\nPaina 1 pelaaksesi uudelleen");
            printf("\nPaina 0 lopettaaksesi");
            printf("\n\nValinta: ");
            scanf("%d", &pelaajanValinta);
            if (pelaajanValinta)
            {
                luokentta();
            }
            printf("\n");
        }
    }
    printf("\n :: Kiitos ristonollan pelaamisesta! :: \n");



 
   
    return 0;
}