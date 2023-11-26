#include <iostream>
#include <vector>
using namespace std;

#define MAXSIZE 16
#define MAXDLXCOL 1024 // 16*16*4
#define MAXDLXROW 4096 // (1,1,1) ~ (16,16,16)

char matrix[MAXSIZE][MAXSIZE];
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

void dlxUncover(node* head) 
{
    for (node* it = head->up; it != head; it = it->up) 
    {
        for (node* jt = it->left; jt != it; jt = jt->left) 
        {
            jt->down->up = jt;
            jt->up->down = jt;
            jt->col->size++;
        }
    }

    head->right->left = head;
    head->left->right = head;
}

bool dlxSearch(node* head) 
{
    if (head->right == head) return true;
    node* ptr = nullptr;
    int low = MAXDLXROW + 1;
    int cnt = 0;
    for (node* it = head->right; it != head; it = it->right)
    {
        cnt++;
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
        for (node* it = ptr->down; it != ptr; it = it->down) 
        {
            solution.push_back(it->row);
            for (node* jt = it->right; jt != it; jt = jt->right) 
                dlxCover(jt->col);
            if (dlxSearch(head))
                return true;
            else 
            {
                solution.pop_back();
                for (node* jt = it->left; jt != it; jt = jt->left)
                    dlxUncover(jt->col);
            }
        }
    }
    dlxUncover(ptr);
    return false;
}

void makeLinkedList()
{
    // column head 생성
    vector<node> cols(MAXDLXCOL); // (1,1)~(16,16), (row1,1)~(row16,16), (col1,1)~(col16,16), (box1,1)~(box16,16)
    node base; // DLX의 base head node
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

    vector<node*> nodes; // 생성한 모든 노드에 대한 포인터 저장 (프로그램 종료 시 delete 위해)
    for (int i = 0; i < dlxMatrix.size(); i++)
    {
        node* lNode = nullptr;
        for (int j = 0; j < MAXDLXCOL; j++)
        {
            if (dlxMatrix[i][j]) // 0이 아닌 칸에 대해서 노드 생성
            {
                node* nNode = new node;
                nNode->row = i;
                nNode->col = &cols[j];
                nNode->col->size++;

                nNode->up = nNode->col->up;
                nNode->down = nNode->col;
                nNode->col->up = nNode;
                nNode->up->down = nNode;

                if (lNode) // 같은 행의 왼쪽에 node가 이미 있을 경우
                {
                    nNode->left = lNode;
                    nNode->right = lNode->right; // 행의 가장 처음 원소 가리키게 하여 circular linked list 구현
                    lNode->right->left = nNode; // 행의 가장 처음 원소의 left가 nNode 가리키게 함
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
    dlxSearch(&base);
    for (node* ptr : nodes) // nodes에 속한 모든 node에 대해 메모리 할당 해제
        delete ptr;
}

void printMatrix()
{
    for (int i : solution)
        matrix[rows[i][0]][rows[i][1]] = rows[i][2];
    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
            cout << (char)(matrix[i][j]+'A');
        cout << "\n";
    }
}

void solve()
{
    makeLinkedList();
    printMatrix();
}

void getMatrix()
{
    char ch;
    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
        {
            ch = cin.get();
            if (ch == '-')
            {
                for (int k = 0; k < MAXSIZE; k++)
                {
                    vector<bool> row(MAXDLXCOL, false);
                    row[i * 16 + j] = true; // 각 칸
                    row[256 + i * 16 + k] = true; // 가로줄
                    row[512 + j * 16 + k] = true; // 세로줄
                    row[768 + (i / 4 * 4 + j / 4) * 16 + k] = true; // 4x4 박스
                    dlxMatrix.push_back(row);
                    vector<int> rowData = { i,j,k };
                    rows.push_back(rowData);
                }
            }
            else if (ch == '\n')
            {
                j--; // '\n'에 사용된 반복횟수 카운트 x
                continue;
            }
            else
            {
                ch -= 'A';
                vector<bool> row(MAXDLXCOL, false);
                row[i * 16 + j] = true; // 각 칸
                row[256 + i * 16 + ch] = true; // 가로줄
                row[512 + j * 16 + ch] = true; // 세로줄
                row[768 + (i / 4 * 4 + j / 4) * 16 + ch] = true; // 4x4 박스
                dlxMatrix.push_back(row);
                vector<int> rowData = { i,j,ch };
                rows.push_back(rowData);
            }
        }
    }
    solve();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getMatrix();

    return 0;
}