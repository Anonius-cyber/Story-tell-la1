# Story-tell-la1

Joc de tip Text Adventure (Story Tale) - laborator de programare orientata pe obiecte.

## Ce este proiectul

Story-tell-la1 este un joc text in care controlezi un naufragiat care se trezeste pe o insula necunoscuta. Trebuie sa exploreze insula, sa gaseasca obiecte si sa ia decizii ca sa gaseasca o cale de salvare (sau sa gaseasca o comoara ascunsa).

Jocul ruleaza in consola. La fiecare pas:
 citesti descrierea scenei in care esti
alegi una din optiunile numerotate, sau scrii o comanda speciala
 jocul actualizeaza starea (inventar, flag-uri, scena curenta) in functie de alegerea ta

## Comenzi disponibile

 1, 2, 3... - alegi optiunea cu numarul respectiv din scena curenta
 inv - iti arata inventarul curent
 help - iti arata lista de comenzi
 quit - iesi din joc

Unele alegeri au nevoie de un obiect anume din inventar (de exemplu o oglinda de semnalizare ca sa chemi o nava), iar altele iti dau un obiect nou. Jocul se termina cand ajungi intr-o scena de final. Sunt mai multe finaluri posibile (salvare, comoara ascunsa etc).

## Structuri de date folosite

Toate structurile de date sunt in fisierul GameTypes.hpp:

 Item - un obiect din joc (id, name, description)
 Choice - o optiune dintr-o scena: textul care se afiseaza, scena spre care duce (targetSceneId), un obiect necesar optional (requiredItemId), un obiect pe care il primesti optional (givesItemId) si un flag boolean care poate fi setat (setFlag)
Scene - o scena din poveste: id, title, description, lista de Choice si un flag isEnding care spune daca e o scena finala
GameState - starea curenta a jocului: scena curenta (currentSceneId), inventarul jucatorului (inventory), flag-urile boolene pentru diverse decizii (flags), numarul de ture (turnCount) si daca jocul mai ruleaza (isRunning)

Povestea e practic un graf: fiecare Scene e un nod, iar fiecare Choice e o muchie catre alta scena.

## Fisierele proiectului

 GameTypes.hpp - structurile de date de baza (Item, Choice, Scene, GameState)
 GameEngine.hpp - motorul de joc, tine povestea si starea, ruleaza bucla principala
 Renderer.hpp - deseneaza scenele, inventarul si mesajele in consola
 Listener.hpp - citeste si interpreteaza ce scrie jucatorul
main.cpp - punctul de pornire al jocului
 CMakeLists.txt - fisierul de configurare pentru compilare cu CMake

GameEngine foloseste Renderer ca sa afiseze lucruri si Listener ca sa citeasca alegerile jucatorului. Renderer si Listener nu stiu unul de celalalt, comunica doar prin GameEngine.

## Cum compilez si rulez

g++ -std=c++17 -Wall -o insula_uitata main.cpp
./insula_uitata

sau in Visual Studio, cu CMakeLists.txt, direct din Select Startup Item.

## Ce as putea adauga mai tarziu

Povestea e hardcodata acum in GameEngine::buildStory(). O idee ar fi sa o mut intr-un fisier extern (json sau text), ca sa pot schimba povestea fara sa umblu la Renderer sau Listener.

## Autor

Anonius-cyber
Autor Stanislav