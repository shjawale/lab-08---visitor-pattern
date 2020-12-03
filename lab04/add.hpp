#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "op.hpp"
#include "../iterator.hpp"
#include <string>
#include <iostream>

class Add : public Base {
   private:
        Base* _lChild = nullptr;
        Base* _rChild = nullptr;

   public:
        Add(Base* left, Base* right) {
            _lChild = left;
            _rChild = right;
        }

        virtual double evaluate() {
            return _lChild->evaluate() + _rChild->evaluate(); 
        }

        virtual std::string stringify() {
            std::stringstream out;
            out << std::setprecision(5) << _lChild->stringify() << " + " << _rChild->stringify();
            return out.str();
        }

        virtual Iterator* create_iterator(){
            Iterator* temp =  new BinaryIterator(this);
            return temp;
        }

        virtual Base* get_left(){
            return _lChild;
        }

        virtual Base* get_right(){
            return _rChild;
        }

        virtual void accept(CountVisitor* v){
            v->visit_add();
        }
};

#endif //__MULT_HPP__
