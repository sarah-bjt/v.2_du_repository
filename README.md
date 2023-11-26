# S1 | Prog: Workshop c++
## Beaujault Sarah & Jan Agathe

---

### Exercice 1 : Ne garder que le vert
![image](./images/logo.png) ![image](./output/ex01onlyGreen.png)

---
### Exercice 2 : Échanger les canaux
![image](./images/logo.png) ![image](./output/ex02blueAndRedReverse.png)

---
### Exercice 3 : Noir et blanc
![image](./images/logo.png) ![image](./output/ex03blackAndWhite.png)

---

### Exercice 4 : Négatif
![image](./images/logo.png) ![image](./output/ex04inverteColor.png)

---
### Exercice 5 : Dégradé
**Fonctionnement**
On part d'une image totalement noir, puis on éclairci chaque pixel en fonction de leurs colonnes.

![image](./output/ex05degrader.png)
---

### Exercice 6 : Miroir
**Fonctionnement**
On prend une copie de l'image, puis on repositionne chaque pixel sur cette copie de sorte à inverser l'image. Pour cela, on modifie la position de x avec la formule suivante : `image2.width() - 1.f - x`

![image](./images/logo.png) ![image](./output/ex06miroir.png)

**Problème rencontré**
Au tout départ, je n'avais pas effectué de copie de l'image et modifiait directement l'image de base, ce qui avait pour effet de n'inverser qu'une moitié de l'image.

---
### Exercice 7 : Image Bruité
####Version de Sarah 
**Fonctionnement**
Pour chaque pixels qui compose l'image, on determine aléatoirement si ce pixel est bruité ou non. Si oui on l'associe à une couleur choisie elle aussi aléatoirement.

![image](./images/logo.png) ![image](./output/ex07imageBruit.png)

**Problème rencontré**

Dans la première version du code, je déterminais si un pixel été bruité ou non avec cette partie du code : 
`int isPixelBruit {random_int(0, 4)};
if (isPixelBruit = 1)`
Cependant avec cette formule il est impossible de de choisir une fréquence de bruit telle que 1/28 par exemple. 
Le code final contient ces ligne qui permettent de pouvoir choisir avec beaucoup plus de précision le taux de bruit sur l'image final 
`float rand{random_float(0.f, 1.f)};
        if (rand < 0.28f)`


####Version d'Agathe
**Fonctionnement**
On choisit le nombre de bruit que l'on veut créer et l'on effectue une boucle pour rajouter chaque point du bruit un par un. Au sein de la boucle, on choisit un pixel au hasard et on attribue une couleur au hasard à chacune composantes (verte, bleue et jaune) avec un `random_float(0,1)`

![image](./images/logo.png) ![image](./output/ex07bruite.png)

---
### Exercice 9 : RGB Split S
**Fonctionnement**
La fonction crée une copie de l'image d'origine, puis sépare les composantes rouge, bleue et verte de l'image d'origine pour les placer respectivement du côté droit, gauche et au centre de l'image copiée. La espacement entre les couleurs est choisit en argument.

![image](./images/logo.png) ![image](./output/ex09RGBsplit.png)

**Remarque**

Si chaque couleurs sont espacé de 1/5 de la taille de l'image d'origine alors le résultat ressemble à un effet arlequin 

![image](./output/ex09RGBsplit_version_arlequin.png)


---
### Exercice 10 : Luminosité S

La fonction ajuste la luminosité de chaque pixel en élevant chaque composante de couleur à la puissance 0.6. Cela a pour effet de réduire l'intensité lumineuse globale de l'image.

![image](./images/photo.jpg) ![image](./output/ex10luminosite.png)
---
### Exercice 11 : Disque S
![image](./output/ex11disque.png)
---
### Exercice 12 : Cercle S
![image](./output/ex12cercle.png)
---
### Exercice 13 : Rosace S
**Fonctionnement**

