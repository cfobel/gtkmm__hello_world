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
    void on_hello_clicked();
    void on_toggle_hello_clicked();
    bool on_toggle_hello_timeout();
    void update_hello();

    void on_goodbye_clicked();
    void on_toggle_goodbye_clicked();
    bool on_toggle_goodbye_timeout();
    void update_goodbye();

    bool on_canvas_expose(GdkEventExpose* event);
    void update_canvas();

    //Member widgets:
    Gtk::Button btn_hello;
    Gtk::Button btn_goodbye;
    Gtk::ToggleButton tgl_hello;
    Gtk::ToggleButton tgl_goodbye;
    Gtk::VBox box_v;
    Gtk::HBox box_h;
    Gtk::DrawingArea ara_canvas;
    Gtk::Allocation alc_allocation;
    double level;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H
