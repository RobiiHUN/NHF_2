#include "base.hpp"

/* 
struct Node {
    Bejegyzes data;
    Node* left;
    Node* right;

    Node(Bejegyzes d) : data(d), left(nullptr), right(nullptr) {}
};

class KeresoFa {
private:
    Node* root;

    Node* insert(Node* node, Bejegyzes bejegyzes) {
        if (node == nullptr) {
            return new Node(bejegyzes);
        }

        if (bejegyzes.getKereszt() < node->data.getKereszt()) {
            node->left = insert(node->left, bejegyzes);
        } else if (bejegyzes.getKereszt() > node->data.getKereszt()) {
            node->right = insert(node->right, bejegyzes);
        }

        return node;
    }

    Bejegyzes* search(Node* node, std::string keresztnev) {
        if (node == nullptr || node->data.getKereszt() == keresztnev) {
            return &node->data;
        }

        if (node->data.getKereszt() < keresztnev) {
            return search(node->right, keresztnev);
        }

        return search(node->left, keresztnev);
    }
    bool search_benne(Node* node, std::string keresztnev) {
        if (node == nullptr) {
            return false;  // A keresett keresztnév nem található a fában
        }

        if (node->data.getKereszt() == keresztnev) {
            return true;  // A keresett keresztnév megtalálva
        }

public:
    KeresoFa() : root(nullptr) {}

    void insert(Bejegyzes bejegyzes) {
        root = insert(root, bejegyzes);
    }

    Bejegyzes* search(std::string keresztnev) {
        return search(root, keresztnev);
    }
};
 */

//TODO ez nem megy