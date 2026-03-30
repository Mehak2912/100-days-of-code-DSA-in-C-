class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
def buildTree(preorder, inorder):
    if not preorder or not inorder:
        return None
    root_val = preorder[0]
    root = Node(root_val)
    mid = inorder.index(root_val)
    root.left = buildTree(preorder[1:mid+1], inorder[:mid])
    root.right = buildTree(preorder[mid+1:], inorder[mid+1:])
    return root
def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.val, end=" ")
n = int(input())
preorder = list(map(int, input().split()))
inorder = list(map(int, input().split()))
root = buildTree(preorder, inorder)
postorder(root)
