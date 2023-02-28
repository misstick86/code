/*
https://leetcode.cn/problems/list-of-depth-lcci/
*/

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func BuildTree(node []int, n int) *TreeNode {
	if n >= len(node) {
		return nil
	}
	var root *TreeNode

	root = new(TreeNode)
	if node[n] == -1 {
		root = nil
		return root
	}
	root.Val = node[n]
	root.Left = BuildTree(node, 2*n+1)
	root.Right = BuildTree(node, 2*n+2)

	return root
}

func listOfDepth(tree *TreeNode) []*ListNode {
	p := make([]*TreeNode, 0)
	result := make([]*ListNode, 0)
	p = append(p, tree)

	for len(p) != 0 {

		n := len(p)
		l := new(ListNode)
		v := l
		for n != 0 {
			node := p[0]
			p = p[1:]
			if node.Left != nil {
				p = append(p, node.Left)
			}
			if node.Right != nil {
				p = append(p, node.Right)
			}
			l.Next = &ListNode{Val: node.Val}
			l = l.Next
			n--
		}
		result = append(result, v.Next)

	}

	return result
}

func main() {
	node := []int{1, 2, 3, 4, 5, -1, 7, 8}
	root := BuildTree(node, 0)
	listOfDepth(root)
}
