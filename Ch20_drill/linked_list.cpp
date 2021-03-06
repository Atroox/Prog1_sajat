#include <iostream>

template<typename Elem>
struct Link {
    Elem val;           
    Link* prev;         
    Link* succ;         
    Link(const Elem& v = Elem{0}, Link* p = nullptr, Link* s = nullptr)
        : val{v}, prev{p}, succ{s} { }
};

template<typename Elem>
class list {
    int sz;
    Link<Elem>* first;
    Link<Elem>* last;           
public:
    list() : sz{0}, first{new Link<Elem>{}}, last{first} { }

    explicit list(int n, Elem def = Elem())
        : sz{n}, first{new Link<Elem>{}}, last{first}
    {
        for (int i = 0; i < n; ++i) {
            first = new Link<Elem>{def, nullptr, first};
            first->succ->prev = first;
        }
    }

    ~list()
    {
        while (first != nullptr) {
            auto p = first->succ;
            delete first;
            first = p;
        }
    }

    class iterator;             

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(last); }

    iterator insert(iterator p, const Elem& v); 

    void push_front(const Elem& v);             
    void push_back(const Elem& v);              
    
    int size() const { return sz; }
};

template<typename Elem>
class list<Elem>::iterator {
    Link<Elem>* curr;
public:
    iterator(Link<Elem>* p) : curr{p} { }

    iterator& operator++() {curr = curr->succ; return *this; }
    iterator& operator--() {curr = curr->prev; return *this; }
    Elem& operator*() { return curr->val; }
    Link<Elem>* operator->() { return curr; }

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};

template<typename Elem>
typename list<Elem>::iterator list<Elem>::insert(list<Elem>::iterator p,
        const Elem& v)
{
    Link<Elem>* q = new Link<Elem>{v, p->prev};

    if (p->succ) q->succ = p->succ->prev;
    else q->succ = last;
    p->prev = q;

    if (q->prev) q->prev->succ = q;
    else first = q;

    ++sz;
    return iterator(q);
}

template<typename Elem> void list<Elem>::push_front(const Elem& v)
{
    Link<Elem>* p = new Link<Elem>{v};
    p->succ = first;
    first->prev = p;
    first = p;
    ++sz;
}

template<typename Elem> void list<Elem>::push_back(const Elem& v)
{
    Link<Elem>* p = new Link<Elem>{v};

    if (last == first) first = p;
    else last->prev->succ = p;

    p->prev = last->prev;
    p->succ = last;
    last->prev = p;
    ++sz;
}

template<typename Iter>
Iter high(Iter first, Iter last)
{
    Iter high = first;
    for (Iter p = first; p != last; ++p)
        if (*high < *p) high = p;
    return high;
}

void f()
{
    list<int> lst; for (int x; std::cin >> x; ) lst.push_front(x);

    list<int>::iterator p = high(lst.begin(), lst.end());
    std::cout << "the highest value was " << *p << '\n';
}

int main()
{
    list<int> li1;
    std::cout << "Empty list size: " << li1.size() << '\n';

    list<int> li2 (9);
    std::cout << "int init'd size: " << li2.size() << '\n';

    for (auto& l : li2)
        l = 7;

    for (auto& l : li2)
        std::cout << l << ' ';
    std::cout << '\n';

    list<char> lc1;
    lc1.push_front('n');
    lc1.push_back('k');
    lc1.push_front('i');
    lc1.push_back('l');
    lc1.push_back('i');
    lc1.push_back('s');

    auto pi = lc1.begin();
    ++pi; ++pi; ++pi;
    lc1.insert(pi, 'd');
    lc1.insert(lc1.begin(), 'L');
    lc1.insert(lc1.end(), 't');

    for (auto a : lc1)
        std::cout << a << ' ';
    std::cout << '\n';

    list<char> lc2;
    lc2.push_back('l');
    lc2.push_back('m');
    lc2.push_back('a');
    lc2.push_front('a');

    for (auto a : lc2)
        std::cout << a << ' ';
    std::cout << '\n';

    f();
}