Les coordonnées du centre et le rayon du cercle central sont définis, puis une boucle génère les coordonnées des cercles périphériques en fonction du nombre de cercles spécifié (nb_circles). Ces coordonnées sont calculées en utilisant les fonctions trigonométriques cos et sin pour répartir les cercles uniformément autour du cercle central. Chaque cercle est ensuite dessiné à l'aide de la fonction dessineCercle.

![image](./output/ex13rosace.png)

### Exercice 14 : Mosaïque
**Fonctionnement**
On créé d'abord une image 5 fois plus grande que l'image d'origine, puis on parcours chaque pixel de cette nouvelle image. Dès que l'on a copié un logo en entier, on en copie un deuxième à côté et ainsi de suite jusqu'à ce que l'image soit entièrement remplis. Pour ce faire, on utilise une double boucle :
```cpp
for (int i{0}; i < 5; ++i)
            {
            for (int j{0}; j < 5; ++j)
                {
                    image2.pixel(x+i*image.width(), y+j*image.height()) = image.pixel(x, y);
                }
            }
```

![image](./images/logo.png) ![image](./output/ex14mosaique2.png)

**Problème rencontré**
Lors de ma première version de la fonction, j'ai utilisé une formule qui ne prenait pas en compte tout les pixels de l'image et donc ne copiait pas tout les pixels correctement :
```cpp
for (int i{0}; i < 5; ++i)
            {
                for(int j{0}; j < 5; ++j)
                {
                    logo2.pixel(x*i, y*j) = logo.pixel(x, y);
                }
            }
```

![image](./output/ex14mosaique.png)

### Exercice 15 : Mosaïque miroir
**Fonctionnement**
Comme pour la mosaïque, on créé d'abord une image 5 fois plus grande que l'image d'origine, puis on parcourt chaque pixel de cette nouvelle image. On établi deux variables : `int NewX {x%image.width()}` et `int NewY {y%image.height()}` qui nous permettent de revenir au début du logo dès que l'on a finit de le copier. Enfin, une fois sur deux, on modifie ces variables pour qu'elles recopient le logo à l'envers : `NewX = {image.width() - 1 - NewX}` et `NewY = {image.height() - 1 - NewY}`

![image](./images/logo.png) ![image](./output/ex15MosaiqueMiroir.png)

### Exercice 16 : Glitch S
**Fonctionnement**

La fonction crée une version glitchée d'une image en remplaçant des portions aléatoires de l'image par des segments provenant d'autres parties de l'image. Le nombre de glitches et les paramètres spécifiques de chaque glitch (position, longueur, largeur) sont déterminés de manière aléatoire.

![image](./images/logo.png) ![image](./output/ex16glitch.png)

---
### Exercice 17 : Tramage
**Fonctionnement**
On prend une image que l'on passe en noir et blanc, puis on initialise une matrice de Bayer.
```cpp
float bayer_matrix_4x4[][bayer_n] = { 
        { -0.5, 0, -0.375, 0.125 }, 
        { 0.25, -0.25, 0.375, - 0.125 }, 
        { -0.3125, 0.1875, -0.4375, 0.0625 }, 
        { 0.4375, -0.625 , 0.3125, -0.1875 } };
```
On calcule ensuite la couleur de sortie des pixels en fonction de leurs couleurs d'origine et des valeurs de la matrice :
```cpp
float orig_color = image.pixel(x, y).r;
float bayer_value = bayer_matrix_4x4[y % bayer_n][x % bayer_n]; 
float output_color = orig_color + (1 * bayer_value);
```
Enfin, si la couleur de sortie est inférieur à 0.5, le pixel deviendra noir, sinon il deviendra blanc.

![image](./images/photo.jpg) ![image](./output/ex17Tramage.png)
---
### Exercice 18 : Vortex S
![image](./images/logo.png)  ![image](./output/ex18vortex.png)

**Problème rencontré**

