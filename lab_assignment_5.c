/* Author: Harsh Dave
 * Date: June 9th, 2023
 * Course: COP 3502C
 * Assignment: Lab 4 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    char letter;
    struct node* next;
} node;

int length(node* head) 
{
    // initialize a counter variable to 0
    int listLength = 0;

    // while loop to traverse through the nodes
    while (head != NULL) 
    {
        head = head->next;
        listLength++;  // increment length by 1
    }
    return listLength;
}

char* toCString(node* head) 
{
    // initialize index counter variable to 0 for first position
    int index = 0;

    // call length function to get length of the list
    int listLength = length(head); 

    // allocate memory to character pointer for the string of characters
    char* forString = (char*)malloc((listLength + 1) * sizeof(char));
    
    // traverse through the list / characters
    while (head != NULL) 
    {
        forString[index++] = head->letter;
        head = head->next;
    }
    // final character is the null terminator
    forString[listLength] = '\0';
    return forString;
}


void insertChar(node** pHead, char c) 
{
    // allocate the memory for a new node
    node* temp = (node*)malloc(sizeof(node));

    // set the info and pointer in the new node
    temp->letter = c;
    temp->next = NULL;

    // check if the head is null, if so then add the new node
    if (*pHead == NULL) 
    {
        *pHead = temp;
    } 
    else 
    {
        // set the current node to pointer of Head
        node* current = *pHead;

        // traverse through the nodes and add the characters to the following nodes
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void deleteList(node** pHead) 
{
    // set the current node to pointer of Head
    node* current = *pHead;

    // traverse through the nodes
    while (current != NULL) 
    {
        // free the memory until the list is empty
        node* next = current->next;
        free(current);
        current = next;
    }
    *pHead = NULL;
}

int main(void) 
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0) 
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) 
        {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is: %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!\n");
            break;
        }
    }
    fclose(inFile);
}
