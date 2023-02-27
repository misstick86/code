/*
https://leetcode.cn/problems/legal-binary-search-tree-lcci/
*/
package main

import "math"

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

func isValidBST(root *TreeNode) bool {
	p := make([]*TreeNode, 0)
	min := math.MinInt16
	for root != nil || len(p) != 0 {
		if root != nil {
			p = append(p, root)
			root = root.Left

		} else {
			node := p[len(p)-1]
			p = p[:len(p)-1]
			root = node.Right
			if min >= node.Val {
				return false
			} else {
				min = node.Val
			}
		}

	}
	return true
}
func main() {
	node := []int{1, 1}
	root := BuildTree(node, 0)
	isValidBST(root)
}
