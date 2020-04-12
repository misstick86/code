#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 2/10/20

'''

N叉树的前 hou序遍历
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def preorder(self, root):
        result=[]
        if root:

            if(root.children):
                for item in root.children:
                    result += self.preorder(item)
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


N   叉树的最大深度



class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root == None:
            return 0;
        if root.children == None:
            return 1
        max_depth = 0
        for item in root.children:
            length = self.maxDepth(item)
            max_depth = max_depth if max_depth> length else length;
        return max_depth +1



if __name__ == '__main__':
    node5=Node(5,None)
    node6=Node(6,None)
    node4=Node(4,None)
    node2=Node(2,None)
    node3=Node(3,[node5,node6])
    node1=Node(1,[node3,node2,node4])

    s = Solution()
    print(s.maxDepth(node1))

'''
'''
 N叉树的层序遍历
'''


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:

    def levelOrder(self, root: 'Node'):
        pass
if __name__ == '__main__':
    node5=Node(5,None)
    node6=Node(6,None)
    node4=Node(4,None)
    node2=Node(2,None)
    node3=Node(3,[node5,node6])
    node1=Node(1,[node3,node2,node4])

    s= Solution()
    print(s.levelOrder(node1))