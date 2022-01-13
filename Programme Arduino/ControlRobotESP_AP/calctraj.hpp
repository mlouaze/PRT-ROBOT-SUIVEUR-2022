#ifndef CALCTRAJ_HPP_
#define CALCTRAJ_HPP_

#define RAYON_ROUE (0.030f) //rayon de la roue en m
#define ECART_ROUE (0.0865f) //distance entre la roue et le milieu du robot
#define DISTANCE_MIN (0.1f) //distance minimale en mètre à partir de laquelle on considere qu'on a atteint un point

#include <math.h>
#include <Arduino.h>

class calctraj
{
  public:
  
  int NbrPoints; //contient le nombre de points de passages souhaité
  int PointActuel; //contient le numéro du dernier point rentré
  int PointCible;//contient le numéro du point ciblé
  float *PosX; //tableau contenant les coordonnées en X des points de passages
  float *PosY; //idem pour les Y
  float VitComm; //contient la vitesse moyenne de commande sur le parcours
  float AngleInit; //contient l'angle initial du robot avec l'axe des x

  bool TabPosRempli; //indique si on a bien recu tous les points
  bool TrajOK; //indique que la trajectoire est bien calculée et qu'on est pret à partir
  bool TrajEffectuee; //indique qu'on a fini la traj

  bool Repeat; //indique si on doit repeter le circuit a sa fin

  calctraj();

  void clear();
  void ConfCalcTraj(const int &nb, const bool &rep);
  void AjouterPoint(const float &Px,const float &Py);
  bool InitCalcTraj(const float &vit, const float &angle);//permet de terminer la configuration en ajoutant les derniers paramètres retourne true si tout est ok et qu'on est pret à partir

  void RecupCommandes(float &CommVitesse, float &CommAngle, const float &Px, const float &Py, const float &Alpha);
  
  
};







#endif 
