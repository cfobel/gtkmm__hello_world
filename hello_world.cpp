#include "hello_world.hpp"
#include <iostream>

HelloWorld::HelloWorld()
    // creates a new button with label "Hello World".  
    : hello_button("Hello World"), goodbye_button("Goodbye World") {
  // Sets the border width of the window.
  set_border_width(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  hello_button.signal_clicked().connect(sigc::mem_fun(*this,
              &HelloWorld::on_hello_button_clicked));
  goodbye_button.signal_clicked().connect(sigc::mem_fun(*this,
              &HelloWorld::on_goodbye_button_clicked));

  vbox.pack_start(hbox, false, false);
  hbox.pack_start(hello_button, false, false);
  hbox.pack_start(goodbye_button, false, false);
  add(vbox);
  show_all_children();
}

HelloWorld::~HelloWorld() {}

void HelloWorld::on_hello_button_clicked() {
  std::cout << "Hello World" << std::endl;
}

void HelloWorld::on_goodbye_button_clicked() {
  std::cout << "Goodbye World" << std::endl;
}
