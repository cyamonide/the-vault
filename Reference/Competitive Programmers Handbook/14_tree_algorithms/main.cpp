#include <iostream>

using namespace std;

// Binary tree struct
struct Tree {
    // Cargo of this node
    char cargo;
    // Left child
    Tree *left;
    // Right child
    Tree *right;
};

/**
 * Recursively calculates sum of tree's children
 * @param tree Root node to begin sum
 * @return sum of nodes below tree
 */
int total(Tree *tree) {
    if (tree == nullptr) {
        return 0;
    }
    return total(tree->left) + total(tree->right) + tree->cargo;
}

void print_tree_preorder(Tree *tree) {
    if (tree == nullptr) return;
    printf("%c ", tree->cargo);
    print_tree_preorder(tree->left);
    print_tree_preorder(tree->right);
}

void print_tree_postorder(Tree *tree) {
    if (tree == nullptr) return;
    print_tree_postorder(tree->left);
    print_tree_postorder(tree->right);
    printf("%c ", tree->cargo);
}

void print_tree_inorder(Tree *tree) {
    if (tree == nullptr) return;
    print_tree_inorder(tree->left);
    printf("%c ", tree->cargo);
    print_tree_inorder(tree->right);
}

int main()
{
    Tree t1 = {'2', nullptr, nullptr};
    Tree t2 = {'3', nullptr, nullptr};
    Tree t3 = {'*', &t1, &t2};
    Tree t4 = {'1', nullptr, nullptr};
    Tree t5 = {'+', &t4, &t3};

    print_tree_preorder(&t5);
    printf("\n");
    print_tree_postorder(&t5);
    printf("\n");
    print_tree_inorder(&t5);
    printf("\n");

    cout << "Hello world!" << endl;
    return 0;
}
