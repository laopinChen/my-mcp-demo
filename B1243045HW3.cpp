#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct position {
    float con;
    int exp;
    position *next;
} pos;

void add_items(pos *head, float con, int exp);
void show_function(pos *head);
void add(pos *a,pos *b,pos *c);
void input_poly(pos *a);

int main() {
    pos *A = new pos;
    pos *B = new pos;
    pos *C = new pos;

    A->next = NULL;
    B->next = NULL;
    C->next = NULL;

    cout << "請輸入A(x)";
    input_poly(A);
    cout << "請輸入B(x)";
    input_poly(B);

    cout << "A(x) = ";
    show_function(A);
    cout << "\n";

    cout << "B(x) = ";
    show_function(B);
    cout << "\n";

    add(A,B,C);

    cout << "C(x) = ";
    show_function(C);
    cout << "\n";

    return 0;
}

void input_poly(pos *head) {
    float con;
    int exp;
    cout << "(格式：係數 次方 係數 次方 ...，以 -999 結束): ";
    while (cin >> con && con != -999) {
        cin >> exp;
        add_items(head, con, exp);
    }
    cin.clear(); cin.ignore(1000, '\n'); // 清除殘留輸入
}

void add_items(pos *head, float con, int exp) {
    pos *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    pos *newNode = new pos;
    newNode->con = con;
    newNode->exp = exp;
    newNode->next = NULL;
    ptr->next = newNode;
}

void show_function(pos *head) {
    pos *ptr = head->next;  // 跳過頭節點
    while (ptr != NULL) {
        cout << ptr->con << "X^" << ptr->exp;
        if (ptr->next != NULL)
            cout << " + ";
        ptr = ptr->next;
    }
}

void add(pos *a, pos *b, pos *c) {
    a = a->next;
    b = b->next;
    pos *ptrC = c;

    while (a != NULL || b != NULL) {
        float sum_con;
        int exp;

        if (a == NULL) {
            sum_con = b->con;
            exp = b->exp;
            b = b->next;
        } else if (b == NULL) {
            sum_con = a->con;
            exp = a->exp;
            a = a->next;
        } else if (a->exp == b->exp) {
            sum_con = a->con + b->con;
            exp = a->exp;
            a = a->next;
            b = b->next;
        } else if (a->exp > b->exp) {
            sum_con = a->con;
            exp = a->exp;
            a = a->next;
        } else {
            sum_con = b->con;
            exp = b->exp;
            b = b->next;
        }
        if (sum_con != 0) {
            pos *newNode = new pos;
            newNode->con = sum_con;
            newNode->exp = exp;
            newNode->next = NULL;
            ptrC->next = newNode;
            ptrC = newNode;
        }
    }
}
