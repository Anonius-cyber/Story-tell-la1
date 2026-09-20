# Prompts pentru Lab01 (Insula Uitata)

Fisierul asta contine prompturile pe care le-am folosit cu un LLM (Claude) ca sa ma ajute cu codul si cu configurarea proiectului, plus ce rezultat am obtinut sau ce problema am rezolvat cu fiecare.

## Prompt 1

Ce am cerut:
Cerinta laboratorului - un joc text adventure (Story Tale) in C++, cu fisiere .hpp separate pentru motorul de joc (GameEngine), desenator (Renderer) si ascultator (Listener), plus README.md cu descrierea proiectului si a structurilor de date, si acest fisier de prompturi.

Ce am primit:
Structura completa a proiectului - GameTypes.hpp, GameEngine.hpp, Renderer.hpp, Listener.hpp, main.cpp, README.md. Povestea se numeste Insula Uitata, are 9 scene si 2 finaluri diferite. Codul a fost verificat prin compilare cu g++ -std=c++17 inainte sa-l primesc, asa ca a mers direct.

## Prompt 2

Ce am cerut:
Cum fac pasii de Git/GitHub direct din Visual Studio, nu din linie de comanda.

Ce am primit:
Pasii pentru a clona repo-ul din Visual Studio (Clone a Repository), a crea un proiect Console App, a adauga fisierele generate si a face commit/push din interfata grafica.

## Prompt 3

Ce am cerut:
Am trimis un screenshot cu structura mea reala - fisierele erau intr-un folder numit "files", aveam doua README.md si un fisier files.zip nefolosit.

Ce am primit / ce am rezolvat:
Mi s-a explicat cum sa unesc cele doua README.md, sa mut fisierele de cod la radacina proiectului, sa sterg folderul files si files.zip, si sa adaug un CMakeLists.txt ca sa pot compila si rula direct din Visual Studio (mod Open Folder, fara .sln).

## Prompt 4

Ce am cerut:
Am zis ca la mine proiectul din Git se numeste Story-tell-la1, diferit de numele folosit initial in CMakeLists.txt.

Ce am primit:
Confirmare ca numele cu cratima e valid pentru CMake si ca executabilul rezultat va fi Story-tell-la1.exe.

## Prompt 5

Ce am cerut:
Butonul Commit All din Visual Studio nu facea nimic.

Ce am primit / ce am rezolvat:
O lista de cauze posibile (mesaj de commit gol, fisiere nesalvate, identitate Git nesetata, gitignore care exclude fisiere din greseala) si sfatul sa verific direct din terminal cu git status ca sa vad exact ce se intampla.

## Prompt 6

Ce am cerut:
Am trimis output-ul lui git status din terminal - aratam ca toate fisierele erau untracked, inclusiv folderul .vs.

Ce am primit / ce am rezolvat:
Mi s-a spus sa adaug .vs/ in .gitignore, ca sa nu urc pe GitHub folderul intern al Visual Studio, si apoi sa rulez git add ., git commit, git push.

## Prompt 7

Ce am cerut:
A aparut un popup in Visual Studio despre un conflict pe fisierul .gitignore (fusese modificat si din editor si din terminal in acelasi timp).

Ce am primit / ce am rezolvat:
Mi s-a explicat ca e sigur sa apas Yes ca sa reincarc fisierul de pe disc, pentru ca ambele modificari incercau sa scrie exact acelasi lucru.

## Prompt 8

Ce am cerut:
Am trimis rezultatul final dupa git commit si git push.

Ce am primit:
Confirmare ca push-ul a reusit (main -> main) si recomandarea sa verific pe github.com ca fisierele apar in repository.

## Prompt 9

Ce am cerut:
Ce fac daca modific ceva mai tarziu in README.md sau in acest fisier.

Ce am primit:
Acelasi ciclu de fiecare data - salvez fisierele, git add ., git commit -m "...", git push.

## Prompt 10

Ce am cerut:
Sa rescriu README.md si acest fisier intr-un stil mai simplu, ca si cum le-as fi scris eu, fara diacritice si fara semne care nu sunt pe tastatura.

Ce am primit:
Ambele fisiere rescrise fara diacritice, cu propozitii mai simple si fara formatari ciudate (tabele, caractere speciale etc).

---

Notez o sectiune noua "Prompt N" de fiecare data cand mai folosesc LLM-ul ca sa modific ceva la proiect.
