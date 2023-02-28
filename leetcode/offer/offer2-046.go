/*
https://leetcode.cn/problems/WNC0Lk/
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

/*
	层序遍历每一层的最后一个节点
*/

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	p := make([]*TreeNode, 0)
	r := make([]int, 0)
	p = append(p, root)
	for len(p) != 0 {
		n := len(p)
		node := p[len(p)-1]
		r = append(r, node.Val)
		for n != 0 {
			node = p[0]
			p = p[1:]
			if node.Left != nil {
				p = append(p, node.Left)
			}
			if node.Right != nil {
				p = append(p, node.Right)
			}
			n--
		}
	}
	return r
}
func main() {
	node := []int{1, 2, 3, -1, 5, -1, 4}
	root := BuildTree(node, 0)
	rightSideView(root)
}
