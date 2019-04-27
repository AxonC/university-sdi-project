#ifndef TREKSTAR_STACK_H
#define TREKSTAR_STACK_H

#include <vector>
#include <stdexcept>
#include <initializer_list>

namespace TrekStar
{
    namespace Structures
    {
        template <class T>
        class Stack {
        public:
            Stack() = default;
            Stack(std::initializer_list<T> initialElements): elements(initialElements) {};

            void push(T const &);
            void pop();
            bool isEmpty() const; // determines whether or not the stack is empty.
            unsigned int size() const;
            std::vector<T> data() const; // returns the underlying data structure.
            void update(T const &, unsigned int);

            T operator[](unsigned int) const;
        private:
            std::vector<T> elements;
        };

        template<class T>
        void Stack<T>::push(const T & element)
        {
            elements.push_back(element);
        }

        template<class T>
        void Stack<T>::pop() {
            if (this->isEmpty()) {
                throw std::out_of_range("Stack is empty. Cannot pop from an empty data structure");
            }

            elements.pop_back();
        }

        template<class T>
        bool Stack<T>::isEmpty() const {
            return elements.empty();
        }

        template<class T>
        unsigned int Stack<T>::size() const {
            return elements.size();
        }

        template<class T>
        std::vector<T> Stack<T>::data() const {
            return elements;
        }

        template<class T>
        void Stack<T>::update(const T & element, unsigned int elementPos)
        {
            this->elements.at(elementPos) = element;
        }

        template<class T>
        T Stack<T>::operator[](unsigned int index) const {
            return elements.at(index);
        }
    }
}

#endif //TREKSTAR_STACK_H
