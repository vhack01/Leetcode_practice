#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int k, int v)
    {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
    int capacity;
    unordered_map<int, Node *> umap;
    queue<int> q;
    Node *head = new Node(0, 0);
    Node *tail = new Node(0, 0);

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    Node *addNode(int key, int value)
    {
        Node *curr = new Node(key, value);
        Node *temp = head->next;
        head->next = curr;
        curr->next = temp;
        curr->prev = head;
        temp->prev = curr;
        return curr;
    }
    void deleteNode(Node *curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }

    int get(int key)
    {
        if (umap.find(key) != umap.end())
        {
            Node *curr = addNode(key, umap[key]->val);
            deleteNode(umap[key]);
            umap[key] = curr;
            return umap[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (umap.find(key) == umap.end())
        {
            // insert after head
            Node *curr = addNode(key, value);
            umap[key] = curr;

            if (umap.size() > capacity)
            {
                // Capacity is full
                // insert after head & delete least bofore tail
                umap.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
        }
        else
        {
            // update
            Node *curr = addNode(key, value);
            deleteNode(umap[key]);
            umap[key] = curr;
        }
    }
    void display()
    {
        cout << "display....." << endl;
        for (auto p : umap)
            cout << p.first << " : " << p.second->val << endl;
        cout << endl;
    }
    void traverse()
    {
        Node *curr = head;
        cout << "\nDLL" << endl;
        while (curr != NULL)
        {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    system("cls");
    LRUCache *lru = new LRUCache(3);
    lru->put(1, 1);
    lru->put(2, 2);
    lru->put(3, 3);
    lru->put(4, 4);
    lru->display();
    cout << "result: " << lru->get(4) << endl;
    cout << "result: " << lru->get(3) << endl;
    lru->traverse();
    cout << "result: " << lru->get(2) << endl;
    lru->traverse();
    cout << "result: " << lru->get(1) << endl;
    lru->put(5, 5);
    lru->display();
    cout << "result: " << lru->get(1) << endl;
    cout << "result: " << lru->get(2) << endl;
    cout << "result: " << lru->get(3) << endl;
    cout << "result: " << lru->get(4) << endl;
    cout << "result: " << lru->get(5) << endl;
}