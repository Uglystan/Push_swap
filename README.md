# Push_Swap

## Objectif
Le but de ce projet est de trier des données en utilisant des piles avec un nombre d'instructions limité, en moins de coups possibles. Il faut sélectionner les algorithmes les plus appropriés. À la fin, on doit avoir toutes les valeurs triées dans l'ordre croissant dans la pile_A.

## Règles
On dispose d'un set de valeurs (int), de 2 stacks (pile_A et pile_B). La pile_A est de base remplie avec le set de valeurs non triées et d'un set d'instructions qui vont nous permettre de modifier les 2 piles. POur passer un nombre de la pile_A a la pile_B est inversement il faut que le nombre soit au sommet de la pile. Les barèmes sont les suivants :

| Taille du set de valeurs | Nombre max d'opérations pour que tout soit trié dans la pile_A |
|----------|-------------|
| 3       | 3 |
| 5       | 12 |
| 100       | 700 |
| 500       | 5500 |

## Instructions
| Commande | Description |
|----------|-------------|
| sa       | Swap: Échange les deux premiers éléments en haut de la pile a. Ne fait rien s'il y a un seul élément ou aucun. |
| sb       | Swap: Échange les deux premiers éléments en haut de la pile b. Ne fait rien s'il y a un seul élément ou aucun. |
| ss       | sa et sb simultanément. |
| pa       | Push: Prend le premier élément en haut de la pile b et le place en haut de la pile a. Ne fait rien si b est vide. |
| pb       | Push: Prend le premier élément en haut de la pile a et le place en haut de la pile b. Ne fait rien si a est vide. |
| ra       | Rotate: Décale vers le haut tous les éléments de la pile a de 1. Le premier élément devient le dernier. |
| rb       | Rotate: Décale vers le haut tous les éléments de la pile b de 1. Le premier élément devient le dernier. |
| rr       | ra et rb simultanément. |
| rra      | Reverse Rotate: Décale vers le bas tous les éléments de la pile a de 1. Le dernier élément devient le premier. |
| rrb      | Reverse Rotate: Décale vers le bas tous les éléments de la pile b de 1. Le dernier élément devient le premier. |
| rrr      | rra et rrb simultanément. |


## Solution
Pour résoudre ce problème, j'ai découpé en plusieurs parties en fonction de la taille du set.

### Set de 1 a 3
Pour une taille de 3, j'ai chaque cas en dur.

### Set de 4 a 5
Pour une taille de 5, je déplace les 2 plus petits dans la pile_B et ensuite j'utilise mon tri pour 3 valeurs et si nécessaire j'inverse dans la pile_B les 2 valeurs avant de les remettre.

- référence

### Set de 6 a 500

#### Etape 1 (100 valeurs par exemple) :

Je met en place des indices sur les valeurs et ensuite je travail uniquement avec les indices je met dans la pile_B les 28 plus petits nombres. J'analyse ma pile_A pour savoir si il est plus judicieux pour avoir un nombre de faire rra ou ra. Dans ses 28 je met les 14 plus petits en dessous des 14 plus grand a chaque fois que je dois changer la position d'un nombre dans la pile_B je verifie dans ma pile_A si je vais devoir faire la meme action aucquels cas j'utilise les actions rr ou rrr. Je fais ca jusqu'a avoir 3 nombres dans ma pile_A

![Screenshot from 2024-03-26 17-23-51](https://github.com/Uglystan/Push_swap/assets/117684814/19125a29-a099-4466-8dda-e4d2dbc6f83d)

#### Etape 2 :
Ensuite je vais remettre les nombre dans la pile_A. Donc je vais chercher le nom qui va juste au dessus de ma pile pour qu'elle soit directement triee. Je regarde si le moyen le plus efficace d'y arriver entre rb ou rrb et pendant que je defile sur chaque nombre qui passe en haut de ma pile_B je regarde si il est plus petit que le nombre que je cherche si c'est le cas je le bascule dans la pile_A et je le met en dessous de la pile si le contexte le permet. Je fais ca pour chaque nombre qui va passer en haut de la pile_B tant que je n'ai pas atteint le nombre que je recherchais. (A partir du moment ou il y'a un nombre en dessous de la pile_A je ne place plus que des nombres plus grand que le dernier nombre a la fin de la pile_A)

![Screenshot from 2024-03-26 18-21-04](https://github.com/Uglystan/Push_swap/assets/117684814/9409c0d5-4405-4d23-adf0-dd8b861c55c6)
