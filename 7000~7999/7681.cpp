#include <iostream>
#include <vector>
using namespace std;

#define MAXSIZE 9
#define MAXDLXCOL 324
#define MAXDLXROW 729

int matrix[MAXSIZE][MAXSIZE];
vector<vector<bool>> dlxMatrix;
vector<int> solution;
vector<vector<int>> rows;

struct node
{
    int row;
    int size;
    node* col;
    node* up;
    node* down;
    node* left;
    node* right;
};

void dlxCover(node* head)
{
    head->right->left = head->left;
    head->left->right = head->right;

    for (node* it = head->down; it != head; it = it->down)
    {
        for (node* jt = it->right; jt != it; jt = jt->right)
        {
            jt->down->up = jt->up;
            jt->up->down = jt->down;
            jt->col->size--;
        }
    }
}

void dlxUncover(node* head) {
    for (node* it = head->up; it != head; it = it->up) {
        for (node* jt = it->left; jt != it; jt = jt->left) {
            jt->down->up = jt;
            jt->up->down = jt;
            jt->col->size++;
        }
    }

    head->right->left = head;
    head->left->right = head;
}

bool dlxSearch(node* head, int k) {
    if (head->right == head) return true;
    node* ptr = nullptr;
    int low = 1000;
    for (node* it = head->right; it != head; it = it->right)
    {
        if (it->size < low)
        {
            if (it->size == 0)
                return false;
            low = it->size;
            ptr = it;
        }
    }

    dlxCover(ptr);

    if (ptr != nullptr)
    {
        for (node* it = ptr->down; it != ptr; it = it->down) {
            solution.push_back(it->row);
            for (node* jt = it->right; jt != it; jt = jt->right) {
                dlxCover(jt->col);
            }
            if (dlxSearch(head, k + 1)) return true;
            else {
                solution.pop_back();
                for (node* jt = it->left; jt != it; jt = jt->left) {
                    dlxUncover(jt->col);
                }
            }
        }
    }
    dlxUncover(ptr);
    return false;
}

void makeLinkedList()
{
    // column head ����
    vector<node> cols(MAXDLXCOL); // (1,1)~(9,9), (row1,1)~(row9,9), (col1,1)~(col9,9), (box1,1)~(box9,9)
    node base; // DLX�� base head node
    base.left = &cols[MAXDLXCOL - 1];
    base.right = &cols[0];
    for (int i = 0; i < MAXDLXCOL; i++)
    {
        cols[i].size = 0;
        cols[i].up = &cols[i];
        cols[i].down = &cols[i];
        if (i == 0)
            cols[i].left = &base;
        else
            cols[i].left = &cols[i - 1];
        if (i == MAXDLXCOL - 1)
            cols[i].right = &base;
        else
            cols[i].right = &cols[i + 1];
    }

    vector<node*> nodes; // ������ ��� ��忡 ���� ������ ���� (���α׷� ���� �� delete ����)
    for (int i = 0; i < dlxMatrix.size(); ++i)
    {
        node* lNode = nullptr;
        for (int j = 0; j < MAXDLXCOL; j++)
        {
            if (dlxMatrix[i][j]) // 0�� �ƴ� ĭ�� ���ؼ� ��� ����
            {
                node* nNode = new node;
                nNode->row = i;
                nNode->col = &cols[j];
                nNode->col->size++;

                nNode->up = nNode->col->up;
                nNode->down = nNode->col;
                nNode->col->up = nNode;
                nNode->up->down = nNode;

                if (lNode) // ���� ���� ���ʿ� node�� �̹� ���� ���
                {
                    nNode->left = lNode;
                    nNode->right = lNode->right; // ���� ���� ó�� ���� ����Ű�� �Ͽ� circular linked list ����
                    lNode->right->left = nNode; // ���� ���� ó�� ������ left�� nNode ����Ű�� ��
                    lNode->right = nNode;
                }
                else
                {
                    nNode->left = nNode;
                    nNode->right = nNode;
                }
                lNode = nNode;
                nodes.push_back(nNode);
            }
        }
    }
    dlxSearch(&base, 0);
    for (node* ptr : nodes) // nodes�� ���� ��� node�� ���� �޸� �Ҵ� ����
        delete ptr;
}

void printMatrix()
{
    for (int i : solution)
        matrix[rows[i][0]][rows[i][1]] = rows[i][2];
    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
            cout << matrix[i][j] + 1;
    }
    cout << "\n";
}

void solve()
{
    makeLinkedList();
    printMatrix();
}

void getMatrix()
{
    char ch;
    while (true)
    {
        dlxMatrix.clear();
        rows.clear();
        solution.clear();
        for (int i = 0; i < MAXSIZE; i++)
        {
            for (int j = 0; j < MAXSIZE; j++)
            {
                ch = cin.get();
                if ((49 <= ch) && (ch <= 57))
                {
                    ch -= 48; // ���� �Է� ���� ���ϴ� cin.get() ����
                    vector<bool> row(MAXDLXCOL, false);
                    row[i * 9 + j] = true; // �� ĭ
                    row[81 + i * 9 + ch - 1] = true; // ������
                    row[162 + j * 9 + ch - 1] = true; // ������
                    row[243 + (i / 3 * 3 + j / 3) * 9 + ch - 1] = true; // 3x3 �ڽ�
                    dlxMatrix.push_back(row);
                    vector<int> rowData = { i,j,ch - 1 };
                    rows.push_back(rowData);
                }
                else if (ch == '.')
                {
                    ch = 0;
                    for (int k = 0; k < MAXSIZE; k++)
                    {
                        vector<bool> row(MAXDLXCOL, false);
                        row[i * 9 + j] = true; // �� ĭ
                        row[81 + i * 9 + k] = true; // ������
                        row[162 + j * 9 + k] = true; // ������
                        row[243 + (i / 3 * 3 + j / 3) * 9 + k] = true; // 3x3 �ڽ�
                        dlxMatrix.push_back(row);
                        vector<int> rowData = { i,j,k };
                        rows.push_back(rowData);
                    }
                }
                else if (ch == '\n')
                {
                    j--; // '\n'�� ���� �ݺ�Ƚ�� ī��Ʈ x
                    continue;
                }
                else
                    return;
            }
        }
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getMatrix();

    return 0;
}