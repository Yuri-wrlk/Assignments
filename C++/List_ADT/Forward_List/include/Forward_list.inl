template <class T>
Forward_list<T>::Forward_list() : 
        m_size (0),
        m_head (nullptr),
        m_tail (nullptr)
{ /* Empty */ }

template <class T>
Forward_list<T>::~Forward_list() 
{
    clear();
}

template <class T>
Forward_list<T>::Forward_list(const Forward_list<T> &lista)
{
    clear();
    if(lista.size() != 0)
    {
        Node * tocopy = lista.m_head; // aqui esta dando erro //precisamos do metdodo que pega o m_head // sim, deixa comigo ai ô returnM_head()
        Node * newNode;
        try {
            newNode = new Node;
        }
        catch(const std::bad_alloc & e) {
            throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
        }
    
        newNode->data = tocopy->data; 
        newNode->next = nullptr;
        m_head = newNode;
        m_tail = newNode;
        tocopy = tocopy->next;
    
        while(tocopy != nullptr){
        
            try {
                newNode->next = new Node;
            }
            catch(const std::bad_alloc & e) {
                throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
            }
            newNode = newNode->next;
            
            newNode->data = tocopy->data;
            newNode->next = nullptr;
            
            m_tail = newNode;
            tocopy = tocopy->next;
        }                   
    }
    m_size = lista.size(); 
}

template <class T>
Forward_list<T>::Forward_list(Forward_list<T> && ) 
{
    
}

template <class T>
Forward_list<T> & Forward_list<T>::operator= ( const Forward_list<T> & lista){ // copia profunda
    clear();
    if(lista.size() != 0)
    {
        Node * tocopy = lista.m_head;
        Node * newNode;
        try {
            newNode = new Node;
        }
        catch(const std::bad_alloc & e) {
            throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
        }
    
        newNode->data = tocopy->data; 
        newNode->next = nullptr;
        m_head = newNode;
        m_tail = newNode;
        tocopy = tocopy->next;
    
        while(tocopy != nullptr){
        
            try {
                newNode->next = new Node;
            }
            catch(const std::bad_alloc & e) {
                throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
            }
            newNode = newNode->next;
            
            newNode->data = tocopy->data;
            newNode->next = nullptr;
            
            m_tail = newNode;
            tocopy = tocopy->next;
        }                   
    }
    m_size = lista.size();
    return *this;
}

template <class T>
Forward_list<T> & Forward_list<T>::operator= ( Forward_list<T> && lista)
{
    clear();
    Node* work =  lista;
    m_head = lista.front();
    m_tail = lista.back();
}
        
template <class T>
size_type Forward_list<T>::size() const {

    return m_size;
}



template <class T>
void Forward_list<T>::clear(){
    if(m_head != nullptr){
        Node* work = m_head;
         while(m_head != nullptr) {
            work = work->next;
            delete[] m_head;
            m_head = work;
        }
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }
}

template <class T>
bool Forward_list<T>::empty() {
    return (m_head == nullptr);
}

template <class T>
void Forward_list<T>::push_back( const T & x ){
    Node* newNode;
    try {
        newNode = new Node;
    }
      catch(const std::bad_alloc & e) {
        throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
    }
    
    newNode->data = x;
    newNode->next = nullptr;
    
    if(!empty())
    {
        m_tail->next = newNode;
        m_tail = newNode;
    }
    else
    {
        m_head = newNode;
        m_tail = newNode;
    }
    m_size++;
}


