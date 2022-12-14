#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"

class MainMenu : public Gtk::Window
{
public:
  MainMenu();
  virtual ~MainMenu();
  void CreateWindow();
  void setMenu(Gtk::Frame);

protected:
  //Signal handlers:
  void staffMenuButton();
  void stockMenuButton();
  void thursdayBookingsButton();
  void sundayBookingsButton();

  

  Gtk::Frame GetMainMenuControls();
  

  //Child widgets:
  Gtk::Window MainMenuWindow;
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::Button StaffButton;
  Gtk::Button StockButton;
  Gtk::Button ThursdayBookingButton;
  Gtk::Button SundayBookingButton;
  Gtk::Button exitButton;
  Gtk::Grid m_grid;
  Gtk::Frame controls_Frame;
  Gtk::Frame view_Frame;
  Gtk::Grid* Controls_grid;
  Gtk::Grid* Main_grid;
};
