/* read_button.cpp
* Made by Jenna Hebet 
* reads a pushbutton on GPIO1_14
* a sumbit button on the webpage will 
* run the program and read the state of the pin
* The state of the pin will then be displayed on the browser
* the program uses Molloy's GPIO class 
 * 
*/

#include <iostream>         // for the input/output
#include<unistd.h> //forsleep?
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include"GPIO.h"
using namespace exploringBB;
using namespace std;
using namespace cgicc;
//TODO edit logic to use gpio class and test 
int main(){
   GPIO button(46);
   button.setDirection(INPUT); //using the GPIO class, setting it as the input
   Cgicc form;                      // the CGI form object
   //string cmd;                      // the Set LED command
   // get the state of the form that was submitted - script calls itself
   bool isStatus = form.queryCheckbox("status");
   //form_iterator it = form.getElement("cmd");  // the radio command
   //if (it == form.getElements().end() || it->getValue()==""){
   //   cmd = "off";                     // if it is invalid use "off"
   //}
   //else { cmd = it->getValue(); }      // otherwise use submitted value
   char *value = getenv("REMOTE_ADDR");    // The remote IP address
 
   // generate the static HTML page 
   cout << HTTPHTMLHeader() << endl;      
   cout << html() << head() << title("Read Button") << head() << endl;
   cout << body() << h1("CPE 422/522 Reading a Pushbutton as Digital Input") << endl;
   cout << "<form>";
   cout << "<div> <input type=\"submit\" value = \"Read Button\"> </div>";
   cout << "</form>";
   cout << "<div> <h2> Pushbutton State </h2> </div>"; 

 //edit this to take the logic from the pushbutton
   if (button.getValue()==0) {
	   cout << "<h2>Button Pressed</h2>" <<endl;
   }
   else {
	   cout <<"<h2>Button Not Pressed</h2>"<<endl;
   }
  return 0;
}

