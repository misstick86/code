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

func findMaxDepthAndLeft(root *TreeNode, currDepth *int, value *int, maxDepth *int) {
	if root == nil {
		return
	}
	*currDepth++
	if *currDepth > *maxDepth {
		*maxDepth = *currDepth
		*value = root.Val
	}

	findMaxDepthAndLeft(root.Left, currDepth, value, maxDepth)
	findMaxDepthAndLeft(root.Right, currDepth, value, maxDepth)
	*currDepth--
}

func findBottomLeftValue(root *TreeNode) int {
	currDepth, Value, maxDepth := 0, 0, 0
	findMaxDepthAndLeft(root.Left, &currDepth, &Value, &maxDepth)
	currDepth = 0
	findMaxDepthAndLeft(root.Right, &currDepth, &Value, &maxDepth)
	if maxDepth == 1 {
		return root.Val
	}
	return Value
}

func main() {
	node := []int{1}
	root := BuildTree(node, 0)
	findBottomLeftValue(root)
}
