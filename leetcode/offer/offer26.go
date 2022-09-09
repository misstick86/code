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

func SubStructure(A *TreeNode, B *TreeNode) bool {
	if A == nil && B == nil || A != nil && B == nil {
		return true
	}
	if A == nil && B != nil {
		return false
	}
	if A.Val == B.Val {
		flag := true
		flag = flag && SubStructure(A.Left, B.Left)
		if !flag {
			return flag
		}
		flag = flag && SubStructure(A.Right, B.Right)
		return flag
	}
	return false
}
func isSubStructure(A *TreeNode, B *TreeNode) bool {
	p := false
	if A != nil {
		if B == nil {
			return false
		}
		p = SubStructure(A, B)
		if p {
			return p
		}
		p = isSubStructure(A.Left, B)
		if p {
			return p
		}
		p = isSubStructure(A.Right, B)
	}
	return p

}
func main() {
	nodea := []int{3, 4, 5, 1, 2}
	nodeb := []int{4, 1}
	rootA := BuildTree(nodea, 0)
	rootB := BuildTree(nodeb, 0)
	isSubStructure(rootA, rootB)
}
