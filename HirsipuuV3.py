import random
import time

# Lista sanoista, josta hirsipuupeli valitsee satunnaisesti
sanat = [
    "kuoppa",
    "ostoskori",
    "ohjelmointi",
    "kieli",
    "auto",
    "kirous",
    "historia",
    "haava"
]

def onkoSana(sana, kirjain):
    # Etsitään for loopissa pelaajan syötetty kirjain, jos se osuu piilotettuun sanaan
    # Jokaisessa kohdassa, jossa syötetty kirjain on sama kuin sanassa, palautuu tosi.
    # Jos kirjainta ei löydy loopin jälkeen, palauttaa epätosin

    for char in sana:
        if kirjain == char:
            return True

    return False

def onkoValmis(sala, oikeat):
    # For looppi, jolla tarkastellaan salaisen sanan jokaista sijaintia
    # Jos kaikki salaisen sanan kirjaimet ovat oikeat arrayssa niin, palauta tosi, muussa tapauksessa palauta epätosi
    for iter in range(len(sala)):
        for j in range(len(oikeat)):
            if sala[iter] == oikeat[j] and iter == (len(sala) - 1):
                return True

    return False

def tulostaHirsipuu(montavaaraa):
    print("\t  ______")
    print("\t  |     |")
    print("\t  |     +")

    # Vasen käsi, pää ja oikea käsi
    print("\t  |", end="")
    if montavaaraa > 0: print("    \\", end="")
    if montavaaraa > 1: print("O", end="")
    if montavaaraa > 2: print("/", end="")
    print()

    # Kroppa
    print("\t  |", end="")
    if montavaaraa > 3: print("     |", end="")
    print()

    # Vasen ja oikea jalka
    print("\t  |", end="")
    if montavaaraa > 4: print("    /", end="")
    if montavaaraa > 5: print(" \\", end="")
    print()
    print("\t  |")
    print("\t__|__")

def tulostaKirjaimet(kirjaimet):
    for kirjain in kirjaimet:
        print(kirjain, end=" ")

def tulostaRuutu(oikeat, vaarat, sala):
    # Tyhjää ruudun (tyhmä ratkaisu, keksi parempi)
    for _ in range(25):
        print()

    # Tulostaa hirsipuun
    tulostaHirsipuu(len(vaarat))
    print()

    # Tulostaa tähän mennessä oikein ja väärin arvatut
    print("Oikeat arvaukset:", end=" ")
    tulostaKirjaimet(oikeat)
    print()
    print("Väärät arvaukset:", end=" ")
    tulostaKirjaimet(vaarat)
    print("\n\n")

    # Tulostaa piilotetun sanan
    print("\t", end="")
    for kirjain in sala:
        if onkoSana(oikeat, kirjain):
            print(kirjain, end=" ")
        else:
            print("_", end=" ")
    print("\n")

def main():
    # Tämä on indeksi salaiselle sanalle sanalistassa mikä on globaalina muuttujana ohjelman alussa
    salaindeksi = 0

    # Tämä array sisältää kaikki käyttäjän oikein arvaamat kirjaimet
    oikeat = []

    # Tämä array sisältää kaikki käyttäjän väärin arvaamat kirjaimet
    vaarat = []

    # Satunnaistetaan pelin sanalista
    random.seed(time.time())
    # Sitten talletetaan satunnainen annettu numero salaindeksiin, jonka peitto on 0 - 8 (sanojen määrä arrayssa) - 1
    salaindeksi = random.randint(0, 7)

    # While looppi, kun väärien arvausten määrä on suurempi tai yhtä suuri kuin 6 tai kun salaisen sanan kaikki kirjaimet on arvattu oikein
    while len(vaarat) < 6 and not onkoValmis(sanat[salaindeksi], oikeat):
        # Tulosta hirsipuuruutu
        tulostaRuutu(oikeat, vaarat, sanat[salaindeksi])

        # Kysytään arvausta
        print("\nAnna arvauksesi: ")
        arvaus = input()

        # Tässä käytetään onkoSana funtiota eli, jos arvattu kirjain on piilotetussa sanassa, silloin arvaus menee oikeat arrayhin.
        # Muussa tapauksessa se menee vaarat arrayhin
        if onkoSana(sanat[salaindeksi], arvaus):
            oikeat.append(arvaus)
        else:
            vaarat.append(arvaus)
        
        print("Vaarat array nyt:", vaarat)  # Print the vaarat array to debug

    # Tulostetaan lopullinen hirsipuu
    tulostaRuutu(oikeat, vaarat, sanat[salaindeksi])

    # Lopuksi tulostetaan voittiko vai hävisikö pelaaja
    if len(vaarat) >= 6:
        print("Hävisit!")
    else:
        print("Voitit!")


if __name__ == "__main__":
    main()        