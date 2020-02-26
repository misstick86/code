
#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 2/10/20
'''
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :

我们应返回其最大深度，3。

说明:

树的深度不会超过 1000。
树的节点总不会超过 5000。

'''


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root == None:
            return 0
        if root.children == None:
            return 1
        max_depth = 0
        for item in root.children:
            length = self.maxDepth(item)
            max_depth = max_depth if max_depth> length else length;
        return max_depth +1
