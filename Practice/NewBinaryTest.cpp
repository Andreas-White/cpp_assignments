#include <fstream>
#include <iterator>
#include <algorithm>

int main()
{
    std::ifstream input( "C:/Users/PC/OneDrive/Desktop/files/timelog.dat", std::ios::binary );
    std::ofstream output( "C:/Users/PC/OneDrive/Desktop/files/A.txt");

    std::copy( 
        std::istreambuf_iterator<char>(input), 
        std::istreambuf_iterator<char>( ),
        std::ostreambuf_iterator<char>(output));
}