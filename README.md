# ProgramavimasAG
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
