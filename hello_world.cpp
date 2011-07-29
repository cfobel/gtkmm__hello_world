#include "hello_world.hpp"
#include <iostream>
using namespace std;

HelloWorld::HelloWorld()
        // creates a new button with label "Hello World".  
        : hello_button("Hello World"), goodbye_button("Goodbye World"),
            level(0.8) {
    set_size_request(400, 400);
    // Sets the border width of the window.
    set_border_width(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    hello_button.signal_clicked().connect(sigc::mem_fun(*this,
                &HelloWorld::on_hello_button_clicked));
    goodbye_button.signal_clicked().connect(sigc::mem_fun(*this,
                &HelloWorld::on_goodbye_button_clicked));
    area.signal_expose_event().connect(
        sigc::mem_fun(*this, &HelloWorld::on_area_expose));

    vbox.pack_start(hbox, false, false);
    hbox.pack_start(hello_button, false, false);
    hbox.pack_start(goodbye_button, false, false);
    vbox.pack_start(area);
    add(vbox);
    show_all_children();
}

HelloWorld::~HelloWorld() {}

void HelloWorld::on_hello_button_clicked() {
    std::cout << "Hello World" << std::endl;
    level /= 0.9;
    update_drawing();
}

void HelloWorld::on_goodbye_button_clicked() {
    std::cout << "Goodbye World" << std::endl;
    level *= 0.9;
    update_drawing();
}


bool HelloWorld::on_area_expose(GdkEventExpose* event) {
    update_drawing();
    return true;
}

void HelloWorld::update_drawing() {
    allocation = area.get_allocation();
    Cairo::RefPtr<Cairo::Context> context = area.get_window()->create_cairo_context();
    int width = allocation.get_width();
    int height = allocation.get_height();
    cout << "width: " << width << ", height: " << height << endl;
    context->save();
    context->set_source_rgba(0, level, 0, 1);
    context->scale(width, height);
    context->rectangle(0, 0, 1, 1);
    context->fill();
    context->restore();
}
