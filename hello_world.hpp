#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window {
public:
    HelloWorld();
    virtual ~HelloWorld();

protected:
    //Signal handlers:
    void on_hello_button_clicked();
    void on_goodbye_button_clicked();
    bool on_area_expose(GdkEventExpose* event);
    void update_drawing();

    //Member widgets:
    Gtk::Button hello_button;
    Gtk::Button goodbye_button;
    Gtk::VBox vbox;
    Gtk::HBox hbox;
    Gtk::DrawingArea area;
    Gtk::Allocation allocation;
    double level;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H
