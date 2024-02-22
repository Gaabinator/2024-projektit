import random

# Pelaajan valinta eli kivi, paperi vai sakset, palautetaan pienillä kirjaimilla
def pelaajan_valinta():
    valinta = input("Minkä valitset (kivi, paperi, sakset): ")
    return valinta.lower()


# Tietokoneen valinta, random generaattorilla valitsee jonkun
def tietokoneen_valinta():
    valinnat = ["kivi", "paperi", "sakset"]
    return random.choice(valinnat) 

# Pelin voittaja, missä vertaillaan eri kombinaatiot. 
def pelin_voittaja(käyttäjä, tietokone):
    if käyttäjä == tietokone:
        return "tasapeli"
    vertailu = [("kivi", "sakset"), ("sakset", "paperi"), ("paperi", "kivi")]
    return "käyttäjä" if (käyttäjä, tietokone) in vertailu else "tietokone"


def main():
    while True:
        pelaajanValinta = pelaajan_valinta()
        tietokoneenValinta = tietokoneen_valinta()
        print(f"\nSinä valitsit {pelaajanValinta}, tietokone valitsi {tietokoneenValinta}.\n")
        voittaja = pelin_voittaja(pelaajanValinta, tietokoneenValinta)

        if voittaja == "tasapeli":
            print("Se on tasapeli")
        elif voittaja == "käyttäjä":
            print("Sinä voitit!")
        elif voittaja == "tietokone":
            print("Tietokone voittaa!")

        uusi_peli = input("Uusi peli? (k/e): ")
        if uusi_peli.lower() != "k":
            break

if __name__ == "__main__":
    main()

