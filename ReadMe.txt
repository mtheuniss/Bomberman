Theunissen Mathilde
Wadoux Pierre

Nous avons implémenté un jeu de Bomberman en utilisant la bibliothèque sfml.
Nous n'avons pas utilisé une autre bibliothèque. Des tests unitaires ont également été réalisés avec Catch2.

Pour compiler notre programme : make puis ./main
Pour lancer les tests unitaires : make test puis ./tests_catch

Règle du jeu :
Lors du lancement du programme, les 2 joueurs choisissent leur personnage qui doivent être différents.
S’il n'y a qu'un seul joueur alors un robot remplace le deuxième joueur absent.
Dans notre programme, le robot n'est pas fonctionnel mais cela montre que notre jeu peut être compatible avec l'ajout d'un joueur automatique.
Une fois les deux joueurs sélectionnés, on appuie sur start pour commencer. Une deuxième fenêtre s'affiche.
Chaque joueur possède au départ 3 vies et 5 bombes. Ils peuvent faire les actions suivantes :
•	Se déplacer dans les zones sans mur (en vert) : le joueur 1 se déplace avec les flèches et le joueur 2 avec les touches qzsd.
•	Lancer une bombe : le joueur 1 en appuyant sur la barre espace et le joueur 2 en appuyant sur a.
Les bombes explosent au bout de 3 secondes. La zone de portée de l’explosion varie au cours du jeu.
Au départ, les dégâts sont dans un rayon de 2 cases. Les bombes détruisent les murs marrons et enlèvent une vie aux joueurs présents dans la zone d’explosion.
L’explosion ne traverse pas les murs de briques. Sous la plupart des murs marrons se trouvent des PowerUps choisis aléatoirement que les joueurs peuvent récupérés.
Les 4 types de PowerUps implémentés permet d’augmenter la zone de destruction de la bombe, la vitesse, le nombre de bombes ou de vies du joueur qui récupère le PowerUp.
Si le stock de bombes des deux joueurs est vide alors le programme leur rajoute des bombes pour que la partie puisse continuée.
La partie se termine lorsqu’un des deux joueurs n’a plus de vie.
Dans notre code, le type de PowerUp n’a aucune influence sur le reste du programme.
Ajouter un nouveau type de PowerUps est donc très simple : seule la méthode de choix aléatoire du powerup est à modifier.
Les bombes et PowerUp à afficher sont stockés dans des listes std::list pour permettre une suppression d'un élément en o(1) quelque soit sa position dans la liste.

Note : Le programme ne fonctionne pas sur l'ordinateur de Pierre : le programme se termine à cause d’une segmentation fault dès qu'une bombe explose. Nous n'avons pas compris d'où cela provenait.
L'erreur se situe au niveau de l'iteror dans la boucle for de la fonction updateGrille de la classe Plateau.

Nous avons travaillé en groupe en utilisant git et atom lorsque nous codions à deux. Nous avons la moitié du temps travaillé l’un après l’autre en se relayant ce qui fait nous avons tous les deux participé à chaque grande partie du programme.
Mathilde a dessiné les grandes lignes de l’interface graphique que Pierre a rendu compréhensible à l’utilisateur par l’ajout d’images et d’animation. Pierre a codé les tests unitaires et Mathilde les destructeurs.
Le reste du jeu a été codé par les deux membres de l’équipe.
L'uml relatif au projet ce trouve dans /Docx/UML_Projet_MathildePierre.
