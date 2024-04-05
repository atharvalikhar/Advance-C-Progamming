
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_TASKS 100 
#define MAX_TASK_LENGTH 50 
struct Task { 
    char description[MAX_TASK_LENGTH];     int completed; 
}; 
struct Task todoList[MAX_TASKS]; 
int numTasks = 0; 
void addTask(const char* description) {     if (numTasks < MAX_TASKS) { 
        strcpy(todoList[numTasks].description, description);         todoList[numTasks].completed = 0;         numTasks++; 
        printf("Task added successfully!\n"); 
    } else { 
        printf("Todo list is full. Cannot add more tasks.\n"); 
    } 
} 
void viewTasks() {     printf("Todo List:\n"); 
    for (int i = 0; i < numTasks; i++) { 
        printf("%d. [%c] %s\n", i + 1, todoList[i].completed ? 'X' : ' ', todoList[i].description); 
    } 
} 
void markTaskCompleted(int index) {     if (index >= 1 && index <= numTasks) {         todoList[index - 1].completed = 1; 
        printf("Task %d marked as completed.\n", index); 
    } else { 
        printf("Invalid task number.\n"); 
    } 
} 
int main() {   
    int choice; 
    char description[MAX_TASK_LENGTH]; 
    printf("Simple Todo List\n"); 
    do {         printf("\nMenu:\n");         printf("1. Add Task\n");         printf("2. View Tasks\n"); 
        printf("3. Mark Task as Completed\n");         printf("4. Exit\n"); 
        printf("Enter your choice: ");         scanf("%d", &choice); 
        switch (choice) {             case 1: 
                printf("Enter task description: ");                 scanf(" %[^\n]s", description);                 addTask(description); 
                break;             case 2:                 viewTasks(); 
                break;             case 3: 
                printf("Enter task number to mark as completed: ");                 scanf("%d", &choice);                 markTaskCompleted(choice);                 break;             case 4: 
                printf("Exiting program.\n");                 break;             default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } while (choice != 4); 
    return 0; 
}

