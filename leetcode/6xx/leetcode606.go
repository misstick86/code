/*
@File    :   leetcode606.c
@Time    :   2020/03/23 17:45:43
@Author  :   xiaosongsong
@Desc    :   None

你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

示例 1:

输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。
示例 2:

输入: 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

输出: "1(2()(4))(3)"

解释: 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。


*/

package main

import "strconv"

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
func tree2str(root *TreeNode) string {
	s := ""
	if root == nil {
		return s
	}
	s = s + strconv.Itoa(root.Val)
	if root.Left == nil && root.Right == nil {
		return s
	}
	s = s + "(" + tree2str(root.Left) + ")"
	if root.Right != nil {

		s = s + "(" + tree2str(root.Right) + ")"
	}
	return s

}
func main() {
	node := []int{1, 2, 3, 4}
	root := BuildTree(node, 0)
	tree2str(root)
}
