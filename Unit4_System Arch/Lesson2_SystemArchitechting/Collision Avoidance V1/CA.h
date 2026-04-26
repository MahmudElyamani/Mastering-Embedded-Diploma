//--- ✄ --------- 2026.04.15 09:32 -------------------
//Author: Eng. Mahmoud Elyamani
//Collision Avoidance library

#ifndef CA_H_
#define CA_H_
#include "state.h"
//state definition.
enum {
    CA_waiting,
    CA_driving
}CA_state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);

//STATE pointer to function
extern void *CA_state();

#endif  /*      CA.h*/