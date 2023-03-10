#include <iostream>
#include<string>
using namespace std;


class list
{
public:
    list* next;
    list* previous;
    int id = 0;
    int data;
};


class contener
{
public:
    list* head = NULL;
    list* tail = NULL;
    int count;
};


void dodajprzod(contener& neew, int NewElement)
{
    if (neew.head == NULL)
    {
        list* a = new list;
        a->data = NewElement;
        a->next = NULL;
        a->previous = NULL;
        neew.head = a;
        neew.tail = a;
    }
    else if (neew.head != NULL)
    {
        list* a = new list;
        a->data = NewElement;
        a->previous = NULL;
        a->next = neew.head;
        neew.head = a;
    }
}

void dodajtyl(contener& neew, int NewElement)
{
    if (neew.tail == NULL)
    {
        list* a = new list;
        a->data = NewElement;
        a->next = NULL;
        a->previous = NULL;
        neew.head = a;
        neew.tail = a;
    }
    else if (neew.tail != NULL)
    {
        list* a = new list;
        a->data = NewElement;
        a->previous = neew.tail;
        a->previous->next = a;
        a->next = NULL;
        neew.tail = a;
    }
}


int display(contener& nowe) {
    list* c = new list;
    int g = 0;
    int n = 0;
    int count = 1;
    c = nowe.head;
    if (nowe.head == NULL || nowe.tail == NULL)
    {
        cout << "Lista jest pusta" << endl;
    }
    else {
        while (n != 1) {

            cout << g << ":" << c->data << endl;
            if (c->next == NULL) {
                n = 1;


            }
            else {
                c = c->next;
                g++;
                count++;
            }

        }

    }
    return count;
}
void usunT(contener& neew) {
    list* c = new list;
    if (neew.head == NULL && neew.tail == NULL)
    {
        cout << "Lista jest pusta";
    }
    else {

        list* c = new list;
        c = neew.head;
        while (c->next->next != NULL)
        {
            c = c->next;
        }
        delete(c->next);
        c->next = NULL;
    }
};

void usunP(contener& neew)
{
    list* c = new list;
    if (neew.head == NULL && neew.tail == NULL)
    {
        cout << "Lista jest pusta";

    }
    else
    {
        list* c = new list;
        list* tmp;
        tmp = (neew.head)->next;
        delete(neew.head);
        neew.head = tmp;
        neew.head->previous = NULL;
    }


}


void usun(contener& neew) {
    int n = 0;
    int g = 0;
    list* c = new list;
    list* tmp;
    int licz = 0;

    while (n != 1) {


        if (neew.head == neew.tail)
        {
            list* k = new list;
            k = neew.tail;
            c = neew.head;
            c->next = NULL;
            c->previous = NULL;
            neew.head = NULL;
            k->next = NULL;
            k->previous = NULL;
            neew.tail = NULL;
            delete k;


            break;

            n = 1;

        }
        else
        {

            list* tmp;
            tmp = neew.head->next;
            delete(neew.head);
            neew.head = tmp;
            neew.head->previous = NULL;
            licz++;

        }

    }
    if (neew.head == NULL || neew.tail == NULL)
    {
        cout << "Lista jest wyczyszczona!" << endl;
    }

}


void podmiana(contener& nowe, int position, int nowy)
{
    list* c = new list;
    int g = 0;
    int n = 0;
    c = nowe.head;

    if (c == NULL) {
        cout << "Lista nie posiada elementow" << endl;
    }
    else {
        bool b = true;
        while (b == true)
        {
            if (n != position)
            {
                c = c->next;
                n++;
                g++;
            }
            else
            {
                cout << "wymieniles element: " << c->data << endl;
                c->data = nowy;
                cout << "Nowa wartosc" << ":" << c->data << endl;
                b = false;

            }
        }


    }


}




int main() {
    contener l;
    int option = 0;
    int liczba;
    int nowa;
    int opcja;
    while (option != 1) {

        cout << "stan listy" << endl;
        display(l);
        cout << "wybierz opcje" << endl;
        cout << "1. Dodaj wartosc z przodu" << endl;
        cout << "2. Dodaj wartosc z tylu" << endl;
        cout << "3. Usun wartosc z przodu" << endl;
        cout << "4. Usun wartosc z tylu" << endl;
        cout << "5. Podmien wybrany element" << endl;
        cout << "6. Usun cala liste" << endl;
        cin >> opcja;

        switch (opcja) {

        case 1:
            system("cls");
            cout << "Wybierz liczbe jaka chcesz dodac" << endl;
            cin >> liczba;
            dodajtyl(l, liczba);
            break;

        case 2:
            system("cls");
            cout << "Wybierz liczbe jaka chcesz dodac" << endl;
            cin >> liczba;
            dodajprzod(l, liczba);
            break;

        case 3:
            system("cls");
            usunP(l);
            break;

        case 4:
            system("cls");
            usunT(l);
            break;

        case 5:
            system("cls");
            cout << "Wybierz liczbe jaka chcesz podmienic" << endl;
            cin >> liczba;
            cout << "Podaj nowa wartosc: " << endl;
            cin >> nowa;
            podmiana(l, liczba, nowa);
            break;
        case 6:
            system("cls");
            usun(l);
            break;
        }

    }



};