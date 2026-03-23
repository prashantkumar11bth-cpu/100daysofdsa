class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, key):
    if root is None:
        return Node(key)
    
    if key < root.val:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
        
    return root

def LCA(root, n1, n2):
    while root:
        if n1 < root.val and n2 < root.val:
            root = root.left
        elif n1 > root.val and n2 > root.val:
            root = root.right
        else:
            return root.val

# Input
n = int(input())
arr = list(map(int, input().split()))
n1, n2 = map(int, input().split())

root = None
for x in arr:
    root = insert(root, x)

print(LCA(root, n1, n2))