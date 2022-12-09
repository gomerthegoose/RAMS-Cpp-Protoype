#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"
#include "StaffMenu.h"
#include <iostream>

Gtk::Frame StaffMenu::CreateFrame(){
    Gtk::Frame staffFrame;
    testbtn.set_label("Stock");
    testbtn.signal_clicked().connect( sigc::mem_fun(*this,&StaffMenu::testcall) ); //set callback function
    staffFrame.set_child(testbtn);
    return staffFrame;
}

void StaffMenu::testcall(){
    std::cout << "test" << std::endl;
}