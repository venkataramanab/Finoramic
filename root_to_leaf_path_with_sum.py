# Created by venkataramana on 09/02/18.
# https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
# Root to Leaf Paths With Sum
# Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.
#
# For example:
# Given the below binary tree and sum = 22,
# return [
# [5,4,11,2],
# [5,8,4,5]
# ]
class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def getTree():
    n5, n4, n11, n7, n2, n8, n13, _n4, _n5, _n1 = Node(5), Node(4), Node(11), Node(7), Node(2), Node(8), Node(13), Node(
        4), Node(5), Node(1)
    n5.left = n4
    n5.right = n8
    n4.left = n11
    n11.left = n7
    n11.right = n2
    n8.left = n13
    n8.right = _n4
    _n4.left = _n5
    _n4.right = _n1
    return n5


def init():
    root = getTree()
    print printTree(root, 22)


def printTree(node, tar_sum):
    if node is None:
        return None
    left = printTree(node.left, tar_sum - node.data)
    right = printTree(node.right, tar_sum - node.data)
    if left is None and right is None and tar_sum == node.data:
        return [node.data]
    if left and right:
        left.insert(0, node.data)
        right.insert(0, node.data)
        return [left, right]
    if left:
        left.insert(0, node.data)
        return left
    if right:
        right.insert(0, node.data)
        return right
    return None


if __name__ == "__main__":
    init()
