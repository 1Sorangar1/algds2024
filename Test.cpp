#include "Head.h"
#include "main.c"

TEST(CreateNode, Create_node) {
    struct Node* root = create_node(5);

    EXPECT_EQ(root->data, 5);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);

    free(root);
}

TEST(InsertNode, Insert_node) {
    struct Node* root = NULL;
    root = insert_node(root, 5);
    insert_node(root, 2);
    insert_node(root, 6);

    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, 5);
    EXPECT_NE(root->left, nullptr);
    EXPECT_EQ(root->left->data, 2);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->data, 6);

    free(root);
}

TEST(search1, Node_Found) {
    struct Node* root = NULL;
    root = insert_node(root, 5);
    root = insert_node(root, 3);
    root = insert_node(root, 7);

    EXPECT_NE(search(root, 5), nullptr);
}

TEST(search2, Node_not_Found) {
    struct Node* root = NULL;
    root = insert_node(root, 5);
    root = insert_node(root, 3);
    root = insert_node(root, 7);

    EXPECT_EQ(search(root, 4), nullptr);
}

TEST(FindMin, Find_min) {
    struct Node* root = NULL;
    root = insert_node(root, 6);
    root = insert_node(root, 2);
    root = insert_node(root, 8);

    struct Node* minNode = find_min(root);

    EXPECT_NE(minNode, nullptr);
    EXPECT_EQ(minNode->data, 2);

    free(root);
    free(minNode);
}

TEST(DeleteNode1, Delete_node) {
    struct Node* root = NULL;
    root = insert_node(root, 6);
    root = insert_node(root, 2);
    root = insert_node(root, 8);

    root = delete_node(root, 2);

    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, 6);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->data, 8);

    free(root);
}

TEST(DeleteNode2, Delete_Node_From_Empty_Tree) {
    struct Node* root = NULL;
    root = delete_node(root, 2);

    EXPECT_EQ(root, nullptr);

    free(root);
}