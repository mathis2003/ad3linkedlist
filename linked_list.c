//
// Created by Mathis De Witte on 26/09/2023.
//
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void add_element(LinkedList* list, int el) {
    ListNode* current_node = malloc(sizeof(ListNode));

    if (list->start_node == NULL) list->start_node = current_node;
    else list->end_node->next_node = current_node;

    list->end_node = current_node;
    current_node->content = el;
    current_node->next_node = NULL; // obviously the last node can't point to another node

    list->size++;
}

LinkedList* create_list() {
    LinkedList* result = malloc(sizeof (LinkedList));
    result->start_node = NULL;
    result->end_node = NULL;
    result->size = 0;
    return result;
}

void delete_element(LinkedList* list, int el) {
    ListNode* current_node = list->start_node;
    if (current_node == NULL) return;
    if (current_node->content == el) {
        if (current_node == list->end_node) list->end_node = NULL;
        list->start_node = current_node->next_node;
        free(current_node);
        list->size--;
    } else {
        ListNode* prev_node = list->start_node;
        current_node = list->start_node->next_node;
        while(current_node != NULL) {
            if (current_node->content == el) {
                prev_node->next_node = current_node->next_node;
                if (current_node == list->end_node) list->end_node = prev_node;
                list->size--;
                free(current_node);
                break;
            } else {
                prev_node = current_node;
                current_node = current_node->next_node;
            }
        }
    }

}

void delete_list(LinkedList* list) {
    ListNode* next_node;
    ListNode* current_node = list->start_node;
    while (current_node != NULL) {
        next_node = current_node->next_node;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

void print_list(LinkedList* list) {
    ListNode* current_node = list->start_node;
    printf("size: %d\n", list->size);
    for (int i = 1; current_node != NULL; i++) {
        printf("node: %d: %d\n", i, current_node->content);
        current_node = current_node->next_node;
    }
}

int compare_nodes(const void* n1, const void* n2) {
    return ((ListNode*)n1)->content - ((ListNode*)n2)->content;
}

void sort_list(LinkedList* list) {

}
