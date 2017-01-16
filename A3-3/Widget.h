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
        Widget(T data) : p_(make_shared<Model<T>>(move(data))) { }

        friend void setPosition(Widget const &w, SDL_Rect const &offset){
            w.p_->setPosition_(offset);
        }

        friend void draw(Widget const &w, my::Surface const &sur) {
            w.p_->draw_(sur);
        }

        friend void handleEvent(Widget const &w, SDL_Event const &evt) {
            w.p_->handleEvent_(evt);
        }

        friend SDL_Rect getPosition(Widget const &w){
            return w.p_->getPosition_();
        }

    private:
        struct Concept {

            virtual void setPosition_(SDL_Rect const &offset) const = 0;

            virtual void draw_(my::Surface const &sur) const = 0;

            virtual void handleEvent_(SDL_Event const &evt) const = 0;

            virtual SDL_Rect getPosition_() const = 0;

            virtual ~Concept() = default;
        };

        template<typename T>
        struct Model : Concept {
            Model(T data) : data_(move(data)) {}

            void setPosition_(SDL_Rect const &offset) const override {
                setPosition(data_, offset);
            }

            void draw_(my::Surface const &sur) const override {
                draw(data_,sur);
            }

            void handleEvent_(SDL_Event const &evt) const override {
                handleEvent(data_, evt);
            }

            SDL_Rect getPosition_() const override {
                return getPosition(data_);
            }

            T data_;
        };

        shared_ptr<const Concept> p_;
    };
}
#endif //SDL_DEMO_WIDGET_H
