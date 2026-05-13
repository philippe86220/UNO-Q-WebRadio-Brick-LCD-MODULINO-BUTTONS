![Arduino App Lab](https://img.shields.io/badge/Arduino%20App%20Lab-0.7.0-blue)
![Platform](https://img.shields.io/badge/macOS-26.3.1-lightgrey)
![Target](https://img.shields.io/badge/Board-UNO%20Q-green)
![Python](https://img.shields.io/badge/Python-3.x-yellow)
![Audio](https://img.shields.io/badge/Audio-ALSA%20%2F%20mpg123-red)
![Container](https://img.shields.io/badge/Container-Docker-orange)

# UNO-Q-WebRadio-Brick-LCD-MODULINO-BUTTONS

Version avec Modulino Buttons et écran LCD 20x4 de l'utilisation d'une WebRadio avec la brick personnalisée `AudioPlayer`.

## Principe de fonctionnement

- Côté MPU, dès que le système audio est prêt, Bridge transmet l'information au MCU.
- Sur le LCD 20x4 (3,3 V), à côté de `Radio :`, apparaît `OK`.
- L'application est alors opérationnelle.

Le MCU surveille ensuite les actions utilisateur via les boutons Modulino et transmet les commandes au MPU via Bridge. :

- **A** : change de station
- **B** : augmente le volume par incréments de 10 % (au-delà de 100 %, retour à 0 %)
- **C** : arrête la lecture audio

Après un arrêt, un nouvel appui sur **A** redémarre la lecture avec la dernière station sélectionnée.

## Architecture

- **MPU (Python / App Lab)** :
  - gestion du backend audio
  - lecture des flux WebRadio
  - gestion du volume
  - réception des commandes via Bridge

- **MCU (C++ / Arduino)** :
  - gestion des boutons Modulino
  - affichage sur LCD
  - interface utilisateur locale

Communication bidirectionnelle via **Bridge (MPU <-> MCU)**.

Ce code reste volontairement très simple afin de pouvoir être facilement adapté.

---

## Capture d'écran

![Aperçu](/docs/screenshot.jpg)

---

## Remerciements

Ce projet a été réalisé avec la collaboration de ChatGPT (OpenAI).
