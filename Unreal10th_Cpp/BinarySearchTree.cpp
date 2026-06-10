#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::~BinarySearchTree()
{
    DestroyTree(Root);
}

void BinarySearchTree::Insert(int InKey)
{
    Root = InsertNode(Root, InKey);
}

void BinarySearchTree::Delete(int InKey)
{
    Root = DeleteNode(Root, InKey);
}

TreeNode* BinarySearchTree::Search(int InKey)
{
    return SearchNode(Root, InKey);
}

void BinarySearchTree::PrintPreOrder() const
{
    printf("PreOrder : ");
    PreOrderTraversal(Root);
    printf("\n");
}

void BinarySearchTree::PrintInOrder() const
{
    printf("InOrder : ");
    InOrderTraversal(Root);
    printf("\n");
}

void BinarySearchTree::PrintPostOrder() const
{
    printf("PostOrder : ");
    PostOrderTraversal(Root);
    printf("\n");
}

TreeNode* BinarySearchTree::InsertNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return new TreeNode(InKey);
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = InsertNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = InsertNode(InNode->Right, InKey);
    }
    else
    {
        // 이진 탐색 트리에서는 키가 중복되면 안된다
        // 중복된 키는 무시
    }

    return InNode;
}

TreeNode* BinarySearchTree::DeleteNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return InNode;
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = DeleteNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = DeleteNode(InNode->Right, InKey);
    }
    else
    {
        // 삭제할 노드를 찾음
        if (InNode->Left == nullptr)
        {
            TreeNode* temp = InNode->Right;
            delete InNode;
            return temp;
        }
        else if (InNode->Right == nullptr)
        {
            TreeNode* temp = InNode->Left;
            delete InNode;
            return temp;
        }

        // 두 자식이 모두 있는 경우 - 오른쪽 서브트리의 최소값으로 대체
        TreeNode* temp = FindMinNode(InNode->Right);
        InNode->Key = temp->Key; // 오른쪽 서브트리의 최소값 노드와 교체
        InNode->Right = DeleteNode(InNode->Right, temp->Key); // 오른쪽 서브트리의 최소값 노드 제거
    }

    return InNode;
}

TreeNode* BinarySearchTree::SearchNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return nullptr;
    }

    if (InKey < InNode->Key)
    {
        return SearchNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        return SearchNode(InNode->Right, InKey);
    }
    else
    {
        return InNode;
    }
}

TreeNode* BinarySearchTree::FindMinNode(TreeNode* InNode)
{
    while (InNode != nullptr && InNode->Left != nullptr)
    {
        InNode = InNode->Left;
    }

    return InNode;
}

void BinarySearchTree::PreOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        printf("%d ", InNode->Key);
        PreOrderTraversal(InNode->Left);
        PreOrderTraversal(InNode->Right);
    }
}

void BinarySearchTree::InOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        InOrderTraversal(InNode->Left);
        printf("%d ", InNode->Key);
        InOrderTraversal(InNode->Right);
    }
}

void BinarySearchTree::PostOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        PostOrderTraversal(InNode->Left);
        PostOrderTraversal(InNode->Right);
        printf("%d ", InNode->Key);
    }
}

void BinarySearchTree::DestroyTree(TreeNode* InNode)
{
    if (InNode != nullptr)
    {
        // 후위 순회 방식으로 서브트리 제거
        DestroyTree(InNode->Left);
        DestroyTree(InNode->Right);
        delete InNode;
    }
}
