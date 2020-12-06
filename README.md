# ProgramavimasAG
**Antroji strategija** (studentų perkėlimas tik į vieną naują konteinerį šalinat perkeltuosiuos iš pradinio konteinerio)
**Programos sparta naudojant antrąją strategiją, ir naudojant algoritmus( *std::remove_copy_if, std::remove_if*):**
**Generavimo greitis:**
|Konteineris| 1000 | 10000 | 100000 | 1000000 |10000000 |
| --------- |:----:|:-----:|:------:|:-------:|--------:|
|Std::vector| 37 ms|354 ms | 4285 ms|52680 ms |590948 ms|

**Skirstymo ir spausdinimo greitis:**
|Konteineris| 1000 |10000  | 100000 |1000000  | 10000000 |
| --------- |:----:| :----:|:------:|:-------:|---------:|
|Std::vector|33 ms |286  ms| 3219 ms|43210  ms|492473  ms|
