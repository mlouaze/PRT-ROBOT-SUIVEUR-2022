# Le dossier "Rendu PRT" contient les sous dossiers et fichiers suivants :

* Simulations Matlab
* Programme Arduino
* Programme Commande à distance
* Rapport et présentation

*Voici leurs contenus en détail*

----

**Simulation Matlab**

* Fichier de configuration : fichierconfig.m, il permet de calculer les paramètres des correcteurs de vitesse,angle et suivi de points
* Fichier de regulation en vitesse : regulation_vitesse.slx, permet de simuler l'asservissement/regulation en vitesse des moteurs
* Fichier de régulation en angle : regulation_angle.slx, permet de simuler l'asservissement/régulation en angle et vitesse des moteurs
* Fichier de suivi de points : suivi_points.slx, permet de simuler le suivi d'une trajectoire en visant un point donné.

----

**Programme Arduino :**

* Fichier ControlRobotESP_AP.ino qui contient le programme principal du robot
* Fichiers Calctraj.cpp et Calctraj.hpp qui contiennent la classe permettant le suivi de trajectoire
* Fichiers ESP32Encoder.cpp et ESP32Encoder.h qui contiennent la classe permettant la gestion des encodeurs des deux moteurs
* Fichiers frame.cpp et frame.hpp qui contiennent la classe de gestion des messages entrant et sortant
* Fichiers moteur.cpp et moteur.hpp qui contiennent la classe de gestion des deux moteurs 
* Fichier types.h qui contient la redefinition de plusieurs types
	
Pour être compilé et envoyé sur le robot, on doit installer les librairies ESP32 (cf [(https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/))

----

**Programme Commande à distance**

Pour compiler et être lancé, le programme de commande à distance nécessite l'installation du module QtCharts Module (cf pour windows : [(https://stackoverflow.com/questions/42867557/how-to-install-qtcharts-on-windows)](https://stackoverflow.com/questions/42867557/how-to-install-qtcharts-on-windows) et pour linux ```sudo apt install libqt5charts5-dev```)

* Fichier main.cpp, le main du programme
* Fichiers mainwindow.ui, mainwindow.cpp et mainwindow.hpp, la classe de l'affichage de la fenêtre
* Fichiers graphviewer.h et graphviewer.cpp, la classe des widgets de monitoring 
* Fichiers robotposviewer.cpp et robotposviewer.hpp, la classe du widget d'affichage de parcours/obstacles
* Fichiers wifimanager.cpp et wifimanager.hpp, la classe de gestion de la connexion entre PC et robot via wifi
* Fichier type.h définissant les entetes des frames de communication
* Fichiers remotecontrol.pro, configuration du compilateur


**Fonctionnement :**
1. Se connecter en Wifi au robot, SSID : "Roboutchou", mot de passe : "123456789"
1. Lancer le programme, on doit voir status connected (sinon ca signifie que le programme ne détecte pas la connexion au robot)
1. Appuyer sur le bouton Connect, on doit voir status connected & TCP, le programme envoie un requête de connexion TCP et établi sa connexion avec le robot
1. On a maintenant accès à toutes les fonctions du programme de controle à distance


*NB: La connexion en WiFi est assez aléatoire suivant le PC et la plateforme, parfois le programme reconnaitra la connexion même après l'avoir lancé parfois pas. Le plus simple est de se connecter d'abord au robot en wifi puis de le lancer. En cas de redémarrage du robot, il est nécessaire de relancer le programme.*

----

**Rapport et présentation** 

* Présentation_PRT_6_bin_2.pptx, notre présentation PowerPoint utilisé pendant la soutenance
* Rapport_PRT_6_bin_2.pdf, notre compte rendu final du projet
* Video_Robot.mp4, vidéo du robot en fonctionnement
