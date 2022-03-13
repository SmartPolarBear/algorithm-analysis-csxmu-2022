from typing import Optional


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.heights = dict()

    def height(self, root: 'TreeNode', anc: Optional[TreeNode], h):
        root.ancestor = anc
        self.heights[root] = h

        if root.left is not None:
            self.height(root.left, root, h + 1)

        if root.right is not None:
            self.height(root.right, root, h + 1)

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.height(root, None, 1)

        if self.heights[p] == self.heights[q]:
            while p.val != q.val:
                p = p.ancestor
                q = q.ancestor

            return p

        (low, high, high_h) = (p, q, self.heights[q]) if self.heights[p] > self.heights[q] else (q, p, self.heights[p])

        while self.heights[low] > high_h:
            low = low.ancestor

        while not (low is None) and not (high is None) and low.val != high.val:
            low = low.ancestor
            high = high.ancestor

        return low
