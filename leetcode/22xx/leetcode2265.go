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
func caleAvg(root *TreeNode, n *int) int {
	sum := 0
	if root != nil {
		*n++
		sum = root.Val + caleAvg(root.Left, n) + caleAvg(root.Right, n)
	}
	return sum
}

func cale(root *TreeNode, p *int) {
	if root == nil {
		return
	}
	n := 0
	sum := caleAvg(root, &n)
	if sum/n == root.Val {
		*p++
	}
	cale(root.Left, p)
	cale(root.Right, p)
}

func averageOfSubtree(root *TreeNode) int {

	sum := 0
	cale(root, &sum)
	return sum
}

func main() {
	node := []int{4, 8, 5, 0, 1, -1, 6}
	root := BuildTree(node, 0)
	averageOfSubtree(root)

}
