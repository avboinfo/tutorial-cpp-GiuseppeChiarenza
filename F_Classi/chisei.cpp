
#include <io.stream>
#include <string>

class orario
{

public:
    int ore, minuti, secondi

    orario (int h, int m, int s){
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        {
            cout << "orario non valido" << endl;
        }
        ore = h;
        minuti = m;
        secondi = s;
        
    }

    string to_string(){
        return to_string(ore) + ":" + to_string(minuti) + ":" + to_string(secondi)
    }
    int to 



};