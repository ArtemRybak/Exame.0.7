#include "Task.h"


void addTask(Task**& tasks, int& numTask, Task* newTask) {
    tasks[numTask] = newTask;
    ++numTask;
}



void getUserTaskInput(Task* task) {
    cout << "Enter title: ";
    cin.ignore();
    cin.getline(task->title, sizeof(task->title));
    cout << "Enter priority: ";
    cin >> task->priority;
    cout << "Enter description: ";
    cin.ignore();
    cin.getline(task->description, sizeof(task->description));
    cout << "Enter date: ";
    cin >> task->date;
    cout << "Enter time: ";
    cin >> task->time;
}

void deleteTaskLogic(Task**& tasks, int& numTask, int taskNumber) {
    if (taskNumber < 1 || taskNumber > numTask) {
        cout << "Invalid task number. Please enter a valid task number." << endl;
        return;
    }

    delete tasks[taskNumber - 1];

    for (int i = taskNumber - 1; i < numTask - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    numTask--;
    cout << "Task #" << taskNumber << " has been deleted." << endl;
}

void editTaskDetails(Task* taskToEdit) {
    cout << "Editing Task:" << endl;
    cout << "Enter task title: ";
    cin.ignore();
    cin.getline(taskToEdit->title, sizeof(taskToEdit->title));

    cout << "Enter task priority (1-10): ";
    cin >> taskToEdit->priority;

    cin.ignore();
    cout << "Enter task description: ";
    cin.getline(taskToEdit->description, sizeof(taskToEdit->description));

    cout << "Enter task date (dd.mm.yyyy): ";
    cin >> taskToEdit->date;

    cout << "Enter task time (hh:mm): ";
    cin >> taskToEdit->time;
}

void searchByName(Task** tasks, int numTask) {
    cout << "Enter task name to search: ";
    char searchTitle[100];
    cin.ignore();
    cin.getline(searchTitle, sizeof(searchTitle));

    bool found = false;
    for (int i = 0; i < numTask; i++) {
        if (strcmp(tasks[i]->title, searchTitle) == 0) {
            cout << "Found matching task:" << endl;
            displayTask(*(tasks[i]));
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks matching the name found." << endl;
    }
}

void searchByPriority(Task** tasks, int numTask) {
    cout << "Enter task priority to search (1-10): ";
    int searchPriority;
    cin >> searchPriority;

    bool found = false;
    for (int i = 0; i < numTask; i++) {
        if (tasks[i]->priority == searchPriority) {
            cout << "Found matching task:" << endl;
            displayTask(*(tasks[i]));
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks matching the priority found." << endl;
    }
}

void searchByDescription(Task** tasks, int numTask) {
    cout << "Enter task description to search: ";
    char searchDescription[200];
    cin.ignore();
    cin.getline(searchDescription, sizeof(searchDescription));

    bool found = false;
    for (int i = 0; i < numTask; i++) {
        if (strstr(tasks[i]->description, searchDescription) != nullptr) {
            cout << "Found matching task:" << endl;
            displayTask(*(tasks[i]));
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks matching the description found." << endl;
    }
}

void searchByDate(Task** tasks, int numTask) {
    cout << "Enter task date to search (dd.mm.yyyy): ";
    char searchDate[20];
    cin.ignore();
    cin.getline(searchDate, sizeof(searchDate));

    bool found = false;
    for (int i = 0; i < numTask; i++) {
        if (strcmp(tasks[i]->date, searchDate) == 0) {
            cout << "Found matching task:" << endl;
            displayTask(*(tasks[i]));
            found = true;
        }
    }

    if (!found) {
        cout << "No tasks matching the date found." << endl;
    }
}

void displayTask(const Task& task) {
    cout << "Task Title: " << task.title << endl;
    cout << "Priority: " << task.priority << endl;
    cout << "Description: " << task.description << endl;
    cout << "Date: " << task.date << endl;
    cout << "Time: " << task.time << endl;
}

void cleanupMemory(Task** tasks, int numTask, int maxTask) {
    
    for (int i = 0; i < numTask; ++i) {
        delete tasks[i];
    }
    delete[] tasks;
}