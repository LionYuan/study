/*
单双链表操作
*/

#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

// 单链表添加节点
Node* add_node(Node* head, int num)
{
    if(!head)
        return NULL;

    Node *tmp = new Node;
    tmp->data = num;
    tmp->next = NULL;
    
    Node* p = head;
    while(p->next) 
        p = p->next;
    p->next = tmp;

    return head; 
}

// 单链表删除节点
Node* del_node(Node* head, int num)
{
    // del head node
    // del middle node
    // del tail node
    return head;
}

// 打印单链表
void print_list(Node* head)
{
    cout << "print list:" << endl;
    while(head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

// 单链表排序
Node* sort(Node* head)
{

    return head;
}

// 从尾到头打印单链表
// 顺序遍历，节点入栈，利用栈性质，进行逆序遍历打印
void reverse_print(Node* head)
{
    stack<Node*> stk;
    while(head)
    {
        stk.push(head);
        head = head->next;
    }

    cout << "begin reverse print list:" << endl;
    while(!stk.empty())
    {
        cout << stk.top()->data << "->";
        stk.pop();
    }
    cout << endl;
}

// 单链表的逆置
// 设置三个指针：pre, cur, next
// head -> 1 -> 2 -> 3 -> 4 -> null
// 逆置过程
// 1. 先特殊处理头节点：head->nex = null
// 2. 初始化 pre, cur, next 指针
// 3. 处理中部：
//      1) cur->next = pre
//      2) 三个指针从前往后逐个更新
// 4. 处理尾节点： cur->next = pre

Node* reverse(Node* head)
{
    // head is empty or has one node, return
    if(!head || !head->next)
        return head;

    // 定义前，当前，后指针
    // 头节点和尾节点特殊处理
    Node* pre = head;
    Node* cur = head->next;
    Node* next = cur->next;
    head->next = NULL;

    // 当 next 指向 null 时，尾节点处理完毕
    while(next)
    {
        // 设置当前节点 next
        cur->next = pre;
        cout << "reverse cur:" << cur->data << endl;

        // 更新迭代指针，从前往后更新
        pre = cur;
        cur = next;
        next = next->next;
    }

    // cur 指针即指向尾部节点
    cur->next = pre;
    head = cur;

    return head;
}

// 循环版本
Node* reverse_v1(Node* head)
{
    Node* reversed_head = NULL;
    Node* pcur = head;
    Node* ppre = NULL;

    while(pcur)
    {
        // tmp pointer
        Node* pnext = pcur->next;
        if(!pnext)
            reversed_head = pcur;

        // reverse cur node next pointer
        pcur->next = ppre;

        // update pointer
        ppre = pcur;
        pcur = pnext;
    }
    return reversed_head;
}

// best version
Node *ReverseLink(Node *head)
{
    Node *prev = NULL;
    while (head != NULL)
    {
        // tmp pointer
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// 递归版本 ??? 暂时不处理
Node *ReverseLink2(Node *head)
{
    // head empyt or has one node.
    if ((head == NULL) || (head->next == NULL))
        return head;

    Node *newHead = ReverseLink2(head->next); /*递归部分*/
    head->next->next = head; /*回朔部分*/
    head->next = NULL;
    return newHead;
}

// 查找链表中倒数k个节点
Node* find_kth_to_tail(Node* head, unsigned int k)
{
    Node* pre = head;
    Node* cur = head;
    while(cur)
    {
        if(k>0)
            --k;
        else
            pre = pre->next;
        cur = cur->next;
    }
    return k == 0 ? pre : NULL;
}

// 合并两个有序链表
Node* merge(Node* head1, Node* head2)
{
    // new list head
    Node* head = NULL;
    // new list iterator
    Node* p = NULL;
    while(head1 && head2)
    {
        // tmp node 
        Node* tmp;
        if(head2->data < head1->data)
        {
            tmp = head2;
            head2 = head2->next;
        }
        else
        {
            tmp = head1;
            head1 = head1->next;
        }

        // init new list head
        if(!head)
        {
            head = tmp;
            p = head;
        }
        // update new list head
        else
        {
            p->next = tmp;
            p = p->next;
        }
    }

    // rest of list
    if(head1)
        p->next = head1;
    if(head2)
        p->next = head2;

    return head;
}

void test()
{
    Node* head = new Node;
    head->data = 0;
    head->next = NULL;
    for(int i = 1; i < 10; ++i)
        add_node(head, i);
    print_list(head);

    Node* head1 = new Node;
    head1->data = 5;
    head1->next = NULL;
    for(int i = 6; i < 8; ++i)
        add_node(head1, i);
    print_list(head1);

    // reverse print list
    //reverse_print(head);

    //Node* reverse_head = ReverseLink(head);
    //print_list(reverse_head);

    Node* node = find_kth_to_tail(head, 11);
    if(node)
        cout << "find node: data:" << node->data << endl;
    else
        cout << "no result." << endl;

    Node* new_head = merge(head, head1);
    print_list(new_head);
}

int main()
{
    test();
};