# Laboratoire Papers animés

Ces laboratoires sont une variante "animée" des papers. Les seules nouveautés étant :
- que chaque `colorize()` marque une pause juste après avoir colorié la case ;
- que le temps de pause à marquer entre chaque coloriage de case est spécifié dans le nouveau paramètre `delai_anim` de la fonction `init_paper()` ;
- que les dessins se font en niveaux de gris (de 0 (ou `black`) à 255 (ou `white`), en passant notamment par 127 (ou `grey`)) ;
- que l'on peut récupérer le niveau de gris de la case sous le "curseur" via `get_color()` qui retourne un entier entre 0 (ou `black`) et 255 (ou `white`) en passant notamment par 127 (ou `grey`).
- que la fonction `init_paper()` se voit ajouter un dernier nouveau paramètre, qui pour l'instant ne sera pas éxploité et devra être tout simplement mis à 0.

## Manipuler les papers animés.

Un `paper animé` est un quadrillage dans lequel on va pouvoir se déplacer et colorier des cases. Le "curseur" de coloriage se trouve initialement toujours dans le coin supérieur gauche et chaque coloriage est une étape de l'animation.

Les fonctions permettant de manipuler un `paper animé` :
- `init_paper(nb_lignes,nb_colonnes,taille,delai_anim,useStepping)` : Permet de créer un `paper` contenant `nb_lignes` lignes et `nb_colonnes` colonnes. `taille` est la dimension en pixel d'une case et `delai_anim` est le temps de pause (en seconde) entre chaque coloriages de cases. Ce délai peut-être décimal, par exemple 0.05 pour 5 centièmes de seconde. Le paramètre `useStepping` sera exploité plus tard, il devra être mis à 0 pour le moment.
- `move_left()` : déplace le "curseur" de coloriage d'une case à gauche.
- `move_right()` : déplace le "curseur" de coloriage d'une case à droite.
- `move_down()` : déplace le "curseur" de coloriage d'une case vers le bas.
- `move_up()`  : déplace le "curseur" de coloriage d'une case vers le haut.
- `get_color()` : retourne un entier entre 0 (ou `black`) et 255 (ou `white`) en passant notamment par 127 (ou `grey`). Ce nombre entier correspond au niveau de gris de la case sous le "curseur" de coloriage.
- `colorize()` : colorie la case où se trouve le "curseur" de coloriage. **Attention : on ne peut jamais colorier hors du `paper`**
- `change_color(greyLevel)` : permet de définir la couleur de coloriage en fixant le niveau de gris avec `greyLevel` entre 0 (ou `black`) et 255 (ou `white`) en passant notamment par 127 (ou `grey`).
- `display_paper()` : affiche le `paper animé`.

### Exemple

Voici un exemple qui re-colorie (9 fois) les cases noires en blanc et inversement. Ceci en dessinant des petits carrés (de côtés 2) tout en haut à gauche du paper animé :

@[Sample paper]({"stubs": ["main.c"],"command": "sh /project/target/run.sh", "project" : "paper"})
