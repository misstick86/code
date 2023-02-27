/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。



示例 1：

输入：head = [1,3,2]
输出：[2,3,1]

*/

package main

import "fmt"

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

func reverse(a []int) {
	for i := 0; i < len(a)-1; i++ {
		a[i], a[len(a)-i-1] = a[len(a)-i-1], a[i]
	}
}
func reversePrint(head *ListNode) []int {
	var result []int
	for head != nil {
		result = append(result, head.Val)
		head = head.Next
	}
	reverse(result)
	fmt.Println(result)
	return result
}

func Reverse2(head *ListNode) []int {
	var p []int
	if head != nil {

		p = append(p, Reverse2(head.Next)...)
		p = append(p, head.Val)
	}
	return p
}

func reversePrint2(head *ListNode) []int {
	return Reverse2(head)
}

func main() {
	l := []int{1, 2, 3}
	root := BuildList(l)
	reversePrint2(root)
	//reversePrint(root)
}
