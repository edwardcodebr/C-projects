RED = True
BLACK = False


class RBNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None
        self.color = RED


class RBTree:

    def __init__(self):
        self.NIL = RBNode(0)
        self.NIL.color = BLACK
        self.root = self.NIL

    def left_rotate(self, x):

        y = x.right
        x.right = y.left

        if y.left != self.NIL:
            y.left.parent = x

        y.parent = x.parent

        if x.parent is None:
            self.root = y

        elif x == x.parent.left:
            x.parent.left = y

        else:
            x.parent.right = y

        y.left = x
        x.parent = y

    def right_rotate(self, y):

        x = y.left
        y.left = x.right

        if x.right != self.NIL:
            x.right.parent = y

        x.parent = y.parent

        if y.parent is None:
            self.root = x

        elif y == y.parent.right:
            y.parent.right = x

        else:
            y.parent.left = x

        x.right = y
        y.parent = x

    def insert(self, key):

        node = RBNode(key)

        node.parent = None
        node.left = self.NIL
        node.right = self.NIL
        node.color = RED

        y = None
        x = self.root

        while x != self.NIL:

            y = x

            if node.key < x.key:
                x = x.left
            else:
                x = x.right

        node.parent = y

        if y is None:
            self.root = node

        elif node.key < y.key:
            y.left = node

        else:
            y.right = node

        if node.parent is None:
            node.color = BLACK
            return

        if node.parent.parent is None:
            return

        self.fix_insert(node)

    def fix_insert(self, k):

        while k.parent.color == RED:

            if k.parent == k.parent.parent.right:

                u = k.parent.parent.left

                if u.color == RED:

                    u.color = BLACK
                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    k = k.parent.parent

                else:

                    if k == k.parent.left:
                        k = k.parent
                        self.right_rotate(k)

                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    self.left_rotate(k.parent.parent)

            else:

                u = k.parent.parent.right

                if u.color == RED:

                    u.color = BLACK
                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    k = k.parent.parent

                else:

                    if k == k.parent.right:
                        k = k.parent
                        self.left_rotate(k)

                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    self.right_rotate(k.parent.parent)

            if k == self.root:
                break

        self.root.color = BLACK

    def search(self, node, key):

        if node == self.NIL or key == node.key:
            return node

        if key < node.key:
            return self.search(node.left, key)

        return self.search(node.right, key)
