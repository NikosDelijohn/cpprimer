#include <iostream>
#include "../help.hpp"

// Due to inheritance relationship between the streams, 
// all the things mentioned here are applicable to sstreams and fstreams too!

int main()
{
    std::istream &ref = std::cin;
    std::iostream::iostate state = ref.rdstate();

    /*
    iostate has 4 defined constexpr states
    
     eofbit: When set in the stream's state indicates that the EOF is reached.
     badbit: When set in the stream's state indicates that a system-level failure occured.
    goodbit: When set in the stream's state indicates that no bad, fail and eofbits are set.
    failbit: When set in the stream's state indicates that the IO operation failed.

    Each permutation of the above can occur and define a stream state.    
    */

    std::cout << "State before reading an EOF char: (press CTRL-D) " << ref.rdstate() << std::endl;
    print_stream_bit_matrix(ref);
    int _ ;
    ref >> _ ; 
    std::cout << "State after reading an EOF char: " << ref.rdstate() << std::endl;
    print_stream_bit_matrix(ref);
    
    // Sets the new state of our stream
    std::cout << "State after clear(goodbit) call!" << std::endl;
    ref.clear(std::iostream::goodbit);
    print_stream_bit_matrix(ref);

    // What if we turn on the bad bit and then try to read
    std::cout << "State after clear(badbit) call!" << std::endl;
    ref.clear(std::iostream::badbit);
    print_stream_bit_matrix(ref);
    
    std::cout << "Attempting to read after badbit is set!" << std::endl;
    if (!(ref >> _))
        std::cout << "Could not read from stream!" << std::endl;
    print_stream_bit_matrix(ref);

    std::cout << "Resetting cin to good state!" << std::endl;
    ref.clear(std::iostream::goodbit);
    print_stream_bit_matrix(ref);


    // Unrecoverable on its own... Manual intervention required to clear() the stream.

/*
   ____        _               _     ____         __  __              
  / __ \      | |             | |   |  _ \       / _|/ _|             
 | |  | |_   _| |_ _ __  _   _| |_  | |_) |_   _| |_| |_ ___ _ __ ___ 
 | |  | | | | | __| '_ \| | | | __| |  _ <| | | |  _|  _/ _ \ '__/ __|
 | |__| | |_| | |_| |_) | |_| | |_  | |_) | |_| | | | ||  __/ |  \__ \
  \____/ \__,_|\__| .__/ \__,_|\__| |____/ \__,_|_| |_| \___|_|  |___/
                  | |                                                 
                  |_|                                                 

*/

    std::cout << "Hi !" << std::endl;  // Terminates with a newline and flushes buffer.
    std::cout << "Hi !" << std::flush; // Just flushes the buffer. Adds no other data.
    std::cout << "Hi !" << std::ends;  // Terminates with a null and flushes buffer.

    // We can set a write to a stream to be Always flushed
    // by using the unitbuf.

    std::cout << std::unitbuf;
    
    // Any subsequent out write will be immediately flushed
    std::cout << "\n\nNo buffering due to std::unitbuf\n\n";

    // To disable it (after it has been enabled)
    std::cout << std::nounitbuf;

    // Also, the stdlib ties cin to cout. So any read action from CIN causes COUT to be flushed first!
    /* This is because we want interractive behavior and scenarios like this:   
        std::cout << "Enter value: ";
        int x;
        std::cin >> x;
    */
    
    // std::ios::tie() is used to link one stream to another so that whenever the first stream performs an input operation, the tied stream is automatically flushed.
    // If stream A is tied to stream B, then before A does any input, B.flush() is called automatically.
    

    std::cout << type_name(*std::cin.tie()) << std::endl; // prints the name of the stream that std::cin is tied to! (stdout)
    std::cout << std::cout.tie() << std::endl; // expect 0 (nullptr). out is not tied to any other stream.
    
    // To Untie std::cin from std::cout for example we can
    std::cin.tie(nullptr);
    // After this, std::cout won’t flush automatically before reads — which can slightly speed up I/O-heavy code 
    // but can cause prompts to disappear.
    
    std::cout << "\nEnter your name: \n";
    std::string name;
    std::cin >> name; // may!! not show the prompt immediately!
    
    // We can tie cin to cerr like this
    std::cin.tie(&std::cerr); // after this, cerr will flush automatically before reads!
    std::cerr << "[err]: Enter your name again: \n\n";
    std::cin >> name;

    return EXIT_SUCCESS;
}