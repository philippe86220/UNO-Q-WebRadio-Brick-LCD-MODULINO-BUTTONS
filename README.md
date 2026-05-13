![Arduino App Lab](https://img.shields.io/badge/Arduino%20App%20Lab-0.7.0-blue)
![Platform](https://img.shields.io/badge/macOS-26.3.1-lightgrey)
![Target](https://img.shields.io/badge/Board-UNO%20Q-green)
![Python](https://img.shields.io/badge/Python-3.x-yellow)
![Audio](https://img.shields.io/badge/Audio-ALSA%20%2F%20mpg123-red)
![Container](https://img.shields.io/badge/Container-Docker-orange)

# UNO-Q-WebRadio-Brick-LCD-MODULINO-BUTTONS

Version avec Modulino Buttons et LCD 20x04 de l'utilisation d'une WebRadio avec la brick personnalisée `AudioPlayer`.

## Principe de fonctionnement :

- Côté MPU dès que Le système audio est prêt, Bridge transmet l'information au MCU :
  - Sur le LCD 20x04 (3,3V) à côté de `Radio :` apparait `OK`  
  👉 l'application est opérationnelle 
  - MPU est en attente via Bridge d'un appui côté MCU sur les BP `A`, `B` ou `C` :
    - appui sur `A` : change de station
    - appui sur `B` : augmente le volume (il augmente par incrément de 10 et si > 100 repasse à 0) 
    - appui sur `C` : arrête le player audio, si on appui sur A il redemarre 

C'est un code trés basic que chacun pourra adapter à son bon vouloir.

---

## capture d'écran :

![aperçu](/docs/scrennshot.jpg)

---

## remerciements :

Ce projet a été réalisé avec la collaboration de ChatGPT (openAI)
