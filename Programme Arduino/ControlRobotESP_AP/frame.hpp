/*
 * frame.hpp
*
 *  Created on: 11 sept. 2016
 *  Last Modification: 27 fev. 2017
 *      Author: Florian Bianco (florian.bianco@univ-lyon1.fr)
 *              Romain Delpoux (romain.delpoux@insa-lyon.fr)
 */

#ifndef FRAME_HPP_
#define FRAME_HPP_

#include <Arduino.h>
#include <WiFi.h>

#include "types.h"

#define MARKER 	0xFF
#define SIZE_TAB_DATA 		3

enum _FRAME_CMD {
	CMD_MODE_OFF=0xFF,
  CMD_MODE_SELDATA=0xAA,
  CMD_MODE_SENDTRACK=0xBB,
  CMD_MODE_PARAM = 0,
  CMD_MODE_STEP,
  CMD_MODE_CL,
  CMD_MODE_POINTFOLLOW,
  CMD_MODE_OBSTACLE,
  CMD_MODE_SENDDATA,
  CMD_MODE_SENDINFO,
};

struct DATA_FRAME {
	u8  Mark;
	u8 	Id;
	u8 	Cmd;
	s32 TabData[SIZE_TAB_DATA];
	u8 	CheckSum;
};
typedef struct DATA_FRAME Data_Frame;

class Frame {

private:
  WiFiClient * client;
	Data_Frame data;

	int size_frame;
public:

	Frame(WiFiClient * cli); 	//Ctor
	~Frame(); 	//Dtor

	void clear();

	void set_Id(u8 Id);
	void set_Cmd(u8 Cmd);
	void set_Data(s32 data, int pos);
	void set_Checksum(u8 checksum);

	/* Get Values */
	//u8  get_Mark();
	u8  get_Id();
	u8  get_Cmd();
	s32 get_data(int pos);
	u8  get_Checksum();

	/* Get address */
	//u8 *  p_get_Mark();
	u8 *  p_get_Id();
	u8 *  p_get_Cmd();
	s32 * p_get_data();
	u8 *  p_get_Checksum();

	/* Get sizes */
	int get_sizeFrame();

	int get_sizeMark();
	int get_sizeId();
	int get_sizeCmd();
	int get_sizeData();
	int get_sizeCheckSum();

	u8 calc_checksum();

	void set_checksum();
	bool verif_checksum();

	Data_Frame * create_data_frame();

	void send_frame();
	bool recev_frame();

	void print();

};

#endif /* FRAME_HPP_ */
