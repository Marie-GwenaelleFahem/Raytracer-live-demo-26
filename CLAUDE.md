# Contexte du projet

## Qui je suis
- Étudiante en ingénierie logicielle. Je connais JavaScript et PHP (Laravel). Je débute en C++ et en ray tracing.
- Mon niveau d'anglais est B2 : tout ce qui est écrit en anglais dans ce dépôt (code, commentaires, documentation, messages de commit) doit rester simple et clair.
- Réponds-moi en français, mais écris le code et la documentation en anglais.

## Le projet
- Module de 3 semaines : construire un ray tracer en C++ pour un studio de cinéma de Los Angeles (scénario fictif situé en 2035).
- Le studio veut un ray tracer qu'il peut **comprendre, maintenir et faire évoluer pendant des années** : lisible, testé, documenté, ouvert aux contributions de studios partenaires, et assez rapide pour rendre un film entier.
- Organisation :
  - Semaine 1 : travail individuel, évalué seul.
  - Semaine 2 : travail en groupe sur le même dépôt, façon open source.
  - Semaine 3 : démo de groupe, puis dette technique, diagnostics et optimisation, en individuel.
- Le document de référence est `docs/discovery/discovery-report.md`. Lis-le avant de proposer une architecture ou une fonctionnalité.

## Ce que le client a dit (résumé)
- Film de 90 min, 1080p, 24 FPS, soit 129 600 images.
- 200 machines de production, CPU uniquement (pas de carte graphique), 2 mois pour le rendu final.
- Deux usages : un aperçu rapide pour les designers sur des machines de bureau puissantes, et une image finale de haute qualité.
- Pas d'interface utilisateur. Le ray tracer est une « black box » : des objets en entrée, une image en sortie. Il doit s'intégrer à Maya.
- Une anomalie dans une image doit pouvoir être diagnostiquée et corrigée le jour même. Le studio a eu des points noirs inexpliqués, dont la cause n'a jamais été trouvée.
- Le code doit rester maintenable quand quelqu'un quitte l'équipe. Les studios partenaires corrigeront des bugs et proposeront des changements.
- Le ray tracer doit être terminé le 5 janvier.
- Style visuel proche de Toy Story.
- Plusieurs points restent ouverts (temps max par image, format d'entrée, intégration exacte avec Maya) : voir la section « Open questions » du rapport. Ne les considère pas comme réglés.

## Comment je veux travailler avec toi
- **J'apprends.** Explique tes choix et les notions de C++ ou de rendu quand elles sont nouvelles. Compare avec JavaScript ou PHP quand ça aide.
- **Je relis tout ce que tu écris.** Propose des changements petits et faciles à relire, pas des gros blocs de code d'un coup. Le brief dit que le code généré par une IA doit être relu attentivement par un humain.
- **Ne réécris pas mes textes rédigés** (rapport, sections en anglais) sans que je le demande. Signale plutôt les erreurs.
- Demande-moi avant de choisir une bibliothèque externe, un format de fichier ou un standard C++.
- Si une demande va contre un besoin du client ou un principe ci-dessous, dis-le-moi.

## Principes d'ingénierie attendus
- C++ moderne : RAII, `std::unique_ptr`, conteneurs standard, pas de `new`/`delete` à la main, `const` partout où c'est possible.
- SOLID, DRY, programmation orientée objet. Des noms tirés du vocabulaire du domaine : `Scene`, `Camera`, `Ray`, `Material`, `Shape`, `Light`, `Image`.
- Le cœur du ray tracer ne dépend pas de Maya. L'intégration se fait dans une couche séparée.
- Tests pour chaque fonctionnalité. Avertissements du compilateur activés, au maximum.
- Documentation à jour dans `README.md` et `docs/`.
- Commits petits, avec des messages clairs en anglais.
