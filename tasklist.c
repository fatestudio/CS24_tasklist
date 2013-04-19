#include <stdio.h>
#include <stdlib.h>
#include "tasklist.h"
#include <string.h>

/* makeTask
 *
 * This function takes the parameters with the information for a task.
 * These parameters are stored in **temporary** strings.  Your job is
 * to create a new task and fill in the fields properly.  Return this
 * new task.  Make sure you think carefully about what malloc call(s)
 * you need to make.
 */

task *makeTask(char *name, char *date, char *priority)
{
  task *T = (task *)malloc(sizeof(task));
  char *pch = strtok(name, "\n");
  T->task_name = (char *)malloc(sizeof(char) * strlen(pch));
  strcpy(T->task_name, pch);
  T->priority = abs(atoi(priority));
  strcpy(T->date_entered, date);

  int k = 0;
  while (T->date_entered[k] != '\0')
    {
      if(T->date_entered[k] == '\n'){
	T->date_entered[k] = '\0';
	break;
	  }
      k++;
    }
  return T; // FILE THIS IN
}

/* createAndInitialize
*
* This function allocates space for a task list and initializes the task list
* to an initial state. Additionally, it returns the newly created task list
* structure to the caller.
*
* Initializing the task list involves assigning values to each of the attributes
* of the 'tasklist' structure. You would also have to allocate ,memory for the task
* array.
*/

tasklist *createAndInitialize()
{
  tasklist *tl = (tasklist *)malloc(sizeof(tasklist));
	tl->array_size = 4;
  tl->task_array = (task **)malloc(sizeof(task *) * 4);
  tl->occupied_count = 0;
	return tl;
}


/* addTaskToEnd
*
* This function takes two parameters - the task list and the task to be inserted.
* It attempts to append said task into an array of tasks maintained by the task
* list. When the array reaches its capacity, the function proceeds to re-allocate the
* array before carrying out the insertion operation.
*
* NOTE:
* The use of realloc() is NOT permitted in this exercise. You would have to figure out
* a way to perform the re-allocation using other memory allocation operations
*
* HINT: Think malloc() and memcpy()!
*/

void addTaskToEnd(tasklist *list,task *input_task)
{
	if(list->occupied_count >= list->array_size){
//		printf("\nThe number of occupied entries in the Task List is : %d\n", list->occupied_count + 1);
//		printf("The size of the Task List is greater than the occupied count\n");
		task **temp = (task **)malloc(sizeof(task *) * (list->array_size + 3));
		memcpy(temp, list->task_array, sizeof(task *) * list->array_size);
		free(list->task_array);
		list->task_array = temp;
		list->array_size = list->array_size + 3;
	}
  list->occupied_count += 1;
  list->task_array[list->occupied_count-1] = input_task;
}


/* removeTask
*
* This function takes two parameters - the task list and the index value associated with
* the task to be removed.
*
* The task to be removed can occur anywhere in the task array. You are required to write
* code that handles all possible cases.
*/


task *removeTask(tasklist *list, int task_index)
{
  int i;
  if(task_index >= list->occupied_count || task_index < 0){
	  return NULL;
  }

  task *remove = (task *)malloc(sizeof(task));
  memcpy(remove, list->task_array[task_index], sizeof(task));
  free(list->task_array[task_index]);

  for (i = task_index; i < list->occupied_count-1; i++)
    {
      list->task_array[i] = list->task_array[i+1];
    }
  list->occupied_count--;
	return remove;
}


/* printTaskList
*
* This function takes as input the task list and prints the contents of the list on the screen.
*/

void printTaskList(tasklist *list)
{
	int i = 0;

	if (list == NULL)
		printf("List is NULL\n");

	printf("\n The number of occupied entries in the Task List is : %d",
			list->occupied_count);

	printf("\n The entries in the Task List are:\n");
	for (i = 0;i < list->occupied_count; i++)
	{
		if (list->task_array[i] == NULL)
			printf("NULL\n");
		else
			printf("%d: %s, priority: %d.  Entered %s\n ", i,
				list->task_array[i]->task_name,
				list->task_array[i]->priority,
				list->task_array[i]->date_entered);
	}
}
