PROMPT: salut, primesc eroare in cmake ca nu gaseste un fisier sursa, cum adaug corect in cmakelists?

RASPUNS: Deschide CMakeLists.txt și adaugă numele fișierului lipsă în interiorul funcției add_executable, apoi șterge folderul build și rulează din nou comanda cmake ...

PROMPT: de ce imi da eroare git push rejected cand dau upload pe github?

RASPUNS: Această eroare apare când versiunea de pe server este mai nouă sau diferită de a ta. Rulează git pull origin <nume-ramura> --rebase pentru a sincroniza modificările, sau folosește --force dacă vrei să suprascrii direct.