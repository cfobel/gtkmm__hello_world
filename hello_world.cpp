#include "hello_world.hpp"
#include <iostream>
using namespace std;

HelloWorld::HelloWorld()
        // creates a new button with label "Hello World".  
        : btn_hello("Hello World"), btn_goodbye("Goodbye World"),
            tgl_hello("Hello World (run)"),
            tgl_goodbye("Goodbye World (run)"),
            level(0.8) {
    set_size_request(400, 400);
    // Sets the border width of the window.
    set_border_width(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    btn_hello.signal_clicked().connect(sigc::mem_fun(*this,
                &HelloWorld::on_hello_clicked));
    tgl_hello.signal_clicked().connect(sigc::mem_fun(*this,
                &HelloWorld::on_toggle_hello_clicked));
    btn_goodbye.signal_clicked().connect(sigc::mem_fun(*this,
                &HelloWorld::on_goodbye_clicked));
    tgl_goodbye.signal_clicked().connect(sigc::mem_fun(*this,
                &HelloWorld::on_toggle_goodbye_clicked));
    ara_canvas.signal_expose_event().connect(
        sigc::mem_fun(*this, &HelloWorld::on_canvas_expose));

    box_v.pack_start(box_h, false, false);
    box_h.pack_start(btn_hello, false, false);
    box_h.pack_start(btn_goodbye, false, false);
    box_h.pack_start(tgl_hello, false, false);
    box_h.pack_start(tgl_goodbye, false, false);
    box_v.pack_start(ara_canvas);
    add(box_v);
    show_all_children();
}

HelloWorld::~HelloWorld() {}

void HelloWorld::on_hello_clicked() {
    update_hello();
}


bool HelloWorld::on_toggle_hello_timeout() {
    if(tgl_hello.get_active()) {
        update_hello();
        Glib::signal_timeout().connect(
                sigc::mem_fun(*this, &HelloWorld::on_toggle_hello_timeout),
                500);
    }
}


void HelloWorld::on_toggle_hello_clicked() {
    tgl_goodbye.set_active(false);
    on_toggle_hello_timeout();
}


void HelloWorld::update_hello() {
    std::cout << "Hello World" << std::endl;
    level /= 0.9;
    update_canvas();
}


bool HelloWorld::on_toggle_goodbye_timeout() {
    if(tgl_goodbye.get_active()) {
        update_goodbye();
        Glib::signal_timeout().connect(
                sigc::mem_fun(*this, &HelloWorld::on_toggle_goodbye_timeout),
                500);
    }
}


void HelloWorld::on_toggle_goodbye_clicked() {
    tgl_hello.set_active(false);
    on_toggle_goodbye_timeout();
}


void HelloWorld::on_goodbye_clicked() {
    update_goodbye();
}


void HelloWorld::update_goodbye() {
    std::cout << "Goodbye World" << std::endl;
    level *= 0.9;
    update_canvas();
}


bool HelloWorld::on_canvas_expose(GdkEventExpose* event) {
    Cairo::RefPtr<Cairo::Context> context = ara_canvas.get_window()->create_cairo_context();
    context->rectangle(event->area.x, event->area.y, event->area.width, 
            event->area.height);
    context->clip();
    update_canvas();
    return true;
}


void HelloWorld::update_canvas() {
    Cairo::RefPtr<Cairo::Context> context = ara_canvas.get_window()->create_cairo_context();
    update_canvas(context);
}


void HelloWorld::update_canvas(Cairo::RefPtr<Cairo::Context> &context) {
    alc_allocation = ara_canvas.get_allocation();
    int width = alc_allocation.get_width();
    int height = alc_allocation.get_height();
    cout << "width: " << width << ", height: " << height << endl;
    context->save();
    context->set_source_rgba(0, level, 0, 1);
    context->scale(width, height);
    context->rectangle(0, 0, 1, 1);
    context->fill();
    context->restore();
}
