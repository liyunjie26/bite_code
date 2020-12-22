#include<stdio.h>
#include<malloc.h>


typedef struct ListNode {

	int val;
struct	ListNode* next;
struct	ListNode* random;
}ListNode;



/*给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

ListNode* copyRandomList(ListNode* head)
{
	if (head == NULL)
		return head;
struct	ListNode* cur = head;
	//拷贝数据
	while (cur)
	{
	struct ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = cur->val;
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
	//拷贝随机指针
	cur = head;
	while (cur)
	{
		struct ListNode* copy = cur->next;
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		cur = copy->next;
	}
	//拆链
	struct ListNode* newhead = NULL;
	cur = head;
	newhead = cur->next;
	while (cur)
	{
		struct ListNode* copy = cur->next;
		struct ListNode* next = copy->next;
		if (next)
			copy->next = next->next;
		cur->next = next;
		cur = next;
	}
	return newhead;
}
void main()
{
}