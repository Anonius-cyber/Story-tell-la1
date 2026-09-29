# Story Tale (Text Adventure Game)

## Descrierea proiectului / reguli de joc
Acest proiect este un joc interactiv bazat pe text (Text Adventure) dezvoltat în C++.
Jucătorul explorează o poveste ramificată luând decizii la fiecare pas. Fiecare alegere influențează cursul poveștii și poate duce la finaluri diferite (succes, eșec sau deznodăminte alternative).

### Reguli de joc:
1. Citiți descrierea scenei curente.
2. Introduceți numărul corespunzător opțiunii dorite.
3. Progresați prin poveste până ajungeți la un final.

## Structuri de date și descrierea lor
* **Choice**: Reprezintă o opțiune de alegere, conținând textul opțiunii (`optionText`) și ID-ul scenei următoare (`nextNodeId`).
* **StoryNode**: Reprezintă un nod de poveste (o scenă) care conține un ID unic (`id`), textul descriptiv (`description`), o listă de alegeri posibile (`choices`) și un flag de final (`isEnding`).
* **Engine**: Clasa principală a motorului de joc, responsabilă pentru gestionarea graficului de scene/noduri, starea curentă și logica de tranziție.
* **Renderer**: Clasa responsabilă pentru afișarea textului în consolă și curățarea ecranului.
* **Listener**: Clasa ce preia și validează introducerea de date de la tastatură de către utilizator.