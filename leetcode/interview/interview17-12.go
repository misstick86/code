/*

二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

返回转换后的单向链表的头节点。

注意：本题相对原题稍作改动



示例：

输入： [4,2,5,1,3,null,6,0]
输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
提示：

节点数量不会超过 100000。
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

func convertBiNode(root *TreeNode) *TreeNode {
	pre := new(TreeNode)
	q := pre
	p := make([]*TreeNode, 0)
	for root != nil || len(p) != 0 {
		if root != nil {
			p = append(p, root)
			root = root.Left
		} else {
			node := p[len(p)-1]
			node.Left = nil
			p = p[:len(p)-1]
			pre.Left = nil
			pre.Right = node
			pre = pre.Right
			root = node.Right

		}
	}
	return q.Right
}
func main() {
	s := []int{4, 2, 5, 1, 3, -1, 6, 0}
	root := BuildTree(s, 0)
	convertBiNode(root)
}
