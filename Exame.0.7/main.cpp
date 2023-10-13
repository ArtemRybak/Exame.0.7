
#include "menu.h"

int main() {
    int numTask = 0;
    int maxTask = 10;
    Task** tasks = new Task * [maxTask];

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Delete a task" << endl;
        cout << "3. Edit a task" << endl;
        cout << "5. Display tasks" << endl;
        cout << "4. Search for tasks" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an action: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addUserTaskMenu(tasks, numTask, maxTask);
            break;
        case 2:
            deleteTaskMenu(tasks, numTask, maxTask);
            break;
        case 3:
            editTaskMenu(tasks, numTask);
            break;
        case 4:
            displayTasksMenu(tasks, numTask);
            break;
        case 5:
            searchTasksMenu(tasks, numTask, maxTask);
            break;
        case 6:
            cleanupMemory(tasks, numTask, maxTask);
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}


