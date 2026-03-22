#include <iostream>  // for std::cout and cin 
  #include <string>    // for std::string
> 
> /**
>  * main function ,            
>  */                                                  
> int main() {
>     std::string name;                      // name,
>     std::cout << "Enter your name: ";      // введите имя                  
>     std::getline(std::cin, name);          // reading name     
>     std::cout << "Hello world from " << name << std::endl;  // print    
>     return 0;                              //ending      
> }   
