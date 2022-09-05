/*
https://leetcode.cn/problems/sZ59z6/
*/

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func Node2Map(root *TreeNode, p map[int]interface{}) {
	if root == nil {
		return
	}
	p[root.Val] = nil
	Node2Map(root.Left, p)
	Node2Map(root.Right, p)
}

func numColor(root *TreeNode) int {
	m := make(map[int]interface{})
	Node2Map(root, m)
	return len(m)
}
func BuildTree(node []int, n int) *TreeNode {
	if n >= len(node) {
		return nil
	}
	if node[n] == -1 {
		return nil
	}
	var root *TreeNode

	root = new(TreeNode)
	root.Val = node[n]
	root.Left = BuildTree(node, 2*n+1)
	root.Right = BuildTree(node, 2*n+2)

	return root
}

func main() {
	node := []int{1, 3, 2, 1, -1, 2}
	root := BuildTree(node, 0)
	numColor(root)
}
