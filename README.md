42sh
===================

Ce dépôt contient les sources du 42sh de mon groupe pour le module Système Unix de 1ere année à Epitech.
Il a été réalisé à Strasbourg en 2014.

----------

Fonctionnalités
-------------

> - Gestion de la ligne d'exécution avec un parsing qui gère notamment les "double-quotes"
> - Pipes et multi-pipes
> - Redirections (simples et doubles, gauches et droites)
> - Séparateurs && et ||
> - Commandes "buit-in" : env, cd, echo, exit, alias, unalias, history, set, unset
> - Globing : *, [], ?
> - Variables locales et d'environnement
> - Gestion des alias
> - Edition de ligne avec utilisation des termcaps
> - Autocomplétion
> - Prompt élaboré
> - etc...

![Visuel du 42sh](http://antoine.buchser.fr/uploads/projects/thumbnails/42sh.jpg)

Problèmes connus
-------------

> - Le built-in "echo" renvoie 1 au lieu de 0 et inversement
> - La gestion des && et || n'est pas tout à fait complète, certains cas complexes ne sont pas gérés correctement

Disclaimer
-------------

Si vous êtes étudiant à Epitech, servez vous des concepts utilisés, pas du code, ou la moulinette de triche vous trouvera et vous mettra un -42.