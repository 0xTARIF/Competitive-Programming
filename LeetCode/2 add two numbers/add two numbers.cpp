/**
 * author       :   Tarif Bin Mehedi
 * created at   :   28th december 2025
 * Leetcode 2   :   Add Two Numbers
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(); //Initialize the result nodes head with 0
        ListNode *resultT = result; //This is the tail in which we will add new nodes
        int sum=0; //this is for each digits sum
        int carry=0; //this is for each digits carry
        int li1; //Temporary holds the value of list 1
        int li2; //Temporary holds the value of list 2
        ListNode *dummy1 = l1; //represents list 1
        ListNode *dummy2 = l2; //represents list 2
        while(dummy1!=nullptr || dummy2!=nullptr) //loop goes until dummy1 and 2 are both over
        {
            if(dummy1!=nullptr)
            {
                li1 = dummy1->val; 
                dummy1 = dummy1->next; //after li1 has dummy1s current address value, dummy1 will point to the next node
            }

            if(dummy2!=nullptr)
            {
                li2=dummy2->val;
                dummy2 = dummy2->next;
            }

            if(dummy1==nullptr && dummy2==nullptr) //if both lists goes to the end
            { 
                if((li1+li2+carry)<10) //if sum is less than 10, no need to mention the carry, else 0 will append
                {   resultT->next = new ListNode(li1+li2+carry);
                    resultT = resultT->next;
                }
                else //if sum is 10 or more, then carry also must be mentioned
                {   resultT->next = new ListNode((li1+li2+carry)%10);
                    resultT = resultT->next;
                    resultT->next = new ListNode((li1+li2+carry)/10);
                    resultT = resultT->next;
                }
                break;
            }

            sum = (li1+li2+carry)%10; // 7+7+0 = 14, here 14%10 = 4, this is the value we will store in result
            carry = (li1+li2+carry)/10; //14/10 = 1, this is our carry
            li1 = 0; //list1 value is 0
            li2=0; //list2 value is now 0
            resultT->next = new ListNode(sum); //resultT represents the tail, and will input sum in the new node
            resultT = resultT->next; //then tail will be that node

        }
        result = result->next;

        return result;
        
    }
};

//SIMPLE TEST CASE

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    ListNode *head1 = new ListNode();
    ListNode *tail1 = head1;

    ListNode *head2 = new ListNode();
    ListNode *tail2 = head2;

    cout<<"List1 values: ";
    for(int i = 0; i<7; i++)
    {
        int temp;
        cin>>temp;
        tail1->next = new ListNode(temp);
        tail1 = tail1->next;
    }
    cout<<"\nList2 values: ";
    for(int i = 0; i<4; i++)
    {
        int temp;
        cin>>temp;
        tail2->next = new ListNode(temp);
        tail2 = tail2->next;
    }

    Solution s;

    ListNode *result = s.addTwoNumbers(head1, head2);

    result = result->next;

    cout<<"[";
    while(result != nullptr)
    {
        cout<<result->val;
        result = result->next;
    }
    cout<<"]";


    return 0;
}
