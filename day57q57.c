from collections import deque
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
def build_tree(arr):
    if not arr or arr[0] == -1:
        return None
    root = Node(arr[0])
    q = deque([root])
    i = 1    
    while q and i < len(arr):
        curr = q.popleft()     
        if arr[i] != -1:
            curr.left = Node(arr[i])
            q.append(curr.left)
        i += 1
        if i >= len(arr):
            break     
        if arr[i] != -1:
            curr.right = Node(arr[i])
            q.append(curr.right)
        i += 1
    return root
def mirror(root):
    if root is None:
        return None
    root.left, root.right = root.right, root.left
    mirror(root.left)
    mirror(root.right)
    return root
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)
n = int(input())
arr = list(map(int, input().split()))
root = build_tree(arr)
root = mirror(root)
inorder(root)
