/*
 * Utils.h
 *
 * Created: 10/29/2026 10:49:31 AM
 *  Author: mah.elyamany
 */ 


#ifndef UTILS_H_
#define UTILS_H_

typedef unsigned char uint8_t;
typedef unsigned char *ptr_uint8_t;
typedef char* ptr_sint8_t;
typedef void(*PTR_VoidFunVoid_t)(void);\
typedef unsigned char E_STATUS_t;
#define E_ok			(E_STATUS_t)(0)
#define E_NotOk			(E_STATUS_t)(1)

#define NULL_PTR			((void*) (0))

#define SET_BIT(PORT, BIT)			(PORT |= (1<<BIT));
#define RESET_BIT(PORT, BIT)		(PORT &= ~(1<<BIT));
#define TOGGLE_BIT(PORT, BIT)		(PORT ^= (1<<BIT));
#define GET_BIT(PORT, BIT)			(PORT & (1<<BIT)>>BIT);



#endif /* UTILS_H_ */