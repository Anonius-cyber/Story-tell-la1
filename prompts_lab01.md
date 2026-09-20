# Prompts LLM — Laboratorul 1 (Insula Uitată)

Acest fișier documentează prompturile folosite împreună cu un model LLM
(Claude) pentru generarea și corectarea codului din acest proiect, conform
cerinței 9 din enunțul laboratorului.

## Prompt 1

**Prompt folosit:**
> Cerința laboratorului (rezumat): implementarea unui joc text adventure
> ("Story Tale") în C++, cu fișiere `.hpp` separate pentru motorul de joc
> (GameEngine), desenator (Renderer) și ascultător (Listener), plus un
> README.md cu descrierea proiectului și a structurilor de date, și acest
> fișier de prompturi.

**Rezultat obținut:**
- Structura proiectului: `GameTypes.hpp`, `GameEngine.hpp`, `Renderer.hpp`,
  `Listener.hpp`, `main.cpp`, `README.md`.
- O poveste de bază ("Insula Uitată") cu 9 scene și 2 finaluri, hardcodată
  în `GameEngine::buildStory()`.
- Cod verificat prin compilare locală: `g++ -std=c++17 -Wall -Wextra` —
  compilează fără erori (doar avertismente minore, nesemnificative, legate
  de inițializarea implicită a câmpului `Choice::setFlag`).
- Testare manuală prin rularea jocului cu mai multe secvențe de input,
  inclusiv: parcurgerea până la finalul „Salvare”, comanda `inv` (inventar
  gol / cu obiecte), blocarea unei alegeri quand lipsește obiectul necesar
  și comanda `quit`.

**Modificări făcute manual după generare:**
- _(completați aici orice modificare pe care ați făcut-o voi manual: nume
  de variabile, conținutul poveștii, textul scenelor, obiecte noi etc.)_

## Prompt 2

**Prompt folosit:**
> _(adăugați aici următorul prompt folosit, de exemplu pentru a extinde
> povestea, a repara o eroare de compilare, a adăuga un nou tip de obiect,
> a schimba genul jocului etc.)_

**Rezultat obținut / eroare fixată:**
> _(descrieți ce a rezolvat sau ce a schimbat răspunsul LLM-ului)_

---

> **Notă:** adăugați o nouă secțiune „Prompt N” de fiecare dată când
> folosiți un LLM pentru a modifica proiectul, împreună cu o scurtă
> descriere a rezultatului obținut sau a erorii corectate.
