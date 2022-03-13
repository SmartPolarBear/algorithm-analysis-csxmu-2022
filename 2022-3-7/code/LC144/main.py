# Definition for a binary tree node.
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.list = []

    def traversal(self, root: Optional[TreeNode]):
        if root is None:
            return

        self.list.append(root.val)
        self.traversal(root.left)
        self.traversal(root.right)

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.traversal(root)
        return self.list
