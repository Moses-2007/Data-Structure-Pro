#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_MSG_LEN 256

// Structure for a message node
typedef struct Message {
    char sender[MAX_NAME_LEN];
    char content[MAX_MSG_LEN];
    struct Message* next;
} Message;

// Structure for a chat group
typedef struct Group {
    char name[MAX_NAME_LEN];
    Message* head;
    Message* tail;
} Group;

// Function to initialize a group
void initGroup(Group* group, const char* name) {
    strcpy(group->name, name);
    group->head = NULL;
    group->tail = NULL;
}

// Function to send a message to the group
void sendMessage(Group* group, const char* sender, const char* content) {
    Message* newMsg = (Message*)malloc(sizeof(Message));
    strcpy(newMsg->sender, sender);
    strcpy(newMsg->content, content);
    newMsg->next = NULL;

    if (group->tail == NULL) {
        group->head = group->tail = newMsg;
    } else {
        group->tail->next = newMsg;
        group->tail = newMsg;
    }

    printf("[Sent] %s: %s\n", sender, content);
}

// Function to display all messages in the group
void displayChat(Group* group) {
    printf("\n--- Chat in Group '%s' ---\n", group->name);
    Message* current = group->head;
}
