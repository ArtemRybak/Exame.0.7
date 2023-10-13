#include "menu.h"

void addUserTaskMenu(Task**& tasks, int& numTask, int& maxTask) {
    if (numTask >= maxTask) {
        maxTask *= 2;
        Task** newTasks = new Task * [maxTask];
        for (int i = 0; i < numTask; ++i) {
            newTasks[i] = tasks[i];
        }
        delete[] tasks;
        tasks = newTasks;
    }

    Task* newTask = new Task;
    getUserTaskInput(newTask);

  
    int taskNumber = numTask + 1;

    addTask(tasks, numTask, newTask);
    cout << "Task #" << taskNumber << " added successfully!" << endl;
}


    void deleteTaskMenu(Task**& tasks, int& numTask, int& maxTask) {
        if (numTask == 0) {
            cout << "The task list is empty." << endl;
            return;
        }

        cout << "Enter the task number to delete (1-" << numTask << "): ";
        int taskNumber;
        cin >> taskNumber;

        if (taskNumber < 1 || taskNumber > numTask) {
            cout << "Invalid task number. Please enter a valid task number." << endl;
            return;
        }

        deleteTaskLogic(tasks, numTask, taskNumber);
    }

void editTaskMenu(Task** tasks, int numTask) {
    if (numTask == 0) {
        cout << "The task list is empty." << endl;
        return;
    }

    cout << "Enter the task number to edit (1-" << numTask << "): ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > numTask) {
        cout << "Invalid task number. Please enter a valid task number." << endl;
        return;
    }

    Task* taskToEdit = tasks[taskNumber - 1];
    editTaskDetails(taskToEdit);

    cout << "Task #" << taskNumber << " has been edited." << endl;
}


void searchTasksMenu(Task** tasks, int numTask, int maxTask) {
    if (numTask == 0 || maxTask == 0) {
        cout << "The task list is empty." << endl;
        return;
    }

    cout << "Search criteria:" << endl;
    cout << "1. By Name" << endl;
    cout << "2. By Priority" << endl;
    cout << "3. By Description" << endl;
    cout << "4. By Date" << endl;
    cout << "Choose a search criterion: ";
    int searchChoice;
    cin >> searchChoice;

    switch (searchChoice) {
    case 1:
        searchByName(tasks, numTask);
        break;
    case 2:
        searchByPriority(tasks, numTask);
        break;
    case 3:
        searchByDescription(tasks, numTask);
        break;
    case 4:
        searchByDate(tasks, numTask);
        break;
    default:
        cout << "Invalid search criterion. Please try again." << endl;
    }
}

void displayTasksMenu(Task** taskArray, int numTasks) {
    for (int i = 0; i < numTasks; ++i) {
        if (taskArray[i] != nullptr) {
            cout << "Task #" << i + 1 << ":" << endl;
            displayTask(*taskArray[i]);
        }
    }
}