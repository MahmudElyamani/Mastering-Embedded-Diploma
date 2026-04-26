/*
 * Platform_Types.h
 *
 *  Created on: Feb 22, 2026
 *      Author: Mahmoud Elyamani
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_



#include<stdbool.h>
#include<stdint.h>

#ifndef _Bool
#define _Bool
#endif

#define CPU_TYPE 			CPU_TYPE_32
#define CPU_BIT_ORDER 		MSB_FIRST
#define CPU_BYTE_ORDER		HIGH_BYTE_FIRST


#ifndef FALSE
#define FALSE				(bolean)false
#endif

#ifndef TRUE
#define TRUE				(bolean)true
#endif

typedef _Bool				boolean;
typedef int8_t				sint8;
typedef uint8_t				uint8;
typedef char				char_t;
typedef int16_t				sint16_t;
typedef uint16_t			uint16_t;
typedef int32_t				sint32_t;
typedef uint32_t			uint32_t;
typedef int64_t				int64_t;
typedef uint64_t			uint64_t;



typedef volatile int8_t		vint8_t;
typedef volatile uint8_t	vuint8_t;
typedef volatile int8_t		vint8_t;
typedef volatile uint8_t	vuint8_t;
typedef volatile int32_t	vint32_t;
typedef volatile uint32_t	vuint32_t;
typedef volatile int64_t	vint64_t;
typedef volatile uint64_t	vuint64_t;



#endif /* PLATFORM_TYPES_H_ */
