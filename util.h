/*
 * util.h
 *
 *  Created on: Nov 15, 2017
 *      Author: G&N&P&M
 */

#ifndef UTIL_H_
#define UTIL_H_


#define set_bit(reg,pin) ((reg) |= (1 << (pin)))
#define clr_bit(reg,pin) ((reg) &= ~((1) << (pin)))


#define assain_bit(reg,pin,val) (reg ^= (-val ^ reg) & (1 << pin))
#define get_bit(reg,pin) ((reg>>pin)&1)

#define toggle_bit(reg,pin) (reg ^= (1<<pin))

#define clr_low_nibble(reg) (reg &= 0xf0)
#define set_low_nibble(reg) (reg |= 0x0f)

#define clr_high_nibble(reg) (reg &= 0x0f)
#define set_high_nibble(reg) (reg |= 0xf0)

#define rotate_left(reg,val) (reg=(reg<<val) | ((reg>>(8-val))))
#define rotate_right(reg,val) (reg=(reg>>val) | ((reg<<(8-val))))
 // de hna bt3tmd 3la ano ysfer el goz2 el tane mn el nIpple
#define Get_Nibble_High(reg)			(reg&(0b11110000))>>4
#define Get_Nibble_Low(reg)				 reg&(0b00001111)
// hna bysfer el goz2 ale 3awz y7ot fe el number ba3d kda tmlo OR m3 el goz2 el gded
#define Assign_Nibble_High(reg,value)      reg=(((reg&(0b00001111)))|(value*16))
#define Assign_Nibble_Low(reg,value)       reg=(((reg&(0b11110000)))|(value*16))


#endif /* UTIL_H_ */
