// Number     : 147 
// Title      : Insertion Sort List
// Source     : https://leetcode.com/problems/insertion-sort-list/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-07


/**********************************************************************************
*
* Sort a linked list using insertion sort.
*
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode*
insertionSortList(ListNode* head) {
    if (head == nullptr) { return head; }

    // helper start for sorted list
    ListNode* helper = new ListNode(0);
    // alias for helper
    ListNode* p_sorted = helper;

    while (head != nullptr)
    {
        // remeber the next
        const auto next = head->next;
        // find the right position to insert
        while (p_sorted->next != nullptr && p_sorted->next->val < head->val)
        {
            p_sorted = p_sorted->next;
        }

        // insert between pre and next
        head->next = p_sorted->next;
        p_sorted->next = head;
        // initialize for next round    
        p_sorted = helper;
        head = next;
    }

    return p_sorted->next;
}

void
printList(ListNode* head)
{
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

ListNode*
createList(const int a[], const int n)
{
    ListNode *head = nullptr, *p = nullptr;
    for (auto i = 0; i < n; i++) {
        if (head == nullptr) {
            head = p = new ListNode(a[i]);
        }
        else {
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}


int main(const int argc, char** argv)
{
    auto n = 10;
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    srand(time(nullptr));

    const auto a = new int[n];
    for (auto i = 0; i < n; i++) {
        a[i] = rand() % n + 1;
    }

    const auto p = createList(a, n);
    printList(p);
    printList(insertionSortList(p));

    delete[] a;
}