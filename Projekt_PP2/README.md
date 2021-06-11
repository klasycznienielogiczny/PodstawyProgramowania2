## Instrukcja uruchomienia projektu

Aby uruchomić projekt wystarczy sklonować repozytorium.
Należy upewnić się, że zainstalowane są biblioteki _curl_ oraz _jsoncpp_.

Można je zainstalować na systemie z rodziny linux z użyciem poleceń

```sudo apt-get install libjsoncpp-dev```

oraz

``` sudo apt-get install curl```

Biblioteka _csv.h_ została załączona do repozytorium.

Podczas kompilacji należy pamiętać o dodaniu flag

``` -ljsoncpp -lcurl```

Zakładając, że skompilowany projekt ma nazwę ```sip``` można go uruchomić za pomocą polecenia ```./sip```.

![uruchomienie](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-53-26.png)

## Instrukcja korzystania

Po uruchomieniu projektu pojawia się następujące okno

![menu](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-54-01.png)

Możemy:

* [sprawdzić rozkład na wybranym przystanku](#sprawdzenie-rozkładu)
* [zobaczyć instrukcję korzystania z programu](#instrukcja)
* [wyjść z programu](#wyjście-z-programu)

### Sprawdzenie rozkładu

![szukanie_przystanku](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-55-37.png)

Po wyborze opcji ```1. Sprawdź rozkład na wybranym przystanku``` pojawia się powyższe okno. Należy wpisać conajmniej trzy znaki
z nazwy przystanku i zatwierdzić enterem. W przypadku wpisania ciągu, którego nie zawiera żadna nazwa przystanku pojawi się stosowna
informacja.

![bledna_nazwa](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-55-48.png)

Gdy ciąg będzie poprawny, zostaną wyświetlone wszystkie przystanki spełniające podane kryterium.

![szukanie2](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-56-03.png)

![znalezione](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-56-14.png)

Następnie należy wpisać ID interesującego nas przystanku i zatwierdzić enterem.

![podano_id](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-57-09.png)

W przypadku braku odjazdów z danego przystanku wyświetlona zostaje stosowna informacja.

![brak_kursow](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-57-24.png)

W przeciwnym razie wyświetlone zostają najbliższe odjazdy.

![znajdz_o_id](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-57-49.png)

![odjazdy](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-57-59.png)

Na górze prezentowana jest pełna nazwa przystanku, następnie wyświetlana jest _tablica_ z informacją o numerze linii, kierunku oraz
godzinie odjazdu. Kolorem zielonym zaznaczono kursy bez opóźnienia, kolorem czerwonym kursy opóźnione. Na samym dole prezentowana
jest informacja o dacie pobranych danych.


### Instrukcja

![instrukcja](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-54-37.png)

Po wyborze opcji ```2. Instrukcja obsługi``` pojawia się powyższe okno. Po przeczytaniu instrukcji wystarczy kliknąć
dowolny klawisz, aby wrócić do menu.

### Wyjście z programu

Po wybraniu opcji ```3. Wyjdz z programu``` kończona jest praca z programem.

![wyjscie](/screenshots/Zrzut%20ekranu%20z%202021-06-11%2007-58-18.png)