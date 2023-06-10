// Question -->Intersection of Two Linked Lists
// //   Node *temp=headA,*temp2=headB;
// //          if(headA==NULL || headB==NULL)
// //            return NULL;
// //        while(headA!=headB)
// //        {
// //             if(headA==NULL)
// //             headA=temp2;
// //             else
// //             headA=headA->next;
// //             if(headB==NULL)
// //             headB=temp;
// //             else
// //             headB=headB->next;
// //        }
      
// //        return headB;

// Question---> detect a cycle in linked list 
// bool detectCycle(Node *head)
// {
// 	Node *temp=head,*q=head;
//         while(q!=NULL && q->next!=NULL)
//         {
//             temp=temp->next;
//             q=q->next->next;
//             if(temp==q)
//             return true;
//         }
//         return false;
// }

// //Question -->Linked list is palindrome or not
// #include <bits/stdc++.h> 
// /****************************************************************

//     Following is the class structure of the LinkedListNode class:

//     template <typename T>
//     class LinkedListNode
//     {
//     public:
//         T data;
//         LinkedListNode<T> *next;
//         LinkedListNode(T data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };

// *****************************************************************/

// bool isPalindrome(LinkedListNode<int> *head) {
//     if(head==NULL)
//     return true;
//     LinkedListNode<int> *slow=head,*fast=head;
//         while(fast && fast->next)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         LinkedListNode<int> *prev=slow->next;
//         LinkedListNode<int> *r=NULL;
//         LinkedListNode<int> *q=NULL;
//         LinkedListNode<int> *p=slow;
//         while(p)
//         {
//             r=q;
//             q=p;
//             p=p->next;
//             q->next=r;
//         }
//         prev=q;
//         while(prev!=NULL)
//         {
//             if(prev->data!=head->data)
//             return false;
//             head=head->next;
//             prev=prev->next;
//         }
//         return true;

// }

// Question --->LInked List cycle II 
// Node *firstNode(Node *head)
// {
//      Node *prev,*p=head,*q=head;
//         if(!head)
//         return head;
//         while(q && q->next)
//         {
//             prev=p;
//             p=p->next;
//             q=q->next->next;
//             if(p==q)
//             {
//                break;
//             }
//         }
//         if(q==NULL || q->next==NULL)
//         return NULL;
//         Node *start=head;
//         prev=p;
//         while(start!=p)
//         {
//             p=p->next;
//             start=start->next;
//         }
//         return start;
// }

// // Question---> flatten a linked list
// Node* merge(Node *a,Node *b)
//     {
// 		Node* temp = new Node(-1);
// 	Node* res = temp;
// 	if(!a)return b;
// 	if(!b) return a;
// 	while(a && b){
// 		if(a->data< b->data){
// 			temp->child = a;
// 			temp = temp->child;
// 			a = a->child;
// 		}
// 		else{
// 			temp->child =b;
// 			temp =temp->child;
// 			b = b->child;
// 		}
// 	}
// 	if(a) temp->child =a;
// 	else
// 	temp->child= b;

// 	return res->child;
//     }
// Node* flattenLinkedList(Node* head) 
// {
// 	if(!head) return head;
//  Node* down = head;
//    Node* right = head->next;
//    down->next = NULL;
//    right = flattenLinkedList(right);
    
//     Node* ans = merge(down, right);
//     return ans;
// }


// Question ---> reverse a linked list 
//  if(head==NULL )
//         return head;
//         Node *dummy=new Node(0);
//          dummy->next=head;
//         Node *cur=dummy,*nex=dummy,*pre=dummy;
//         int cnt=0;
//         while(cur->next)
//         {
//             cnt++;
//             cur=cur->next;
//         }
// 		int j=0;
//         cur=pre;
//         while(j<n && cnt>=b[j])
//         {
// 			if(b[j]<1)
// 			{
// 				cnt-=b[j];
// 				j++;
// 			continue;}
//             cur=pre->next;
//             nex=cur->next;
//             for(int i=1;i<b[j];i++)
//             {
//                 cur->next=nex->next;
//                 nex->next=pre->next;
//                 pre->next=nex;
//                 nex=cur->next;
//             }
//             pre=cur;
//             cnt-=b[j];
// 			j++;
//         }
//         if(j<n)
// 		{Node *temp1=cur->next;
//         Node *p=NULL;
//         Node *q=NULL;
//         while (temp1) {
//           q = temp1->next;
//           temp1->next = p;
//           p = temp1;
//           temp1 = q;
//         }
//         cur->next = p;
//         }
//         return dummy->next;