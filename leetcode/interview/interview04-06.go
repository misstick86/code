package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
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

func Find(root *TreeNode) *TreeNode {
	for root.Left != nil {
		root = root.Left
	}
	return root
}

func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	s := make([]*TreeNode, 0)
	for root != nil || len(s) != 0 {
		if root != nil {
			s = append(s, root)
			root = root.Left
		} else {
			node := s[len(s)-1]
			s = s[:len(s)-1]
			if node.Val == p.Val {
				if node.Right != nil {
					return Find(node.Right)
				}
				if len(s) != 0 {
					return s[len(s)-1]
				}
				return nil
			}
			root = node.Right
		}
	}
	return nil
}
func main() {
	node := []int{6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5}
	root := BuildTree(node, 0)
	p := TreeNode{Val: 2, Left: nil, Right: nil}
	s := inorderSuccessor(root, &p)
	fmt.Println(s.Val)
}
