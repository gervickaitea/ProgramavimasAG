# ProgramavimasAG
# 0.1 V
0.1 versijoje pirmiausia suskaičiuojama mediana. Tada sugeneruojami random skaičiai nuo 1-10, kadangi jų reikės norint automatiškai įvesti pažymius. Toliau funkcija automatiškai suveda pažymius ir egzamino pažymį arba leidžia pačiam vartotojui juos įvesti. Sekanti funkcija leidžia įvesti studento vardą ir pavardę. Galiausiai atspausdinami rezultatai.
# 0.2 V
Antroje versijoje yra nuskaitomas failas ir suskaiciuojami galutiniai pazymiai bei viskas tvarkingai isvedama faile "rezultatai.txt".
# 0.3 V
Šioje versijoje funkcijos yra išskirstytos į h ir cpp failus. Taip pat kai yra nuskaitoma iš failo, įdėtas exception, kad kiekvieną kartą tikrintų ar gerai įvestas failo pavadinimas. Jei ne, išmetama "Neteisingas failo pavadinimas", taip žinome kur palikome klaidą. Pati programa nuskaito duomenis iš studentai100000.txt failo ir sukuria nauja txt faila "rezultatai.txt', kuriame gražiai pagal vardus ir pavardes surūšiuoja studentus bei apskaičiuoja jų GP ir medianą. 
# 0.4 V
Pirmiausia programa paprašo įvesti studentų skaičių. Kai skaičius yra įvedamas, tada sukuriamas txt failas su tiek studentų (vardas, pavardė ir random suskaičiuotas GP). Toliau tas sukurtas failas yra nuskaitomas. Kai failas yra nuskaitytas tada studentai yra suskirstomi į dvi kategorijas- protingi ir vargšiukai. Toliau studentus suskirstytus į dvi katerogijas sudeda i du naujus txt failus. Taip pat programoje atlikta greičio analizė: 
failų kūrimas;
duomenų nuskaitymas iš failų;
studentų rūšiavimas į dvi grupes/kategorijas;
surūšiuotų studentų išvedimas į du naujus failus.
# 0.5 V
Testavimo sistemos parametrai:
CPU: Intel(R) Core(TM) i5-3320M CPU @ 2.60GHz
RAM:	Installed Physical Memory (RAM)	8,00 GB
SSD: 240 GB

Duomenų nuskaitymas iš failų:
|1000        | 10000      | 100000   | 1000000    | 10000000 |
|:----------:| :---------:|:--------:|:----------:|:--------:|
| 0.0359733 s| 0.518194 s | 3.99218 s| 42.4784 s  | 330.505 s|

Studentų rūšiavimas į dvi grupes:

|1000        | 10000      | 100000   | 1000000            | 10000000          |
|:----------:| :---------:|:--------:|:------------------:|:-----------------:|
| 35.1544 s  | 3393.77 s  |33687.25 s| neuzteko atminties | neuzteko atminties|
# 1.0 V
Programa  buvo perrašyta nuo pagrindų kadangi nepavyko pakeisti praeitos programos, pagal reikalavimus.
1.0L- listas
1.0VV- vektorius
Pirmoji strategija (studentų išskaidymas į du tipus, tačiau taip pat jų palikimas pradiniame konteineryje) 
Ši programos versija padaryta dviem konteineriais- List ir Vector.  
**Skirstymo ir spausdinimo greitis:**
|Konteineris|1000  | 10000  | 100000 | 1000000  | 
| --------- |:----:| :-----:|:------:|:--------:|
|Std::List  | 26 ms| 224 ms | 2512 ms| 22844ms  | 
|Std::vector|132 ms|12484 ms|210127ms|2459025 ms| 

# 1.0 V(2)
**Antroji strategija** (studentų perkėlimas tik į vieną naują konteinerį šalinat perkeltuosiuos iš pradinio konteinerio)
**Programos sparta naudojant antrąją strategiją, ir naudojant algoritmus( *std::remove_copy_if, std::remove_if*):**
**Generavimo greitis:**
|Konteineris| 1000 | 10000 | 100000 | 1000000 |10000000 |
| --------- |:----:|:-----:|:------:|:-------:|--------:|
|Std::vector| 39 ms|355 ms | 4291 ms|52682 ms |590945 ms|

**Skirstymo ir spausdinimo greitis:**
|Konteineris| 1000 |10000  | 100000 |1000000  | 10000000 |
| --------- |:----:| :----:|:------:|:-------:|---------:|
|Std::vector|32 ms |287  ms| 3218 ms|43213  ms|492475  ms|

