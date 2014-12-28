#include <GL/glew.h>
#include <boost/compressed_pair.hpp>
#pragma once

template<class Initializer, class Deleter>
class Handle {
private:
        typedef boost::compressed_pair<GLuint, Initializer> inner_pair_type;
        typedef boost::compressed_pair<inner_pair_type, Deleter> triple_type;

        triple_type handle;
        GLuint& get_handle() {
                return handle.first().first();
        }
        const GLuint& get_handle() const {
                return handle.first().first();
        }
        Initializer& get_initializer() {
                return handle.first().second();
        }
        Deleter& get_deleter() {
                return handle.second();
        }

        static triple_type construct_triple(GLuint h) {
                return triple_type(inner_pair_type(h));
        }

        void clear() {
                get_deleter()(get_handle());
        }
public:
        GLuint operator*() const {
                return get_handle();
        }

        void reset(GLuint p) {
                clear();
                get_handle() = p;
        }

        GLuint release() {
                GLuint temp = get_handle();
                get_handle() = 0;
                return temp;
        }

        void swap(Handle& other) {
                GLuint temp = get_handle();
                get_handle() = other.get_handle();
                other.get_handle() = temp;
        }

        Handle():
                handle(construct_triple(get_initializer()())) {}

        template<typename ... Args>
        Handle(Args ... args):
                handle(construct_triple(get_initializer()(args...))) {}

        ~Handle() {
                clear();
        }

        Handle(const Handle& rhs) = delete;
        Handle& operator=(const Handle& rhs) = delete;

        Handle(Handle&& rhs):
                handle(construct_triple(rhs.release())) {}

        Handle& operator=(Handle&& rhs) {
                reset(rhs.release());
                return *this;
        }
};
