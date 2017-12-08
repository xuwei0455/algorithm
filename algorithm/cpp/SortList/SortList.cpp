// Number     : 148 
// Title      : Sort List
// Source     : https://leetcode.com/problems/sort-list/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-08


/**********************************************************************************
*
* Sort a linked list in O(n log n) time using constant space complexity.
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


/**
* Divide the linked list into two lists,
* while the first list contains first n ndoes
* return the second list's head
*/
ListNode*
split(ListNode* head, const int n)
{
    // n may bigger than head's length
    for (int i = 1; head && i < n; i++) head = head->next;

    if (!head) return nullptr;

    ListNode* second = head->next;
    head->next = nullptr;
    return second;
}


/**
* merge the two sorted linked list l1 and l2,
* then append the merged sorted linked list to the node head
* return the tail of the merged sorted linked list
*/
ListNode*
merge(ListNode* l1, ListNode* l2, ListNode* head)
{
    ListNode* cur = head;
    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            cur->next = l2;
            l2 = l2->next;
        }
        else
        {
            cur->next = l1;
            l1 = l1->next;
        }
        cur = cur->next;
    }

    cur->next = (l1 ? l1 : l2);
    while (cur->next) cur = cur->next;
    // return the tail of merged sorted linked node.
    return cur;
}


ListNode*
sortList(ListNode* head)
{
    if (!head || !(head->next)) return nullptr;

    ListNode* cur = head;
    int length = 0;
    while (cur)
    {
        cur = cur->next;
        length++;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    for (int step = 1; step < length; step <<= 1)
    {
        cur = dummy->next;
        ListNode* tail = dummy;
        while (cur)
        {
            ListNode* left = cur;
            ListNode* right = split(left, step);
            cur = split(right, step);
            tail = merge(left, right, tail);
        }
    }
    return dummy->next;
}

ListNode*
createList(int a[], int n)
{
    ListNode* head = new ListNode(a[0]);
    ListNode* p = head;

    for (int i = 1; i < n; i++)
    {
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    return head;
}


void
printList(ListNode* head)
{
    ListNode* cur = head;
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
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

    ListNode* p = createList(a, n);
    printList(p);
    printList(sortList(p));

    delete[] a;
    return 0;
}