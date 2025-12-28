![[Pasted image 20251228125700.png]]![[Pasted image 20251228125710.png]]

Solution
![[Pasted image 20251228125832.png]]
![[Pasted image 20251228125846.png]]
![[Pasted image 20251228125859.png]]![[Pasted image 20251228125915.png]]
![[Pasted image 20251228125940.png]]
![[Pasted image 20251228125956.png]]

main
`int main() {`
    `// ios::sync_with_stdio(false);`
    `// cin.tie(0);`
    `ListNode *head1 = new ListNode();`
    `ListNode *tail1 = head1;`
    `ListNode *head2 = new ListNode();`
    `ListNode *tail2 = head2;`
    `cout<<"List1 values: ";`
    `for(int i = 0; i<7; i++)`
    `{`
        `int temp;`
        `cin>>temp;`
        `tail1->next = new ListNode(temp);`
        `tail1 = tail1->next;`
    `}`
    `cout<<"\nList2 values: ";`
    `for(int i = 0; i<4; i++)`
    `{`
        `int temp;`
        `cin>>temp;`
        `tail2->next = new ListNode(temp);`
        `tail2 = tail2->next;`
    `}`
    `Solution s;`
    `ListNode *result = s.addTwoNumbers(head1, head2);`
    `result = result->next;`
    `cout<<"[";`
    `while(result != nullptr)`
    `{`
        `cout<<result->val;`
       `result = result->next;`
    `}`
    `cout<<"]";`
    `return 0;`
`}`

<hr>
## Explaination

## Problem (LeetCode 2 – Add Two Numbers)

- Two numbers are given as **linked lists**.
- Digits are stored **in reverse order**.
- Each node contains **one digit**.
- Add the two numbers and return the **sum as a linked list**.

## 1. First Intuition (Very Basic Idea)

- This is just like **adding two numbers digit by digit**.
- Start from the **first node** of both lists.
- Add:
    - digit from list1
    - digit from list2
    - carry from previous addition
- Store the **last digit** of the sum.
- Pass the **carry** to the next step.
- Continue until both lists are finished.
- If carry remains at the end, add a new node.

## 2. Overall Approach (What We Do)
1. Create a **dummy head** for the result list
2. Use a **tail pointer** to build the result list step by step.
3. Traverse both lists at the same time.
4. At each step:
    - Take values from lists if available.
    - Add them with carry.
    - Store `sum % 10` in a new node.
    - Update carry as `sum / 10`.
5. Return the list **after the dummy node**.

## 3. Solution Code — Part by Part Explanation

### A. ListNode Structure
`struct ListNode{     int val;     ListNode *next; };`
**Why used**
- Represents one digit of the number.
- `val` stores the digit.
- `next` points to the next digit.
### B. Dummy Head for Result
`ListNode *result = new ListNode(); 
`ListNode *resultT = result;`
**Why used**
- Dummy head avoids special handling for the first node.
- `resultT` always points to the **last node** of the result list.
- Makes insertion simple.

### C. Variables for Addition
`int sum = 0; int carry = 0; int li1, li2;`
**Why used**
- `sum`: stores digit result.
- `carry`: stores carry from previous digit.
- `li1`, `li2`: temporary values from list1 and list2.

### D. Pointers to Traverse Lists
`ListNode *dummy1 = l1; ListNode *dummy2 = l2;`
**Why used**
- We should not modify original head pointers.
- These move through the lists safely.

### E. Main Loop
`while(dummy1 != nullptr || dummy2 != nullptr)`
**Why used**
- Continue while **at least one list still has digits**.

### F. Reading Values Safely
`if(dummy1 != nullptr){     li1 = dummy1->val;     dummy1 = dummy1->next; }`
`if(dummy2 != nullptr){     li2 = dummy2->val;     dummy2 = dummy2->next; }`
**Why used**
- Lists can be of **different lengths**.
- If one list ends earlier, its value is treated as `0`.

### G. Sum and Carry Calculation
`sum = (li1 + li2 + carry) % 10; carry = (li1 + li2 + carry) / 10;
**Why used**
- `% 10` gives the digit to store.
- `/ 10` gives the carry to pass forward.
- This mimics normal addition.

### H. Adding New Node to Result
`resultT->next = new ListNode(sum); resultT = resultT->next;`
**Why used**
- Appends the new digit to the result list.
- Moves the tail forward.

### I. Reset Values
`li1 = 0; li2 = 0;`
**Why used**
- Prevents using old values when a list has ended.

### J. Removing Dummy Head
`result = result->next;`
**Why used**
- Dummy node does not belong to the final answer.
- Actual result starts from the next node.

## 4. Time Complexity
### **O(max(n, m))**
- `n` = length of list1
- `m` = length of list2
- Each node is visited **once**.
- No nested loops.
**Why**
- One pass through both lists.

## 5. Space Complexity
### **O(max(n, m))**
**Why**
- A new linked list is created to store the result.
- In worst case, result length is `max(n, m) + 1` (extra carry).

## 6. Key Takeaways

- Dummy head simplifies linked list construction.
- Carry handling is identical to normal addition.
- `% 10` → digit, `/ 10` → carry.
- Traverse while **any list is not finished**.
- Time: linear
- Space: linear

<hr>
