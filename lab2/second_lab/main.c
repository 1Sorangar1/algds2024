#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert_node(struct node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert_node(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert_node(root->right, value);
    }
    return root;
}

struct node* search(struct node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

struct node* find_min(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* delete_node(struct node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->value) {
        root->right = delete_node(root->right, value);
    }
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = find_min(root->right);
        root->value = temp->value;
        root->right = delete_node(root->right, temp->value);
    }
    return root;
}
