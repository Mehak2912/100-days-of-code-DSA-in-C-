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
def is_mirror(t1, t2):
    if not t1 and not t2:
        return True
    if not t1 or not t2:
        return False
    return (t1.val == t2.val and
            is_mirror(t1.left, t2.right) and
            is_mirror(t1.right, t2.left))
def is_symmetric(root):
    return is_mirror(root, root)
n = int(input())
arr = list(map(int, input().split()))
root = build_tree(arr)
if is_symmetric(root):
    print("YES")
else:
    print("NO")
