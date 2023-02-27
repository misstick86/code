/*
剑指 Offer 22. 链表中倒数第k个节点

输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
*/
package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func BuildList(nums []int) *ListNode {
	root := &ListNode{
		Val:  nums[0],
		Next: nil,
	}
	p := root
	for i := 1; i < len(nums); i++ {
		node := ListNode{Val: nums[i], Next: nil}
		p.Next = &node
		p = p.Next

	}
	return root
}

func getKthFromEnd(head *ListNode, k int) *ListNode {
	last := head
	for k != 0 && head != nil {
		head = head.Next
		k--
	}
	first := head

	for first != nil {
		last = last.Next
		first = first.Next
	}
	return last
}

func main() {
	l := []int{1, 2, 3, 4, 5}
	root := BuildList(l)
	getKthFromEnd(root, 2)
}
