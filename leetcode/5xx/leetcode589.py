
#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 2/10/20
"""
给定一个二叉树，计算整个树的坡度。

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

整个树的坡度就是其所有节点的坡度之和。

示例:

输入:
         1
       /   \
      2     3
输出: 1
解释:
结点的坡度 2 : 0
结点的坡度 3 : 0
结点的坡度 1 : |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1
注意:

任何子树的结点的和不会超过32位整数的范围。
坡度的值不会超过32位整数的范围。

"""


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def preorder(self, root):
        result=[]
        if root:
            result.append(root.val)
            if(root.children):
                for item in root.children:
                    result += self.preorder(item)
        return result

if __name__ == '__main__':
    node5=Node(5,None)
    node6=Node(6,None)
    node4=Node(4,None)
    node2=Node(2,None)
    node3=Node(3,[node5,node6])
    node1=Node(1,[node3,node2,node4])

    s = Solution()
    print(s.preorder(node1))