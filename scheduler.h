/*
 * scheduler.h
 *
 *  Created on: Feb 9, 2018
 *      Author: G&N&P&M
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


typedef struct {


	void(*pf)(void);
	int peridicty;
	int periority;

}OS_Type;

extern void Start_OS(void);



#endif /* SCHEDULER_H_ */
