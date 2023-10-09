//
// Created by Mathis De Witte on 26/09/2023.
//

#ifndef UNTITLED_LINKED_LIST_H
#define UNTITLED_LINKED_LIST_H

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct LinkedList {
    struct ListNode* start_node;
    struct ListNode* end_node;
    int size;
} LinkedList;

typedef struct ListNode {
    struct ListNode* next_node;
    int content;
} ListNode;

LinkedList* create_list();
void add_element(LinkedList* list, int el);
void delete_element(LinkedList* list, int el);
void print_list(LinkedList* list);
void delete_list(LinkedList* list);

#endif


#endif //UNTITLED_LINKED_LIST_H
