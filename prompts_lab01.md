# Registru Prompturi LLM - Laboratorul 1

Acest fișier documentează interacțiunea cu asistentul AI pentru structurarea proiectului și rezolvarea problemelor întâmpinate în Git.

---

## 1. Generarea structurii inițiale pentru HPP-uri

**Prompt:**
> Salut! Am ales proiectul Story Tale (text adventure) în C++ și l-am creat ca aplicație de consolă în Visual Studio. Îmi poți genera doar fișierele HPP necesare (Engine.hpp, Renderer.hpp, Listener.hpp) cu `#pragma once` și structurile de date de bază pentru un joc bazat pe text? Nu am nevoie de implementare CPP încă.

**Rezultat:**
AI-ul a generat fișierele de antet cu structurile `Choice` și `StoryNode`, alături de clasele principale `Engine`, `Renderer` și `Listener`.

---

## 2. Ajustare structură date și remediere bug compilare

**Prompt:**
> Am adăugat codul în Visual Studio, dar am o eroare la vectorul de decizii în `StoryNode`. Îmi dă `unknown type name 'Choice'` când declar `std::vector<Choice>`. Cum rezolv asta?

**Fix / Soluție:**
Eroarea a fost cauzată de ordinea declarării structurilor. AI-ul mi-a sugerat mutarea definitiei `struct Choice` înaintea structurii `StoryNode` în `Engine.hpp`.

---

## 3. Generarea fișierului README.md

**Prompt:**
> Poți să-mi faci conținutul pentru fișierul `README.md` conform cerințelor din laborator? Să includă descrierea jocului, regulile și explicația structurilor de date pe care le-am definit mai sus.

**Rezultat:**
A fost generat `README.md` formatat corespunzător în Markdown cu toate secțiunile obligatorii.

---

## 4. Ajutor cu comenzile Git (Curățare și Push)

**Prompt:**
> Am deja un repozitoriu vechi pe GitHub cu alte teste. Vreau să șterg tot ce e pe GitHub și să fac push la proiectul acesta nou peste el. Ce comenzi de Git Bash trebuie să rulez ca să fac force push de pe calculator?

**Rezultat / Soluție:**
A fost furnizată secvența de comenzi Git:
1. `git init` și redenumirea pe branch-ul `main`.
2. Legarea remote-ului prin `git remote add origin`.
3. Adăugarea fișierelor și commit-ul inițial.
4. `git push -u origin main --force` pentru suprascrierea istoricului vechi de pe GitHub.