# V0.5 programos versija
## Kas pasikeitė nuo v0.4 versijos?
1. Sukurtos programos naudojant VECTOR, LIST ir DEQUE
2. Programų matavimo sparta.
## Spartos analizė
| File Size   | VECTOR    | LIST      | DEQUE     |
| ----------- | --------- | --------- | --------- |
| 10 000 000  |           |           |           |
| Nuskaitymas | 6,56743   | 7,32453   | 6,52963   |
| Rūšiavimas  | 22,5238   | 15,1796   | 48,6143   |
| Atskyrimas  | 6,14556   | 26,519    | 58,752    |
| Visas Laikas| 35,2368   | 49,0231   | 113,896   |
| 1 000 000   |           |           |           |
| Nuskaitymas | 0,674196  | 0,696138  | 0,649767  |
| Rūšiavimas  | 1,81215   | 1,0472    | 3,83383   |
| Atskyrimas  | 0,540555  | 2,3946    | 1,76381   |
| Visas Laikas| 3,0269    | 4,13793   | 6,24741   |
| 100 000     |           |           |           |
| Nuskaitymas | 0,0787889 | 0,072805  | 0,0822853 |
| Rūšiavimas  | 0,140624  | 0,0738027 | 0,293227  |
| Atskyrimas  | 0,0468748 | 0,2244    | 0,155584  |
| Visas Laikas| 0,266288  | 0,371008  | 0,531096  |
| 10 000      |           |           |           |
| Nuskaitymas | 0,0069805 | 0,007978  | 0,007979  |
| Rūšiavimas  | 0,0119678 | 0,0049865 | 0,0269279 |
| Atskyrimas  | 0,0049868 | 0,0169547 | 0,0159578 |
| Visas Laikas| 0,0239351 | 0,0299192 | 0,0508647 |
| 1 000       |           |           |           |
| Nuskaitymas | 0,0009974 | 0,000997  | 0,0009974 |
| Rūšiavimas  | 0,0009971 | 0,000000  | 0,0019946 |
| Atskyrimas  | 0,0009968 | 0,0019947 | 0,0009971 |
| Visas Laikas| 0,0029913 | 0,0029917 | 0,0039891 |

Išvada: 
1. Naudojant vector konteinerius programos bendras veikimo laikas greičiausias, antroje vietoje list konteineris.
2. List rūšiavimas yra greičiausias.
3. Vector ir Deque nuskaitymo laikai +- vienodi.
### main.cpp - pagrindinis failas
### functions.h - struktūros, funkcijų apibrėžimai ir includes
### functions.cpp - funkcijų implementacijos
### mix.h - skaitymo iš failo funkcijos apibrėžimas
### mix.cpp - skaitymo iš failo funkcijos implementacija
### Ką galite daryti su šia programa?
1. Sukurti studentų failą, pasirenkant kiek studentų saugosite.
2. Surikiuoti rezultatus pagal galutinį pažymį.
3. Išvesti rezultatus į failus pagal galutinį pažymį (<5 nelaimingieji.txt, >= 5 kietekai.txt).
4. Pasirinkti kiek pažymių norite generuoti studentui.
