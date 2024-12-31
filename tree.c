#include <stdlib.h>
#include "tree.h"

// private functions
static tree_t *initDefaultNode(char*);

tree_t *initTreeLogic() {
    tree_t *root = malloc(sizeof(tree_t));
    root->data = malloc(sizeof(treeData_t));
    root->data->question = "Is it a domestic animal?";
    root->data->animal = NULL;
    root->yes = initDefaultNode("dog");
    root->no = initDefaultNode("eagle");
    return root;
}

static tree_t *initDefaultNode(char *animalName) {
    tree_t *node = malloc(sizeof(tree_t));
    node->data = malloc(sizeof(treeData_t));
    node->data->question = NULL;
    node->data->animal = animalName;
    node->yes = NULL;
    node->no = NULL;
    return node;
}