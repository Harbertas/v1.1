# V1.0 programos versija
1. Palyginta programos sparta naudojant #PirmaStrategija ir #AntraStrategija
2. Patyrinėti ankčiau nenaudoti algoritmai
3. Sukurtas MakeFile.
# V0.5 programos versija
## Kas pasikeitė nuo v0.4 versijos?
1. Sukurtos programos naudojant VECTOR, LIST ir DEQUE
2. Programų matavimo sparta.
## Spartos analizė
| File Size   | VECTOR    | LIST      | DEQUE     |
| ----------- | --------- | --------- | --------- |
| 10 000 000  |           |           |           |
| Nuskaitymas | 6,56743   | 7,4048    | 6,57549   |
| Rūšiavimas  | 22,5238   | 15,1803   | 48,5964   |
| Atskyrimas  | 6,14556   | 9,90316   | 8,91084   |
| Visas Laikas| 35,2368   | 32,4883   | 64,0827   |
| 1 000 000   |           |           |           |
| Nuskaitymas | 0,674196  | 0,732539  | 0,661231  |
| Rūšiavimas  | 1,81215   | 1,22027   | 4,02281   |
| Atskyrimas  | 0,540555  | 0,922065  | 0,734049  |
| Visas Laikas| 3,0269    | 2.87487   | 5,41809   |
| 100 000     |           |           |           |
| Nuskaitymas | 0,0787889 | 0,0797862 | 0,0668212 |
| Rūšiavimas  | 0,140624  | 0,0812882 | 0,299705  |
| Atskyrimas  | 0,0468748 | 0,0862754 | 0,0618351 |
| Visas Laikas| 0,266288  | 0,24735   | 0,428361  |
| 10 000      |           |           |           |
| Nuskaitymas | 0,0069805 | 0,009973  | 0,0089758 |
| Rūšiavimas  | 0,0119678 | 0,0059842 | 0,0239358 |
| Atskyrimas  | 0,0049868 | 0,005984  | 0,0059839 |
| Visas Laikas| 0,0239351 | 0,0219412 | 0,0388955 |
| 1 000       |           |           |           |
| Nuskaitymas | 0,0009974 | 0,0009963 | 0,0009976 |
| Rūšiavimas  | 0,0009971 | 0,0009985 | 0,0019944 |
| Atskyrimas  | 0,0009968 | 0,0009971 | 0,0000000 |
| Visas Laikas| 0,0029913 | 0,0029919 | 0,002992  |

Išvada: 
1. Naudojant list konteinerius programos bendras veikimo laikas greičiausias, antroje vietoje vector konteineris.
2. List rūšiavimas yra greičiausias.
3. Vector atskyrimas greičiausias.
4. Visų konteinerių nuskaitymo laikai +- vienodi.
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
