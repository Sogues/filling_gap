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

void rb_tree_delete(rb_tree_t* tree, rb_tree_node_t* node)
{
    rb_tree_node_t **root, *sentinel, *del, *replace, *tmp;
    int red;
    root = &tree->root;
    sentinel = tree->sentinel;

    if (sentinel == node->left)
    {
        del = node;
        replace = node->right;
    }
    else if (sentinel == node->right)
    {
        del = node;
        replace = node->left;
    }
    else
    {
        del = rb_tree_min_right(node->right, sentinel);
        replace = del->right;
    }

    if (*root == del)
    {
        *root = replace;
        SET_RB_TREE_NODE_BLACK(replace);
        replace->parent = NULL;
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;
        node->key = NULL;
        return;
    }

    red = IS_RB_TREE_NODE_RED(del);

    if (del == del->parent->left)
    {
        del->parent->left = replace;
    }
    else
    {
        del->parent->right = replace;
    }

    if (del == node)
    {
        replace->parent = del->parent;
    }
    else
    {
        /// 避免父节点是要删除的节点
        if (node == del->parent)
        {
            replace->parent = del;
        }
        else
        {
            replace->parent = del->parent;
        }

        del->parent = node->parent;
        del->left = node->left;
        del->right = node->right;
        RB_TREE_COPY_COLOR(del, node);

        if (node == *root)
        {
            *root = replace;
        }
        else
        {
            if (node == node->parent->left)
            {
                node->parent->left = del;
            }
            else
            {
                node->parent->right - del;
            }
        }

        if (sentinel != del->left)
        {
            del->left->parent = del;
        }
        if (sentinel != del->right)
        {
            del->right->parent = del;
        }
    }

    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->key = NULL;
    if (red)
    {
        return;
    }

    while (replace != root && !IS_RB_TREE_NODE_RED(replace))
    {
        if (replace == replace->parent->left)
        {
            tmp = replace->parent->right;
            if (IS_RB_TREE_NODE_RED(tmp))
            {
                SET_RB_TREE_NODE_BLACK(tmp);
                SET_RB_TREE_NODE_RED(replace->parent);
                rb_tree_left_rotate(root, replace->parent, sentinel);
                tmp = replace->parent->right;
            }
            if (!IS_RB_TREE_NODE_RED(tmp->left) && !IS_RB_TREE_NODE_RED(tmp->right))
            {
                SET_RB_TREE_NODE_RED(tmp);
                replace = replace->parent;
            }
            else
            {
                if (IS_RB_TREE_NODE_RED(tmp->left))
                {
                    SET_RB_TREE_NODE_BLACK(tmp->left);
                    SET_RB_TREE_NODE_RED(tmp);
                    rb_tree_right_rotate(root, tmp, sentinel);
                    tmp = replace->parent->right;
                }
                RB_TREE_COPY_COLOR(tmp, replace->parent);
                SET_RB_TREE_NODE_BLACK(replace->parent);
                SET_RB_TREE_NODE_BLACK(tmp->right);
                rb_tree_left_rotate(root, replace->parent, sentinel);
                replace = *root;
            }
        }
        else
        {
            tmp = replace->parent->left;
            if (IS_RB_TREE_NODE_RED(tmp))
            {
                SET_RB_TREE_NODE_BLACK(tmp);
                SET_RB_TREE_NODE_RED(replace->parent);
                rb_tree_right_rotate(root, replace->parent, sentinel);
                tmp = replace->parent->left;
            }
            if (!IS_RB_TREE_NODE_RED(tmp->left) && !IS_RB_TREE_NODE_RED(tmp->right))
            {
                SET_RB_TREE_NODE_RED(tmp);
                replace = replace->parent;
            }
            else
            {
                if (IS_RB_TREE_NODE_RED(tmp->right))
                {
                    SET_RB_TREE_NODE_BLACK(tmp->right);
                    SET_RB_TREE_NODE_RED(tmp);
                    rb_tree_left_rotate(root, replace->parent, sentinel);
                    tmp = replace->parent->left;
                }
                RB_TREE_COPY_COLOR(tmp, replace->parent);
                SET_RB_TREE_NODE_BLACK(replace->parent);
                SET_RB_TREE_NODE_BLACK(tmp->left);
                rb_tree_right_rotate(root, tmp->parent, sentinel);
                replace = *root;
            }
        }
    }
    SET_RB_TREE_NODE_BLACK(replace);
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

rb_tree_node_t* rb_tree_min_right(rb_tree_node_t* node, rb_tree_node_t* sentinel)
{
    while (sentinel != node->left)
    {
        node = node->left;
    }
    return node;
}
