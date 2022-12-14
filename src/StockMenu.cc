#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"
#include "StockMenu.h"
#include <iostream>

Gtk::Frame StockMenu::CreateFrame(){
    Gtk::Frame staffFrame;

    staffFrame.set_label("- Stock Menu -");
    testbtn.set_label("Stock");
    testbtn.signal_clicked().connect( sigc::mem_fun(*this,&StockMenu::testcall) ); //set callback function
    staffFrame.set_child(testbtn);
    //testEntry.signal_icon_press().connect(sigc::mem_fun(*this,&StockMenu::testcall)); // test
    staffFrame.set_child(testEntry);

    return staffFrame;
}

void StockMenu::testcall(){
    std::cout << "test" << std::endl;
}