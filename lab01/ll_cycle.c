#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    if (head == NULL) {
        return 0;
    }

    node* ptr_slow = head;
    node* ptr_fast = head;

    while (
        ptr_slow->next &&
        ptr_fast->next &&
        ptr_fast->next->next
    ) {
        ptr_slow = ptr_slow->next;
        ptr_fast = ptr_fast->next->next;
        if (ptr_slow == ptr_fast) {
            return 1;
        }
    }

    return 0;
}