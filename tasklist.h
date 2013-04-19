/*
 * tasklist.h
 *
 *  Created on: 2013-4-17
 *      Author: zhoufrederic
 */

#ifndef TASKLIST_H_
#define TASKLIST_H_

/* STRUCT _task
*
* This structure identifies a single task in a task list.
*/
typedef struct _task{
	char *task_name;
	int priority; // higher numbers have higher priority
	char date_entered[11];
	char date_completed[11]; // not used yet
} task;


/* STRUCT _tasklist
*
* This structure defines a generic task list that stores
* an array of active tasks. The task list also maintains
* a count of the occupied entries and the overall size
* of the array.
*/
typedef struct _tasklist{

	task **task_array; // an array of task pointers
	int occupied_count;
	int array_size;
} tasklist;


// forward declarations
task *makeTask(char *name, char *date, char *priority);
tasklist *createAndInitialize();
void addTaskToEnd(tasklist *, task *);
task *removeTask(tasklist *, int);
void printTaskList(tasklist *);


#endif /* TASKLIST_H_ */
