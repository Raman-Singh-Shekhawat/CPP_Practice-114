/*
130. kReverse: Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
*/

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/
Node *reverseLinkedListRec(Node *head)
{
    if (!head || !head->next)
    {

        return head;
    }

    Node *recHead = reverseLinkedListRec(head->next);

    head->next->next = head;
    head->next = NULL;

    return recHead;
}
Node *kReverse(Node *head1, int k)
{

    Node *temp = head1;
    for (int i = 1; i < k; i++)
    {

        temp = temp->next;
    }

    Node *head2 = temp->next;
    temp->next = NULL;
    Node *newHead1 = reverseLinkedListRec(head1);
    Node *newHead2 = reverseLinkedListRec(head2);

    head1->next = newHead2;

    return newHead1;
}