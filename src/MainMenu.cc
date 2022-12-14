#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"
#include "MainMenu.h"
#include "LoginWindow.h"
#include "StaffMenu.h"
#include "StockMenu.h"
#include "FileLocations.h"

#include <iostream>



MainMenu::MainMenu(): m_VBox(Gtk::Orientation::VERTICAL) // main mewnu constructor 
{
  g_object_set(gtk_settings_get_default(),"gtk-application-prefer-dark-theme", TRUE,NULL); //set dark mode





  set_size_request(1000,800); //set default size of window  
  set_title("Main Menu"); // title
  set_resizable(true); // make window resizable
  set_child(m_VBox);
  m_VBox.append(m_HBox);


  Controls_grid = Gtk::manage(new Gtk::Grid());

  StaffButton.set_label("Staff");
  StaffButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::staffMenuButton) ); //set callback function
  Controls_grid->attach(StaffButton, 1,1,2,1);

  StockButton.set_label("Stock");
  StockButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::stockMenuButton) ); //set callback function
  Controls_grid->attach(StockButton,1,3,2,1);

  ThursdayBookingButton.set_label("Thursday Bookings");
  ThursdayBookingButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::thursdayBookingsButton) ); //set callback function
  Controls_grid->attach(ThursdayBookingButton,1,5,2,1);

  SundayBookingButton.set_label("Sunday Bookings");
  SundayBookingButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::sundayBookingsButton) ); //set callback function
  Controls_grid->attach(SundayBookingButton,1,7,2,1);

  exitButton.set_label("Exit");
  exitButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::sundayBookingsButton) ); //set callback function
  exitButton.set_valign(Gtk::Align::FILL);
  Controls_grid->attach(exitButton,1,8,2,1);

  Main_grid = Gtk::manage(new Gtk::Grid());

  view_Frame.set_label("- View -");
  Main_grid->attach(view_Frame,1,0,1,1);
  view_Frame.set_expand(true);


  controls_Frame.set_label("- Main Menu -");
  Main_grid->attach(controls_Frame,0,0,1,1);
  controls_Frame.set_child(*Controls_grid);
  m_VBox.append(*Main_grid);
}


void MainMenu::setMenu(Gtk::Frame frame){
  Main_grid->attach(frame,1,0,1,1); // atatch new frame to grid in correct location 
  frame.set_expand(true); // allow new frame to expand
  Main_grid->remove(*(Main_grid->get_child_at(1,0))); // remove existing widget from grid to avoid stacking frames
}

MainMenu::~MainMenu(){
}

// button handlers
void MainMenu::staffMenuButton(){
  std::cout << "Staff" << std::endl;
  view_Frame.hide(); // hide original frame
  StaffMenu staffMenu; // create new staff menu instance
  setMenu(staffMenu.CreateFrame()); // set active frame
}

void MainMenu::stockMenuButton(){
  std::cout << "Stock" << std::endl;
  view_Frame.hide(); // hide original frame
  StockMenu stockMenu; // create new staff menu instance
  setMenu(stockMenu.CreateFrame()); // set active frame
}

void MainMenu::thursdayBookingsButton(){
  std::cout << "Thursday Bookings" << std::endl;
  view_Frame.hide(); // hide original frame
  StaffMenu staffMenu; // create new staff menu instance
  setMenu(staffMenu.CreateFrame()); // set active frame
}

void MainMenu::sundayBookingsButton(){
  std::cout << "Sudnay Bookings" << std::endl;
  view_Frame.hide(); // hide original frame
  StaffMenu staffMenu; // create new staff menu instance
  setMenu(staffMenu.CreateFrame()); // set active frame
}


