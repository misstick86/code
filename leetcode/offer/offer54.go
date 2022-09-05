/*
	https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
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

func find(root *TreeNode, k *int) *TreeNode {
	if root == nil {
		return nil
	}

	p := find(root.Right, k)

	if p != nil {
		return p
	}
	*k--
	if *k == 0 {
		return root
	}
	return find(root.Left, k)
}
func kthLargest(root *TreeNode, k int) int {
	n := find(root, &k)
	return n.Val
}
func main() {
	node := []int{5, 3, 7, 2, 4, 6, 8, 1}
	root := BuildTree(node, 0)
	kthLargest(root, 3)
}
