//
// Created by roberto on 19.12.16.
//

#ifndef SDL_DEMO_WIDGET_H
#define SDL_DEMO_WIDGET_H

#include "Surface.h"
#include "Window.h"
#include <memory>


namespace my {
    using namespace std;
    class Widget {

    public:
        template<typename T>
        Widget(T data) : p_(make_shared<Model<T>>(move(data))) {}
        friend my::Surface getSurface(const Widget &w){
            return w.p_->draw_();
        }
        void onMouseOver( const Widget &w, bool isOver){
            w.p_->onMouseOver_(isOver);
        }
        void onMouseClick(const Widget &w, bool isClicked){
            w.p_->onMouseClick_(isClicked);
        }

    private:
        struct Concept {
            virtual my::Surface draw_() const = 0;
            virtual ~Concept() = default;
            virtual void onMouseOver_(bool b) const = 0;
            virtual void onMouseClick_(bool b) const = 0;
        };

        template<typename T>
        struct Model : Concept {
            Model(T data) : data_(move(data)) {}

            my::Surface draw_() const override {
                return data_.draw();
            }

            void onMouseOver_(bool b) const override{
                data_.onMouseOver(b);
            }
            void onMouseClick_(bool b) const override{
                data_.onMouseClick(b);
            }

            T data_;
        };

        shared_ptr<const Concept> p_;
    };
}
#endif //SDL_DEMO_WIDGET_H
