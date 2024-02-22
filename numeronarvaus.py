import random
import time

def arvaa(luku):
    montakertaa = 0

    # Initialize randomizer
    random.seed(time.time())

    # Luodaan satunnainen luku
    numero = random.randint(1, luku)

    print(f"Arvaa numero 1 ja {luku} välillä")

    # Avataan while looppi, joka pyörii niin kauan kun pelaaja arvaa ohjelman generoiman luvun tai arvauskerrat tulee täyteen
    while True:
        if montakertaa > 9:
            print("\nHävisit!")
            break

        # Pelaajan arvaus
        arvaus = int(input())

        # Jos pelaajan arvaus on suuri
        if arvaus > numero:
            print("\nPienempi")
            montakertaa += 1  # lisätään arvauskertojen määrä

        # Jos pelaajan arvaus on pieni
        elif numero > arvaus:
            print("\nSuurempi")
            montakertaa += 1

        else:
            print(f"Olet arvannut numeron {montakertaa + 1} yrittämällä!")  # tulostaa montako kertaa piti yrittää, että osui kohdilleen
            break


def main():
    # Kutsutaan arvaa funktio halutulla peitolla, tässä tapauksessa 1-100 välillä kun arvaa on 100
    arvaa(100)  

if __name__ == "__main__":
    main()
