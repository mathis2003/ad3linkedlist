#include <stdio.h>
#include "linked_list.h"



int main() {
    LinkedList* list = create_list();

    add_element(list, 1);
    add_element(list, 2);
    add_element(list, 3);
    printf("current list is:\n");
    print_list(list);

    add_element(list, 5);
    add_element(list, 8);
    add_element(list, 2);
    printf("current list2 is:\n");
    print_list(list);

    delete_element(list, 2);
    delete_element(list, 5);
    delete_element(list, 2);
    delete_element(list, 8);

    printf("current list3 is:\n");
    print_list(list);

    delete_list(list);

}

