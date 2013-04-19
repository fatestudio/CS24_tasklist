/*
MAIN.C

Implements the main() method of this exercise and initiates function
calls to all task list methods
*/

#include <stdio.h>
#include <stdlib.h>
#include "tasklist.h"


int main(int argc[], char *argv[])
{
	tasklist *pTaskList = createAndInitialize();
	task *pTask;

	int insert_count = 0;
	int delete_count = 0;
	int task_count = 0;
	char buf1[100],buf2[50],buf3[20];

	// just to force you to make it bigger....
	if (pTaskList->array_size > 3)
           pTaskList->array_size = 3;


	//Creating the task object and inserting it in the task list
	for(insert_count = 0;insert_count < 5;insert_count++)
	{
		printf("\n Enter the task name: ");
		fgets(buf1,100,stdin);
		printf("\n Enter the priority: ");
		fgets(buf3,20,stdin);
		printf("\n Enter today's date (DD/MM/YYYY): ");
		fgets(buf2,20,stdin);

		pTask = makeTask(buf1,buf2,buf3);
		addTaskToEnd(pTaskList,pTask);
		printTaskList(pTaskList);
	}


	//Looking up the corresponding task and deleting it from the task list
	for(delete_count = 0;delete_count < 5; delete_count++)
	{
		int taskNum;
		printf("\n\n Enter the number of the task you wish to delete: ");
		printTaskList(pTaskList);
		fgets(buf3,20,stdin);
		taskNum = atoi(buf3);

		pTask = removeTask(pTaskList,taskNum);

		if (pTask == NULL)
			printf("NULL\n");
		else
			printf("%s, %d, %s\n",pTask->task_name,
				pTask->priority, pTask->date_entered);

		free(pTask);
	}
	printf("Task list at the end:\n");
	printTaskList(pTaskList);

}
