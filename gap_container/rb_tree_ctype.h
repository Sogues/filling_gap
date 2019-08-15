#ifndef RB_TREE_CTYPE_H
#define RB_TREE_CTYPE_H

typedef rb_tree_node_s rb_tree_node_t;
typedef rb_tree_s rb_tree_t;

typedef int rb_node_color_t;

#define rb_node_color_Black 0
#define rb_node_color_red 1

typedef void (*rb_tree_insert_pt)(rb_tree_node_t* root, rb_tree_node_t* node, rb_tree_node_t* sentinel);

typedef struct
{
    void* key;
    rb_tree_node_t* parent;
    rb_tree_node_t* left;
    rb_tree_node_t* right;
    rb_node_color_t color;
} rb_tree_node_s;

typedef struct
{
    rb_tree_node_t* root;
    rb_tree_node_t* sentinel;
    rb_tree_insert_pt insert;
} rb_tree_s;

#define INIT_RB_TREE_NODE(node) (node)->color = rb_node_color_Black

#define INIT_RB_TREE(tree, node, insert) \
    INIT_RB_TREE_NODE(node);             \
    (tree)->root = (node);               \
    (tree)->sentinel = (node);           \
    (tree)->insert = (insert);

#define IS_RB_TREE_NODE_RED(node) ((node)->color == rb_node_color_red)
#define SET_RB_TREE_NODE_RED(node) (node)->color = rb_node_color_red
#define SET_RB_TREE_NODE_BLACK(node) (node)->color = rb_node_color_Black
#define RB_TREE_COPY_COLOR(from, to) (to)->color = (from)->color

void rb_tree_insert(rb_tree_t* tree, rb_tree_node_t* node);
void rb_tree_delete(rb_tree_t* tree, rb_tree_node_t* node);
#endif