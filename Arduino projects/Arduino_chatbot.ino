#include <SoftwareSerial.h>

SoftwareSerial BT(10, 9); // TX, RX
String Data; // the data received
String Name;// to store your name

 
void setup() {
  BT.begin(9600);
  }
 
void loop() {
  if (BT.available()){ //wait for data received
    delay(200);    //delay to write buffer
    Data =BT.readString();
    //Data = tolower(Data);
    if((Data.indexOf("hi")> -1) ||(Data.indexOf("hey")> -1)|| (Data.indexOf("chatbot")>-1)) { 
      BT.println("hello!! what's up?");
      Data = ""; // clear  "Data" for next inputs 
      }
    else if(((Data.indexOf("what")> -1) || (Data.indexOf("your")> -1)) && (Data.indexOf("name")> -1)){
      BT.println("My name is chatbot;");
      delay(500);
      BT.println("what is your name?");
      delay(200);
      BT.println("waiting 10 sec  for your name:");
      delay(10000);
      Name = ""; // if different person interactingwith bot  it clears "Name"
      Name = BT.readString();
      BT.println("Nice to meet you "+ Name);
      Data = "";
      }
      else if((Data.indexOf("what")> -1) && (Data.indexOf("doing")> -1)){
        BT.println("I am talking with you :)");
        BT.println("what about you?");
        Data = "";
      }
      else if ((Data.indexOf("i am")> -1) || (Data.indexOf("doing")> -1)){
      BT.println("Nice to hear that...");
      Data = "";
     }
     else if((Data.indexOf("what")> -1) && (Data.indexOf("my")> -1) && (Data.indexOf(" name")> -1)){
      BT.println("your Name is " + Name);
     }
     else if ((Data.indexOf("what is your gender")>-1) || ((Data.indexOf("gender")>-1) || (Data.indexOf("male")>-1)|| (Data.indexOf("female")>-1))){
      BT.println("I have a Boyfriend :)");
     }
     else if ((Data.indexOf("your phone number")>-1) ||(Data.indexOf("number")>-1)){
      BT.println("I told you before, I have a BOYFRIEND");
     }
     else if ((Data.indexOf("who is your boyfriend")>-1) || (Data.indexOf("bf")>-1) || (Data.indexOf("what is your bf name")>-1)){
        BT.println("Thats TOO personal question");
      }
     else if((Data.indexOf("address")>-1) || (Data.indexOf("you stay")>-1)){
     BT.println("I am everywhere!!!1");
     }
     
     else if ((Data.indexOf("like you")>-1) ||(Data.indexOf("love you")>-1)){
      BT.println("I Like you as FRIEND");
      }
      
     else if((Data.indexOf("human")>-1) || (Data.indexOf("who are you")>-1)){
       BT.println("I am Chatbot ...");
       }
        
     else if((Data.indexOf("bore")>-1) || (Data.indexOf(" you are boring")>-1)){
       BT.println("Thats makes me sad ):");
     }
     
     else if((Data.indexOf("bye")>-1)|| (Data.indexOf("i am going")>-1)||(Data.indexOf("get lost")>-1)){
      BT.println("Bye,Have a nice day ");
  }

  else if ((Data.indexOf("how are you")>-1)){
    BT.println("I am fine");
    delay(200);
    BT.println("How are you doing?");
  }

  else if ((Data.indexOf("fine")>-1) || (Data.indexOf("well")>-1)){
    BT.println("That is good to hear..");
  }
  else if ((Data.indexOf("i am")>-1) || (Data.indexOf("doing")>-1)){
    BT.println("OK");
  }
  else if ((Data.indexOf("how old")>-1) || (Data.indexOf("age")>-1)){
    BT.println("You have pretty eyes,you can guess my age");
    }
}
}
