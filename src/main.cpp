#include <iostream>
#include "EmbeddedIntentRecognizer.h"

int main(int argc, char** argv)
{
    if(argc > 1){
        EmbeddedIntentRecognizer rec;
        cout << rec.GetIntent(argc-1, &argv[1]) << endl;
    }
    return 0;
}
