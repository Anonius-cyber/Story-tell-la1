# Story-tell-la1

Text Adventure (Story Tale) — laborator de programare orientat? pe obiecte.

## Descrierea proiectului

„Insula Uitat?” este un joc de tip **text adventure**: juc?torul controleaz?
un naufragiat care se treze?te pe o insul? necunoscut? ?i trebuie s?
exploreze, s? colecteze obiecte ?i s? ia decizii pentru a g?si o cale de
salvare (sau o comoar? ascuns?).

Jocul ruleaz? ?n consol?. La fiecare pas, juc?torul:
1. cite?te descrierea scenei curente;
2. alege una dintre op?iunile numerotate afi?ate, sau folose?te o comand?
   special?;
3. motorul de joc actualizeaz? starea (inventar, flag-uri, scena curent?)
   ?n func?ie de alegere.

### Reguli de joc / comenzi disponibile

| Comand?            | Efect                                             |
|--------------------|----------------------------------------------------|
| `1`, `2`, `3`, ...  | alege op?iunea corespunz?toare din scena curent?    |
| `inv`               | afi?eaz? inventarul curent                          |
| `help`              | afi?eaz? lista de comenzi                           |
| `quit`              | iese din joc                                        |

Unele alegeri necesit? un obiect anume din inventar (ex: o oglind? de
semnalizare pentru a chema o nav?), iar altele ofer? un obiect nou. Jocul
se termin? c?nd juc?torul ajunge ?ntr-o scen? de final — exist? mai multe
finaluri posibile (salvare, comoar? ascuns? etc.).

## Structuri de date ?i descrierea lor

Toate structurile de date de baz? sunt definite ?n `GameTypes.hpp`:

- **`Item`** — un obiect din poveste (`id`, `name`, `description`).
- **`Choice`** — o op?iune disponibil? ?ntr-o scen?: textul afi?at,
  scena spre care duce (`targetSceneId`), un obiect necesar op?ional
  (`requiredItemId`), un obiect oferit op?ional (`givesItemId`) ?i un
  flag boolean care poate fi setat (`setFlag`).
- **`Scene`** — un nod din graful pove?tii: `id`, `title`, `description`,
  lista de `Choice` disponibile ?i un indicator `isEnding` (dac? este
  o scen? final?).
- **`GameState`** — starea curent? a partidei: scena curent?
  (`currentSceneId`), inventarul juc?torului (`inventory`), flag-uri
  boolene pentru decizii/evenimente (`flags`), num?rul de ture jucate
  (`turnCount`) ?i dac? jocul mai ruleaz? (`isRunning`).

Povestea ?n sine este reprezentat? ca un **graf orientat**: fiecare `Scene`
este un nod, iar fiecare `Choice` este o muchie c?tre alt? scen?
(`targetSceneId`).

## Arhitectura codului

| Fi?ier             | Rol                                                                |
|---------------------|----------------------------------------------------------------------|
| `GameTypes.hpp`     | define?te structurile de date de baz? (`Item`, `Choice`, `Scene`, `GameState`) |
| `GameEngine.hpp`    | **motorul de joc**: de?ine povestea ?i starea, ruleaz? bucla principal? |
| `Renderer.hpp`      | **desenatorul**: afi?eaz? scenele, inventarul ?i mesajele ?n consol?  |
| `Listener.hpp`      | **ascult?torul**: cite?te ?i interpreteaz? input-ul juc?torului       |
| `main.cpp`          | punctul de intrare, porne?te `GameEngine`                             |

`GameEngine` folose?te `Renderer` pentru afi?are ?i `Listener` pentru a
citi alegerile juc?torului, dar `Renderer` ?i `Listener` nu ?tiu nimic
unul despre cel?lalt — comunic? doar prin `GameEngine`.

## Compilare ?i rulare

```bash
g++ -std=c++17 -Wall -o insula_uitata main.cpp
./insula_uitata
```

## Extindere

Povestea este momentan hardcodat? ?n `GameEngine::buildStory()`. Pentru
un laborator ulterior, aceasta poate fi mutat? ?ntr-un fi?ier extern
(JSON/text), f?r? s? fie nevoie de modificarea `Renderer`-ului sau a
`Listener`-ului.

## Autor

Proiect realizat ?n cadrul laboratorului de Programare Orientat? pe Obiecte.
