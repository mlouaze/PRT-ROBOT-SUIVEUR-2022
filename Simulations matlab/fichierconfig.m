Te=0.040; %%temps d'echantillonage moteur
r=0.030;%%rayon des deux roues
L=0.0865;%%moitié de la distance entre les roues

%%regulation en vitesse
G=3.754;
tau=0.09;%%temps de rep du moteur
T0=0.09;%%temps de rep voulu
lambdamot=exp(-Te/tau);
b1mot=G*(1-lambdamot);
a1mot=-lambdamot;
Kp=tau/(G*T0);
Ti=tau;
r0=Kp*(1+Te/Ti);
r1=-Kp;

paramPmoteur=r0;
paramImoteur=(r1+r0)/Te;


%%regulation en  angle
T0angle=0.4;%%0.4 semble OK
Gangle=2;
tauangle=0.09;
lambdaangle=exp(-Te/tauangle);
b1angle=Gangle*(1-lambdaangle);
a1angle=-lambdaangle;
Kpangle=tauangle/(Gangle*T0angle);
Tiangle=tauangle;
r0angle=Kpangle*(1+Te/Tiangle);
r1angle=-Kpangle;
paramPangle=r0angle;
paramIangle=(r1angle+r0angle)/Te;

%%regulation angulaire


T0angle = 4;
Gangle = 3.468e-1;
tauangle = 0.309/3;
b1angle = Gangle*(1-exp(-Te/tauangle));
a1angle= exp(-Te/tauangle);
Loangle = exp(-Te/T0angle);
r0angle = (1-Loangle)/b1angle;
r1angle = r0angle*a1angle;
paramPangle = r0angle;
paramIangle = (r1angle+r0angle)/Te;


%%suivi de points

alphainit=3.14/2;
Pxinit=0;
Pyinit=0;

Pxcible=+0.5;
Pycible=-0.5;
