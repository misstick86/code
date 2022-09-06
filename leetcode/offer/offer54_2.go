/*
	https://leetcode.cn/problems/w6cpku/
*/

package main

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

func convert(root *TreeNode, k *int) {
	if root == nil {
		return
	}
	if root.Right != nil {
		convert(root.Right, k)
	}
	root.Val, *k = root.Val+*k, root.Val+*k
	if root.Left != nil {
		convert(root.Left, k)
	}
}

func convertBST(root *TreeNode) *TreeNode {
	k := 0
	convert(root, &k)
	return root
}
func main() {
	node := []int{4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8}
	root := BuildTree(node, 0)
	convertBST(root)
}
