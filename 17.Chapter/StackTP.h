#ifndef STACKTP_H_
#define STACKTP_H_

export template <class Type> class Stack {
     private:
        enum {Max = 10};
        Type items[Max];
        int top;

     public:
        Stack();
        bool isEmpty() const;
        bool isFull() const;
        bool push(const Type& type);
        bool pop(Type& type);
};

#endif
