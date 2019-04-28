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
            T peak();
            bool isEmpty() const;
            unsigned int size() const;
            std::vector<T> data() const;

            T operator[](unsigned int) const;
        private:
            std::vector<T> elements;
        };

        /**
        *  Push a given element to the data structure.
        *
        *  @param element
        *  @return void
        */
        template<class T>
        void Stack<T>::push(const T & element)
        {
            elements.push_back(element);
        }

        /**
        *  Remove the last element from the data structure.
        *
        *  @throws std::out_of_range
        *  @return void
        */
        template<class T>
        void Stack<T>::pop() {
            if (this->isEmpty())
            {
                throw std::out_of_range("Stack is empty. Cannot pop from an empty data structure");
            }

            elements.pop_back();
        }

        /**
        *  Access the latest element to be inserted i.e. top of stack.
        *
        *  @return void
        */
        template<class T>
        T Stack<T>::peak()
        {
            return elements.back();
        }

        /**
        *  Detects whether the data structure is empty.
        *
        *  @return bool
        */
        template<class T>
        bool Stack<T>::isEmpty() const {
            return elements.empty();
        }

        /**
        *  Gets the number of elements within the stack.
        *
        *  @return unsigned int
        */
        template<class T>
        unsigned int Stack<T>::size() const {
            return elements.size();
        }

        /**
        *  Retrieves the underlying data.
        *
        *  @return std::vector<T>
        */
        template<class T>
        std::vector<T> Stack<T>::data() const {
            return elements;
        }

        /**
        *  Access stack at a numerical index.
        *
        *  @throw std::out_of_range
        *  @return std::vector<T>
        */
        template<class T>
        T Stack<T>::operator[](unsigned int index) const {
            return elements.at(index);
        }
    }
}

#endif //TREKSTAR_STACK_H
