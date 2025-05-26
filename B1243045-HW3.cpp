//B1243045 陳品嶧
//輸入方式為簡單版:數值然後空格再不斷循環enter為結束
#include <iostream>
#include <vector>
using namespace std;

typedef struct position {
    float con;
    int exp;
    position *next;
} pos;

void add_items(pos *head, float con, int exp);
void show_function(pos *head);
void add(pos *a, pos *b, pos *c);
void input_poly(pos *head);

int main() {
    pos *A = new pos;
    pos *B = new pos;
    pos *C = new pos;

    A->next = NULL;
    B->next = NULL;
    C->next = NULL;

    cout << "inputA(x): ";
    input_poly(A);

    cout << "inputB(x): ";
    input_poly(B);

    cout << "A(x) = ";
    show_function(A);
    cout << "\n";

    cout << "B(x) = ";
    show_function(B);
    cout << "\n";

    add(A, B, C);

    cout << "C(x) = ";
    show_function(C);
    cout << "\n";

    return 0;
}

void input_poly(pos *head) {
    vector<float> values;
    float num;

    while (cin.peek() != '\n') {
        cin >> num;
        values.push_back(num);
    }
    cin.ignore();

    if (values.size() % 2 != 0) {
        cout << "input error!\n";
        return;
    }

    for (size_t i = 0; i < values.size(); i += 2) {
        add_items(head, values[i], (int)values[i + 1]);
    }
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
    pos *ptr = head->next;
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
