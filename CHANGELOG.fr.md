# Notes de version

Ces notes couvrent les changements de l'extension Zed depuis la version 0.52.0.
Les versions antérieures restent consultables dans l'historique Git.

## [0.53.0] - 2026-10-06

### Ajouts

- Reconnaissance des déclarations de surcharge d'opérateurs `+`, `-`, `*` et
  `/`, avec coloration du mot-clé `operator` et du symbole.
- Reconnaissance des motifs entiers, booléens et chaînes dans les `match`, y
  compris les entiers négatifs.
- Reconnaissance des `match` conditionnels sans sujet et des instructions
  `yield`, avec coloration de `yield`.

### Corrections

- Reconnaissance de `move` comme nom de méthode, y compris dans les appels
  ordinaires, optionnels et en cascade, sans perdre l'expression de transfert
  `move`.
- Alignement de la grammaire embarquée avec les requêtes de coloration de
  l'extension.

### Installation

- Le README présente désormais le catalogue Zed comme méthode principale et
  conserve l'installation de développement.
- Aucune migration de configuration n'est nécessaire. Le compilateur et le
  serveur de langage restent fournis séparément par la commande `silex`.
