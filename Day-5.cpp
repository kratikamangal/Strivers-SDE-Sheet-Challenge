// Question -->Reverse Linked list 

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// {
//     LinkedListNode<int> *r,*q=NULL,*p=head;
//         while(p)
//         {
//             r=q;
//             q=p;
//             p=p->next;
//             q->next=r;
//         }
//         head=q;
//         return head;
// }

// Question -->Middle of linked list 
// Node *findMiddle(Node *head) {
//      Node *first=head,*second=head;
//         if(head==NULL)
//         return head;
//         while(first->next && second->next)
//         {
//             first=first->next;
//             second=second->next;
//             if(second->next)
//             second=second->next;
//         }
//         return first;
// }

// Question -->merge two sorted linked list 
// Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
// {
//      Node<int> *third=NULL,*last=NULL;
//         if(list1==NULL && list2==NULL)
//             return list1;
//         if(list1==NULL && list2!=NULL)
//             return list2;
//         if(list1!=NULL && list2==NULL)
//             return list1;
//         if(list1->data<list2->data)
//         {
//             third=list1;
//             last=list1;
//             list1=list1->next;
//             last->next=NULL;
//         }
//         else
//         {
//            third=list2;
//             last=list2;
//             list2=list2->next;
//             last->next=NULL; 
//         }
//         while(list1!=NULL && list2!=NULL)
//         {
//             if(list1->data<list2->data)
//         {
//             last->next=list1;
//             last=list1;
//                 list1=list1->next;
//             last->next=NULL;
//         }
//             else
//             {
//                 last->next=list2;
//             last=list2;
//                 list2=list2->next;
//             last->next=NULL;
//             }
//         }
//         if(list1)
//             last->next=list1;
//         if(list2)
//             last->next=list2;
//         return third;
// }


// Question -->remove nth node from linked list 
// /*
// Following is the class structure of the Node class:

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node()
//     {
//         this->data = 0;
//         next = NULL;
//     }
//     Node(int data)
//     {
//         this->data = data; 
//         this->next = NULL;
//     }
//     Node(int data, Node* next)
//     {
//         this->data = data;
//         this->next = next;
//     }
// };
// */

// Node* removeKthNode(Node* head, int n)
// {
//     Node *temp=head;
//          if(head==NULL)
//          return head;
//        int count=0;
//        while(temp)
//        {
//            count++;
//            temp=temp->next;
//        }
//        int x=0;
//        Node *q,*p=head;
//        if(count-n==0)
//        {
//            head=head->next;
//            return head;
//        }
//        while(p && x!=count-n)
//        {
//            q=p;
//            p=p->next;
//            x++;
//        }
//        if(p)
//        q->next=p->next;
//        else
//        q->next=NULL;
//        delete p;
//        return head;
// }


// Question -->Add two numbers
// /**
//  * Definition of linked list:
//  *
//  * class Node {
//  * public:
//  *      int data;
//  *      Node *next;
//  *      Node() {
//  *          this->data = 0;
//  *          this->next = NULL;
//  *      }
//  *      Node(int data) {
//  *          this->data = data;
//  *          this->next = NULL;
//  *      }
//  *      Node (int data, Node *next) {
//  *          this->data = data;
//  *          this->next = next;
//  *      }
//  * };
//  *
//  *************************************************************************/

// Node *addTwoNumbers(Node *l1, Node *l2)
// {
//      Node *l;
//         Node *head=new Node(0);
//         Node *temp=head;
//         int k=0;
//         while(l1!=NULL && l2!=NULL)
//         {
//             l=new Node;
//             l->data=(l1->data+l2->data+k)%10;
//             l->next=NULL;
//             k=(l1->data+l2->data+k)/10;
//             temp->next=l;
//             temp=l;
//             l1=l1->next;
//             l2=l2->next;
//         }
//         while(l1)
//         {
//             l=new Node;
//             l->data=(l1->data+k)%10;
//             l->next=NULL;
//             k=(l1->data+k)/10;
//             temp->next=l;
//             temp=l;
//             l1=l1->next;
//         }
//         while(l2)
//         {
//             l=new Node;
//             l->data=(l2->data+k)%10;
//             l->next=NULL;
//             k=(l2->data+k)/10;
//             temp->next=l;
//             temp=l;
//             l2=l2->next;
//         }
//         if(k==1)
//         {
//             l=new Node(k);
//             temp->next=l;
//             temp=l;
//         }
//         return head->next;
// }


// Question---->Delete a given Node when a node is given.
// void deleteNode(LinkedListNode<int> * node) {
//     node->data=node->next->data;
//         node->next=node->next->next;

// }