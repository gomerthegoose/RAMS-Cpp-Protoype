#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"
#include <string>

class LoginWindow : public Gtk::Window
{
public:
  LoginWindow();
  virtual ~LoginWindow();

  

protected:
  //Signal handlesr:
  void HandleLogin();
  void onClose();

  //Child widgets:
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::PasswordEntry PasswordEntry_txt;
  Gtk::Entry UsernameEnrty_txt;
  Gtk::Button Login_btn; 
  Gtk::Button addUserTmp_btn; 
  std::unique_ptr<Gtk::MessageDialog> loginError_msg;
  //Gtk::Window LoginScreenWindow;
};