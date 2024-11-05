class Node:
    def __init__(self, str_value, is_end_of_word):
        self.children = [None] * 26
        self.str = str_value
        self.is_end_of_word = is_end_of_word

class Trie:
    root = None

    @staticmethod
    def setup(strs):
        Trie.root = Trie.build_trie(strs)

    @staticmethod
    def build_trie(strs):
        root = Node("", False)
        for s in strs:
            ref = root
            for c in s:
                index = ord(c) - ord('a')
                if ref.children[index] is None:
                    ref.children[index] = Node("", False)
                ref = ref.children[index]
            ref.is_end_of_word = True
            ref.str = s
        return root

    @staticmethod
    def is_member(word):
        return Trie.checkMember(Trie.root, word, 0)

    @staticmethod
    def checkMember(root, s, index):
        if root is None:
            return False
        if index == len(s):
            return root.is_end_of_word
        c = s[index]
        if c == '*':
            for node in root.children:
                if Trie.checkMember(node, s, index + 1):
                    return True
        else:
            node = root.children[ord(c) - ord('a')]
            if Trie.checkMember(node, s, index + 1):
                return True
        return False

if __name__ == "__main__":
    strs = ["foo", "bar", "baz"]
    Trie.setup(strs)
    is_member = Trie.is_member("f*o")
    print(is_member)

