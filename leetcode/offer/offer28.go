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
	if node[n] == -1000 {
		root = nil
		return root
	}
	root.Val = node[n]
	root.Left = BuildTree(node, 2*n+1)
	root.Right = BuildTree(node, 2*n+2)

	return root
}

func Equal(left *TreeNode, right *TreeNode) bool {
	flag := false
	if left != nil && right != nil {
		if left.Val == right.Val {
			flag = true
		}
		flag = flag && Equal(left.Left, right.Right)
		if flag == false {
			return false
		}
		flag = flag && Equal(left.Right, right.Left)
	}
	if left == nil && right == nil {
		return true
	}
	return flag
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return false
	}
	return Equal(root.Left, root.Right)
}

func main() {
	node := []int{1, 2, 2, -1000, 3, -1000, 3}
	root := BuildTree(node, 0)
	isSymmetric(root)
}
