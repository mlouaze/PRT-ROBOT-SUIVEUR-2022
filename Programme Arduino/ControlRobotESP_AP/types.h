/*
 * types.h
*
 *  Created on: 11 sept. 2016
 *  Last Modification: 27 fev. 2017
 *      Author: Florian Bianco (florian.bianco@univ-lyon1.fr)
 *              Romain Delpoux (romain.delpoux@insa-lyon.fr)
 */
 
#ifndef TYPES_H_
#define TYPES_H_



typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

enum {
	STATE_ERROR = -1,
	STATE_INIT  = 0,
	STATE_OK,
	STATE_RUN,
	STATE_STOP,
};

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
  MODE_SENDINFO
};

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
    Y_POS
};

#endif /* TYPES_H_ */
