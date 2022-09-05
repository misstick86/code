/*
	https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/
*/

package main

import (
	"math"
)

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

func findDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := findDepth(root.Left)
	right := findDepth(root.Right)
	return 1 + int(math.Max(float64(left), float64(right)))
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	flag := true
	left := findDepth(root.Left)
	right := findDepth(root.Right)

	if left-right >= 2 || left-right <= -2 {
		flag = false
	}
	flag = flag && isBalanced(root.Left)
	flag = flag && isBalanced(root.Right)
	return flag
}

func main() {
	node := []int{1, 2, 2, 3, 3, -1, -1, 4, 4}
	root := BuildTree(node, 0)
	isBalanced(root)

}