template <class T>
void Forward_list<T>::pop_back() {
    if(empty() ) {
        throw std::underflow_error ("Nao ha elemento a ser removido");
    }
    Node* work = m_head;
    Node* work2 = nullptr;
    while(work->next != nullptr) {
        work2 = work;
        work = work->next;
    }
    delete[] work;
    if (work2 == nullptr)
    {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else
    {
        m_tail = work2;
        work2->next = nullptr;
    }
    m_size--;
}

template <class T>
const T & Forward_list<T>::back() const {
    if(m_head == nullptr) {
      throw std::length_error ("Nao ha valor a ser consultado");
    }
    return m_tail->data;
}

template <class T>
const T & Forward_list<T>::front() const {
    if(m_head == nullptr) {
        throw std::length_error ("Nao ha valor a ser consultado");
    }
    return m_head->data;
}

template <class T>
void Forward_list<T>::assign(const T & x){
    Node * work = m_head;
    while (work != nullptr){
        work-> data = x;
        work = work->next;
    }
}

template <class T>
void Forward_list<T>::push_front( const T & x ) {
    Node* newNode = nullptr;

    try {
        newNode = new Node;
    }
    catch(const std::bad_alloc & e) {
        throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
    }

    newNode->data = x;
    newNode->next = m_head;
    m_head = newNode;
    m_size++;
    if(m_size == 1)
        m_tail = m_head;
}

template <class T>
void Forward_list<T>::pop_front() {
    if(empty() ) {
        throw std::underflow_error ("Nao ha elemento a ser removido");
    }
    Node* work = m_head;
    work = work->next;
    delete[] m_head;
    m_head = work;
    m_size--;
    if(m_size == 0)
        m_tail = nullptr;
}

template <class T>
void Forward_list<T>::print() {
    int i = 0;
    Node* work = m_head;
    if(empty() ) {
      std::cerr << ">>> Lista vazia.\n"; // erro de lista vazia
    }
    std::cout << "[ ";
    while(work != nullptr) {
      std::cout << work->data << " ";
      i++;
      work = work->next;
    }
    std::cout << "]\n";
}
/*
template <class T>
typename Forward_list<T>::Iterator insert_after( Forward_list<T>::Const_Iterator itr , const T & x )
{
    Node* work = itr.const_it_ptr;
    while(work != nullptr)
    {
        work->data = x;
        work = work->next;
    }
}

template <class T>
typename Forward_list<T>::Iterator insert_after( Const_Iterator pos , std::initializer_list<T> ilist )
{
    
}
*/
//OBS: o tipo SNPtr aqui se chama NPtr
//OBS2: o _pAIL aqui se chama head que é o ponteiro para o inicio da lista
// sim mas é bom olhar caso a caso para não gerar algum problema
// blz

// void print()
// {
//     int i = 0;
//     NPtr work = m_head;
//     if(empty() ) {
//       std::cerr << ">>> Lista vazia.\n"; // erro de lista vazia
//     }
//     std::cout << "[ ";
//     while(work != nullptr) {
//       std::cout << work->data << " ";
//       i++;
//       work = work->next;
//     }
//     std::cout << "]\n";
// }

//! Length of the list.
/*! Calculates and return the length of the list. Length is zero, if list is empty.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 *  @return The length.
 */
 
// int length()
// {
//   return nodesNumber+1;
// }


// bool empty()
// {
//   if(m_head == nullptr && m_size == 0) {
//     return true;
//   }
//   return false;
// }


// void clear()
// {
//   if(m_head == nullptr) {
//     std::cout << ">>> Esta fila já está vazia.\n";
//   }
//   Node* work = m_head;
//   while(m_head != nullptr) {
//     work = work->mpNext;
//     delete m_head;
//     m_head = work;
//   }
//   m_head = nullptr;
//}


// bool front(int & _retrievedVal)
// {
//     if(m_head == nullptr) {
//       _retrievedVal = m_head->miData;
//       return false;
//     }
//     return true;
// }


// bool back(int & _retrievedVal)
// {
//     if(m_head == nullptr) {
//       return false;
//     }
//     Node* work = _pAIL;
//     while(work->next == nullptr) {
//       work = work->next;
//     }
//     _retrievedVal = work->data;
//     return true;
// }


// bool pushFront(int _newVal )
// {
//   Node* newNode = nullptr;

//   try {
//     newNode = new Node;
//   }
//   catch(const std::bad_alloc & e) {
//     return false;
//   }

//   newNode->data = _newVal;
//   newNode->next = m_head;
//   m_head = newNode;

//   return true;
// }


// bool pushBack(int _newVal)
// {
//   Node* work = _pAIL;
//   Node* newNode;
//   try {
//     newNode = new Node;
//   }
//   catch(const std::bad_alloc & e) {
//     std::cout << ">>> Erro durante alocação na memoria do novo valor da lista.\n";
//     return false;
//   }
//   if(work == nullptr) {
//     newNode->data = _newVal;
//     newNode->next = nullptr;
//     m_head = newNode;
//     return true;
//   }
//   while(work != nullptr) {
//     if(work->next == nullptr) {
//       break;
//     }
//     work = work->next;
//   }
//   newNode->data = _newVal;
//   newNode->next = nullptr;
//   work->next = newNode;
//   return true;
// }


// bool popFront(int & _retrievedVal)
// {
//   if(empty() ) {
//     std::cout << ">>> A lista está vazia.\n";
//     return false;
//   }
//   Node* work = m_head;
//   _retrievedVal = work->data;
//   work = work->next;
//   delete m_head;
//   m_head = work;
//     return true;
// }


// bool popBack(int& _retrievedVal)
// {
//   if(empty() ) {
//     std::cout << ">>> A lista está vazia.\n";
//     return false;
//   }
//   Node* work = m_head;
//   Node* work2 = m_head;
//   while(work->next != nullptr) {
//     work2 = work;
//     work = work->next;
//   }
//   delete work;
//   work2->next = nullptr;
//     return true;
// }





/**
*   Retorna o node anterior ao do node procurado.
*/
// template <class T>
// Node* Forward_list<T>::find(int _targetVal)
// {
//     Node* work = m_head;
//     if(work == nullptr) {
//       std::cout << ">>> A lista esta vazia.\n";
//       return nullptr;
//     }
//     if(work->data == _targetVal) {
//       return nullptr;
//     }
//     if(tail->dataa == _targetVal) {
//         return tail;
//     }
//     while(work->next != nullptr) {
//       if( (work->next->data) == _targetVal){
//         return work;
//       }
//       work = work->next;
//     }
//     std::cout << ">>> O elemento não foi encontrado.\n";
//     return nullptr;
// }

// template <class T>
// bool Forward_list<T>::insert(Node* _pAnte, int _newVal ) //antes tinha 3 entradas            bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal )
// {
//     Node* work = m_head;
//     Node* newNode;
//     if(_pAnte == nullptr) { // o novo Node deve ser 
//       Node* work = m_head;
//       m_head = new Node;
//       m_head->data = _newVal;
//       m_head->next = work;
//       return true;
//     }
//     else if(m_head == nullptr) { // a lista é vazia, um node é craiado
//       try {
//         newNode = new Node;
//       }
//       catch(const std::bad_alloc & e) {
//         std::cout << ">>> Erro durante alocação na memoria do novo valor da lista.\n";
//         return false;
//       }
//       newNode->data = _newVal;
//       newNode->next = nullptr;
//       m_head = newNode;
//     }
//     else if(m_head == _pAnte) {  

//       try {
//         SNPtr newNode = new Node;
//       }
//       catch(const std::bad_alloc & e) {
//         std::cout << ">>> Erro durante alocação na memoria do novo valor da lista.\n";
//         return false;
//       }

//       newNode->data = _newVal;
//       newNode->next = work;
//       m_head = newNode;
//     }
//     while(work->next != _pAnte) {
//       if(work->next == nullptr) {
//         std::cout << ">>> A posição que deve ser colocado o volor " << _newVal << " não foi encontrado.\n";
//         return false;
//       }
//       work = work->next;
//     }

//     try {
//       SNPtr newNode = new Node;
//     }
//     catch(std::bad_alloc & e) {
//       std::cout << ">>> Erro durante alocação na memoria do novo valor da lista.\n";
//       return false;
//     }

//     newNode->data = _newVal;
//     newNode->next = _pAnte;
//     work->next = newNode;
//     m_size += 1;
//     return true;
// }

// template <class T>
// bool Forward_list<T>::remove(Node* _pAnte, int & _retrievedVal ) // antes tinha 3 entradas     bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
// {
//     int x;
//     Node* work = m_head;
//     if(work == nullptr) {
//       std::cout << ">>> A lista esta vazia. Não existe oque remover.\n";
//       return false;
//     }
//     if(_pAnte == nullptr) {
//       work = work->next;
//       _retrievedVal = work->data;
//       delete work;
//       return true;
//     }
//     work = _pAnte->next;
//     _pAnte->next = work->next;
//     _retrievedVal = work->data;
//     delete work;
//     return true;
// }
