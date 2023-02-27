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

func deleteNode(head *ListNode, val int) *ListNode {
	if head == nil {
		return head
	}
	if head.Val == val {
		return head.Next
	}
	pre := head
	p := head.Next
	for p.Val != val {
		p = p.Next
		pre = pre.Next
	}
	pre.Next = p.Next
	return head
}
func main() {
	l := []int{1, 2, 3, 4, 5}
	root := BuildList(l)
	deleteNode(root, 3)
}
