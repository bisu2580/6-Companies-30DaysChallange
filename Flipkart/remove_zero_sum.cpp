#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    void printNode(ListNode *head)
    {
        ListNode *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    ListNode *removeZeroSumSublists(ListNode *head)
    {

        if (head == NULL)
        {
            return 0;
        }
        unordered_map<int, ListNode *> mp;
        ListNode *temp = new ListNode(0);
        temp->next = head;
        mp[0] = temp;
        int sum = 0;
        while (head != NULL)
        {
            sum += head->val;
            if (mp.find(sum) != mp.end())
            {
                ListNode *start = mp[sum];
                int sum2 = sum;
                while (start != NULL && start != head)
                {
                    start = start->next;
                    sum2 += start->val;
                    if (start != head)
                        mp.erase(sum2);
                }
                mp[sum]->next = head->next;
            }
            else
            {
                mp[sum] = head;
            }
            head = head->next;
        }
        return temp->next;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(-3);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(1);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution s;
    head = s.removeZeroSumSublists(head);
    cout << "Resultant list after deleting zero sum consecutive nodes: \n";
    s.printNode(head);
}