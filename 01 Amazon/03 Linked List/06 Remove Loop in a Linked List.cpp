Problem Statement  : https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
// Floyd Cycle Detection 

bool isloop(Node* head)
{
   Node *slow=head;
   Node *fast=head;
   while(slow && fast && fast->next)
   {
       slow=slow->next;
       fast=fast->next->next;
       if(slow==fast)
          return true;
   }
   return false;
}

void removeTheLoop(Node *head)
{
     if(!isloop(head))
        return ;
     else
     {
        Node *slow=head;
        Node *fast=head;
        while(slow && fast && fast->next)
        {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
               break;
        }
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        while(slow!=fast->next)
        {
            fast=fast->next;
        }
        fast->next=NULL;
        return ;
     }
}


