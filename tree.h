#ifndef TREE_H
#define TREE_H

typedef struct 
{
    char *question;
    char *animal;
} treeData_t;

typedef struct tree { 
    treeData_t *data;
    struct tree *yes;
    struct tree *no;
} tree_t;

// global functions
tree_t *initTreeLogic(void);

#endif