Dans ma première version du programme, j'ai attribué aux pixel de l'image d'origine aux pixels de l'image final avec pour coordonné les points après rotation. Or en faisant cette méthode nous nous retrouvons avec certains pixels noirs alors qu'ils devraient être coloré, cela est dû au fait qu'après rotation, certains pixels se retrouvent entre deux pixels de l'image d'origine.
`imageVortex.pixel(nouveau_point.x, nouveau_point.y) = image.pixel(x,y);`
Résultat :

![image](./output/ex18vortex_version_ptNoir.png)

Il faut donc atribuer aux pixels de l'image final, la couleur des pixels d'origine après rotation
`imageVortex.pixel(x,y) = image.pixel(nouveau_point.x, nouveau_point.y);`

---
### Exercice 19 : Normalisation de l'Histogramme S

![image](./images/photo_faible_contraste.jpg) ![image](./output/ex19normalisationHistogramme.png)

**Problème rencontré**

Ma première version du programme se trouvait être fausse car je m'étais tromper dans la formule à utilisé cependant l'image enregistrée avait bien une plus grande profondeur de couleur. 
Formule utilisé :
`color = color * (1/hight_brightness) - low_brightness;`
Résultat :
![image](./output/ex19normalisationHistogramme_version.1.png)

---
### Exercice 20 : Convolution
**Fonctionnement**
On parcours chaque pixel de l'image avec un kernel, et on effectue la moyenne de ce pixel et de ceux qui l'entourent, puis on modifie la couleur du pixel par cette moyenne. Si un pixel est un bord de l'image, alors il sera automatiquement noir.

![image](./images/logo.png) ![image](./output/ex20Convolutions.png)

**Remarque**
Le flou ici est très léger mais pourrait être augmenté avec un plus gros kernel.

---
### Exercice 21 : Fractale S
![image](./output/ex21fractale.png)

**Problème rencontré**

La première fois que j'ai essayé de faire tourner le programme je n'ai pas réussie car j'ai oublié de mettre le `static_cast<float>`

---


### Exercice 22 : Emboss
**Fonctionnement**
Même principe que la convolution, mais avec des coefficients différents dans la matrice.
```cpp
float kernel[3][3] = {{ -2.f, -1.f, 0.f }, 
                      { -1.f, 1.f, 1.f }, 
                      { 0.f, 1.f, 2.f }};
```

![image](./images/logo.png) ![image](./output/ex22Emboss.png)

### Exercice 23 : Outline
**Fonctionnement**
Même principe que la convolution, mais avec des coefficients différents dans la matrice.
```cpp
float kernel[3][3] = {{ -1.f, -1.f, -1.f }, 
                          { -1.f, 8.f, -1.f }, 
                          { -1.f, -1.f, -1.f }};
```

![image](./images/logo.png) ![image](./output/ex23Outline.png)

### Exercice 24 : Sharpen
**Fonctionnement**
Même principe que la convolution, mais avec des coefficients différents dans la matrice.
```cpp
float kernel[3][3] = {{ 0.f, -1.f, 0.f }, 
                      { -1.f, 5.f, -1.f }, 
                      { 0.f, -1.f, 0.f }};
```

![image](./images/logo.png) ![image](./output/ex24Sharpen.png)


*Italique*

**Gras**

[lien](https://github.com/dsmtE/Learn--cpp_programming)

![image](./output/pouet.png)

#### Titre (plus ou moins gros en fonction du nombre de #)

- Listes
- avec
- plusieurs items

```cpp
// Bloc de code C++
int x{0};
std::cout << "x vaut " << x << '\n';
```

Bout de code `int x{0};` au milieu d'une phrase.

Équations de math avec LaTeX :
$$
\int_{-\inf{}}^{+\inf{}} x^2 dx
$$

Notes de bas de page [^1]

[^1]: Je suis une note de bas de page !

> Citation

| Tableaux      | 😁        | ✨  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |

Séparateur :

---