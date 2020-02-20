
#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 2/10/20

'''
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

 

返回其后序遍历: [5,6,3,2,4,1].

说明: 递归法很简单，你可以使用迭代法完成此题吗?

'''


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def postorder(self, root):
        result=[]
        if root:

            if(root.children):
                for item in root.children:
                    result += self.postorder(item)
            result.append(root.val)
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