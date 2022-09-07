/*
	https://leetcode.cn/problems/evaluate-boolean-binary-tree/
*/

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
func evaluateTree(root *TreeNode) bool {

	if root == nil {
		return true
	}

	switch root.Val {
	case 0:
		return false
	case 1:
		return true
	case 2:
		if evaluateTree(root.Left) {
			return true
		}
		return evaluateTree(root.Right)
	case 3:
		if evaluateTree(root.Left) == false {
			return false
		}
		return evaluateTree(root.Right)
	}
	return true
}

func main() {
	node := []int{3, 1, 0}
	root := BuildTree(node, 0)
	p := evaluateTree(root)
	fmt.Println(p)
}
