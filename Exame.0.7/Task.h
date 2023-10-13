
#include <iostream>
#include <cstring>


using namespace std;


struct Task 
{
    char title[100];
    int priority;
    char description[200];
    char date[9];
    char time[6];
};

void addTask(Task**& tasks, int& numTask, Task* newTask);
void getUserTaskInput(Task* task);
void getUserTaskInput(Task* task);

void deleteTaskLogic(Task**& tasks, int& numTask, int taskNumber);

void editTaskDetails(Task* taskToEdit);

void searchByName(Task** tasks, int numTask);
void searchByPriority(Task** tasks, int numTask);
void searchByDescription(Task** tasks, int numTask);
void searchByDate(Task** tasks, int numTask);

void displayTask(const Task& task);


void cleanupMemory(Task** tasks, int numTask, int maxTask);