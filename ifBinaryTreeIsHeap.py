from collections import deque

def isHeap(root):
    q = deque()
    q.append(root)
    flag = True
    while q:
        node = q.popleft()
        if flag == False:
            return flag
        if node.left:
            q.append(node.left)
            if node.data < node.left.data:
                flag = False
        if node.right:
            q.append(node.right)
            if node.data < node.right.data:
                flag = False

    return flag
