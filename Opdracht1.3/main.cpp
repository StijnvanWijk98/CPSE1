#include "hwlib.hpp"

extern "C" void print_asciz(const char *s);

extern "C" void application();

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" char  convert( char to_convert){
   char char_ret = to_convert;
   if(to_convert >= 'A' && to_convert <= 'Z'){
      char_ret = to_convert + 32;
   } else if (to_convert >= 'a' && to_convert <= 'z'){
      char_ret = to_convert - 32;
   }
   return char_ret; 
}

int main( void ){	
   
   namespace target = hwlib::target;
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}