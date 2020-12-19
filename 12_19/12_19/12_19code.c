/*
8. 输入两个链表，找出它们的第一个公共结点。

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


#include<stdio.h>
#include<stdbool.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
/*
长度不一样会产生错位
统计两个链表的长度，若一样长则同时走，若不一样长，则长的先走基本，使二者长度相同
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) //比较地址
{
	struct ListNode* curA, *curB;
	curA = headA;
	curB = headB;
	int lengthA = 0, lengthB = 0;//找到两个链表的长度
	while (curA)
	{
		++lengthA;
		curA = curA->next;
	}
	while (curB)
	{
		++lengthB;
		curB = curB->next;
	}
	curA = headA;
	curB = headB;
	int gap = abs(lengthA - lengthB);
	if (lengthA > lengthB)
	{
		while (gap--)
		{
			curA = curA->next;
		}
	}
	else
	{
		while (gap--)
		{
			curB = curB->next;
		}
	}
	while (curA && curB)
	{
		if (curA == curB)
			return curA;
		curA = curA->next;
		curB = curB->next;
	}
	return NULL;
}


/*
9.给定一个链表，判断链表中是否有环
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思想：追及相遇问题
*/
bool hasCycle(struct ListNode *head)
{
	struct ListNode* low, *fast;
	low = fast = head;
	while (fast&&fast->next)
	{
		low = low->next;
		fast = fast->next->next;
		if (low == fast)
			return true;
	}
	return false;
}

/*如何找到有环链表的入口节点？
10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
1.找到相遇点
2.分别从相遇点和头结点开始走，相遇的位置为入口节点的位置
*/

struct ListNode* hasCycle1(struct ListNode *head)
{
	struct ListNode* low, *fast;
	if (head == NULL)
		return NULL;
	low =fast= head;
	
	while (fast&&fast->next)
	{
		low = low->next;
		fast = fast->next->next;
		if (low == fast)
			return fast;
	}
	return NULL;
}//一般两步步长，否则产生跳过现象
struct ListNode *detectCycle(ListNode *head)
{
	struct ListNode* cur = hasCycle1(head);
	if (cur)
	{
	while (cur)
	{
		if (cur == head)
			return cur;
		cur = cur->next;
		head = head->next;
	}
	}
	return NULL;
}

/*
对链表进行插入排序


插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//从前到后遍历找到第一个比待插入数字大的位置
struct ListNode* insertionSortList(struct ListNode* head)

{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* node = head->next;
	struct ListNode* tail = head;
	while (node)
	{
	}

}

int main()
{}