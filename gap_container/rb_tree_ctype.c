#include "rb_tree_ctype.h"

void rb_tree_insert(rb_tree_t* tree, rb_tree_node_t* node)
{
    rb_tree_node_t **root, *sentinel;
    root = &tree->root;
    sentinel = tree->sentinel;
    // 当前节点是根结点，不需要调整
    if (sentinel == *root)
    {
        node->parent = NULL;
        node->left = sentinel;
        node->right = sentinel;
        *root = node;
        return;
    }

    // 具体逻辑插入
    tree->insert(*root, node, sentinel);

    while (node != *root && IS_RB_TREE_NODE_RED(node->parent))
    {
        if (node->parent == node->parent->parent->left)
        {
            rb_tree_node_t* tmp = node->parent->parent->right;
            if (IS_RB_TREE_NODE_RED(tmp))
            {
                SET_RB_TREE_NODE_BLACK(node->parent);
                SET_RB_TREE_NODE_BLACK(tmp);
                SET_RB_TREE_NODE_RED(node->parent->parent);
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    rb_tree_left_rotate(root, node, sentinel);
                }
                SET_RB_TREE_NODE_BLACK(node->parent);
                SET_RB_TREE_NODE_RED(node->parent->parent);
                rb_tree_right_rotate(root, node->parent->parent, sentinel);
            }
        }
        else
        {
            rb_tree_node_t* tmp = node->parent->parent->left;
            if (IS_RB_TREE_NODE_RED(tmp))
            {
                SET_RB_TREE_NODE_BLACK(node->parent);
                SET_RB_TREE_NODE_BLACK(tmp);
                SET_RB_TREE_NODE_RED(node->parent->parent);
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rb_tree_right_rotate(root, node, sentinel);
                }
                SET_RB_TREE_NODE_BLACK(node->parent);
                SET_RB_TREE_NODE_RED(node->parent->parent);
                rb_tree_left_rotate(root, node->parent, sentinel);
            }
        }
    }
    SET_RB_TREE_NODE_BLACK(*root);
}

void rb_tree_left_rotate(rb_tree_node_t** root, rb_tree_node_t* node, rb_tree_node_t* sentinel)
{
    rb_tree_node_t* right = node->right;
    node->right = right->left;
    if (right->left != sentinel)
    {
        right->left->parent = node;
    }
    right->left = node;
    right->parent = node->parent;
    if (node == *root)
    {
        *root = right;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = right;
    }
    else
    {
        node->parent->right = right;
    }
    node->parent = right;
}

void rb_tree_right_rotate(rb_tree_node_t** root, rb_tree_node_t* node, rb_tree_node_t* sentinel)
{
    rb_tree_node_t* left = node->left;
    node->left = left->right;
    if (left->right != sentinel)
    {
        left->right->parent = node;
    }
    left->right = node;
    left->parent = node->parent;
    if (node == *root)
    {
        *root = left;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = left;
    }
    else
    {
        node->parent->right = left;
    }
    node->parent = left;
}
