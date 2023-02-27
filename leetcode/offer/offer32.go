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
	if node[n] == 0 {
		root = nil
		return root
	}
	root.Val = node[n]
	root.Left = BuildTree(node, 2*n+1)
	root.Right = BuildTree(node, 2*n+2)

	return root
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	p := make([][]int, 0)
	s := make([]*TreeNode, 0)
	s = append(s, root)
	for len(s) != 0 {
		n := len(s)
		c := make([]int, 0)
		for n > 0 {
			k := s[0]
			if k.Left != nil {
				s = append(s, k.Left)
			}
			if k.Right != nil {
				s = append(s, k.Right)
			}
			c = append(c, k.Val)
			s = s[1:]
			n--
		}
		p = append(p, c)

	}
	return p
}
func main() {
	node := []int{3, 9, 20, 0, 0, 15, 7}
	root := BuildTree(node, 0)
	p := levelOrder(root)
	fmt.Println(p)
}
