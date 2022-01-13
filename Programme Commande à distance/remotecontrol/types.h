#ifndef TYPES_H
#define TYPES_H

enum {
  MODE_OFF=0xFF,
  MODE_SELDATA=0xAA,
  MODE_SENDTRACK=0xBB,
  MODE_PARAM = 0,
  MODE_STEP,
  MODE_CL,
  MODE_POINTFOLLOW,
  MODE_OBSTACLE,
  MODE_SENDDATA,
  MODE_SENDINFO,
};//setup the first bit of the communication for all communication mode

enum {
    RIGHT_POS=0,
    LEFT_POS,

    RIGHT_SPEED,
    LEFT_SPEED,

    MOTOR_SPEED,
    THETA_SPEED,

    ALPHA_SPEED,
    ALPHA_POS,

    X_SPEED,
    Y_SPEED,
    X_POS,
    Y_POS,
};

#endif // TYPES_H
